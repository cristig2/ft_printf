/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgallar <crgallar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:29:10 by crgallar          #+#    #+#             */
/*   Updated: 2023/10/09 17:29:10 by crgallar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*La funcion ft_base_hexa: Hace la conversion de decimal a hexadecimal. 
Se crea un puntero a la cadena que representa los digitios hexadecimales.
Si el número es mayor o igual a 16, la función se llama a sí misma de forma
recursiva para convertir el cociente dividido menor de 16, dividiendo por 16.
Escribe el carácter correspondiente al resto de la división por 16.
Este proceso se realiza de manera recursiva hasta convertir todo el número en 
su representación hexadecimal.
 */
void	ft_base_hexa(int num)
{
	char	*hexa;
	int		len;

	hexa = "0123456789abcdef";
	len = 0;
	if (num >= 16)
		len += ft_base_hexa(num / 16);
	write (1, &hexa[num % 16], 1);
	len++;
}

/*La funcion ft_pointer:
Usa como parametro size_t para almacenar valores no negativos.
Imprime 0x al principio para indicar que esta en numero hexadecimal e imprime 
a continuacion el numero hexadecimal mediante la funcion ft_base_hexa.*/

void	ft_pointer(size_t pointer)
{
    char strhex[25];
	int	len;

    len = 0;
	write (1, "0x", 2);
    len += 2;
	strhex = ft_base_hexa(pointer);
	write (1, &strhex, 1);
	len += ft_strlen(strhex);
}

/*La funcion ft_lower_hexa: Hace la conversion de decimal a hexadecimal de la 
misma forma que ft_base_hexa pero en el caso de un placeholder de x mayuscula.*/

void	ft_lower_hexa(int num, char charph)
{
	char	*hexa_lower;
	int		len;
	if (charph == 'x')
		hexa_lower = "0123456789abcdef";
	len = 0;
	if (num >= 16)
		len += ft_lower_hexa(num / 16);
	write (1, &hexa_lower[num % 16], 1);
	len++;
}

/*La funcion ft_upper_hexa: Hace la conversion de decimal a hexadecimal de la 
misma forma que ft_base_hexa pero en el caso de un placeholder de X mayuscula.*/

void	ft_upper_hexa(int num, char charph)
{
	char	*hexa_upper;
	int		len;
	if (charph == 'X')
		hexa_upper = "0123456789ABCDEF";
	len = 0;
	if (num >= 16)
		len += ft_upper_hexa(num / 16);
	write (1, &hexa_upper[num % 16], 1);
	len++;
}

