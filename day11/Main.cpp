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
	int r[8] = {-1, -1 , -1, 0, 0, 1, 1, 1};
    int c[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
	
	
	for(int tc=1; tc<=T;tc++)
	{
	    int n;
        cin>>n;
        vector<string> arr(n);
        for(int i =0; i<n; i++)
            cin>>arr[i];
        int m = sz(arr[0]);
        for(auto x: arr)
            cout<<x<<"\n";
        while (true)
        {
            int cnt = 0;
            vector<string> temp(n);
            for(int i =0; i< n; i++)
            {
                temp[i] = arr[i];
                for(int j = 0; j<m; j++)
                {
                    if(arr[i][j] == '.')
                    {
                        temp[i][j] = '.';
                        continue;
                    }
                    int tc = 0;
                    for(int a = 0; a<8; a++)
                    {
                        int x = i+r[a];
                        int y = j+c[a];
                        while(x>=0 && y >=0 && x<n && y< m)
                        {
                            if(arr[x][y] == '#')
                            {
                                tc++;
                                break;
                            }
                            else if(arr[x][y] == 'L')
                            {
                                break;
                            }
                            else
                            {
                                x+=r[a];
                                y+= c[a];
                            }
                        }
                    }
                    if(arr[i][j] == 'L' && tc == 0)
                    {
                        cnt++;
                        temp[i][j] = '#';
                    }
                    else if(arr[i][j] == '#' && tc >= 5)
                    {
                        cnt++;
                        temp[i][j] = 'L';
                    }
                    else
                        temp[i][j] = arr[i][j];
                }
            }
            trace(cnt);
            if(cnt==0)
                break;
            else{
                for(int i=0; i<n; i++)
                    arr[i] = temp[i];
            }
            for(auto x: temp)
                cout<<x<<"\n";
        }
        int ans = 0;
        for(int i =0; i<n; i++)
            for(int j =0; j<m; j++)
                if(arr[i][j]=='#')
                    ans++;
        trace(ans);









		
		





		
		//cout<<"Case #"<<tc<<": "<<"NO"<<"\n";

	}
  
 
 
	return 0;
}
 
 
