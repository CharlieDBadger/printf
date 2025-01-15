/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolanos <cbolanos@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:34:15 by cbolanos          #+#    #+#             */
/*   Updated: 2025/01/11 17:34:19 by cbolanos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_proccess_args(const char *format, va_list args, int count);
static int	ft_printf_specifier(char specifier, va_list args);

/**
 * ft_printf - Custom implementation of printf function.
 * @format: The format string specifying how subsequent arguments 
 *          are to be printed.
 *
 * This function processes the input format string and its associated 
 * arguments, printing them according to the specified format. It handles 
 * various specifiers like %c, %s, %d, %x, and others.
 *
 * Return: The total number of characters printed, or -1 in case of an error.
 */
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	if (!format || format[0] == '\0')
		return (-1);
	va_start(args, format);
	count = ft_proccess_args(format, args, count);
	va_end(args);
	return (count);
}

/**
 * ft_proccess_args - Processes the format string and calls the appropriate 
 *                    function for each specifier.
 * @format: The format string with specifiers.
 * @args: The list of arguments to be printed.
 * @count: The running total of characters printed so far.
 *
 * This function iterates through the format string, handling each 
 * specifier (like %c, %d, %s, etc.) by calling the appropriate function.
 * It also handles errors (e.g., invalid specifiers) and ensures proper 
 * character counting.
 *
 * Return: The total number of characters printed, or -1 if an error occurs.
 */
static int	ft_proccess_args(const char *format, va_list args, int count)
{
	int		i;
	int		control;

	i = 0;
	control = 0;
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			control = ft_printf_specifier(format[i + 1], args);
			if (control == -1)
				return (control);
			count += control;
			i += 2;
		}
		else
		{
			count += ft_putchar(format[i]);
			i++;
		}
	}
	return (count);
}

/**
 * ft_printf_specifier - Handles specific format specifiers and prints 
 *                       the corresponding argument.
 * @specifier: The character representing the format specifier (e.g., %c, %d).
 * @args: The list of arguments to be printed.
 *
 * This function checks the specifier and delegates the task of printing 
 * the corresponding argument to the appropriate function (e.g., ft_putchar 
 * for %c, ft_putstr for %s, etc.).
 *
 * Return: The number of characters printed for the specific specifier.
 */
static int	ft_printf_specifier(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar((char)va_arg(args, int));
	else if (specifier == 's')
		count += ft_putstr((char *)va_arg(args, char *));
	else if (specifier == 'p')
		count += ft_putptr((void *)va_arg(args, void *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnum((int)va_arg(args, int));
	else if (specifier == 'u')
		count += ft_putnum_abs((unsigned int)va_arg(args, unsigned int));
	else if (specifier == '%')
		count += ft_putchar('%');
	else if (specifier == 'x')
		count += ft_putn_hexm((unsigned int)va_arg(args, unsigned int));
	else if (specifier == 'X')
		count += ft_putn_hexc((unsigned int)va_arg(args, unsigned int));
	return (count);
}
