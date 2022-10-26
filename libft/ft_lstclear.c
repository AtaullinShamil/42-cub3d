/* ************************************************************************** */
/*                                                                            */
/*   ft_lstclear.c                                                            */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2021/11/08                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*l;
	t_list	*to_del;

	if (!lst || !(*lst) || !del)
		return ;
	l = *lst;
	while (l)
	{
		to_del = l;
		l = l->next;
		del(to_del->content);
		free(to_del);
	}
	(*lst) = NULL;
}
