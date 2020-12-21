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
#define PI 3.14159265
unordered_map<string, int> ing;
unordered_map<string, int> allergens;
unordered_map<int, string> rev_all_map;
vector<vector<string> > arr_ing;
vector<vector<string> > arr_all;
vector<int> arr_bm;
unordered_map<int, set<string> > all_ing_map;
unordered_set<string> ingredients_set;
map<string, string> ing_with_allergens;
int cnt = 0;
int main()

{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T=1;
	
	for(int tc=1; tc<=T;tc++)
	{
	    int n;
        cin>>n;
		arr_ing.resize(n);
		arr_all.resize(n);
		for(int i =0; i<n; i++)
		{
			string temp;
			cin>>temp;
			while(temp!="contains")
			{
				ing[temp]++;
				ingredients_set.insert(temp);
				arr_ing[i].pb(temp);
				cin>>temp;
			}
			cin>>temp;
			while(temp!="$$$")
			{
				if(!allergens.count(temp))
				{
					rev_all_map[cnt] = temp;
					allergens[temp] = cnt++;
				}
				arr_all[i].pb(temp);
				//allergens.insert(temp);
				cin>>temp;
			}
		}
		for(auto x:allergens)
		{
			trace(x.first, x.second);
		}
		for(int i =0; i<n;i++)
		{
			int bitmask = 0;
			for(auto x: arr_all[i])
			{
				int cnti = allergens[x];
				for(auto y:arr_ing[i])
				{
					all_ing_map[cnti].insert(y);
				}
				bitmask |= 1<<cnti;
			}
			arr_bm.pb(bitmask);
			trace(i, bitmask);
		}
		for(int i = 0; i<cnt; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(arr_bm[j] & (1<<i))
				{
					vector<string> common;
					for(auto x: arr_ing[j])
					{
						if(all_ing_map[i].count(x))
						{
							common.pb(x);
						}
					}
					all_ing_map[i].clear();
					for(auto x: common)
					{
						all_ing_map[i].insert(x);
					}
					if(sz(all_ing_map[i]) ==1)
					{
						ingredients_set.erase(*all_ing_map[i].begin());
						ing_with_allergens[rev_all_map[i]] = (*all_ing_map[i].begin());
					}
				}
			}
			trace(i);
			for(auto x: all_ing_map[i])
			{
				cout<<x<<" ";
			}
			cout<<"\n";
		}
		while(true)
		{ 
			bool break_loop = true;
			for(int i =0; i<cnt;i++)
			{
				vector<string> to_erase;
				for(auto x:all_ing_map[i])
				{
					if(!ingredients_set.count(x)){
						break_loop = false;
						to_erase.pb(x);
					}
				}
				for(auto x: to_erase)
				{
					all_ing_map[i].erase(x);
				}
				if(sz(all_ing_map[i]) ==1)
				{
					ingredients_set.erase(*all_ing_map[i].begin());
					ing_with_allergens[rev_all_map[i]] = (*all_ing_map[i].begin());
				}
			}
			if(break_loop)
				break;
		}
		int ans = 0;
		for(auto x:ingredients_set)
		{
			trace(x);
			ans+= ing[x];
		}
		string dangerous_list = "";
		for(auto x: ing_with_allergens)
		{
			trace(x.first, x.second);
			dangerous_list+= x.second;
			dangerous_list+=",";
		}
		dangerous_list.pop_back();


		trace(ans, dangerous_list);
       	 





        
        

	}
  
 
 
	return 0;
}
 
 
