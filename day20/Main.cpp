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
int sdim;
unordered_map<ll, vector<vector<pair<ll, int> > > >mat;
unordered_map<ll, unordered_set<ll > >adj;	
unordered_set<ll> ids;
map<string, string> seqmap;
unordered_map<int, vector<string> > mivsr;
unordered_map<int, vector<string> > mivsc;
bool chkr(string &a, string &b)
{
	int s = sz(a);
	for(int i =0; i<s; i++)
	{
		if(a[i] != b[s-1-i])
			return false;
	}
	return true;

}

void reflectv(vector<string> &arr)
{
	for(int i=0; i<sz(arr); i++)
	{
		for(int j =0; j<sz(arr)/2; j++)
			swap(arr[i][j], arr[i][sz(arr)-1-j]);
	}
}

void reflecth(vector<string> &arr)
{
	for(int j=0; j<sz(arr); j++)
	{
		for(int i =0; i<sz(arr)/2; i++)
			swap(arr[i][j], arr[sz(arr)-1-i][j]);
	}
}

void rotate(vector<string> &arr)
{
	for(int i =0; i<sz(arr)/2; i++)
	{
		for(int j =i; j <sz(arr)-i-1; j++)
		{
			int temp = arr[i][j];
			arr[i][j] = arr[sz(arr)-1-j][i];
			arr[sz(arr)-1-j][i] = arr[sz(arr)-1-i][sz(arr)-1-j];
			arr[sz(arr)-1-i][sz(arr)-1-j] = arr[j][sz(arr)-1-i];
			arr[j][sz(arr)-1-i] = temp;
		}
	}
}

void enseq(vi &de,  int h, int v, string seq)
{
	string keyseq;
	for(int x:de)
	{
		keyseq+= to_string(x);
		keyseq+=",";
	}
	
	if(seqmap.count(keyseq))
	{
		if(sz(seq) < sz(seqmap[keyseq]))
			seqmap[keyseq] = seq;
		return;
	}
	seqmap[keyseq] = seq;
	int temp = de[3];
	de[3] = de[2];
	de[2] = -de[1];
	de[1] = de[0];
	de[0] = -temp;
	enseq(de,h, v,  seq+"r");
	temp = de[0];
	de[0] = de[1];
	de[1] = -de[2];
	de[2] = de[3];
	de[3] = -temp;
	if(true)
	{
		swap(de[0], de[2]);
		de[1] = -de[1];
		de[3] = -de[3];
		enseq(de, 1, v, seq+"h");
		swap(de[0], de[2]);
		de[1] = -de[1];
		de[3] = -de[3];
	}
	if(true)
	{
		swap(de[1], de[3]);
		de[0] = -de[0];
		de[2] = -de[2];
		enseq(de, h, 1, seq+"v");
		swap(de[1], de[3]);
		de[0] = -de[0];
		de[2] = -de[2];
	}
	
}










