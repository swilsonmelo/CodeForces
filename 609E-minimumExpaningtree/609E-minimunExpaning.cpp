#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;

vector< pair<int,ii > > graph;
vector< pair<int,ii > > edges;
int parent[100005];
int V,E,u,v,w;;


int find(int x){
	if( parent[x] != x) {
		parent[x] = find(parent[x]);
	}
	return parent[x];
}


void unin( int x, int y){
	int xRaiz = find(x);
	int yRaiz = find(y);
	if(xRaiz != yRaiz) parent[yRaiz] = xRaiz;
}

long long kruskal(long long cost){
	//int cost = 0;
	for(int i = 0; i < E; i++){
		u = graph[i].second.first;
		v = graph[i].second.second;
		w = graph[i].first;
		if( find(u) != find(v)){
			cost += w;
			unin(u,v);
		}
	}
	return cost;
}


int main(){ 
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d %d",&V,&E);
	
	for(int i = 1; i <= V; i++) parent[i] = i;
	
	pair<int,ii> arc;
	for(int i = 0; i < E; i++){
		scanf("%d %d %d",&u,&v,&w);
		arc.first = w;
		arc.second.first = u;
		arc.second.second = v;
		graph.push_back(arc);
		edges.push_back(arc);
	}
	sort(graph.begin(),graph.end());
	long long cost,r ;
	for(int i = 0; i < E; i++){
		for(int i = 1; i <= V; i++) parent[i] = i;
		cost = edges[i].first;
		u = edges[i].second.first;
		v = edges[i].second.second;
		unin(u,v);
		r = kruskal(cost);
		cout << r <<endl;
		
	}
	
	return 0;
}
