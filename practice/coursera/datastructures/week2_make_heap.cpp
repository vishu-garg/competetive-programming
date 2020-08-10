#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;
  int n;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
   cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void shift_down(int i)
  {
      int maxIndex=i;
      int l=2*i+1;
      if(l>=n)
      return;
      if(l<n && data_[l]<data_[maxIndex])
      maxIndex=l;
      int r=2*i+2;
      if(r<n && data_[r]<data_[maxIndex])
      maxIndex=r;
      if(i!=maxIndex)
      { 
          swaps_.push_back(make_pair(i,maxIndex));
          swap(data_[i],data_[maxIndex]);
          shift_down(maxIndex);
      }
      return;
  }

  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts 
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap, 
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
    for(int i=n-1;i>=0;i--)
    {
        if((2*i+1)>=n)
        continue;
        shift_down(i);
    }
  }



 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}


// shift down operations from penultimate leaf nodes.


// shift down operations from penultimate leaf nodes.