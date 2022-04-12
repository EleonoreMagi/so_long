/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmillan <dmillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 04:19:06 by eleon             #+#    #+#             */
/*   Updated: 2022/01/11 01:53:16 by dmillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_type(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p')
		|| (c == 'd') || (c == 'i') || (c == 'u')
		|| (c == 'x') || (c == 'X') || (c == '%'));
}

t_print	*ft_clear_table(t_print	*table)
{
	table->zero = 0;
	table->width = 0;
	table->prc = 0;
	table->minus = 0;
	table->dot = 0;
	table->sign = 'a';
	table->alt = 0;
	table->space = 0;
	table->plus = 0;
	table->is_zero = 0;
	return (table);
}

void	ft_parse_type(char c, t_print *table)
{
	table->type = c;
	if (c == 'c')
		ft_parse_char(table);
	else if (c == 's')
		ft_parse_string(table);
	else if (c == 'p')
		ft_parse_ptr(table);
	else if (c == 'd' || c == 'i')
		ft_parse_int(table);
	else if (c == 'u')
		ft_parse_unsigned_int(table);
	else if (c == 'x')
		ft_parse_hex_sm(table);
	else if (c == 'X')
		ft_parse_hex_bg(table);
	else if (c == '%')
		ft_parse_percent(table);
}
