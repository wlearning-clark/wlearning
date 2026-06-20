VERSION = 0.0.1

COMMONINC = /usr/include

INCS = -I${COMMONINC}
LIBS = -lm -lstdc++

CPPFLAGS = --std=c++20 -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_POSIX_C_SOURCE=200809L -DVERSION=\"${VERSION}\"
# CFLAGS = -g -std=gnu11 -pedantic -Wall -Wextra -Os ${INCS} ${CPPFLAGS}
CFLAGS = -O --std=gnu11 -pedantic -Wall -Wextra -fno-asynchronous-unwind-tables -fcf-protection=none  ${INCS} ${CPPFLAGS}

LDFLAGS = ${LIBS}

ASFLAGS = -g --64
LINKFLAGS =

CC = gcc
