# Industrial Material Transportation Network

A menu-driven C++ DSA mini project that models an industrial transportation
network as a weighted, undirected graph and uses Dijkstra's algorithm to find
the shortest route between two production units.

## Production units

| ID | Production unit |
|---:|---|
| 0 | Raw Material Storage |
| 1 | Cutting Unit |
| 2 | Processing Unit |
| 3 | Assembly Unit |
| 4 | Quality Checking Unit |
| 5 | Final Packaging Unit |

## Routes and weights

| Route | Weight |
|---|---:|
| 0 - 1 | 4 |
| 0 - 2 | 2 |
| 1 - 2 | 1 |
| 1 - 3 | 5 |
| 2 - 3 | 8 |
| 2 - 4 | 10 |
| 3 - 4 | 2 |
| 3 - 5 | 6 |
| 4 - 5 | 3 |

Weights represent transportation distance/cost units. All routes are
bidirectional and have non-negative weights.

## Features

- Display all production units.
- Display the weighted transportation network.
- Select a source and destination unit.
- Calculate and display the shortest route and total weight.
- Menu-driven console interface.

## Algorithm

Dijkstra's shortest-path algorithm is implemented with an adjacency list
and a min-priority queue.

**Time complexity:** `O((V + E) log V)` with an adjacency list and priority
queue.

## Compile and run

### Windows (MinGW / VS Code terminal)

```bash
g++ -std=c++11 -Wall -Wextra main.cpp -o main.exe
.\main.exe
```

### Linux / macOS

```bash
g++ -std=c++11 -Wall -Wextra main.cpp -o main
./main
```

## Sample test

Choose option `3`, source `0`, destination `5`.

Expected shortest route:

`Raw Material Storage -> Processing Unit -> Cutting Unit -> Assembly Unit -> Quality Checking Unit -> Final Packaging Unit`

Expected total weight: **13 units**.

## Project structure

```text
Industrial-Material-Transportation/
├── main.cpp
├── README.md
├── .gitignore
├── sample_output.txt
└── screenshots/
    └── network_diagram.png
```

## Applications

- Factory material movement planning
- Production-unit connectivity
- Logistics and route optimization
- Learning weighted graphs and shortest-path algorithms

## Author

Add your name and class/department here.
