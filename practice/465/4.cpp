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
        vector<array<ll,3>> a(8),b;
        rep(i,0,8)
        {
            cin>>a[i][0]>>a[i][1]>>a[i][2];

            sort(all(a[i]));
        }

        b=a;

        sort(all(a),[&](array<ll,3> tmp1, array<ll,3> tmp2){
            if(tmp1[0]!=tmp2[0])
            return tmp1[0]<tmp2[0];
            if(tmp1[1]!=tmp2[1])
            return tmp1[1]<tmp2[1];
            if(tmp1[2]!=tmp2[2])
            return tmp1[2]<tmp2[1];
        });

        if(a[7][1]-a[0][1]!=a1)
        {
            cout<<"NO"<<endl;
            break;
        }
        if(a[7][2]-a[0][2]!=a1)
        {
            cout<<"NO"<<endl;
            break;
        }

        err();

        ll x=a[0][0],y=a[0][1],z=a[0][2];
        ll x1=a[7][0],y1=a[7][1],z1=a[7][2];

        vector<array<ll,3>>ans;


        array<ll,3> p,p2;


        p[0]=x,p[1]=y,p[2]=z;
        p2=p;
        sort(all(p));
        if(find(all(b),p)==b.end())
        {
            cout<<"NO"<<endl;
            return 0;
        }
        else 
        {
            ans.pb(p2);
        }

        p[0]=x1,p[1]=y,p[2]=z;
        p2=p;
        sort(all(p));
        if(find(all(b),p)==b.end())
        {
            cout<<"NO"<<endl;
            return 0;
        }
        else 
        {
            ans.pb(p2);
        }

        p[0]=x,p[1]=y1,p[2]=z;
        p2=p;
        sort(all(p));
        if(find(all(b),p)==b.end())
        {
            cout<<"NO"<<endl;
            return 0;
        }
        else 
        {
            ans.pb(p2);
        }

        p[0]=x,p[1]=y,p[2]=z1;
        p2=p;
        sort(all(p));
        if(find(all(b),p)==b.end())
        {
            cout<<"NO"<<endl;
            return 0;
        }
        else 
        {
            ans.pb(p2);
        }

        p[0]=x1,p[1]=y1,p[2]=z;
        p2=p;
        sort(all(p));
        if(find(all(b),p)==b.end())
        {
            cout<<"NO"<<endl;
            return 0;
        }
        else 
        {
            ans.pb(p2);
        }

        p[0]=x1,p[1]=y,p[2]=z1;
        p2=p;
        sort(all(p));
        if(find(all(b),p)==b.end())
        {
            cout<<"NO"<<endl;
            return 0;
        }
        else 
        {
            ans.pb(p2);
        }
        
        p[0]=x,p[1]=y1,p[2]=z1;
        p2=p;
        sort(all(p));
        if(find(all(b),p)==b.end())
        {
            cout<<"NO"<<endl;
            return 0;
        }
        else 
        {
            ans.pb(p2);
        }

        p[0]=x1,p[1]=y1,p[2]=z1;
        p2=p;
        sort(all(p));
        if(find(all(b),p)==b.end())
        {
            cout<<"NO"<<endl;
            return 0;
        }
        else 
        {
            ans.pb(p2);
        }

        cout<<"YES"<<endl;

        V vis(8,0);

        rep(i,0,8)
        {
            // cout<<b[i][0]<<" "<<b[i][1]<<" "<<b[i][2]<<"<==="<<endl;
            ll cnt=0;
            array<ll,3>c=b[i];
            sort(all(c));
            rep(j,0,8)
            {
                if(vis[j])
                continue;
                array<ll,3>d=ans[j];
                sort(all(d));

                if(d==c)
                {
                    cout<<ans[j][0]<<" "<<ans[j][1]<<" "<<ans[j][2]<<endl;
                    vis[j]=1;
                    break;
                }
                
            }
        }

    }

}