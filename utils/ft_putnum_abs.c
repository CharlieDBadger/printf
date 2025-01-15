/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum_abs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolanos <cbolanos@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:19:30 by cbolanos          #+#    #+#             */
/*   Updated: 2025/01/14 17:19:34 by cbolanos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_str_len(unsigned int n);
static char	*ft_uitoa(unsigned int n);
int			ft_putstr(char *str);

/**
 * ft_putnum_abs - Converts an unsigned integer to a string and writes it 
 *                 to the standard output.
 * @num: The unsigned integer to be converted and printed.
 *
 * This function takes an unsigned integer, converts it to a string using 
 * `ft_uitoa`, and then writes the resulting string to the standard output 
 * using `ft_putstr`. After printing, it frees the allocated memory for the 
 * string.
 * 
 * Return: The number of characters written to the standard output, or -1 if 
 *         memory allocation for the string fails.
 */
int	ft_putnum_abs(unsigned int num)
{
	char	*num_str;
	int		count;

	num_str = ft_uitoa(num);
	if (!num_str)
		return (-1);
	count = ft_putstr(num_str);
	free(num_str);
	return (count);
}

/**
 * ft_uitoa - Converts an unsigned integer to a string.
 * @n: The unsigned integer to be converted.
 *
 * This function converts an unsigned integer into a string representation. 
 * If the integer is 0, it returns the string "0". For other values, it 
 * calculates the length of the string, allocates memory, and fills the string 
 * with digits in reverse order.
 *
 * Return: A pointer to the string representing the unsigned integer, or NULL 
 *         if memory allocation fails.
 */
static char	*ft_uitoa(unsigned int n)
{
	int		num_len;
	char	*n_str;

	num_len = num_str_len(n);
	n_str = (char *)malloc((num_len + 1) * sizeof(char));
	if (!n_str)
		return (NULL);
	if (n == 0)
	{
		n_str[0] = '0';
		n_str[1] = '\0';
		return (n_str);
	}
	n_str[num_len] = '\0';
	while (n > 0)
	{
		n_str[num_len - 1] = (n % 10) + '0';
		n = n / 10;
		num_len--;
	}
	return (n_str);
}

/**
 * num_str_len - Calculates the length of an unsigned integer when converted 
 *               to a string.
 * @n: The unsigned integer whose length is to be calculated.
 *
 * This function determines the number of digits in the unsigned integer by 
 * dividing it by 10 repeatedly until the number becomes 0. The length is then 
 * returned.
 *
 * Return: The length of the string representing the unsigned integer.
 */
static int	num_str_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
