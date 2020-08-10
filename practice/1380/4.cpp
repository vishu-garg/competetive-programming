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
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    
    ll T=1;
    // cin>>T;
    while(T--)
    {
        ll x,k,y;
        ll n,m;
        cin>>n>>m;
        cin>>x>>k>>y;
        V a(n),b(m);
        rep(i,0,n)cin>>a[i];
        rep(i,0,m)cin>>b[i];
        // reverse(all(a));
        // reverse(all(b));

        ll flg=0;
        V tmp;
        tmp.pb(-1);
        ll i=0,j=n-1;
        ll lst=0;
        ll s1=0,s2=m-1;
        while(tmp.size()-1<m && i<=j)
        {
            // err1(lst);
            if(lst==0)
            {
                while(i<=j && a[i]!=b[s1])
                i++;
                // err1(i);
                if(i>j)
                {
                    break;
                }
                else 
                {
                    tmp.pb(i);
                    i++;
                    s1++;
                    lst++;
                    // err3(i,j,lst);
                }
                // err();
            }
            else 
            {
                // err();
                while(i<=j && a[j]!=b[s2])
                j--;
                // err1(j);
                if(i>j)
                {
                    break;
                }
                else 
                {
                    tmp.pb(j);
                    j--;
                    s2--;
                    lst--;
                }
            }
        }
        // errA(tmp);
        sort(all(tmp));
        tmp.pb(n);
        if(tmp.size()-2<m)
        {
            cout<<"-1";
            break;
        }
        // errA(tmp);
        ll ans=0;

        for(ll i=1;i<m+2;i++)
        {
            ll diff=(tmp[i]-tmp[i-1]-1);
            // err1(diff);
            ll mx=-INF;
            if(diff==0)
            continue;
            // err2(tmp[i-1]+1,tmp[i]-1);
            rep(j,tmp[i-1]+1,tmp[i])
            {
                mx=max(mx,a[j]);
            }
            // err1(mx);
            ll fnd=0;
            if(tmp[i-1]>=0 && a[tmp[i-1]]>=mx)
            fnd=1;
            else if(tmp[i]<n && a[tmp[i]]>=mx)
            fnd=1;
            
            if(fnd)
            {ll cst1=(y*(diff));
            ll tmp2=(diff/k);
            ll tmp3=(diff%k);
            ll cst2=(tmp2*x)+(tmp3*y);
            ans+=min(cst2,cst1);}

            else 
            {
                if(diff<k)
                {
                    cout<<"-1";
                    return 0;
                }
                else 
                {
                    ll cst=x;
                    diff-=k;
                    ll cst1=(y*(diff));
                    ll tmp2=(diff/k);
                    ll tmp3=(diff%k);
                    ll cst2=(tmp2*x)+(tmp3*y);
                    cst+=min(cst2,cst1);
                    ans+=cst;
                }
            }
        }

        cout<<ans<<endl;


    }

}