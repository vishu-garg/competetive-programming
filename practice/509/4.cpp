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
    fast;

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    
    ll T=1;
//     cin>>T;
    while(T--)
    {
        ll n,m;
        cin>>n>>m;
        vector<vector<ll>>mat(n,V(m));
        rep(i,0,n)
        rep(j,0,m)
        {cin>>mat[i][j];}

        // rep(i,0,n)
        // {errA(mat[i]);cout<<endl;}
        
        sort(all(mat));

        // err1(mat[0][0]);

        ll a1=0;
        V a,b;
        a.pb(0);

        ll flg=0;

        ll k=1;

        rep(i,1,n)
        {
            set<ll> tmp;
            rep(j,0,m)
            {
                // err2(mat[i][j],mat[i-1][j]);
                tmp.insert(mat[i][j]-mat[i-1][j]);
            }
            // errA(tmp);
            if(tmp.size()>2)
            {
                err();
                flg=1;
                break;
            }
            V tmp2;
            for(auto it:tmp)
            tmp2.pb(it);
            // err()
            if(tmp2.size()==2)
            {
                if(tmp2[0]*tmp2[1]>=0)
                {
                    // err();
                    flg=1;
                    break;
                }
                else 
                {
                    if(k==1)
                    k=(k*abs((tmp2[0]-tmp2[1])));
                    else if(k!=abs((tmp2[0]-tmp2[1])))
                    {
                        // err();
                        flg=1;
                        break;
                    }
                }
            }
        }
            if(flg==1)
            {
                cout<<"NO"<<endl;
                return 0;
            }


            // err();


            rep(i,1,n)
            {
                a.pb(mat[i][0]-mat[0][0]);
            }

            rep(j,0,m)
            {
                b.pb(mat[0][j]);
            }

            ll mat2[n+1][m+1];
            rep(i,0,n)
            {
                rep(j,0,m)
                {
                    mat2[i][j]=a[i]+b[j];
                    if(k!=1)
                    {
                        mat2[i][j]%=k;
                    }   
                }
            }

            rep(i,0,n)
            {
                rep(j,0,m)
                {
                    if(mat[i][j]!=mat2[i][j])
                    {
                        cout<<"NO"<<endl;
                        return 0;
                    }
                }
            }

            cout<<"YES"<<endl;

            if(k==1)
            {
                cout<<(ll)(1e18)<<endl;
            }
            else 
            {
                cout<<k<<endl;
            }

            rep(i,0,n)
            cout<<a[i]<<" ";
            cout<<endl;
            rep(i,0,m)
            cout<<b[i]<<" ";
      

    }

}