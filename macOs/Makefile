BDIR			:=	bin/
TARGET			:=	$(BDIR)LYRE
MAKEFLAGS		+=	--silent

#	LIBRARIES

LDIR			:=	lib/

buildLib		:
				cd $(LDIR)audioShell && make build
				cd $(LDIR)iris && make build

cleanLib		:
				cd $(LDIR)audioShell && make clean
				cd $(LDIR)iris && make clean

fcleanLib		:
				cd $(LDIR)audioShell && make fclean
				cd $(LDIR)iris && make fclean

#	COMPILATION

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

#	RULES

build			: $(OBJ) buildLib
				mkdir -p $(BDIR)
				$(CC) $(LFLG) $(OBJ) -o $(TARGET) -L./$(LDIR)audioShell/ -lAudioShell -L./$(LDIR)iris/ -lIris

clean			: cleanLib
				rm -rf $(ODIR)

fclean			: clean fcleanLib
				rm -rf $(BDIR)

re				: fclean build

all				: build clean

.PHONY			: all clean fclean re all