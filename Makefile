# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/21 22:10:19 by hlorrine          #+#    #+#              #
#    Updated: 2020/07/07 16:59:59 by dbutterw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS :=	ls_strcmp.c				\
		main.c					\
		parse_args.c			\
		print_args.c			\
		flags/del_flags.c		\
		flags/flags_error.c		\
		flags/get_flag.c		\
		flags/init_flags.c		\
		flags/parse_flags.c		\
		nodes/cmp_nodes.c		\
		nodes/del_node.c		\
		nodes/get_dir_node.c	\
		nodes/get_file_node.c	\
		nodes/get_node.c		\
		srcs/cmp_srcs.c			\
		srcs/del_src.c			\
		srcs/get_srcs.c			\
		srcs/init_src.c			\
		print/init_dir_path.c 			\
		print/print_col.c 			\
		print/print_col_right.c 			\
		print/print_dir_node.c 			\
		print/print_error.c 			\
		print/print_file_node.c 			\
		print/print_name.c 			\
		print/print_name_endl.c 			\
		print/print_node.c 			\
		print/print_srcs.c 			\
		print/col/init_col_attr.c 		\
		print/col/print_src.c 		\
		print/col/print_srcs_col.c 		\
		print/col/walk_srcs_col.c 		\
		print/col/walk_srcs_row.c 		\
		print/line/get_human_readable.c 			\
		print/line/get_max_values.c 			\
		print/line/print_gid.c 			\
		print/line/print_date.c 			\
		print/line/print_link.c 			\
		print/line/print_mode.c 			\
		print/line/print_nlink.c 			\
		print/line/print_size.c 			\
		print/line/print_srcs_line.c 			\
		print/line/print_total.c 			\
		print/line/print_uid.c

SRC_DIR := ./src

LIB_DIR := ./libft

INC :=	-I ./includes			\
			-I $(LIB_DIR)			\
			-I $(LIB_DIR)/char		\
			 -I $(LIB_DIR)/env		\
			 -I $(LIB_DIR)/file		\
			 -I $(LIB_DIR)/list		\
			 -I $(LIB_DIR)/math		\
			 -I $(LIB_DIR)/memory	\
			 -I $(LIB_DIR)/num		\
			 -I $(LIB_DIR)/regex	\
			 -I $(LIB_DIR)/string	\
			 -I $(LIB_DIR)/vector	\
			 -I $(LIB_DIR)/search

OBJ_DIR := ./obj

CMP_DIR	:= $(OBJ_DIR)/flags		\
			$(OBJ_DIR)/nodes	\
			$(OBJ_DIR)/srcs		\
			$(OBJ_DIR)/print	\
			$(OBJ_DIR)/print/col\
			$(OBJ_DIR)/print/line

OBJ	:= $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

CFLAGS	:= -Wall -Wextra -Werror

LFLAGS	:= -L $(LIB_DIR) -lft

NAME = ft_ls

.PHONY: all clean lib fclean re

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR) $(CMP_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc $(CFLAGS) $(INC) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ) | lib
	gcc -o $(NAME) $(OBJ) $(LFLAGS)

lib:
	make -C $(LIB_DIR)

clean:
	rm -rf $(OBJ_DIR) $(CMP_DIR)
	make clean -C $(LIB_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_DIR)

re: fclean all
