/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pminne <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/22 01:52:05 by pminne       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/22 01:52:07 by pminne      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*add_link;

	new_lst = NULL;
	add_link = NULL;
	if (!(new_lst = ft_lstnew(lst->content)) || !lst)
		return (NULL);
	new_lst->content = f(new_lst->content);
	lst = lst->next;
	while (lst)
	{
		if (!(add_link = ft_lstnew(lst->content)))
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		add_link->content = f(add_link->content);
		ft_lstadd_back(&new_lst, add_link);
		lst = lst->next;
	}
	return (new_lst);
}
