/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galpers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 23:46:58 by galpers           #+#    #+#             */
/*   Updated: 2022/04/13 11:24:18 by galpers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	long long	res;
	int			minus;

	res = 0;
	minus = 1;
	while (*str != '\0' && ft_strchr("\t\n\v\f\r ", *str) != NULL)
		str++;
	if (*str != '\0' && ft_strchr("+-", *str) != NULL)
		if (*str++ == '-')
			minus *= -1;
	while (*str != '\0' && ft_strchr("0123456789", *str) != NULL)
	{
		res *= 10;
		res += *str - '0';
		str++;
	}
	return (res * minus);
}
