/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgallar <crgallar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:21:06 by crgallar          #+#    #+#             */
/*   Updated: 2023/08/31 10:21:06 by crgallar         ###   ########.fr       */
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
	if (num == -2147483648) //valor mínimo representable para un int (32 bits)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	if (num < 0)
	{
		ft_putcharacter_length('-', len);
		ft_number(num * -1, len); //recursiva para imprimir el valor en positivo
	}
	else
	{
		if (num > 9)
		{
            ft_number(num / 10, len); //separa el número en dígitos
        }	
        ft_putcharacter_length(num % 10 + '0', len); //imprime el último dígito
	}
}

/* La función ft_pointer:

Imprime un puntero en formato hexadecimal, precedido por "0x".
Utiliza una cadena de caracteres string para construir la representación 
hexadecimal del puntero.
Agrega un carácter nulo al final de la cadena string para que sea válida.
Imprime cada dígito hexadecimal utilizando la función ft_putcharacter_length.
Incrementa el contador de longitud (length) según la cantidad de caracteres 
impresos.*/

void	ft_pointer(size_t ptr, int *len)
{
	char	str[25];
	int		i;
	char	*base_char;

	base_char = "0123456789abcdef";
	i = 0;
	write(1, "0x", 2);
	(*len) += 2;
	if (ptr == 0)
	{
		ft_putcharacter_length('0', len);
		return ;
	}
	while (ptr != 0)
	{
		str[i] = base_char[ptr % 16];
		ptr = ptr / 16;
		i++;
	}
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		ft_putcharacter_length(str[i], len);
		i--;
	}
}


/* La función hexadecimal -> x or X:

Imprime un número hexadecimal en formato decimal, mayúsculas ('X') o en 
minúsculas ('x').
Utiliza una cadena de caracteres string para construir la representación 
hexadecimal del número.
Imprime cada dígito hexadecimal utilizando la función ft_putcharacter_length.
Incrementa el contador de longitud (length) según la cantidad de caracteres 
impresos*/

void	ft_hexadecimal(unsigned int x, int *length, char x_or_x)
{
	char	string[25];
	char	*base_character;
	int		i;

	if (x_or_x == 'X')
		base_character = "0123456789ABCDEF";
	else
		base_character = "0123456789abcdef";
	i = 0;
	if (x == 0)
	{
		ft_putcharacter_length('0', length);
		return ;
	}
	while (x != 0)
	{
		string[i] = base_character [x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
		ft_putcharacter_length(string[i], length);
}

/* La función ft_unsigned_int:

Imprime un número entero sin signo en formato decimal.
Utiliza recursión para imprimir cada dígito por separado.
Incrementa el contador de longitud (length) según la cantidad de caracteres
impresos.*/

void	ft_unsigned_int(unsigned int u, int *length)
{
	if (u >= 10)
		ft_unsigned_int(u / 10, length);
	ft_putcharacter_length(u % 10 + '0', length);
}