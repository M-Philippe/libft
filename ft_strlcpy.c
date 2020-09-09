/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pminne <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 14:22:58 by pminne       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 16:47:25 by pminne      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

static	size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t			ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;

	if (dst == NULL || src == NULL)
		return (0);
	else if (size == 0)
		return (ft_strlen(src));
	i = 0;
	if (ft_strlen(src) + 1 < size)
	{
		while (i < ft_strlen(src) + 1)
		{
			dst[i] = src[i];
			i++;
		}
	}
	else
	{
		while (i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
