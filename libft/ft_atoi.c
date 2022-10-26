/* ************************************************************************** */
/*                                                                            */
/*   ft_atoi.c                                                                */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2021/10/14                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	long int	negative;
	long int	res;

	negative = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' \
			||str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		negative = -1;
	if (negative == -1 || str[i] == '+')
		i++;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		if (res * negative <= -2147483649)
			return (0);
		else if (res * negative >= 2147483648)
			return (-1);
		i++;
	}
	return (res * negative);
}
