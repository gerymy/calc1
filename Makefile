all: calk 
	
calk: calk.h main.c lib
	gcc main.c -ldl -g -o calk 
lib: calk.h mat.c vvod.c multi.c dedu.c summ.c 
	gcc vvod.c -o libvvod.so -shared -fPIC 
	gcc dedu.c -o libdedu.so -shared -fPIC
	gcc summ.c -o libsumm.so -shared -fPIC
	gcc multi.c -o libmulti.so -shared -fPIC
	gcc mat.c -o libdiv.so -shared -fPIC	
clear:
	-rm *.o
o: mat.c vvod.c summ.c dedu.c multi.c
	gcc -c mat.c
	gcc -c vvod.c
	gcc -c summ.c
	gcc -c dedu.c
	gcc -c multi.c
