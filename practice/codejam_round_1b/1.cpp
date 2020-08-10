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
	cin.tie(NULL);
    ll t=1;
   cin>>t;
    for(ll cse=1;cse<=t;cse++)
    {
        char h,v;
        ll A,B;
        cin>>A>>B;
        ll a,b;
        a=abs(A);b=abs(B);
        ll xr_val;
        ll sum=a+b;
//        cout<<sum<<endl;
        ll k=0;
        while((ll)pow(2,k)-1LL<sum)
        {k++;}
        xr_val=(ll)pow(2,k)-1LL;
        ll x,y,xpy;
        xpy=(xr_val-sum)/2;
//        cout<<xpy<<endl;
        ll psx=0,psy,psa,psb;
        ll flg=0;
        while(psx<=xpy)
        {
            psy=xpy-psx;
            psa=a+psx;
            psb=b+psy;
//            cout<<psx<<" "<<psy<<" "<<psa<<" "<<psb<<endl;
            ll tmp2=0,fnd=0;
			ll tmp=xr_val;
            while(tmp>0)
            {
            	ll cnt=0;
            	if((psx>>tmp2)&1)cnt++;
				if((psy>>tmp2)&1)cnt++;
				if((psa>>tmp2)&1)cnt++;
				if((psb>>tmp2)&1)cnt++;   
//				cout<<cnt<<endl;         	
            	if(cnt>1 || cnt==0)
            	{
            		fnd=1;
            		break;
				}
				tmp=tmp>>1;
				tmp2++;
			}
			if(fnd==0)
			{
				flg=1;
				break;
//				psx++;
//				continue;
			}
			psx++;
//			else 
//			break;
//            psx++;
        }
//        cout<<"here"<<endl;
        if(flg==0)
        {
            cout<<"Case #"<<cse<<": IMPOSSIBLE"<<endl;
            continue;
        }
        string ans="";
        k=0;
        while(xr_val>0)
        {
            if((psx>>k)&1==1)
            ans+='W';
            else if((psa>>k)&1==1)
            ans+='E';
            else if((psy>>k)&1==1)
            ans+='S';
            else if((psb>>k)&1==1)
            ans+='N';
            k++;
            xr_val>>=1;
        }
        if(A<0)
        {
            rep(i,0,ans.length())
            {
                if(ans[i]=='E')
                ans[i]='W';
                else if(ans[i]=='W')
                ans[i]='E';
            }
        }
        if(B<0)
        {
            rep(i,0,ans.length())
            {
                if(ans[i]=='N')
                ans[i]='S';
                else if(ans[i]=='S')
                ans[i]='N';
            }
        }

        cout<<"Case #"<<cse<<": "<<ans<<endl;
	}
}