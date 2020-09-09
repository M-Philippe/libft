/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pminne <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/22 00:13:34 by pminne       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/22 00:13:38 by pminne      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list *link;

	if (!(link = malloc(sizeof(t_list))))
		return (NULL);
	link->content = content;
	link->next = NULL;
	return (link);
}
