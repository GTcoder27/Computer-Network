#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Structure to represent a graph node
struct Node {
    int id;
    vector<pair<int, int>> neighbors; // adjacency list
};

// Function to find the shortest path using Dijkstra's algorithm with backtracking
vector<int> dijkstraBacktrack(vector<Node>& graph, int start, int end) {
    int numNodes = graph.size();
    vector<int> distance(numNodes, numeric_limits<int>::max()); // distance to each node
    vector<int> parent(numNodes, -1); // parent node in the shortest path
    vector<bool> visited(numNodes, false); // visited nodes

    distance[start] = 0; // distance to the start node is 0

    // Priority queue to store nodes to be processed
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start}); // start node with distance 0

    while (!pq.empty()) {
        int currNode = pq.top().second;
        pq.pop();

        if (visited[currNode]) continue; // skip if already visited
        visited[currNode] = true;

        for (auto& neighbor : graph[currNode].neighbors) {
            int neighborNode = neighbor.first;
            int edgeWeight = neighbor.second;

            if (distance[currNode] + edgeWeight < distance[neighborNode]) {
                distance[neighborNode] = distance[currNode] + edgeWeight;
                parent[neighborNode] = currNode;
                pq.push({distance[neighborNode], neighborNode});
            }
        }
    }

    // Backtrack to find the shortest path
    vector<int> path;
    int currNode = end;
    while (currNode!= -1) {
        path.push_back(currNode);
        currNode = parent[currNode];
    }
    reverse(path.begin(), path.end());

    return path;
}

int main() {
    int numNodes = 6;
    vector<Node> graph(numNodes);

    // Add edges to the graph
    graph[0].neighbors = {{1, 4}, {2, 2}};
    graph[1].neighbors = {{0, 4}, {3, 5}};
    graph[2].neighbors = {{0, 2}, {3, 1}, {4, 3}};
    graph[3].neighbors = {{1, 5}, {2, 1}, {4, 2}};
    graph[4].neighbors = {{2, 3}, {3, 2}, {5, 4}};
    graph[5].neighbors = {{4, 4}};

    int startNode = 0;
    int endNode = 5;

    vector<int> shortestPath = dijkstraBacktrack(graph, startNode, endNode);

    cout << "Shortest path from " << startNode << " to " << endNode << ": ";
    for (int node : shortestPath) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}