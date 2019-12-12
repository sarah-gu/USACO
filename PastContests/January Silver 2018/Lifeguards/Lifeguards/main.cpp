//
//  main.cpp
//  Lifeguards
//
//  Created by Sarah Gu on 12/30/18.
//  Copyright © 2018 Sarah Gu. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
void solve(pair<int,int> *arr, int N)
{
    // iterate through once to find total sum and lifeguard unique times
    int iTime[N];
    if(arr[0].second > arr[1].first)
        iTime[0] =  arr[1].first - arr[0].first;
    else
        iTime[0] = arr[0].second = arr[0].first;
    bool boolean = true;
    int totalTime = arr[0].second -arr[0].first;
  //  cout << totalTime << endl;
    int maxEnd = arr[0].second;
    for(int x = 1; x < N-1; x++)
    {
        pair<int,int> prevPair = arr[x-1];
        pair<int,int> curPair = arr[x];
        pair<int,int> nextPair = arr[x+1];
        
        if(prevPair.second >= curPair.first && curPair.second > nextPair.first && boolean)
        {
            int wholeTime = curPair.second - curPair.first;
            wholeTime = max(0, wholeTime - (prevPair.second - curPair.first ) - (curPair.second - nextPair.first));
            iTime[x] = wholeTime;
            if(wholeTime == 0)
            {
                boolean = false;
            }
        
        }
        else if(prevPair.second >= curPair.first && curPair.second <= nextPair.first && boolean)
        {
            int wholeTime = curPair.second - curPair.first;
            wholeTime = max(0, wholeTime - (prevPair.second - curPair.first ));
            iTime[x] = wholeTime;
            if(wholeTime == 0)
            {
                boolean = false;
            }
        }
        else if(curPair.second > nextPair.first && boolean)
        {
            int wholeTime = curPair.second - curPair.first;
            wholeTime = max(0, wholeTime - (curPair.second - nextPair.first));
            iTime[x] = wholeTime;
            if(wholeTime == 0)
            {
                boolean = false;
            }
        }
        else
        {
            iTime[x] = curPair.second - curPair.first;
        }
        if(curPair.second > maxEnd)
        {
            if(curPair.first > maxEnd )
            {
                totalTime += curPair.second - curPair.first;
                
            }
            else
            {
                totalTime += (curPair.second - curPair.first) - (maxEnd - curPair.first);
            }
         //   cout<< totalTime << endl;
            maxEnd = curPair.second;
        }
        
    }
    if(arr[N-1].second > maxEnd)
    {
        if(arr[N-1].first > maxEnd )
        {
            totalTime += arr[N-1].second - arr[N-1].first;
            iTime[N-1] =arr[N-1].second - arr[N-1].first;
            
        }
        else
        {
            totalTime += (arr[N-1].second - arr[N-1].first) - (maxEnd - arr[N-1].first);
            iTime[N-1] =(arr[N-1].second - arr[N-1].first) - (maxEnd - arr[N-1].first);
        }
        

    }

    if(!boolean)
    {
        cout << totalTime << endl;
    }
    else
    {
        //cout << "TOTAL" << totalTime << endl;
        int highTime = 0;
        for(int y = 0; y < N; y++)
        {
            if((totalTime - iTime[y]) > highTime)
                highTime = (totalTime - iTime[y]);
//cout << totalTime << " " << highTime << endl;
        }
        cout << highTime;
    }
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int N;
    cin >> N;
    pair<int,int> arr[N];
    for(int x = 0; x < N; x++)
    {
        int t1,t2;
        cin >> t1 >> t2;
        arr[x] = make_pair(t1,t2);
    }
    sort(arr, arr+N);
    solve(arr, N);
    return 0;
}
