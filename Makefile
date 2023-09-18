# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crgallar <crgallar@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 14:37:22 by crgallar          #+#    #+#              #
#    Updated: 2023/08/29 14:37:22 by crgallar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME: define el nombre del archivo de salida que se creará para la libreria.

NAME	= libftprintf.a

# SRCS: Enumera las rutas de los archivos fuente que se utilizarán para 
# compilar la libreria.

SRCS	= ./sources/ft_words.c \

# OBJS: Esta variable contiene los nombres de los archivos objeto que se 
# generarán a partir de los archivos fuente. Se deriva de la lista de archivos
# fuente reemplazando la extensión .c por .o.

OBJS	= $(SRCS:.c=.o)

# CC: Define el compilador que se utilizará para compilar los archivos fuente.

CC	= gcc

# RM: Define el comando para eliminar archivos. En este caso, se utiliza rm -f 
# para forzar la eliminación sin solicitar confirmación.

RM	= rm -f

#CFLAGS: Define las banderas de compilación que se utilizarán. Estas banderas 
# incluyen -Wall (mostrar advertencias), -Wextra (mostrar advertencias 
# adicionales) y -Werror (tratar las advertencias como errores).

CFLAGS	= -Wall -Wextra -Werror

# REGLAS DE COMPILACIÓN

# all es la primera regla y se compila cuando ejecutas simplemente 
# make. Aquí simplemente se especifica que el objetivo all es construir el 
# archivo especificado en $(NAME).

all:	$(NAME)

# $(NAME) esta regla establece que el archivo $(NAME) depende de los archivos
# objeto en $(OBJS). Utiliza el comando ar para crear el archivo de biblioteca
# a partir de los archivos objeto.

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

# clean: Esta regla elimina los archivos objeto ($(OBJS)).

clean:
			$(RM) $(OBJS)

# fclean: Esta regla elimina tanto los archivos objeto ($(OBJS)) como
# la biblioteca ($(NAME)).

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

#.PHONY: Esta directiva establece que los objetivos all, clean, fclean y re no
# son nombres reales de archivos, sino metas ficticias que no dependen de 
# archivos reales. Esto ayuda a asegurarse de que Make sepa que estos objetivos
# no tienen relación con archivos llamados igual.

.PHONY:		all clean fclean re