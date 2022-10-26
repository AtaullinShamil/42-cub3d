/* ************************************************************************** */
/*                                                                            */
/*   ft_memcpy.c                                                              */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2021/10/07                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ds;
	char	*sr;

	ds = (char *)dst;
	sr = (char *)src;
	if (!dst && !src)
		return (dst);
	while (n--)
		*ds++ = *sr++;
	return (dst);
}
