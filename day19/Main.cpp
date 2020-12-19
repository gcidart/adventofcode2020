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
int len42;
bool chk8(string &s, map<int, set<string>> &done)
{
    bool chk = true;
    int idx = 0;
    while(idx<sz(s))
    {
        if(!done[42].count(s.substr(idx, len42)))
            return false;
        idx+=len42;
    }
    return true;
}
bool chk11(string &s, map<int, set<string>> &done)
{
    if(sz(s) < 2*len42)
        return false;
    if(done[42].count(s.substr(0, len42)) && done[31].count(s.substr(sz(s)-len42,len42)))
    {
        int remlen = sz(s) - 2*len42;
        if(remlen==0)
            return true;
        string ss = s.substr(len42, remlen);
        return chk11(ss, done);
    }
    else
        return false;
    
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
        map<int, set<string>> done;
        int num;
        string s;
        cin>>num>>s;
        done[num].insert(s);
        cin>>s;
        cin>>num>>s;
        done[num].insert(s);
        cin>>s;
        map<int, vvi> rules;
        for(int i =2; i< n; i++)
        {
            cin>>num;
            string temp;
            vi temp_arr;

            while(true)
            {
                cin>>temp;
                if(temp=="|")
                {
                    rules[num].pb(temp_arr);
                    
                    temp_arr.clear();
                }
                else if(temp=="$$$")
                {
                    rules[num].pb(temp_arr);
                    if(num==0)
                    {
                        trace(rules[num].back()[0], rules[num].back()[1], sz(rules[num]));
                    }

                    temp_arr.clear();
                    
                    break;
                }
                else
                {
                    temp_arr.pb(stoi(temp));
                    if(num==0)
                    {
                        trace(temp_arr.back());
                    }
                }
            }
           
        }
        while(true)
        {
            bool break_loop = true;
            vi rules_to_delete;
            for(auto x: rules)
            {
                int key = x.first;
                vvi l = x.second;
                bool chk = true;
                //trace(key);
                for(auto ele : l)
                {
                    for(auto e: ele)
                    {
                        if(!done.count(e))
                        {
                            chk = false;
                            break;
                        }
                    }
                }
                if(chk)
                {
                    break_loop = false;
                    for(auto ele : l)
                    {
                        if(sz(ele)==1)
                        {
                            for(auto s1:done[ele[0]])
                            {
                                string si=s1;
                                done[key].insert(si);
                            }
                        }
                        else if (sz(ele)==2)
                        {
                            for(auto s1: done[ele[0]])
                            {
                                for(auto s2: done[ele[1]])
                                {
                                    string si = s1+s2;
                                    done[key].insert(si);
                                }
                            }
                        }
                        else
                        {
                            for(auto s1: done[ele[0]])
                            {
                                for(auto s2: done[ele[1]])
                                {
                                    for(auto s3: done[ele[2]])
                                    {
                                        string si = s1+s2+s3;
                                        done[key].insert(si);
                                    }
                                }
                            }
                        }
    
                    }
                    trace(key, sz(done));
                    rules_to_delete.pb(key);
                    
                }
            }
            for(int key:rules_to_delete)
                rules.erase(key);
            if(break_loop)
                break;
        }
        for(auto s: done[42])
        {
            trace(42, s);
            len42 = sz(s);
        }
        for(auto s: done[31])
        {
            trace(31, s);
        }

        int m;
        cin>> m;
        int ans = 0,ans2=0, ans3 = 0;
        for(int i =0; i<m; i++)
        {
            string cs;
            cin>>cs;
            if(done[0].count(cs))
            {
                ans++;
                //trace(cs);
            }
            int csl = sz(cs);
            int uni = csl/len42;
            for(int j = 1; j< uni-1; j++)
            {
                string ss1 = cs.substr(0, len42*j);
                string ss2 = cs.substr( len42*j);
                if(chk8(ss1, done) && chk11(ss2, done))
                {
                    ans2++;
                    break;
                }
            }
            
            

            
        }


                    


        trace( ans, ans2);






        
        

	}
  
 
 
	return 0;
}
 
 
