/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgallar <crgallar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:43:29 by crgallar          #+#    #+#             */
/*   Updated: 2023/10/18 12:49:44 by crgallar         ###   ########.fr       */
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
	while (strph[i] != '\0')
	{
		if (strph[i] == '%')
		{
			i++;
			len += ft_check_percen(strph[i], &args);
		}
		else
		{
			len += ft_putchar(strph[i]);
		}
		i++;
	}
	va_end(args);
	return (len);
}
/*
int	main(void)
{
	char c = 'A';
    char *str = "Hello, world!";
    int num = -12345;
    unsigned int uint = 12345;
    void *ptr = (void *)0x12345678;

	printf("Orginal function result Character: %c\n", c);
	ft_printf("My own function result Character: %c\n\n", c);
	printf("Orginal function result String: %s\n", str);
	ft_printf("My own function result String: %s\n\n", str);
	printf("Orginal function result Pointer: %p\n", ptr);
	ft_printf("My own function result Pointer: %p\n\n", ptr);
	printf("Orginal function result Decimal: %d\n", num);
	ft_printf("My own function result Decimal (d): %d\n\n", num);
	printf("Orginal function result Decimal: %i\n", num);
	ft_printf("My own function result Decimal (i): %i\n\n", num);
	printf("Orginal function result Unsigned Decimal: %u\n", uint);
	ft_printf("My own function result Unsigned Decimal (u): %u\n\n", uint);
	printf("Orginal function result Lowercase Hexadecimal : %x\n", num);
	ft_printf("My own function result Lowercase Hexadecimal (x): %x\n\n", num);
	printf("Orginal function result Uppercase Hexadecimal: %X\n", num);
	ft_printf("My own function result Uppercase Hexadecimal (X): %X\n\n", num);
	printf("Orginal function result Percentage symbol: %%\n");
	ft_printf("My own function result Percentage symbol: %%\n\n");
	return (0);
}
*/