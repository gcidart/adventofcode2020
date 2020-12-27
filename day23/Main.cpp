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
unordered_map<string, int> ing;
unordered_map<string, int> allergens;
unordered_map<int, string> rev_all_map;
vector<vector<string> > arr_ing;
vector<vector<string> > arr_all;
vector<int> arr_bm;
unordered_map<int, set<string> > all_ing_map;
unordered_set<string> ingredients_set;
map<string, string> ing_with_allergens;
int cnt = 0;
struct Node
{
    ll val;
    Node* next;
    Node(int x): val(x), next(nullptr){}
};
int main()

{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T=1;
	unordered_map<int, Node*> mapin;
	for(int tc=1; tc<=T;tc++)
	{
        string s;
        cin>>s;
	    int n = sz(s);
        vi arr(10);
        for(int i =0; i<n; i++)
        {
            arr[i] = s[i] - '0';
            mapin[arr[i]] = new Node(arr[i]);
        }
        for(int i =0; i<8; i++)
        {
            mapin[arr[i]]->next = mapin[arr[i+1]];
        }
        mapin[10] = new Node(10);
        mapin[arr[8]]->next = mapin[10];
        for(int i =11; i<=1e6; i++)
        {
            mapin[i] = new Node(i);
            mapin[i-1] -> next = mapin[i];
        }
        mapin[1e6] -> next = mapin[arr[0]];
        Node* head = mapin[arr[0]];
        Node* tt = head;
        

        int num_moves = 100;
        int index = 0;
        for(int i =0; i<num_moves; i++)
        {
            vi temp(n);
            int cnt = 0;
            int dest_index = index;
            temp[dest_index] = (arr[index]);
            dest_index = (dest_index+1)%n;
            cnt++;
            int to_rem = (index+1)%n;
            set<int> removed;
            vi removed_arr;
            for(int j =0; j<3; j++)
            {
                removed.insert(arr[to_rem]);
                removed_arr.pb(arr[to_rem]);
                to_rem = (to_rem+1)%n;
            }
            int label = arr[index]-1;
            if(label==0)
                label = n;
            while(removed.count(label))
            {
                label--;
                if(label==0)
                    label = n;

            }
            trace(arr[index],label);
            int j = (index+1)%n;
            while(arr[j]!=label)
            {
                if(!removed.count(arr[j]))
                {
                    temp[dest_index] = (arr[j]);
                    dest_index = (dest_index+1)%n;
                    cnt++;
                }
                j = (j+1)%n;
            }
            temp[dest_index] = label;
            dest_index = (dest_index+1)%n;
            cnt++;
            for(int x:removed_arr)
            {
                temp[dest_index] = x;
                dest_index = (dest_index+1)%n;
                cnt++;
            }
            j = (j+1)%n;
            while(cnt!=sz(arr))
            {
                if(!removed.count(arr[j]))
                {
                    temp[dest_index] = (arr[j]);
                    dest_index = (dest_index+1)%n;
                    cnt++;
                }
                j = (j+1)%n;
            }
            swap(arr,temp);
            index = (index+1)%n;

            for(int x: arr)
                cout<<x<<" ";
            cout<<"\n";
        }
        for(int x: arr)
                cout<<x;
            cout<<"\n";
        
        num_moves = 10e6;
        for(int i =0; i<num_moves; i++)
        {
            Node* breakchain = head->next;
            Node* breakchain_end = breakchain->next->next;
            //trace(breakchain->val, breakchain_end->val);
            head->next = breakchain_end->next;
            breakchain_end->next = nullptr;
            set<int> breakset;
            breakset.insert(breakchain->val);
            breakset.insert(breakchain->next->val);
            breakset.insert(breakchain->next->next->val);
            int label = head->val-1;
            if(label==0)
                label = 1e6;
            while(breakset.count(label))
            {
                label--;
                if(label==0)
                    label = 1e6;

            }
            breakchain_end->next = mapin[label]->next;
            mapin[label]->next = breakchain;
            head = head->next;
            //trace(i, head->val);
        }
        trace((mapin[1]->next->val)*(mapin[1]->next->next->val));





		





        
        

	}
  
 
 
	return 0;
}
 
 
