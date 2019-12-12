/*
 ID: guwen881
 PROG: barn1
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
int M,S,C;
int stallsBlocked[200];
int allStalls[200];
vector<int> seenIdx;
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);
    cin >> M >> S >> C;
    int firstidx = 0, lastidx = 0;
    for(int x = 0; x < C; x++)
    {
        
        int blocked;
        cin >> blocked;
        stallsBlocked[blocked-1] = 1;
        allStalls[x] = blocked-1;
    }
    sort(allStalls, allStalls+C);
    int toRet = allStalls[C-1] - allStalls[0]+1;
    for(int r = 0; r < M-1; r++)
    {
        int count = 0, max = 0, idx = 0, goodidx = 0;
        bool checking = false;
        for(int r = allStalls[0]; r <= allStalls[C-1]; r++)
        {
            if(checking && stallsBlocked[r] == 1)
            {
                if(count > max && find(seenIdx.begin(), seenIdx.end(), idx) == seenIdx.end())
                {
                 //   cout << idx << endl;
                    goodidx = idx;
                    max = count;
                }
                count = 0;
                checking = false;
            }
            else if(!checking && stallsBlocked[r] == 0)
            {
                idx = r;
                count += 1;
                checking = true;
                
            }
            else if(checking && stallsBlocked[r] == 0)
            {
                count += 1;
            }
        }
        seenIdx.push_back(goodidx);
       // cout << goodidx << " " << max <<  endl;
        toRet -=max;
    }
    cout << toRet << endl;
}
