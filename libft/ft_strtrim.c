/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharvel <mcharvel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:30:41 by mcharvel          #+#    #+#             */
/*   Updated: 2022/09/21 09:24:08 by mcharvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;

	if (s1 == 0 || set == 0)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (len && ft_strchr(set, s1[len]))
		len--;
	return (ft_substr (s1, 0, len + 1));
}

/*
int main(void)
{
	char *s1 = "abababa";
	char *set = "a";
	char *res;
	res = ft_strtrim(s1, set);
	printf("%s", res);
	return (0);
}
*/