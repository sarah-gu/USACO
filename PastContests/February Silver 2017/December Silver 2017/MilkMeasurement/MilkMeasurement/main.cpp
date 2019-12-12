//
//  main.cpp
//  MilkMeasurement
//
//  Created by Sarah Gu on 1/20/19.
//  Copyright © 2019 Sarah Gu. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int N, G;
map<int, int> cows;
pair<int, pair<int,int> > measurements[100000];
vector<int> curBestCows;
void solve()
{
    int highMilk = G, countChange = 0;
    for(int x = 0; x < N; x++)
    {
        pair<int,int> change = measurements[x].second;
        int cowName = change.first;
        int milkChange = change.second;
        cows[cowName] += milkChange;
       // cout << "cowName: " << cowName << " cowOutput: " << cows[cowName] <<" milkChange: " << milkChange << " highMilk: " << highMilk << endl;
        bool cowInBest = find(curBestCows.begin(), curBestCows.end(), cowName) != curBestCows.end(); // true if in arr
        if(cows[cowName] > highMilk && (!cowInBest|| (cowInBest && curBestCows.size() > 1))) // need to switch
        {
            highMilk = cows[cowName];
            curBestCows.clear();
            curBestCows.push_back(cowName);
            countChange += 1;
        }
        else if(cows[cowName] > highMilk && cowInBest)
        {
            highMilk = cows[cowName];
        }
        else if(cows[cowName] == highMilk && !cowInBest)
        {
            curBestCows.push_back(cowName);
            countChange +=1;
        }
        else if(cows[cowName] < highMilk && (cowInBest) && curBestCows.size() == 1)
        {
            countChange += 1;
            curBestCows.clear();
            int newHigh = 0;
            vector<int> bestCow;
            for (auto const& x : cows)
            {
                if(x.second == newHigh)
                {
                    bestCow.push_back(x.first);
                }
                if(x.second > newHigh)
                {
                    newHigh = x.second;
                    bestCow.clear();
                    bestCow.push_back(x.first);
                }
            }
            if(find(bestCow.begin(), bestCow.end(), cowName) != bestCow.end() && bestCow.size() == 1)
            {
                countChange -=1;
                curBestCows.push_back(cowName);
            }
            else{
                curBestCows = bestCow;
                
            }
            highMilk = newHigh;
        }
        else if(cows[cowName] < highMilk && cowInBest && curBestCows.size() > 1)
        {
            countChange +=1;
            int pos = find(curBestCows.begin(), curBestCows.end(), cowName) - curBestCows.begin();
            curBestCows.erase(curBestCows.begin() + pos);
        }
       // cout << curBestCows[0] << endl;
    }
    cout << countChange;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    cin >> N >> G;
    //cout << N << endl;
    for(int x = 0; x < N; x++)
    {
        int day, cow;
        string change;
        cin >> day >> cow >> change;
        int rC;
        if(change[0] == '-')
        {
            rC = stoi(change.substr(1)) * -1;
        }
        else
            rC= stoi(change.substr(1));
       // cout << rC << endl;
        curBestCows.push_back(cow);
        cows[cow] = G;
        measurements[x] = make_pair(day, make_pair(cow,rC ));
    }
    sort(measurements, measurements+ N);
    solve();
    return 0;
}
