/* ************************************************************************** */
/*                                                                            */
/*   ft_itoa.c                                                                */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2021/10/21                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(long int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	ft_line(char *str, long int n, int len)
{
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		str[len - 1] = '0' + (n % 10);
		n = n / 10;
		len --;
	}
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	long int	number;

	number = n;
	len = ft_size(number);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_line(str, number, len);
	return (str);
}
//-2 147 483 648 --- 2 147 483 647
