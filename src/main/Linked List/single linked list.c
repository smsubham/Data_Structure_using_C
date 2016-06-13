// single linked list implementation in C
#include <stdio.h>
#include <malloc.h>
struct node //node for single linked list
{
    int data;
    struct node *next;
}*start=NULL;
void main()
{
    int i,j;
    do
    {
        printf("1. Create a list\n");
        printf("2. Insert a node at beginning\n");
        printf("3. Insert a node in middle\n");
        printf("4. Insert a node at end\n");
        printf("5. Insert a node after a node\n");
        printf("6. Insert a node before a node\n");
        printf("7. Delete a node at beginning\n");
        printf("8. Delete a node at middle\n");
        printf("9. Delete a node at end\n");
        printf("10. Delete a node after a node\n");
        printf("11. Delete a node before a node\n");
        printf("12. Delete list\n");
        printf("13. Search list\n");
        printf("14. Sort list\n");
        printf("15. Traverse list\n");
        printf("16. Exit\n");
        scanf("%d",&i);
        switch(i)
        {
            case 1: create_list(start);
                    break;
            case 2: insert_beg(); printf("%d\n",start->next->next->data); break;
            //case 3: insert_mid(); break;
            case 4: insert_end(); break;
            case 5: insert_after(); break;
            case 6: insert_before(); break;
            /*case 7: delete_beg(); break;
            case 8: delete_mid(); break;
            case 9: delete_end(); break;
            case 10: delete_after(); break;
            case 11: delete_before(); break;
            case 12: delete_list(); break;
            case 13: search_list(); break;
            case 14: sort_list(); break;*/
            case 15: traverse_list(); break;
            default: printf("Invalid choice!!! Enter again");
        }
    } while(i!=16);
}

void create_list()
{
  struct node *new_node,*ptr;
  int i,data;
  printf("press 1 to add more node or 0 to abort adding\n");
  scanf("%d%d",&i,&data);
while(i!=0)
{
    new_node=(struct node*) malloc(sizeof(struct node));
    new_node->data=data;
    if(start==NULL)
       {
            start=ptr=new_node;
            new_node->next=NULL;
            printf("%p\n",start);
             printf("%p\n%d\n",start->next,start->data);
       }
    else if(i==1)
       {
          ptr->next=new_node;
          ptr=new_node;
          new_node->next=NULL;
          printf("%p\n",start);
          printf("%p\n%d\n",new_node->next,new_node->data);
       }
  printf("press 1 to add more node or 0 to abort adding");
  scanf("%d%d",&i,&data);
}
}
void traverse_list()
{
    struct node *ptr;
     ptr=start;
   while(ptr!=NULL)
   {
      printf("%d\n",ptr->data);
      ptr=ptr->next;
   }
}
void insert_beg(struct node *start)
{
    int data;
    struct node *new_node;
    printf("enter data for node\n");
    scanf("%d",&data);
    new_node=(struct node*) malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=start;
    start=new_node;
}
void insert_end()
{
    int data;
    struct node *new_node,*ptr;
    printf("enter data for node\n");
    scanf("%d",&data);
    new_node=(struct node*) malloc(sizeof(struct node));
    while(ptr->next!=NULL)
        {
           ptr=ptr->next;
           printf("enter data for node\n");
        }
    ptr->next=new_node;
    new_node->data=data;
    new_node->next=NULL;
}
void insert_before()
{
    int data,i;
    struct node *new_node,*ptr;
    printf("enter data for node and node no before which new node is to be inserted\n");
    scanf("%d%d",&data,&i);
    new_node=(struct node*) malloc(sizeof(struct node));
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=new_node;
    new_node->data=data;
    new_node->next=NULL;
}
void insert_after()
{
    int data,i,a;
    struct node *new_node,*ptr;
    printf("enter data for node and node no of new node after which new node is to be inserted\n");
    scanf("%d%d",&data,&i);
    new_node=(struct node*) malloc(sizeof(struct node));
    ptr=start;
    while(ptr->next!=NULL && a!=i)
    {
        ptr=ptr->next;
        a++;
    }
    if(a!=i)
    {
        printf("Entered no of nodes doesn't exist");
        return;
    }
    ptr=ptr->next;
    ptr->next=new_node;
    new_node->data=data;
    new_node->next=NULL;
}
