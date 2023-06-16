#include <stdio.h>
/**
 * main - Print all possible combinations of two two-digit numbers.
 * Return: 0
 */
int main(void)
{
	int x, y;

	for (x = 0; x <= 98; x++)
	{
		for (y = x + 1; y <= 99; y++)
