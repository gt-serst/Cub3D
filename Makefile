# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 17:15:25 by gt-serst          #+#    #+#              #
#    Updated: 2023/12/27 14:30:25 by gt-serst         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =		$(addprefix Sources/,\
			main.c\
			Utils/ft_putstr_fd.c\
			Utils/ft_strlen.c\
			Utils/gnl/get_next_line.c\
			Utils/gnl/get_next_line_utils.c\
			Utils/ft_strjoin.c\
			Utils/ft_exit.c\
			Utils/ft_isspace.c\
			Utils/ft_split.c\
			Utils/ft_isnumber.c\
			Utils/ft_atoi.c\
			Checker/arg_checker.c\
			Checker/map_checker.c\
			Checker/map_checker2.c\
			Checker/sprite_checker.c\
			Checker/map_valid.c\
			Raycasting/input.c\
			Raycasting/launch_graphic_env.c\
			Raycasting/my_mlx_pixel_put.c\
			Raycasting/ft_raycasting.c\
			Raycasting/dda.c\
			Raycasting/dda_utils.c\
			Raycasting/paint_stripe.c\
			Raycasting/paint_stripe_utils.c\
			Raycasting/move.c\
			Raycasting/rotate.c)

NAME		= cub3D

INC			= -I ./

MLXFLAGS	= -Lmlx -lmlx -framework OpenGL -framework AppKit

MLXINC		= -Imlx

FLAGS		= -Wall -Werror -Wextra

OBJS		= ${SRCS:.c=.o}

${NAME} : ${OBJS}
			gcc ${FLAGS} ${INC} $(OBJS) ${MLXFLAGS} -o $(NAME)

all : ${NAME}

%.o:%.c
		gcc ${FLAGS} ${MLXINC} -c $< -o $@

clean :
		rm -rf ${OBJS}

fclean : clean
		rm -rf ${NAME}

re : fclean all

.PHONY : all clean fclean re NAME
