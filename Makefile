CC = gcc
LIB = ar rcs
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
RM = rm -f
SRC = libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c \
	libft/ft_isprint.c libft/ft_strlen.c libft/ft_memset.c libft/ft_bzero.c libft/ft_memcpy.c \
	libft/ft_strncmp.c libft/ft_memmove.c libft/ft_strchr.c libft/ft_strrchr.c libft/ft_strlcpy.c \
	libft/ft_strlcat.c libft/ft_calloc.c libft/ft_strdup.c libft/ft_memchr.c libft/ft_memcmp.c \
	libft/ft_strnstr.c libft/ft_atoi.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c \
	libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_split.c libft/ft_itoa.c libft/ft_strmapi.c \
	libft/ft_striteri.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c \
	libft/ft_lstnew_bonus.c libft/ft_lstadd_front_bonus.c libft/ft_lstsize_bonus.c \
	libft/ft_lstlast_bonus.c libft/ft_lstadd_back_bonus.c libft/ft_lstdelone_bonus.c \
	libft/ft_lstclear_bonus.c libft/ft_lstiter_bonus.c libft/ft_lstmap_bonus.c \
	ft_printf.c tipe_finder.c putchar_c.c putstr_c.c putnbr_c.c puthexa_min_c.c \
	puthexa_may_c.c ft_putunsint_c.c putptrc_c.c

OBJ = $(SRC:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) -c $< -I ./ -o $@

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean all fclean re .c.o