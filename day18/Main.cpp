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
        ll ans = 0;
        for(int i =0; i< n; i++)
        {
            ll temp = 0;
            char co = '+';
            stack<string> st;
            queue<string> q;
            while(true)
            {
                string ins;
                cin>> ins;
                //trace(ins);
                if(ins=="$$$")
                {
                    break;
                }
                else if(ins=="(")
                {
                    st.push(ins);
                }
                else if(ins==")")
                {
                    while(st.top()!="(")
                    {
                        q.push(st.top());
                        st.pop();
                    }
                    st.pop();
                }
                else if(ins == "*")
                {
                    while(!st.empty() && (st.top()=="*" || st.top()=="+"))
                    {
                        q.push(st.top());
                        st.pop();
                    }
                    st.push(ins);
                }
                else if(ins == "+")
                {
                    while(!st.empty() && ( st.top()=="+"))
                    {
                        q.push(st.top());
                        st.pop();
                    }
                    st.push(ins);
                }
                else
                    q.push(ins);
            }
            while(!st.empty())
            {
                q.push(st.top());
                st.pop();
            }
            stack<ll> sll;
            while(!q.empty())
            {
                string entry1 = q.front();
                q.pop();
                ll temp = 0;
                if(entry1=="+" || entry1=="*")
                {
                    ll entry2 =  sll.top();
                    sll.pop();
                    ll entry3 =  sll.top();
                    sll.pop();
                    if(entry1=="+")
                        temp+= (entry2) + (entry3);
                    else
                        temp+= (entry2) * (entry3);
                    sll.push(temp);
                }
                else
                    sll.push(stoll(entry1));
            }

            ans += sll.top();
            //trace(sll.top());
               

                    


        }
        trace( ans);






        
        

	}
  
 
 
	return 0;
}
 
 
