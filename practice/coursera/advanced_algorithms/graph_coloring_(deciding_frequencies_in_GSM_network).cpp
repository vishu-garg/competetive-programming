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
        ll  n,m;
        cin>>n>>m;
        ll clr=3; // no of frequncies
        ll v=clr*n;
        ll c=n+(m*clr);
        vector<pair<ll,ll> >edges(m);
        rep(i,0,m)
        {
        cin>>edges[i].first>>edges[i].second;
        ll mx=max(edges[i].first,edges[i].second);
        ll mn=min(edges[i].first,edges[i].second);
        edges[i].first=mn;edges[i].second=mx;
        }
        cout<<c<<" "<<v<<endl;
        rep(i,1,n+1)
        {
            rep(j,1,clr+1)
            {
                cout<<(clr*(i-1))+(j)<<" ";
            }
            cout<<"0"<<endl;
        }
        rep(i,0,m)
        {
            ll i1=edges[i].first;
            ll i2=edges[i].second;
            rep(j,1,clr+1)
            {
                cout<<"-"<<(clr*(i1-1)+j)<<" -"<<(clr*(i2-1)+j)<<" 0"<<endl;
            }
        }
        return 0;
    }

}