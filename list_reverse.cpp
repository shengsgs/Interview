#include <iostream>
#define Max 100
using namespace std;


struct Node{
	Node *next;
	int key;
	Node(){key = 0;next = NULL;}
};

Node* AddList(Node* head, int data)
{
	Node* p =(Node *)malloc(sizeof(Node)); 
	Node* temp = NULL;
	if(p == NULL)
		return NULL;
	else
	{
		p->key = data;
		p->next = NULL;
		if(head == NULL)
		{
			head = p;
			return p;
		}
		else 
		{
			temp = head;
			while(temp->next!= NULL)
			{
				temp = temp->next;
			}
			temp->next = p;
		}
		//free(p);
		//free(temp);
		return head;
	}

}

void DisplayList(Node* temp)
{
	cout<<"Show the List:"<<endl;
	while(temp!= NULL)
	{
		cout<<temp->key<<"->\t";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}

Node *CreateList(Node *head)
{
	head=NULL;
	for(int i = 0; i < 8; i++)
		head = AddList(head,rand()%Max);
	return head;
}

Node* reverseList(Node* head)
{
	if(head == NULL || head->next == NULL) return NULL;
	Node* p = head;
	Node* q = head->next;
	Node* r = NULL;
	
	head->next = NULL;
	while(q)
	{
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	head = p;
	return head;
}

Node * reverseListByRecursive(Node * head)
{
	if(head == NULL|| head->next == NULL) return head;
	Node *p = reverseListByRecuisive(head->next);

	head->next->next = head;
	head ->next = NULL;
	return p;
}

int main()
{
	Node *Head;

	cout<<"Createa List"<<endl;
	Head = CreateList(Head);
	DisplayList(Head);

	cout<<"After the reverse （Non recursive）"<<endl;
	Head = reverseList(Head);
	DisplayList(Head);

	cout<<"After twice reverse （ recursive）"<<endl;
	Head = reverseListByRecursive(Head);
	DisplayList(Head);

	return 0;
}
