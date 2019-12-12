//
//  p1.cpp
//  
//
//  Created by Sarah Gu on 1/20/19.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int N;
map<string, vector<string> > m;
map<string, int> numOccur;

void solve(int high, string animal)
{
    int bestCount = 0;
    for (auto const& x : m)
    {
        vector<string> secCh = x.second;
        for(auto const& y : m)
        {
            if(x != y)
            {
                vector<string> c3 = y.second;
                int count = 0;
                for(int i = 0; i < c3.size(); i++)
                {
                    if(find(secCh.begin(), secCh.end(), c3[i]) != secCh.end())
                    {
                        count +=1;
                    }
                }
                if(count > bestCount)
                {
                    bestCount = count;
                }
            }
        }
    }
    cout << bestCount +1;
   /* vector<string> character=  m[animal];
    int pos = 0, count = 0;
    for(int z = 0; z < high; z++)
    {
        string curChar = character[pos];
      //  cout<<curChar << endl;
        bool check = false;
        for (auto const& x : m)
        {
            if(x.first != animal)
            {
                vector<string> secCh = x.second;
                for(int y = 0; y < secCh.size(); y++)
                {
                    if(secCh[y] == curChar)
                    {
                   //     cout<< x.first << endl;
                        check = true;
                        break;
                    }
                }
                if(check)
                    break;
            }
        }
        if(check)
        {
            count +=1;
        }
        pos +=1;
        
    }
    cout << (1+ count); */
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
    cin >> N;
    int highNum = 0;
    string testAnimal = "";
    for(int x = 0; x < N; x++)
    {
        string animal;
        int number;
        cin >> animal >> number;
        if(number >= highNum)
        {
            highNum = number;
            testAnimal = animal;
        }
        for(int y = 0; y < number; y++)
        {
            string ch;
            cin >> ch;
            m[animal].push_back(ch);
            numOccur[ch] += 1;
        }

    }


    solve(highNum, testAnimal);
    return 0;
}

