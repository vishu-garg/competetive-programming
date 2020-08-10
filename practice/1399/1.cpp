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




map<pll,ll>mp;
vector<vector<pair<ll,ll>>> adj;
ll n,s;
priority_queue<pair<pll,ll>>pq1,pq2;


int dfs(ll s, ll prv)
{
    if(adj[s].size()==1 && s!=1)
    {
        return 1;
    }
    // err2(s,prv);
    ll tot=0;
    for(auto it:adj[s])
    {
        if(it.first!=prv)
        {
            ll cnt=0;
            cnt=dfs(it.first,s);
            tot+=cnt;
            // err3(s,it.first,cnt);
            mp[{s,it.first}]+=cnt;
        }
    }
    return tot;
}

int main()
{
    // fast;

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    
    ll T=1;
    cin>>T;
    while(T--)
    {
        cin>>n>>s;


        // err();
        map<pll,pll>mp2;

        adj=vector<Vpll>(n+2);

        rep(i,0,n-1)
        {
            ll u,v,w,cst;
            cin>>u>>v>>w>>cst;

            // err3(u,v,w);

            // cout<<adj.size();

            adj[u].pb({v,w});
            adj[v].pb({u,w});

            mp2[{u,v}]=make_pair(w,cst);
            mp2[{v,u}]=make_pair(w,cst);


        }

        // err();

        

        dfs(1,0);

        // err();

        ll cnt=0;
        ll sum=0;
        for(auto it:mp)
        {
            ll u=it.first.first,v=it.first.second;
            ll w=mp2[{u,v}].first;
            ll cst=mp2[{u,v}].second;
            ll w2=w*it.second;
            ll delta=(w2-((w/2)*it.second));
            if(cst==1)
            pq1.push({{delta,w/2},it.second});
            if(cst==2)
            pq2.push({{delta,w/2},it.second});
            sum+=w2;
            // err4(u,v,w,w2);
            // err2(sum,it.second);
        }

        // cout<<sum;

        vector<ll>cst1,cst2;

        cst1.pb(0);
        cst2.pb(0);

        ll prv1=0,prv2=0;

        while(!pq1.empty())
        {

            pair<pll,ll>p1=pq1.top();
            pq1.pop();

            prv1+=(p1.first.first);

            cst1.pb(prv1);

            // err3(p1.first.first,p1.first.second,p1.second);

            // cout<<sum<<endl;

            ll new_val=(p1.first.second)/2;

            // cout<<new_val<<"<=="<<endl;

            ll new_delta=((p1.first.second*p1.second)-((new_val)*p1.second));

            // sum+=new_w;

            // cout<<sum<<endl;
            if(new_delta!=0)
            pq1.push({{new_delta,new_val},p1.second});

            cnt++;

        }

        while(!pq2.empty())
        {

            pair<pll,ll>p1=pq2.top();
            pq2.pop();

            prv2+=(p1.first.first);

            cst2.pb(prv2);

            // err3(p1.first.first,p1.first.second,p1.second);

            // cout<<sum<<endl;

            ll new_val=(p1.first.second)/2;

            // cout<<new_val<<"<=="<<endl;

            ll new_delta=((p1.first.second*p1.second)-((new_val)*p1.second));

            // sum+=new_w;

            // cout<<sum<<endl;
            if(new_delta!=0)
            pq2.push({{new_delta,new_val},p1.second});

            cnt++;

        }


        ll ans=LLONG_MAX;

        if(cst2.back()>=(sum-s))
        ans=(lower_bound(all(cst2),(sum-s))-cst2.begin())*2;

        // errA(cst1);

        // err1(sum-s);

        for(ll i=0;i<cst1.size();i++)
        {
            ll imp=(sum-s)-(cst1[i]);
            ll ans2=(i);

            if(cst2.back()<imp)
            continue;

            if(imp==0)
            {
                ans=min(ans2,ans);
                break;
            }

            ans2+=((lower_bound(all(cst2),(imp))-cst2.begin())*2);
            // err1(ans2);
            ans=min(ans,ans2);

        }

        cout<<ans<<endl;

        


        // cout<<cnt<<endl;


        while(!pq1.empty())pq1.pop();
        while(!pq2.empty())pq2.pop();

        // err();
        
        mp.clear();

        // err();

        

        




        
        
        



    }

}