SUBJECT = subject.o subject_main.o 		                       		# target
INPUT = input.o input_main.o 
CC = g++									# compiler variable
DEBUG = -g									# debugging flag 
CFLAGS = -Wall -c $(DEBUG)							# linking flag
LFLAGS = -Wall $(DEBUG)					  	  # flag used in compiling and creating object files	

# All targets 
all: run_input run_subject

# target to generate executable file.

input: $(INPUT)
	$(CC) $(LFLAGS) $(INPUT) -o input

subject: $(SUBJECT)
	$(CC) $(LFLAGS) $(SUBJECT) -o subject

# target to run executable file
run_input: input input.in
	./input

run_subject: subject input_rollno.out
	./subject

# dependencies 
input_main.o: input_main.cpp input.h
	$(CC) $(CFLAGS) input_main.cpp

input.o: input.cpp input.h files.h
	$(CC) $(CFLAGS) input.cpp

subject_main.o: subject_main.cpp subject.h
	$(CC) $(CFLAGS) subject_main.cpp

subject.o: subject.cc subject.h files.h
	$(CC) $(CFLAGS) subject.cc

# to destroy all the object and exectuable file
clean:
	rm -f *.o *.out input subject

# to create tar file 	
tar:
	tar cfv seat.tar input_main.o input.o seat_main.o seat_functions.o
