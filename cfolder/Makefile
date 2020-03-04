GCC = g++
MYSQLCFLAGS=$(mysql_config --cflags)
MYSQLLIBS=$(mysql_config --libs)

show: show.o
	$(GCC)  -o ../cgi/show show.o -L/usr/lib/x86_64-linux-gnu -lmysqlclient
show.o: show.cpp
	$(GCC) -c show.cpp
