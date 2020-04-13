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
const ll M = 1000000007;
const ll INF = 1e12;
#define PI 3.14159265

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<ll> c(n);
        rep(i,0,n)
        cin>>c[i];
        set<ll>S1;
        vector<vector<ll>>v(n);
        rep(i,0,m)
        {
            ll x,y;
            cin>>x>>y;
            x--;y--;
            v[y].pb(x);
        }
        map<vector<ll>,ll>mp;
        for(ll i=0;i<n;i++)
        {
            if(v[i].empty())
            continue;
            sort(all(v[i]));    
            mp[v[i]]+=c[i];
        }
        
        ll ans=0;
        for(auto it : mp)
        {
            ans=__gcd(ans,it.second);
        }
        cout<<ans<<endl;
    }
}



/*

Alternate solution 
uses h[i], a hash function insted of vector as a key element
#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ll long long
#define ull long long
using namespace std;
ll t,n,m;
const int N=5e5+5;
long long c[N],h[N],ans;
long long v[N];
long long read() {
	ll sum=0;char s=getchar();
	while (s<'0' or s >'9')s=getchar();
	while (s>='0' and s<='9') {
		sum=sum*10+s-'0';
		s=getchar();
	}
	return sum;
}
int main() {
	srand(time(0));
	scanf("%d",&t);
	while (t--) {
		n=read(),m=read();
		ans=0;
		for (int i=1;i<=n;i++) {
			c[i]=read();h[i]=0;
			v[i]=1ll*rand()*rand()*rand()+rand();
		}
		while (m--) {
			ll x,y;
			x=read();y=read();h[y]^=v[x];
		}
		map<long long,long long> k;
		for (int i=1;i<=n;i++)if(h[i])k[h[i]]+=c[i];
		for (auto it : k)
			ans=__gcd(ans,it.second);
		printf("%lld\n",ans);
	}
	return 0;
}
*/