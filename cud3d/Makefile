NAME = a.out

MOVES = move/all_moves.c move/move_up.c move/move_down.c move/move_left.c move/move_reight.c move/player_position.c raycast/cast_rays.c raycast/find_horizontal.c raycast/find_vertical.c raycast/utils.c rendering/render.c
SRC = main/main.c $(MOVES)
INCL = header/Cub3d.h header/move.h rendering/rendering.h

CC = gcc
FLAGS = -Wall -Wextra -Werror
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