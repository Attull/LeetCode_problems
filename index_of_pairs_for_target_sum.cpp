/*
Given an array of integers nums and and integer target, return the indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> res;
        int size=nums.size();

        for(int i=0;i<size;++i)
        {
            for(int j=i+1;j<size;++j)
            {
                if(nums[i]+nums[j]==target)             //when we get the required answer then store its index in vector
                {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution a;                         //declare class object

    vector <int> v{3,2,4};

    vector<int> temp;                   //to store return vector value
    temp=a.twoSum(v,6);                 //call twoSum function using object of class

    for(int i=0;i<temp.size();++i)        //for display
   {
       cout<<temp[i]<<",";
   }
    return 0;
}