void fill_corners_reduced_sea(vl &corners, vvl &idmap, vector<vector<vector<int > > > & edgemap, int mask)
{
	idmap[0][0] = corners[0];
	idmap[0][sdim-1] = corners[1];
	idmap[sdim-1][sdim-1] = corners[2];
	idmap[sdim-1][0] = corners[3];
	ll key = idmap[0][0];
	if(sz(mat[key][0])==0 && sz(mat[key][3])==0)
	{
		edgemap[0][0][1] = 2;
		edgemap[0][0][2] = 3;
		edgemap[0][0][3] = 4;
		edgemap[0][0][0] = 1;
	}
	else if(sz(mat[key][0])==0 && sz(mat[key][1])==0)
	{
		if(mask & 1)
		{
			edgemap[0][0][1] = -3;
			edgemap[0][0][2] = 4;
			edgemap[0][0][3] = -1;
			edgemap[0][0][0] = 2;
		}
		else
		{
			edgemap[0][0][1] = 4;
			edgemap[0][0][2] = -3;
			edgemap[0][0][3] = 2;
			edgemap[0][0][0] = -1;
		}

	}
	else if(sz(mat[key][2])==0 && sz(mat[key][1])==0)
	{
		edgemap[0][0][1] = -4;
		edgemap[0][0][2] = -1;
		edgemap[0][0][3] = -2;
		edgemap[0][0][0] = -3;
	}
	else
	{
		if(mask&1)
		{
			edgemap[0][0][1] = 1;
			edgemap[0][0][2] = -2;
			edgemap[0][0][3] = 3;
			edgemap[0][0][0] = -4;
		}
		else
		{
			edgemap[0][0][1] = -2;
			edgemap[0][0][2] = 1;
			edgemap[0][0][3] = -4;
			edgemap[0][0][0] = 3;
		}
	}
	key = idmap[0][sdim-1];
	if(sz(mat[key][0])==0 && sz(mat[key][3])==0)
	{
		if(mask & 2)
		{
			edgemap[0][sdim-1][2] = -2;
			edgemap[0][sdim-1][3] = 3;
			edgemap[0][sdim-1][0] = -4;
			edgemap[0][sdim-1][1] = 1;
		}
		else
		{
			edgemap[0][sdim-1][2] = -3;
			edgemap[0][sdim-1][3] = 2;
			edgemap[0][sdim-1][0] = -1;
			edgemap[0][sdim-1][1] = 4;
		}

	}
	else if(sz(mat[key][0])==0 && sz(mat[key][1])==0)
	{
		edgemap[0][sdim-1][2] = 3;
		edgemap[0][sdim-1][3] = 4;
		edgemap[0][sdim-1][0] = 1;
		edgemap[0][sdim-1][1] = 2;
	}
	else if(sz(mat[key][2])==0 && sz(mat[key][1])==0)
	{
		if(mask & 2)
		{
			edgemap[0][sdim-1][2] = 4;
			edgemap[0][sdim-1][3] = -1;
			edgemap[0][sdim-1][0] = 2;
			edgemap[0][sdim-1][1] = -3;
		}
		else
		{
			edgemap[0][sdim-1][2] = 1;
			edgemap[0][sdim-1][3] = -4;
			edgemap[0][sdim-1][0] = 3;
			edgemap[0][sdim-1][1] = -2;
		}
	}
	else
	{
		edgemap[0][sdim-1][2] = -1;
		edgemap[0][sdim-1][3] = -2;
		edgemap[0][sdim-1][0] = -3;
		edgemap[0][sdim-1][1] = -4;
	}
	key = idmap[sdim-1][sdim-1];
	if(sz(mat[key][0])==0 && sz(mat[key][3])==0)
	{
		edgemap[sdim-1][sdim-1][3] = -2;
		edgemap[sdim-1][sdim-1][0] = -3;
		edgemap[sdim-1][sdim-1][1] = -4;
		edgemap[sdim-1][sdim-1][2] = -1;
	}
	else if(sz(mat[key][0])==0 && sz(mat[key][1])==0)
	{
		if(mask & 4)
		{
			edgemap[sdim-1][sdim-1][3] = 3;
			edgemap[sdim-1][sdim-1][0] = -4;
			edgemap[sdim-1][sdim-1][1] = 1;
			edgemap[sdim-1][sdim-1][2] = -2;
		}
		else
		{
			edgemap[sdim-1][sdim-1][3] = -4;
			edgemap[sdim-1][sdim-1][0] = 3;
			edgemap[sdim-1][sdim-1][1] = -2;
			edgemap[sdim-1][sdim-1][2] = 1;
		}

	}
	else if(sz(mat[key][2])==0 && sz(mat[key][1])==0)
	{
		edgemap[sdim-1][sdim-1][3] = 4;
		edgemap[sdim-1][sdim-1][0] = 1;
		edgemap[sdim-1][sdim-1][1] = 2;
		edgemap[sdim-1][sdim-1][2] = 3;
	}
	else
	{
		if(mask & 4)
		{
			edgemap[sdim-1][sdim-1][3] = -1;
			edgemap[sdim-1][sdim-1][0] = 2;
			edgemap[sdim-1][sdim-1][1] = -3;
			edgemap[sdim-1][sdim-1][2] = 4;
		}
		else
		{
			edgemap[sdim-1][sdim-1][3] = 2;
			edgemap[sdim-1][sdim-1][0] = -1;
			edgemap[sdim-1][sdim-1][1] = 4;
			edgemap[sdim-1][sdim-1][2] = -3;
		}
	}
	key = idmap[sdim-1][0];
	if(sz(mat[key][0])==0 && sz(mat[key][3])==0)
	{
		if(mask&8)
		{
			edgemap[sdim-1][0][0] = 2;
			edgemap[sdim-1][0][1] = -3;
			edgemap[sdim-1][0][2] = 4;
			edgemap[sdim-1][0][3] = -1;
		}
		else
		{
			edgemap[sdim-1][0][0] = 3;
			edgemap[sdim-1][0][1] = -2;
			edgemap[sdim-1][0][2] = 1;
			edgemap[sdim-1][0][3] = -4;
		}

	}
	else if(sz(mat[key][0])==0 && sz(mat[key][1])==0)
	{
		edgemap[sdim-1][0][0] = -3;
		edgemap[sdim-1][0][1] = -4;
		edgemap[sdim-1][0][2] = -1;
		edgemap[sdim-1][0][3] = -2;
	}
	else if(sz(mat[key][2])==0 && sz(mat[key][1])==0)
	{
		if(mask & 8)
		{
			edgemap[sdim-1][0][0] = -4;
			edgemap[sdim-1][0][1] = 1;
			edgemap[sdim-1][0][2] = -2;
			edgemap[sdim-1][0][3] = 3;
		}
		else
		{
			edgemap[sdim-1][0][0] = -1;
			edgemap[sdim-1][0][1] = 4;
			edgemap[sdim-1][0][2] = -3;
			edgemap[sdim-1][0][3] = 2;
		}

	}
	else
	{
		edgemap[sdim-1][0][0] = 1;
		edgemap[sdim-1][0][1] = 2;
		edgemap[sdim-1][0][2] = 3;
		edgemap[sdim-1][0][3] = 4;
	}
	
}

