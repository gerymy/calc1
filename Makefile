all: calk lib
	
calk: calk.h main.c 
	gcc main.c -ldl -g -o calc 
	gcc -o ./lib/libvvod.so -shared -fPIC ./lib/vvod.c
	gcc -o ./lib/libdedu.so -shared -fPIC ./lib/dedu.c
	gcc -o ./lib/libsumm.so -shared -fPIC ./lib/summ.c
	gcc -o ./lib/libmulti.so -shared -fPIC ./lib/multi.c
	gcc -o ./lib/libdiv.so -shared -fPIC ./lib/mat.c	

