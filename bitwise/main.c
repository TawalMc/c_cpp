#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "bitwise_operations.h"

int main(void)
{
	// 1. is_lsb_set:
	uint8_t num1 = 5;					 // 0x5 = 0000 0101 (LSB set)
	uint8_t num2 = 8;					 // 0x8 = 0000 1000 (LSB not set)
	assert(is_lsb_set(num1));	 // LSB is set in num1
	assert(!is_lsb_set(num2)); // LSB is not set in num2
	printf("All assertions for 'is_lsb_set' passed successfully\n");

	// 2. is_msb_set:
	uint8_t num3 = 137; // 0x89 = 0b1000 1001
	uint8_t num4 = 9;		// 0x09 = 0b0000 1001
	assert(is_msb_set(num3));
	assert(!is_msb_set(num4));
	printf("All assertions for 'is_msb_set' passed successfully\n");

	// 3. get_nth_bit:
	assert(get_nth_bit(num3, 3) == 1);
	assert(get_nth_bit(num3, 2) == 0);
	printf("All assertions for 'get_nth_bit' passed successfully\n");

	// 4. set_nth_bit
	uint8_t num5 = 137;		 // 0x89 = 0b1000 1001
	uint8_t num6 = 9;			 // 0x09 = 0b0000 1001
	set_nth_bit(&num5, 2); // 141 = 0x8D = 0b1000 1101
	set_nth_bit(&num6, 7); // 137 = 0x89 = 0b1000 1001
	assert(get_nth_bit(num5, 2) == 1);
	assert(num6 == 137);
	printf("All assertions for 'set_nth_bit' passed successfully\n");

	// 5. clear_nth_bit
	uint8_t num7 = 137;			 // 0x89 = 0b1000 1001
	uint8_t num8 = 9;				 // 0x09 = 0b0000 1001
	clear_nth_bit(&num7, 7); // 9 = 0x09 = 0b0000 1001
	clear_nth_bit(&num8, 3); // 1 = 0x01 = 0b0000 0001
	assert(get_nth_bit(num7, 7) == 0);
	assert(num8 == 1);
	printf("All assertions for 'clear_nth_bit' passed successfully\n");

	// 6. toggle_nth_bit
	uint8_t num9 = 137;				// 0x89 = 0b1000 1001
	toggle_nth_bit(&num9, 7); // 9 = 0x09 = 0b0000 1001
	assert(get_nth_bit(num9, 7) == 0);
	toggle_nth_bit(&num9 /* 0b0000 1001 */, 7); // 9 = 0x09 = 0b1000 1001
	assert(get_nth_bit(num9, 7) == 1);
	printf("All assertions for 'toggle_nth_bit' passed successfully\n");

	// 16. is_even
	uint8_t num10 = 5; // 0x5 = 0000 0101 (LSB set)
	uint8_t num11 = 8; // 0x8 = 0000 1000 (LSB not set)
	assert(!is_even(num10));
	assert(is_even(num11));
	printf("All assertions for 'is_even' passed successfully\n");

	return 0;
}