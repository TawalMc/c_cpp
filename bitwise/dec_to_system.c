#include <stdint.h>
#include <stdio.h>

#define MAX_BASE 36
char symbols[MAX_BASE] = {
		'0', '1', '2', '3', '4', '5', '6', '7', '8',
		'9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
		'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
		'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

uint8_t a = 0;
static void print_base_rec0(uint16_t n, uint8_t base, uint16_t rem)
{

	if (n > 0)
	{
		uint16_t r = n % base;
		print_base_rec0(n / base, base, r); // calls the method again
		// printing the character from the next line
		// doesn't happen until the previous call to
		// the method is finished
		fprintf(stdout, "%d\n", a++);
		fprintf(stdout, "%c", symbols[r]);
	}
}
void print_base_rec(uint16_t n, uint8_t base)
{
	if (base >= MAX_BASE)
	{
		fprintf(stderr, "Base %d is bigger than the possible accepted base", base);
		return;
	}
	print_base_rec0(n, base, 5);
}
int main(int argc, char const *argv[])
{
	print_base_rec(35, 2);

	return 0;
}
