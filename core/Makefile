BDIR			:=	bin/
NAME			:=	$(BDIR)soundCore
MAKEFLAGS		+=	--silent

SDIR			:=	src/
SRC				:=	$(shell find src -name "*.cpp")

ODIR			:=	.obj/
OBJ				:=	$(subst $(SDIR),$(ODIR), ${SRC:.cpp=.o})

CC				:=	c++
CFLG			:=	-std=c++20
LFLG			:=

$(ODIR)%.o		: $(SDIR)%.cpp
				mkdir -p $(subst $(SDIR),$(ODIR), $(shell dirname $<)/)
				$(CC) $(CFLG) -c $< -o ${addprefix $(ODIR), ${<:$(SDIR)%.cpp=%.o}}

${NAME}			: $(OBJ)
				mkdir -p $(BDIR)
				$(CC) $(LFLG) $(OBJ) -o $(NAME)

all				: $(NAME)

clean			:
				rm -rf $(ODIR)

fclean			: clean
				rm -rf $(BDIR)

re				: fclean all

.PHONY			: all clean fclean re