void fill_reduced_sea(vvl &idmap, vector<vector<vector<int > > > & edgemap, bool &ignore)
{
	queue<ii> q;
	unordered_set<ll> assigned;
	assigned.insert(idmap[0][0]);
	assigned.insert(idmap[0][sdim-1]);
	assigned.insert(idmap[sdim-1][sdim-1]);
	assigned.insert(idmap[0][sdim-1]);
	q.push({0,0});
	q.push({0,sdim-1});
	q.push({sdim-1,sdim-1});
	q.push({sdim-1,0});
	int r[4] = {-1,0,1,0};
	int c[4] = {0,1,0,-1};
	unordered_map<int, int > opp_edge;
	opp_edge[1] = 3;
	opp_edge[2] = 4;
	opp_edge[3] = 1;
	opp_edge[4] = 2;
	opp_edge[-1] = -3;
	opp_edge[-2] = -4;
	opp_edge[-3] = -1;
	opp_edge[-4] = -2;
	while(!q.empty())
	{
		auto u = q.front();
		q.pop();
		int ux = u.first;
		int uy = u.second;
		ll uid = idmap[ux][uy];
		for(int i =0; i<4; i++)
		{
			int edgemap_idx = abs(edgemap[ux][uy][i]) - 1;
			//trace(edgemap_idx);
			if(edgemap_idx <0)
				continue;
			if(sz(mat[uid][edgemap_idx])==0)
				continue;
			int vx = ux+r[i];
			int vy = uy+c[i];
			if(vx<0 || vy < 0 || vx>=sdim || vy >= sdim)
				continue;
			//trace(ux,uy, vx, vy);
			if(idmap[vx][vy] == -1)
			{
				idmap[vx][vy] = mat[uid][edgemap_idx][0].first;
				assigned.insert(idmap[vx][vy]);
			}
			else if(idmap[vx][vy] != mat[uid][edgemap_idx][0].first)
			{
				ignore = true;
				//trace(idmap[vx][vy], mat[uid][edgemap_idx][0].first);
				return;
			}
			int j ;
			if(i==0)
			{
				j=2;
			}
			else if(i==1)
			{
				j=3;
			}
			else if(i==2)
			{
				j=0;
			}
			else 
			{
				j = 1;
			}
			if(edgemap[vx][vy][j]==0)
			{
				q.push({vx, vy});
				edgemap[vx][vy][j] = mat[uid][edgemap_idx][0].second;
				if(edgemap[ux][uy][i] < 0)
				{
					edgemap[vx][vy][j] = -edgemap[vx][vy][j];
				}
				if(edgemap[vx][vy][i] == 0)
				{
					edgemap[vx][vy][i] = opp_edge[edgemap[vx][vy][j]];
				}
				else if(edgemap[vx][vy][i] != opp_edge[edgemap[vx][vy][j]])
				{
					ignore = true;
					return;
				}
			}
			else if(abs(edgemap[vx][vy][j]) != abs(mat[uid][edgemap_idx][0].second))
			{
				ignore = true;
				return;
				//throw("id not matching");
			}
		}
	}
	while(true)
	{
		bool break_loop = true;
		for(int i =0; i<sdim; i++)
		{
			for(int j =0; j<sdim; j++)
			{
				if(idmap[i][j]!=-1)
					continue;
				//trace(i, j);
				unordered_set<int> neighbours;
				unordered_set<ll> idsc(all(ids));
				for(auto x:assigned)
				{
					idsc.erase(x);
				}
				int nc = 0;
				for(int k=0; k<4; k++)
				{
					int ii= i +r[k];
					int jj = j+c[k];
					if(ii>=0 && jj>=0 && ii<sdim && jj<sdim)
					{
						if(idmap[ii][jj]!=-1)
						{
							nc++;
							vl tdl;
							std::vector<ll>::iterator it, ls;
							vl tsc;
							vl ssc(all(adj[idmap[ii][jj]]));
							/*for(auto x:idsc)
								cout<<x<<" ";
							cout<<"\n";
							for(auto x:ssc)
								cout<<x<<" ";
							cout<<"\n";*/
							for(auto x:idsc)
							{
								for(auto y:ssc)
								{
									if(x==y)
									{
										tsc.pb(x);
									}
								}
							}
							idsc.clear();
							for (it = tsc.begin(); it != tsc.end(); ++it)
							{
								idsc.insert(*it);
							}
							
						}
					}
				}
				if(nc>=2)
				{
					if(sz(idsc)==1)
					{
						idmap[i][j] = *idsc.begin();
						assigned.insert(idmap[i][j]);
						break_loop = false;
					}
					else if(sz(idsc)==0)
					{
						ignore = true;
						return;
					}
				}
			}
		}
		if(break_loop)
			break;
	}
	for(int j =1; j<sdim -1; j++)
	{
		for(int i =0; i<sdim-1; i++)
		{
			int id1 = idmap[i][j];
			int id2 = idmap[i+1][j];
			for(int k =0; k<4; k++)
			{
				if(sz(mat[id1][k]) >0 && mat[id1][k][0].first==id2)
				{
					if(i==0)
					{
						edgemap[i][j][2] = k+1;
						edgemap[i][j][0] = opp_edge[edgemap[i][j][2]];
						string seqkey = "";
						for(int ii=0; ii<4; ii++)
						{
							seqkey+= to_string(edgemap[i][j][ii]);
							seqkey+= ",";
						}
						if(!seqmap.count(seqkey))
						{
							edgemap[i][j][2] = -(k+1);
							edgemap[i][j][0] = opp_edge[edgemap[i][j][2]];
						}
					}
					else if(abs(edgemap[i][j][2]) !=(k+1))
					{
						ignore = false;
						return;
					}


					edgemap[i+1][j][0] = mat[id1][k][0].second;
					if(edgemap[i][j][2]== -(k+1))
						edgemap[i+1][j][0] = - edgemap[i+1][j][0];
					edgemap[i+1][j][2] = opp_edge[edgemap[i+1][j][0]];
				}
			}
		}
	}
	for(int i =1; i<sdim -1; i++)
	{
		for(int j =0; j<sdim-1; j++)
		{
			int id1 = idmap[i][j];
			int id2 = idmap[i][j+1];
			for(int k =0; k<4; k++)
			{
				if(sz(mat[id1][k]) >0 && mat[id1][k][0].first==id2)
				{
					if(j==0)
					{
						edgemap[i][j][1] = k+1;
						edgemap[i][j][3] = opp_edge[edgemap[i][j][1]];
						string seqkey = "";
						for(int ii=0; ii<4; ii++)
						{
							seqkey+= to_string(edgemap[i][j][ii]);
							seqkey+= ",";
						}
						if(!seqmap.count(seqkey))
						{
							edgemap[i][j][1] = -(k+1);
							edgemap[i][j][3] = opp_edge[edgemap[i][j][1]];
						}


					}
					else if(abs(edgemap[i][j][1]) !=(k+1))
					{
						ignore = false;
						return;
					}


					edgemap[i][j+1][3] = mat[id1][k][0].second;
					if(edgemap[i][j][1]== -(k+1))
						edgemap[i][j+1][3] = - edgemap[i][j+1][3];
					edgemap[i][j+1][1] = opp_edge[edgemap[i][j+1][3]];
				}
			}
		}
	}


}

