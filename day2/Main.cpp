#include <bits/stdc++.h>
using namespace std;
int main () 
{
    int ans = 0;
    int n = 1000;
    for(int i =0; i<n; i++)
    {
        string cnt;
        cin>>cnt;
        int j =0;
        int lnum = 0, rnum = 0;
        while(cnt[j]!='-')
        {
            lnum = lnum*10 + (cnt[j]-'0');
            j++;
        }
        j++;
        while(j<cnt.size())
            {
            rnum = rnum*10 + (cnt[j]-'0');
            j++;
        }
        string cha;
        cin>>cha;
        string pass;
        cin>>pass;
        vector<int> cnta(26);
        for(int ii=0; ii<pass.size() ;ii++)
        {
            cnta[pass[ii]-'a']++;
        }
        int tbc = cnta[cha[0]-'a'];
        int tc = 0;
        if(pass[lnum-1]==cha[0])
            tc++;
        if(pass[rnum-1]==cha[0])
            tc++;

        //if(tbc>=lnum && tbc<=rnum)
        if(tc==1)
            ans++;
        cout<<lnum<<" "<<rnum<<" "<<cha<<" "<<tbc<<"\n";
    }
    cout<<ans<<"\n";

    return 0;
}
