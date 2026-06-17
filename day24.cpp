//graphs in c++
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>

using namespace std;

class Graph{
public:
map<string, vector<string>> adjacency_list;
void add_edge(string node1, string node2){
    adjacency_list[node1].push_back(node2);
    adjacency_list[node2].push_back(node1); //undirected
}
void display(){
    for (auto& pair : adjacency_list){
        cout<<pair.first<<" -> ";
        for (string neighbour : pair.second){
            cout<< neighbour << " ";
        }
        cout<< endl;
    }
}
void bfs(string start){
    set < string > visited;
    queue < string > q;

    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        string node = q.front();
        q.pop();
        cout<< node << " ";

        for (string neighbour : adjacency_list[node]) {
            if (visited.find(neighbour)==visited.end()){
                visited.insert(neighbour);
                q.push(neighbour);
            }
        }
    }
    cout<< endl;
}
void dfs(string start) {
    set <string> visited;
    stack <string> s;

    s.push(start);

    while (!s.empty()) {
        string node= s.top();
        s.pop();

        if (visited.find(node)== visited.end()){
            visited.insert(node);
            cout<<node <<" ";

            for (string neighbour : adjacency_list[node]) {
                if (visited.find(neighbour)== visited.end()){
                    s.push(neighbour);
                }
            }
        }
    }
    cout<< endl;
}

};
int main(){
    Graph g;
    g.add_edge("A","B");
    g.add_edge("A","C");
    g.add_edge("B","D");
    g.add_edge("C","D");

    g.dfs("A");
    g.display();
    g.bfs("A");

    return 0;
}