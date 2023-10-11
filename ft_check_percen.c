/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_percen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgallar <crgallar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:33:28 by crgallar          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/10/09 12:37:46 by crgallar         ###   ########.fr       */
=======
/*   Updated: 2023/10/09 12:37:40 by crgallar         ###   ########.fr       */
>>>>>>> 5a9dea240ad59e555aa7c19de6b590e102dbc33e
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*La funcion ft_check_percen:
Revisa el carácter de formato y sus argumentos correspondientes.
Esta función procesa los carácter de formato y sus argumentos correspondientes 
de la lista de argumentos variables. Ejecuta el codigo según el carácter de 
formato y actualiza el contador de caracteres.
Devuelve el número total de caracteres impresos*/

int	ft_check_percen(char change, va_list args, int count)
{
	char	*str;

	if (change == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (change == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (change == 'd' || change == 'i')
	{
		str = ft_itoa(va_arg(args, int));
		count += ft_putstr(str);
		free(str);
	}
	return (count);
}
/*int main ()
{
	char	percentage = 's';
	va_list	args;
	int count = 0;
}
*/
