/* ************************************************************************** */
/*                                                                            */
/*   ft_substr.c                                                              */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2021/10/19                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	new_len;
	size_t	i;

	if (!s)
		return (NULL);
	new_len = ft_strlen(s) - start;
	i = 0;
	if (start >= ft_strlen(s))
	{
		str = (char *)malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (len <= new_len)
		new_len = len;
	str = (char *)malloc(sizeof(char) * (new_len + 1));
	if (!str)
		return (NULL);
	while (s[i] && i < new_len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
