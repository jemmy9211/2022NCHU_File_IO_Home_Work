#include<iostream>
#include<dirent.h>
#include<stdio.h>
#include<string.h>
#include<typeinfo>
#include<sys/types.h>
#include<libgen.h>
#include<errno.h>
#include <stdbool.h>
#include<unistd.h>
using namespace std;

bool found=false;
bool searchfile(const char* path,const char* target){
	DIR* pDir=opendir(path);
	if (pDir == NULL) {
    	//printf("Open Directory Error\t%s\n", path);
    	return false;
  	}
  	
	struct dirent* pEntry=NULL;
    while((pEntry=readdir(pDir))!=NULL){
    	if(pEntry->d_type==DT_DIR){
    		//printf("%s %dfolder\n",pEntry->d_name,pEntry->d_type);
    		if(!strcmp(pEntry->d_name,"..") || !strcmp(pEntry->d_name,".")){
    			//printf("==============back folder\n");
    		}else{
    			char *new_path = (char*)malloc(strlen(path) + strlen(pEntry->d_name) + 2);
			    strcpy(new_path, path);
			    if (strcmp(path, "/") != 0) {
				  strcat(new_path, "/");
			    }
			    strcat(new_path, pEntry->d_name);
			    
    			
    			if (searchfile(new_path, target)) {
				   found = true;
         	    }
			    free(new_path);
    	   }
    		
    		
    
    	}else if(!strcmp(pEntry->d_name,target)){
    		found = true;
      		printf("found in  %s/%s\n", path, pEntry->d_name);
    		
    	}
    			
    }
    if (closedir(pDir) < 0) {
    	printf("Close Directory Error\n");
  	}
    return found;
}

int main(int argc,char** argv){
	//process argument
	const char *path;
	const char *target;
	if(argc<3){
		cout<<"==============="<<endl;
		cout<<"from path:"<<"."<<endl;
		cout<<"search file:"<<argv[1]<<endl;
		cout<<"==============="<<endl;
		path=getcwd(NULL, 0);
		target=argv[1];	
		
	}else{
		cout<<"==============="<<endl;
		cout<<"from path:"<<argv[1]<<endl;
		cout<<"search file:"<<argv[2]<<endl;
		cout<<"==============="<<endl;
		path=argv[1];
		target=argv[2];
	}
	found=false;
	found=searchfile(path,target);
	if(!found){
			cout<<"cannot find corresponding file"<<endl;
	}
	
	//printf("%p",s);
	
    return 0;
}
