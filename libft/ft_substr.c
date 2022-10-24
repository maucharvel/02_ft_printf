/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharvel <mcharvel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:07:03 by mcharvel          #+#    #+#             */
/*   Updated: 2022/09/19 12:36:04 by mcharvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (start >= ft_strlen(s))
	{
		sub = (char *)malloc(1);
		*sub = 0;
		return (sub);
	}
	sub = 0;
	s = s + start;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	sub = malloc(len + 1);
	if (sub == 0)
		return (0);
	ft_strlcpy(sub, s, len + 1);
	return (sub);
}
