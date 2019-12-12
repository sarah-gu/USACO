
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
unordered_set<int> rowSet;
unordered_set<int> colSet;
string rows[1000];
string oppRow[1000];
string cols[1000];
string oppCol[1000];
int tallyM[1000][1000];
int N;
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("leftout.in", "r", stdin);
    freopen("leftout.out", "w", stdout);
    cin >> N;
    for(int x = 0; x < N; x++)
    {
        string s;
        cin >> s;
        string oppStr = "";
        for(int z = 0; z < N; z++)
        {
            if(s[z] == 'R')
            oppStr += 'L';
            else
            oppStr += 'R';
        }
        rows[x] = s;
        oppRow[x] = oppStr;
        for(int y = 0; y < N; y++)
        {
            cols[y] += s[y];
            oppCol[y] += oppStr[y];
        }
    }
    for(int r = 0; r < N; r++)
    {
        for(int comp = r+1; comp < N; comp++)
        {
            if(rows[r] == rows[comp] || oppRow[r] == rows[comp])
            {
               // cout << rows[r] << " " << rows[comp] << endl ;
                rowSet.insert(r);
                rowSet.insert(comp);
            }
            if(cols[r] == cols[comp] || oppCol[r] == cols[comp])
            {
                colSet.insert(r);
                colSet.insert(comp);
            }
        }
    }
    int lowX, lowY, count;
    for(int p = 0; p < N; p++)
    {
        for(int m = 0; m < N; m++)
        {
            unordered_set<int>::const_iterator getR = rowSet.find(p);
            unordered_set<int>::const_iterator getC = colSet.find(m);
            if(getR == rowSet.end() && getC == colSet.end())
            {
              //  cout << p << " " << m << endl;
                if(count == 0)
                {
                    lowX = p+1;
                    lowY = m + 1;
                }
                count += 1;
            }
        }
    }
    
    if(count == 1)
    {
        cout << lowX << " " << lowY << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}
