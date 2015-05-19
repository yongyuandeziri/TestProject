#ifndef _AddressList
#define _AddressList

typedef struct
{
	/* data */
	char num[5];
	char name[9];
	char sex[3];
	char phone[13];
	char addr[31];
}DataType;

typedef struct node
{
	DataType data;
	struct node *next;
}ListNode;

typedef ListNode * LinkList;
LinkList head;
ListNode *p;

#endif