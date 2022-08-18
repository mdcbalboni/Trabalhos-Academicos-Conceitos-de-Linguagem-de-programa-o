CC=gcc

CFLAGS=-g -O1 -std=c99 -pthread
CFLAGS2=-g -O1 -std=c99 -fopenmp

bucket: test
pthread: teste
openmp: teste2
all: print test print4 print1 teste print4 print2 teste2 print4

ord: OrdenaBucket.c
	$(CC) -o ord OrdenaBucket.c
	
ord2: OrdenaPthread.c 
	$(CC) $(CFLAGS) -o ord2 OrdenaPthread.c

ord3: OrdenaOpenMp.c
	$(CC) $(CFLAGS2) -o ord3 OrdenaOpenMp.c

test: ord
	time ./ord
	
teste: ord2
	time ./ord2
	
teste2: ord3
	time ./ord3

clean:
	rm -rf *.o ord ord2 ord3

print: 
	@echo "${\n}${\n}Sequencial: "
print1: 
	@echo "${\n\n\n}Pthreads: "
print2: 
	@echo "${\n\n\n}OpenMp: \n"
print4:
	@echo "${\n\n\n}"
