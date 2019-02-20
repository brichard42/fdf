# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brichard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 12:04:00 by brichard          #+#    #+#              #
#    Updated: 2019/02/20 20:42:38 by brichard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                   VARIABLES                                  #
################################################################################

NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INC_FLAGS = $(addprefix -I , $(LIB_INC))

LIB = libraries

LIB_PATH = $(addprefix $(LIB)/, $(LIBS))

LIB_INC = $(addsuffix /$(INC), $(LIB_PATH))

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

################################################################################
#                                    SRCS                                      #
################################################################################

SRCS =	main.c \
		fdf_parsing.c \
		fdf_utils.c \
		fdf_init.c \
		image_pixel_put.c \
		treat_img.c

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
#                                    SHELL                                     #
################################################################################

define lib_script
	for dir in $(LIB_PATH); do \
		(${MAKE} -C $$dir); \
		done; \

endef

################################################################################
#                                   COMMANDS                                   #
################################################################################

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): lib $(OBJS_PATH) $(INC) $(D_OBJS)
	@$(call run_and_test, $(CC) $(CFLAGS) -o $(NAME) $(D_OBJS) -I $(MLX_PATH)/include/ -L $(MLX_PATH)/lib/ -lmlx -framework OpenGL -framework AppKit -L ./$(LIB)/libft -lft )

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	@$(call run_and_test, $(CC) $(CFLAGS) -o $@ -c $< -I $(INC)  $(INC_FLAGS))

$(OBJS_PATH) :
	@$(call run_and_test, mkdir -p $@)

lib:
	@$(call lib_script)

CLEAN_LIB = $(addprefix && make clean -C , $(LIB_PATH))
clean:
	@$(call run_and_test, rm -f $(D_OBJS) && rm -rf $(OBJS_PATH) $(CLEAN_LIB))

FCLEAN_LIB = $(addprefix && make fclean -C , $(LIB_PATH))
fclean:
	@$(call run_and_test, rm -f $(D_OBJS) && rm -rf $(OBJS_PATH) && rm -f $(NAME) $(FCLEAN_LIB))

re: fclean all
