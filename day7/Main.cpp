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

map<string, vector<pair<string, int> > > mspsi;
map<string, vector<pair<string, int> > > adj;
set<string> ss;
int dfs(string u)
{
    int ret = 0;
    for(auto v:mspsi[u])
    {
        ret+= dfs(v.first);
        ss.insert(v.first);
    }
    if(sz(mspsi[u])==0)
        return 1;
    return ret;
}

long long dfs2(string u)
{
    ll ret = 0;
    
    for(auto v:adj[u])
    {
        long long qty = v.second;
        ll tret= qty*(1+dfs2(v.first));
        //trace(u, v.first, v.second, tret);
        ret+= tret;
    }
   return ret;
}
	
int main()

{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T=1;
	//cin>>T;
	
	
	
	for(int tc=1; tc<=T;tc++)
	{
		int ans = 0;
		int n;
        cin>>n;
        
        for(int line =0; line < n; line++)
        {
            string temp1, temp2;
            cin>>temp1>>temp2;
            string key = temp1 + "_" + temp2;
            cin >> temp1;

            while(true)
            {
                string temp;
                cin>> temp;
                if(temp=="$$$")
                    break;
                cin>>temp1>>temp2;
                string value = temp1 + "_" + temp2;
                //trace(key, value, temp);
                mspsi[value].pb( {key, stoi(temp)});
                adj[key].pb( {value, stoi(temp)});
                cin>>temp;
            }
        }
        dfs("shiny_gold");
        ans = ss.size();
		cout<<ans<<"\n";
        long long ans2 =  dfs2("shiny_gold");
		cout<<ans2<<"\n";












		
		





		
		//cout<<"Case #"<<tc<<": "<<"NO"<<"\n";

	}
  
 
 
	return 0;
}
 
 
