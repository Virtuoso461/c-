#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
typedef struct {
    char no[8];   //8位学号
    char name[20]; //姓名
    int score;     //成绩
}Student;

typedef struct LNode{
     Student data;     //数据域
     struct LNode *next;   //指针域
}LNode,*LinkList;   
void Menu(void)
{
	printf("------单链表------\n");
	printf("1 创建学生信息\n");
	printf("2 显示学生信息\n");
	printf("3 按姓名查询\n");
	printf("4 按位置查找\n");
	printf("5 Insert\n");
	printf("6 Delete\n");
	printf("7 Count\n");
	printf("0 退出\n");
}
LinkList create(LinkList head,LinkList p)
{
	int n;
	LinkList tail;
	head = (LinkList)new LNode;
	head->next=NULL; 

	tail=head;
	printf("Please enter the linklist length you want to:");
	scanf("%d",&n);
	printf("Please enter the linklist data:\n");
	for(int i=0;i<n;i++)
	{
		p=(LinkList)new LNode;
		scanf("%s %s %d",p->data.no,p->data.name,&p->data.score);
		tail->next=p;
		tail=p;
	 } 
	 p=head->next;
	 tail->next=NULL;
	return head,p;
}
void display(LinkList head,LinkList p)
{
	while(p!=NULL)
	{
		printf("%s %s %d\n",p->data.no,p->data.name,p->data.score);
		p = p->next;
	}
	if(p==NULL)
	{
		printf("This isn't data int the linklist\n");
	}
}
void search(LinkList p)
{
	char name[20];
	int flag=0;
	printf("Please enter a name you want to seek:");
	scanf("%s",name);
	while(p!=NULL)
	{
		if(strcmp(name,p->data.name)==0)
		{
			printf("%s %s %d\n",p->data.no,p->data.name,p->data.score);
			flag=1;
		}
		p=p->next;
	}
	if(flag==0)
	{
		printf("This isn't the student\n");
	}
}
void seek(LinkList p)
{
	int i,flag=0,j=0;
	printf("Please enter the line numer you want to seek:");
	scanf("%d",&i);
	
	while(p!=NULL)
	{
		++j;
		if(j==i)
		{
			printf("%s %s %d\n",p->data.no,p->data.name,p->data.score);
			flag=1;
		}
		p=p->next;
	}
	if(flag==0)
	{
		printf("The line number you want to serach exceeds the maxsize");
	}
}
LinkList  insert(LinkList p)
{
	int i,j=0,flag=0;
	LinkList q;
	q=(LinkList)new LNode;
	printf("Please enter the line number you want to insert:");
	scanf("%d",&i);
	printf("Please enter the data you want to insert:");
	scanf("%s %s %d",q->data.no,q->data.name,&q->data.score);
	if(i==1)
	{
		q->next=p;
		p=q;
		flag=1;
	}else
	{
		while(p!=NULL)
		{
			j++;
			if(j==i-1)
			{
				q->next=p->next;
				p->next=q;
				flag=1;
			}
			p=p->next;
		}
		if(flag==0)
		{
			printf("The line number you want to insert exceeds the maxsize");
		}
	}
	return p; 
}
LinkList shanchu(LinkList p)
{
	int i,j=0,flag=0;
	printf("Please enter the line number you want to delete:");
	scanf("%d",&i);
	while(p!=NULL)
	{
		if(flag==1)break;
		if(i==1)
		{
			p=p->next;
			flag=1;
		} 
		++j;
		if(j==i-1)
		{
			p->next=p->next->next;
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("This isn't the line number you want to delete");
	}
	return p;
}
void Statistics(LinkList p)
{
	int i;
	while(p!=NULL)
	{
		++i;
		p=p->next;
	}
	printf("This is %d data in the linklist\n",i);
}
int main()
{
	LinkList head,p;
	LinkList *L;
	int choice,flag=1;
	while(flag==1)
	{
		Menu();
		printf("Please enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				p=create(head,p);
				break;
			case 2:
				display(head,p);
				break;
			case 3:
				search(p);
				break;
			case 4:
				seek(p);
			case 5:
				p=insert(p);
			case 6:
				p=shanchu(p);
			case 7:
				Statistics(p);
		 }
		if(choice==0)flag=0;
		
	}
	 return 0;
}
