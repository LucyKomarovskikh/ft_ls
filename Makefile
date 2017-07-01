NAME = ft_ls
CC = gcc

OBJ = ft_ls.o ft_sort_list.o assist.o ft_print_list.o ft_form_list.o ft_error.o ft_print_file.o ft_sort_time_r.o main.o

SRC = ft_ls.c ft_sort_list.c assist.c ft_print_list.c ft_form_list.c ft_error.c ft_print_file.c ft_sort_time_r.c main.c

LIB = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) lib
	$(CC) $(OBJ) $(LIB) -o $(NAME)

lib:
	make -C libft/

$(OBJ): $(SRC)
	$(CC) -c -Wall -Wextra -Werror $(SRC) 	

clean:
	make clean -C libft/
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all
