/*
 ID: guwen881
 PROG: crypt1
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
int digits[10], topMult[729], bottomMult[81];
int N, tidx, bidx;
void fillArr(int b)
{
    if(b == 1)
    {
        int idx = 0;
        for(int x = 0; x < N; x++)
        {
            for(int y = 0; y < N; y++)
            {
                for(int z = 0; z < N; z++)
                {
                    topMult[idx] = 100*digits[x] + 10*digits[y] + digits[z];
                    idx += 1;
                }
            }
        }
        tidx = idx;
    }
    else{
        int idx = 0;
        for(int x = 0; x < N; x++)
        {
            for(int y = 0; y < N; y++)
            {
                bottomMult[idx] = 10*digits[x] + digits[y];
                idx += 1;
            }
        }
        bidx = idx;
      //  cout << bidx << endl;
    }
}
bool check(int p, int maxsize, int digit)
{
    if(p/maxsize != 0)
        return false;
    string checkstr = to_string(p);
    for(int x = 0; x < digit; x++)
    {
        int toFind =(int)checkstr[x] - 48;
        int * p;
        p = find(digits, digits+N, toFind);
        if(p == digits+N)
            return false;
    }
    return true;
}
void solve()
{
    int count = 0;
    for(int t = 0; t < tidx; t++)
    {
        for(int b = 0; b < bidx; b++)
        {
            int top = topMult[t];
            int bot = bottomMult[b];
            int part1 = bot%10 * top;
          //  cout << part1 << endl;
            if(check(part1, 1000,3))
            {
                int part2 = bot/10 * top;
               // cout << part1 << " " << part2 << " " << endl;
                if(check(part2, 1000,3))
                {
                    int finalAns = top * bot;
                    if(check(finalAns, 10000, 4))
                        count += 1;
                }
            }
        }
    }
    cout << count << endl;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);
    cin >> N;
    for(int x = 0; x < N; x++)
    {
        cin >> digits[x];
    }
    fillArr(1);
    fillArr(0);
    solve();
    return 0;
}
