#include <stdint.h>
#include <stdio.h>

static int with_xor(int *array, size_t array_size)
{
	int result = 0;
	for (int i = 0; i < array_size; ++i)
		result ^= array[i];
	return result;
}
int main(void)
{
	int array[9] = {1, 2, 3, 3, 8, 1, 9, 2, 9};
	printf("%d\n", with_xor(array, 9));
	return 0;
}