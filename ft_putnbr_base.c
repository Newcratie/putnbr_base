/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 14:55:09 by vimucchi          #+#    #+#             */
/*   Updated: 2017/08/09 21:39:32 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && s1[i] == s2[i] && i < n - 1)
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int l;

	i = 0;
	l = 0;
	if (to_find[0] == '\0')
		return (str);
	while (to_find[l] != '\0')
		l++;
	while (str[i] != '\0')
	{
		if (ft_strncmp(str + i, to_find, l) == 0)
			return (str + i);
		i++;
	}	
	return (0);
}


int		ft_lbase(char *base)
{
	int i;
	
	i = 0;
	while (base[i])
	{
		if (ft_strstr(base + i, &base[i]) == 0)
			return (0);	
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int i;
	int nb_conv[64];
	int lbase;
	int neg;

	i = 0;
	lbase = ft_lbase(base);
	if (nbr < 0)
	{
		nbr = nbr * -1;
		neg = 1;
	}
	while (nbr > 0 && lbase != 0)
	{
		nb_conv[i] = nbr % lbase;
		nbr = nbr / lbase;
		i++;
	}
	if (neg == 1 && lbase != 0)
		ft_putchar(45);
	while (i > 0 && lbase != 0)
	{
		ft_putchar(base[nb_conv[i - 1]]);
		i--;
	}
}

int		main(void)
{
	ft_putnbr_base(-544545, "0123556789ABCDEF");
	return (0);
}
