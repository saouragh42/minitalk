/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:59:17 by saouragh          #+#    #+#             */
/*   Updated: 2024/11/19 16:33:36 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *str, char c, int flag)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	if (flag == 0)
	{
		while (str[i] && str[i] != c)
			i++;
		return (i);
	}
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			wc++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (wc);
}

static char	*ft_strncpy(char *str, int len)
{
	char	*dst;
	int		i;

	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (str[i] && i < len)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static void	ft_free_split(char **spl, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(spl[i]);
		i++;
	}
	free(spl);
}

static char	**ft_split_core(char const *s, char c, char **spl)
{
	int	len;
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			len = ft_word_count((char *)(s + i), c, 0);
			spl[j] = ft_strncpy((char *)(s + i), len);
			if (!spl[j])
				return (ft_free_split(spl, j), NULL);
			j++;
			i += len;
		}
	}
	spl[j] = NULL;
	return (spl);
}

char	**ft_split(char const *s, char c)
{
	char			**spl;

	if (!s)
		return (NULL);
	spl = malloc(sizeof(char *) * (ft_word_count(s, c, 1) + 1));
	if (!spl)
		return (NULL);
	return (ft_split_core(s, c, spl));
}
