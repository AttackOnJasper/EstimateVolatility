CXX = g++					# compiler
CXXFLAGS = 


OBJECTS = main.o OptionFunction.o
EXEC = stock

DEPENDS = ${OBJECTS:.o=.d}


#############################################################

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} $^ -o $@

#############################################################


-include ${DEPENDS}				# include *.d files containing program dependences

clean :						# remove files that can be regenerated
	rm -f *.d *.o  ${EXEC}
