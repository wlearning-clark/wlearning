include config.mk

SHELL := cmd.exe
TARGET = a.exe
SRC = main.cpp
ASM = ${SRC:.cpp=.s}
OBJ = ${SRC:.cpp=.o}

# SRC = printf.s util.s
# OBJ = ${SRC:.s=.o}

all: options ${TARGET} ${ASM} objclean

options:
	@echo ${TARGET} build options:
	@echo "INCS      = ${INCS}"
	@echo "LDFLAGS   = ${LDFLAGS}"
	@echo "CFLAGS    = ${CFLAGS}"
	@echo "CC        = ${CC}"
	@echo "ASFLAGS   = ${ASFLAGS}"
	@echo "LINKFLAGS = ${LINKFLAGS}"
	@echo "SRC = ${SRC}"
	@echo "OBJ = ${OBJ}"
	@echo "ASM = ${ASM}"
	
# Automatic Variables
# The value of ‘$^’ is a list of all the prerequisites of the rule
# The automatic variable ‘$<’ is just the first prerequisite

%.s: %.cpp
	${CC} -S ${CFLAGS} $<

%.o: %.s
	${CC} -c ${CFLAGS} $<

${TARGET}: ${OBJ}
	${CC} -o $@ $^ ${LDFLAGS}

# %.o: %.s
# as -o $@ $< ${ASFLAGS}

# ${TARGET}: ${OBJ}
# ld -o $@ $^ ${LINKFLAGS}

run:
	./${TARGET}

asmclean:
	del /Q ${ASM}

objclean:
	del /Q ${OBJ}

clean:
	del /Q ${OBJ} ${ASM} ${TARGET}

.PHONY: options all ${TARGET} asmclean objclean clean
