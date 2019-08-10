#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void create(struct node **head,int data){
	struct node *new_node=(struct node *)malloc(sizeof(struct node ));
	new_node->data=data;
	new_node->next=*head;
	*head=new_node;
}

void print(struct node *h){
	while(h){
		printf("->%d",h->data);
		h=h->next;
	}
}

void delete(struct node **h){
	struct node *temp;
	//deleting a node at the head of ll
	temp=*h;
	*h=(*h)->next;
	free(temp);
};


void delete_in__middle(struct node *m){
	struct node *temp=m->next;
	m->next=temp->next;
	free(temp);
}

void reverse(struct node **h){
	struct node *p,*q,*r;
	p=q=r=*h;
	p=p->next->next;
	q=q->next;
	r->next=NULL;
	q->next=r;
	while(p!=NULL){
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	*h=q;
}

void sorting(struct node *head){
	//struct node *temp;
	struct node *i,*j;
	for(i=head;i->next!=NULL;i=i->next){
		for(j=i->next;j!=NULL;j=j->next){
			if(i->data > j->data){
				int temp=i->data;
				i->data=j->data;
				j->data=temp;

			}
		}
	}
}

void sorting_again(struct node *h){
	struct node *sptr,*lptr;
	//sptr=h;
	lptr=NULL;
	int flag;
	do{
		flag=0;
		sptr=h;
		while(sptr->next!=lptr){
			if(sptr->data < sptr->next->data){
				flag=1;
				int temp=sptr->data;
				sptr->data=sptr->next->data;
				sptr->next->data=temp;
			}
			sptr=sptr->next;	
		}	
		lptr=sptr;
			//while(flag);
	}
	while(flag);
}


// 1--2--3--4--5--6--7
// 2--1--4--3

void pair_wise_swap(struct node **h){
	struct node *temp,*a,*b;
	a=*h;
	b=NULL;
	while(a!=NULL && a->next!=NULL){
		temp=a->next; //temp=2
		a->next=temp->next;//1->next=2->next
		temp->next=a;//2->next=1
		if(b==NULL)
			*h=temp;//new_head=2
		else 
			b->next=temp;
		b=a;//b=1
		a=a->next;//1=3
	}
}

//>444->151->140->111->101->90->61->51->21->12->8->7->3->1printing after pairwisw swap
//->444->111->61->12->3->7	
	       	
void swap(struct node *a,struct node *b){
	int temp=a->data;
	a->data=b->data;
	b->data=temp;
}

struct node* middle(struct node *h){
	struct node *p,*q;
	p=q=h;
	while(p!=NULL && p->next!=NULL){
		p=p->next->next;
		q=q->next;
	}
	return q;
}
		
void main(){
	struct node *head=NULL;
	create(&head,1);
	create(&head,21);
	create(&head,3);
	create(&head,444);
	create(&head,51);
	create(&head,61);
	create(&head,7);
	create(&head,8);
	create(&head,90);
	create(&head,101);
	create(&head,111);
	create(&head,12);
	create(&head,103);
	create(&head,140);
	create(&head,151);
	create(&head,169);

	print(head);

	printf("\n");
	delete(&head);
	print(head);
	printf("\n");
	delete_in__middle((head->next));
	printf("\n");
	print(head);
	reverse(&head);
	printf("printing after reverse\n");
	print(head);
	printf("printing after the sorting\n");
	sorting(head);
	print(head);
	sorting_again(head);
	printf("sorting again in another method\n");
	print(head);
	pair_wise_swap(&head);
	printf("printing after pairwisw swap\n");
	print(head);
	
	struct node *mn=middle(head);
	printf("\n%d",mn->data);


}



