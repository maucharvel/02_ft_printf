/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharvel <mcharvel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:17:08 by mcharvel          #+#    #+#             */
/*   Updated: 2022/09/15 09:23:25 by mcharvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[i] == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle [j] && i + j < len)
		{
			if (needle[j + 1] == 0)
				return ((char *)haystack + i);
			j++;
		}
	i++;
	}
	return (0);
}
/*
int main()
{
    char *ret;

    ret = ft_strnstr("lorem ipsum dolor sit amet", "rem", 10);

    printf("%s\n", ret);
    printf("%s\n", ft_strnstr("lorem ipsum dolor sit amet", "dolor", 17));

    return (0);
}
*/