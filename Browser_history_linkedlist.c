#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct Page{ //Doubly linked list
    char url[50];
    struct Page *next;
    struct Page *prev;
};

void loadingbar(){ // loading bar effect using sleep()
    printf("Loading ::");
    for (int i=0;i<5;i++){
        printf(".....");
        sleep(1);
    }
    printf("\n");
}


int main(){
    loadingbar();
}