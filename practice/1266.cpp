#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        string s;
        cin>>s;
        bool is_10=false;
        ll is_2=0;
        ll is_3=0;
        for(ll j=0;j<s.length();j++)
        {
            ll temp=s[j]-'0';
            if(temp==0)
            is_10=true;
            if(temp%2==0)
            is_2++;
            is_3=temp+is_3;
        }
        if(is_2>=2 && is_10 && is_3%3==0)
        cout<<"red"<<endl;
        else
        cout<<"cyan"<<endl;
    }
}