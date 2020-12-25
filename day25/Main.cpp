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

int get_loop_size( ll public_key)
{
    int loopsize = 0;
    ll val = 1;
    while(val!=public_key)
    {
        val*=7;
        val%=20201227;
        loopsize++;
    }
    return loopsize;
}
ll get_encryption_key(int loopsize, ll public_key)
{
    ll val = 1;
    for(int i=0; i<loopsize; i++)
    {
        val*=public_key;
        val%=20201227;
    }
    return val;
}

int main()

{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T=1;
    vvi arr(1000, vi(1000));
	for(int tc=1; tc<=T;tc++)
	{
      ll pk1, pk2;
      cin>>pk1>> pk2;
      trace(pk1, pk2);
      int ls1 = get_loop_size(pk1);
      int ls2 = get_loop_size(pk2);
      trace(ls1, ls2);
      trace(get_encryption_key(ls2, pk1));
	}
	return 0;
}
 
 
