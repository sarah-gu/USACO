//
//  main.cpp
//  MooTube
//
//  Created by Sarah Gu on 12/31/18.
//  Copyright © 2018 Sarah Gu. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <stack>
#include <list>
using namespace std;
struct Video
{
    int id;
    vector<pair<Video,long long> > dirConn; //
};
void DFSUtil(Video v, bool visited[], Video original, long long **mat)
{
    // Mark the current node as visited and
    // print it
    visited[v.id] = true;
   // cout << v << " ";
    
    // Recur for all the vertices adjacent
    // to this vertex
    vector<pair<Video, long long> > adj = v.dirConn;
    for (int i = 0; i < adj.size(); i++)
    {
        if (!visited[adj[i].first.id])
        {
            DFSUtil(adj[i].first, visited, original, mat);
        }
    }
}

// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
void DFS(Video v, int N, long long **mat)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[N];
    for (int i = 0; i < N; i++)
        visited[i] = false;
    
    // Call the recursive helper function
    // to print DFS traversal
    DFSUtil(v, visited, v, mat);
}
void solve(Video *vids, pair<long long ,int> *question, int N, int Q)
{
    long long **mat;
    mat = new long long *[N];
    for(int i = 0; i < N; i++)
    {
        mat[i] = new long long [N];
    }
    
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("mootube.in", "r", stdin);
    //freopen("mootube.out", "w", stdout);
    int N, Q; // number of videos, number of questions
    cin >> N >> Q;
    unordered_set<int> container;
    Video graph[N];
    for(int x = 0; x < N-1; x++)
    {
        int vid1, vid2;
        long long relevance;
        cin >> vid1 >> vid2 >> relevance;
        if(container.find(vid1) != container.end() && container.find(vid2) != container.end())
        {
            Video v;
            v.id = vid1;
            Video v2;
            v2.id = vid2;
            v.dirConn.push_back(make_pair(v2, relevance));
        }
        else if(container.find(vid1) == container.end() && container.find(vid2) != container.end())
        {
            Video v;
            for(int i = 0; i < N-1; i++)
            {
                if(graph[i].id == vid1)
                {
                    v = graph[i];
                    break;
                }
            }
            Video v2;
            v2.id = vid2;
            v.dirConn.push_back(make_pair(v2, relevance));
        }
        else{
            Video v, v2;
            int count = 0;
            for(int i = 0; i < N-1; i++)
            {
                if(graph[i].id == vid1)
                {
                    v = graph[i];
                    count += 1;
                }
                if(graph[i].id == vid2)
                {
                    v2 = graph[i];
                    count += 1;
                }
                if(count == 2)
                    break;
            }
            v.dirConn.push_back(make_pair(v2, relevance));
        }
    }
    pair<long long, int> questions[Q];
    for(int y = 0; y < Q; y++)
    {
        long long k;
        int vid;
        cin >> k >> vid;
        questions[y] = make_pair(k, vid);
    }
    solve(graph, questions, N, Q);
    return 0;
}
