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
Usa como parametro size_t para almacenar valores no negativos.
Imprime 0x al principio para indicar que esta en numero hexadecimal e imprime 
a continuacion el numero hexadecimal mediante la funcion ft_base_hexa.*/

int	ft_pointer(size_t pointer)
{
    size_t len;

	write(1, "0x", 2);
    len = ft_base_hexa((int)pointer) + 2;
    return (len);
}

/*La funcion ft_lower_hexa: Hace la conversion de decimal a hexadecimal de la 
misma forma que ft_base_hexa pero en el caso de un placeholder de x mayuscula.*/

int	ft_lower_hexa(int num, char charph)
{
	char	*hexa_lower;
	int		len;


	hexa_lower = "0123456789abcdef";
	len = 0;
	if (charph == 'x' && num >= 16)
		len += ft_lower_hexa(num / 16, charph);
	write (1, &hexa_lower[num % 16], 1);
	len++;
	return (len);
}

/*La funcion ft_upper_hexa: Hace la conversion de decimal a hexadecimal de la 
misma forma que ft_base_hexa pero en el caso de un placeholder de X mayuscula.*/

int	ft_upper_hexa(int num, char charph)
{
	char	*hexa_upper;
	int		len;

	hexa_upper = "0123456789ABCDEF";
	len = 0;
	if (charph == 'X' && num >= 16)
		len += ft_lower_hexa(num / 16, charph);
	write (1, &hexa_upper[num % 16], 1);
	len++;
	return (len);
}
/*
int main() {
    int num = 255;

    printf("Base Hexadecimal: ");
    size_t len_base_hex = ft_base_hexa(num);
    printf("\nLongitud de la representación hexadecimal: %d\n", len_base_hex);

    size_t pointer = 0x12345678;
    printf("Puntero en Hexadecimal: ");
    size_t len_pointer_hex = ft_pointer(pointer);
    printf("\nLongitud de la representación hexadecimal del puntero: %d\n", len_pointer_hex);

    printf("Lowercase Hexadecimal: ");
    size_t len_lower_hex = ft_lower_hexa(num, 'x');
    printf("\nLongitud de la representación hexadecimal en minúsculas: %d\n", len_lower_hex);

    printf("Uppercase Hexadecimal: ");
    size_t len_upper_hex = ft_upper_hexa(num, 'X');
    printf("\nLongitud de la representación hexadecimal en mayúsculas: %d\n", len_upper_hex);

    return 0;
}*/