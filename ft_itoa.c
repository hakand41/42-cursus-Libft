/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeger <hdeger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:36:11 by hdeger            #+#    #+#             */
/*   Updated: 2022/12/07 12:40:36 by hdeger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int c)
{
	int	i;

	i = 0;
	if (c <= 0)
	{
		i = 1;
	}
	while (c)
	{
		i++;
		c = c / 10;
		if (c == 0)
			break ;
	}
	return (i);
}

static char	*nummaker(int n, int s, int number, char *str)
{
	while (s >= 0)
	{
		number = n % 10;
		str[s--] = number + 48;
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		strlength;
	char	*str;
	int		num;
	int		sign;

	strlength = intlen(n);
	num = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(sizeof(char) * strlength + 1);
	if (!str)
		return (0);
	sign = 0;
	if (n < 0)
	{
		n = -n;
		sign = -1;
	}
	str[strlength--] = '\0';
	nummaker(n, strlength, num, str);
	if (sign == -1 && str[0] == '0')
		str[0] = '-';
	return (str);
}
