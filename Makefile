NAME		=	codingame.cpp
CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -MMD
SRC			=	Olymbits.cpp main.cpp
INC_FILE	=	Olymbits.hpp
INC			=	-I ${INC_PATH}
INC_PATH	=	./inc/
SRC_PATH	=	./src/
OBJ_PATH	=	./obj/
OBJ			=	${addprefix ${OBJ_PATH}, ${SRC:.cpp=.o}}
DEP			=	${OBJ:.o=.d}

${NAME}:${addprefix ${INC_PATH}, ${INC_FILE}} ${addprefix ${SRC_PATH}, ${SRC}}
	@cat $^ | grep -v '#\s*include\s*"' > ${NAME}

${OBJ_PATH}:
	mkdir -p ${OBJ_PATH}

${OBJ_PATH}%.o:${SRC_PATH}%.cpp
	@mkdir -p ${dir $@}
	${CPP} ${CPPFLAGS} -c $< -o $@ ${INC}

all:${NAME}

clean:
	rm -rf ${OBJ_PATH} .vscode

fclean:clean
	rm -rf ${NAME}

re:fclean
	make all

.PHONY: all clean fclean re

-include ${DEP}
