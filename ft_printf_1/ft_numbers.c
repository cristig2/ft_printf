/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgallar <crgallar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:21:06 by crgallar          #+#    #+#             */
/*   Updated: 2023/10/04 13:27:37 by crgallar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* La función ft_numlen:
Calcula & devuelve la longuitud de un entero.
*/

int	ft_numlen(int num)
{
	int	len;

	len = 0;
	if (num <= 0)
		len++;
	while (num)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

/* La función ft_itoa:
Toma un número entero y lo convierte en una string que representa ese número
*/

char	*ft_itoa(int num)
{
	char		*str;
	int			len;
	long int	nb;

	nb = num;
	len = ft_numlen(nb);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[0] = '0';
	str[len] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		len--;
		str[len] = nb % 10 + 48;
		nb = nb / 10;
	}
	return (str);
}

/* La función ft_number:

Imprime un número decimal (base 10).
Imprime un número entero en base 10.
Maneja casos especiales como el número más negativo (-2147483648).
Utiliza recursión para imprimir cada dígito por separado.
Incrementa el contador (len) según la cantidad de caracteres impresos.*/

void	ft_number(int num, int *len)
{
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	if (num < 0)
	{
		ft_putcharacter_length('-', len);
		ft_number(num * -1, len);
	}
	else
	{
		if (num > 9)
		{
			ft_number(num / 10, len);
		}
		ft_putcharacter_length(num % 10 + '0', len);
	}
}
/*
int	main(void)
{
	int num = -345;
	int len = 0;

	ft_number(num, &len);
	printf("\nLongitud de la variable num: %d\n", len);
	return (0);
}
*/

void	ft_unsigned(unsigned int num, int *len)
{
	if (num < 0)
		num = num * -1;
	if (num > 9)
	{
		ft_unsigned(num / 10, len);
	}
	ft_putcharacter_length(num % 10 + '0', len);
}

int	main(void)
{
	unsigned int num = -323;
	int len = 0;

	ft_unsigned(num, &len);
	printf("\nLongitud de la%d variable num: %d\n", len);
	return (0);
}
