/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pminne <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 15:06:54 by pminne       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 16:13:35 by pminne      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char					*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	w;
	char	*dst;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	w = 0;
	if (!(dst = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[w])
		dst[i++] = s2[w++];
	dst[i] = '\0';
	return (dst);
}
