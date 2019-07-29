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
	
	ld1=dlopen("./lib/libvvod.so", RTLD_NOW);//загрузка библиотеки для ввода
	orig_vvod=dlsym(ld1,"vvodi");
	orig_clear=dlsym(ld1,"clear");
	printf("Hello, ");
	 do
	 {	printf("type exspression: \n");
		orig_vvod(&real1, &compx1);// ввод первого числа
		orig_clear();//очистка  буффера после сканф
		printf("vvedite znak(+,-,*,/):");
		fgets(znak_str,2,stdin);//ввод знака
		if(strcmp(znak_str,"+")==0)znak=1;
		if(strcmp(znak_str,"-")==0)znak=2;
		if(strcmp(znak_str,"*")==0)znak=3;			
		if(strcmp(znak_str,"/")==0)znak=4;
		orig_vvod(&real2, &compx2);//ввод второго числа
		orig_clear();
		switch(znak)//выбор и вызов функций
		{
			case 1:
				ld2=dlopen("./lib/libplus.so", RTLD_NOW);
				orig_math=dlsym(ld2,"plus");
				orig_math(&real1, &compx1, &real2, &compx2, &real3, &compx3);
				break;
			case 2:
				ld2=dlopen("./lib/libminus.so", RTLD_NOW);
				orig_math=dlsym(ld2,"minus");
				orig_math(&real1, &compx1, &real2, &compx2, &real3, &compx3);
				break;
			case 3:
				ld2=dlopen("./lib/libumnojaem.so", RTLD_NOW);
				orig_math=dlsym(ld2,"umnojaem");
				orig_math(&real1, &compx1, &real2, &compx2, &real3, &compx3);
				break;
			case 4:
				ld2=dlopen("./lib/libdelim.so", RTLD_NOW);
				orig_math=dlsym(ld2,"delim");
				orig_math(&real1, &compx1, &real2, &compx2, &real3, &compx3);
				break;
		}
		printf("Rezult: %.2f + %.2fi", real3, compx3);//вывод результата
		orig_clear();//очистка буффера
		printf("Continue? y/n\n");
		fgets(quite_str,2,stdin);//выход
		quite=strcmp(quite_str,"y");
		dlclose(ld2);
	} while (quite==0);
	dlclose(ld1);
	return 0;
}
