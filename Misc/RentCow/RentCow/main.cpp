//
//  main.cpp
//  RentCow
//
//  Created by Sarah Gu on 12/31/18.
//  Copyright © 2018 Sarah Gu. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>
using namespace std;
bool sortinrev(const pair<int,int> &a,
               const pair<int,int> &b)
{
    return (a.first > b.first);
}
pair<int,int> getMoney(int numGal, pair<int,int>* milk, int index, int M)
{
    int money = 0;
    while(numGal > 0)
    {
        if(index > M)
        {
            return make_pair(money, index);
        }
        if(numGal < milk[index].second)
        {
            milk[index].second -= numGal;
            return make_pair(numGal * milk[index].first + money, index);
        }
        else if(numGal == milk[index].second)
        {
            int tmoney = numGal * milk[index].first;
            index += 1;
            return make_pair(tmoney + money, index);
        }
        else if(numGal > milk[index].second)
        {
            money = milk[index].second * milk[index].first;
            numGal -= milk[index].second;
            index += 1;
            
        }
    }
    return make_pair(0,0);
}
void solve(int *cows, pair<int,int> *milk, int* rent, int N, int M, int R, int total)
{
    long long bestMoney = total;
    int index = 0;
    for(int x = 0; x < N; x++)
    {
        pair<int,int> newGain = getMoney(cows[x], milk, index, M);
      //  cout << cows[x] << " " << newGain.first << " " << bestMoney << endl;
        index = newGain.second;
        if(index > M)
        {
            cout << bestMoney << endl;
            exit(0);
        }
        if(newGain.first > rent[x])
        {
            bestMoney = bestMoney + newGain.first - rent[x];
        }
        else
        {
            int extraCow = N - R;
            int rentidx = x-1;
            int iter = x;
            while(extraCow > 0 && rentidx >= 0 && iter < N)
            {
                pair<int,int> tGain = getMoney(cows[iter], milk, index, M);
                if (rent[rentidx] > tGain.first)
                    bestMoney += rent[rentidx];
                else
                    bestMoney += tGain.first;
                extraCow -=1;
                rentidx -=1;
                iter +=1;
            }
            cout << bestMoney << endl;
            exit(0);
        }
        
    }
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    int N,M,R; // cows, milking money, renting money
    cin >> N >> M>>R;
    int cows[N];
    for(int x = 0; x < N; x++)
    {
        cin >> cows[x];
    }
    pair<int,int> milkStore[M];
    for(int y = 0; y < M; y++)
    {
        int t1,t2;
        cin >> t2 >> t1;
        milkStore[y] = make_pair(t1,t2);
    }
    int rentStore[R];
    for(int z = 0; z < R; z++)
    {
        cin >> rentStore[z];
    }
    sort(cows, cows+N, greater<int>());
    sort(milkStore,milkStore + M, sortinrev);
    sort(rentStore, rentStore + R);
    int allRent = 0;
    //cout << rentStore[0] << endl;
    if(N > R)
        allRent = accumulate(rentStore, rentStore + R, allRent);
    else
        allRent = accumulate(rentStore, rentStore + N, allRent);
   // cout << allRent << endl;
    solve(cows, milkStore, rentStore, N, M, R, allRent);
    return 0;
}

