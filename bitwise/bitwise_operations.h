#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define BIT_SIZE 8
#define BIT_MASK_LSB 0x01
#define BIT_MASK_MSB 0x80 // 1<<7
#define BIT_MASK_ALL 0xFF // ~(0x00)

/**
 * @brief 1. Write a C program to check Least Significant Bit (LSB) of a number is set or not.
 *
 */
bool is_lsb_set(uint8_t num)
{
	return (num & BIT_MASK_LSB) == 1;
}

/**
 * @brief 2. Write a C program to check Most Significant Bit (MSB) of a number is set or not.
 *
 */
bool is_msb_set(uint8_t num)
{
	return ((num & BIT_MASK_MSB) >> (BIT_SIZE - 1)) == 1; // (n & BIT_MASK_MSB) == BIT_MASK_MSB
}

/**
 * @brief 3. Write a C program to get nth bit of a number.
 *
 */
uint8_t get_nth_bit(uint8_t num, uint8_t n)
{
	uint8_t mask = 1 << n;
	return (num & mask) >> n;
}

/**
 * @brief 4. Write a C program to set nth bit of a number.
 *
 */
void set_nth_bit(uint8_t *num, uint8_t n)
{
	uint8_t mask = 1 << n;
	*num |= mask;
}

/**
 * @brief 5. Write a C program to clear nth bit of a number.
 *
 */
void clear_nth_bit(uint8_t *num, uint8_t n)
{
	uint8_t mask = ~(1 << n);
	*num &= mask;
}

/**
 * @brief 6. Write a C program to toggle nth bit of a number.
 *
 */
void toggle_nth_bit(uint8_t *num, uint8_t n)
{
	uint8_t mask = 1 << n;
	*num ^= mask;
}

/**
 * @brief 7. Write a C program to get highest set bit of a number.
 *
 */

int8_t get_highest_set_bit_pos(uint8_t num)
{
	for (size_t i = 0; i <= BIT_SIZE - 1; i++)
	{
		uint8_t pos = BIT_SIZE - 1 - i;
		uint8_t bit = get_nth_bit(num, pos);
		if (bit == 1)
			return pos;
	}
	return -1;
}

/**
 * @brief 8. Write a C program to get lowest set bit of a number.
 *
 */

int8_t get_lowest_set_bit_pos(uint8_t num)
{
	for (size_t i = 0; i <= BIT_SIZE - 1; i++)
	{
		uint8_t bit = get_nth_bit(num, i);
		if (bit == 1)
			return i;
	}
	return -1;
}

/**
 * @brief 9. Write a C program to count trailing zeros in a binary number.
 *
 */
uint8_t count_trailing_zeros(uint8_t num)
{
	uint8_t count = 0;
	for (size_t i = 0; i <= BIT_SIZE - 1; i++)
	{
		if (get_nth_bit(num, i) == 0)
		{
			count++;
		}
		else
			return count;
	}
	return count;
}

/**
 * @brief 10. Write a C program to count leading zeros in a binary number.
 *
 */
uint8_t count_leading_zeros(uint8_t num)
{
	uint8_t count = 0;
	for (size_t i = 0; i <= BIT_SIZE - 1; i++)
	{
		if (get_nth_bit(num, BIT_SIZE - 1 - i) == 0)
		{
			count++;
		}
		else
			return count;
	}
	return count;
}

/**
 * @brief 12. Write a C program to count total zeros and ones in a binary number.
 *
 */
uint8_t count_zeros_or_ones(uint8_t num, uint8_t value_to_count)
{
	assert(value_to_count == 1 || value_to_count == 0); // to remove
	uint8_t count = 0;
	for (size_t i = 0; i <= BIT_SIZE - 1; i++)
	{
		if (get_nth_bit(num, BIT_SIZE - 1) == value_to_count)
		{
			count++;
		}
	}
	return count;
}

/**
 * @brief 14. Write a C program to convert decimal to binary number system using bitwise operator.
 *
 */
void dec_to_bin(uint8_t num, char *bin)
{
	if (num >> 1)
	{
		dec_to_bin(num >> 1, bin);
	}
	strcat(bin, num & 0x01 == 1 ? "1" : "0");
}

/**
 * @brief 14. Write a C program to convert decimal to binary number system using bitwise operator.
 *
 */
void dec_to_full_bin(uint8_t num, char *bin)
{
	for (size_t i = 0; i <= BIT_SIZE - 1; i++)
	{
		uint8_t bit = get_nth_bit(num, BIT_SIZE - 1 - i);
		strcat(bin, bit == 1 ? "1" : "0");
	}
}

/**
 * @brief 16. Write a C program to check whether a number is even or odd using bitwise operator.
 *
 */
bool is_even(uint8_t num)
{
	return !is_lsb_set(num);
}