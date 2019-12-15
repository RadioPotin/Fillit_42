# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evogel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 16:47:44 by evogel            #+#    #+#              #
#    Updated: 2019/07/18 15:14:27 by dapinto          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INC = .

L_INC = libft/includes

P_SRCS = .

SRCS = main.c \
	   algo.c \
	   check_relative.c \
	   ft_eraser.c \
	   ft_listdelete.c \
	   ft_placer.c \
	   mapper.c \
	   get_tetri.c \
	   make_node.c \
	   ft_listlen_tet.c

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

define run_and_test
printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@F)$(NO_COLOR)\r"; \
	$(1) 2> $@.log; \
	RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"   ; \
	elif [ -s $@.log ]; then \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"   ; \
	else  \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"   ; \
	fi; \
	cat $@.log; \
	rm -f $@.log; \
	exit $$RESULT
endef

OK_STRING    = "[OK]"
ERROR_STRING = "[ERROR]"
WARN_STRING  = "[WARNING]"
COM_STRING   = "Compiling"

P_OBJS = .

OBJS = $(SRCS:.c=.o)

D_OBJS = $(addprefix $(P_OBJS)/, $(OBJS))

P_LIB = libft

all: $(NAME)

$(NAME): $(INC) $(D_OBJS)
	@make -C $(P_LIB)
	@$(call run_and_test, $(CC) $(CFLAGS) -o $(NAME) $(D_OBJS) -I $(L_INC) -I $(INC) -L $(P_LIB) -lft)

$(P_OBJS)/%.o: $(P_SRCS)/%.c
	@$(call run_and_test, $(CC) $(CFLAGS) -o $@ -c $< -I$(INC))

clean:
	@make -C $(P_LIB) clean
	@$(call run_and_test, rm -f $(D_OBJS))

fclean: clean
	@make -C $(P_LIB) fclean
	@$(call run_and_test, rm -f $(NAME))

re: fclean all
