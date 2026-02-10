#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct Page
{ // Doubly linked list
    char url[50];
    struct Page *next;
    struct Page *prev;
};
struct Page *start = NULL;
void loadingbar()
{ // loading bar effect using sleep()
    printf("Loading ::");
    for (int i = 0; i < 5; i++)
    {
        printf(".....");
        sleep(1);
    }
    printf("\n");
}

struct Page *add_history(char *url)
{ // Creating a new node
    struct Page *newpage = (struct Page *)malloc(sizeof(struct Page));
    strcpy(newpage->url, url); // cant assign string directly
    newpage->next = NULL;
    newpage->prev = NULL;
    return newpage;
}

void page_visit()
{ // add a new node
    char url[50];
    printf("Enter the url of the site ur visiting:");
    scanf("%s", url);
    loadingbar();
    struct Page *newpage = add_history(url);
    if (start == NULL)
    {
        start = newpage;
        return;
    }
    newpage->next = start;
    newpage->prev = NULL;
    start->prev = newpage;
    start = newpage;
}
void delete_a_single_page(int pos)
{ // delete a single node at a position
    struct Page* temp= start;
    for(int i=1;i<pos;i++){
        temp=temp->next;

    }
    struct Page* deletionnode = temp;
    free(deletionnode);
}
void full_history()
{ // show all nodes
    if (start == NULL)
    {
        printf("History Empty \n");
        return;
    }
    int count=1;
    struct Page *temp = start;
    while (temp != NULL)
    {

        printf("%d : Page = %s\n", count,temp->url);
        temp = temp->next;
        count++;
    }
}

void clear_all_history()
{ // remove all nodes
    if (start == NULL)
    {
        printf("There is no history to clear\t");
        return;
    }
    struct Page *temp = start;
    while (temp != NULL)
    {
        printf("Deleting..");
        struct Page *deletionitem = temp;
        free(deletionitem);
        temp = temp->next;
    }
    loadingbar();
    printf("History cleared\t");
}

int main()
{
    page_visit();
    page_visit();
    full_history();
}