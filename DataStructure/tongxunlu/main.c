/*
main menu
*/

#include <stdio.h>
#include <string.h>
#include "AddressList.h"
#include <stdlib.h>

int menu_select();
LinkList CreateList(void);
void InsertNode(LinkList head,ListNode *p);
ListNode *ListFind(LinkList head);
void DelNode(LinkList head);
void PrintList(LinkList head);

int menu_select(){
	int sn;
	printf("AddressList manage system\n");
	printf("=======================\n");
	printf("1.create\n");
	printf("2.insert\n");
	printf("3.query\n");
	printf("4.deleate\n");
	printf("5.output\n");
	printf("0.quit\n");
	printf("========================\n");
	printf("please select 0-5:\n");
	for( ; ; ){
		scanf("%d",&sn);
		if(sn<0 || sn>5)
		{
			printf("input error!\n");
			printf("please try another:\n");
		}
		else 
			break;
	}
	return sn;
}

void main()
{
	for(;;){
		switch(menu_select()){
		case 1:
		printf("create AddressList LinkedList\n");
		head=CreateList();
		break;

		case 2:
		printf("insert AddressList LinkedList\n");
		p=(ListNode *)malloc(sizeof(ListNode));
		scanf("%s%s%s%s%s",p->data.num,p->data.name,p->data.sex,p->data.phone,p->data.addr);
		InsertNode(head,p);
		break;
		case 3:
		printf("query AddressList LinkedList\n");
		p=ListFind(head);
		if(p!=NULL){
			printf("%s,%s,%s,%s,%s\n",p->data.num,p->data.name,p->data.sex,p->data.phone,p->data.addr);
		}
		else printf("not found this record\n");
		break;

		case 4:
		printf("deleate AddressList LinkedList\n");
		DelNode(head);
		break;

		case 5:
		printf("output AddressList LinkedList\n");
		PrintList(head);
		break;

		case 0:
		printf("goodbye!\n");
		return;

		defalut:
		printf("Input error,try again!\n");
		return;
		}

	}
}

/*create AddressList*/
LinkList CreateList(void)
{
	LinkList head=(ListNode *)malloc(sizeof(ListNode));
	ListNode *p,*rear;
	char flag='y';
	rear=head;/*rear pointer point to head in the first*/
	while(flag=='y'||flag=='Y')
	{
		p=(ListNode *)malloc(sizeof(ListNode));
		printf("num(4) name(8) sec(3) phone(11) address(31)\n");
		scanf("%s %s %s %s %s",p->data.num,p->data.name,p->data.sex,p->data.phone,p->data.addr);
		rear->next=p;
		rear=p;
		flag='0';
		printf("continue to type?(y/n)\n");
		scanf("%s",&flag);
		printf("wardtestdddd\n");
	}
	rear->next=NULL;
	printf("2222\n");
	return head;
}

/*insert AddressList*/
void InsertNode(LinkList Head,ListNode *p)
{
	ListNode *p1,*p2;
	p1=head;
	p2=p1->next;
	while(p2!=NULL && (strcmp(p2->data.num,p->data.num)<0))
	{
		p1=p2;
		p2=p2->next;
	}
	p1->next=p;
	p->next=p2;

}


/*query AddressList*/
ListNode * ListFind(LinkList head)
{
	ListNode *p;
	char num[5];
	char name[9];
	int xz;

	printf("=================\n");
	printf("1.query by num\n");
	printf("2.query by name\n");
	printf("please make a choice:\n");

	p=head->next;
	scanf("%d",&xz);
	if(xz==1){
		printf("please input the num you want to find:\n");
		scanf("%s",num);
		while(p && strcmp(p->data.num,num)<0) p=p->next;
		if(p==NULL || strcmp(p->data.num,num)>0) 
		 p=NULL;/*not found*/
	}
	else if(xz==2)
	{
		printf("please input the name you want to find\n");
		scanf("%s",name);
		while(p&&strcmp(p->data.name,name)!=0) 
			p=p->next;
        if(p==NULL) p=NULL;
	}

	return p;

}


/*deleate AddressList*/
void DelNode(LinkList head)
{
	ListNode *p ,*q;
	p=ListFind(head);
	if(p==NULL){
		printf("No such record\n");
		return;
	}

	q=head;
	while(q && q->next!=p) q=q->next;
	q->next=p->next;
	free(p);
	printf("record has been deleated\n");
}

/*output AddressList*/
void PrintList(LinkList head)
{
	ListNode *p;
	p=head->next;
	printf("num  name sex phone address\n");
	printf("------------------------------\n");
	while(p)
	{
		printf("%s,%s,%s,%s,%s\n",p->data.num,p->data.name,p->data.sex,p->data.phone,p->data.addr);
		printf("---------------------------\n");
		p=p->next;
	}
}