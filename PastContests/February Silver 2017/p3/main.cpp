//
//  main.cpp
//  
//
//  Created by Sarah Gu on 1/30/19.
//


#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
int N, K, R;

pair<int,int> cows[10000];
vector<pair<pair<int,int> , pair<int,int> > > roads;
bool cellsAllBlocked(int r, int c)
{
    pair<int,int> p1 = make_pair(r,c);
    if(r-1 >=0)
    {
        pair<pair<int,int>, pair<int,int> >check= make_pair(make_pair(r-1, c),p1);
        if(find(roads.begin(), roads.end(), check) == roads.end())
            return true;
    }
    if(r+1 < N)
    {
         pair<pair<int,int>, pair<int,int> >check= make_pair(make_pair(r+1, c),p1);

        if(find(roads.begin(), roads.end(), check)  == roads.end())
            return true;
    }
    if(c+1 < N)
    {
        pair<pair<int,int>, pair<int,int> >check= make_pair(make_pair(r, c+1),p1);
        if(find(roads.begin(), roads.end(), check)  == roads.end())
            return true;
    }
    if(c-1 >=0)
    {
        pair<pair<int,int>, pair<int,int> >check= make_pair(make_pair(r, c-1),p1);
        if(find(roads.begin(), roads.end(), check)  == roads.end())
            return true;
    }
    return false;
}
bool recurse(int r, int c, int tr, int tc, int field[100][100])
{
    if(r >= N || r < 0 || c >= N || c < 0||!cellsAllBlocked(r,c) || field[r][c] == 1)
    {
        return false;
    }
    else if(r == tr && c == tc)
    {
       // cout << "HI" << endl;
        return true;
    }
    else{
        field[r][c] = 1;
        return(recurse(r-1,c,tr,tc, field) || recurse(r+1, c, tr,tc,field) || recurse(r,c+1, tr,tc,field) || recurse(r,c-1, tr,tc,field));
    }
}
void solve()
{
    int count = 0;

    for(int x = 0; x < K; x++)
    {
        int field[100][100];
        for(int y = x+1; y < K; y++)
        {
            pair<int,int> cow1Coord = cows[x];
            pair<int,int> cow2Coord = cows[y];
            if(!recurse(cow1Coord.first, cow1Coord.second, cow2Coord.first, cow2Coord.second, field))
            {
                count += 1;
            }
        }
    }
    cout << count;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
    cin >> N >> K >> R;
    for(int x = 0; x < R; x++)
    {
        int p1, p2, p3, p4;
        cin >> p1 >> p2 >> p3 >> p4;
        pair<int,int> field1  = make_pair(p1-1,p2-1);
        pair<int,int> field2 = make_pair(p3-1,p4-1);
        roads.push_back(make_pair(field1, field2));
        roads.push_back(make_pair(field2, field1));
    }
    for(int y = 0; y < K; y++)
    {
        int r1,r2;
        cin >> r1 >> r2;
        cows[y] = make_pair(r1-1,r2-1);
    }
    solve();
    return 0;
}
