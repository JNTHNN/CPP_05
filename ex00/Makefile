# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 11:14:43 by jgasparo          #+#    #+#              #
#    Updated: 2024/12/12 12:56:02 by jgasparo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:= Bureaucrat

CPP 		:= c++
CPPFLAGS	:= -Wall -Wextra -Werror -std=c++98 -MMD -fsanitize=address -g 

SRC_DIR		:=	sources/
OBJ_DIR		:=	.obj/
DEP_DIR		:=	.dep/
INC_DIR		:=	includes/

SRC_FILES	:= main.cpp Bureaucrat.cpp

OBJ_FILES	:=	$(SRC_FILES:.cpp=.o)
DEP_FILES	:=	$(OBJ_FILES:.o=.d)

SRC			:=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			:=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))
DEP			:=	$(addprefix $(DEP_DIR), $(DEP_FILES))

all: $(NAME)

$(NAME): $(OBJ)
		@echo CREATING BUREAUCRAT
		@$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJ)
		@sleep 1
		@tput cuu1 dl1
		@echo "BUREAUCRAT CREATED  " 


$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR) $(DEP_DIR)
	@$(CPP) $(CPPFLAGS) -I $(INC_DIR) -o $@ -c $<
	@mv $(OBJ_DIR)$*.d $(DEP_DIR)

-include $(DEP)

clean:
	@$(RM) -fr $(OBJ_DIR) $(DEP_DIR)
	@echo BUREAUCRAT DESTROYED BYE !
	@sleep 1
	@tput cuu1 dl1

fclean: clean
	@$(RM) $(NAME)
	@echo BUREAUCRAT DESTROYED BYE !
	@sleep 1
	@tput cuu1 dl1

re: fclean all

.PHONY : all clean fclean re