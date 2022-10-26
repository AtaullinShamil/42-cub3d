/* ************************************************************************** */
/*                                                                            */
/*   ft_lstnew.c                                                              */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2021/11/08                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*begin_pointer;

	begin_pointer = (t_list *)malloc(sizeof(t_list));
	if (!begin_pointer)
		return (NULL);
	begin_pointer -> content = content;
	begin_pointer -> next = NULL;
	return (begin_pointer);
}
