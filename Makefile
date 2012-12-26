SUBJECT = subject.o subject_main.o 		                       		# target
INPUT = input.o input_main.o 
strategyValidation = rollno.o strategyVal.o strategyVal_main.o
REPORT = report.o report_main.o

CC = g++									# compiler variable
DEBUG = -g									# debugging flag 
CFLAGS = -c $(DEBUG)							# linking flag
LFLAGS =  $(DEBUG)					  	  # flag used in compiling and creating object files	

# All targets 
all: run_input run_subject run_strategyValid run_report

# target to generate executable file.

input: $(INPUT)
	$(CC) $(LFLAGS) $(INPUT) -o input

subject: $(SUBJECT)
	$(CC) $(LFLAGS) $(SUBJECT) -o subject
	
report: $(REPORT)
	$(CC) $(LFLAGS) $(REPORT) -o report

# target to run executable file
run_input: input input.in
	./input
	
run_report: report
	./report

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

strategyValid : $(strategyValidation)
	$(CC) $(LFLAGS) $(strategyValidation) -o strategyValid
	#./strategyValid_compile

run_strategyValid : strategyValid
	./strategyValid

strategyVal.o : strategyVal.cpp strategyVal.h rollno.h
	$(CC) $(CFLAGS) strategyVal.cpp

strategyVal_main.o : strategyVal_main.cpp
	$(CC) $(CFLAGS) strategyVal_main.cpp

rollno.o : rollno.cpp rollno.h 
	$(CC) $(CFLAGS) rollno.cpp
	
report.o : report.cc report.h FinalAllotment.out
	$(CC) $(CFLAGS) report.cc

report_main.o : report_main.cpp
	$(CC) $(CFLAGS) report_main.cpp

# to destroy all the object and exectuable file
clean:
	rm -f *.o *.out input subject strategyVal report

# to create tar file 	
#tar:
#	tar cfv seat.tar input_main.o input.o seat_main.o seat_functions.o
