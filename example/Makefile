all:
	gcc md5.c -lcrypto -o md5
	gcc crypto.c -lcrypto -o crypto 
	gcc inotify.c -o inotify
	gcc thread.c -o thread -lpthread
	gcc threadbench.c -o threadbench -lpthread

clean:
	rm -rf *.o
