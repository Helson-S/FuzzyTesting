.phony: all

all : poc_demo exploit_demo

poc_demo : poc_demo.c
	gcc -g -O3 -Wall -pedantic -fsanitize=address poc_demo.c -o $@ 

exploit_demo : exploit_demo.c
	gcc -g -O3 -Wall -pedantic -fno-stack-protector exploit_demo.c -o $@ 
