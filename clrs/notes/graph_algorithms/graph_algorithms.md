# Graph Algorithms
All about basic graph data structure and its related algorithms:
- BFS
- DFS
- Shortest-Path (Djikstra's)

--------------------

## 1. Representations of Graphs
- There are two ways to represent a graph $G = (V, E)$:
  - **Adjacency list**: if $|E| << |V|^{2}$
  - **Adjacency matrix**: if $|E|$ is close to $|V|^{2}$

### 1.1 Adjacency List
- Complexity:
  - memory is $\Theta (V + E)$
  - finding each edge is $\Theta (V + E)$
- **Weighted graphs**: their edges are weighted by a *weight function w*.
- Good for small graphs.

### 1.2 Adjacency Matrix
- $|V| \times |V|$ matrix $A = (a_{ij})$:
```math
a_{ij} = \begin{cases}
    1 & \text{if } (i, j) \in E \\
    0 & \text{otherwise}
\end{cases}
```
  - can store $w(u,v)$ instead of 1 for **weighted graphs**.
  - 0 can also be NIL or $\infin$
- Complexity:
  - memory: $\Theta (V^{2})$
  - time finding each edge: $\Theta (V^{2})$
- For undirected graphs, $A = A^{T}$ because $(u,v)$ and $(v,u)$ are the same edge.
- Good for **unweighted graphs** (only one bit per entry).

------------------------------

## 2. Elementary Graph Algorithms

### 2.1 Breadth-First Search (BFS)
Given a graph $G=(V,E)$, and a source vertex $s$. From $s$, how to discover every other vertex by exploring edges of $G$.

BFS uses a **queue** to track vertices, containing two consecutive waves at any time (i.e., some vertices at a distance $k$, followed by some vertices at distance $k+1$).

BFS uses **colours** (white, gray, black) to keep track of progress.
- **White**: not reachable from $s$.
- **Gray**: first time discovered from $s$, now becoming the *frontier* of the search. -> The queue contains all gray vertices.
- **Black**: once all edges of a gray vertex are explored -> It becomes black.

**Breadth-First Tree** is a tree with root $s$, in which the path from $s$ to $v$ is the shortest path in $G$.

Whenerver the search discovers a white vertex $v$ in the course of scanning the adjacency list of a gray vertex $u$, the vertex $v$ and the edge $(u, v)$ are added to the tree.

$v \in V$ has attributes:
- $v.colour$
- $v.d$: distance from $s$ to $v$
- $v.\pi$: predecessor of $v$ in the breadth-first tree ($=\text{NIL}$ if $v$ has no predecessor)

BFS Algorithm for adjacency-list graphs
```python
BFS(G, s):  # O(V + E)
  for each vertex u in G.V - {s}:
    u.colour = WHITE
    u.d = ∞
    u.𝛑 = NIL
  
  s.colour = GRAY
  s.d = 0
  s.𝛑 = NIL
  ENQUEUE(Q, s)

  while Q ≠ ∅:
    u = DEQUEUE(Q)  # O(V)
    for each vertex v in G.Adj[u]:  # search neighbours of u - O(V + E)
      if v.colour == WHITE:
        v.colour = GRAY
        v.d = u.d + 1
        v.𝛑 = u
        ENQUEUE(Q, v) # v is on the frontier
    u.colour = BLACK  # u is behind the frontier
```

#### 2.1.1 Shortest Paths

#### 2.1.2 Breadth-First Trees

### 2.2 Depth-First Search (DFS)
Unlike BFS - trying to find widely - DFS tries to go deeper. That's why DFS is not used to solve Shortest Path problems. Instead, applications of DFS include:
- Topological Sort

In BFS, predecessor subgraph of vertex v is a single tree, but there multiple **depth-first trees** forming **depth-first forest** for DFS:
```math
E_{\pi} = \{ (v.\pi, v): v \in V \text{ and } v.\pi \neq \text{NIL} \}
```

DFS vertex has colour, $\pi$ like BFS. The difference is DFS tracks timestamps:
- $v.d$: Discover time
- $v.f$: Finish time

The reason DFS doesn't store distance from source to destination vertex because in BFS, we try to find in breadth mode, every vertex discovered in the shortest path as possible. But in DFS, we care about how many steps it takes to get from source $s$ to a vertex $v$.

```python
DFS(G):
  for vertex u in G.V:
    u.colour = WHITE
    u.pi = NIL
  time = 0

  for vertex u in G.V:
    if u.colour == WHITE:
      DFS_VISIT(G, u)

DFS_VISIT(G, u):
  time = time + 1
  u.d = time
  u.colour = GRAY

  for vertex v in G.Adj[u]:
    if v.colour == WHITE:
      v.pi = u
      DFS_VISIT(G, v)

  time = time + 1
  u.f = time
  u.colour = BLACK
```
------------------------------