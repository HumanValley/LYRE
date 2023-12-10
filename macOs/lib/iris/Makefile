TARGET			:=	libIris.a
MAKEFLAGS		+=	--silent

SDIR			:=	src/
SRC				:=	$(shell find $(SDIR) -name "*.cpp")

ODIR			:=	.obj/
OBJ				:=	$(subst $(SDIR),$(ODIR), ${SRC:.cpp=.o})

CC				:=	c++
CFLG			:=	-std=c++20
LFLG			:=

$(ODIR)%.o		: $(SDIR)%.cpp
				mkdir -p $(subst $(SDIR),$(ODIR), $(shell dirname $<)/)
				$(CC) $(CFLG) -c $< -o ${addprefix $(ODIR), ${<:$(SDIR)%.cpp=%.o}}

${TARGET}		: $(OBJ)
				ar rcs $(TARGET) $(OBJ)

build			: $(OBJ)

clean			:
				rm -rf $(ODIR)

fclean			: clean
				rm -rf $(TARGET)

re				: fclean build

all				: build clean

.PHONY			: build clean fclean re all
