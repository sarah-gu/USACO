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
int N, C;
pair<int,int> cows[20000];
int chickens[20000];
unordered_set<int> alreadySeen;
void solve()
{
    int count = 0;
    for(int x = 0; x < N; x++)
    {
        for(int y = 0; y < C; y++)
        {
            unordered_set<int>::const_iterator check= alreadySeen.find(y);
            if(chickens[y] <= cows[x].first && chickens[y] >= cows[x].second && check == alreadySeen.end())
            {
                count += 1;
                alreadySeen.insert(y);
                break;
            }
            if(chickens[y] > cows[x].first)
                break;
        }
    }
    cout << count;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
    cin >> C >> N;
    for(int x = 0; x < C; x++)
    {
        cin >> chickens[x];
    }
    for(int y = 0; y < N; y++)
    {
        int p1, p2;
        cin >> p1 >> p2;
        cows[y] = make_pair(p2,p1);
    }
    sort(chickens, chickens+C);
    sort(cows, cows + N);
    solve();
    return 0;
}
