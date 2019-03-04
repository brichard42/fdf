# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brichard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 12:04:00 by brichard          #+#    #+#              #
#    Updated: 2019/03/04 12:15:18 by brichard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                   VARIABLES                                  #
################################################################################

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INC = includes

SRCS_PATH = srcs

OBJS_PATH = obj

OBJS = $(SRCS:.c=.o)

D_OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS))

################################################################################
#                                    SOURCES                                   #
################################################################################

SRCS =			ft_strlen.c \
				get_next_line.c \
				ft_isdigit.c \
				ft_putendl.c \
				ft_bzero.c \
				ft_memset.c \
				ft_memalloc.c \
				ft_memdel.c \
				ft_lstnew.c \
				ft_lstdelone.c \
				ft_lstdel.c \
				ft_lstapp.c \
				ft_lstadd.c \
				ft_memcpy.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_strjoin.c \
				ft_strnew.c \
				ft_strsub.c \
				ft_del_cont.c

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
	@echo > /dev/null

$(NAME): $(OBJS_PATH) $(INC) $(D_OBJS)
	@$(call run_and_test, ar -rc $(NAME) $(D_OBJS))
	@ranlib $(NAME)

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INC)

$(OBJS_PATH):
	@mkdir -p $@

clean:
	@rm -f $(D_OBJS) && rm -rf $(OBJS_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all
