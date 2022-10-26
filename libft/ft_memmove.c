/* ************************************************************************** */
/*                                                                            */
/*   ft_memmove.c                                                             */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2021/10/07                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*ds;
	const char	*sr;

	ds = (char *)dst;
	sr = (char *)src;
	if (!dst && !src)
		return (NULL);
	if (sr < ds)
	{
		while (len--)
			ds[len] = sr[len];
	}
	else
	{
		while (len--)
			*ds++ = *sr++;
	}
	return (dst);
}
