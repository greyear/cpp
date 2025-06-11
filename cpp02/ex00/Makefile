# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/02 11:27:58 by azinchen          #+#    #+#              #
#    Updated: 2025/06/02 17:41:15 by azinchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
DEF_COLOR		=	\033[0;39m
RED				=	\033[0;91m
GREEN			=	\033[0;92m
BLUE			=	\033[0;94m

# Standard
NAME 			=	fixed

# Directories
OBJ_DIR 		=	obj

# Compiler and compilation flags
CXX				=	c++
CXXFLAGS 		=	-Wall -Wextra -Werror -std=c++98
RM				=	rm -f

# Source files
SRC				=	main.cpp Fixed.cpp

# Object files
OBJ 			=	$(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

# Build rules
all: 			$(NAME)

$(NAME): 		$(OBJ)
				@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
				@echo "$(GREEN) Compiled!$(DEF_COLOR)"

$(OBJ_DIR)/%.o:	%.cpp
				@mkdir -p $(@D)
				@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
				@$(RM) -rf $(OBJ_DIR)
				@echo "$(BLUE) Obj files deleted$(DEF_COLOR)"
		
fclean: 		clean
				@$(RM) $(NAME)
				@echo "$(BLUE) Cleaning finished$(DEF_COLOR)"
			
re: 			fclean all

.PHONY: 		all clean fclean re
