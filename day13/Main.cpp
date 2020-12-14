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

ll power(ll x, ll y, ll m)
{
    if (y == 0) 
        return 1; 
    int p = power(x, y / 2, m) % m; 
    p = (p * p) % m; 
  
    return (y % 2 == 0) ? p : (x * p) % m; 
} 
ll modInverse(ll a, ll m)
{
    return power(a, m-2, m);
}

	
int main()

{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T=1;
	
	
	for(int tc=1; tc<=T;tc++)
	{
	    ll n;
        cin>>n;
        int ans =-1;
        ll at = 1e18;
        vl arr;
        while(true)
        {
            ll  temp;
            cin>>temp;
            //trace(temp);
            arr.pb(temp);
            if(temp==-1)
                continue;
            if(temp==-100)
                break;
            ll a = n%temp;
            a = temp-a;
            if(a<at)
            {
                at = a;
                ans = temp;
            }
            //trace(temp, a, at, ans);
            
        }
        trace(at*ans);
        //https://cp-algorithms.com/algebra/chinese-remainder-theorem.html
        vl p;
        vl a;
        for(int i=0; i<sz(arr); i++)
        {
            if(arr[i]<0)
                continue;
            ll t = arr[i]-i;
            while(t<0)
                t+=arr[i];
            a.pb(t);
            p.pb(arr[i]);
            trace(i,p.back(), a.back());
        }
        vl x(sz(p)+1);
        int k = p.size();
        for (int i = 0; i < k; ++i) {
            x[i] = a[i];
            for (int j = 0; j < i; ++j) {
                x[i] = modInverse(p[j], p[i]) * (x[i] - x[j]);

                x[i] = x[i] % p[i];
                if (x[i] < 0)
                    x[i] += p[i];
            }
            trace(i, x[i]);
        }
        ll ans2 = 0;
        ll  prod =1;
        for(int i =0; i<k ; i++)
        {
            ans2+= x[i]*prod;
            prod*= p[i];
        }
        trace(ans2);
        


        
        










		
		





		
		//cout<<"Case #"<<tc<<": "<<"NO"<<"\n";

	}
  
 
 
	return 0;
}
 
 
