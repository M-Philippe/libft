/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pminne <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/13 18:35:21 by pminne       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 16:47:01 by pminne      ###    #+. /#+    ###.fr     */
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

static	size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t i;

	i = 0;
	while (i < maxlen && s[i])
		i++;
	return (i);
}

static	char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

static char		*ft_strncat(char *s1, const char *s2, size_t size, size_t count)
{
	size_t	w;

	w = 0;
	while (count < size - 1)
	{
		s1[count] = s2[w];
		count++;
		w++;
	}
	s1[count] = '\0';
	return (s1);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	w;
	size_t	dstl;

	i = 0;
	w = 0;
	dstl = ft_strnlen(dst, size);
	if (size == 0)
		return (ft_strlen(src));
	else if (ft_strlen(dst) >= size)
		return (dstl + ft_strlen(src));
	while (dst[i])
		i++;
	if (ft_strlen(src) < size - dstl)
		dst = ft_strcat(dst, src);
	else
		dst = ft_strncat(dst, src, size, i);
	return (dstl + ft_strlen(src));
}
