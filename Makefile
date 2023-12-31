# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 17:54:29 by daguilar          #+#    #+#              #
#    Updated: 2023/12/20 17:33:55 by daguilar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH 		= include/libft

SRCS			=	errors.c libft_utils.c new_stack.c node_utils.c nodeA.c nodeB.c operations_1.c \
				operations_2.c operations_3.c operations_4.c push_swap.c sort_stack.c sort_three.c \
				split_ps.c stack_utils.c

BONUS_SRCS		= checker.c errors.c libft_utils.c new_stack.c node_utils.c nodeA.c nodeB.c operations_1.c \
				operations_2.c operations_3.c operations_4.c sort_stack.c sort_three.c \
				split_ps.c stack_utils.c

OBJS			= $(SRCS:.c=.o)

OBJS_BONUS		= ${BONUS_SRCS:.c=.o}

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= push_swap

BONUS_NAME 		= my_checker

all:			$(NAME)

bonus:			$(BONUS_NAME)

$(NAME):		$(LIBFT_PATH)/libft.a $(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_PATH)/libft.a

$(BONUS_NAME):	$(LIBFT_PATH)/libft.a $(OBJS_BONUS)
			$(CC) $(CFLAGS) -o $(BONUS_NAME) $(OBJS_BONUS) $(LIBFT_PATH)/libft.a

$(LIBFT_PATH)/libft.a:
	@make -C $(LIBFT_PATH)

clean:
			$(RM) $(OBJS) $(LIBFT_PATH)/libft.a $(OBJS_BONUS)
			@make -C $(LIBFT_PATH) clean

fclean:			clean
			$(RM) $(NAME) $(LIBFT_PATH)/libft.a $(BONUS_NAME)
			@make -C $(LIBFT_PATH) fclean
			

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus