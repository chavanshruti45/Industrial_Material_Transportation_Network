#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <string>
using namespace std;

const int V = 6;

const string units[V] = {
    "Raw Material Storage",
    "Cutting Unit",
    "Processing Unit",
    "Assembly Unit",
    "Quality Checking Unit",
    "Final Packaging Unit"
};

vector<pair<int, int>> graph[V];

void addRoute(int u, int v, int weight) {
    graph[u].push_back({v, weight});
    graph[v].push_back({u, weight});
}

void createNetwork() {
    addRoute(0, 1, 4);
    addRoute(0, 2, 2);
    addRoute(1, 2, 1);
    addRoute(1, 3, 5);
    addRoute(2, 3, 8);
    addRoute(2, 4, 10);
    addRoute(3, 4, 2);
    addRoute(3, 5, 6);
    addRoute(4, 5, 3);
}

void displayUnits() {
    cout << "\\n--- PRODUCTION UNITS ---\n";
    for (int i = 0; i < V; i++) {
        cout << i << ". " << units[i] << '\n';
    }
}

void displayNetwork() {
    cout << "\n--- INDUSTRIAL TRANSPORTATION NETWORK ---\n";
    for (int i = 0; i < V; i++) {
        cout << i << " - " << units[i] << ": ";
        for (const auto& edge : graph[i]) {
            cout << "(" << edge.first << ", weight " << edge.second << ") ";
        }
        cout << '\n';
    }
}

void dijkstra(int source, int destination) {
    vector<int> distance(V, INT_MAX);
    vector<int> parent(V, -1);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int currentDistance = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (currentDistance != distance[current]) {
            continue;
        }

        for (const auto& edge : graph[current]) {
            int next = edge.first;
            int weight = edge.second;

            if (distance[current] != INT_MAX &&
                distance[current] + weight < distance[next]) {
                distance[next] = distance[current] + weight;
                parent[next] = current;
                pq.push({distance[next], next});
            }
        }
    }

    if (distance[destination] == INT_MAX) {
        cout << "\nNo route is available between these units.\n";
        return;
    }

    vector<int> path;
    for (int node = destination; node != -1; node = parent[node]) {
        path.push_back(node);
    }
    reverse(path.begin(), path.end());

    cout << "\n--- SHORTEST TRANSPORTATION ROUTE ---\n";
    for (size_t i = 0; i < path.size(); i++) {
        cout << units[path[i]];
        if (i + 1 < path.size()) {
            cout << " -> ";
        }
    }

    cout << "\nTotal transportation distance: "
         << distance[destination] << " units\n";
}

int main() {
    createNetwork();

    int choice;
    do {
        cout << "\n===== INDUSTRIAL MATERIAL TRANSPORTATION NETWORK =====\n";
        cout << "1. Display production units\n";
        cout << "2. Display transportation network\n";
        cout << "3. Find shortest path\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "\nInvalid input. Please enter a number.\n";
            return 1;
        }

        switch (choice) {
            case 1:
                displayUnits();
                break;

            case 2:
                displayNetwork();
                break;

            case 3: {
                int source, destination;
                displayUnits();

                cout << "\nEnter source unit number (0-5): ";
                cin >> source;
                cout << "Enter destination unit number (0-5): ";
                cin >> destination;

                if (source < 0 || source >= V ||
                    destination < 0 || destination >= V) {
                    cout << "\nInvalid production unit number. Choose 0 to 5.\n";
                } else {
                    dijkstra(source, destination);
                }
                break;
            }

            case 4:
                cout << "\nThank you for using the system!\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
