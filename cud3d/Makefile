NAME = a.out

PARSE = parse/cub3d.c \
	parse/utils.c \
	parse/check.c \
	parse/check_bis.c \
	parse/init.c\
	parse/global_utils.c \
	libft/utils_l.c \
	libft/ft_split.c \
	libft/utils_II.c \
	gnl/get_next_line.c \
	gnl/get_next_line_utils.c \

RENDERING = rendering/render.c \
			rendering/mini_map.c \
			rendering/render_ciel.c \
			rendering/render_floor.c \
			rendering/render_wall.c \
			rendering/tools.c \
			rendering/my_mlx_rendring.c \
			
RAYCAST = raycast/cast_rays.c raycast/find_horizontal.c raycast/find_vertical.c raycast/utils.c 
MOVES = move/all_moves.c move/move_up.c move/move_down.c move/move_left.c move/move_reight.c move/player_position.c 
SRC =  main/put_img.c $(MOVES) $(PARSE) $(RENDERING) $(RAYCAST)
INCL = header/Cub3d.h header/move.h rendering/rendering.h

CC = gcc
FLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
FLAGS_MLX =   -lmlx -framework OpenGL -framework AppKit #-lmlx -lXext -lX11 -lm 
RM = rm -f

OBJ = $(SRC:.c=.o)

all : $(NAME)
$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ)  $(FLAGS_MLX)  -o $(NAME)

%.o:%.c $(INCL)
	$(CC) $(FLAGS) -c $< -o $@

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(OBJ)


re : fclean all

run : fclean all
	./a.out