#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll r,c;
    cin>>r>>c;
    ll row[r];
    ll col[c];
    ll cnt=1;
    for(ll i=0;i<r;i++)
    {
        row[i]=cnt;
        cnt++;
    }
    for(ll i=0;i<c;i++)
    {
        col[i]=cnt;
        cnt++;
    }
    if(r==1 && c==1)
    cout<<"0";
    else if(r==1 &&c!=1)
    {
        for(ll i=0;i<c;i++)
        cout<<i+2<<" ";
    }
    else if(r!=1 &&c==1)
    {
        for(ll i=0;i<r;i++)
        cout<<i+2<<endl;
    }
    else
    {
        ll ans[r][c];
        for(ll i=0;i<r;i++)
        {
            for(ll j=0;j<c;j++)
            {
                ll temp=row[i]*col[j];
                ll t2=__gcd(row[i],col[j]);
                temp=(temp/t2);
                ans[i][j]=temp;
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}