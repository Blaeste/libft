/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:45:12 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/23 11:10:08 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_dig(long n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	ft_fill_rslt(char *result, long nb, size_t len)
{
	size_t	i;

	if (nb < 0)
	{
		result[0] = '-';
		nb *= -1;
		i = len - 1;
		while (i > 0)
		{
			result[i] = (nb % 10) + '0';
			nb /= 10;
			i--;
		}
	}
	else
	{
		i = len;
		while (i-- > 0)
		{
			result[i] = (nb % 10) + '0';
			nb /= 10;
		}
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	long	nb;
	size_t	len;

	nb = n;
	len = ft_count_dig(nb);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	result[len] = '\0';
	ft_fill_rslt(result, nb, len);
	return (result);
}
