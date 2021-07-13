# Tobechi Maduchukwu
# Lab 10

lab10: lab10.o ParseLine.o RunExternalCommand.o ProcessInput.o Redirection.o
	gcc -o lab10 lab10.o ParseLine.o RunExternalCommand.o ProcessInput.o Redirection.o -Wall

lab10.o: lab10.c lab9_10.h
	gcc -c lab10.c -Wall

ParseLine.o: ParseLine.c lab9_10.h
	gcc -c ParseLine.c -Wall

RunExternalCommand.o: RunExternalCommand.c lab9_10.h
	gcc -c RunExternalCommand.c -Wall

ProcessInput.o: ProcessInput.c lab9_10.h
	gcc -c ProcessInput.c -Wall

Redirection.o: Redirection.c lab9_10.h
	gcc -c Redirection.c -Wall
