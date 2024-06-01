#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void insertatbeginning(struct node *head)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode != NULL)
    {
        scanf("%d", &newnode->data);
        newnode->next = head->next;
        head->next = newnode;
    }
}

void insertatmiddle(struct node* head)
{
    struct node* prev=head;
    struct node* current=head->next;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    int index=3;
    if(newnode!=NULL)
    {
        scanf("%d",&newnode->data);
        while(index--)
        {
            prev=current;
            current=current->next;
        }
        prev->next=newnode;
        newnode->next=current;
    }
}

void insertatending(struct node *head)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode != NULL)
    {
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        struct node *last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = newnode;
    }
}

void print(struct node *head)
{
    head = head->next;
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void searching(struct node *head)
{
    int x;
    printf("Enter what you want to search in linked list : ");
    scanf("%d", &x);
    head = head->next;
    while (head != NULL)
    {
        if (head->data == x)
        {
            printf("FOUND\n");
            exit(0);
        }
        head = head->next;
    }
    printf("NOT FOUND\n");
}
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
//void sortLinkedList(struct node* head) {
//    if (head == NULL || head->next == NULL)
//        return;
//
//    int swapped;
//    struct node* ptr1;
//    struct node* lptr = NULL;
//
//    do {
//        swapped = 0;
//        ptr1 = head->next;
//
//        while (ptr1->next != lptr) {
//            if (ptr1->data > ptr1->next->data) {
//                swap(&ptr1->data, &ptr1->next->data);
//                swapped = 1;
//            }
//            ptr1 = ptr1->next;
//        }
//        lptr = ptr1;
//        printf("After swapping: ");
//        print(head);
//    } while (swapped);
//}

void deletefrombeginning(struct node *head)
{
    if (head->next == NULL)
    {
        printf("List is empty. No node to delete.\n");
        return;
    }
    struct node *temp = head->next;
    head->next = temp->next;
    free(temp);
}

void deletefromanyindex(struct node* head)
{
    struct node* current=head->next;
    struct node* prev=head;
    int index=3;
    while(--index)
    {
        prev=current;
        current=current->next;
    }
    prev->next=current->next;
    free(current);
}

void deletefromending(struct node *head)
{
    if (head->next == NULL)
    {
        printf("List is empty. No node to delete.\n");
        return;
    }
    struct node *prev = head;
    struct node *current = head->next;
    while (current->next != NULL)
    {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    free(current);
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    if (head != NULL)
    {
        head->next = NULL;
        int n;
        printf("Enter list size : ");
        scanf("%d", &n);
        // while(n--)insertatbeginning(head);
        while (n--)insertatending(head);
        insertatmiddle(head);
        // printf("Before delete : ");
        print(head);
        // searching(head);
        // deletefrombeginning(head);
        // deletefromanyindex(head);
        // deletefromending(head);
        // printf("After delete : ");
        ///sortLinkedList(head);
        print(head);
    }
    return 0;
}
