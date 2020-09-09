/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pminne <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 13:57:57 by pminne       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/13 20:04:45 by pminne      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

static size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int		checkstr(const char *haystack, const char *needle)
{
	size_t w;

	w = 0;
	while (needle[w] != '\0')
	{
		if (haystack[w] != needle[w])
			return (1);
		w++;
	}
	return (0);
}

char			*ft_strnstr(const char *hk, const char *nl, size_t len)
{
	size_t i;

	i = 0;
	if (nl[0] == '\0')
		return ((char*)hk);
	while (i < len)
	{
		if (hk[i] == nl[0])
		{
			if (checkstr(&hk[i], nl) == 0 && (i + ft_strlen(nl)) <= len)
				return ((char *)&hk[i]);
		}
		i++;
	}
	return (NULL);
}
