/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgallar <crgallar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:01:32 by crgallar          #+#    #+#             */
/*   Updated: 2023/10/18 10:40:05 by crgallar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* La función ft_unsig_numlen:
Calcula la cantidad de dígitos en un número entero.
Esta función determina la cantidad de dígitos en un número sin signo.
Devuelve la cantidad de dígitos del número especificado*/

int	ft_unsig_numlen(unsigned long num)
{
	int	len;

	len = 0;
	if (num == 0)
		len ++;
	while (num)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

/* La función ft_itoa:
Convierte un número sin signo a una cadena de caracteres.
Devuelve un puntero a la cadena de caracteres que representa el número.
Si hay un error de memoria, devuelve NULL.
*/
char	*ft_unsig_itoa(unsigned int num)
{
	char			*str;
	int				len;
	unsigned long	nb;

	nb = num;
	len = ft_unsig_numlen(nb);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
		str[len--] = '\0';
	str[0] = '0';
	str[len] = '\0';
	if (nb < 0)
		nb = nb * -1;
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
    unsigned int num = 12345;
    char *str = ft_unsig_itoa(num);

    if (str != NULL) {
        printf("Número: %u\n", num);
        printf("Representación en cadena: %s\n", str);
        free(str);
    } else {
        printf("No se pudo asignar memoria para la cadena.\n");
    }

    return 0;
}
*/