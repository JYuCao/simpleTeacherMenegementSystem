objects = main.o Linklist.o SMS_Linklist.o
CC = cc
CPPFLAGS = 

run: $(objects)
	$(CC) -o run $(objects)

%.d: %.c
	@set -e; rm -f $@; \
	$(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

main.o main.d: main.c

Linklist.o Linklist.d: Linklist.c

TMS_Linklist.o TMS_Linklist.d: TMS_Linklist.c

.PHONY: clean

clean:
	rm -f $(objects) run
