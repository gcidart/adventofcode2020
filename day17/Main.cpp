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

int arr[21][21][21][21];
int temp[21][21][21][21];
int main()

{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T=1;
    	
	
    memset(arr, 0, sizeof(arr[0][0][0][0]) * 21 * 21 *21*21);
	for(int tc=1; tc<=T;tc++)
	{
	    int n, m;
        cin>>n;
        int xx = 10 - n/2,  zz = 10, aa= 10; 
        for(int i =0; i<n; i++)
        {
            string temp;

            cin>>temp;
            m = sz(temp);
            int yy = 10-m/2;
            for(int j = 0; j<m; j++)
            {
                if(temp[j]=='#')
                    arr[xx][yy][zz][aa] = 1;
                yy++;
            }
            xx++;

        }
        for(int t =0; t< 6; t++)
        {
            memset(temp, 0, sizeof(temp[0][0][0][0]) * 21 * 21 *21*21);
            for(int i =0; i<21; i++)
            {
                for(int j =0; j<21; j++)
                {
                    
                    for(int k =0; k<21; k++)
                    {
                        for(int l=0; l<21; l++)
                        {
                            int cnt = 0;
                            int x  ;
                            int y ;
                            int z;
                            int w;
                            for(int a = -1; a<=1; a++)
                            {
                                for(int b = -1; b<=1; b++)
                                {
                                    for(int c = -1; c<=1; c++)
                                    {
                                        for(int d = -1; d<=1; d++)
                                        {
                                            if(a==0 && b==0 && c==0 && d==0)
                                                continue;
                                            x = i+a;
                                            y= j+b; 
                                            z = k+c;
                                            w = l+d;
                                            if(x>=0 && y>=0 && z>=0 && w>=0 && x< 21 && y<21 && z< 21&& w<21&& arr[x][y][z][w]==1)
                                                cnt++;
                                        }
                                    }
                                }
                            }
                            if(arr[i][j][k][l] ==1)
                            {
                                if(cnt==2|| cnt==3)
                                    temp[i][j][k][l] = 1;
                                else
                                    temp[i][j][k][l] = 0;
                            }
                            else
                            {
                                if(cnt==3)
                                    temp[i][j][k][l] = 1;
                                else
                                    temp[i][j][k][l] = 0;
                            }
                        }
                    }
                    
                }
            }
            int ans = 0;
            for(int i =0; i<21; i++)
            {
                for(int j =0; j<21; j++)
                {
                    for(int k=0; k<21; k++)
                    {
                        for(int l=0; l<21; l++)
                        {
                        arr[i][j][k][l] = temp[i][j][k][l];
                        if(arr[i][j][k][l]==1)
                            ans++;
                        }
                    }
                }
            }
            trace(ans);

        }






        
        

	}
  
 
 
	return 0;
}
 
 
