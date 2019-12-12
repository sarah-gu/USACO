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
#include <bitset>
using namespace std;
class Fields
{
    int size;
    vector<int> adjList[100000];
    void DFS(int v, bool visited[], int prevField);
public:
    void make_Graph(int N);
    void addEdge(int e1, int e2);
    void findAllIslands();
    
};

int N, M;
Fields f;
map<pair<int,int>, char> checkSame;
bool hasDifferent = false;
int midx;

void Fields::make_Graph(int N)
{
    size = N;
    for(int x = 0; x < N; x++)
    {
        adjList[x].push_back(0);
    }
}
void Fields::addEdge(int e1, int e2)
{
    adjList[e1].push_back(e2);
    adjList[e2].push_back(e1);
}

map<int, int> popFields;
void Fields::DFS(int v, bool visited[], int prevField)
{
    visited[v] = true;
    if(prevField == -1)
    {
        popFields[v] = 1;
    }
    else
    {
        //cout << v << " " << prevField << endl;
        char c = checkSame[make_pair(v, prevField)];
       // cout << c << endl;
        if ( popFields.find(v) == popFields.end() ) {
            if(c == 'D')
            {
                if(popFields[prevField] ==1)
                {
                    popFields[v] = 2;
                }
                else
                    popFields[v] = 1;
            }
            else
            {
                if(popFields[prevField] ==1)
                {
                    popFields[v] = 1;
                }
                else
                    popFields[v] = 2;
            }
        }
        else
        {
            if(c == 'D')
            {
                if(popFields[v] == popFields[prevField])
                {
                    hasDifferent = true;
                }
            }
            else
            {
                if(popFields[v] != popFields[prevField])
                {
                    hasDifferent = true;
                }
            }
        }
    }
    vector<int> adj = adjList[v];
    for(int i = 0; i < adj.size(); i++)
    {
        if(visited[adj[i]])
        {
            char c = checkSame[make_pair(v, adj[i])];
            if(c == 'D')
            {
                if(popFields[v] == popFields[adj[i]])
                {
                    hasDifferent = true;
                }
            }
            else if(c == 'S')
            {
                if(popFields[v] != popFields[adj[i]])
                {
                    hasDifferent = true;
                }
            }
        }
        if(!visited[adj[i]])
            DFS(adj[i], visited, v);
    }
}
void Fields::findAllIslands()
{
    bool *visited = new bool[size];
    for(int v = 0; v < size; v++)
        visited[v] = false;
    int curComb= 1;
    vector<int> fieldsInComp;
    for (int v=0; v<size; v++)
    {
        if (visited[v] == false)
        {
            DFS(v, visited, -1);
            if(!hasDifferent)
                curComb = curComb* 2;
            hasDifferent = false;
        }
    }
    
    midx = curComb;
}
//binary conversion referenced from GeeksforGeeks
void toBinary(int n)
{
    if(n == 0)
    {
        cout << 0;
        exit(0);
    }
    bool checkPrint = false;
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
        {
            cout << "1";
            checkPrint = true;
        }
        else if(checkPrint)
        {
            cout << "0";
        }
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    cin >> N >> M;
    f.make_Graph(N);
    for(int x = 0; x < M; x++)
    {
        char c;
        int f1, f2;
        cin >> c >> f1 >> f2;
       // cout << f1 << " " << f2 << endl;
        checkSame[make_pair(f1-1,f2-1)] = c;
        checkSame[make_pair(f2-1,f1-1)] = c;
        f.addEdge(f1-1, f2-1);
        
    }
    f.findAllIslands();
    toBinary(midx);
    //cout << 10;
    return 0;
}
