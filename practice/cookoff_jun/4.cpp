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
    cin>>T;
    while(T--)
    {
        ll n,c;
        cin>>n>>c;
        vector<array<ll,2>>v(n);
        rep(i,0,n)
        {
            cin>>v[i][0]>>v[i][1];
        } 
        if(c==0)    
        {
            cout<<n<<" "<<0<<endl;
            continue;
        }
        vector<bool>vis(n+1,false);
        vector<V>ans;
        rep(i,0,n)
        {
            if(vis[i])continue;
            vector<ll>tmp;
            vis[i]=true;
            tmp.pb(v[i][0]);
            for(ll j=i+1;j<n;j++)
            {
                if(vis[j])continue;
                ll d1=v[j][0]-v[i][0];
                ll d2=v[j][1]-v[i][1];
                if(d1==d2 && d1%c==0)
                {
                    vis[j]=true;
                    tmp.pb(v[j][0]);
                }
            }
            sort(all(tmp));
            ans.pb(tmp);
            // sort(all(tmp));
        }


        ll chk=ans.size();
        ll stp=0;
        for(auto it:ans)
        {
            if(it.size()==1)continue;
            // sort(all(it));
            // ll f=it[0];
            // ll lst=(it.back());
            // ll md_x=(f+lst)/2;
            // ll md_2=(f+lst+1)/2;
            ll tmp2=LLONG_MAX;
            vector<ll>tmp4=it;
            rep(i,1,it.size())
            {
                tmp4[i]+=tmp4[i-1];
            }
            // errA(tmp4);
            for(ll i=0;i<it.size();i++)
            {
                ll tmp3=0;
                ll sum=tmp4.back();
                if(i>0)sum-=tmp4[i-1];
                sum-=(it[i]*(it.size()-i));
                sum/=c;
                ll sum2=tmp4[i];
                sum2=(it[i]*(i+1))-sum2;
                sum2/=c;
                tmp3=sum+sum2;
                // cout<<tmp3<<endl;
                tmp2=min(tmp2,tmp3);
            }
            // cout<<tmp2<<endl;
            // for(auto it2:it)
            // {
            //     tmp3+=(abs(it2[0]-md_2));
            // }
            stp+=tmp2;
        }

        cout<<chk<<" "<<stp<<endl;



    }

}