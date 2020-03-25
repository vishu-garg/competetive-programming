#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,start,end) for(ll i=start;i<end;i++)
int main()
{
    ll n;
    cin>>n;
    ll b[n];
    rep(i,0,n)
    cin>>b[i];
    ll m;
    cin>>m;
    ll g[m];
    rep(i,0,m)
    cin>>g[i];
    sort(b,b+n);
    sort(g,g+m);
    ll pb=0,pg=0;
    ll cnt=0;
    while(pb!=n && pg!=m)
    {
        ll dif=b[pb]-g[pg];
        if(dif==1 || dif==0 || dif==-1)
        {
            cnt++;
            pb++;
            pg++;
        }
        else if(dif>1)
        pg++;
        else
        pb++;
    }
    cout<<cnt;
}