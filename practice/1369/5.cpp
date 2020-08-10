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
    // fast;
    ll T=1;
//     cin>>T;
    while(T--)
    {
        ll n,m;
        cin>>n>>m;
        V w(n+1);
        rep(i,1,n+1)
        cin>>w[i];
        
        priority_queue<pll,Vpll,greater<pll>>pq;

        V s(n+1,0);
        Vpll v2(m+1);
        VV vec(n+1);
        rep(i,0,m)
        {
            ll a,b;
            cin>>a>>b;
            s[a]++;
            s[b]++;
            v2[i+1]=make_pair(a,b);
            vec[a].pb(i+1);
            vec[b].pb(i+1);

        }

        rep(i,1,n+1)
        {
            pq.push({s[i]-w[i],i});
        }

        rep(i,1,n+1)
        s[i]=(s[i]-w[i]);


        vector<bool>vis(n+1,false);
        V ord,ord2(m+1,-1);
        ll flg=0;
        ll cnt=0;
        while(!pq.empty())
        {
            if(cnt==m)
            break;
            pll  num1=pq.top();
            // cout<<num1.second<<" "<<num1.first<<endl;
            pq.pop();
            if(vis[num1.second])
            continue;
            if(num1.first>0)
            {
                flg=1;
                break;
            }
            else 
            {
                vis[num1.second]=true;
                ll type=num1.second;
                for(auto it:vec[type])
                {
                    // cout<<it<<" ";
                    if(ord2[it]==-1)
                    {
                       ord.pb(it);
                       ord2[it]=1;
                       cnt++;
                       ll a=v2[it].first;
                       ll b=v2[it].second;
                       if(!vis[a])
                       {
                           s[a]=s[a]-1;
                           pq.push({s[a],a});
                       }
                       else if(!vis[b])
                       {
                           s[b]=s[b]-1;
                            pq.push({s[b],b});
                       }
                    }
                }
                // cout<<endl;
            }
        }

        if(flg==1)
        {
            cout<<"DEAD"<<endl;
        }
        else 
        {
            cout<<"ALIVE";
            reverse(all(ord));
            cout<<endl;
            errA(ord);

        }


    }

}