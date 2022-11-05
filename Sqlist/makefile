objects = main.o Sqlist.o TMS_Sqlist.o
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

Sqlist.o Sqlist.d: Sqlist.c

TMS_Sqlist.o TMS_Sqlist.d: TMS_Sqlist.c

.PHONY: clean

clean:
	rm -f $(objects) run
