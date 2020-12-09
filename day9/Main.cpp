#include<bits/stdc++.h>
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define F(i,n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define VE(i,v) for(int i = 0;i < (v).size();i++)

using namespace std;
#define trace(...) cerr<<__FUNCTION__<<":"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
	cerr<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
	const char *comma=strchr(names+1,',');
	cerr.write(names,comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1,args...);
}
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned int ui;
typedef vector<ll> vl; 
typedef vector<vl> vvl; 
typedef pair<ll,ll> pll;
typedef vector<pll> vpll; 
#define MOD2 1LL<<32


	
int main()

{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T=1;
	//cin>>T;
	
	
	
	for(int tc=1; tc<=T;tc++)
	{
		int acc = 0;
        int n;
        cin>>n;
        map<ll, ll> mii;
        int pre = 25;
        vl barr(n);
        vl sbarr(n+1);
        ll ans = 0;
        bool ansf = false;
        for(int i = 0; i < pre; i++)
        {
            ll temp;
            cin>>temp;
            mii[temp]++;
            barr[i] = temp;
            sbarr[i+1] = barr[i] + sbarr[i];
        }
        for(int i = pre; i<n; i++)
        {
            ll temp ;
            cin>>temp;
            barr[i] = temp;
            sbarr[i+1] = barr[i] + sbarr[i];
            vl arr;
            for(auto x:mii)
            {
                for(int j =0; j< x.second; j++)
                    arr.pb(x.first);
            }
            bool found = false;
            for(int j =0; j<pre; j++)
            {
                for(int k=j+1; k< pre; k++)
                {
                    if(arr[j] + arr[k] == temp)
                    {
                        found = true;
                        break;
                    }
                }
            }
            if(!found)
            {
                trace(i, temp);
                if(!ansf)
                    ans = temp;
                ansf = true;
            }
            mii[temp]++;
            mii[barr[i-pre]]--;
            if(mii[barr[i-pre]]==0)
                mii.erase(barr[i-pre]);
        }
        trace(ans);
        for(int i=0; i<=n; i++)
        {
            int index = lower_bound(sbarr.begin()+i, sbarr.end(), sbarr[i]+ans) - sbarr.begin();
            if(sbarr[index] != sbarr[i] + ans)
                continue;
            if(index-i==1)
                continue;
            ll maxe = 0, mine = 1e18;
            for(int j =i; j<index; j++)
            {
                maxe = max(maxe, barr[j]);
                mine = min(mine, barr[j]);
            }
            trace(i, index, mine+maxe);
        }














		
		





		
		//cout<<"Case #"<<tc<<": "<<"NO"<<"\n";

	}
  
 
 
	return 0;
}
 
 
