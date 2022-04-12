/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_diu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmillan <dmillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 01:41:43 by eleon             #+#    #+#             */
/*   Updated: 2022/01/11 05:31:08 by dmillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_int(t_print *table)
{
	long		num;
	char		*c_num;

	num = (long)va_arg(table->args, int);
	if (num >= 0)
		table->sign = '+';
	else if (num < 0)
	{
		table->sign = '-';
		num *= -1;
	}
	if (num == 0)
		table->is_zero = 1;
	c_num = ft_ulitoa_base((unsigned long int)num, "0123456789");
	if (!(table->is_zero && table->dot && !table->prc))
		ft_print_flags(c_num, ft_strlen(c_num), table);
	else
		ft_print_flags("", 0, table);
	ft_clear_table(table);
	free(c_num);
}

void	ft_parse_unsigned_int(t_print *table)
{
	unsigned int	num;
	char			*c_num;

	num = va_arg(table->args, unsigned int);
	if (num == 0)
		table->is_zero = 1;
	c_num = ft_ulitoa_base((unsigned long int)num, "0123456789");
	if (!(table->is_zero && table->dot && !table->prc))
		ft_print_flags(c_num, ft_strlen(c_num), table);
	else
		ft_print_flags("", 0, table);
	ft_clear_table(table);
	free (c_num);
}
