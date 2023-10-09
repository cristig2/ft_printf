/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgallar <crgallar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:43:29 by crgallar          #+#    #+#             */
/*   Updated: 2023/10/04 12:57:41 by crgallar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*La funcion ft_printf:
Es una reprogramacion simplificada del printf.
En la cadena de formato pasamos los placeholders que cambiaremos por los 
argumentos que se dan a continuacion de la string.
Devolvera el numero total de caracteres impresos*/

int	ft_printf(const char *strph, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, strph);
	i = 0;
	len = 0;
	while (strph[i] != '\0')
	{
		if (strph[i] == '%')
		{
			i++;
			len = ft_check_percen(strph[i], args, len);
	
		}
		else
			len += ft_putchar(strph[i]);
		i++;
	}
	va_end(args);
	return (len);
}
/*
int	main(void)
{
	int	original;
	int	test;

	original = printf("Orginal function result: %s\n", "Hola");
	test = ft_printf("My own function result: %s\n", "Hello");
	return (0);
}
*/
