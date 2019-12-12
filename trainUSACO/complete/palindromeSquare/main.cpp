/*
 ID: guwen881
 PROG: palsquare
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
using namespace std;
int B;
string convert(int n)
{
    map<int, string> m;
    m[10] = "A";
    m[11] = "B";
    m[12] = "C";
    m[13] = "D";
    m[14] = "E";
    m[15] = "F";
    m[16] = "G";
    m[17] = "H";
    m[18] = "I";
    m[19] = "J";
    m[20] = "K"; 
    string curString = "";
    while(n != 0)
    {
      //  cout << n%B << endl;
        int remainder = n%B;
        if(remainder/10 !=0)
        {
            curString += m[remainder];
        }
        else
            curString += to_string(n%B);
    //    cout << curString << endl;
        n = n/B;
    }
    string toRet = "";
    for(int y = curString.length()- 1; y >= 0; y--)
    {
        toRet += string(1, curString[y]);
    }
    return toRet;
}
bool isPalindrome(string s)
{
    int len = s.length();
    int backidx = len -1;
    for(int x = 0; x < len/2; x++)
    {
        if(s[x] != s[backidx])
            return false;
        backidx -=1;
    }
    return true;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);
    cin >> B;
    for(int n = 1; n <= 300; n++)
    {
        int square = n*n;
        string newBase = convert(square);
        if(isPalindrome(newBase))
        {
            cout << convert(n) << " " << newBase << endl;
        }
    }
    return 0;
}

