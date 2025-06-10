// STACK
#include <iostream>
using namespace std;

class stack
{
    public:
    int Stack[100];
    int top=-1;

    void push(int ele)
    {
        if(!isfull())
        {
            top++;
            Stack[top]=ele;
        }
        else
            cout<<"\nSTACK OVERFLOW";
    }   

    void pop()
    {
        if(!isempty())
        {
            top--;
            cout<<"\nELEMENTS AFTER POP OPERATION:\n";
            display();
        }
        else
            cout<<"\nSTACK UNDERFLOW!";
    }

    void peek()
    {
        cout<<"\t"<<Stack[top]<<"\n";
    }

    bool isempty()
    {
        if (top==-1)
            return 1;
        else 
            return 0;
    }

    bool isfull()
    {
        if(top==(100-1))
            return 1;
        else 
            return 0;
    }

    void display()
    {
        for(int i=0;i<=top;i++)
        {
            cout<<"\n\t\t "<<Stack[i]<<"\n\t\t____";
        }
    }
};

int main()
{
    stack s;
    int a;
    do
    {
        cout<<"\n\nWHAT DO YOU WANT TO DO?";
        cout<<"\n1.ADD ELEMENT\n2.REMOVE ELEMENT\n3.SEE INSERTED ELEMENT\n4.DISPLAY STACK\n5.EXIT";
        cout<<"\nSELECTION:";
        cin>>a;
        switch(a)
        {
            case 1:
            {
                cout<<"ENTER ELEMENT TO INSERT:";
                int b;
                cin>>b;
                s.push(b);
                break;
            }
            case 2:
            {
                cout<<"PERFORMING POP OPERATION:\n\t\t";
                s.pop();
                break;
            }

            case 3:
            {
                cout<<"LAST INSERTED ELEMENT:";
                s.peek();
                break;
            }
            case 4:
            {
                cout<<"ELEMENTS IN STACK:";
                s.display();
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