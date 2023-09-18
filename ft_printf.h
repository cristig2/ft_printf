/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgallar <crgallar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:32:17 by crgallar          #+#    #+#             */
/*   Updated: 2023/09/18 13:05:41 by crgallar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ARCHIVO DE ENCABEZADOS
/* Directivas de preprocesador:
Estas directivas aseguran que el contenido del archivo de encabezado solo se
incluirá una vez, evitando problemas de redefinición en caso de que el archivo
se incluya múltiples veces en diferentes partes del código. */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* Inclusión de bibliotecas estándar (#include):
Se está incluyendo las bibliotecas estándar necesarias, para que las funciones
y tipos definidos en estas bibliotecas estén disponibles en el archivo de
encabezado. */

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <stddef.h>


/* Prototipos de funciones:
Se declaran los prototipos de las funciones que se implementan en el proyecto.
Cada prototipo enumera el tipo de retorno, el nombre de la función y los 
parámetros que la función espera recibir. */

void	ft_putcharacter_length(char character, int *length);
void	ft_string(char *args, int *length);

void	ft_number(int num, int *len);
void	ft_pointer(size_t ptr, int *len);
void	ft_hexadecimal(unsigned int x, int *length, char x_or_x);
void	ft_unsigned_int(unsigned int u, int *length);

#endif