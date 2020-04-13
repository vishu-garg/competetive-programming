	ll n,m,k;
		cin>>n>>m>>k;
		ll b=n;
		V ans;
		ll mat[k]={0};
		while(b--){
			V v(k);
			V v1;
			ll cnt[10]={0};
			f(i,0,k){
				cin>>v[i];
				cnt[v[i]]++;
			}
			ll ind=0;
			ll ind1=0;
            ll max=0;
            ll min=M;
			f(i,0,k){
		    if(mat[i]<min){
		    	min=mat[i];
			}	
			}
			f(i,0,k){
				if(cnt[v[i]]>max && mat[i]==min){
					max=cnt[v[i]];
					ind=v[i];
				}
			}
			ans.pb(ind);
			f(i,0,k){
				if(v[i]==ind){
					mat[i]++;
				}
			}
		}
		f(i,0,n)cout<<ans[i]<<" ";
		cout<<endl;	ll n,m,k;
		cin>>n>>m>>k;
		ll b=n;
		V ans;
		ll mat[k]={0};
		while(b--){
			V v(k);
			V v1;
			ll cnt[10]={0};
			f(i,0,k){
				cin>>v[i];
				cnt[v[i]]++;
			}
			ll ind=0;
			ll ind1=0;
            ll max=0;
            ll min=M;
			f(i,0,k){
		    if(mat[i]<min){
		    	min=mat[i];
			}	
			}
			f(i,0,k){
				if(cnt[v[i]]>max && mat[i]==min){
					max=cnt[v[i]];
					ind=v[i];
				}
			}
			ans.pb(ind);
			f(i,0,k){
				if(v[i]==ind){
					mat[i]++;
				}
			}
		}
		f(i,0,n)cout<<ans[i]<<" ";
		cout<<endl;