/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharvel <mcharvel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:37:35 by mcharvel          #+#    #+#             */
/*   Updated: 2022/09/16 11:48:57 by mcharvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*ptr;

	i = 0;
	len = ft_strlen(s1);
	ptr = malloc(sizeof(char) * len + 1);
	if (ptr == 0)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*
int        main(void)
{
    printf("%s\n", ft_strdup("Hello world!"));
    return (0);
}
*/