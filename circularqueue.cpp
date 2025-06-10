#include <iostream>
using namespace std;

#define MAX 50

class CQueue
{
    int queue[MAX];
    int front,rear;
    public:
    CQueue()
    {
        front=-1;
        rear=-1;
    }
    bool isfull()
    {
        if((rear+1)%MAX==front)
            return 1;
        else
            return 0;
    }

    bool isempty()
    {
        if(front==-1)
            return 1;
        else 
            return 0;
    }

    void enqueue(int a)
    {
        if(!isfull())
        {
            rear=(rear+1)%MAX;
            queue[rear]=a;
            if(front==-1)
                front=0;
        }
        else 
            cout<<"\nQUEUE OVERFLOW";
            return;
    }

    int dequeue()
    {
        if(!isempty())
        {
            if(front==rear)
                front=rear=-1;
            else
            {
                front=(front+1)%MAX;
            }
        }
        else 
        {
            cout<<"\nQUEUE UNDERFLOW!";
            return 0;
        }
    }

    void display()
    {
        cout<<endl<<"\t\t ";
        for(int i=(front%MAX);i<=(rear%MAX);i++)
        {
            cout<<queue[i];
            if(i!=rear)
                cout<<" <-- ";
        }
    }

    int peek()
    {
        if(!isempty())
            cout<<queue[front];
        else    
            cout<<"\nQUEUE EMPTY!";
    }
};

int main()
{
    CQueue q;
    int a;
    do
    {
        cout<<"\n\nWHAT DO YOU WANT TO DO?";
        cout<<"\n1.ADD ELEMENT\n2.REMOVE ELEMENT\n3.SEE FRONT ELEMENT\n4.DISPLAY QUEUE\n5.EXIT";
        cout<<"\nSELECTION:";
        cin>>a;
        switch(a)
        {
            case 1:
            {
                cout<<"ENTER ELEMENT TO INSERT:";
                int b;
                cin>>b;
                q.enqueue(b);
                break;
            }
            case 2:
            {
                cout<<"PERFORMING DEQUEUE OPERATION:\n\t\t";
                q.dequeue();
                break;
            }

            case 3:
            {
                cout<<"\t\tFRONT ELEMENT:";
                q.peek();
                break;
            }
            case 4:
            {
                cout<<"ELEMENTS IN QUEUE:";
                q.display();
                break;
            }

            case 5:
                cout<<"EXITED";
                break;

            default:
                cout<<"INAVLID CHOICE!";
        }
    }while(a!=5);
    return 0;
}