CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB=my_mat.o
FLAGS= -Wall -g

all: mains maind libmylib.so libmylib.a


mains: $(OBJECTS_MAIN) libmylib.a 
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libmylib.a
maind: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o maind $(OBJECTS_MAIN) ./libmylib.so

libmylib.so: $(OBJECTS_LIB)
	$(CC) -shared -o libmylib.so $(OBJECTS_LIB)

libmylib.a: $(OBJECTS_LIB)
	$(AR) -rcs libmylib.a $(OBJECTS_LIB)

my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c

main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c


clean:
	rm -f *.o *.a *.so progmains progmaind