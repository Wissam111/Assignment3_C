CC=gcc
FLAGS=-Wall	-g
AR=ar


all:	stringProg
		

stringProg:	main.o libmylib.a	
			$(CC) $(FLAGS)	-o stringProg main.o ./libmylib.a
#static lib	
libmylib.a: sequence.o
			$(AR)	-rcs libmylib.a	sequence.o
main.o:	main.c sequence.h
			$(CC)	$(FLAGS) -c main.c

sequence.o:	sequence.c sequence.h
		$(CC)	$(FLAGS) -c sequence.c


.PHONY:	clean

clean:	
	rm -f	*.o	stringProg	*.a	*.so