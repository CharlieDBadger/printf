/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolanos <cbolanos@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:19:38 by cbolanos          #+#    #+#             */
/*   Updated: 2025/01/14 17:19:42 by cbolanos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putstr(char *str);
static int	ft_hexlen(unsigned long address);
static char	*ft_ptr_to_hex(void *ptr);

/**
 * ft_putptr - Converts a pointer to a hexadecimal string and writes it to 
 *             the standard output.
 * @ptr: The pointer to be converted and printed.
 *
 * This function takes a pointer, converts it to a hexadecimal string 
 * representation using `ft_ptr_to_hex`, and then writes the resulting 
 * string to the standard output using `ft_putstr`. If the pointer is 
 * `NULL`, it prints "(nil)" instead. After printing, it frees the 
 * allocated memory for the string.
 *
 * Return: The number of characters written to the standard output, or -1 
 *         if memory allocation for the string fails.
 */
int	ft_putptr(void *ptr)
{
	int		count;
	char	*hexa;

	hexa = ft_ptr_to_hex(ptr);
	if (ft_strncmp(hexa, "(nil)", 5) == 0)
		return (ft_putstr(hexa));
	count = ft_putstr(hexa);
	free(hexa);
	return (count);
}

/**
 * ft_ptr_to_hex - Converts a pointer to a hexadecimal string.
 * @ptr: The pointer to be converted.
 *
 * This function converts a pointer into a string representation in 
 * hexadecimal format, prefixed with "0x". If the pointer is `NULL`, it 
 * returns the string "(nil)". Otherwise, it allocates memory for the 
 * resulting string, converts the address to hexadecimal, and fills the 
 * string with the corresponding hexadecimal characters.
 *
 * Return: A pointer to the string representing the pointer in 
 *         hexadecimal, or NULL if memory allocation fails.
 */
static char	*ft_ptr_to_hex(void *ptr)
{
	unsigned long	address;
	char			*hex_str;
	const char		*hex_chars;
	int				i;
	int				len;

	hex_chars = "0123456789abcdef";
	address = (unsigned long)ptr;
	if (address == 0 || ptr == NULL)
		return ("(nil)");
	len = ft_hexlen(address);
	hex_str = (char *)malloc(2 + len + 1);
	if (!hex_str)
		return (NULL);
	hex_str[0] = '0';
	hex_str[1] = 'x';
	i = 2 + len - 1;
	while (address > 0)
	{
		hex_str[i--] = hex_chars[address % 16];
		address /= 16;
	}
	hex_str[2 + len] = '\0';
	return (hex_str);
}

/**
 * ft_hexlen - Calculates the length of a hexadecimal string representation 
 *             for an unsigned long address.
 * @address: The address to be converted to hexadecimal.
 *
 * This function calculates the number of hexadecimal characters needed 
 * to represent the given address. If the address is 0, it returns 0.
 *
 * Return: The number of hexadecimal digits required to represent the 
 *         address.
 */
static int	ft_hexlen(unsigned long address)
{
	int	count;

	count = 0;
	if (address == 0)
		return (0);
	while (address > 0)
	{
		address /= 16;
		count++;
	}
	return (count);
}
