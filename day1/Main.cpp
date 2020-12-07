#include <bits/stdc++.h>
using namespace std;
int main () 
{
    unordered_map<long long, vector<long long> > si;
    long long ans = 0;
    long long tt = 2020;
    int n = 200;
    vector<int> arr(200);
    for(int i =0; i<n; i++)
    {
        int temp;
        cin>>temp;
        arr[i] = temp;
        if(si.count(tt-temp)){
            ans = temp * (tt-temp);
            cout<<temp<<" "<<(tt-temp)<<"\n";
        }
        si[temp].push_back(i);
    }
    cout<<ans<<"\n";
    long long ans2 = 0;
    for(int i =0; i<n; i++)
    {
        for(int j =i+1; j<n; j++)
        {
            long long temp2 = arr[i] + arr[j];
            if((arr[i]==arr[j] && temp2==arr[i] && si[temp2].size()>2) ||
                                        (temp2==arr[i] && si[temp2].size()>1) ||
                                        (temp2==arr[j] && si[temp2].size()>1)  )
            {
                ans2 = arr[i] * arr[j]*(tt-temp2);
                cout<<arr[i]<<" "<<arr[j]<<" "<<(tt-temp2)<<"\n" ;
            }
            else if(si.count(tt-temp2) && arr[i]!=temp2 && arr[j]!=temp2 )
            {
                ans2 = arr[i] * arr[j]*(tt-temp2);
                cout<<arr[i]<<" "<<arr[j]<<" "<<(tt-temp2)<<"\n" ;
            }
        }
    }
        
    
    cout<<ans2<<"\n";
    return 0;
}
