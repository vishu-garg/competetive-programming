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

ll pow1(ll a,ll b){
    ll res=1;
    a%=M;
    while(b>0){
        if(b&1){
        	res=(res*a)%M;
		}
        a=(a*a)%M;
        b>>=1;
    }
    return res%M;
}

int main()
{
    ll t=1;
//     cin>>t;
    while(t--)
    {
        ll s,n;
        cin>>s>>n;
        
        if(n==0)
        return 0;

        queue<ll> q;

        ll a[n],p[n];
        cin>>a[0]>>p[0];
        q.push(0);
        s--;
        ll tme=a[0]+p[0];
        ll ans[n];
        ans[0]=a[0];
        for(ll i=1;i<n;i++)
        {
            cin>>a[i]>>p[i];
            if(s==0 && a[i]<tme)
            ans[i]=-1;
            else 
            {
                if(a[i]<tme)
                {
                    q.push(i);
                    s--;
                }
                if(a[i]>=tme)
                {
//                	cout<<"#"<<endl;
                    q.pop();
                    q.push(i);
                    ll ind=q.front();
//                    err1(a[ind])<<endl;
                    ans[ind]=max(tme,a[ind]);
                    tme=ans[ind];
					tme+=p[ind];
//                    q.push(i);
                }
            }
        }
//        err1(q.size());
        while(q.size()>1)
        {
//        	err()
            q.pop();
            if(q.empty())
            break;
            ll ind=q.front();
//            cout<<tme<<" "<<a[ind]<<endl;
            ans[ind]=max(tme,a[ind]);
            tme=ans[ind]+p[ind];
        }

        rep(i,0,n)
        cout<<ans[i]<<endl;

    }

}