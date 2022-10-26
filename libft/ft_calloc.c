/* ************************************************************************** */
/*                                                                            */
/*   ft_calloc.c                                                              */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2021/10/14                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	ret = malloc(size * count);
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, (size * count));
	return (ret);
}
