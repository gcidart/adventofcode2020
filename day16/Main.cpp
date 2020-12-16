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

int main()

{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T=1;
    	
	
	
	for(int tc=1; tc<=T;tc++)
	{
	    int n;
        cin>>n;
        vvi rules(n, vi(4));
        for(int i =0; i<n; i++)
        {
            string temp;
            cin>> temp;
            cin>>rules[i][0]>>rules[i][1]>>rules[i][2]>>rules[i][3];
        }
        ll ans = 0;
        vector<int> my_ticket(n);
        for(int i =0; i<n; i++)
        {
            int temp = 0;
            cin>>my_ticket[i];
        }
        int m;
        cin>>m; 
        vvi valid_tickets;
        vi mask(n, (1<<n)-1);
        for(int i =0; i<m; i++)
        {
            bool valid = true;
            vector<int> tarr;

            for(int j =0; j<n; j++)
            {
                int temp;
                cin>>temp;
                tarr.pb(temp);
                bool chk = false;
                for(int k=0; k<n; k++)
                {
                    if((temp>= rules[k][0] && temp <= rules[k][1]) || (temp>= rules[k][2] && temp <= rules[k][3]) )
                    {
                        chk = true;
                    
                    }
                    
                }
                //trace(i, j, temp, chk);
                if(!chk)
                {
                    ans+=temp;
                    valid = false;
                }
            }
            if(valid)
            {
                valid_tickets.pb(tarr);
                bool chk = false;
                for(int j=0; j<n; j++)
                {
                    int temp = tarr[j];
                    for(int k=0; k<n; k++)
                    {
                        if((temp>= rules[k][0] && temp <= rules[k][1]) || (temp>= rules[k][2] && temp <= rules[k][3]) )
                        {
                            chk = true;
                    
                        }
                        else
                        {
                            mask[j] &= ~(1<<k);
                        }
                    }
                }
                

                
            }

        }
        trace(sz(valid_tickets));
        trace(ans);
        int i =0;
        vector<set<int> > sol_mask(n);
        map<int, int> final_map;
        for(auto x:mask)
        {
            cout<<i<<" "<<x<<" : ";
            int k =0;
            for(int j =0; j<n; j++)
            {
                int y = x &(1<<j);
                if(y !=0)
                {
                    cout<<j<<",";
                    k++;
                    sol_mask[i].insert(j);
                }
            }
            i++;
            cout<<"=============="<<k<<"\n";
        }
        
        while(true)
        {
            int next_ans = -1;
            bool break_loop = true;
            for(int i =0; i<n; i++)
            {
                if(sz(sol_mask[i])==1)
                {
                    final_map[*sol_mask[i].begin()] = i;
                    next_ans = *sol_mask[i].begin();
                    trace(i, next_ans);
                    break_loop = false;
                }
            }
            for(int i =0; i<n; i++)
            {
                sol_mask[i].erase(next_ans);
            }
            if(break_loop)
                break;
        }
        for(auto x: final_map)
        {
            trace(x.first, x.second);
        }
        ll ans2 = 1;
        for(int i =0; i<6;i++)
            ans2*= my_ticket[final_map[i]];
        trace(ans2);






        
        

	}
  
 
 
	return 0;
}
 
 
