EXEC=prog
FILE=main.cc
FLAGS=-std=c++14

${EXEC}: ${FILE}
	g++ ${FLAGS} ${FILE} -o ${EXEC}
	./${EXEC}

clean:
	rm ${EXEC}
