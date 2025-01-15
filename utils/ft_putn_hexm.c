/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putn_hexm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolanos <cbolanos@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:19:10 by cbolanos          #+#    #+#             */
/*   Updated: 2025/01/14 17:19:11 by cbolanos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putstr(char *str);
static int	ft_hexlen(unsigned int num);
static char	*ft_uint_to_hexm(unsigned int num);

/**
 * ft_putn_hexm - Converts an unsigned integer to its hexadecimal string 
 *                representation and writes it to the standard output in 
 *                lowercase letters.
 * @num: The unsigned integer to be converted.
 *
 * This function converts the given unsigned integer to its hexadecimal 
 * representation using lowercase letters ('a' to 'f'). It then outputs 
 * the resulting string using `ft_putstr` and returns the number of 
 * characters written.
 * 
 * Return: The number of characters written to the standard output.
 */
int	ft_putn_hexm(unsigned int num)
{
	int		count;
	char	*hexa;

	hexa = ft_uint_to_hexm(num);
	count = ft_putstr(hexa);
	free(hexa);
	return (count);
}

/**
 * ft_uint_to_hexm - Converts an unsigned integer to its hexadecimal string 
 *                   representation using lowercase letters.
 * @num: The unsigned integer to be converted.
 *
 * This function takes an unsigned integer and converts it to a hexadecimal 
 * string using the digits '0'-'9' and the letters 'a'-'f' for the 
 * hexadecimal characters. If the number is 0, it returns the string "0".
 * 
 * Return: A dynamically allocated string containing the hexadecimal 
 *         representation of the number, or NULL if memory allocation fails.
 */
static char	*ft_uint_to_hexm(unsigned int num)
{
	char			*hex_str;
	const char		*hex_chars;
	int				i;
	int				len;

	hex_chars = "0123456789abcdef";
	len = ft_hexlen(num);
	hex_str = (char *)malloc(len + 1);
	if (!hex_str)
		return (NULL);
	i = len - 1;
	if (num == 0)
		hex_str[i] = '0';
	while (num > 0)
	{
		hex_str[i--] = hex_chars[num % 16];
		num /= 16;
	}
	hex_str[len] = '\0';
	return (hex_str);
}

/**
 * ft_hexlen - Calculates the length of the hexadecimal representation of 
 *             an unsigned integer.
 * @num: The unsigned integer to calculate the length for.
 *
 * This function computes the number of hexadecimal digits required to 
 * represent the given unsigned integer. It handles the special case where 
 * the number is 0, in which case the length is considered 1 (representing "0").
 * 
 * Return: The number of hexadecimal digits required to represent the number.
 */
static int	ft_hexlen(unsigned int num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 16;
		count++;
	}
	return (count);
}
