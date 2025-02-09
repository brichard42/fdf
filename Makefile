# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brichard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 12:04:00 by brichard          #+#    #+#              #
#    Updated: 2019/03/04 19:21:52 by brichard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                   VARIABLES                                  #
################################################################################

NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INC_FLAGS = $(addprefix -I , $(LIB_INC))

SANITIZE = -g -g3 -fsanitize=address

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
		ft_t_pointnew.c \
		treat_img.c \
		maths.c \
		key_func.c \
		key_func_2.c \
		key_func_3.c \
		fdf_colors.c \
		bresenham.c

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

$(NAME): $(LIB_PATH)/libft.a $(OBJS_PATH) $(INC) $(D_OBJS)
	@$(call run_and_test, $(CC) $(CFLAGS) -o $(NAME) $(D_OBJS) -I $(MLX_PATH)/include/ -L $(MLX_PATH)/lib/ -lmlx -framework OpenGL -framework AppKit -L ./$(LIB)/libft -lft )

linux: $(OBJS_PATH) $(INC) $(D_OBJS)
	@$(call run_and_test, $(CC) $(CFLAGS) -o $(NAME) $(D_OBJS) -I ./$(LIB)/libmlx/include/ -L ./$(LIB)/libmlx/ -lmlx -L ./$(LIB)/libft -lft -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11 -lm)

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	@$(call run_and_test, $(CC) $(CFLAGS) -o $@ -c $< -I $(INC) $(INC_FLAGS))

$(OBJS_PATH) :
	@$(call run_and_test, mkdir -p $@)

$(LIB_PATH)/libft.a:
	@make -C $(LIB_PATH)

CLEAN_LIB = $(addprefix && make clean -C , $(LIB_PATH))
clean:
	@$(call run_and_test, rm -f $(D_OBJS) && rm -rf $(OBJS_PATH) $(CLEAN_LIB))

FCLEAN_LIB = $(addprefix && make fclean -C , $(LIB_PATH))
fclean:
	@$(call run_and_test, rm -f $(D_OBJS) && rm -rf $(OBJS_PATH) && rm -f $(NAME) $(FCLEAN_LIB))

re: fclean all
