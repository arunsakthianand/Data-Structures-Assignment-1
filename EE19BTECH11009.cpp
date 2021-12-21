#include <bits/stdc++.h>

using namespace std;

double d[500];
int iffirst=0,current=0;

void push(double a)
{
    if(current == 0 && iffirst == 0)
    {
        d[current] = a;
        iffirst = 1;
    }
    else
    {
        current++;
        d[current] = a;
    }
}

void pop()
{
    if(current == 0)
    {
        d[current] = 0;
        iffirst = 0;
    }
    else
    {
        d[current] = 0;
        current--;
    }
}

int main()
{
    
    string s;
    getline(cin, s);
    int size = (s.length());
    int i = 0;
    double value=0;
    
    for(int c=0;c++;c<500)
    {
        d[c] = 0;
    }
    
    while(i<size)
    {
        if (s[i]=='+')
        {
            value=0;
            if(current<1)
            {
                cout<<"Invalid Expression";
                break;
            }
            else
            {
                double temp1 = d[current-1]+d[current];
                pop();
                pop();
                push(temp1);
            }
            i++;
        }
        else if (s[i]=='-')
        {
            if (s[i+1]==',')
            {
                value=0;
                if(current<1)
                {
                    cout<<"Invalid Expression";
                    break;
                }
                else
                {
                    double temp1 = d[current-1]-d[current];
                    pop();
                    pop();
                    push(temp1);
                }
                i++;
            }
            else
            {
                string temp;
                int j=0;
                while(s[i] != ',' && i<size)
                {
                    temp += s[i];
                    j++;
                    i++;
                }
                
                if (j!=0)
                {
                    value = stod(temp);
                    push(value);
                    value = 0;
                    j=0;
                }
            }
        }
        else if (s[i]=='*')
        {
            value=0;
            if(current<1)
            {
                cout<<"Invalid Expression";
                break;
            }
            else
            {
                double temp1 = d[current-1]*d[current];
                pop();
                pop();
                push(temp1);
            }
            i++;
        }
        else if (s[i]=='/')
        {
            value=0;
            if(current<1)
            {
                cout<<"Error/no";
                break;
            }
            else
            {
                double temp1 = d[current-1]/d[current];
                pop();
                pop();
                push(temp1);
            }
            i++;
        }
        else
        {
            string temp;
            int j=0;
            while(s[i] != ',' && i<size)
            {
                temp += s[i];
                j++;
                i++;
            }
            if (j!=0)
            {
                value = stod(temp);
                push(value);
                value = 0;
                j=0;
            }
        }
        i++;
    }
    if(current == 0)
    {
        cout<<d[current];
    }
    else
    {
        cout<<"Invalid Expression";
    }
    return 0;
}
