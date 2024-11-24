 
N_SRCS = ft_strncmp.c ft_bzero.c ft_strchr.c \
	ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_printf.c \
	ft_printf_address.c ft_convert_to_hex.c ft_casses2_bonus.c \
	ft_check_types_v2.c


NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra 
CC = cc
AR = ar rcs
SRC_OBJ = $(N_SRCS:.c=.o)
RM = rm -f

all : $(NAME)

bonus : $(NAME)

$(NAME) : $(SRC_OBJ)
	$(AR) $(NAME) $(SRC_OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(SRC_OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all
