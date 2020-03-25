#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,p,k;
        cin>>n>>p>>k;
        vector<ll> a(n);
        for(ll i=0;i<n;i++)
        cin>>a[i];
        sort(a.begin(),a.end());
        ll i,pref=0,sum=0,ans=0;
        for(i=0;i<k;i++)
        {
            sum=pref;
            if(sum>p) break;
            ll cnt=i;
            for(ll j=i+k-1;j<n;j+=k)
            {
                if(sum+a[j]<=p)
                {
                    cnt+=k;
                    sum+=a[j];
                }
                else{
                    break;
                }
            }
            pref+=a[i];
            ans=max(ans,cnt);
        }
        cout<<ans<<"\n";
    }
}