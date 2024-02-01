#include<stdio.h>
#include<conio.h>
#include<alloc.h>

typedef struct singlylist{
    int data;
    struct singlylist *next;
}node;

void creat(node *head){
	node *l;
	int n,i;
	l=head;
	printf("\nHow many node create:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("\n\nEnter value==>");
		scanf("%d",&l->data);

		l->next=(node*)malloc(sizeof(node));
		l=l->next;
	}
	l->next=NULL;
}

void display(node *head){
	node *p;
	p=head;
	while(p->next!=NULL){
		printf(" %d -->",p->data);
		p=p->next;
	}

}
void count(node *head){
	node *p;
	int cnt=0;
	p=head;
	while(p->next !=NULL){
		cnt++;
		p=p->next;
	}

	printf("\n\n total no of node:%d",cnt);

}
int search(node*head,int key)
{
	node *p;
	int flag=0;
	p=head;
	while (p->next !=NULL)
	{
		if(key==p->data)
		{
			flag=1;
			break;
		}
		else
		{
			flag=0;
		}
		p=p->next;
	}
	return flag;

}
mode*
void main()
{
	int choice,key,flag;
	node *head;
	clrscr();
	head=(node*)malloc(sizeof(node));
	do{
	printf("\n\n\t1. create");
	printf("\n\t2. display");
	printf("\n\t3. count");
	printf("\n\t4. search");
	printf("\n\t0. exit");
	printf("\n\t\n enter your choice");
	scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				creat(head);
				break;

			case 2:
				display(head);
				break;

			case 3:
				count(head);
				break;

			case 4:
				printf("\n\n Enter key==>");
				scanf("%d",&key);
				flag=search(head,key);
				if(flag)
				{
					printf("\n\n %d found",key);
				}
				else
				{
					printf("\n\n %d not found",key);
				}
				break;

			case 0:
				exit(0);
				break;
			default:
				printf("\n enter valide choice");
				break;
		}
	}while(choice!=0);
	getch();
}