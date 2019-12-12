/*
 ID: guwen881
 PROG: beads
 LANG: C++
 */
//  main.cpp
//  Beads
//
//  Created by Sarah Gu on 12/24/18.
//  Copyright © 2018 Sarah Gu. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
void solve(int n, string necklace)
{
    int bestCount = 0;
    for(int x = 0; x < necklace.length(); x++)
    {
        int forwardCount = 0, backwardCount = 0, counter = x;
        char curBead = necklace[x];
        while((necklace[counter] == curBead || necklace[counter] == 'w') && forwardCount <= necklace.length())
        {
           // cout << necklace[counter] << " " ;
            forwardCount += 1;
            counter += 1;
            if(counter >= necklace.length())
                counter = 0;
            if(curBead == 'w' && necklace[counter] != curBead)
            {
                curBead = necklace[counter];
            }

        }
      // cout << endl;
        counter = x-1;
        curBead = necklace[x-1];
        if(counter < 0)
        {
            counter = (int)necklace.length() -1;
            curBead = necklace[(int)necklace.length()-1];
        }
        while((necklace[counter] == curBead || necklace[counter] == 'w')&&backwardCount <= necklace.length())
        {
          //  cout << necklace[counter] << " " ;
            backwardCount+=1;
            counter -=1;
            if(counter < 0)
            {
                counter = (int)necklace.length() -1;
            }
            if(curBead == 'w' && necklace[counter] != curBead)
            {
                curBead = necklace[counter];
            }
        }
      //  cout << forwardCount + backwardCount << endl;
        if(forwardCount+backwardCount > necklace.length())
        {
            bestCount = necklace.length();
        }
        else if(forwardCount + backwardCount > bestCount)
            bestCount = forwardCount+backwardCount;

    }
    
    cout << bestCount<< endl;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
    int N;
    string beads;
    cin >> N >> beads;
    solve(N, beads);
    return 0;
}
