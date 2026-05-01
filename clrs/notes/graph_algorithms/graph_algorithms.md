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

------------------------------