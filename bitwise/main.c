#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "bitwise_operations.h"

int main(void)
{
	// 1. is_lsb_set:
	uint8_t num1 = 5;									 // 0x5 = 0000 0101 (LSB set)
	uint8_t num2 = 8;									 // 0x8 = 0000 1000 (LSB not set)
	assert(is_lsb_set(num1) == true);	 // LSB is set in num1
	assert(is_lsb_set(num2) == false); // LSB is not set in num2
	printf("All assertions for 'is_lsb_set' passed successfully\n");

	// 2. is_msb_set:
	uint8_t num3 = 137; // 0x89 = 0b1000 1001 (MSB set)
	uint8_t num4 = 9;		// 0x09 = 0b0000 1001 (MSB not set)
	assert(is_msb_set(num3) == true);
	assert(is_msb_set(num4) == false);
	printf("All assertions for 'is_msb_set' passed successfully\n");

	// 3. get_nth_bit:
	assert(get_nth_bit(num3, 3) == 1);
	assert(get_nth_bit(num3, 2) == 0);
	printf("All assertions for 'get_nth_bit' passed successfully\n");

	return 0;
}