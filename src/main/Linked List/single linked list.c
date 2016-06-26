// single linked list implementation in C
#include <stdio.h>
#include <malloc.h>
struct node //node for single linked list
{
    int data;
    struct node *next;
};//*start=NULL;
struct node *start=NULL;

void main()
{
    int i,j;
    do
    {
        printf("1. Create a list\n");
        printf("2. Insert a node at beginning\n");
        printf("3. Insert a node at end\n");
        printf("4. Insert a node after a node\n");
        printf("5. Insert a node before a node\n");
        printf("6. Delete a node at beginning\n");
        printf("7. Delete a node at end\n");
        printf("8. Delete a node after a node\n");
        printf("9. Delete a node before a node\n");
        printf("10. Delete list\n");
        printf("11. Search list\n");
        printf("12. Sort list\n");
        printf("13. Traverse list\n");
        printf("14. Exit\n");
        scanf("%d",&i);
        switch(i)
        {
            case 1: create_list();
                    printf("%p\n%d\n",start->next,start->data);
                    break;
            case 2: insert_beg();
                    printf("%p\n%d\n",start->next,start->data);
                    break;
            case 3: insert_end(); break;
            case 4: insert_after(); break;
            case 5: insert_before(); break;
            case 6: delete_beg(); break;
            case 7: delete_end(); break;
            case 8: delete_after(); break;
            case 9: delete_before(); break;
            case 10: delete_list(); break;
            case 11: search_list(); break; //code to be added
            case 12: sort_list(); break; //code to be added
            case 13: traverse_list(); break;
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
     //printf("%p\n%d\n",start->next,start->data);
     if(ptr==NULL)
     {
         printf("oops!!!  List is empty");
         return;
     }
   while(ptr!=NULL)
   {
      printf("%d\n",ptr->data);
      ptr=ptr->next;
   }
}
void insert_beg() //done
{
    int data;
    struct node *new_node,*ptr;
    printf("enter data for node\n");
    scanf("%d",&data);
    new_node=(struct node*) malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=start;
    start=new_node;
}
void insert_end() //done
{
    int data;
    struct node *new_node,*ptr;
    ptr=start;
    printf("enter data for node\n");
    scanf("%d",&data);
    new_node=(struct node*) malloc(sizeof(struct node));
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=new_node;
    new_node->data=data;
    new_node->next=NULL;
}
void insert_before() //not working
{
    int data,i,count=0;
    struct node *new_node,*ptr,*preptr;
    ptr=start;
    printf("enter data for node and node no before which new node is to be inserted\n");
    scanf("%d%d",&data,&i);
    new_node=(struct node*) malloc(sizeof(struct node));
    while(ptr->next!=NULL && count!=i)
    {
        preptr=ptr;
        ptr=ptr->next;
        count++;
    }
    preptr->next=new_node;
    new_node->data=data;
    new_node->next=ptr;
}
void insert_after() //done
{
    int data,i,a=0;
    struct node *new_node,*ptr,*temp_ptr;
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
    temp_ptr=ptr->next;
    ptr->next=new_node;
    new_node->data=data;
    new_node->next=temp_ptr;
}
void delete_beg() //done
{
    struct node *ptr;
    ptr=start;
    start=ptr->next;
    free(ptr); //deallocate memory
}
void delete_end() //done
{
    struct node *new_node,*ptr,*pre_ptr;
    ptr=start;
    while(ptr->next!=NULL)
    {
       pre_ptr=ptr;
       ptr=ptr->next;
    }
   pre_ptr->next=NULL;
   free(ptr); //deallocate memory
}
{
    int i,a=0;
    struct node *new_node,*ptr,*pre_ptr;
    printf("enter node no after which node is to be deleted\n");
    scanf("%d",&i);
    ptr=start;
    while(ptr->next!=NULL && a!=i+1) //traverse till node to be deleted if it exists
    {
        pre_ptr=ptr;
        ptr=ptr->next;
        a++;
    }
    if(a!=i+1)
    {
        printf("Sorry!!! This is last node ... ");
        return;
    }
    pre_ptr->next=ptr->next;
    ptr->next=pre_ptr;
}
void delete_before() //not sure if its possible
{
    int i,count=0;
    struct node *new_node,*ptr,*preptr;
    ptr=start;
    printf("enter node no before which new node is to be deleted\n");
    scanf("%d",&i);
    while(ptr->next!=NULL && count!=i)
    {
        preptr=ptr;
        ptr=ptr->next;
        count++;
    }

}
void sort_list() //code missing
{

}
void search_list() //code missing
{

}
void delete_list()
{
    struct node *new_node,*ptr,*ptr_temp;
    ptr=start;
    while(ptr->next!=NULL)
    {
       ptr_temp=ptr;
       ptr=ptr->next;
       free(ptr_temp);
    }
    start=NULL;
}
