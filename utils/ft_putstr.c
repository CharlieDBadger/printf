/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolanos <cbolanos@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:19:47 by cbolanos          #+#    #+#             */
/*   Updated: 2025/01/14 17:19:51 by cbolanos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c);

/**
 * ft_putstr - Writes a string to the standard output.
 * @str: The string to be written.
 *
 * This function takes a string as input and writes each character to the 
 * standard output using `ft_putchar`. If the input string is `NULL`, 
 * it writes the string "(null)" instead. It returns the number of 
 * characters written, or -1 if an error occurs while writing.
 *
 * Return: The number of characters written to the standard output, or -1 
 *         if an error occurs.
 */
int	ft_putstr(char *str)
{
	int	count;

	if (!str)
	{
		return (ft_putstr("(null)"));
	}
	count = 0;
	while (*str)
	{
		if (ft_putchar(*str) == -1)
			return (-1);
		str++;
		count++;
	}
	return (count);
}
