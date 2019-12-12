/*
 ID: guwen881
 PROG: gift1
 LANG: C++
 */
//  main.cpp
//  gift1
//
//  Created by Sarah Gu on 10/30/18.
//  Copyright © 2018 Sarah Gu. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(int argc, const char * argv[]) {
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);
    int N;
    cin >> N;
    map<string, int> bankAcc;
    string order[N];
    for(int x = 0; x < N; x++)
    {
        string temp;
        cin >> temp;
        order[x] = temp;
        bankAcc[temp] = 0;
    }
   // cout << "HI" << endl;
    for(int alg = 0; alg < N; alg++)
    {
        string giver;
        cin >> giver;
        int amt;
        cin >> amt;
        int numtoGive;
        cin >> numtoGive;
        if(numtoGive == 0)
            continue;
        bankAcc[giver] -= amt;
        int perPerson = amt/numtoGive;
      //  cout << amt << " " << numtoGive <<  " " << perPerson << endl;
        for(int names = 0; names < numtoGive; names ++)
        {
            string name;
            cin >> name;
        //    cout << name << endl;
            bankAcc[name] += perPerson;
        }
        int rem = amt%numtoGive;
      //  cout << rem << endl;
      //  cout << rem << endl;
        bankAcc[giver] += rem;
    }
    
    for (int pos = 0; pos < N; pos++) {
        cout << order[pos] << " " << bankAcc[order[pos]] << endl; 
    }
    return 0;
}
