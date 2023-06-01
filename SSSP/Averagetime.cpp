// Created by DELL on 6/1/2023.
//
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX

// Structure to represent a node in the graph
struct Node {
    int id;
    int distance;

    Node(int _id, int _distance) : id(_id), distance(_distance) {}

    // Overloading the comparison operator for min-heap
    bool operator<(const Node& other) const {
        return distance > other.distance;
    }
};

// Function to perform Dijkstra's algorithm
void dijkstra(const vector<vector<int>>& graph, int source, vector<int>& totalTimes) {
    int n = graph.size();

    // Create a vector to store the distances from the source
    vector<int> distances(n, INF);
    distances[source] = 0;

    // Create a priority queue to store the nodes to be processed
    priority_queue<Node> pq;
    pq.push(Node(source, 0));

    // Process all nodes in the priority queue
    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int u = current.id;
        int dist = current.distance;

        // If the current distance is already greater than the stored distance, skip
        if (dist > distances[u]) {
            continue;
        }

        // Process all neighbors of the current node
        for (int v = 0; v < n; ++v) {
            // Skip if there is no edge between u and v
            if (graph[u][v] == 0) {
                continue;
            }

            // Calculate the new distance
            int newDist = distances[u] + graph[u][v];

            // If the new distance is smaller, update the distance and push the node to the priority queue
            if (newDist < distances[v]) {
                distances[v] = newDist;
                pq.push(Node(v, newDist));
            }
        }
    }

    // Update the total times for each city
    for (int i = 0; i < n; ++i) {
        totalTimes[i] += distances[i];
    }
}

// Function to calculate the average time for each source city
void calculateAverageTimes(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> totalTimes(n, 0);

    // Run Dijkstra's algorithm for each source city
    for (int source = 0; source < n; ++source) {
        dijkstra(graph, source, totalTimes);
    }

    // Find the smallest average time
    int smallestAverage = INF;
    vector<int> smallestCities;

    for (int i = 0; i < n; ++i) {
        int averageTime = totalTimes[i] / n;

        if (averageTime < smallestAverage) {
            smallestAverage = averageTime;
            smallestCities.clear();
            smallestCities.push_back(i);
        } else if (averageTime == smallestAverage) {
            smallestCities.push_back(i);
        }
    }

    // Print the cities with the smallest average time
    cout << "Cities with the smallest average time: ";
    for (int city : smallestCities) {
        cout << city << " ";
    }
    cout << endl;

    // Print the smallest average time
    cout << "Smallest average time: " << smallestAverage << endl;
}



int main() {
    // Define the weighted adjacency matrix
    vector<vector<int>> graph = {
            {0, 10, 0, 0, 15, 5},
            {10, 0, 10, 30, 0, 0},
            {0, 10, 0, 12, 5, 0},
            {0, 30, 12, 0, 0, 20},
            {15, 0, 5, 0, 0, 0},
            {5, 0, 0, 20, 0, 0}
    };

    // Calculate the average time for each source city
    calculateAverageTimes(graph);

    return 0;
}
