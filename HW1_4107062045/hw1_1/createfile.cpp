#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main(){
    FILE *f1=fopen("./write.txt","w");
    char *mem;
    if(f1==NULL){
		printf("error");
    }else{
		int filesize=200*1024*1024;
		mem = (char*)malloc(filesize);
		for(int i=0; i<filesize/sizeof(char);i++){
		    mem[i]='0';
		}
        fwrite(mem,sizeof(char),filesize/sizeof(char),f1);
        fclose(f1);
		free(mem);
    }



    return 0;
    
}

