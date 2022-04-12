/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmillan <dmillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:00:51 by eleon             #+#    #+#             */
/*   Updated: 2022/01/11 05:33:43 by dmillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

t_print	*ft_initialize_table(t_print	*table)
{
	table->length = 0;
	table->width = 0;
	table->zero = 0;
	table->prc = 0;
	table->minus = 0;
	table->sign = 'a';
	table->dot = 0;
	table->alt = 0;
	table->space = 0;
	table->plus = 0;
	table->is_zero = 0;
	return (table);
}

int	ft_is_flag(int c)
{
	return ((c == '-') || (c == '0') || (c == '.')
		|| (c == '*') || (c == '#') || (c == ' ')
		|| (c == '+'));
}

int	ft_parse_flag(const char *format, int i, t_print *table)
{
	while (format[i] && (ft_isdigit(format[i]) || ft_is_flag(format[i])))
	{
		if (format[i] == '0' && table->prc == 0 && table->minus == 0)
			table->zero = 1;
		else if (format[i] == '.')
			i = ft_flag_dot(format, i + 1, table);
		else if (format[i] == '-')
			ft_flag_minus(table);
		else if (format[i] == '*')
			ft_flag_width(table);
		else if (format[i] == '#')
			table->alt = 1;
		else if (format[i] == ' ' && table->plus == 0)
			table->space = 1;
		else if (format[i] == '+')
			ft_flag_plus(table);
		else if (ft_isdigit(format[i]))
			i = ft_flag_digit(format, i, table);
		i++;
	}
	return (i);
}

int	ft_evaluate_flags(const char *format, t_print *table, int i)
{
	if (!format[i])
		return (i - 1);
	while (format[i] && !ft_is_type(format[i]))
	{
		if (ft_isdigit(format[i]) || ft_is_flag(format[i]))
			i = ft_parse_flag(format, i, table);
		else
			return (i - 1);
	}
	if (format[i])
		ft_parse_type(format[i], table);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	t_print	*table;

	if (format == NULL)
		return (0);
	i = 0;
	table = (t_print *)malloc(sizeof(t_print));
	if (!table)
		return (-1);
	ft_initialize_table(table);
	va_start(table->args, format);
	while (format[i])
	{
		if (format[i] == '%')
			i = ft_evaluate_flags(format, table, i + 1);
		else
			ft_putchar_count(format[i], table);
		i++;
	}
	va_end(table->args);
	free((char *)table);
	return (table->length);
}
