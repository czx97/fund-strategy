# server:server.o
# gcc -o server server.o -L/usr/local/mysql/lib -Imysqlclient
server:server.c
	gcc -I/usr/include/mysql server.c -L/usr/lib/mysql -lmysqlclient -o server
.PHONY:clean
clean:
	rm server server.o
