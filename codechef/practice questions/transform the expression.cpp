#include<iostream>
#include<iostream>
#include<string.h>
#include<ctype.h>
#include<stack>
using namespace std;

void update_stack(stack<char>*s,char c)
{
    if(c==')')
    {
        while(s->top()!='(')
        {
            cout<<s->top();
            s->pop();
        }
        s->pop();
    }
    else if(c=='(')
     s->push(c);

    else
    {
        if(c=='+' or c=='-')
        {
             while(s->top()!='(')
        {
            cout<<s->top();
            s->pop();
        }
        s->push(c);
        }
        else if(c=='^')
            s->push(c);
        else
        {
            while(s->top()!='+' and s->top()!='-' and s->top()!='(')
        {
            cout<<s->top();
            s->pop();
        }

        s->push(c);

        }


    }

}

void process(char*str)
{
    stack<char> chr_stack;
    for(int i=0;str[i]!='\0';i++)
    {
        if(isalpha(str[i]))
            cout<<str[i];
        else
            update_stack(&chr_stack,str[i]);
    }
}

int main()
{
 int no_cases;
 cin>>no_cases;
 for(int i=0;i<no_cases;i++)
 {
    char* str=new char[400];
    cin>>str;
    process(str);
    cout<<endl;
    delete str;

 }




}

