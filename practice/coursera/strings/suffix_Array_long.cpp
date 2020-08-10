#include<bits/stdc++.h>
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

void sort_char(const string& text , vector<int>& order){
    vector<int>c_f(5,0);
    for(int i=0;i<text.size();i++)
    {
        if(text[i]=='$')
        c_f[0]++;
        else if(text[i]=='A')
        c_f[1]++;
        else if(text[i]=='C')
        c_f[2]++;
        else if(text[i]=='G')
        c_f[3]++;
        else if(text[i]=='T')
        c_f[4]++;
    }
    for(int i=1;i<5;i++)
    c_f[i]+=c_f[i-1];
    for(int i=text.size()-1;i>=0;i--)
    {
        if(text[i]=='$')
        {
            c_f[0]--;
            order[c_f[0]]=i;
        }
        else if(text[i]=='A')
        {
            c_f[1]--;
            order[c_f[1]]=i;
        }
        else if(text[i]=='C')
        {
            c_f[2]--;
            order[c_f[2]]=i;
        }
        else if(text[i]=='G')
        {
            c_f[3]--;
            order[c_f[3]]=i;
        }
        else if(text[i]=='T')
        {
            c_f[4]--;
            order[c_f[4]]=i;
        }
    }
}

void compute_class(const string& text, vector<int>& order, vector<int>& sort_class){
    int count=0;
    sort_class[order[0]]=0;
    for(int i=1;i<order.size();i++)
    {
        if(text[order[i]]==text[order[i-1]])
        sort_class[order[i]]=count;
        else 
        sort_class[order[i]]=++count;
    }
}

vector<int> sort_double(const string &text, int l, vector<int>& order , vector<int>& sort_class)
{
    vector<int> new_order(text.size(),0);
    vector<int> c_f(text.size(),0);
    // cout<<order.size()<<"<--"<<endl;
    for(int i=0;i<order.size();i++)
    {
        c_f[sort_class[i]]++;
    }
    for(int i=1;i<c_f.size();i++){
        c_f[i]+=c_f[i-1];
    }
    for(int i=order.size()-1;i>=0;i--)
    {
        int start=(order[i]-l+order.size())%order.size();
        new_order[--c_f[sort_class[start]]]=start;
    }
 

    order.clear();
    return new_order;
}

vector<int> update_class(vector<int>& order,vector<int> &sort_class,int l)
{
    vector<int> new_sort_class(order.size());
    int cnt=0;
    new_sort_class[order[0]]=cnt;
    for(int i=1;i<order.size();i++)
    {
        int cur=order[i];
        int cur_mid=(order[i]+l)%order.size();
        int prev=order[i-1];
        int prev_mid=(order[i-1]+l)%order.size();
        if(sort_class[cur]!=sort_class[prev] || sort_class[cur_mid]!=sort_class[prev_mid]){
            new_sort_class[cur]=++cnt;
        }
        else 
        new_sort_class[cur]=cnt;
    }
    sort_class.clear();
    return new_sort_class;
}

vector<int> BuildSuffixArray(const string& text) {
  vector<int>order(text.size());
  sort_char(text , order);
  vector<int> sort_class(text.size());
  compute_class(text,order,sort_class);
//   cout<<text.size()<<endl;
  for(int L=1;L<=text.size();L*=2){
      order=sort_double(text,L,order,sort_class);
    //   cout<<order.size()<<endl;
    //   for(int i=0;i<order.size();i++)
    //   {
    //       cout<<order[i]<<" ";
    //   }
    //   cout<<endl;
      sort_class=update_class(order,sort_class,L);
  }

  return order;
}

int main() {
  string text;
  cin >> text;
  vector<int> suffix_array = BuildSuffixArray(text);
  for (int i = 0; i < suffix_array.size(); ++i) {
    cout << suffix_array[i] << ' ';
  }
  cout << endl;
  return 0;
}
