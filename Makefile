# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brichard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 12:04:00 by brichard          #+#    #+#              #
#    Updated: 2019/02/13 11:44:44 by brichard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                   VARIABLES                                  #
################################################################################

NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIB_NAME = $(LIBS:=.a)

LIB = libraries

LIB_PATH = $(addprefix $(LIB)/, $(LIBS))

D_LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))

INC = includes

MLX_PATH = /usr/local/

SRCS_PATH = srcs

OBJS_PATH = obj

OBJS = $(SRCS:.c=.o)

D_OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS))

################################################################################
#                                    LIBS                                      #
################################################################################

LIBS = libft \
	  # libgraph

################################################################################
#                                    SRCS                                      #
################################################################################

SRCS =	main.c

################################################################################
#                                    COlORS                                    #
################################################################################

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

################################################################################
#                                   COMMANDS                                   #
################################################################################

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(D_LIB) $(OBJS_PATH) $(INC) $(D_OBJS)
	@$(call run_and_test, $(CC) $(CFLAGS) -o $(NAME) $(D_OBJS) -L ./$(LIB_PATH) -lft -I $(MLX_PATH)/include/ -L $(MLX_PATH)/lib/ -lmlx -framework OpenGL -framework AppKit)

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	@$(call run_and_test, $(CC) $(CFLAGS) -o $@ -c $< -I $(INC) -I $(LIB_PATH)/$(INC))

$(OBJS_PATH) :
	@$(call run_and_test, mkdir -p $@)

$(LIB_PATH)/%.a:
	@make -C $(LIB_PATH)

clean:
	@$(call run_and_test, rm -f $(D_OBJS) && rm -rf $(OBJS_PATH) && make clean -C $(LIB_PATH))

fclean: clean
	@$(call run_and_test, rm -f $(NAME) && rm -rf $(LIB_PATH)/$(LIB_NAME))

re: fclean all
