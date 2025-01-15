/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolanos <cbolanos@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:00:25 by cbolanos          #+#    #+#             */
/*   Updated: 2025/01/14 17:19:25 by cbolanos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str);

/**
 * ft_putnum - Converts an integer to a string and writes it to the standard 
 *             output.
 * @num: The integer to be converted and printed.
 *
 * This function takes an integer, converts it to a string using `ft_itoa`, 
 * and then writes the resulting string to the standard output using 
 * `ft_putstr`. After printing, it frees the allocated memory for the string.
 * 
 * Return: The number of characters written to the standard output, or -1 if 
 *         memory allocation for the string fails.
 */
int	ft_putnum(int num)
{
	char	*num_str;
	int		count;

	num_str = ft_itoa(num);
	if (!num_str)
		return (-1);
	count = ft_putstr(num_str);
	free(num_str);
	return (count);
}
