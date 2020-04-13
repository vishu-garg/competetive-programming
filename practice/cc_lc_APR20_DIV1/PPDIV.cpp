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

ll pow1(ll a,ll b){
    ll res=1;
    a=(a%M);
    while(b>0){
        if(b&1){
        	res=(res*a)%M;
		}
        a=(a*a)%M;
        b>>=1;
    }
    res%=M;
    return res;
}

int main()
{
    ll t=1;
   cin>>t;
    while(t--)
    {
        ll  n;
        cin>>n;
        ll lmt=cbrt(n);
        for(ll i=2;i<=lmt;i++)
        {
            ll k=(ll)(log(n)/log(i));
            ll tmp=pow1(i,k);
            ans=(ans+tmp)%M;
        }
        ll of2=sqrt(n);
        ll sum=((of2*(of2+1ll))*(2*of2+1ll))/6ll;
        ll s2=((lmt*(lmt+1ll))*(2*lmt+1ll))/6ll;
        sum-=s2;
        sum%=M;
        ans+=sum;
        ans%=M;
        ans+=n;
        ans%=M;
        cout<<ans<<endl;
    }

}