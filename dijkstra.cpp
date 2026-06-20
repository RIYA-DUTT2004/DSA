#include<iostream>
#include<vector>
#include <queue>
#include <climits>
using namespace std;
class graph{
    public:
    int V;
    int wt;
    
    graph(int v,int wt){
        this->V=v;
        this->wt=wt;
    }

};
void dij(int src, vector<vector<graph>> g,int V){
    vector<int> dis(V,INT_MAX);
    dis[src]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({dis[src],src});
    while(pq.size()>0){
        int u=pq.top().second;
        int cost=pq.top().first;
        pq.pop();
        for(graph e: g[u]){
            if(dis[e.V]>e.wt+dis[u]){
                dis[e.V]=e.wt+dis[u];
                pq.push({dis[e.V],e.V});
            }
        }
    }
    for(int i=0;i<dis.size();i++){
        cout<<"Cost to reach "<<i<<": "<<dis[i]<<endl;
    }

}
int main(){
    int V=6;
    vector<vector<graph>> g(6);
    g[0].push_back(graph(1,1));
    g[0].push_back(graph(2,2));
    g[1].push_back(graph(3,3));
    g[1].push_back(graph(2,4));
    g[2].push_back(graph(4,1));
    g[3].push_back(graph(5,5));
    g[3].push_back(graph(4,2));
    g[4].push_back(graph(5,3));
    dij(0,g,V);

}