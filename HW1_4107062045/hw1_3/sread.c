#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/time.h>
#include<sys/mman.h>
#include<string.h>

int gettimeofday(struct timeval *tv,struct timezone *tz);
int main(){
    int fd;
    char *str;
    int filesize=200*1024*1024;
    str = (char*)malloc(4*1024);
    struct timeval start;
    struct timeval end;
    struct timeval n;
    unsigned long diff;
    int* map_f1;
    
   	
    fd=open("file1.txt",O_CREAT | O_RDWR);
    map_f1=(int*)mmap(NULL,filesize*sizeof(char),PROT_WRITE | PROT_READ, MAP_SHARED,fd,0);
    //printf("%d",*map_f1);
    
    /*
    lseek(*map_f1,0,SEEK_SET);
    gettimeofday(&start, &n);
    for(int i=0;i<filesize/(4*1024);i++){
    	read(*map_f1,str,(4*1024)/sizeof(char));
    }
    gettimeofday(&end,&n);
    diff = 1000000*(end.tv_sec-start.tv_sec)+end.tv_usec-start.tv_usec;
    printf("Sequential Read took %ld (us)\n", diff);
    */
    munmap(map_f1,filesize*sizeof(char));
    close(fd);


    return 0;	
    
}

