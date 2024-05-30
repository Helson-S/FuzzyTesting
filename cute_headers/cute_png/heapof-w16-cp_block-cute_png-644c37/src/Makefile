poc_demo : poc_demo.c
	gcc -g -Wall -Werror -pedantic -fsanitize=address poc_demo.c -o $@ 
	# gcc -g -Wall -Werror -pedantic poc_demo.c -o $@  		# Reproduction for unmap invalid memory area in __GI___libc_free() called at line 1189 of cute_png.h v1.05

