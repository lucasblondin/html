GCC = g++
MYSQLCFLAGS=$(mysql_config --cflags)
MYSQLLIBS=$(mysql_config --libs)

reponse: reponse.o
	$(GCC)  -o ../cgi/reponse reponse.o -L/usr/lib/x86_64-linux-gnu -lmysqlclient
reponse.o: reponse.cpp
	$(GCC) -c reponse.cpp
