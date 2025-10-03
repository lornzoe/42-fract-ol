/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:55:37 by lyanga            #+#    #+#             */
/*   Updated: 2025/10/03 14:16:55 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atod(const char *str)
{
	double	result;
	double	power;
	int		i;
	int		sign;

	result = 0.0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		result = (result * 10.0) + (str[i++] - '0');
	if (str[i++] == '.')
	{
		power = 0.1;
		while (str[i] >= '0' && str[i] <= '9')
		{
			result = result + (str[i++] - '0') * power;
			power /= 10.0;
		}
	}
	return (result * sign);
}
