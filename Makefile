CXX = g++
CXXFLAGS = -g -Wall -MMD
OBJECTS = main2.o mediator2.o object2.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = cc3k
${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}
-include ${DEPENDS} 
.PHONY : clean
clean : 
	rm -rf ${DEPENDS} ${OBJECTS} ${EXEC} 
