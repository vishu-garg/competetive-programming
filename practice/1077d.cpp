#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
 
#define ll long long
#define ld long double
 
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
 
#define err() cout<<"=================================="<<endl;
#define errA(A) for(auto i:A)   cout<<i<<" ";cout<<endl;
#define err1(a) cout<<#a<<" "<<a<<endl
#define err2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl
#define err3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl
#define err4(a,b,c,d) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<" "<<#d<<" "<<d<<endl
 
#define pb push_back
#define all(A)  A.begin(),A.end()
#define allr(A)    A.rbegin(),A.rend()
#define ft first
#define sd second
 
#define pll pair<ll,ll>
#define V vector<ll>
#define S set<ll>
#define VV vector<V>
#define Vpll vector<pll>
 
#define endl "\n"
 
const ll logN = 20;
const ll M = 1000000007;
const ll INF = 1e12;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int pow1(int a,int b){
    int res=1;
    while(b>0){
        if(b&1){
        	res=res*a;
		}
        a=a*a;
        b>>=1;
    }
    return res;
}

int main()
{
    fast;
    ll T=1;
//     cin>>T;
    while(T--)
    {
        ll n,k;
        cin>>n>>k;
        vector<ll>v(n);
        map<ll,ll>mp;
        for(ll i=0;i<n;i++)
        {
            cin>>v[i];
            mp[v[i]]++;
        }
        vector<pair<ll,ll>>vec;
        for(auto it:mp)
        vec.pb({it.second,it.first});
        sort(all(vec),greater<pair<ll,ll> >());
        // for(auto it:vec)cout<<it.first<<" "<<it.second<<endl;
        ll lo=1;
        ll hi=(n/k);
        vector<ll>ans;
        for(int i=0;i<k;i++)
        ans.pb(v[i]);
        
        while(lo<=hi)
        {
            ll mid=(lo+hi)/2;
            ll sum=0;
            ll i=0;
            vector<pll>tmp;
            // err()
            while(sum<k && i<vec.size())
            {
                sum+=(vec[i].first/mid);
                tmp.pb({vec[i].first/mid,vec[i].second});
                i++;
            }
            // cout<<lo<<" "<<hi<<" "<<mid<<" "<<sum<<" "<<endl;
            if(sum>=k)
            {
                lo=mid+1;
                ans.clear();
                i=0;
                while(ans.size()<k)
                {
                    if(tmp[i].first==0)
                    i++;
                    ans.pb(tmp[i].second);
                    tmp[i].first--;
                }
                // cout<<endl;
                // for(auto it:ans)cout<<it<<" ";
            }
            else 
            {
                hi=mid-1;
            }
            // cout<<lo<<" "<<hi<<" "<<endl;
        }

        for(auto it:ans)
        {
            cout<<it<<" ";
        }
    }

}