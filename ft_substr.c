/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_substr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pminne <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 15:03:01 by pminne       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/22 19:27:19 by pminne      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
	{
		if (!(dst = (char*)malloc(sizeof(char))))
			return (NULL);
		dst[0] = '\0';
		return (dst);
	}
	i = 0;
	if (!(dst = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (i < len && s[start])
		dst[i++] = s[start++];
	dst[i] = '\0';
	return (dst);
}
