#include<bits/stdc++.h>
#include<sstream>
using namespace std;
#define ll long long
#define ld long double
 
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fb(i,a,b) for(ll i=a;i>=b;i--)
 
#define mp make_pair
#define pb push_back
 
#define ft first
#define sd second
 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
#define pll pair<ll,ll>
#define V vector<ll>
#define S set<ll>
#define VV vector<V> 
 
const ll N = 100005;
const ll M = 1000000007;
 
int main(){
	ll t;
	ll sum=0;
	cin>>t;
	while(t--){
		ll n,a,b,c,d;
		a=0;b=0;c=0;d=0;
		ll ans=0;
		cin>>n;
		vector<char>v[4];
		f(i,0,n){
			char j;
			ll z;
			cin>>j;
			cin>>z;
			ll g=z/3-1;
			v[g].pb(j);
			if(j=='A')a=1;
			else if(j=='B')b=1;
			else if(j=='C')c=1;
			else d=1;
		}
		if(a==0){
			ans-=100;
		}
		if(b==0){
			ans-=100;
		}
		if(c==0){
			ans-=100;
		}
		if(d==0){
			ans-=100;
		}
		ll ar[4][4];
		ll res=0;
		f(i,0,4){
			f(j,0,4){
				if(j==0){
					 res=count(v[i].begin(),v[i].end(),'A');
				}
				else if(j==1){
					 res=count(v[i].begin(),v[i].end(),'B');
				}
				else if(j==2){
					 res=count(v[i].begin(),v[i].end(),'C');
				}
				else if(j==3){
					 res=count(v[i].begin(),v[i].end(),'D');
				}
				ar[i][j]=res;
				//cout<<ar[i][j]<<" ";
			}
		//	cout<<endl;
		}
		ll max=-1;
		ll ind=-1;
		ll in=-1;
		f(i,0,4){
			f(j,0,4){
				if(ar[i][j]>max){
					max=ar[i][j];
					ind=i;
					in=j;
				}
			}
		}
		ans=ans+100*(max);
		f(i,0,4){
			ar[ind][i]=0;
		}
		f(i,0,4){
			ar[i][in]=0;
		}
		max=-1;
		ind=-1;
		in=-1;
		f(i,0,4){
			f(j,0,4){
				if(ar[i][j]>max){
					max=ar[i][j];
					ind=i;
					in=j;
				}
			}
		}
		ans=ans+75*(max);
		f(i,0,4){
			ar[ind][i]=0;
		}
		f(i,0,4){
			ar[i][in]=0;
		}
		max=-1;
		ind=-1;
		in=-1;
		f(i,0,4){
			f(j,0,4){
				if(ar[i][j]>max){
					max=ar[i][j];
					ind=i;
					in=j;
				}
			}
		}
		ans=ans+50*(max);
		f(i,0,4){
			ar[ind][i]=0;
		}
		f(i,0,4){
			ar[i][in]=0;
		}
		max=-1;
		ind=-1;
		in=-1;
		f(i,0,4){
			f(j,0,4){
				if(ar[i][j]>max){
					max=ar[i][j];
					ind=i;
					in=j;
				}
			}
		}
		ans=ans+25*(max);
		f(i,0,4){
			ar[ind][i]=0;
		}
		f(i,0,4){
			ar[i][in]=0;
		}
		cout<<ans<<endl;
		sum+=ans;
	}
	cout<<sum<<endl;
}