# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abosch <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 13:36:55 by abosch            #+#    #+#              #
#    Updated: 2020/02/20 12:48:30 by abosch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------------------#
#											  #
#				   VARIABLES				  #
#											  #
#---------------------------------------------#
NAME = ft_ls

CC = clang
CFLAGS = -Werror -Wextra -Wall

CPPFLAGS = -I$(INC_PATH) -Ilibft/$(INC_PATH) -g3
OPTIFLAGS = -O3

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#					SOURCES					  #
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
SRC_PATH = src
SRC_NAME = file.c dir.c print.c print2.c option.c cmp.c ft_ls.c main.c destroy.c

SRC :=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#					OBJECTS					  #
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ := $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

INC_PATH = include

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#					LIBRARY					  #
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
LIBDIR = -Llibft
LIBFLAGS = -lft

LIB_NAME = libft
LIB_PATH = .
LIB_DIR = libft/
LIB_PD := $(addprefix $(LIB_PATH)/, $(LIB_DIR))

LIB := $(addprefix $(LIB_PATH)/$(LIB_DIR), $(addsuffix .a,$(LIB_NAME)))
#---------------------------------------------#
#											  #
#					 RULES					  #
#											  #
#---------------------------------------------#

.PHONY: all, clean, fclean, re, norme, rere, lclean, lfclean, lib, pure

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#					RELEASE                   #
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
all: $(NAME)

$(NAME): $(OBJ) $(OBJ_CHECKER) $(LIB)
	$(CC) $^ $(CFLAGS) $(CPPFLAGS) -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(OPTIFLAGS) -o $@ -c $<
	@echo "Compiling $(NAME): $<"

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#					LIB						  #
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
libs: $(LIB)

$(LIB_PATH)/$(LIB_DIR)%.a: FORCE
	@make -C $(LIB_PATH)/$(LIB_DIR)

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#					CLEAN					  #
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
lclean:
	@make -C $(LIB_PD) clean

lfclean:
	@make -C $(LIB_PD) fclean

clean: lclean
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean lfclean
	@rm -f $(NAME)

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#					OTHER					 #
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
norme: lnorme
	norminette $(SRC)
	norminette $(INC_PATH)/*.h

lnorme:
	make -C $(LIB_PD) norme

re: fclean all

rere: lfclean fclean libs all

FORCE:

pure: all clean
