#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node * next;
}ListNode;

typedef ListNode * LinkList;

void main(){
	
	LinkList R;
	int n,k;
	LinkList InitRing(int n, LinkList R);
	LinkList DeleteDeath(int n,int k,LinkList R);
	void OutRing(int n,LinkList R);
	printf("The total people is:n The Death total is:k\n");
	scanf("%d %d",&n,&k);
	R=InitRing(n,R);
	R=DeleteDeath(n,k,R);
	OutRing(n,R);
}

/*create Ring*/
LinkList InitRing(int n,LinkList R)
{
	ListNode *p,*q;
	int i;
	R=q=(ListNode *)malloc(sizeof(ListNode));
	for(i=1;i<n;i++){
		p=(ListNode *)malloc(sizeof(ListNode));
		q->data=i;
		q->next=p;
		q=p;
	}
	p->data=n;
	p->next=R;/*make tail to head*/
	R=p;/*R point to the tail*/
	return R;
}

/*chose who should die*/
LinkList DeleteDeath(int n,int k,LinkList R)
{
	printf("who die\n");
	int i,j;
	ListNode *p,*q;
	p=R;/*tail*/
	for(i=1;i<=n/2;i++)
	{
		for(j=1;j<=k-1;j++)
		{
			p=p->next;
		}
		q=p->next;/*q is the person chose to die*/
		p->next=q->next;
		printf("%4d\n",q->data);
		if(i%10==0) printf("\n");
		free(q);
	}
	printf("\n");
	R=p;
	return R;
}

/*who still alive*/
void OutRing(int n,LinkList R)
{
	printf("still alive\n");
	int i;
	ListNode *p;
	p=R;
	for(i=1;i<=n/2;i++,p=p->next)
	{
		printf("%4d\n",p->data);
		if(i%10==0) printf("\n");
	}
	printf("\n");

}