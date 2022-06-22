/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmillan <dmillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:01:37 by eleon             #+#    #+#             */
/*   Updated: 2022/06/22 23:45:57 by dmillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include "../libft/libft.h"

typedef struct s_print
{
	va_list	args;
	char	type;
	int		length;
	int		zero;
	int		width;
	int		prc;
	int		minus;
	char	sign;
	int		dot;
	int		alt;
	int		space;
	int		plus;
	int		is_zero;
}				t_print;

int		ft_printf(const char *format, ...);
void	ft_parse_type(char c, t_print *table);
t_print	*ft_clear_table(t_print	*table);

void	ft_flag_minus(t_print	*table);
void	ft_flag_plus(t_print	*table);
void	ft_flag_width(t_print	*table);
int		ft_flag_dot(const char *format, int start,
			t_print *table);
int		ft_flag_digit(const char *format, int start,
			t_print *table);

void	ft_parse_char(t_print *table);
void	ft_parse_string(t_print *table);
void	ft_parse_percent(t_print *table);
void	ft_parse_int(t_print *table);
void	ft_parse_unsigned_int(t_print *table);
void	ft_parse_ptr(t_print *table);
void	ft_parse_hex_sm(t_print *table);
void	ft_parse_hex_bg(t_print *table);

int		ft_is_type(int c);
t_print	*ft_clear_table(t_print	*table);
void	ft_parse_type(char c, t_print *table);
void	ft_align_char(t_print *table, int minus);
char	*ft_ulitoa_base(unsigned long int n, char *base);
void	ft_putchar_count(char c, t_print *table);
void	ft_putstr_count(char *str, int len, t_print *table);
void	ft_print_width(t_print *table, int len);
void	ft_print_extra(t_print *table, int len);
void	ft_print_flags(char *str, int len, t_print	*table);

#endif