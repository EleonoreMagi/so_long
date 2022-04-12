/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmillan <dmillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 02:35:01 by eleon             #+#    #+#             */
/*   Updated: 2022/01/10 23:29:10 by dmillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_align_char(t_print *table, int minus)
{
	while (table->width - minus > 0)
	{
		if (table->zero)
			ft_putchar_count('0', table);
		else
			ft_putchar_count(' ', table);
		table->width--;
	}
}

void	ft_parse_char(t_print *table)
{
	char	c;

	c = va_arg(table->args, int);
	if (!table->minus)
		ft_align_char(table, 1);
	ft_putchar_count(c, table);
	if (table->minus)
		ft_align_char(table, 1);
	ft_clear_table(table);
}

void	ft_parse_string(t_print *table)
{
	char	*str;

	str = va_arg(table->args, char *);
	if (str == NULL)
		str = "(null)";
	if ((table->dot && table->prc > ft_strlen(str)) || !table->dot)
		table->prc = ft_strlen(str);
	if (!table->minus)
	{
		ft_align_char(table, table->prc);
	}
	ft_putstr_count(str, table->prc, table);
	if (table->minus)
	{
		ft_align_char(table, table->prc);
	}
	ft_clear_table(table);
}

void	ft_parse_percent(t_print *table)
{
	if (!table->minus)
		ft_align_char(table, 1);
	ft_putchar_count('%', table);
	if (table->minus)
		ft_align_char(table, 1);
	ft_clear_table(table);
}
