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
    ll t=1;
//    cin>>t;
    while(t--)
    {
        ll n,k,l;
        cin>>n>>k>>l;
        ll sz=n*k;
        V v(sz);
        rep(i,0,sz)
        cin>>v[i];
        sort(all(v));
        ll mn=v[0];
        ll mx=v[sz-k];
        ll ans=0;
        ll tmp=l+mn+1;
        tmp=lower_bound(all(v),tmp)-v.begin();
        ll t2=sz-tmp;
        if(k==1 && t2!=0)
        {
        	cout<<"0";
        	return 0;
		}
        if(t2>(tmp*(k-1)))
        {
            cout<<"0";
            return 0;
        }
        ll t3=n*k;
        tmp--;
        while(t2>=(k-1) && tmp>=0)
        {
            ans+=v[tmp];
            tmp--;
            t2-=(k-1);
            t3-=k;
        }
        for(ll i=0;i<(t3);i+=k)
        {
            ans+=v[i];
        }

        cout<<ans<<endl;
    return 0;
    }

}