#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
 
#define ll long long
#define ld long double
 
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
#define pb push_back


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll t=1;
     cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        if(n<4)
        {
            cout<<"-1"<<endl;
            continue;
        }
        vector<ll> ans;
        ll tmp=n;
        while(tmp>4)
        {
            if(tmp%2==0)
            ans.pb(tmp);
            tmp--;
        }
        ans.pb(2);
        ans.pb(4);
        rep(i,1,n+1)
        {
            if(i%2)
            ans.pb(i);
        }
        rep(i,0,n)
        cout<<ans[i]<<" ";
        cout<<endl;
    }

}