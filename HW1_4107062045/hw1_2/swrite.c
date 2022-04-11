#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/time.h>
int gettimeofday(struct timeval *tv,struct timezone *tz);
int main(){
    int fd;
    char *str;
    int filesize=200*1024*1024;
    str = (char*)malloc(2*1024);
    
    struct timeval start;
    struct timeval end;
    struct timeval n;
    unsigned long diff;
    for(int i = 0; i < 2*1024 ;i++){
   		str[i] = '1';
   	}
    fd=open("file1.txt",O_CREAT | O_RDWR);
    lseek(fd,0,SEEK_SET);
    gettimeofday(&start, &n);
    for(int i=0;i<filesize/(2*1024);i++){
    	write(fd,str,filesize/(2*1024));	
    }
	gettimeofday(&end, &n);
    diff = 1000000*(end.tv_sec-start.tv_sec)+end.tv_usec-start.tv_usec;
    printf("Sequential Write took %ld (us)\n", diff);
    
    close(fd);
    free(str);


    return 0;	
    
}

