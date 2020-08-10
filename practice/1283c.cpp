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
//     cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        rep(i,0,n)
        cin>>a[i];
        map<ll,ll> mp;
        rep(i,0,n)
        {
            mp[a[i]]++;
        }
        vector<pair<ll,ll> > pr;
        vector<ll> to_gve,to_rcv;
        rep(i,0,n)
        {
            if(mp[i+1]==0 && a[i]==0)
            pr.pb({i,i});
            else
            {
               if(mp[i+1]==0)
               to_rcv.pb(i);
               else if(a[i]==0)
               to_gve.pb(i);
            
			}
        }
        if(pr.size()>1)
		{
			rep(i,0,pr.size())
			{
				a[pr[i].first]=pr[(i+1)%((ll)pr.size())].second+1;
			}
		}
        sort(all(to_gve));
        sort(all(to_rcv));
//        ll flg=0;
       rep(i,0,to_gve.size())
        {
     		a[to_gve[i]]=to_rcv[i]+1;
        }
        if(pr.size()==1){
        a[to_gve.back()]=pr[0].second+1;
        a[pr[0].first]=to_rcv.back()+1;}
        rep(i,0,n)
        cout<<a[i]<<" ";
        cout<<endl;
    }
}