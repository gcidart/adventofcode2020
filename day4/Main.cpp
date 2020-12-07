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
    map<string ,string> ma;
    while(true)
    {
        
        string temp;
        cin >> temp;
        //cout<<temp<<"\n";
        if(temp=="$$$")
        {
            if(chk(ma))
                ans++;
            ma.clear();
        }
        else if(temp =="#######")
        {
            if(chk(ma))
                ans++;
            break;
        }
        else
        {
            string key = "";
            int i =0;
            while(i<temp.size() && temp[i]!=':')
                key += temp[i++];
            if(i<temp.size() && temp[i]==':')
                i++;
            else
                break;
            string val = "";
            while(i<temp.size() && temp[i]!=':')
                val += temp[i++];
            //cout<<key<<" "<<val<<"\n";
            ma[key] = val;
        }
    }




    cout<<ans<<"\n";

    return 0;
}
