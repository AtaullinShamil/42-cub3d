/* ************************************************************************** */
/*                                                                            */
/*   ft_memset.c                                                              */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2021/10/07                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;

	str = (char *)b;
	while (len--)
		*str++ = (char)c;
	return (b);
}
