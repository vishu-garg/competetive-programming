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
// const ll N=1e5+5ll;
V fen(100005,0);

void add1(ll st, ll val)
{
    while(st>0)
    {
        fen[st]+=val;
        st-=(st&(-st));
    }
}

void add2(ll st, ll val)
{
    while(st<N)
    {
        fen[st]+=val;
        st+=(st&(-st));
    }
}

ll find_bg(ll st)
{
    ll ans=0;
    while(st<N)
    {
        ans+=fen[st];
        st+=(st&(-st));
    }
}

ll find_sml(ll st)
{
    ll ans=0;
    while(st>0)
    {
        ans+=fen[st];
        st-=(st&(-st));
    }
}

int main() {
    fast;
    vector<priority_queue<int> > v(100001);
	int n,x,cur=1;
	cin>>n;
	long long ans=0;
	for(int i=0;i<n;i++)
	{
	    cin>>x;
	    v[x].push(i);
	}
	int st=-1;
	while(n>0)
	{
	    ans+=n;
	    while(n>0&&cur<=100000&&(v[cur].size()==0))
	    {
	            cur++;
	    }
	    while(st<v[cur].top())
	    {
	        int nst=v[cur].top();
	        while((v[cur].size())&&(st<v[cur].top())){ v[cur].pop(); n--;}
	        st=nst;
	        while(n>0&&cur<=100000&&(v[cur].size()==0))
	        {
	            cur++;
	        }
	    }
	    st=-1;
	}
	cout<<ans;
	return 0;
}