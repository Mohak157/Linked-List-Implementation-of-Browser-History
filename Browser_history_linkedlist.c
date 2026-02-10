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

void front_navigate()
{
    if (start == NULL || start->next == NULL)
    {
        printf("No page");
        return;
    }
    start = start->next;
    printf("URL is %s\n", start->url);
}
void back_navigate()
{
    if (start == NULL || start->prev == NULL)
    {
        printf("No page");
        return;
    }
    start = start->prev;
    printf("URL is %s\n", start->url);
}
void delete_a_single_page(int pos)
{ // delete a single node at a position
    if (start == NULL)
    {
        printf("No History");
        return;
    }
    struct Page *temp = start;
    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;
    }
    struct Page *deletionnode = temp;
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    free(deletionnode);
}

void full_history()
{ // show all nodes
    if (start == NULL)
    {
        printf("History Empty \n");
        return;
    }
    int count = 1;
    struct Page *temp = start;
    while (temp != NULL)
    {

        printf("%d : Page = %s\n", count, temp->url);
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
    start = NULL;
    loadingbar();
    printf("History cleared\t");
}

int main()
{
    printf(" __    __  ______   ______  ________   ______   _______  __      __ \n");
    printf("|  \\  |  \\|      \\ /      \\|        \\ /      \\ |       \\|  \\    /  \\\n");
    printf("| $$  | $$ \\$$$$$$|  $$$$$$\\\\$$$$$$$$|  $$$$$$\\| $$$$$$$\\\\$$\\  /  $$\n");
    printf("| $__| $$  | $$  | $$___\\$$  | $$   | $$  | $$| $$__| $$ \\$$\\/  $$ \n");
    printf("| $$    $$  | $$   \\$$    \\   | $$   | $$  | $$| $$    $$  \\$$  $$  \n");
    printf("| $$$$$$$$  | $$   _\\$$$$$$\\  | $$   | $$  | $$| $$$$$$$\\   \\$$$$   \n");
    printf("| $$  | $$ _| $$_ |  \\__| $$  | $$   | $$__/ $$| $$  | $$   | $$    \n");
    printf("| $$  | $$|   $$ \\ \\$$    $$  | $$    \\$$    $$| $$  | $$   | $$    \n");
    printf(" \\$$   \\$$ \\$$$$$$  \\$$$$$$    \\$$     \\$$$$$$  \\$$   \\$$    \\$$    \n");
    printf("                                                                    \n");
    printf("                                                                    \n");

    int choice;
    while (1)
    {
        printf("\nOPERATIONS\n");
        printf("\n1. Visit a page\n");
        printf("\n2.Show all history\n");
        printf("\n3.Clear all history\n");
        printf("\n4.Clear a singular history\n");
        printf("\n5.Forward Traversal\n");
        printf("\n6.Backward Traversal\n");
        printf("\nEnter operation:\t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            page_visit();
            break;
        case 2:
            full_history();
            break;
        case 3:
        clear_all_history();
        break;
        case 4:
        int poisition;
        printf("Enter the position of the page u want to delete\t");
        scanf("%d",&poisition);
        delete_a_single_page(poisition);
        break;
        case 5:
        front_navigate();
        break;
        case 6:
        back_navigate();
        break;
        default:
        printf("Invalid");
        }
    }
}