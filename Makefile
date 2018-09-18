# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galemair <galemair@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/06 09:01:02 by galemair          #+#    #+#              #
#    Updated: 2018/09/18 15:34:08 by galemair         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER		=		checker

FLAGS		=		-Wall -Wextra -Werror

PUSH_SWAP	=		push_swap

INCLUDES	=		includes/

SRCS		=		srcs/instructions_manager/error.c\
					srcs/instructions_manager/push.c\
					srcs/instructions_manager/rev_rotate.c\
					srcs/instructions_manager/rotate.c\
					srcs/instructions_manager/swap.c\
					srcs/check_stack.c\
					srcs/checker.c\
					srcs/create_list.c\
					srcs/pre_sort.c\
					srcs/push_swap.c\
					srcs/push_swap_helper.c\
					srcs/small_list.c\
					srcs/sort_helper.c\
					srcs/utils.c\

OBJS		=		$(SRCS:.c=.o)


all:	 lib printf $(CHECKER) $(PUSH_SWAP)

$(CHECKER):	 srcs/main_checker.c $(SRCS) $(OBJS)
	@gcc $(FLAGS) -o $@ $(OBJS) srcs/main_checker.c -L libft/ -lft -L ft_printf/ -lftprintf -I $(INCLUDES)
	@printf	"\nCHECKER COMPILED\n"

$(PUSH_SWAP): srcs/main_push_swap.c $(SRCS) $(OBJS)
	@gcc $(FLAGS) -o $@ $(OBJS) srcs/main_push_swap.c -L libft/ -lft -L ft_printf/ -lftprintf -I $(INCLUDES)
	@printf	"\nPUSH_SWAP COMPILED\n"

lib:
	@make -C libft/

printf:
	@make -C ft_printf/

%.o : %.c
	@printf "👌🏼 "
	@gcc -o $@ -c $< -I $(INCLUDES)

clean:
	@make clean -C libft/
	@make clean -C ft_printf/
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C libft/
	@make fclean -C ft_printf/
	@rm -f $(CHECKER)
	@rm -f $(PUSH_SWAP)

re: clean fclean all

.PHONY:	clean fclean re
