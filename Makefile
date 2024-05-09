# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 17:10:12 by seckhard          #+#    #+#              #
#    Updated: 2024/05/09 23:21:00 by seckhard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colours
GREEN=\e[0;32m
RED=\e[0;31m
NC=\e[0m

# Standard
NAME			= philo

# Source Files
SOURCES 		= main.c dinner_party.c dinner_police.c error.c init.c utils.c

# Object Files
OBJ_DIR			= o_files
OBJECTS 		= $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

# Directories


# Compiler and CFlags
CC 				= cc
CFLAGS			= -Wall -Wextra -Werror
INCLUDE_DIR		= include
CFLAGS 			+= -I$(INCLUDE_DIR)

# Default goal
.DEFAULT_GOAL := all

# Build Rules
$(NAME): 		$(OBJECTS)
				$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
				@echo "$(GREEN)Project built successfully$(NC)"

all:			$(NAME)

$(OBJ_DIR)/%.o:	%.c
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -c $< -o $@
				@echo "$(GREEN)Compiled $<$(NC)"

clean:
				rm -rf $(OBJ_DIR)
				@echo "$(RED)Cleaned$(NC)"

fclean:			clean
				rm -f $(NAME)
				@echo "$(RED)Fully cleaned$(NC)"

re:				fclean all
				@echo "$(GREEN)Project rebuilt successfully$(NC)"

.PHONY:			all clean fclean re