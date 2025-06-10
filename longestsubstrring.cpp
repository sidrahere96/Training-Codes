//Find the length of the longest substring without repeating characters.

#include <iostream>
#include <set>
using namespace std;

class Solution 
{
    public:
    int lengthOfLongestSubstring(string s) 
    {
        int i = 0, j = 0;
        int max_len = 0;
        set<char>substring;
        while(j < s.length())
        {
            if(substring.find(s[j])==substring.end())
            {
                substring.insert(s[j]);
                // cout<<s[j]<<endl;
                max_len = max(max_len,j-i+1);
                j++;
            }
            else
            {
                // cout<<s[i]<<endl;
                substring.erase(s[i]);
                // j++;
                i++;
            }
        }
        return max_len;
    }
};



int main() 
{
    Solution s;
    string str1;
    cout << "Enter a string: ";
    getline(cin,str1);

    cout<<s.lengthOfLongestSubstring(str1);

    return 0;
}