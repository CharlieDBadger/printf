/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolanos <cbolanos@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:17:40 by cbolanos          #+#    #+#             */
/*   Updated: 2025/01/08 13:17:42 by cbolanos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * num_str_len - Calculates the length of the integer when converted to a string.
 * 
 * @n: The integer whose length is to be calculated.
 * 
 * This function calculates how many characters are needed to 
 * represent the integer 'n' as a string. It accounts for 
 * the sign of negative numbers and includes a check 
 * for zero (which has a length of 1).
 * 
 * Example:
 * num_str_len(-123) returns 4.
 * 
 * Return:
 * - The length of the integer when represented as a string.
 */
static int	num_str_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

/**
 * itol_abs - Converts an integer to its absolute value as a long.
 * 
 * @n: The integer to convert to absolute value.
 * 
 * This function takes an integer 'n' and returns its absolute value, 
 * converted to a long to avoid overflow with negative values.
 * 
 * Example:
 * itol_abs(-123) returns 123L.
 * 
 * Return:
 * - The absolute value of the integer 'n' as a long.
 */
static long	itol_abs(int n)
{
	if (n < 0)
		return ((long)n * -1);
	return ((long)n);
}

/**
 * ft_itoa - Converts an integer to a string representation.
 * 
 * @n: The integer to convert.
 * 
 * This function converts the integer 'n' to its string representation. 
 * It handles negative values, zero, and ensures the correct allocation 
 * of memory for the resulting string. The string is dynamically allocated 
 * and returned.
 * 
 * Example:
 * ft_itoa(-123) returns "-123".
 * 
 * Return:
 * - A newly allocated string representing the integer, 
 * or NULL if memory allocation fails.
 */
char	*ft_itoa(int n)
{
	int		num_len;
	long	n_long;
	char	*n_str;

	num_len = num_str_len(n);
	n_str = (char *)malloc((num_len + 1) * sizeof(char));
	if (!n_str)
		return (NULL);
	n_long = itol_abs(n);
	if (n == 0)
	{
		n_str[0] = '0';
		n_str[1] = '\0';
		return (n_str);
	}
	if (n < 0)
		n_str[0] = '-';
	n_str[num_len] = '\0';
	while (n_long > 0)
	{
		n_str[num_len - 1] = (n_long % 10) + '0';
		n_long = n_long / 10;
		num_len--;
	}
	return (n_str);
}
/*
#include <stdio.h>

int	main(void)
{
	int		n;
	char	*str;

	n = 12345;
	str = ft_itoa(n);
	if (str)
	{
		printf("The integer %d as a string is: %s\n", n, str);
		free(str);
	}
	else
	{
		printf("Memory allocation failed.\n");
	}
	return (0);
}
*/
