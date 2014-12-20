menu: menu.o order_list.o
	gcc -o menu menu.o order_list.o
menu.o: menu.c order_list.h
	gcc -c menu.c
order_list.o: order_list.h order_list.c
	gcc -c order_list.c
clean:
	rm -rf *.o menu

