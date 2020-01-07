#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

bool unvisited(vector<bool> &visited){
	for(int i = 0; i < visited.size() ; i++){
		if(!visited[i]){
			return true;
		}
	}
	return false;
}

int min_univisited(vector<long long> &dist,vector<bool> &visited){
	long long min = INFINITY;
	for(int i = 0; i < dist.size();i++){
		if(min > dist[i] && !visited[i]){
			min = i;
		}
	}
	return min;
}

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code here
  vector<long long> dist(adj.size(),10000);
  vector<bool> visited(adj.size(),false);
  dist[s] = 0;
  while(unvisited(visited)){
  	int u = min_univisited(dist,visited);
  	visited[u] = true;
  	for(int i = 0; i < adj[u].size() ; i++){
  		int v = adj[u][i];
  		if(dist[v] > dist[u] + cost[u][i]){
  			dist[v] = dist[u] + cost[u][i];
		  }
	  }
  }
  if(dist[t] == 10000){
  	return -1;
  }
  return dist[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
