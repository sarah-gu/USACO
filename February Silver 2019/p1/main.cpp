/*
 ID: guwen881
 PROG: friday
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
int cows[100000];
int N;
void solve()
{
    int largeGap = 0, smallGap = N;
    int prevCow = cows[0];
    bool keepCheck = true;
    for(int x = 0; x < N-1; x++)
    {
        if(cows[x] - prevCow -1 >= N) // checks for huge empty space
        {
            keepCheck = false;
            largeGap = N;
        }
        int gapCount = 0;
        int travIdx = cows[x] +1;
        int cowIdx = x+1;
        if(cows[x] + N -1<= cows[N-1])
        {
            while(travIdx < cows[x] + N && cowIdx < N) // check if cow will go out of bounds later
            {
                if(travIdx != cows[cowIdx]) //no cow in the index being checked
                {
                    gapCount += 1;
                }
                else
                {
                    cowIdx += 1;
                }
                travIdx += 1;
            }
           // cout << gapCount << endl;
            if(gapCount > largeGap && keepCheck)
            {
                largeGap = gapCount;
            }
            if(gapCount < smallGap)
            {
                smallGap = gapCount;
            }
        }

        prevCow = cows[x];
    }
    cout << smallGap << endl;
    cout << largeGap << endl;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    cin >> N;
    for(int x = 0;x < N; x++)
    {
        cin >> cows[x];
    }
    sort(cows, cows+N);
    solve();
    return 0;
}
