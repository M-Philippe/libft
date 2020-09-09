/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pminne <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 14:18:41 by pminne       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 13:50:41 by pminne      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*ptr;
	const unsigned char *ptsrc;

	ptr = dest;
	ptsrc = src;
	i = 0;
	while (i < n)
	{
		ptr[i] = ptsrc[i];
		if (ptsrc[i] == (unsigned char)c)
			return (&ptr[i + 1]);
		i++;
	}
	return (NULL);
}
