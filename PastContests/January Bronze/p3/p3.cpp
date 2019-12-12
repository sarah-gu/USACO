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
int arr[100];
void print()
{
    for(int x = 0; x < N; x++)
    {
        cout << arr[x] << " ";
    }
    cout << endl;
}
void insert(int unsortedidx)
{
    int temp = arr[0];
    for(int x = 0; x < unsortedidx; x++)
    {
        arr[x] = arr[x+1];
    }
    arr[unsortedidx] = temp;
   // print();
}
bool compare(int cp[100])
{
    for(int x = 0; x < N; x++)
    {
        if(cp[x] != arr[x])
            return true;
    }
    return false;
}

void solve(int cp[100])
{
    int sortedidx = -1;
    for(int x = N-1; x >0; x--)
    {
        if(arr[x-1] > arr[x] )
        {
            sortedidx =x;
            break;
        }
    }
    if(sortedidx == -1)
    {
        cout << 0;
        exit(0);
    }

    int count = 0;
    while(compare(cp) && sortedidx >=0)
    {
        count +=1;
        int unsortedidx = N-1;
        bool check = true;
        for(int y = sortedidx; y < N; y++)
        {
            //cout << sortedidx << endl;
            if(arr[0] < arr[y] && check)
            {
             //   cout << arr[y] << endl;
                unsortedidx = y-1;
                check = false;
            }
        }
//cout << unsortedidx << endl;
        insert(unsortedidx);
        sortedidx -=1;
    
       // print();
    }
    cout <<count;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    cin >> N;
    int cpArr[100];
    for(int x = 0; x < N; x++)
    {
        cin >> arr[x];
        cpArr[x] = arr[x];
    }
    sort(cpArr, cpArr+N);
    solve(cpArr);
    return 0;
}

