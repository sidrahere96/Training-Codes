//Rotating an Array

#include <iostream>
#include <vector>
using namespace std;

void reverse(int i,int j,int a[])
{
    while(i<j)
    {
        swap(a[i],a[j]);
        i++;
        j--;
    }
}

void leftshift(int a[], int r, int n)  
{
    reverse(0,n-1,a);
    reverse(0,n-1-r,a);
    reverse(n-1-r+1,n-1,a);
}

void display(int a[],int n)
{
    cout<<"{";
    for(int i=0;i<n;i++)
    {
        cout<<a[i];
        if(i<n-1)
            cout<<",";
    }
    cout<<"}";
}

int main() 
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int a[n];

    for(int i=0;i<n;i++)
    {
        cout<<"ENTER ELEMENT AT "<<i+1<<" POSITON:";
        cin>>a[i];
    }

    cout<<"ORIGINAL ARRAY:\n\t";
    display(a,n);

    cout<<"\nENTER THE NUMBER TO ROTATE:";
    int r;
    cin>>r;
    
    leftshift(a,r,n);

    cout<<"ROTATED ARRAY:\n\t";
    display(a,n);

    return 0;
}