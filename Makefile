SRCS = 	main.c 						\
		srcs/utils.c				\
		srcs/utils2.c				\
		srcs/valid/valid.c			\
		srcs/valid/valid_utils.c	\
		srcs/valid/valid_utils2.c	\
		srcs/valid/valid_info.c		\
		srcs/valid/valid_info2.c	\
		srcs/valid/valid_info3.c	\
		srcs/valid/valid_map.c		\
		srcs/valid/valid_map2.c		\
		srcs/parse/parse.c			\
		srcs/parse/parse_map.c		\
		srcs/parse/parse_map2.c		\
		srcs/parse/parse_infos.c	\
		srcs/ft_free.c				\
		srcs/color.c				\
		srcs/graphics/draw.c		\
		srcs/error.c				\
		srcs/graphics/display.c		\
		srcs/graphics/raycasting.c	\
		srcs/graphics/raycasting2.c

OBJS = $(SRCS:.c=.o)

NAME = cub3D

LIB = libcub3D.a

CFLAGS = -Wall -Wextra -Werror

LIB_EXTERN = -L./lib/libft -l ft -L./lib/gnl -l gnl -l mlx
 
HEADERS = -I inc/

.c.o:
	@echo "🏗️   Compiling source file"
	@gcc $(CFLAGS) $(HEADERS) -c  $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	@make -C lib/libft
	@make -C lib/gnl
	@echo "🧰  Creating archive $(LIB)... "
	@ar crs $(LIB) $(OBJS)
	@echo "🚀  Building executable $(NAME)... "
	@gcc $(CFLAGS) $(LIB_EXTERN) $(HEADERS) -L. -lcub3D -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "😎  Compilation done !"

all: $(NAME)

clean:
	@make clean -C lib/libft
	@make clean -C lib/gnl
	@echo "🧹  Cleaning object files...       ✅"
	@rm -rf $(OBJS) 

fclean: clean
	@make fclean -C lib/libft
	@make fclean -C lib/gnl
	@echo "🧹  Cleaning archive $(LIB)... ✅"
	@rm -rf $(LIB) 
	@echo "🧹  Cleaning executable $(NAME)...   ✅"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re