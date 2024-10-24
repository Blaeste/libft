/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:22:53 by eschwart          #+#    #+#             */
/*   Updated: 2024/10/17 12:16:24 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	tofind;

	tofind = (unsigned char)c;
	while (*s)
	{
		if (*s == tofind)
			return ((char *)s);
		s++;
	}
	if (tofind == '\0')
		return ((char *)s);
	return (0);
}
