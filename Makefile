NAME = libftprintf.a

CC 	= gcc
FLAGS = -Wall -Werror -Wextra

HEADER_DIR  = includes/

LIBFT_DIR   = libft/

OBJ_DIR     = obj/


PROC_DIR	= process/

SRC_PRINTF  = ft_printf.c ft_parser.c
OBJ_PRINTF  = $(addprefix $(OBJ_DIR), $(SRC_PRINTF:.c=.o))
HEAD_PRINTF = $(addprefix $(HEADER_DIR), libftprintf.h)


SRC_PROC    = ft_process.c ft_proc_char.c ft_proc_str.c ft_proc_d_i.c \
			ft_proc_uint.c ft_proc_pointer.c ft_proc_percent.c ft_proc_x_x.c


OBJ_PROC    = $(addprefix $(OBJ_DIR), $(SRC_PROC:.c=.o))
HEAD_PROC   = $(addprefix $(HEADER_DIR), ft_process.h)

all: $(NAME)

$(NAME): $(OBJ_DIR) objs
		@make -C $(LIBFT_DIR)
		@cp $(LIBFT_DIR)libft.a $(NAME)
		@ar rcs $(NAME) $(OBJ_DIR)*.o


$(OBJ_DIR):
		@mkdir $(OBJ_DIR)

objs: $(OBJ_PRINTF) $(OBJ_PROC)

$(OBJ_PRINTF): $(OBJ_DIR)%.o: %.c $(HEAD_PRINTF)
		$(CC) $(CFLAGS) -I $(HEADER_DIR) -I $(LIBFT_DIR) -c $< -o $@

$(OBJ_PROC): $(OBJ_DIR)%.o: $(PROC_DIR)%.c $(HEAD_PROC)
		$(CC) $(CFLAGS) -I $(HEADER_DIR) -I $(LIBFT_DIR) -c $< -o $@

clean:
		rm -rf $(OBJ_DIR)
		make -C $(LIBFT_DIR) clean

fclean: clean
		rm -f $(NAME)
		make -C $(LIBFT_DIR) fclean

re: fclean all


main:
	gcc -Wall -Werror -Wextra  main.c -L. -lftprintf -o rezult && ./rezult | cat -e


.PHONY: all objs clean fclean re
