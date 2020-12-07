#include <bits/stdc++.h>
using namespace std;
bool chk(map<string ,string> &ma)
{
    /*for(auto x:ma)
        cout<<x.first<<" ";
    cout<<"\n";*/
    if(!ma.count("byr"))
        return false;
    else
    {
        if(ma["byr"].size()!=4)
            return false;
        int byr = 0;
        for(int i =0; i <4; i++)
        {
            if(ma["byr"][i]<='9' && ma["byr"][i]>='0')
                byr = byr*10 + ma["byr"][i]-'0';
            else
                return false;
        }
        if(byr < 1920 || byr > 2002)
            return false;
    }
    if(!ma.count("iyr"))
        return false;
    else
    {
        if(ma["iyr"].size()!=4)
            return false;
        int byr = 0;
        for(int i =0; i <4; i++)
        {
            if(ma["iyr"][i]<='9' && ma["iyr"][i]>='0')
                byr = byr*10 + ma["iyr"][i]-'0';
            else
                return false;
        }
        if(byr < 2010 || byr > 2020)
            return false;
    }
    if(!ma.count("eyr"))
        return false;
    else
    {
        if(ma["eyr"].size()!=4)
            return false;
        int byr = 0;
        for(int i =0; i <4; i++)
        {
            if(ma["eyr"][i]<='9' && ma["eyr"][i]>='0')
                byr = byr*10 + ma["eyr"][i]-'0';
            else
                return false;
        }
        if(byr < 2020 || byr > 2030)
            return false;
        //cout<<byr<<"\n";
    }
    if(!ma.count("hgt"))
        return false;
    else
    {
        int hgt = 0;
        int i =0;
        while(ma["hgt"][i]>='0' && ma["hgt"][i]<='9')
            hgt = hgt*10+(ma["hgt"][i++]-'0');
        cout<<ma["hgt"] <<" "<<i<<"\n";
        if(i!=static_cast<int> (ma["hgt"].size()) -2)
            return false;
        string un = ma["hgt"].substr(i,2);

        cout<<hgt <<" "<<un<<"---\n";
        if(un=="cm")
        {
            if(hgt < 150 || hgt > 193)
                return false;
        }
        else if(un=="in")
        {
            if(hgt < 59 || hgt > 76)
                return false;
        }
        else
            return false;
        cout<<hgt<<"\n";
    }
    if(!ma.count("hcl"))
        return false;
    else
    {
        if(ma["hcl"].size()!=7)
            return false;
        int i = 1;
        for(; i<7; i++)
        {
            if(ma["hcl"][i]<='9' && ma["hcl"][i]>='0')
                continue;
            else if(ma["hcl"][i]<='f' && ma["hcl"][i]>='a')
                continue;
            else
                return false;
        }
        cout<<ma["hcl"]<<"\n";
    }

    if(!ma.count("ecl"))
        return false;
    else
    {
        if(ma["ecl"]!="amb" && ma["ecl"]!="blu" && ma["ecl"]!="brn"
            && ma["ecl"]!="gry" && ma["ecl"]!="grn" && ma["ecl"]!="hzl" && ma["ecl"]!="oth")
            return false;
        cout<<ma["ecl"]<<"\n";
    }

    if(!ma.count("pid"))
        return false;
    else
    {
        if(ma["pid"].size()!=9)
            return false;
        else
        {
            for(int i=0; i<9; i++)
                if(ma["pid"][i]>='0' && ma["pid"][i]<='9')
                    continue;
                else
                    return false;
        }
        cout<<ma["pid"]<<"\n";
    }

    /*if(!ma.count("byr")
        return false;*/
    return true;
}
int main () 
{
    int ans = 0;
    int n;
    cin>>n;
    set<int> seen;
    for(int i =0; i<n; i++)
    {
        string temp;
        cin>>temp;
        int l =0; 
        int r = 127;
        int j =0;
        for(; j<7; j++)
        {
            int mid = (l+r)/2;
            if(temp[j]=='F')
                r = mid;
            else
                l = mid +1;
            cout<<l<<" "<<r<<"\n";
        }
        int row = l;
        l = 0; 
        r  =7;
        for(; j<10; j++)
        {
            int mid = (l+r)/2;
            if(temp[j]=='L')
                r = mid;
            else
                l = mid +1;
        }
        int col = l;
        int seat_id = row*8 + col;
        seen.insert(seat_id);
        //cout<<row<<" "<<col<<" "<<seat_id<<"\n";
        


        ans = max(ans, seat_id);
    }
    for(int ii =0; ii<=127;ii++)
        {
            for(int jj=0; jj<=7; jj++)
            {
                int tsi = ii*8+jj;
                if(!seen.count(tsi))
                    cout<<tsi<<" ";
            }
        }
    cout<<"\n";




    cout<<ans<<"\n";

    return 0;
}
