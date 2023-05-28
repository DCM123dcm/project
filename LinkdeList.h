#ifndef __LINKED_LIST__
#define __LINKED_LIST__
#include<stdlib.h>

/*-----------------头文件--------------------*/
typedef int ElemType;//数据元素类型

typedef struct node
{
    ElemType data;
    struct node *next;
}Node;

//创建双向循环的结点
typedef struct binode
{
    ElemType data;
    struct binode* next;
    struct binode* prev;
}biNode;

//创建带头文件的双向链表
typedef struct bilist
{
    biNode *first;//first的前一个就是last
    //...
}biList;

//创建一个带头结点的循环双向链表(空链表)
biList* create_doubleCircleList(void)
{
    biList *l = malloc(sizeof(*l));

    l->first = NULL;

    return l;
}
/*-------------------创建链表----------------------*/


typedef struct creat_linkedlist_v0
{
    biNode* first;
    biNode* last;
}linkedlist_v0;

typedef struct creat_linkedlist_v2
{
    Node* first;
    Node* last;
}linkedlist;
/**
 * @brief 创建有头结点的链表
 * 
 */
linkedlist* creat_linkedlist_v(void)
{
    linkedlist *l =malloc(sizeof(*l));
    l->first=NULL;
    l->last=NULL;
    return l;
}


/*
    creat_linkedlist：创建单链表
                随用户输入的数据建立链表，输入到数字“0”结束
    @：无参数
    返回值：
        返回链表的首地址
*/
Node* creat_linkedlist()
{
    ElemType a;
    Node* first = NULL;
    Node* last = NULL;
    Node* p=NULL;
    while(1)
    {
        scanf("%d",&a);
        if(a == 0)
        {
            break;
        }
        p = malloc(sizeof(*p));
        p->data = a;
        p->next = NULL;

        if(first == NULL)
        {
            first = p;
            last = p;
        }
        else
        {
            last->next = p;
            last = p;
        }   
    }
    return first;
}


/**
 * @brief 创建双向不循环链表
 * 
 */
biNode* creat_linkedlist_v2()
{
    int a;
    printf("请输入所要创建的双向不循环链表：\n");
    biList* l=create_doubleCircleList();
    biNode* pr;
    while(1)
    {
        scanf("%d",&a);
        biNode* p=malloc(sizeof(*p));
        if(l->first==NULL)
        {
            l->first=p;
            pr=p;
            p->data=a;
            p->next=NULL;
            p->prev=pr;
        }
        else
        {
            if(a==0)
            {
                break;
            }
            else
            {
                p->data=a;
                p->next=NULL;
                p->prev=pr;
                pr->next=p;
                pr=pr->next;
            }
        }
    }
    return l->first;
}
    
/**
 * @brief 建立无序循环链表
 * 
 */
biNode* creat_linkedlist_v3()
{
    ElemType a;
    biList* l=create_doubleCircleList();
    biNode* last;
    while(1)
    {
        scanf("%d",&a);
        biNode* p=malloc(sizeof(*p));
        if(l->first==NULL)
        {
            p->data=a;
            l->first=p;
            last=p;
            last->next=p;
            last->prev=p;
            
        }
        else
        {
            if(a==0)
            {
                break;
            }
            p->data=a;
            p->next=l->first;
            p->prev=last;
            last->next=p;
            last=p;
            l->first->prev=last;
        }   
    }
    return l->first;
}
/*-------------------链表功能----------------------*/

/**
 * @brief 删除双向链表中值为x的结点
 * 
 */
biNode* delete_liank(biNode* h,ElemType x)
{
    biNode* pr=NULL;
    while(h->data==x)
    {
        h=h->next;
    }
    pr=h->next;
    while(1)
    {
        biNode* first=pr;
        if(pr->next==NULL)
        {
            if(pr->data==x)
            {
                pr->prev->next=NULL;
                pr->prev=NULL;
                free(first);
                break;
            }
            else
            {
                break;
            }    
        }
        else
        {
            if(pr->data==x)
            {
                pr->prev->next=pr->next;
                pr->next->prev=pr->prev;
                pr->prev=NULL; 
                pr=pr->next;
                first->next=NULL;
                free(first);
            }
            else
            {
                pr=pr->next;
            }
            
        }   
    }
    
    return h;
}


//负数在前，正数在后
void fushu(biNode* l)
{
   biNode* p=l;
   while(p)
   {
        if(p->data<0)
        {
            printf("%d ",p->data);
        }
        p=p->next;
   } 
   p=l;
   while(p)
   {
        if(p->data>0)
        {
            printf("%d ",p->data);
        }
        p=p->next;
   }
   printf("\n");
}

/**
 * @brief 删除双向链表中的全部结点
 * 
 */
void delete_liank_all(biNode* h)
{
    while(1)
    {
        biNode* pr=h;
        h=h->next;
        if(h==NULL)
        {
            pr->prev=NULL;
            free(pr);
            break;
        }
        else
        {
            pr->next=NULL;
            h->prev=NULL;
            free(pr);
        }    
    }
}


/**
 * @brief 删除循环链表中的某个结点（删除全部！）
 * 
 */
biNode* delete_x3(biNode* p,ElemType x)
{
    biNode* h=p;
    biNode* pr;
    if(h->data==x)//找到第一个不等于x的值
    {
        h=h->next;
    }
    pr=h;
    while(1)
    {
        pr=pr->next;
        if(pr==p)
        {
            return h;
        }
        else
        {
            if(pr->data==x)
            {
                pr->prev->next=pr->next;
                pr->next->prev=pr->prev;
                pr->prev=NULL;
            }
        }  
    }
}

/*-------------------打印链表----------------------*/

/**
 * print_list：打印带头结点的链表
 * @l:链表首地址
 */
 //顺置打印
void print_list(linkedlist *l)
{
    Node* p=l->first;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

//逆置打印
void printf_list_prev(linkedlist_v0* l)
{
    biNode* p=l->last;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->prev;
    }
    printf("\n");
}





#endif