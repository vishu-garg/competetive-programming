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
        vector<ll>a(n);
        rep(i,0,n)cin>>a[i];
        vector<ll>cnt(n,0);
        rep(i,0,n)
        {
            if(a[i]<0)cnt[i]++;
        }
        rep(i,1,n)
        cnt[i]+=cnt[i-1];
        ll ans1=0,ans2=0;
        // rep(i,0,n)
        // cout<<cnt[i]<<" ";
        // cout<<endl;
        ll cnt1=1,cnt2=0;
        rep(i,0,n)
        {
            if(cnt[i]%2==0)
            {
                ans1+=cnt1;
                ans2+=cnt2;
                cnt1++;
            }
            else
            {
                ans1+=cnt2;
                ans2+=cnt1;
                cnt2++;
            }
            // cout<<ans1<<" "<<ans2<<"<--"<<endl;
        }
        cout<<ans2<<" "<<ans1<<endl;
    }

}