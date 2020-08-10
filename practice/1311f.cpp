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

// get and update funciton using fenwick tree!

ll get(vector<ll>&f , int pos)
{
    ll res=0;
    while(pos>=0)
    {   
        res+=f[pos];
        pos=(pos&(pos+1))-1;
        // err1(pos)<<endl;
    }
    // err1(res)<<endl;
    return res;
}

void upd(vector<ll>&f , int pos , int val)
{
    while(pos<(ll)f.size())
    {
        f[pos]+=val;
        pos=(pos|(pos+1));
    }
}

int main()
{
    fast;
    ll t=1;
//     cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<pair<int,int> >p(n);
        for(auto &pnt : p)cin>>pnt.first;
        for(auto &pnt : p)cin>>pnt.second;
        sort(all(p));

        vector<int> vs;
        for(auto pnt : p)vs.pb(pnt.second);
        sort(all(vs));
        vs.resize(unique(all(vs))-vs.begin());

        ll ans=0;
        V cnt(vs.size()),xs(vs.size());
        // cnt[i] -> kitne mile of type vs[i];
        // xs[i] -> total of indexes jahan jahan yeh vs[i] type ke element mile hein

        for(auto pnt : p)
        {
            int pos=lower_bound(all(vs),pnt.second)-vs.begin();
            // err1(pos)<<endl;
            ll tmp; // tmp mein we stored how many elements of type vs[0].....vs[pos] have been found till now i.e (cnt[0]+cnt[1]....cnt[pos]) all these will be multiplied by pnt.first and subtracetd by there index sums which is stored in xs[0]+xs[1]+....xs[pos];
            tmp=((ll)get(cnt,pos))*(pnt.first)-(get(xs,pos));
            ans+=tmp;
            upd(cnt,pos,1);
            upd(xs,pos,pnt.first);  
        }
        cout<<ans<<endl;
        return 0;
    }

}


// A  question which can be done easily using fenwick tree or may be using segemnt tree