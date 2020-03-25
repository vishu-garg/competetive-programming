#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll r,g,b;
        cin>>r>>g>>b;
        ll m=max(r,max(g,b));
        if(m==r) 
        {
            m2=max(b,g)
            if((b+g)<r-1)
            cout<<"No";
            else
            {
                if(m2==b)
                {
                  g=g-(r-1-b);
                  if(g>=2)
                  cout<<"No";   
                }
                else if(m2==g)
                {
                  b=b-(r-1-g);
                  if(b>=2)
                  cout<<"No";   
                }
                else 
                cout<<"Yes";
            }
        }