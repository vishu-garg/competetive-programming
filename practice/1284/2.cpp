#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    vector<vector<ll>> a(n);
    ll ys[n]={0},mn[n],max[n];
    for(ll i=0;i<n;i++)
    {
        ll l;
        cin>>l;
        ll temp1;
        cin>>temp1;
        a[i].push_back(temp1);
        mn[i]=a[i][0];
        max[i]=a[i][0];
        for(ll j=1;j<l;j++)
        {
            ll temp;
            cin>>temp;
            if(temp>mn[i])
            ys[i]=1;
 
            if(temp<=mn[i])
            mn[i]=temp;
 
            if(temp>max[i])
            max[i]=temp;
        }
    }
	ll c1=0;
	vector<ll> v;
	for(ll i=0;i<n;i++)
	{
		if(ys[i]!=1)
		{
			v.push_back(mn[i]);
		}
		else 
		c1++;
	}
	ll ans=0;
	sort(v.begin(),v.end());
	for(ll i=0;i<n;i++)
	{
		if(ys[i]==1)
		ans=ans+n;
		else 
		{
			auto tm=lower_bound(v.begin(),v.end(),max[i]);
			ll temp=tm-v.begin();
			temp=temp+c1;
			ans=ans+temp;
		}
	}
	cout<<ans<<endl;
}