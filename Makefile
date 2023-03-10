# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 13:51:30 by edecoste          #+#    #+#              #
#    Updated: 2023/03/10 15:01:51 by edecoste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			= so_long

FLAGSE			= #-fsanitize=address -g3 
FLAGS			= ${FLAGSE} -Wextra -Werror -Wall -I -g3

MLXFLAGS		= -Imlx_linux -lXext -lX11 -lm -lz

SRCS			=	so_long.c \
					check.c \
					check_solvability.c \
					utils.c \
					imgs.c \
					maps_funct.c \
					render.c \
					move.c
			
DIR_MLX 		= mlx_linux/
MLX				= $(addprefix $(DIR_MLX), libmlx.a)

DIR_LIBFT		= Libft/
LIBFT			= $(addprefix $(DIR_LIBFT), libft.a)

OBJS 			= ${SRCS:%.c=./build/%.o}

HEADER			= includes/so_long.h

all: 			${NAME}

${NAME}:		${OBJS} ${LIBFT} ${MLX}
				${CC} $^ ${FLAGS} ${MLXFLAGS} -o ${NAME}

./build/%.o:	./sources/%.c ${HEADER}
				@mkdir -p build
				${CC} ${FLAGS} -Imlx_linux -c $< -o $@

${MLX}:			FORCE
				make -s -C ${DIR_MLX}

${LIBFT}:		FORCE
				make -s -C ${DIR_LIBFT}

clean:
				${RM} -r ./build

fclean:			clean
				${RM} ${NAME}
				make -s -C ${DIR_MLX} clean
				make -s -C ${DIR_LIBFT} clean

re:				fclean
				${MAKE} all
			
FORCE:

.PHONY: all clean fclean re FORCE