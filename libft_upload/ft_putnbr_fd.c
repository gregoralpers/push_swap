/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galpers <galpers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 23:59:17 by galpers           #+#    #+#             */
/*   Updated: 2022/02/21 15:26:39 by galpers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putnbr_fd(-214, fd);
			ft_putnbr_fd(7483648, fd);
			return ;
		}
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n >= 0 && n < 10)
	{
		n = n + '0';
		ft_putchar_fd(n, fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		n = n % 10 + '0';
		ft_putchar_fd(n, fd);
	}
}
