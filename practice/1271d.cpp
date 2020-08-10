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
ll pow1(ll a,ll b){
    ll res=1;
    while(b>0){
        if(b&1){
        	res=(res*a)%M;
		}
        a=(a*a)%M;
        b>>=1;
    }
    return res%M;
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
    // fast;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    ll T=1;
//     cin>>T;
    while(T--)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        // err();
        V v(n+1);
        v[0]=k;
        ll flg=1;
        Vpll vec;
        V B(n+1),A(n+1);
        ll ned[n+2];

        rep(i,0,n)
        {
            ll a,b,c;
            // err();
            cin>>a>>b>>c;
            A[i+1]=a;
            B[i+1]=b;
            vec.pb({c,i+1});
            // err();
            if(a>v[i])
            {
                flg=0;
            }
            ned[i+1]=a;
            v[i+1]=b+v[i];
        }

        // errA(ned);

        ned[n+1]=0;

        repb(i,n,1)
        ned[i]=max(ned[i],ned[i+1]-B[i]);

        // errA(ned);
        // err1(m);
        ll mx_p[n+2];
        rep(i,1,n+1)
        mx_p[i]=i;


        for(ll i=0;i<m;i++)
        {
            // err1(i);
            ll u,v;
            cin>>u>>v;
            // err2(u,v);
            mx_p[v]=max(mx_p[v],u);
            // err1(mx_p[v]);
        }

        // errA(mx_p);

        // err();

        if(flg==0)
        {
            cout<<"-1"<<endl;
            return 0;
        }

        sort(all(vec),[&](pll p1,pll p2){
            if(p1.first!=p2.first)
            return p1.first<p2.first;
            return p1.second>p2.second;
        });
        reverse(all(vec));

        // err();

        V def(n+1,0);

        ll sum=0;

        for(auto it:vec)
        {
            // err1(it.second);
            ll pos=it.second;
            pos=mx_p[pos];
            // err1(pos);
            ll ext=v[pos]-ned[pos+1];
            err2(ext,pos);
                V tmp1=B;
                ll tmp2[n+2];
                rep(j,1,n+2)
                tmp2[j]=ned[j];

                if(B[pos]==0)
                ned[pos]++;
                else 
                {B[pos]--;}
                
                rep(j,pos,n+1)
                {
                    v[j]=v[j-1]+B[pos];
                }

                // repb(j,pos,0)
                // {
                //     if(B[j]>0)
                //     {err1(j);
                //     flg=1;
                //     B[j]--;
                //     break;}
                // }
                // rep(j,1,n+1)
                // v[j]=v[j-1]+B[j];
                repb(j,n,1)
                ned[j]=max(ned[j],ned[j+1]-B[j]);

                ll flg2=1;
                repb(j,n,1)
                {
                err2(ned[j],v[j-1]);
                if(ned[j]>v[j-1])
                {
                    err1(j);
                    err();
                    flg2=0;
                    break;
                }
                }


                // errA(ned);
                if(flg2){
                def[it.second]=1;
                sum+=it.first;}
                else 
                {
                    rep(j,1,n+2)
                    ned[j]=tmp2[j];
                    B=tmp1;
                }
        }

        cout<<sum<<endl;


    }

}