#include<bits/stdc++.h>
using namespace std;

vector<int>func(string s)
{
    // cout<<s<<"<---"<<endl;
    int flg=0;
    for(auto it:s)
    {
        if(it=='+' || it=='-' || it=='*')
        {
            flg=1;
            break;
        }
    }
    if(flg==0)
    {
        int num=0;
        for(int i=0;i<s.length();i++)
        {
            num+=((int)(s[i]-'0'))*((int)(pow(10,s.length()-i-1)));
        }
        vector<int>result;
        result.push_back(num);
        // cout<<s[0]-'0'<<endl;
        return result;
    }
    vector<int>result;
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        if(s[i]=='+' || s[i]=='-' || s[i]=='*')
        {
            vector<int>v1=func(s.substr(0,i));
            vector<int>v2=func(s.substr(i+1,n-i-1));
            for(auto it1:v1)
            {
                for(auto it2:v2)
                {
                    if(s[i]=='+')
                    result.push_back(it1+it2);
                    else if(s[i]=='-')
                    result.push_back(it1-it2);
                    else 
                    result.push_back(it1*it2);
                }
            }
        }
    }
    return result;
}

int main()
{
    string s;
    cin>>s;
    vector<int>result=func(s);
    sort(result.begin(),result.end());
    for(auto it:result)
    cout<<it<<" ";
}