/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galpers <galpers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 23:52:04 by galpers           #+#    #+#             */
/*   Updated: 2022/02/21 17:49:20 by galpers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length(int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
	{
		return (1);
	}
	if (nbr < 0)
	{
		i = 1;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	int		len;
	char	*number;
	int		k;

	k = 0;
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	len = length(nbr);
	number = (char *)malloc(sizeof (char) * (len + 1));
	if (number == NULL)
		return (NULL);
	if (nbr < 0)
	{
		number [0] = '-';
		k = 1;
	}
	number[len] = '\0';
	nbr = ((nbr < 0) * -2 + 1) * nbr;
	while (len > k)
	{
		number[len - 1] = (nbr % 10) + 48;
		nbr = nbr / 10;
		len--;
	}
	return (number);
}
