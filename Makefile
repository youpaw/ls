SRC_DIR	:= ./src
INC_DIR	:= ./includes
OBJ_DIR	:= ./obj

SRC		:= 	ft_add_node.c				\
           	ft_all_print.c				\
			ft_know_max.c				\
			ft_print_l_or_not.c			\
           	ft_get_flags.c				\
           	ft_new_node.c				\
           	ft_get_node.c				\
           	ft_srcs_list.c				\
			ft_print_simlink.c			\
			ft_print_filetype.c			\
			ft_print_time.c				\
			ft_print_acl.c				\
			ft_print_rights.c			\
			ft_print_major_minor.c		\
			ft_print_nlink.c			\
			ft_print_name_group.c		\
			ft_print_size.c				\
			ft_print_filename.c			\
			ft_print_flag_i.c			\
           	errors/ft_handle_error.c	\
			errors/ft_eacces.c			\
			errors/ft_enoent.c			\
			errors/ft_enotdir.c			\
			errors/ft_init_error.c		\
           	main.c

OBJ		:= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

CFLAGS	:= -Wall -Wextra -Werror

LFLAGS	:= -L ./libft -lft

NAME	:= ft_ls

.PHONY: all clean lib fclean re

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/errors

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | lib
	gcc $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ) | lib
	gcc -o $(NAME) $(OBJ) $(LFLAGS)

lib:
	make -C ./libft

clean:
	rm -rf $(OBJ_DIR)
	make clean -C ./libft
fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all