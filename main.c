#include <stdio.h> //io
#include <string.h>//работа со строками
#include <stdlib.h>//выделение памяти+модуль и деление
#include "calk.h"
#include <dlfcn.h>
int main()
{
	char znak_str[2];
	int znak;
	char quite_str[2];
	int quite=1;
    float real1=0, compx1=0;
	float real2=0, compx2=0;
	float real3=0, compx3=0;
	void *ld1;
	void *ld2;
	void (*orig_vvod)(float *, float *);
	void (*orig_clear)();
	void (*orig_math)(float *,float *, float *,float *,float *, float *);
	
	ld1=dlopen("./lib/libvvod.so", RTLD_NOW);
	orig_vvod=dlsym(ld1,"vvodi");
	orig_clear=dlsym(ld1,"clear");
	printf("Hello, ");
	 do
	 {	printf("type exspression: \n");
		orig_vvod(&real1, &compx1);
		orig_clear();
		printf("vvedite znak:");
		fgets(znak_str,2,stdin);
		if(strcmp(znak_str,"+")==0)znak=1;
		if(strcmp(znak_str,"-")==0)znak=2;
		if(strcmp(znak_str,"*")==0)znak=3;			
		if(strcmp(znak_str,"/")==0)znak=4;
		orig_vvod(&real2, &compx2);
		orig_clear();
		switch(znak)
		{
			case 1:
				ld2=dlopen("./lib/libsumm.so", RTLD_NOW);
				orig_math=dlsym(ld2,"summ");
				orig_math(&real1, &compx1, &real2, &compx2, &real3, &compx3);
				break;
			case 2:
				ld2=dlopen("./lib/libdedu.so", RTLD_NOW);
				orig_math=dlsym(ld2,"dedu");
				orig_math(&real1, &compx1, &real2, &compx2, &real3, &compx3);
				break;
			case 3:
				ld2=dlopen("./lib/libmulti.so", RTLD_NOW);
				orig_math=dlsym(ld2,"multi");
				orig_math(&real1, &compx1, &real2, &compx2, &real3, &compx3);
				break;
			case 4:
				ld2=dlopen("./lib/libdiv.so", RTLD_NOW);
				orig_math=dlsym(ld2,"dive");
				orig_math(&real1, &compx1, &real2, &compx2, &real3, &compx3);
				break;
		}
		printf("Rezult: %.2f + %.2fi", real3, compx3);
		orig_clear();
		printf("Continue? y/n\n");
		fgets(quite_str,2,stdin);
		quite=strcmp(quite_str,"y");
		dlclose(ld2);
	} while (quite==0);
	dlclose(ld1);
	return 0;
}
