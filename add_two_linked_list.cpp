/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order
and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
*/

#include <iostream>
using namespace std;

class node
{
    public:
            int val;
            node *next;

            //constructor
            node(int data)
            {
                val=data;
                next=NULL;
            }

};

void InsertAtBeg(node *&head,int data)      //passing a pointer variable by reference
{
    node *n=new node(data);
    n->next=head;
    head=n;
}

node *addTwoNumbers(node* l1, node* l2)
    {
        node *res=new node(-1);             //res just point to starting of our list which we pass at the end
        node *temp=res;                     //it is used to insert all values of required sum in linked list

        int carry=0;
        while(l1 || l2)
        {
            int a;
            if(l1)
                a=l1->val;
            else
                a=0;

            int b=l2 ? l2->val:0;

            int sum=a+b+carry;
            carry=sum/10;

            temp->next=new node(sum%10);
            temp=temp->next;

            if(l1)                         //if l1 is not empty
                l1=l1->next;

            if(l2)                         //if l2 is not empty
                l2=l2->next;

        }

        if(carry)                          //if still there is value in carry ,so passed it in linked list
            temp->next=new node(carry);

        return res;
}

void printNode(node *head)
{
    while(head!=NULL)
    {
        cout<<head->val<<"->";
        head=head->next;
    }
    cout<<endl;
}

void BuildList(node *&head)          //take input until we enter -1
{
    int data;
    cin>>data;
    while(data!=-1)
    {
        InsertAtBeg(head,data);
        cin>>data;
    }
}

int main()
{
    node *head1=NULL;
    node *head2=NULL;
    BuildList(head1);
    BuildList(head2);
    node *head=addTwoNumbers(head1,head2);
    printNode(head);

    return 0;
}
