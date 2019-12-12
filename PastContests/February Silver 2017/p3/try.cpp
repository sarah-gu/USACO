//try
//
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
bool cellsNotAllBlocked(int r, int c, int pr, int pc)
{
    if(r == pr && c == pc)
        return true;
    else
    {
        pair<int,int> p1 = make_pair(r,c);
        pair<pair<int,int>, pair<int,int> >check= make_pair(make_pair(pr, pc),p1);
        if(find(roads.begin(), roads.end(), check) == roads.end())
        {
          //  cout << check.first.first << " " << check.first.second << " " << check.second.first << " " << check.second.second << endl;
            return true;
        }
        else
            return false;
        
    }
}
bool recurse(int r, int c, int tr, int tc, int pr, int pc, int field[100][100])
{
    cout << field[r][c] << endl;
//
    if(r >= N || r < 0 || c >= N || c < 0|| !cellsNotAllBlocked(r,c, pr, pc)|| field[r][c] == 1)
    {
        return false;
    }
    else if(r == tr && c == tc)
    {
        cout << r << " " << c << " " << tr << " " << tc << endl;
        return true;
    }
    else{
        field[r][c] = 1;
        return(recurse(r-1,c,tr,tc,r,c, field) || recurse(r+1, c, tr,tc,r,c,field) || recurse(r,c+1, tr,tc,r,c,field) || recurse(r,c-1, tr,tc,r,c,field));
    }
}
void solve()
{
    int count = 0;
    
    for(int x = 0; x < K; x++)
    {
        int field[100][100];
        for(int reset = 0; reset < N; reset++)
        {
            for(int hi = 0; hi < N; hi++)
            {
                field[reset][hi] = 0;
            }
        }
        for(int y = x+1; y < K; y++)
        {
            pair<int,int> cow1Coord = cows[x];
            pair<int,int> cow2Coord = cows[y];
            if(!recurse(cow1Coord.first, cow1Coord.second, cow2Coord.first, cow2Coord.second,cow1Coord.first, cow1Coord.second, field))
            {
                
                count += 1;
            }
            else
                cout << "HI" << endl;
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
