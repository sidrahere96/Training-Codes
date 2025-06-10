//TWO SUMS
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int>result(2);
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    result[0]=i;
                    result[1]=j;
                    return result;
                }                       
            } 
        }
    return {};
    }
};

void display(vector<int>a,int n)
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
   Solution s;
   int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int>a(n);

    for(int i=0;i<n;i++)
    {
        cout<<"ENTER ELEMENT AT "<<i+1<<" POSITON:";
        cin>>a[i];
    }

    cout<<"ORIGINAL ARRAY:\n\t";
    display(a,n);

    cout<<"\nENTER TARGET VALUE:";
    int t;
    cin>>t;
    vector<int>result =s.twoSum(a,t);
    cout<<"["<<result[0]<<" ";
    cout<<result[1]<<"]";
    return 0;
}