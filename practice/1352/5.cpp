#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
 
#define ll long long
#define ld long double
 
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
 


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll t=1;
     cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        rep(i,0,n)
        cin>>a[i];
        ll ans=0;
        rep(i,0,n)
        {
            ll l=0,r=1;
            ll flg=0;
            ll sum=a[l]+a[r];
            while(r<n)
            {
                if(sum==a[i])
                {
//                	cout<<l<<" "<<r<<" = "<<sum<<"  "<<a[i]<<" <==="<<endl;
                    flg=1;
                    break;
                }
                else if(sum<a[i])
                {
                    r++;
                    if(r==n)
                    break;
                    sum+=a[r];
                }
                else if(sum>a[i])
                {
                	sum-=a[l];
                    l++;
                    if(l==r)
                    {
                    	r++;
                    	if(r==n)break;
                    	sum+=a[r];
					}
                }
            }
            if(flg==1)
            ans++;
        }
        cout<<ans<<endl;
    }

}

// GOOD CONCEPT USING SLIDING WINDOW SO THAT LOW MEMORY REQUIRED