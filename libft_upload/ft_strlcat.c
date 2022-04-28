/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galpers <galpers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 00:00:30 by galpers           #+#    #+#             */
/*   Updated: 2022/02/21 15:17:09 by galpers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0' && i < size)
	{
		i++;
	}
	while (src[j] != '\0' && ((i + j + 1) < size))
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i < size)
	{
		dest[i + j] = '\0';
	}	
	return (i + ft_strlen(src));
}
