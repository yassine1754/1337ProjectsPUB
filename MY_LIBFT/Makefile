# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yadib <yadib@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 10:50:46 by yadib             #+#    #+#              #
#    Updated: 2024/11/06 17:17:32 by yadib            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



SRCS = ft_atoi.c  ft_isalpha.c ft_isdigit.c  \
	ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
	ft_strchr.c ft_strrchr.c ft_strncmp.c  ft_memchr.c  ft_memcmp.c \
	ft_strnstr.c ft_bzero.c ft_memcpy.c ft_isprint.c ft_memmove.c \
	ft_calloc.c  ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	ft_itoa.c ft_strmapi.c ft_memset.c ft_isascii.c ft_isalnum.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c \

SRCS_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
	ft_lstmap_bonus.c

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
AR = ar rcs
FIRST_OBJECTS = $(SRCS:.c=.o)
OBJECTS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME) 

$(NAME): $(FIRST_OBJECTS)
	$(AR) $(NAME) $(FIRST_OBJECTS)

bonus: $(OBJECTS_BONUS)
	$(AR) $(NAME) $(OBJECTS_BONUS) 

%.o : %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	@$(RM) -f $(FIRST_OBJECTS)
	@$(RM) -f $(OBJECTS_BONUS)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)

.PHONY : clean 