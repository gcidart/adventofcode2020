#include <bits/stdc++.h>
using namespace std;
int main () 
{
    int n = 1000;
    cin>>n;
    vector<string> arr(n);
    int right = 3;
    int down  =1;
    long long ans = 0;
    for(int i =0; i<n; i++)
    {
        cin>>arr[i];
    }
    int m = arr[0].size();
    int i =0;
    int j =0;
    while(i<n)
    {
        for(int x = 0; x<right; x++)
        {
            j = (j+1)%m;
            //if(arr[i][j]=='#')
            //    ans++;
        }
        for(int y=0; y<down; y++)
        {
            i = i+1;
            if(i==n)
                break;
            if(arr[i][j]=='#')
                ans++;
        }
        //cout<<i<<" "<<j<<"\n";
    }
    cout<<ans<<"\n";
    int r[4] = {1, 5, 7 ,1};
    int d[4] = {1, 1 , 1, 2};
    for(int tc = 0; tc<4 ; tc++)
    {
        right = r[tc];
        down = d[tc];
        long long tans = 0;
        i = 0;
        j = 0;
        while(i<n)
        {
            for(int x = 0; x<right; x++)
            {
                j = (j+1)%m;
                //if(arr[i][j]=='#')
                 //    ans++;
            }
            for(int y=0; y<down; y++)
            {
                i = i+1;
                if(i==n)
                    break;
            }
            
            if(i<n && arr[i][j]=='#')
                tans++;
        }
        cout<<tans<<"\n";
        ans*= tans;
    }


    cout<<ans<<"\n";

    return 0;
}
