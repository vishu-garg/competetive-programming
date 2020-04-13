#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
 
#define int long long
#define ld long double
 
#define rep(i,a,b) for(int i=a;i<b;i++)
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
 
const int logN = 20;
const int M = 1000000007;
const int INF = 1e12;
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

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int n;
    cin>>n;
    int m[n];
    rep(i,0,n)cin>>m[i];
    int l[n],r[n];
    int nsl[n],nsr[n];
    rep(x,0,n)
    {
        nsl[x]=-1;
        nsr[x]=-1;
    }
    set<int,greater<int> > s;
    s.insert(0);
    rep(x,1,n)
    {
//    	cout<<s.size()<<" "<<*s.begin()<<"###"<<endl;
        while(!s.empty() && m[*s.begin()]>m[x]){
            nsr[*s.begin()]=x;
//            cout<<nsr[*s.begin()]<<" ###";
            s.erase(s.begin());
        }
        s.insert(x);
    }
    s.clear();
    s.insert(n-1);
    for(int x=n-2;x>=0;x--)
    {
        while(!s.empty() && m[*s.begin()]>m[x])
        {
            nsl[*s.begin()]=x;
            s.erase(s.begin());
        }
        s.insert(x);
    }
    s.clear();
    int sl[n],sr[n];
    sl[0]=m[0];sr[n-1]=m[n-1];
    rep(x,1,n)
    {
    	if(m[x]>m[x-1])
    	sl[x]=sl[x-1]+m[x];
    	else{
//		cout<<nsl[x]<<" ";
        if(nsl[x]!=-1)
        sl[x]=sl[nsl[x]]+(x-nsl[x])*m[x];
        else 
        sl[x]=(x+1)*m[x];
    }
    }
//    cout<<" <---nsl"<<endl;

    for(int x=n-2 ; x>=0 ; x--)
    {
//    	cout<<nsr[x]<<" ";
    	if(m[x]>m[x+1])
    	sr[x]=m[x]+sr[x+1];
    	else{
        if(nsr[x]!=-1)
        sr[x]=sr[nsr[x]]+(nsr[x]-x)*m[x];
        else 
        sr[x]=(n-x)*m[x];
    }
    }
//    cout<<" <--- nsr"<<endl;
//    rep(x,0,n)
//    cout<<sl[x]<<" ";
//    cout<<" <---sl"<<endl;
//    rep(x,0,n)
//    cout<<sr[x]<<" ";
//    cout<<" <---sr"<<endl;
    int ans=0,ai=0;
    for(int x=0;x<n;x++)
    {
        if(ans<sl[x]+sr[x]-m[x]){
            ans=sl[x]+sr[x]-m[x];
            ai=x;
        }
    }
    int w=m[ai];
    for(int x=ai-1;x>=0;x--){
        m[x]=min(m[x],w);
        w=m[x];
    }
    w=m[ai];
    for(int x=ai+1;x<n;x++)
    {
        m[x]=min(m[x],w);
        w=m[x];
    }
    for(int x=0;x<n;x++)
    cout<<m[x]<<" ";
}