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
        double x = 0, y = 0, degree = 90;
        double wpx = 10, wpy = 1;
        for(int i =0; i<n; i++)
        {
            string temp ;
            cin>>temp;
            char d = temp[0];
            int num  = stoi(temp.substr(1));
            if(d=='N')
            {
                wpy+=num;
            }
            else if(d=='S')
            {
                wpy-=num;
            }
            else if(d=='E')
                wpx+=num;
            else if(d=='W')
                wpx-=num;
            else if(d=='R')
            {
                degree -= num;
                {
                    if(num==90)
                    {
                        ll z = wpx;
                        wpx = wpy;
                        wpy = -z;
                    }
                    else if(num==180)
                    {
                        ll z = wpx;
                        wpx = -wpx;
                        wpy = -wpy;
                    }
                    else
                    {
                        ll z = wpx;
                        wpx = -wpy;
                        wpy = z;
                    }
                }
                


            }
            else if(d=='L')
            {
                degree += num;
                if(num==90)
                    {
                        ll z = wpx;
                        wpx = -wpy;
                        wpy = z;
                    }
                    else if(num==180)
                    {
                        ll z = wpx;
                        wpx = -wpx;
                        wpy = -wpy;
                    }
                    else
                    {
                        ll z = wpx;
                        wpx = wpy;
                        wpy = -z;
                    }
            }
            else if(d=='F')
            {
                
                x+=wpx*num;
                y+=wpy*num;

                /*if(degree>=0 && degree <=90)
                {
                    double d = 90.0 - degree;
                    x+=num*cos(d *PI/180.0);
                    y+=num*sin(d *PI/180.0);
                }
                else if(degree > 90 && degree<= 180)
                {
                    double d = degree - 90.0;
                    x+=num*cos(d *PI/180.0);
                    y-=num*sin(d *PI/180.0);
                }
                else if(degree > 180 && degree<= 270)
                {
                    double d = 270-degree ;
                    x-=num*cos(d *PI/180.0);
                    y-=num*sin(d *PI/180.0);
                }
                else
                {
                    double d = degree - 270 ;
                    x-=num*cos(d *PI/180.0);
                    y+=num*sin(d *PI/180.0);
                }*/
            }

            trace(d, num, x, y, wpx, wpy);
        }
        trace(abs(x) + abs(y));
        










		
		





		
		//cout<<"Case #"<<tc<<": "<<"NO"<<"\n";

	}
  
 
 
	return 0;
}
 
 
