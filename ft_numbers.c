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

int	ft_numlen(int num)
{
    int len;

	len = 0;
	if (num <= 0)
		len++;
	while (num != 0)
	{
		num = num / 10;
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

char	*ft_itoa(int num)
{
	char		*str;
	int			len;
	int	nb;

	nb = num;
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

/*
int main() {
    int num = -12345;
    char *result = ft_itoa(num);

    printf("Numero convertido a cadena: %s\n", result);

    // Liberar la memoria asignada
    free(result);

    return 0;
}*/