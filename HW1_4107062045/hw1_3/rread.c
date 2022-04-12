#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/time.h>
#include<sys/mman.h>
#include<string.h>
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
    int *map_f1;
    struct stat sb;
    srand(time(NULL));
   	
    
    fd=open("file1.txt",O_CREAT | O_RDWR);
    fstat(fd,&sb);
    map_f1=(int*)mmap(NULL,sb.st_size,PROT_WRITE | PROT_READ, MAP_SHARED,fd,0);
    if(map_f1 == MAP_FAILED) /* 判断是否映射成功 */
        printf("error");
    gettimeofday(&start, &n);
    for(int i=0;i<50000;i++){
    	int offset=(rand()%filesize)+1;
    	lseek(*map_f1,offset,SEEK_SET);
    	read(*map_f1,str,(3*1024)/sizeof(char));
    }
    gettimeofday(&end,&n);
    diff = 1000000*(end.tv_sec-start.tv_sec)+end.tv_usec-start.tv_usec;
    printf("Random Read took %ld (us)\n", diff);
    close(fd);


    return 0;	
    
}

