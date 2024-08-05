/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabboud <mabboud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:28:46 by mabboud           #+#    #+#             */
/*   Updated: 2024/07/28 11:29:17 by mabboud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define INT_MIN -2147483648
#define INT_MAX 2147483647

int	ft_atoi(const char	*nptr, int *error_limits)
{
	long long int	val;
	int				signe;

	*error_limits = 0;
	val = 0;
	signe = 1;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '-' || *nptr == '+' )
	{
		if (*nptr == '-')
			signe = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		val = val * 10 + signe * (*nptr - '0');
		if (val > INT_MAX || val < INT_MIN
			|| (!val && (*nptr == '-' || *nptr == '+')))
			*error_limits = 1;
		nptr++;
	}
	if (*nptr && *nptr != ' ' && !(*nptr >= '0' && *nptr <= '9'))
		*error_limits = 1;
	return (val);
}
