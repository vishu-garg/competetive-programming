#include<bits/stdc++.h>
#include <algorithm>


using namespace std;

#define ll long long

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void shift_down(ll ind , vector<pair<ll,ll> >&v)
  {
      ll max_ind=ind;
      ll l=2*ind+1;
      if(l>=num_workers_)
      return;
      if(l<num_workers_ && v[l].first<v[max_ind].first)
      max_ind=l;
      else if(l<num_workers_ && v[l].first==v[max_ind].first && v[l].second<v[max_ind].second)
      max_ind=l;
      ll r=2*ind+2;
      if(r<num_workers_ && v[r].first<v[max_ind].first)
      max_ind=r;
      else if(r<num_workers_ && v[r].first==v[max_ind].first && v[r].second<v[max_ind].second)
      max_ind=r;
      if(max_ind!=ind)
      {
          swap(v[ind],v[max_ind]);
          shift_down(max_ind,v);
      }
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    vector<pair<ll,ll> > next_free_time(num_workers_);
    for(ll i=0;i<num_workers_;i++)
    {
        next_free_time[i]=make_pair(0,i);
    }
    for(ll i=0;i<(ll)jobs_.size();i++)
    {
        assigned_workers_[i]=next_free_time[0].second;
        start_times_[i]=next_free_time[0].first;
        next_free_time[0]=make_pair(start_times_[i]+jobs_[i],assigned_workers_[i]);
        shift_down(0,next_free_time);
    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
