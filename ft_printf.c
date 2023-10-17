/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgallar <crgallar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:43:29 by crgallar          #+#    #+#             */
/*   Updated: 2023/10/09 09:32:49 by crgallar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*La funcion ft_printf:
Es una reprogramacion simplificada del printf.
En la cadena de formato pasamos los placeholders que cambiaremos por los 
argumentos que se dan a continuacion de la string.
Devolvera el numero total de caracteres impresos*/

#include "ft_printf.h"

int	ft_printf(const char *strph, ...)
{
	va_list	args;
	int		i;
	int		len;


	len = 0;
	va_start(args, strph);
	i = 0;
	while (strph[i] != '\0') {
        if (strph[i] == '%') {
            i++;
            len += ft_check_percen(strph[i], &args);
        } else {
            len += ft_putchar(strph[i]);
        }
        i++;
    }

    va_end(args);
    return len;
}

int	main(void)
{
	char *str = "Hola mundo, desde el";
	int num = 2024;
	char sig = '!';


	printf("Orginal function result: %s %i%c\n", str, num, sig);
	ft_printf("\nMy own function result: %s %i%c\n", str, num, sig);
	return (0);