/* ************************************************************************** */
/*                                                                            */
/*   ft_lstlast.c                                                             */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2021/11/08                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!(lst))
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
