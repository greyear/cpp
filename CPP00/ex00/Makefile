# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/02 11:27:58 by azinchen          #+#    #+#              #
#    Updated: 2025/06/02 11:33:04 by azinchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Standard
NAME 			=	miniRT

# Directories
SRC_DIR 		=	src
OBJ_DIR 		=	obj

#Includes

INCLUDE 		=	./include/
HEADERS			=	-I$(LIBFT_INC) -I$(MLX_INC)

# Compiler and compilation flags
CC 				=	c++
CFLAGS 			=	-Wall -Wextra -Werror -std=c++98
RM				=	rm -f

# Source files
PARS_FILES		=	file_validation.c \
					set.c

SRC_FILES		=	$(addprefix $(PARS_DIR)/, $(PARS_FILES)) \
					main.c

SRC				=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

# Object files
OBJ 			=	$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

#Build rules
all: 			$(NAME)

$(NAME): 		$(OBJ)
				@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(HEADERS) $(LIB) -o $(NAME)
				@echo "$(GREEN) Compiled!$(DEF_COLOR)"

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) $(INCLUDE_DIR) -Imlx -c $< -o $@

clean:
				@echo "$(YELLOW) Deleting object files... $(DEF_COLOR)"
				@$(RM) -rf $(OBJ_DIR)
		
fclean: 		clean 
				@echo "$(RED) Deleting miniRT... $(DEF_COLOR)"
				@$(RM) $(NAME)
			
re: 			fclean all

.PHONY: 		all clean fclean re
