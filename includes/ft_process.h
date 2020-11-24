/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:05:10 by fgrisell          #+#    #+#             */
/*   Updated: 2020/11/23 10:54:55 by fgrisell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PROCESS_H
# define __FT_PROCESS_H
# include "./libftprintf.h"

int		ft_process(t_arg *pars, va_list *arg_ptr);
int		ft_proc_char(t_arg *pars, va_list *arg_ptr);
int		ft_proc_str(t_arg *pars, va_list *arg_ptr);
int		ft_proc_d_i(t_arg *pars, va_list *arg_ptr);
int		ft_proc_uint(t_arg *pars, va_list *arg_ptr);
int		ft_proc_pointer(t_arg *pars, va_list *arg_ptr);
int		ft_proc_percent(t_arg *pars);
int		ft_proc_x_x(t_arg *pars, va_list *arg_ptr);
int		ft_putchar_width(int c, int width);
int		ft_lennbr_16(size_t nbr);
void	ft_putstr_prec(char *s, int prec);
int		ft_pars_flag(const char *format, t_arg *pars);
int		ft_pars_width(const char *format, t_arg *pars, va_list *arg_ptr);
int		ft_pars_precision(const char *format, t_arg *pars, va_list *arg_ptr);
int		ft_pars_type(const char *format, t_arg *pars);
#endif
