All: program4

program4: program4.o tournament.o tournament.h players.dat 
	gcc -g program4.o tournament.o -o program4

run: program4
	./program4

program4.o: program4.c tournament.h players.dat 
	gcc -c -g program4.c -o program4.o

tournament.o: tournament.c tournament.h players.dat 
	gcc -c -g tournament.c -o tournament.o

memcheck: program4
	valgrind ./program4
	
clean: program4.o tournament.o program4
	rm program4.o tournament.o program4

submit:
	git commit -a -m "final commit"
	git push
	git rev-parse HEAD

