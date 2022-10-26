/* ************************************************************************** */
/*                                                                            */
/*   ft_split.c                                                               */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2021/10/21                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_free(char **res, int words)
{
	while (words--)
		free(res[words]);
	return (0);
}

static int	ft_count_lines(char const *s, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && s[i] != '\0'
			&& (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static void	ft_words(char *dst, char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
}

static int	ft_lines(char **res, const char *s, char c)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c || s[i] == '\0')
			i++;
		else
		{
			j = 0;
			while (s[i + j] != c && s[i + j] != '\0')
				j++;
			res[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (!res[word])
				return (ft_free(res, word - 1));
			ft_words(res[word], s + i, c);
			i = i + j;
			word++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;

	if (!s)
		return (NULL);
	words = ft_count_lines(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	res[words] = NULL;
	if (ft_lines(res, s, c) == 0)
		return (NULL);
	return (res);
}
