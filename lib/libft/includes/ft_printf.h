/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:58:24 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/17 10:01:22 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# define DEC "0123456789"
# define HDL "0123456789abcdef"
# define HDU "0123456789ABCDEF"

typedef struct s_option
{
	unsigned char	flag;
	int				w;
	int				precision;
	int				padding;
	char			*out;
	int				len;
}	t_option;

typedef int	(*t_fct)(t_option *, va_list);

int		ft_printf(const char *format, ...);

int		ft_max(int a, int b);
void	init_option(t_option *opt);
int		find_flag(const char c, unsigned char *flag);
int		find_identifier(const char c);

int		put_percent(t_option *opt, va_list ap);
int		put_chr(t_option *opt, va_list ap);
int		put_str(t_option *opt, va_list ap);
int		put_nbr(t_option *opt, va_list ap);
int		put_unbr(t_option *opt, va_list ap);
int		put_ptr(t_option *opt, va_list ap);
int		put_xunbr_lower(t_option *opt, va_list ap);
int		put_xunbr_upper(t_option *opt, va_list ap);

int		ft_nbrlen(long n, int base_len, t_option *opt);
int		ft_unbrlen(unsigned long n, int base_len, t_option *opt);
void	decide_nbr_sign(t_option *opt, long nbr, int nbr_len);
void	decide_xunbr_hash(t_option *opt, int xunbr_len, int upper);
void	unbrtostr(char *str_nbr, unsigned long nbr, int nbr_len, char *base);

#endif
