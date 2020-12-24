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
    vvi arr(1000, vi(1000));
	for(int tc=1; tc<=T;tc++)
	{
       int n;
       cin>>n;
       set<ll> spii;
       for(int a =0; a<n; a++)
       {
           string s;
           cin>>s;
           int x = 500, y=500;
           int i =0;
           while(i<sz(s))
           {
               if(s[i]=='e')
               {
                   y+=2;
                   i++;
               }
               else if(s[i]=='w')
               {
                   y-=2;
                   i++;
               }
               else if(s[i]=='n')
               {
                   x+=1;
                   if(s[i+1]=='e')
                   {
                       y++;
                   }
                   else
                   {
                       y--;
                   }
                   i+=2;
               }
               else
               {
                   x-=1;
                   if(s[i+1]=='e')
                   {
                       y++;
                   }
                   else
                   {
                       y--;
                   }
                   i+=2;
               }
           }
           //trace(x,y);
           arr[x][y] = 1-arr[x][y];
           ll key = x*1e6+y;
           if(spii.count(key))
           {
               spii.erase(key);
           }
           else
           {
                spii.insert(key);
           }
       }
       
       trace( sz(spii));
       int r[6] = {0, 0 , 1, 1, -1, -1};
       int c[6] = {2, -2, 1, -1, 1, -1};
       for(int a =0; a<100; a++)
       {
           vvi temp(1000, vi(1000));
           
           for(int i = 0; i<1000; i++)
           {
               for(int j = 0; j<1000; j++)
               {
                   int cnt = 0;
                   temp[i][j] = arr[i][j];
                   for(int k=0; k<6; k++)
                   {
                       int x = i+r[k];
                       int y = j+c[k];
                       if(x>=0 && y>=0 && x<1000 && y<1000 && arr[x][y] ==1)
                       {
                           cnt++;
                       }
                   }
                   if(arr[i][j] ==1 && (cnt==0 || cnt>2))
                       temp[i][j] =0;
                   if(arr[i][j]==0 && cnt==2)
                       temp[i][j] = 1;
               }
           }
           swap(arr,temp);
           int ans2 = 0;
           for(int i=0; i<1000; i++)
           {
               for(int j=0; j< 1000; j++)
               {
                   if(arr[i][j]==1)
                       ans2++;
               }
           }
           trace(a+1, ans2);

       }







		





        
        

	}
  
 
 
	return 0;
}
 
 
