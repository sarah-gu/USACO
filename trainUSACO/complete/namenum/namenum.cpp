/*
 ID: guwen881
 PROG: namenum
 LANG: C++
 */
//  main.cpp
//  Format
//
//  Created by Sarah Gu on 12/9/18.
//  Copyright © 2018 Sarah Gu. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
string cowNum;
vector<string> dict, toRet;
map<string, vector<string> > nums;
bool checkExist(string curWord, int idx)
{
    for(int x = 0; x < 5000; x++)
    {
        string dWord = dict[x].substr(0,idx);
        if(dWord == curWord)
            return true;
        
    }
    return false;
}
void recurse(int idx, string curWord)
{
    if(idx >= cowNum.length())
    {
        if(find(dict.begin(), dict.end(), curWord) != dict.end())
        {
            toRet.push_back(curWord);
        }
    }
    else
    {
        if(checkExist(curWord, idx))
        {
            string t = string(1,cowNum[idx]);
           // cout << t << endl;
            vector<string> posLet = nums[t];
            recurse(idx+1, curWord+posLet[0]);
            recurse(idx+1, curWord+posLet[1]);
            recurse(idx+1, curWord+posLet[2]);
        }
    }
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream file("dict.txt");
    int idx = 0;
    while(file.good())
    {
        string s;
        file >> s;
        dict.push_back(s);

    }
    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);
    cin >> cowNum;
    nums["2"];
    nums["2"].push_back("A");
    nums["2"].push_back("B");
    nums["2"].push_back("C");
    nums["3"];
    nums["3"].push_back("D");
    nums["3"].push_back("E");
    nums["3"].push_back("F");
    nums["4"];
    nums["4"].push_back("G");
    nums["4"].push_back("H");
    nums["4"].push_back("I");
    nums["5"];
    nums["5"].push_back("J");
    nums["5"].push_back("K");
    nums["5"].push_back("L");
    nums["6"];
    nums["6"].push_back("M");
    nums["6"].push_back("N");
    nums["6"].push_back("O");
    nums["7"];
    nums["7"].push_back("P");
    nums["7"].push_back("R");
    nums["7"].push_back("S");
    nums["8"];
    nums["8"].push_back("T");
    nums["8"].push_back("U");
    nums["8"].push_back("V");
    nums["9"];
    nums["9"].push_back("W");
    nums["9"].push_back("X");
    nums["9"].push_back("Y");
    
    recurse(0, "");
    if(toRet.size() == 0)
        cout << "NONE" << endl;
    for(int x = 0; x < toRet.size(); x++)
    {
        if(x+1 == toRet.size())
            cout << toRet[x] << endl;
        else
            cout << toRet[x] << endl;
    }


    return 0;
}
