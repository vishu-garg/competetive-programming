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
        ll n;
        cin>>n;
        vector<pll>a(n);
        rep(i,0,n)
        cin>>a[i].first>>a[i].second;
        ll ans=0;
        V r(n),l(n);
        l[0]=-INF;
        r[n-1]=INF;
        rep(i,1,n)
        {
            l[i]=a[i-1].first;
        }
        rep(i,0,n-1)
        {
            r[i]=a[i+1].first;
        }

        ans=1;
        rep(i,1,n)
        {
            // cout<<a[i].second<<" "<<l[i]<<" "<<r[i]<<endl;
            if(l[i]<a[i].first-a[i].second)
            {
                ans++;
            }
            else if(r[i]>a[i].first+a[i].second)
            {
                ans++;
                if(i+1<n)
                l[i+1]=a[i].first+a[i].second;
            }
        }
        cout<<ans<<endl;
        return 0;

    }

}