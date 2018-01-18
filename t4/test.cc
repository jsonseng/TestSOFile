#include <iostream>  
#include <stdio.h>
#include <dlfcn.h>  
  
// using namespace std;  
  
int main(int argc, char **argv) {  
    if(argc != 2) {  
        printf("argument error!");
        // cout << "argument error!" << endl;  
        return 1;  
    }  
  
    //pointer to function  
    typedef void (*pf_t)();  
      
    char *err = NULL;  
    //open the lib  
    void *handle = dlopen(argv[1], RTLD_NOW);  
      
    if(!handle) {  
        printf("load failed!");
        return 1;  
    }  
  
    //clear error info  
    dlerror();  
  
    pf_t pf  = (pf_t)dlsym(handle, "HelloFunc");  
    err = dlerror();  
    if(err) {  
        printf("can't find symbol HelloFunc! ");  
        return 1;  
    }  
  
    //call function by pointer  
    pf();  
  
    dlclose(handle);  
  
    return 0;  
}  