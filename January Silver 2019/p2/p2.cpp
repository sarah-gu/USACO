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
int grid[1000][1000];
int N;
int alreadySeen[1000][1000];
bool sortinrev(const pair<int,int> &a,
               const pair<int,int> &b)
{
   // if(a.first == b.first)
      //  return a.second <= b.second;
    return (a.first > b.first);
}
pair<int,int> recurse(int r, int c)
{
    if(alreadySeen[r][c] == 1)
        return make_pair(0,0);
    if(r >= N || c >= N || r < 0 || c < 0 || grid[r][c] == 0)
        return make_pair(0,1);
    else{
        grid[r][c] = 0;
        alreadySeen[r][c] = 1;
        pair<int,int> getLeft = recurse(r, c-1);
        pair<int ,int> getRight = recurse(r, c+1);
        pair<int,int> getUp = recurse( r-1, c);
        pair<int,int> getDown = recurse(r+1, c);
        return make_pair(1+ getLeft.first + getRight.first + getUp.first+ getDown.first, getLeft.second + getRight.second + getUp.second + getDown.second);
    }
}
void solve()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            alreadySeen[i][j] = 0;
    }
    vector<pair<int,int> > vect;
    for(int x = 0; x < N; x++)
    {
        for(int y = 0; y < N; y++)
        {
            if(grid[x][y] == 1)
            {
                vect.push_back(recurse(x,y));
                
            }
        }
    }
    sort(vect.begin(), vect.end(), sortinrev);
    cout << vect[0].first << " " << vect[0].second;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    cin >>N;
    for(int x = 0; x < N; x++)
    {
        string ch;
        cin >> ch;
        for(int y = 0; y < N; y++)
        {
            if(ch[y] == '#')
                grid[x][y] = 1;
            else
                grid[x][y] = 0;
        }

    }
    solve();
    return 0;
}
