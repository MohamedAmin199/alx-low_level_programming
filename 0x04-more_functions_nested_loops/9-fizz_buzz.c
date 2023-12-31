#include <stdio.h>
/**
 * main - Prints the numbers from 1-100,
 * For multiples of three, Fizz is printed instead of the number,
 * For multiples of five, Buzz is printed instead of the number,
 * and for multiples of both three and five, FizzBuzz.
 * Return: void.
 */

int main(void)
{
	int i = 1;

	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
			printf("FizzBuzz");
		}
		else if (i % 3 == 0)
		{
			printf("Fizz");
		}
		else if (i % 5 == 0)
		{
			printf("Buzz");
		}
		else
		{
			printf("%i", i);
		}

		if (i != 100)
		{
			putchar(' ');
		}
		i++;
	}
	putchar('\n');
	return (0);
}
