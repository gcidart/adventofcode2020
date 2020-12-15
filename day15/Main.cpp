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
vector<int> mask1, mask0, maskx;
map<ll, ll> umii;
void addm(ll address, ll value){
    for(auto b:mask1)
    {
        address |= (1LL<<b);
        if(b>35)
            return ;
    }
    set<ll > faddr;
    set<int> smx(all(maskx));
    int bit0 = address & 1;
    if(smx.count(0))
    {
        faddr.insert(0);
        faddr.insert(1);
    }
    else
    {
        faddr.insert(bit0);
    }
    for(int i =1; i<36; i++)
    {
        set<ll> tfaddr;
        ll biti = address & (1LL<<i);
        if(smx.count(i))
        {
            for(auto addr:faddr)
            {
                tfaddr.insert(addr);
                tfaddr.insert(addr | (1LL<<i));
            }
        }
        else if (biti==0)
        {
            for(auto addr:faddr)
            {
                tfaddr.insert(addr);
            }
        }
        else
        {
            for(auto addr:faddr)
            {
                tfaddr.insert(addr | (1LL<<i));
            }
        }
        faddr= tfaddr;
        
    }

    for (auto x: faddr)
    {
        umii[x] = value;
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
        vl arr(n);
        map<ll, ii> mlvl;
        ll last_num = -1;
        for(int i =0; i<n; i++)
        {
            cin>>arr[i];
            mlvl[arr[i]] = {-1, i+1};
            last_num = arr[i];
        }

        ll new_num = -1;
        for(int i =n+1; i<=30000000; i++)
        {
            if(mlvl[last_num].first == -1)
            {
                new_num = 0;
            }
            else
            {
                //int li = sz(mlvl[last_num]) - 1;
                new_num = mlvl[last_num].second - mlvl[last_num].first;
            }
            if(mlvl.count(new_num))
            {
                int temp = mlvl[new_num].second;
                mlvl[new_num] = {temp, i};
            }
            else
                mlvl[new_num] = {-1, i};
            last_num = new_num;
            //trace(i, new_num);
        }
        trace(new_num);


        
        

	}
  
 
 
	return 0;
}
 
 
