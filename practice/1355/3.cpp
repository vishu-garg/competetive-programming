#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
 
#define ll long long
#define ld long double
 
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
 
#define err() cout<<"=================================="<<endl;
#define err1(a) cout<<#a<<" "<<a<<endl

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

ll my_algo(ll a,ll b, ll c, ll d)
{
    ll ans=0;
        ll lmt=d+1;
//        cout<<lmt<<endl;
        repb(z,lmt,c+1)
        {
//        	if(lmt>d)
//        	{
//        		ans+=d-c+1;
//        		continue;
//			}
            ll min_a=(z-c);
            if(min_a>b)
            continue;
            ll min_b=(z-b);
            ll tmp=0;
            if(min_b>c)
            continue;
//            cout<<z<<" "<<min_a<<" "<<min_b<<"<--"<<endl; 
            ll b1=c-min_b+1;
            ll a2=b-min_a+1;
//            cout<<b1<<" "<<a2<<endl;
//            if(z==12)
//            cout<<b1<<" "<<a2<<endl;
//			cout<<b1<<" "<<a2<<endl;
            tmp+=(a2*(a2+1))/2;
            ll chk=0;
			if(b1>(c-b+1))
            {
            	ll rem=b1-c+b-1;
            	if(rem>(b-a+1))
            	{
            		chk=1;
            		tmp-=((b-a+1)*(b-a+2))/2;
            		tmp-=(rem-(b-a+1))*(b-a+1);
				}
				else
//            	err1(rem)<<endl;
            	tmp-=(((rem)*(rem+1))/2);
			}
			if(a2>(b-a+1))
			{
				ll rem=a2-b+a-1;
				if(rem>(c-b+1) && chk==0)
            	{
            		chk=1;
            		tmp-=((c-b+1)*(c-b+2))/2;
            		tmp-=(rem-(c-b+1))*(c-b+1);
				}
				else
//				err1(rem)<<endl;
            	tmp-=(((rem)*(rem+1))/2);
			}
            // cout<<z<<" "<<num<<"<---"<<endl;
            // ll tmp2=(num*(num+1))/2; 
            // tmp+=tmp2;
//            cout<<tmp<<endl;
            ans+=tmp;
//            cout<<z<<" "<<tmp<<"<---"<<endl;
            // cout<<z<<" "<<tmp<<" <--"<<endl;
        }
//        cout<<ans<<endl;
        return ans;
}

int main()
{
    fast;
    ll T=1;
    // cin>>T;
    while(T--)
    {
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
//        srand(time(0));
//        ll num[4]={0};
//        rep(i,0,4)
//        while(num[i]<1 || num[i]>20)
//        {num[i]=rand();num[i]%=20;}
//		
////		cout<<num[0]<<endl;
//        sort(num,num+4);
//        a=num[0];b=num[1];c=num[2];d=num[3];
//        ll ans=0;
//        rep(x,a,b+1)
//        {
//            rep(y,b,c+1)
//            {
//                rep(z,c,d+1)
//                {
//                    if(x+y>z && x+z>y && y+z>x)
//                    ans++;
//                }
//            }
//        }

        ll ans2=my_algo(a,b,c,d);
        cout<<ans2<<endl;
//        if(ans!=ans2)
//        {
//            cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
//            cout<<ans<<" "<<ans2<<endl;
//            break;
//        }
//        else 
//        {
//        	cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
//            cout<<ans<<" "<<ans2<<endl;
//		}
// break;       

    }

}