void fill_full_sea(vvl &idmap, vector<vector<vector<int > > > & edgemap, vector<string> &fullsea)
{
	for(int i =0; i<sdim; i++)
	{
		for(int j =0; j<sdim; j++)
		{
			ll id = idmap[i][j];
			string keyseq;
			for(int x:edgemap[i][j])
			{
				keyseq+= to_string(x);
				keyseq+=",";
			}
			//trace(i, j, keyseq);
			vector<string> tarr(10, mivsr[id][0]);
			for(int ii =0; ii<10; ii++)
				tarr[ii] = mivsr[id][ii];
			if(!seqmap.count(keyseq))
			{
				trace(i, j, keyseq);
				throw;
			}
			for(char c: seqmap[keyseq])
			{
				if(c=='r')
					rotate(tarr);
				else if(c=='h')
					reflecth(tarr);
				else if(c=='v')
					reflectv(tarr);
			}
			int x = i*8;
			
			for(int a =1; a<9; a++)
			{
				int y = j*8;
				for(int b = 1; b<9; b++)
				{
					fullsea[x][y] = tarr[a][b];
					y++;
				}
				x++;
			}
		}
	}
}

void find_monster(vector<string> full_sea)
{
	int hashcount = 0;
	int monster_num = 0;
	int dim = sdim*8;
	int r[15] = {1, 2, 2, 1, 1, 2, 2 , 1 , 1 , 2 , 2 , 1 , 0 , 1 , 1 };
	int c[15] = {0, 1, 4, 5, 6, 7, 10, 11, 12, 13, 16, 17, 18, 18, 19};
	for(int i =0; i<dim; i++)
	{
		for(int j = 0; j<dim; j++)
		{
			if(full_sea[i][j] =='#')
				hashcount++;
		}
	}
	for(int i =0; i <dim-2; i++)
	{
		for(int j =0; j<dim; j++)
		{
			bool chk = true;
			for(int k=0; k<15; k++)
			{
				int ii = i+r[k];
				int jj = j+c[k];
				if(ii>=dim || jj>=dim)
				{
					chk = false;
					break;
				}
				if(full_sea[ii][jj]!='#')
				{
					chk = false;
					break;
				}
			}
			if(chk)
			{
				//trace(i,j);
				monster_num++;
			}
		}
	}
	if(monster_num!=0)
	{
		trace(hashcount, monster_num, hashcount -15*monster_num);
	}
}




