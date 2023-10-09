/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgallar <crgallar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:21:06 by crgallar          #+#    #+#             */
/*   Updated: 2023/10/09 12:34:12 by crgallar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* La función ft_numlen:
Calcula la cantidad de dígitos en un número entero.
Esta función determina la cantidad de dígitos en un número entero, incluyendo
el signo negativo si el número es negativo. Se cuenta un dígito adicional para 
el signo en números menores o iguales a cero.
Devuelve la cantidad de dígitos del número especificado, incluyendo el signo.*/

int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

/* La función ft_itoa:
Convierte un número entero a una cadena de caracteres.
La cadena resultante puede incluir el signo '-' en caso de números
negativos.
Devuelve un puntero a la cadena de caracteres que representa el número 
(incluyendo el signo). Si hay un error de memoria, devuelve NULL.
*/

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	long int	nb;

	nb = n;
	len = ft_numlen(nb);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
		str[len--] = '\0';
	if (nb == 0)
		str[0] = '0';
	str[len] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		str[len] = nb % 10 + 48;
		nb = nb / 10;
		len--;
	}
	return (str);
}

/*La funcion ft_base_hexa:
Hace la conversion de un numero decimal a hexadecimal. 
Se crea un puntero a la cadena que representa los digitios hexadecimales.
Si el número es mayor o igual a 16, la función se llama a sí misma de forma
recursiva para convertir el cociente dividido menor de 16, dividiendo por 16.
Escribe el carácter correspondiente al residuo de la división por 16 (hexa).
Este proceso se realiza de manera recursiva hasta convertir todo el número en su
representación hexadecimal.
 */
int	ft_base_hexa(int num)
{
	char	*hexa;
	int		len;

	hexa = "0123456789abcdef";
	len = 0;
	if (num >= 16)
		len += ft_base_hexa(num / 16);
	write (1, &hexa[num % 16], 1);
	len++;
	return (len);
}

/*La funcion ft_pointer:
Usa como parametro un tipo de datos sin signo para almacenar valores no 
negativos y otro puntero que lo usa para medir la longitud.
imprime 0x */

int	ft_pointer(size_t pointer)
{
	int	len;

	write (1, "0x", 2);
	len += 2;
	len = ft_base_hexa(pointer);
	return (len);
}
int main() {
    int decimal_number = 255;
    size_t pointer_address = (size_t) &decimal_number;

    write(1, "Decimal number: ", 16);
    write(1, &decimal_number, sizeof(decimal_number));
    write(1, "\n", 1);

    write(1, "Pointer address: ", 17);
    int length = ft_pointer(pointer_address);
    write(1, "\n", 1);

    return 0;
}