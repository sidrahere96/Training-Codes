//DOUBLY LINKED LIST

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* prev;
    Node* next;

	Node(int a)
	{
		data=a;
		prev,next=NULL;
	}
};

class dll
{
	Node* head;

public:
	dll()
	{
		head=NULL;
	}

	void inserth(int a)
	{
        Node* newnode=new Node(a);
        if(head!=NULL)
		{
            head->prev=newnode;
            newnode->next=head;
	    }
        head=newnode;
    }

	void insertt(int b)
	{
		Node* newnode=new Node(b);
        if(head==NULL)
		{
            head=newnode;
            return;
	    }
        Node *temp=head;
		while(temp->next)
		{
			temp=temp->next;
		}
		temp->next=newnode;
        newnode->prev=temp;
	}

	void deleteh()
	{
		if(head==NULL)  return;
        
        Node* temp=head;
		head=head->next;
		if(head)
			head->prev=NULL;
		delete temp;

        display();
	}

	void deletet()
	{
		if (head == NULL)	return;
		
		Node* temp = head;
		while (temp->next)
		{
			temp = temp->next;
		}
        if(temp->prev)
			temp->prev->next=NULL;
		else
			head=NULL;
		delete temp;

		display();
	}

	void deleteany(int value)
	{
		if (head == NULL)
			return;
		Node* temp = head;
		while (temp->next->data != value)
		{
			temp = temp->next;
		}
		Node* todelete=temp->next->next;
		temp->next=temp->next->next;
		temp->next->prev=temp->prev->prev;
		delete todelete;

		display();
	}

	void display()
	{
        if(head==NULL)  return;
		Node* temp = head;
		do
		{
			cout << temp->data ;
			if(temp->next!=NULL)
			    cout<< " <--> ";
			temp = temp->next;
		}while (temp != NULL);
		cout<<endl;
	}

};


int main()
{
	dll d;
	int a;
	do
	{
		cout<<"\n\nWHAT DO YOU WANT TO DO?";
		cout<<"\n1.ADD ELEMENT AT HEAD\n2.ADD ELEMENT AT TAIL\n3.REMOVE ELEMENT FROM HEAD\n4.REMOVE ELEMENT AT TAIL\n5.REMOVE ANY ELEMENT\n6.TRAVERSE DLL\n7.EXIT";
		cout<<"\nSELECTION:";
		cin>>a;
		switch(a)
		{
		case 1:
		{
			cout<<"ENTER ELEMENT TO INSERT:";
			int b;
			cin>>b;
			d.inserth(b);
			break;
		}

		case 2:
		{
			cout<<"ENTER ELEMENT TO INSERT:";
			int b;
			cin>>b;
			d.insertt(b);
			break;
		}

		case 3:
		{
			cout<<"PERFORMING DELETE OPERATION:\n\t\t";
			d.deleteh();
			break;
		}

		case 4:
		{
			cout<<"PERFORMING DELETE OPERATION:\n\t\t";
			d.deletet();
			break;
		}

		case 5:
		{

			cout<<"ENTER ELEMENT TO DELETE:\n\t\t";
			int b;
			cin>>b;
			d.deleteany(b);
			break;
		}

		case 6:
		{
			cout<<"ELEMENTS IN CLL:";
			d.display();
			break;
		}

		case 7:
			cout<<"EXITED";
			break;

		default:
			cout<<"INAVLID CHOICE!";
		}
	} while(a!=7);
	return 0;
}
