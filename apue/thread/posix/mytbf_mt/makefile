CFLAGS+=-pthread
LDFLAGS+=-pthread

mytbf:mytbf.o main.o
	gcc $(CFLAGS) $^ -o $@ $(LDFLAGS)


clean:
	rm *.o mytbf -rf



