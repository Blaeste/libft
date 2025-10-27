/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:22:53 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/27 10:04:57 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	tofind;

	tofind = (char)c;
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
