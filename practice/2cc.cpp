#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        ll n=s.length();
        ll p[s.length()+1];
        ll i;
        p[0]=0;
        for(i=1;i<=n;i++)
        {
            p[i]=p[i-1];
            if(s[i-1]=='0')
            p[i]=p[i]+1;
        }
        ll pre_cost=s.length();
        for(ll L=1;L<=n;L++)
        {
            for(ll R=L;R<=n;R++)    
            {
                ll s1=p[L-1];
                ll s2=p[n]-p[R];
                ll s3=(R-L+1)-(p[R]-p[L-1]);
                ll cost=s1+s2+s3;
                if(cost<pre_cost)
                pre_cost=cost;
            }
        }

        p[0]=0;
        for(i=1;i<=n;i++)
        {
            p[i]=p[i-1];
            if(s[i-1]=='1')
            p[i]=p[i]+1;
        }
        for(ll L=1;L<=n;L++)
        {
            for(ll R=L;R<=n;R++)    
            {
                ll s1=p[L-1];
                ll s2=p[n]-p[R];
                ll s3=(R-L+1)-(p[R]-p[L-1]);
                ll cost=s1+s2+s3;
                if(cost<pre_cost)
                pre_cost=cost;
            }
        }
        cout<<pre_cost<<endl;
    }
}