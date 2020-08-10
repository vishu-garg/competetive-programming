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



long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}
void minMaxValue(vector< vector<long long> > & minValues, vector< vector<long long> > & maxValues, const vector<char> &op, int start, int end){
    
    long long min  = 1000000000;
    long long max = -1000000000;
    for (int i = start; i < end; ++i) {
        
        long long m1 = eval(maxValues[start][i] , maxValues[i+1][end] ,op[i]);
        long long m2 = eval(maxValues[start][i] , minValues[i+1][end] ,op[i]);
        long long m3 = eval(minValues[start][i] , maxValues[i+1][end] ,op[i]);
        long long m4 = eval(minValues[start][i] , minValues[i+1][end] ,op[i]);
        long long curr_min = std::min(m1,std::min(m2,std::min(m3,m4)));
        long long curr_max = std::max(m1,std::max(m2,std::max(m3,m4)));

        min = std::min(min,curr_min);
        max = std::max(max,curr_max);
    }
    
    minValues[start][end] = min;
    maxValues[start][end] = max;
}
long long get_max_value(const vector<int> & digits, const vector<char> &op, int start, int end){
    
    vector< vector<long long> > minValues(digits.size(),vector<long long>(digits.size(),0));
    vector< vector<long long> > maxValues(digits.size(),vector<long long>(digits.size(),0));
    int expLength = end - start;
    //initialize values
    for (int i = 0; i < digits.size(); ++i) {
        minValues[i][i] = digits[i];
        maxValues[i][i] = digits[i];
    }
    
    for(int s = 1; s <= expLength; ++s){
        for(int i = 0; i < digits.size() - s ; ++i ){
            int j = i + s;
            minMaxValue(minValues,maxValues,op,i,j);
        }
    }
    
    return maxValues[start][end];
}
long long get_maximum_value(const string &exp) {
    //parse input
    vector<char> op;
    vector<int> digits;
    for (int i = 0; i  < exp.length(); ++i) {
        if( i % 2 == 0)
            digits.push_back(exp[i] - '0');
        else
            op.push_back(exp[i]);
    }

    //DP algorithm for computing max value of an expression
    return get_max_value(digits,op,0,digits.size()-1);
}

int main() {
  string s;
  cin >> s;
  cout << get_maximum_value(s) << '\n';
}