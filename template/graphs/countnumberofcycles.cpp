
#include<iostream>
#include<vector>
using namespace std;

//adjacency list for representation of a graph
// vector<int> arr[51];
int visited[200001];
int DiscoveryTime[200001];
int timer=1,k=0;
//function  for cycle detection
void Cycle_Detecter(int node,vector<int>adj[],int par){

    DiscoveryTime[node]=timer;
    timer++;

    visited[node]=1;

    for(int child:adj[node]){
        if(child==par){
            continue;
        }
        if(visited[child]==1 && DiscoveryTime[child]<DiscoveryTime[node]){
            k++;
        }
        if(visited[child]!=1)
           Cycle_Detecter(child,adj,node);

    }


}
int main(){

   
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
        int n,m;cin>>n>>m;
    vector<int>adj[n];
    for(int i=0;i<m;i++)
    {
        int a,b;cin>>a>>b;
        --a;--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            Cycle_Detecter(i,adj,-1);
        }
    }
    cout<<k<<endl;
    return 0;

}
