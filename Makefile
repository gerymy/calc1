all: calk lib
	
calk: calk.h main.c 
	gcc main.c -ldl -g -o calc 
	gcc -o ./lib/libvvod.so -shared -fPIC ./lib/vvod.c
	gcc -o ./lib/libminus.so -shared -fPIC ./lib/minus.c
	gcc -o ./lib/libplus.so -shared -fPIC ./lib/plus.c
	gcc -o ./lib/libumnojaem.so -shared -fPIC ./lib/umnojaem.c
	gcc -o ./lib/libdelim.so -shared -fPIC ./lib/delim.c	

