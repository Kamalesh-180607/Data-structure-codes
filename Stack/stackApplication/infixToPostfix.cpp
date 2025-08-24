//INFIX TO POSTFIX AND POSTFIX EVALUATION

#include<iostream>
#include<string>
#include<sstream>
using namespace std;
class Node
{
    public:
    int idata;
    char cdata;
    Node *next;

    Node(int val)
    {
        idata=val;
        next=NULL;
    }
    Node(char val)
    {
        cdata=val;
        next=NULL;
    }
};
Node *head1=NULL;
Node *head2=NULL;
void push_int(int val)
{
    Node *newnode=new Node(val);
    if(!head1)
    {
        head1=newnode;
        return;
    }
    newnode->next=head1;
    head1=newnode;
}
void pop_int()
{
    if(!head1)
    {
        return;
    }
    Node *del=head1;
    head1=head1->next;
    delete del;
}
void push_char(char val)
{
    Node *newnode=new Node(val);
    if(!head2)
    {
        head2=newnode;
        return;
    }
    newnode->next=head2;
    head2=newnode;
}
void pop_char()
{
    if(!head2)
    {
        return;
    }
    Node *del=head2;
    head2=head2->next;
    delete del;
}
int prec(char c)
{
    if(c=='+' || c=='-')
    return 1;
    else if(c=='*'||c=='/'||c=='%')
    return 2;
    else
    return 0;
}
string postfix(string str)
{
    stringstream ss(str);
    string token;
    string result="";
    while(ss>>token)
    {
        if(isdigit(token[0]) || (token.size()>1 && token[0]=='-'))
        {
            result+=token;
            result+=" ";
        }
        else
        {
            if(token=="(")
            {
                push_char(token[0]);
            }
            else if(token==")")
            {
                while(head2 && head2->cdata!='(')
                {
                    result+=head2->cdata;
                    result+=" ";
                    pop_char();
                }
                if(head2->cdata=='(')
                pop_char();
            }
            else
            {
                while(head2 && prec(token[0]) <= prec(head2->cdata))
                {
                    result+=head2->cdata;
                    result+=" ";
                    pop_char();
                }
                push_char(token[0]); 
            }
        }
    }
    while(head2)
    {
        result+=" ";
        result+=head2->cdata;
        pop_char();
    }
    return result;
}
int Evaluation(string str)
{
    stringstream ss(str);
    string token;
    int result;
    while(ss>>token)
    {
        if(isdigit(token[0]) || (token.size()>1 && token[0]=='-'))
        {
            push_int(stoi(token));
        }
        else
        {
            if(token[0]=='+')
            {
                int left=head1->idata;
                pop_int();
                int right=head1->idata;
                pop_int();
                push_int(right+left);
            }
            else if(token[0]=='-')
            {
                int left=head1->idata;
                pop_int();
                int right=head1->idata;
                pop_int();
                push_int(right-left);
            }
            else if(token[0]=='*')
            {
                int left=head1->idata;
                pop_int();
                int right=head1->idata;
                pop_int();
                push_int(right*left);
            }
            else if(token[0]=='/')
            {
                int left=head1->idata;
                pop_int();
                int right=head1->idata;
                pop_int();
                push_int(right/left);
            }
            else if(token[0]=='%')
            {
                int left=head1->idata;
                pop_int();
                int right=head1->idata;
                pop_int();
                push_int(right % left);
            }
        }
    }
    result=head1->idata;
    return result;
}
int main()
{
    string expr="5 + ( 3 * 2 ) - 8 / 4";
    string result=postfix(expr);
    cout<<"The Postfix expression is: "<<result<<endl;   
    cout<<"Solution of the expression is: "<<Evaluation(result)<<endl;
}
