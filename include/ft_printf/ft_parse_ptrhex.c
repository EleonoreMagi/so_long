/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ptrhex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmillan <dmillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 23:30:56 by dmillan           #+#    #+#             */
/*   Updated: 2022/01/11 05:30:45 by dmillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ulitoa_base(unsigned long int n, char *base)
{
	char					*str;
	unsigned long int		nbr;
	int						size;

	nbr = n;
	size = 1;
	n /= ft_strlen(base);
	while (n != 0)
	{
		n /= ft_strlen(base);
		size++;
	}
	str = (char *)malloc(size + 1);
	if (!str)
		return (0);
	str[size--] = '\0';
	while (nbr > 0)
	{
		str[size--] = base[nbr % ft_strlen(base)];
		nbr /= ft_strlen(base);
	}
	if (size == 0 && str[1] == '\0')
		str[0] = '0';
	return (str);
}

void	ft_parse_ptr(t_print *table)
{
	unsigned long int	ptr;
	char				*c_ptr;

	ptr = va_arg(table->args, unsigned long int);
	c_ptr = ft_ulitoa_base(ptr, "0123456789abcdef");
	ft_print_flags(c_ptr, ft_strlen(c_ptr), table);
	ft_clear_table(table);
	free(c_ptr);
}

void	ft_parse_hex_sm(t_print *table)
{
	unsigned long int	hex;
	char				*c_hex;

	hex = va_arg(table->args, unsigned int);
	if (hex == 0)
		table->is_zero = 1;
	c_hex = ft_ulitoa_base((unsigned long int)hex, "0123456789abcdef");
	if (!(table->is_zero && table->dot && !table->prc))
		ft_print_flags(c_hex, ft_strlen(c_hex), table);
	else
		ft_print_flags("", 0, table);
	ft_clear_table(table);
	free(c_hex);
}

void	ft_parse_hex_bg(t_print *table)
{
	unsigned long int	hex;
	char				*c_hex;

	hex = (unsigned long int)va_arg(table->args, unsigned int);
	if (hex == 0)
		table->is_zero = 1;
	c_hex = ft_ulitoa_base((unsigned long int)hex, "0123456789ABCDEF");
	if (!(table->is_zero && table->dot && !table->prc))
		ft_print_flags(c_hex, ft_strlen(c_hex), table);
	else
		ft_print_flags("", 0, table);
	ft_clear_table(table);
	free(c_hex);
}
