Flag=-Wall -Wextra
CC=g++

communiToolsx: communiTools.o communiTools_functions.o
	${CC} communiTools.o communiTools_functions.o -o $@


communiTools.o: communiTools_main.cpp communiTools_header.hpp
	${CC} ${Flag} -c $< -o $@

communiTools_functions.o: communiTools_functions.cpp communiTools_header.hpp
	${CC} ${Flag} -c $< -o $@

.PHONY: clean
clean:
	rm *.o communiToolsx