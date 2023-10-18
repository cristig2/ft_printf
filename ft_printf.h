/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgallar <crgallar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:32:17 by crgallar          #+#    #+#             */
/*   Updated: 2023/10/18 12:37:46 by crgallar         ###   ########.fr       */
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
# include <stdio.h>

/* Prototipos de funciones:
Se declaran los prototipos de las funciones que se implementan en el proyecto.
Cada prototipo enumera el tipo de retorno(void), el nombre de la función y los 
parámetros que la función espera recibir. */

size_t	ft_strlen(const char *str);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_numlen(int num);
char	*ft_itoa(int num);
int		ft_base_hexa(int num);
int		ft_pointer(size_t pointer);
int		ft_lower_hexa(int num);
int		ft_upper_hexa(int num);
int		ft_unsig_numlen(unsigned long num);
char	*ft_unsig_itoa(unsigned int num);
int		ft_check_percen(char change, va_list *args);
int		ft_printf(const char *strph, ...);

#endif