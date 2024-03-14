#include <stdint.h>
#include <stdbool.h>

#define BIT_SIZE 8
#define BIT_MASK_LSB 0x01
#define BIT_MASK_MSB 0x80 // 1<<7
#define BIT_MASK_ALL 0xFF // ~(0x00)

/**
 * @brief 1. Write a C program to check Least Significant Bit (LSB) of a number is set or not.
 *
 */
bool is_lsb_set(uint8_t n)
{
	return (n & BIT_MASK_LSB) == 1;
}

/**
 * @brief 2. Write a C program to check Most Significant Bit (MSB) of a number is set or not.
 *
 */
bool is_msb_set(uint8_t n)
{
	return ((n & BIT_MASK_MSB) >> (BIT_SIZE - 1)) == 1; // (n & BIT_MASK_MSB) == BIT_MASK_MSB
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
uint8_t set_nth_bit(uint8_t *num, uint8_t n)
{
	uint8_t mask = 1 << n;
	*num |= mask;
}
