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
	fast;
	ll t;
	cin>>t;
	while(t--){
	  string s;
	  cin>>s;
	  ll ans=0;
	  V v1,v2;
	  ll n=s.length();
	  ll count1=0;
	  ll count2=0;
	  if(s[0]=='1'){
	  	count2++;
	  }
	  else{
	  	count1++;
	  }
	  f(i,1,n){
	  	if(s[i]==s[i-1]){
	  		if(s[i]=='1'){
	  			count2++;
			  }
			  else{
			  	count1++;
			  }
		  }
		  else if(s[i]!=s[i-1]){
		  	if(s[i]=='1'){
		  		v1.pb(count1);
		  		count1=0;
		  		count2++;
			  }
			  else{
			  	v2.pb(count2);
			  	count2=0;
			  	count1++;
			  }
		  }
	  }
	  if(s[n-1]=='1'){
	  	v2.pb(count2);
	  	count2=0;
	  }
	  else{
	  	v1.pb(count1);
	  }
	  //cout<<v1.size();
	  /*f(i,0,v1.size()){
	  	cout<<v1[i]<<" ";
	  }cout<<endl;
	  f(i,0,v2.size()){
	  	cout<<v2[i]<<" ";
	  }cout<<endl;*/
	  if(v1.size()<=1 || v2.size()<=1){
	  	ans=0;
	  }
	  else{
	sort(v1.begin(),v1.end());
	  sort(v2.begin(),v2.end());
	  ll sum1=accumulate(v1.begin(),v1.end()-1,0);
	  ll sum2=accumulate(v2.begin(),v2.end()-1,0);
	  
	  ans=min(sum1,sum2);}
	  cout<<ans<<endl;
	  
}
}
