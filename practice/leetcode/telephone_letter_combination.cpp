#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<string> find(string s)
{
    vector<string> v,v2;
    if(s.length()>1)
    v=find(s.substr(1));
    else 
    v.push_back("");
    vector<char>tmp2;
    if(s[0]=='2')
    {
        tmp2.push_back('a');
        tmp2.push_back('b');
        tmp2.push_back('c');
    }

    else if(s[0]=='3')
    {
        tmp2.push_back('d');
        tmp2.push_back('e');
        tmp2.push_back('f');
    }

    else if(s[0]=='4')
    {
        tmp2.push_back('g');
        tmp2.push_back('h');
        tmp2.push_back('i');
    }

    else if(s[0]=='5')
    {
        tmp2.push_back('j');
        tmp2.push_back('k');
        tmp2.push_back('l');
    }

    else if(s[0]=='6')
    {
        tmp2.push_back('m');
        tmp2.push_back('n');
        tmp2.push_back('o');
    }

    else if(s[0]=='7')
    {
        tmp2.push_back('p');
        tmp2.push_back('q');
        tmp2.push_back('r');
        tmp2.push_back('s');
    }

    else if(s[0]=='8')
    {
        tmp2.push_back('t');
        tmp2.push_back('u');
        tmp2.push_back('v');
    }

    else if(s[0]=='9')
    {
        tmp2.push_back('w');
        tmp2.push_back('x');
        tmp2.push_back('y');
        tmp2.push_back('z');   
    }
    
    
    for(ll i=0;i<v.size();i++)
    {
        for(int j=0;j<tmp2.size();j++)
        {
            string str="";
            str+=tmp2[j];
            str+=v[i];
            v2.push_back(str);
        }   
    }
    return v2;

}

int main()
{
    string s;
    cin>>s;
    vector<string> v2=find(s);
    for(ll i=0;i<v2.size();i++)
    cout<<v2[i]<<" ";
    cout<<endl;
}