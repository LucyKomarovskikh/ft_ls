NAME = libft.a
CC = gcc
OBJ = ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_itoa.o ft_memalloc.o ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memdel.o ft_memmove.o ft_memset.o ft_putchar_fd.o ft_putchar.o ft_putendl_fd.o ft_putendl.o ft_putnbr_fd.o ft_putnbr.o ft_putstr_fd.o ft_putstr.o ft_strcat.o ft_strchr.o ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdel.o ft_strdup.o ft_strequ.o ft_striter.o ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlen.o ft_strmap.o ft_strmapi.o ft_strncat.o ft_strncmp.o ft_strncpy.o ft_strnequ.o ft_strnew.o ft_strrchr.o ft_strstr.o ft_strnstr.o ft_strsub.o ft_strtrim.o ft_tolower.o ft_toupper.o ft_lstnew.o ft_lstadd.o ft_lstiter.o ft_lstdel.o ft_lstdelone.o ft_strsplit.o ft_lstmap.o ft_memrcpy.o ft_digitcount.o ft_wordcount.o ft_strtoupper.o ft_strtolower.o ft_printf.o ft_wstrlen.o ft_putchar_c.o ft_wchar_str.o ft_format.o ft_d_num.o ft_ixo.o ft_fill.o ft_pr_ht.o ft_pr_s.o ft_assign.o ft_find_nbr.o ft_intcount.o ft_char.o ft_str.o ft_all_toa.o

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c ft_putstr.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_lstnew.c ft_lstadd.c ft_lstiter.c ft_lstdel.c ft_lstdelone.c ft_strsplit.c ft_lstmap.c ft_memrcpy.c ft_digitcount.c ft_wordcount.c ft_strtoupper.c ft_strtolower.c ft_printf.c ft_assign.c ft_wstrlen.c ft_putchar_c.c ft_wchar_str.c  ft_format.c ft_d_num.c ft_ixo.c ft_fill.c ft_pr_ht.c ft_pr_s.c ft_find_nbr.c ft_intcount.c ft_char.c ft_str.c ft_all_toa.c 

all: $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJ) : $(SRC)
	$(CC) -c -Wall -Wextra -Werror $(SRC)	

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
