/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgallar <crgallar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:46:15 by crgallar          #+#    #+#             */
/*   Updated: 2023/10/04 13:31:23 by crgallar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* La función ft_strlen:
Calcula & devuelve la longuitud de una cadena.
*/

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/* La función ft_putcharacter_length:
Imprime un carácter en la salida estándar utilizando la función write y aumenta
el contador de longitud (len) para realizar un seguimiento de cuántos caracteres
se han impreso.*/

void	ft_putcharacter_length(char chartr, int *len)
{
	write(1, &chartr, 1);
	(*len)++;
}

/* La función ft_string:
Se encarga de imprimir cadenas de caracteres. Si arg es NULL, imprime la cadena 
"(null)". Si no es NULL, itera sobre cada carácter de la cadena y lo imprime 
utilizando la función ft_putcharacter_length.*/

void	ft_string(char *str, int *len)
{
	size_t	i;

	if (!str)
	{
		write(1, "(null)", 6);
		(*len) += 6;
	}
	i = 0;
	while (str[i] != '\0')
	{
		ft_putcharacter_length(str[i], len);
		i++;
	}
}

/*
int	main(void)
{
	char* str = "Name: Cristina";
	int len = 0;

	ft_string(str, &len);
	printf("\nLongitud de la variable str: %d\n", len);
	return (0);
}
*/
