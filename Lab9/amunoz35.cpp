//Collaborators: N/A
//Sources: Introduction to Algorithms: 3rd Edition. Strongly Connected Components: Using a directed graph G = (V,E)
//The inputs will be in the appropriate order: V for the number of vertices, E for edges and will output the id of the vertex
//To accommodate for this, the depth first search must be called
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool test[101] = {false};
vector<int> adjacent[101];
vector<int> temp_vec[101];
vector<int> order;
vector<vector<int>> StrongConnection;

void DepthFirst(vector<int> graph[], vector<int> &res, int n){
	test[n] = true;
	for(int i = 0; i < graph[n].size(); i++){
		if(!test[graph[n][i]]){
			DepthFirst(graph, res, graph[n][i]);
		}
	res.push_back(n);
	}
}

int main(){
	int V = 0;
	int E = 0;
	int t1, t2;
	cin >> V >> E;
	int A[V];
	for(int i = 0; i < V; i++){
		A[i] = i;
	}
	for(int i = 0; i < E; i++){
		cin >> t1 >> t2;
		adjacent[t1].push_back(t2);
	}
	for(int i = 0; i < V; i++){
		if(!test[i]){
			DepthFirst(adjacent, order, i);
		}
	}
	for(int i = 0; i < V; i++){
		for(int j = 0; j < adjacent[i].size(); j++){
			temp_vec[adjacent[i][j]].push_back(i);
		}
	}
	for(int i = 0; i < V; i++){
		test[i] = false;
	}
	reverse(order.begin(), order.end());
	for(int i = 0; i < order.size(); i++){
		if(!test[order[i]]){
			vector<int> compon;
			DepthFirst(temp_vec, compon, order[i]);
			StrongConnection.push_back(compon);
		}
	}
	for(int i = 0; i < StrongConnection.size(); i++){
		for(int j = 0; j < StrongConnection[i].size(); j++){
			int compare = StrongConnection[i][j];
			for(int k = 0; k < V; k++){
				if(A[k] == compare){
					A[k] = *min_element(StrongConnection[i].begin(), StrongConnection[i].end());
				}
			}
		}
	}
	for(int i = 0; i < V; i++){
		cout << A[i] << endl;
	}
}