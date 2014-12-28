menu: menu.o order_list.o  tLinkTable.o
	gcc -o menu menu.o order_list.o  tLinkTable.o
menu.o: menu.c order_list.h orderStructure.h tLinkTable.h
	gcc -c menu.c 
order_list.o: order_list.h order_list.c 
	gcc -c order_list.c


tLinkTable.o:  tLinkTable.h tLinkTable.c
	gcc -c tLinkTable.c
clean:
	rm -rf *.o menu

