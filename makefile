menu: menu.o order_list.o orderStructure.o
	gcc -o menu menu.o order_list.o orderStructure.o
menu.o: menu.c order_list.h orderStructure.h
	gcc -c menu.c 
order_list.o: order_list.h order_list.c 
	gcc -c order_list.c
orderStructure.o: orderStructure.h orderStructure.c
	gcc -c orderStructure.c
clean:
	rm -rf *.o menu

