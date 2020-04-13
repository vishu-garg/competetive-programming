// CPP Program to count the numbers 
// within a range such that number 
// can be expressed as power of some 
// other number 
#include <bits/stdc++.h> 

using namespace std; 

#define N 1000005 
#define MAX 1e18 

// Vector to store powers greater than 3 
vector<long int> powers; 

// set to store perfect squares 
set<long int> squares; 

// set to store powers other 
// than perfect squares 
set<long int> s; 

void powersPrecomputation() 
{ 
	for (long int i = 2; i < N; i++) 
	{ 
		// pushing squares 
		squares.insert(i * i); 

		// if the values is already 
		// a perfect square means 
		// present in the set 
		if (squares.find(i) != squares.end()) 
				continue; 

		long int temp = i; 

		// run loop until some 
		// power of current number 
		// doesn't exceed MAX 
		while (i * i <= MAX / temp) 
		{ 
			temp *= (i * i); 

			/* pushing only odd powers 
			as even power of a number 
			can always be expressed as 
			a perfect square which is 
			already present in set squares */
			s.insert(temp); 
		} 
	} 

	// Inserting those sorted 
	// values of set into a vector 
	for (long int x : s) 
		powers.push_back(x); 
} 

long int calculateAnswer(long int L, long int R) 
{ 
	// calculate perfect squares in 
	// range using sqrtl function 
	long int perfectSquares = floor(sqrtl(R)) - 
							floor(sqrtl(L - 1)); 

	// calculate upper value of R 
	// in vector using binary search 
	long int high = (upper_bound(powers.begin(), 
			powers.end(), R) - powers.begin()); 

	// calculate lower value of L 
	// in vector using binary search 
	long int low = (lower_bound(powers.begin(), 
			powers.end(), L) - powers.begin()); 

	// add into final answer 
	perfectSquares += (high - low); 

	return perfectSquares; 
} 

// Driver Code 
int main() 
{ 
	// precompute the powers 
	powersPrecomputation(); 

	// left value of range 
	long int L = 1; 
	
	// right value of range 
	long int R = 10; 

	cout << "Number of powers between " << L 
			<< " and " << R << " = " << 
			calculateAnswer(L, R) << endl; 

	// L = 1; 
	// R = 1000000000;

	// cout << "Number of powers between " << L 
	// 		<< " and " << R << " = " << 
	// 		calculateAnswer(L, R) << endl; 
	for(auto it : s)
	cout<<it<<" ";
	cout<<endl;

	return 0; 
} 
