include config.mk

TARGET = a.out
SRC = prt_builtin.c prt_builtin_ex.c
ASM = ${SRC:.c=.s}
OBJ = ${SRC:.c=.o}

# SRC = myprintf.s util.s
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

%.s: %.c
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
	rm -f ${ASM}

objclean:
	rm -f ${OBJ}

clean:
	rm -f ${OBJ} ${ASM} ${TARGET}

.PHONY: all options ${TARGET} asmclean objclean clean
