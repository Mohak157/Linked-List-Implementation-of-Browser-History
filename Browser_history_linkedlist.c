#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct Page{ //Doubly linked list
    char url[50];
    struct Page *next;
    struct Page *prev;
};
struct Page *start =NULL;
void loadingbar(){ // loading bar effect using sleep()
    printf("Loading ::");
    for (int i=0;i<5;i++){
        printf(".....");
        sleep(1);
    }
    printf("\n");
}

struct Page *add_history(char *url){  //Creating a new node
    struct Page *newpage =(struct Page*)malloc(sizeof(struct Page));
    strcpy(newpage->url,url); // cant assign string directly
    newpage->next=NULL;
    newpage->prev = NULL;
    return newpage;

}

void page_visit(){
    char url[50];
    printf("Enter the url of the site ur visiting:");
    scanf("%s",url);
    loadingbar();
    struct Page *newpage =add_history(url);
    if(start==NULL){
        start=newpage;
        return;
    }
    newpage->next=start;
    newpage->prev=NULL;
    start->prev=newpage;
    start=newpage;
}

void full_history(){
    if (start==NULL){
        printf("History Empty \n");
        return;
    }
    struct Page *temp = start;
    while(temp != NULL){
      printf("Page : %s\n",temp->url);
      temp= temp->next;
  }
}

int main(){
    page_visit();
    page_visit();
    full_history();
    
}