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

    // #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    // #endif

    ll T=1;
//     cin>>T;
    while(T--)
    {
        ll m,n,k,t;
        cin>>m>>n>>k>>t;
        V a(m);
        rep(i,0,m)cin>>a[i];

        vector<array<ll,3>>trap(k);
        rep(i,0,k)
        {
            cin>>trap[i][0]>>trap[i][1]>>trap[i][2];
        }

        if(t<n+1)
        {
            cout<<"0<----";
            return 0;
        }

        ll lo=0,hi=200005;

        ll ans=-1;

        while(lo<=hi)
        {
            ll md=(lo+hi)/2;

            ll mx=-1;
            ll mn=n+1;
            ll flg=0;

            Vpll v;

            rep(i,0,k)
            {
                if(trap[i][2]>md)
                v.pb({trap[i][0]-1,trap[i][1]});
            }

            sort(all(v));

            vector<pll>v2;

            rep(i,0,v.size())
            {
                if(i==0)
                v2.pb(v[i]);
                else 
                {
                    pll tmp=v2.back();
                    if(v[i].first<=tmp.second)
                    {
                        v2.back().second=max(v2.back().second,v[i].second);
                    }
                    else
                    {
                        v2.pb(v[i]);
                    }
                }
            }

            if(v2.size()==0)flg=1;
            else 
            {
                ll tme=0;
                for(auto it:v2)
                tme+=(2*(it.second-it.first));
                tme+=n+1;
                if(tme<=t)
                flg=1;
            }
            


            if(flg==1)
            {
                ans=md;
                hi=md-1;
            }
            else 
            {
                lo=md+1;
            }  
        }

        assert(ans!=-1);


        ll cnt=0;

        rep(i,0,m)
        if(a[i]>=ans)cnt++;

        cout<<cnt<<endl;

        
    }

}