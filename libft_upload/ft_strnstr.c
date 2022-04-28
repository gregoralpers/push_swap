/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galpers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 00:08:43 by galpers           #+#    #+#             */
/*   Updated: 2022/02/23 12:13:59 by galpers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*dst;
	char	*src;

	i = 0;
	dst = (char *)haystack;
	src = (char *)needle;
	if (*src == '\0' || src == NULL)
		return (dst);
	while (dst[i] && i < len)
	{
		j = 0;
		while (src[j] == dst[i + j] && i + j < len)
		{
			if (src[j + 1] == '\0')
			{
				return (dst + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
