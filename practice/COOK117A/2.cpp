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
   cin>>t;
    while(t--)
    {
        string s,r;
        cin>>s>>r;
        ll n=s.length();
        vector<ll> vec;
        rep(i,0,n)
        {
            if(s[i]!=r[i])
            vec.pb(i);
        }
        ll l=vec.size();
        if(l==0)
        {
            cout<<"0"<<endl;
            continue;
        }
        // ll k=1;
        vector<ll> dif;
        rep(i,0,vec.size()-1)
        {
//        	cout<<vec[i+1]-vec[i]-1<<" ";
            if(vec[i+1]-vec[i]-1!=0)
            dif.pb(vec[i+1]-vec[i]-1);
        }
//        cout<<endl;
//        cout<<dif.size()<<endl;
        ll k=dif.size()+1;
        ll ans=k*l;
        sort(all(dif));
        rep(i,0,dif.size())
        {
            k--;
            l+=dif[i];
//            cout<<k<<" "<<l<<endl;
            ll tmp=k*l;
            ans=min(ans,tmp);
        }
        cout<<ans<<endl;
    }

}