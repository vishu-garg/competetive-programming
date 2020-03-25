#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,s;
        cin>>n>>s;
        vector<ll> v(n),m(n),v2(n);
        cin>>v[0];
        m[0]=0;
        v2[0]=v[0];
        for(ll i=1;i<n;i++)
        {
            cin>>v2[i];
            m[i]=m[i-1];
            if(v2[m[i]]<v2[i])
            m[i]=i;
            v[i]=v2[i]+v[i-1];
         }
         ll real_ans=0;
        ll ans= lower_bound(v.begin(),v.end(),s)-v.begin();
        cout<<ans<<endl;
        ll real_ans2=m[ans-1]+1;
        ll temp=s-v[m[ans-1]]+v[ans-1];
        ll ans2=lower_bound(v.begin(),v.end(),temp)-v.begin();
        if(ans>ans2)
        cout<<"0"<<endl;
        else
        {
            cout<<real_ans2<<endl;
        }

    }
}