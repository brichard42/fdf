/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:35:04 by brichard          #+#    #+#             */
/*   Updated: 2019/02/20 16:45:30 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define FMIN res->f_minus
# define FPLU res->f_plus
# define FSPA res->f_space
# define FZER res->f_zero
# define FHAS res->f_hash
# define WIDTH res->width
# define PREC res->prec
# define LEN res->len
# define CONV res->conv
# define STR res->str
# define SSIZE res->str_size
# define NSIZE res->num_size
# define NEG res->neg

# define H_BASE_CAP "0123456789ABCDEF"
# define H_BASE_LOW "0123456789abcdef"

# define TAB_SIZE 18

typedef struct				s_parse
{
	int		f_minus;
	int		f_plus;
	int		f_space;
	int		f_zero;
	int		f_hash;
	int		width;
	int		prec;
	int		len;
	char	conv;
	char	*str;
	int		str_size;
	int		num_size;
	int		neg;
}							t_parse;

typedef unsigned long long	t_ullong;
typedef int					(*t_exf)(t_parse *, va_list *);

typedef struct				s_exfstruct
{
	char	c;
	t_exf	exf;
}							t_exfst;

/*
** TAB_MAKER.C
*/
void						exf_tab_maker(t_exfst *exf_tab);

/*
** UTILS.C
*/
int							check_conv(char c);
void						skip_param(const char **s);
void						ini_res(t_parse *res);

/*
** FT_PRINTF.C
*/
int							ft_printf(const char *format, ...);

/*
** PARSING.C
*/
int							parsing(va_list *ap, t_parse *res, char **tmp);

/*
** parsing_FFUN.C
*/
int							p_minu(t_parse *res);
int							p_plus(t_parse *res);
int							p_spac(t_parse *res);
int							p_hash(t_parse *res);
int							p_zero(t_parse *res);

/*
** EX_CFUN.C
*/
int							ex_stri(t_parse *res, va_list *ap);
int							ex_char(t_parse *res, va_list *ap);
int							ex_ints(t_parse *res, va_list *ap);
int							ex_octo(t_parse *res, va_list *ap);

/*
** EX_CFUN_2.C
*/
int							ex_unsi(t_parse *res, va_list *ap);
int							ex_hexa(t_parse *res, va_list *ap);
int							ex_flop(t_parse *res, va_list *ap);
int							ex_point(t_parse *res, va_list *ap);

/*
** PREF_WPFUN.C
*/
int							width(t_parse *res);
int							prec(t_parse *res);
int							prec_stri(t_parse *res);
int							prefix(t_parse *res);
int							put_neg(t_parse *res);

/*
** GET_LENGTH.C
*/
void						get_length(t_parse *res, va_list *ap, t_ullong *nb);
void						get_lint(t_parse *res, va_list *ap, long long *nb);
void						get_lflop(t_parse *res, va_list *ap,
									long double *lf);

/*
**	GET_INT.C
*/
long long					get_int(t_parse *res, va_list *ap);
long long					get_hh_int(t_parse *res, va_list *ap);
long long					get_h_int(t_parse *res, va_list *ap);
long long					get_l_int(t_parse *res, va_list *ap);
long long					get_ll_int(t_parse *res, va_list *ap);

/*
**	GET_HEX_OCT.C
*/
t_ullong					get_hex_oct(t_parse *res, va_list *ap);
t_ullong					get_hh_hex_oct(t_parse *res, va_list *ap);
t_ullong					get_h_hex_oct(t_parse *res, va_list *ap);
t_ullong					get_l_hex_oct(t_parse *res, va_list *ap);
t_ullong					get_ll_hex_oct(t_parse *res, va_list *ap);

/*
**	GET_FLOATS.C
*/
long double					get_flop(t_parse *res, va_list *ap);
long double					get_l_flop(t_parse *res, va_list *ap);

/*
**	BONUS.C
*/
void						wild_card(t_parse *res, va_list *ap);
int							bonus_f_cap(t_parse *res, va_list *ap);
int							bonus_d_cap(t_parse *res, va_list *ap);
int							bonus_u_cap(t_parse *res, va_list *ap);
int							bonus_o_cap(t_parse *res, va_list *ap);

/*
**	BONUS_2.C
*/
#endif
