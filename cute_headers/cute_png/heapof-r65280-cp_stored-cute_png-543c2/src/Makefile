poc_demo : poc_demo.c
	gcc -g -Wall -Werror -pedantic -fsanitize=address poc_demo.c -o $@ 
	# gcc -g -Wall -Werror -pedantic poc_demo.c -o $@  				# Reproduction for double-free memory corruption.
