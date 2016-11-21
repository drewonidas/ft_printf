/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdlamini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 13:52:10 by mdlamini          #+#    #+#             */
/*   Updated: 2016/08/12 14:20:33 by mdlamini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	cnt_words(char const *s, char c)
{
	int		i;
	int		in_word;

	i = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c && in_word == 1)
		{
			in_word = 0;
			continue ;
		}
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			i++;
		}
		s++;
	}
	return (i);
}

static int	word_len(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**result;
	int		index;
	int		num_words;

	index = 0;
	num_words = cnt_words(s, c);
	result = (char **)malloc((sizeof(char *) * (num_words)) + (sizeof(char *)));
	if (result == NULL)
		return (NULL);
	while (num_words--)
		{
			while (*s == c && *s != '\0')
				s++;
			result[index] = ft_strsub((const char *)s, 0, word_len(s, c));
			if (result[index] == NULL)
				return (NULL);
			s = s + word_len(s, c);
			index++;
		}
	result[index] = NULL;
	return (result);
}
