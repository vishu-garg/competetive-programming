#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    string a[5],b[5],c[5],d[5],e[5];
    a[0]="***";
    b[0]="***";
    c[0]="***";
    d[0]="***";
    e[0]="***";
    a[1]="*.*";
    b[1]="*.*";
    c[1]="*..";
    d[1]="*.*";
    e[1]="*..";
    a[2]="***";
    b[2]="***";
    c[2]="*..";
    d[2]="*.*";
    e[2]="***";
    a[3]="*.*";
    b[3]="*.*";
    c[3]="*..";
    d[3]="*.*";
    e[3]="*..";
    a[4]="*.*";
    b[4]="***";
    c[4]="***";
    d[4]="***";
    e[4]="***";
    ll cnt=0;
    while(cnt!=5)
    {
    for(ll i=0;i<n;i++)
    {
        if(s[i]=='A')
        cout<<a[cnt];
        else if(s[i]=='B')
        cout<<b[cnt];
        else if(s[i]=='C')
        cout<<c[cnt];
        else if(s[i]=='D')
        cout<<d[cnt];
        else if(s[i]=='E')
        cout<<e[cnt];
    }
    cout<<endl;
    cnt++;
    }

}