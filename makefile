all:
	gcc $(wildcard *.c *.h) -o main -Wall -std=c89
