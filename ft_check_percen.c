/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_percen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgallar <crgallar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:33:28 by crgallar          #+#    #+#             */
/*   Updated: 2023/10/18 12:47:02 by crgallar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*La funcion ft_check_percen:
Revisa el carácter de formato y sus argumentos correspondientes.
Esta función procesa los carácter de formato y sus argumentos correspondientes 
de la lista de argumentos variables. Ejecuta el codigo según el carácter de 
formato y actualiza el contador de caracteres.
Devuelve el número total de caracteres impresos*/

int	ft_check_rest(char change, va_list *args)
{
	char	*str;
	int		count;

	count = 0;
	if (change == 'u')
	{
		str = ft_unsig_itoa(va_arg(*args, unsigned int));
		count += ft_putstr(str);
		free(str);
	}
	else if (change == 'x')
		count += ft_lower_hexa(va_arg(*args, int));
	else if (change == 'X')
		count += ft_upper_hexa(va_arg(*args, int));
	else if (change == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_check_percen(char change, va_list *args)
{
	char	*str;
	int		count;
	int		*ptr;

	count = 0;
	str = 0;
	if (change == 'c')
		count += ft_putchar(va_arg(*args, int));
	else if (change == 's')
		count += ft_putstr(va_arg(*args, char *));
	else if (change == 'p')
	{
		ptr = va_arg(*args, int *);
		ft_pointer((size_t)ptr);
		ft_itoa((size_t)ptr);
	}
	else if (change == 'd' || change == 'i')
	{
		str = ft_itoa(va_arg(*args, int));
		count += ft_putstr(str);
		free(str);
	}
	else
		count += ft_check_rest(change, args);
	return (count);
}
/*
int main ()
{
	printf("Resultado: ");

    int count = 0;
    va_list args;

    count = ft_check_percen('c', *args);
    count = ft_check_percen('s', *args);

    va_end(args);

    printf("\nTotal de caracteres impresos: %d\n", count);

    return 0;
}
*/
