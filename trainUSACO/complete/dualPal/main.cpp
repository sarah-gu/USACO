/*
 ID: guwen881
 PROG: dualpal
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
int N, S;
string convert(int n, int B)
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
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);
    cin >> N >> S;
    int count = 0;
    int curNum = S+1;
    while(count < N)
    {
        int numPal = 0;
        for(int x = 2; x <= 10; x++)
        {
            string checkPal = convert(curNum, x);
            if(isPalindrome(checkPal))
            {
                numPal += 1;
            }
            if(numPal == 2)
            {
                cout << curNum << endl;
                count += 1;
                break;
            }
        }
        curNum += 1;
    }
    return 0;
}

