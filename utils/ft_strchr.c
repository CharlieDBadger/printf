/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolanos <cbolanos@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:22:18 by cbolanos          #+#    #+#             */
/*   Updated: 2025/01/08 13:22:20 by cbolanos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * strchr - Locates the first occurrence of a character in a string.
 * @s: The string to search in.
 * @c: The character to search for.
 * 
 * Return: 
 * - A pointer to the first occurrence of @c in @s, 
 *   or NULL if the character is not found.
 * - If @c is '\0', returns a pointer to the null terminator of the string.
 */
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "Hello, world!";
	char	c;
	char	*result;

	c = 'o';
	result = ft_strchr(str, c);
	if (result)
		printf("First occurrence of '%c': %s\n", c, result);
	else
		printf("Character '%c' not found in string.\n", c);
	return (0);
}
*/