int main()

{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T=1;
	//cin>>T;
	

	vi de(4);
	de[0] = 1;
	de[1] = 2;
	de[2] = 3;
	de[3] = 4;
	string startseq = "";
	enseq(de, 0, 0, startseq);
	
	for(int tc=1; tc<=T;tc++)
	{
		ll ans = 1;
		
		while(true)
		{
			string temp;
			cin>>temp;
			if(temp=="$$$")
				break;
			else {
				ll id ;
				cin>>id;
				ids.insert(id);
				vector<string> rarr(10);
				vector<string> carr(10);
				for(int i =0; i<10; i++)
				{
					cin>>rarr[i];
				}
				for(int i =0; i<10; i++)
				{
					carr[i] = rarr[i];
					for(int j =0; j<10; j++)
					{
						carr[i][j] = rarr[j][i];
					}
					
				}
				mivsr[id] = rarr;
				mivsc[id] = carr;

			}
		}
		
		for(auto xkey:ids)
		{
			vector<vector<pair<ll, int> > > temp(4);
			for(auto ykey:ids)
			{
				if(xkey==ykey)
					continue;
				//trace(xkey, ykey, mivsr[xkey][0], mivsr[xkey][9],  mivsc[xkey][0], mivsc[xkey][9]);
				if(mivsr[xkey][0] == mivsr[ykey][0])
					temp[0].pb({ykey, 1});
				if(mivsr[xkey][0] == mivsr[ykey][9])
					temp[0].pb({ykey, 3});
				if(mivsr[xkey][0] == mivsc[ykey][9])
					temp[0].pb({ykey, 2});
				if(mivsr[xkey][0] == mivsc[ykey][0])
					temp[0].pb({ykey, 4});
				if(mivsr[xkey][9] == mivsr[ykey][0])
					temp[2].pb({ykey, 1});
				if(mivsr[xkey][9] == mivsr[ykey][9])
					temp[2].pb({ykey, 3});
				if(mivsr[xkey][9] == mivsc[ykey][9])
					temp[2].pb({ykey, 2});
				if(mivsr[xkey][9] == mivsc[ykey][0])
					temp[2].pb({ykey, 4});
				if(mivsc[xkey][0] == mivsr[ykey][0])
					temp[3].pb({ykey, 1});
				if(mivsc[xkey][0] == mivsr[ykey][9])
					temp[3].pb({ykey, 3});
				if(mivsc[xkey][0] == mivsc[ykey][9])
					temp[3].pb({ykey, 2});
				if(mivsc[xkey][0] == mivsc[ykey][0])
					temp[3].pb({ykey, 4});
				if(mivsc[xkey][9] == mivsr[ykey][0])
					temp[1].pb({ykey, 1});
				if(mivsc[xkey][9] == mivsr[ykey][9])
					temp[1].pb({ykey, 3});
				if(mivsc[xkey][9] == mivsc[ykey][9])
					temp[1].pb({ykey, 2});
				if(mivsc[xkey][9] == mivsc[ykey][0])
					temp[1].pb({ykey, 4});
				////////////////////////////////////////////
				if(chkr(mivsr[xkey][0] ,mivsr[ykey][0]))
					temp[0].pb({ykey, -1});
				if(chkr(mivsr[xkey][0] ,mivsr[ykey][9]))
					temp[0].pb({ykey, -3});
				if(chkr(mivsr[xkey][0] ,mivsc[ykey][9]))
					temp[0].pb({ykey, -2});
				if(chkr(mivsr[xkey][0] ,mivsc[ykey][0]))
					temp[0].pb({ykey, -4});
				if(chkr(mivsr[xkey][9] ,mivsr[ykey][0]))
					temp[2].pb({ykey, -1});
				if(chkr(mivsr[xkey][9] ,mivsr[ykey][9]))
					temp[2].pb({ykey, -3});
				if(chkr(mivsr[xkey][9] ,mivsc[ykey][9]))
					temp[2].pb({ykey, -2});
				if(chkr(mivsr[xkey][9] ,mivsc[ykey][0]))
					temp[2].pb({ykey, -4});
				if(chkr(mivsc[xkey][0] ,mivsr[ykey][0]))
					temp[3].pb({ykey, -1});
				if(chkr(mivsc[xkey][0] ,mivsr[ykey][9]))
					temp[3].pb({ykey, -3});
				if(chkr(mivsc[xkey][0] ,mivsc[ykey][9]))
					temp[3].pb({ykey, -2});
				if(chkr(mivsc[xkey][0] ,mivsc[ykey][0]))
					temp[3].pb({ykey, -4});
				if(chkr(mivsc[xkey][9] ,mivsr[ykey][0]))
					temp[1].pb({ykey, -1});
				if(chkr(mivsc[xkey][9] ,mivsr[ykey][9]))
					temp[1].pb({ykey, -3});
				if(chkr(mivsc[xkey][9] ,mivsc[ykey][9]))
					temp[1].pb({ykey, -2});
				if(chkr(mivsc[xkey][9] ,mivsc[ykey][0]))
					temp[1].pb({ykey, -4});
			}
			mat[xkey] = temp;
			for(int i =0; i <4; i++)
			{
				if(sz(temp[i])!=0)
				{
					adj[xkey].insert(temp[i][0].first);
				}
			}
			trace(xkey);
			for(auto x:temp)
			{
				for(auto u: x)
				{
					cout<<u.first<<", "<< u.second<<" ";
				}
				cout<<"\n";
			}
		}
		vl corners;
		for(auto x:ids)
		{
			int cnt = 0;
			for(int i =0; i<4; i++)
			{
				if(sz(mat[x][i])==0)
					cnt++;
			}
			if(cnt==2)
			{
				trace(x);
				ans*=x;
				corners.pb(x);
				for(auto y:mat[x])
				{
					for(auto u: y)
					{
						cout<<u.first<<", "<< u.second<<" ";
					}
					cout<<"\n";
				}
				
			}
			
		}
		sort(all(corners));
		int dim = sqrt(sz(mivsr));
		sdim = dim;
		dim *=8;
		int perm_cnt = 0;
		for(auto x: seqmap)
		{
			trace(x.first, x.second);
		}
		do {
			for(int mc = 0; mc<16; mc++)
			{
				vvl idmap(sdim, vl(sdim, -1));
				vector<vector<vector<int > > > edgemap (sdim, vvi (sdim, vi(4,0)));
			
				fill_corners_reduced_sea(corners, idmap,  edgemap, mc);
			
				bool ignore = false;
				fill_reduced_sea(idmap, edgemap, ignore);
				if(ignore)
					continue;

				trace(corners[0], corners[1],corners[2],corners[3], mc);
				
				string ini_string = "";
				for(int i =0; i<dim; i++)
					ini_string+=".";
				vector<string> fullsea(dim, ini_string);
				fill_full_sea(idmap, edgemap, fullsea);
				
				for(auto x:seqmap)
				{
					//trace(x.first, x.second);
					vector<string> fullsea_copy(sz(fullsea), fullsea[0]);
					for(int i =0; i<dim; i++)
					{
						fullsea_copy[i] = fullsea[i];
					}
					
					for(char c: x.second)
					{
						if(c=='r')
						{
							rotate(fullsea_copy);
						}
						else if(c=='h')
							reflecth(fullsea_copy);
						else if(c=='v')
							reflectv(fullsea_copy);
					}
					find_monster(fullsea_copy);
					
				}
				
				perm_cnt++;
			}
		} while(next_permutation(all(corners)));
		


		trace(sz(mivsr),  dim, perm_cnt);
		cout<<ans<<"\n";
		

	}
  
 
 
	return 0;
}
 
 
