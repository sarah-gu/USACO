#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
unordered_set<string> alreadySeen;
string cowForm;
int N;
pair<int,int> locationL;
pair<int,int> locationR;
int recurseDepth = 0;
bool oneCowLeft(string s)
{
    int countR = 0;
    int countL = 0;
    for(int x = 0; x < s.length(); x++)
    {
        if(s[x] == 'R')
        {
            countR += 1;
            locationR.first = x/N +1;
            locationR.second = x%N +1;
        }
        if(s[x] == 'L')
        {
            countL += 1;
            locationL.first = x/N +1;
            locationL.second = x%N +1;
        }
        if(countR > 1 && countL > 1)
            return false;
    }
    if(countR == 0 || countL == 0)
    {
        cout << -1 << endl;
        exit(0);
    }
    if(countR <=1)
    {
        cout << locationR.first << " " << locationR.second << endl;
        exit(0);
    }
    else
    {
        cout << locationL.first << " " << locationL.second << endl;
        exit(0);
    }
    return true;
}
string switchRow(string cur, int rowIdx)
{
    for(int x = rowIdx*N; x < rowIdx*N+N; x++)
    {
        if(cur[x] == 'R')
        {
            cur[x] = 'L';
        }
        else{
            cur[x] = 'R';
        }
    }
    return cur;
}
string switchCol(string cur, int colIdx)
{
    cout << colIdx << endl;
    for(int x = colIdx; x < cur.length(); x+= N)
    {
        cout << x << endl;
        if(cur[x] == 'R')
        {
            cur[x] = 'L';
        }
        else{
            cur[x] = 'R';
        }
    }
    cout << cur << endl;
    return cur;
}
void print(string s)
{
    int count = 0;
    for(int x = 0; x < N; x++)
    {
        for(int y = 0; y < N; y++)
        {
            cout << s[count];
            count += 1;
        }
        cout << endl;
    }
    cout << endl;
}
int recurse(string curArr)
{
    recurseDepth += 1;
    cout << "RECURSE" << recurseDepth << endl;
  //  print(curArr);
    
    if(oneCowLeft(curArr))
    {
        return 1;
    }
    unordered_set<string>::const_iterator got = alreadySeen.find(curArr);
    if(got != alreadySeen.end())
    {
        return -1;
    }
    else{
        alreadySeen.insert(curArr);
        for(int x = 0; x < N; x++)
        {
            //string newRow = curArr;
         //   string newCol = curArr;
            //cout << newRow << endl;
            
            recurse(switchCol(curArr, x));
           // cout << "HI " << endl;
            recurse(switchRow(curArr, x));
        }
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("leftout.in", "r", stdin);
    //freopen("leftout.out", "w", stdout);
    cin >> N;
    for(int x = 0; x < N; x++)
    {
        string s;
        cin >> s;
        cowForm += s;
    }
   // alreadySeen.insert(cowForm);
    recurse(cowForm);
    cout << -1 << endl; 
    return 0;
}
