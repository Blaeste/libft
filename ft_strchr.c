/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:05:35 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/06 10:09:15 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	tofind;

	tofind = (unsigned char)c;
	while (*s)
	{
		if ((unsigned char)*s == tofind)
			return ((char *)s);
		s++;
	}
	if (tofind == '\0')
		return ((char *)s);
	return (0);
}
