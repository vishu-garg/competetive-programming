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
const ll N=100005;
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

// struct segtree{
//     ll x,y;
//     ll tree[4*N];

//     void build_tree(vector<ll>&v , ll ind,ll l, ll r)
//     {
//         if(l==r)
//         {
//             tree[ind]=v[l];
//             return;
//         }
//         ll mid=(l+r)/2;
//         build_tree(v,2*ind,l,mid);
//         build_tree(v,2*ind+1,mid+1,r);
//         tree[ind]=max(tree[2*ind],tree[2*ind+1]);
//     }

//     ll query(ll ind, ll l, ll r)
//     {
//         // cout<<l<<" "<<r<<" "<<endl;
//         if(x>r || y<l)return -LLONG_MAX;
//         if(l>=x && r<=y)return tree[ind];
//         ll mid=(l+r)/2;
//         return max(query(2*ind,l,mid),query(2*ind+1,mid+1,r));
//     }
// }obj;

int main()
{
    fast;
    ll T=1;
//     cin>>T;
    while(T--)
    {
        ll n,p;
        cin>>n>>p;
        V a(n);
        rep(i,0,n)cin>>a[i];
        sort(all(a));

        ll lo=1,hi=1e9+1;
        ll s=-1;
        while(lo<=hi)
        {
            ll md=(lo+hi)/2;
            ll x=md;
            ll cnt=0;
            ll fnd=0;
            while(cnt<n)
            {
                ll tmp=upper_bound(all(a),x)-a.begin();
                tmp-=cnt;
                if(tmp==0){fnd=1;break;}
                x+=1;
                cnt++;
            }
            if(fnd==0)
            {
                s=md;
                hi=md-1;
            }
            else 
            {
                lo=md+1;
            }
        }

        if(s<0)
        {
            cout<<"0"<<endl<<endl;
            return 0;
        }

        ll t=-1;
        lo=1;
        hi=1e9+1;
        // err1(lo);
        
        while(lo<=hi)
        {
            ll md=(lo+hi)/2;
            ll x=md;
            ll cnt=0;
            ll fnd=0;
            // err1(md);
            while(cnt<n)
            {
                ll tmp=upper_bound(all(a),x)-a.begin();
                tmp-=cnt;
                if(tmp>=p){fnd=1;break;}
                x+=1;
                cnt++;
            }
            // err1(fnd);
            if(fnd==0)
            {
                t=md;
                lo=md+1;
            }
            else 
            {
                hi=md-1;
            }
        }

        // err2(s,t);

        if(t<0 || t-s+1<0)
        {
            cout<<"0"<<endl<<endl;
            return 0;
        }

        cout<<t-s+1<<endl;
        rep(i,s,t+1)
        cout<<i<<" ";
        cout<<endl;




        
    }

}