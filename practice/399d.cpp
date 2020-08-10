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
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll logN = 20;
const ll M = 1000000007;
const ll INF = 1e12;
#define PI 3.14159265

ll pow1(ll a,ll b){
    ll res=1;
    a%=M;
    while(b>0){
        if(b&1){
        	res=(res*a)%M;
		}
        a=(a*a)%M;
        b>>=1;
    }
    return res%M;
}
vector<ll> a;
vector<ll>node(300005);

void build(ll ind,ll st, ll en, ll d)
{
    if(st==en)
    {node[ind]=a[st];return;}
    ll mid=(st+en)/2;
    build(2*ind,st,mid,d-1);
    build(2*ind+1,mid+1,en,d-1);
    if(d%2==0)
    node[ind]=(node[2*ind] ^ node[2*ind+1]);
    else 
    node[ind]=(node[2*ind] | node[2*ind+1]);
//    cout<<node[ind]<<" <--"<<endl;
    
}

void update(ll ind, ll st, ll en,  ll pnt , ll d)
{
//	cout<<st<<" "<<en<<" "<<pnt<<" "<<d<<" "<<endl;
    if(st==pnt && en==pnt)
    {
        node[ind]=a[st];
        return;
    }
    if(st>pnt || en<pnt)
    return;
    ll mid=(st+en)/2;
    update(2*ind,st,mid,pnt,d-1);
    update(2*ind+1,mid+1,en,pnt,d-1);
    if(d%2==0)
    node[ind]=(node[2*ind] ^ node[2*ind+1]);
    else 
    node[ind]=(node[2*ind] | node[2*ind+1]);
//    cout<<node[ind]<<" <---"<<endl;
}

int main()
{
    fast
    ll t=1;
//     cin>>t;
    while(t--)
    {   
        ll n,m;
        cin>>n>>m;
        a=vector<ll>((ll)pow(2,n)+5ll);
//        cout<<a.size();
        rep(i,0,(ll)pow(2,n))
        cin>>a[i];
        ll lmt=pow(2,n)-1ll;
        build(1,0,lmt,n);
        rep(i,0,m)
        {
            ll p,b;
            cin>>p>>b;
            a[p-1]=b;
            update(1,0,lmt ,p-1,n);
            cout<<node[1]<<endl;
        }
        
    }

}