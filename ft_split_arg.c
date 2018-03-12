/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 01:53:58 by obenazzo          #+#    #+#             */
/*   Updated: 2016/09/08 09:44:25 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**while_blank(char *str, char **words, int save, int w)
{
	int s;

	s = 0;
	while (str[s] && (str[s] == ' ' || str[s] == '\n' || str[s] == 9))
		s++;
	if (save)
		return (while_char(str + s, words, save, w));
	if (str[s])
		return (while_char(str + s, words, save, w));
	words[w] = 0;
	return (words);
}

char	**while_char(char *str, char **words, int save, int w)
{
	int		s;

	s = 0;
	while (str[s] && str[s] != ' ' && str[s] != '\n' && str[s] != 9)
		s++;
	if (save)
	{
		if (str[s])
			return (while_blank(str + s, words, save + 1, w));
		words = (char**)pr_malloc(sizeof(char *) * (save + 1) + 1);
		return (while_blank(str + s - w, words, 0, 0));
	}
	if (s)
		words[w++] = (char*)pr_malloc(sizeof(char) * s + 1);
	s = 0;
	while (str[s] && str[s] != ' ' && str[s] != '\n' && str[s++] != 9)
		words[w - 1][s - 1] = str[s - 1];
	if (s)
		words[w - 1][s] = '\0';
	if (str[s])
		return (while_blank(str + s, words, save, w));
	words[w] = 0;
	return (words);
}

char	**ft_split_arg(char *str)
{
	char		**words;
	int			s;

	s = 0;
	while (str[s])
	{
		if (!ft_strchr("-+0123456789 \t\n", str[s]))
			error();
		s++;
	}
	words = NULL;
	return (while_blank(str, words, 1, s));
}
