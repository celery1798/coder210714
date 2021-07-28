OBJS=main.o
OBJS+=mod1.o mod2.o
CFLAGS=-g -Wall

myproj:$(OBJS)
	$(CC) $^ -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@


clean:
	rm -rf  *.o  myproj


