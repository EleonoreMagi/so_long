/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmillan <dmillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 03:07:18 by eleon             #+#    #+#             */
/*   Updated: 2022/01/11 04:29:48 by dmillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_minus(t_print	*table)
{
	table->minus = 1;
	table->zero = 0;
}

void	ft_flag_plus(t_print	*table)
{
	table->plus = 1;
	table->space = 0;
}

void	ft_flag_width(t_print	*table)
{
	table->width = va_arg(table->args, int);
	if (table->width < 0)
	{
		table->minus = 1;
		table->width *= -1;
	}
}

int	ft_flag_dot(const char *format, int start,
		t_print *table)
{
	table->dot = 1;
	if (format[start] == '*')
	{
		table->prc = va_arg(table->args, int);
		if (table->prc < 0)
		{
			table->dot = 0;
			table->prc = 0;
		}
	}
	else if (format[start] == '-')
		table->dot = 0;
	else
	{
		while (ft_isdigit(format[start]))
			table->prc = (table->prc * 10) + (format[start++] - '0');
		start--;
	}
	return (start);
}

int	ft_flag_digit(const char *format, int start,
		t_print *table)
{
	int	i;

	i = start;
	while (ft_isdigit(format[i]))
		table->width = (table->width * 10) + (format[i++] - '0');
	return (i - 1);
}
