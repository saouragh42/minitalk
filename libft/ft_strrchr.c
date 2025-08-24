/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:08:36 by saouragh          #+#    #+#             */
/*   Updated: 2024/11/17 23:19:53 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;

	i = ft_strlen(s);
	while (i > 0)
	{
		if ((char) c == s[i])
			return ((char *) s + i);
		i--;
	}
	if (s[i] == (char) c)
		return ((char *) s + i);
	return (NULL);
}
