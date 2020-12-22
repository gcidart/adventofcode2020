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


void copyl(list<ll> &a, list<ll> &b)
{
	int sza = sz(a);
	for(int i =0; i<sza; i++)
	{
		b.pb(a.front());
		a.pb(a.front());
		a.pop_front();
	}
}


int subgame(list<ll> &a, list<ll> &b, int num)
{
	


	unordered_set<string> seen;
	while(sz(a) > 0 && sz(b) > 0)
	{
		string key="";
		int sza = sz(a);
		int szb = sz(b);
		for(int i=0; i<sza; i++)
		{
			char c = 'A' + a.front();
			key+=c;
			a.push_back(a.front());
			a.pop_front();
		}
		key+="#";
		for(int i=0; i<szb; i++)
		{
			char c = 'A' + b.front();
			key+=c;
			b.push_back(b.front());
			b.pop_front();
		}
		
		if(seen.count(key))
		{
			return 1;
		}
		
		seen.insert(key);
		ll af = a.front();
		ll bf = b.front();
		//trace(num, af, bf);
		int winner ;
    	if(af <= (sz(a) - 1) && bf <= (sz(b) - 1))
    	{
    		int as = sz(a)-1;
    		int bs = sz(b) -1 ;
    		list<ll> ac, bc;
			copyl(a,ac);
			copyl(b,bc);
    		ac.pop_front();
    		bc.pop_front();
    		for(int i =af; i<as; i++)
    		{
    			ac.pop_back();
    		}
    		for(int i =bf; i<bs; i++)
    		{
    			bc.pop_back();
    		}
		    winner = subgame(ac, bc, num+1);
		}
		else
		{
			if(a.front()>b.front())
				winner = 1;
			else
				winner = 2;
		}

		if(winner == 1)
		{
			a.push_back(a.front());
			a.push_back(b.front());
			a.pop_front();
			b.pop_front();
		}
		else
		{
			b.push_back(b.front());
			b.push_back(a.front());
			a.pop_front();
			b.pop_front();
		}
	}
	if(sz(a) > 0)
	{
		return 1;
	}

	else
	{
		return 2;
	}
}





int main()

{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T=1;
	
	for(int tc=1; tc<=T;tc++)
	{
	    int n;
        cin>>n;
		list<ll> a;
		list<ll> b;
		for(int i =0; i<n; i++)
		{
			ll temp;
			cin>>temp;
			a.push_back(temp);
		}
		cin>>n;
		for(int i =0; i<n; i++)
		{
			ll temp;
			cin>>temp;
			b.push_back(temp);
		}
		int winner = subgame(a, b,1);
		
		ll ans = 0;
		int i = 1;
		trace(winner, sz(a), sz(b));
		if(winner==2)
		{
			while(sz(b)!=0)
			{
				ans+= i*b.back();
				b.pop_back();
				i++;
			}
		}
		else{
			while(sz(a)!=0)
			{
				ans+= i*a.back();
				a.pop_back();
				i++;
			}
		}
		trace(ans);
	}
  
 
 
	return 0;
}
 
 
