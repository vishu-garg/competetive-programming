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
       ll n;
       cin>>n;
       V v(n);
       set<ll> s;
       map<ll,V> mp;
       rep(i,0,n)
       {cin>>v[i];s.insert(v[i]);mp[v[i]].pb(i);}
       ll ans=0;
       for(auto it : s)
       {
           V ind=mp[it];
           ll tmp=ind.size();
           ll cnt=0;
           ll m2=tmp;
           ll mx=tmp/2;
           rep(i,0,mx)
           {
               ll ans2=(2*(i+1));
               map<ll,ll> mp2;
               rep(j,ind[i],ind[m2-i-1])
               {
                   if(v[j]!=it)
                   mp2[v[j]]++;
                }
                ll m3=0;
                for(auto it2 : mp2)
                {
                    m3=max(m3,it2.second);
                }
                ans2+=m3;
                tmp=max(tmp,ans2);
           }
            
            ans=max(ans,tmp);
       }
       cout<<ans<<endl;

        
    }

}