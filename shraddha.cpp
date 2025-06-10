#include <iostream>
#include <vector>
using namespace std;

void rotation(int arr[], int n, int d)  //arr,5,2       //arr[5]=[1,2,3,4,5]
{
    vector<int> temp(arr, arr + d);     //temp(arr=5,7)

    for (int i = 0; i < n - d; i++)     //i=0 to i<3
        arr[i] = arr[i + d];            // arr[0]=1 ==arr[2]=3........arr[1]=2 ==arr[3]=4......arr[2]=3 ==arr[5]=5...           
                                        //arr[5]={3,4,5,4,5}

                                        //temp={1,2}
    for (int i = 0; i < d; i++)         //i=0 to i<2
        arr[n - d + i] = temp[i];       //arr[5-2-0]=temp[0]-------> arr[5]={3,4,5,1,5} -------> arr[5]={3,4,5,1,2}
}

void display_array(int arr[], int n)
{
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i != n - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main()
{
    int n;
    cout << "Enter the number of elements in the Array: ";
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i + 1 << "th Element: ";
        cin >> arr[i];
    }

    int rot;
    cout << "Enter the number of rotations: ";
    cin >> rot;

    cout << "Original Array:" << endl;
    display_array(arr, n);

    rotation(arr, n, rot % n); 

    cout << "Rotated Array:" << endl;
    display_array(arr, n);

    return 0;
}
