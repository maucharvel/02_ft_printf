/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharvel <mcharvel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:44:26 by mcharvel          #+#    #+#             */
/*   Updated: 2022/09/09 11:17:04 by mcharvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	d = (char *)dst;
	s = (char *)src;
	i = 0;
	if (!dst && !src)
		return (0);
	if (d > s && i < len)
	{
		while (len--)
		{
			d[len] = s[len];
		}
	}
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}	
	return (dst);
}

/*int	main(void)
{
	char	dest[20];
	char	src[20] = "42Urduliz";
	char	*ans;

	ans = ft_memmove(dest, src, 11);
	printf("%s", ans);
	return (0);
}
*/