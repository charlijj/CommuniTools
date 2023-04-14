G = g++-4.9 -std=c++11 
CFLAGS = -I/usr/local/lib/Oracle/instantclient_11_2/sdk/include -Wall -Wextra
LFLAGS = -L/usr/local/lib/Oracle/instantclient_11_2 -locci -lociei

communiToolsx: communiTools.o communiTools_functions.o
	$(G) $(LFLAGS) communiTools.o communiTools_functions.o -o $@

communiTools.o: communiTools_main.cpp communiTools_header.hpp
	${G} ${CFLAGS} -c $< -o $@

communiTools_functions.o: communiTools_functions.cpp communiTools_header.hpp
	${G} ${CFLAGS} -c $< -o $@

.PHONY: clean
clean:
	rm *.o communiToolsx