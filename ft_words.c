/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgallar <crgallar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:46:15 by crgallar          #+#    #+#             */
/*   Updated: 2023/10/09 09:33:47 by crgallar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* La variable size_t se utiliza para representar tamaños o longitudes de datos
	Es un tipo de datos sin signo para almacenar valores no negativos.*/
/* La función ft_strlen:
Calcula la longitud de una cadena de caracteres (string).
Esta función recorre la cadena dada hasta encontrar el caracter nulo '\0',
contando el número de caracteres antes del caracter nulo. El resultado es la 
longitud de la cadena.*/

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/* La función ft_putchar:
Imprime un carácter en la salida estándar utilizando la función write*/

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1)
}

/* La función ft_putstr:
Se encarga de imprimir cadenas de caracteres. Si arg es NULL, imprime la cadena 
"(null)". Si no es NULL, itera sobre cada carácter de la cadena y lo imprime 
utilizando la función ft_putchar.*/

int	ft_putstr(char *str)
{
	size_t	i;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
