CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
EXEC = chess
OBJECTS = cell.o board.o main.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
