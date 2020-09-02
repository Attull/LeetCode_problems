/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
*/

//Method 1- take O(n^3)

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int are_distinct(string str,int i,int j)
{
    vector<bool> visited(26);
    for(int k=i;k<j;++k)
    {
        if(visited[str[k]-'a']==true)      //if character is already present then return false
            return false;

        visited[str[k]-'a']=true;         //for each unique character we set it true
    }
    return true;
}

int long_unique_substring(string str,int n)
{
    int res=0;
    for(int i=0;i<n;++i)
        for(int j=i;j<n;++j)
            if(are_distinct(str,i,j))           //we check for each possible substring possible
                res=max(res,j-i+1);

    return res;
}
int main()
{
    string s="atuabc";
    int n=s.length();
    cout<<long_unique_substring(s,n);
    return 0;
}
