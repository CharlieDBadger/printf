/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolanos <cbolanos@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:18:34 by cbolanos          #+#    #+#             */
/*   Updated: 2025/01/14 17:18:40 by cbolanos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * ft_putchar - Writes a single character to the standard output.
 * @c: The character to be written.
 *
 * This function writes the character 'c' to the standard output (file
 * descriptor 1). It utilizes the system call `write` to perform the
 * operation.
 *
 * Return: On success, returns 1. On failure, returns -1.
 */
int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}
