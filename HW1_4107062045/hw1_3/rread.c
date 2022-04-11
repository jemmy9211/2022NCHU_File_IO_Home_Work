#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/time.h>
#include<time.h>
int gettimeofday(struct timeval *tv,struct timezone *tz);
int main(){
    int fd;
    char *str;
    int filesize=200*1024*1024;
    str = (char*)malloc(3*1024);
    struct timeval start;
    struct timeval end;
    struct timeval n;
    unsigned long diff;
    srand(time(NULL));
   	
    fd=open("file1.txt",O_CREAT | O_RDWR);
    
    gettimeofday(&start, &n);
    for(int i=0;i<50000;i++){
    	int offset=(rand()%filesize)+1;
    	lseek(fd,offset,SEEK_SET);
    	read(fd,str,(3*1024)/sizeof(char));
    }
    gettimeofday(&end,&n);
    diff = 1000000*(end.tv_sec-start.tv_sec)+end.tv_usec-start.tv_usec;
    printf("Random Read took %ld (us)\n", diff);
    close(fd);


    return 0;	
    
}

