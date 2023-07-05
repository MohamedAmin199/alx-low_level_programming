#include "main.h"
/**
 * is_prime_number - A function that check the prime number.
 * @n: int.
 * Return: 1 if n is a prime number, 0 if not.
 */

int is_prime_number(int n)
{
	return (check_prime(n, 2));
}

/**
 * check_prime - Checks if a number is divisible.
 * @n: int.
 * @resp: int.
 * Return: int.
 */

int check_prime(int n, int resp)
{
	if (resp >= n && n > 1)
		return (1);
	else if (n % resp == 0 || n <= 1)
		return (0);
	else
		return (check_prime(n, resp + 1));
}
