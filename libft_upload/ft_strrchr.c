/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galpers <galpers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 00:09:25 by galpers           #+#    #+#             */
/*   Updated: 2022/02/21 15:25:00 by galpers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;

	if (c == 0)
		return ((char *)s + (int)(ft_strlen(s)));
	res = 0;
	while (*s)
	{
		if (*s == (char)c)
			res = (char *)s;
		s++;
	}
	return (res);
}
