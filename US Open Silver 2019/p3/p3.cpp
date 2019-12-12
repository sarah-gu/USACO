#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;
class Friends
{
    int size;
    vector<int> adjList[100000];
    void DFS(int v, bool visited[]);
    public:
    void make_Graph(int N);
    void addEdge(int e1, int e2);
    void findAllNetworks();
    
};
int N, M;
Friends f;
pair<int,int> cowCoords[100000];
int lowX, lowY, highX , highY;
int absbestX, absbestY ;
void Friends::make_Graph(int N)
{
    size = N;
    for(int x = 0; x < N; x++)
    {
        adjList[x].push_back(0);
    }
}
void Friends::addEdge(int e1, int e2)
{
    adjList[e1].push_back(e2);
    adjList[e2].push_back(e1);
}
void Friends::DFS(int v, bool visited[])
{
    visited[v] = true; //look at current cow now
    pair<int,int> curCoord = cowCoords[v];
  //  cout << curCoord.first << " " << curCoord.second << endl;
    if(curCoord.first < lowX)
    {
        lowX = curCoord.first;
    }
    if(curCoord.first > highX)
    {
        highX = curCoord.first;
    }
    if(curCoord.second < lowY)
    {
        lowY = curCoord.second;
    }
    if(curCoord.second > highY)
    {
        highY = curCoord.second;
    }
   // cout << "LOW: " << lowX << " " << lowY << " " << highX << " " << highY << endl;
    vector<int> adj = adjList[v];
    for(int i = 0; i < adj.size(); i++)
    if(!visited[adj[i]])
    DFS(adj[i], visited);
}
void Friends::findAllNetworks()
{
    bool *visited = new bool[size];
    absbestX = 100000000;
    absbestY = 100000000;
    for(int v = 0; v < size; v++)
    visited[v] = false;
    for (int v=0; v<size; v++)
    {
        lowX = 100000000, lowY = 100000000, highX = 0, highY = 0;
        if (visited[v] == false)
        {
            DFS(v, visited);
            if(((highX - lowX) + (highY - lowY))< (absbestX + absbestY))
            {
                absbestX = (highX-lowX);
                absbestY = (highY - lowY);
              //  cout << "ABSBEST " << absbestX << " " << absbestY << endl;
            }
            
        }
    }
    long long perimeter = (2*absbestX) + (2*absbestY);
    cout << perimeter << endl;
    exit(0);
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    cin >> N >> M;
    f.make_Graph(N);
    for(int x = 0; x < N; x++)
    {
        int xcoord, ycoord;
        cin >> xcoord >> ycoord;
        cowCoords[x] = make_pair(xcoord,ycoord);
    }
   // cout << "HI" << endl;
    for(int y = 0; y < M; y++)
    {
        int e1,e2;
        cin >> e1 >> e2;
     //   cout << e1 << " " << e2 << endl;
        f.addEdge(e1-1,e2-1);
    }
  //  cout << "HI" << endl;
    f.findAllNetworks();
    

    return 0;
}
