SRC_DIR=src
OUTDIR=build
SRC=$(wildcard ${SRC_DIR}/*.c)
OBJ=$(patsubst ${SRC_DIR}/%.c, ${OUTDIR}/%.o, ${SRC})
CC=gcc
TARGET=${OUTDIR}/hello
all: ${TARGET}
${TARGET}: ${OBJ}
	${CC} $^ -o $@
${OUTDIR}:
	mkdir ${OUTDIR}
${OUTDIR}/%.o: ${SRC_DIR}/%.c | ${OUTDIR}
	${CC} -c $< -o $@
clean:
	rm -rf ${OUTDIR}
