/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:04:32 by fgrisell          #+#    #+#             */
/*   Updated: 2020/11/22 14:03:53 by fgrisell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_fd(size_t n, int base, int fd, int reg)
{
	char			num;
	size_t			i;
	size_t			j;
	int				sign;

	i = n;
	j = base;
	sign = n < 0 ? -1 : 1;
	while (i /= base)
		j *= base;
	if (sign < 0)
		write(fd, "-", 1);
	while (j /= base)
	{
		i = ((n / j) * sign);
		if (i > 9 && i < 35)
			num = (char)(i + (reg ? 55 : 87));
		else if (i >= 0 && i <= 9)
			num = (char)(i + '0');
		write(fd, &num, 1);
		n %= j;
	}
}
