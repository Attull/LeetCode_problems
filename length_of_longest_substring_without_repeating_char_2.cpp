/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
*/

//Method 1- take O(n^2)

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int longest_unique_substring(string str,int n)
{
    int res=0;

    for(int i=0;i<n;++i)
     {
        vector<bool> visited(26);
        for(int j=i;j<n;++j)
        {
            if(visited[str[j]-'a']==true)
                break;
            else
            {
                res=max(res,j-i+1);
                visited[str[j]-'a']=true;
            }
        }
         visited[str[i]-'a']=false;                      //remove first character from previous window
     }
    return res;
}


int main()
{
    string s="atulatu";
    int n=s.length();
    cout<<longest_unique_substring(s,n);
    return 0;
}
