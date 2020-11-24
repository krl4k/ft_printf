/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:03:57 by fgrisell          #+#    #+#             */
/*   Updated: 2020/11/22 15:38:06 by fgrisell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_process.h"

int	ft_process(t_arg *pars, va_list *arg_ptr)
{
	int ret_value;

	ret_value = 0;
	if (pars->type == 'c')
		ret_value = ft_proc_char(pars, arg_ptr);
	else if (pars->type == 's')
		ret_value = ft_proc_str(pars, arg_ptr);
	else if (pars->type == 'd' || pars->type == 'i')
		ret_value = ft_proc_d_i(pars, arg_ptr);
	else if (pars->type == 'u')
		ret_value = ft_proc_uint(pars, arg_ptr);
	else if (pars->type == 'p')
		ret_value = ft_proc_pointer(pars, arg_ptr);
	else if (pars->type == '%')
		ret_value = ft_proc_percent(pars);
	else if (pars->type == 'x' || pars->type == 'X')
		ret_value = ft_proc_x_x(pars, arg_ptr);
	else
		return (-1);
	return (ret_value);
}
