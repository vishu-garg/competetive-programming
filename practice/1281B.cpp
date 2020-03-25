#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
	int t;
	cin >> t;
	while(t--){	
	string a,b;
	cin >> a >> b;
	for(int i=0;i<a.length();i++){
		int c=i;
		for(int j=a.length()-1;j>i;j--){
			if(a[j]<a[c])
				c=j;
		}
		if(c!=i){
			swap(a[i],a[c]);
			break;
		}
	}
	if(a<b)
		cout << a << endl;
	else
		cout << "---\n";		
	}
}