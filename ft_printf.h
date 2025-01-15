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

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putptr(void *ptr);
int		ft_putnum(int num);
int		ft_putnum_abs(unsigned int num);
int		ft_putn_hexm(unsigned int num);
int		ft_putn_hexc(unsigned int num);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
char	*ft_itoa(int n);
char	*ft_strchr(const char *s, int c);
