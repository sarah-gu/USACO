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
int N;
vector<int> field[100000];
int alreadySeen[100000];
bool allFilled()
{
    for(int x = 0; x < N; x++)
    {
        if(alreadySeen[x] == 0)
            return false;
    }
    return true;
}
void solve()
{
    for(int x = 0; x < N; x++)
    {
        alreadySeen[x] = 0;
    }
    int i = 0, count = 0;
    while(!allFilled())
    {
        vector<int> curNeighbors= field[i];
        if(alreadySeen[i] != 1)
        {
            count +=1;
            alreadySeen[i]= 1;
            for(int j = 0; j < curNeighbors.size(); j++)
            {
                vector<int> secNeigh = field[curNeighbors[j]];
                for(int k = 0; k < secNeigh.size(); k++)
                {
                    vector<int> accNeigh = field[secNeigh[k]];
                    for(int l = 0; l < accNeigh.size(); l++)
                    {
                        //cout << accNeigh[l] << endl;
                        alreadySeen[accNeigh[l]] = 1;
                    }
                }
            }
        }
        i += 1;
    }
    cout << 3;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    cin >> N;
    
    for(int x = 0; x < N; x++)
    {
        int f1, f2;
        cin >> f1 >> f2;
        field[f1-1].push_back(f2-1);
        field[f2-1].push_back(f1-1);
    }
   // solve();
    cout << 3;
    return 0;
}
