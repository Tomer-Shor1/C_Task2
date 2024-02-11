CC=gcc
AR=ar
OBJECTS_MAIN=my_graph.o
OBJECTS_MAIN_KNAPSACK = my_Knapsack.o
OBJECTS_LIB=my_mat.o
FLAGS= -Wall -g

all: my_graph my_Knapsack

my_Knapsack: $(OBJECTS_MAIN_KNAPSACK) $(OBJECTS_LIB)
	$(CC) -o  my_Knapsack my_mat.o my_Knapsack.o

my_graph: $(OBJECTS_MAIN) $(OBJECTS_LIB) 
	$(CC) -o  my_graph my_mat.o my_graph.o
	
my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c

my_graph.o: my_graph.c my_mat.h
	$(CC) $(FLAGS) -c my_graph.c

my_Knapsack.o: my_mat.h my_Knapsack.c
	$(CC) $(FLAGS) -c my_Knapsack.c


clean:
	rm -f *.o *.a *.so my_graph my_Knapsack