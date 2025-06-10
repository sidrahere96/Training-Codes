//CIRCULAR LINKED LIST

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;

	Node(int a)
	{
		data=a;
		next=NULL;
	}
};

class cll
{
	Node* head;

public:
	cll()
	{
		head=NULL;
	}

	void inserth(int a)
	{
        Node* newnode=new Node(a);
        if(head==NULL)
		{
            head=newnode;
            newnode->next=head;
            return;
	    }
        Node *temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
        newnode->next=head;
		temp->next=newnode;
        head=newnode;
    }

	void insertt(int b)
	{
		Node* newnode=new Node(b);
        if(head==NULL)
		{
            head=newnode;
            newnode->next=head;
            return;
	    }
        Node *temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next=newnode;
        newnode->next=head;
	}

	void deleteh()
	{
		if(head==NULL)  return;
        if(head->next==head)
        {
            delete head;
            head=NULL;
            return;
        }

        Node* temp=head;
        while(temp->next!=head)
        {
        temp=temp->next;        
        }
        Node* todelete=head;
        head=head->next;
        temp->next=head;            
        delete todelete;

        display();
	}

	void deletet()
	{
		if (head == NULL)	return;
		if (head->next == head)
		{
			delete head;
			head = NULL;
			return;
            
			display();
		}

		Node* temp = head;
		while (temp->next->next != head)
		{
			temp = temp->next;
		}
        Node* todelete=temp->next;
        temp->next = head;
		delete todelete;

		display();
	}

	void deleteany(int value)
	{
		if(head==NULL)  return;
		if(head->data==value)
		{
			Node* temp=head;
			head=head->next;
			delete temp;
			return ;
		}

		Node* temp=head;
		while(temp->next!=head && temp->next->data!=value)
		{
			temp=temp->next;
		}

		if(temp->next==NULL) return;
		Node* todelete=temp->next;
		temp->next=temp->next->next;
		delete todelete;

		// display();
	}

	void display()
	{
        if(head==NULL)  return;
		Node* temp = head;
		do
		{
			cout << temp->data ;
			if(temp->next!=head)
			    cout<< " -> ";
			if(temp->next==head)
			    cout<<"->head";
			temp = temp->next;
		}while (temp != head);
		cout<<endl;
	}

};


int main()
{
	cll c;
	int a;
	do
	{
		cout<<"\n\nWHAT DO YOU WANT TO DO?";
		cout<<"\n1.ADD ELEMENT AT HEAD\n2.ADD ELEMENT AT TAIL\n3.REMOVE ELEMENT FROM HEAD\n4.REMOVE ELEMENT AT TAIL\n5.REMOVE ANY ELEMENT\n6.TRAVERSE CLL\n7.EXIT";
		cout<<"\nSELECTION:";
		cin>>a;
		switch(a)
		{
		case 1:
		{
			cout<<"ENTER ELEMENT TO INSERT:";
			int b;
			cin>>b;
			c.inserth(b);
			break;
		}

		case 2:
		{
			cout<<"ENTER ELEMENT TO INSERT:";
			int b;
			cin>>b;
			c.insertt(b);
			break;
		}

		case 3:
		{
			cout<<"PERFORMING DELETE OPERATION:\n\t\t";
			c.deleteh();
			break;
		}

		case 4:
		{
			cout<<"PERFORMING DELETE OPERATION:\n\t\t";
			c.deletet();
			break;
		}

		case 5:
		{

			cout<<"ENTER ELEMENT TO DELETE:\n\t\t";
			int b;
			cin>>b;
			c.deleteany(b);
			break;
		}

		case 6:
		{
			cout<<"ELEMENTS IN CLL:";
			c.display();
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
