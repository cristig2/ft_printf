/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgallar <crgallar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:21:06 by crgallar          #+#    #+#             */
/*   Updated: 2023/10/02 09:53:25 by crgallar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* La función ft_number:

Imprime un número entero en la salida estándar.
Maneja casos especiales como el número más negativo (-2147483648).
Utiliza recursión para imprimir cada dígito por separado.
Incrementa el contador (length) según la cantidad de caracteres impresos.*/

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
