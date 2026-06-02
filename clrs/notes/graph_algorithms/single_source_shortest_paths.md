# Single-Source Shortest Paths

Remember Google Map.

## 1. Fundamentals

### Definitions

**Input** 
- a weighted, directed graph $G=(V, E)$
- a weight function $w: E \rightarrow \mathbb{R}$, the weight $w(p) = \sum_{i=1}^k w(v_{i-1}, v_i)$ with path $p = [v_0, v_1,..., v_k]$.

**Output**
- Shortest path weight

```math
\delta(u,v) = \begin{cases}
    \min{w(p): u \overset{p}\leadsto} v & \text{if there is a path from } u \text{ to } v \\
    \infin & \text{otherwise}
\end{cases}
```

### Optimal Substructure

> Subgraphs of shortest paths are also shortest paths.

### Representing Shortest Paths

- Shortest paths trees

### Relaxation

- A technique
- Set $v.d = \infin$ where $v.d$ is the weight of the shortest path from $s$ to $v$ (a shortest path estimate).

## 2. Bellman-Ford Algorithm

Bellman-Ford algo returns boolean values, TRUE if no negative-weight cycles.

```python
BELLMAN_FORD(G, w, s)
    INITIALISE_SINGLE_SOURCE(G, s)

    for i = 1 to |G.V| - 1
        for each edge (u, v) in G.E
            RELAX(u, v, w)
    
    for each edge (u, v) = G.E
        if v.d > u.d + w(u, v)
            return FALSE
    
    return TRUE
```

## 3. Dijkstra's Algorithm

- BFS on weighted graphs

```python
DIJKSTRA(G, w, s)
    INITIALISE_SINGLE_SOURCE(G, s)

    S = ∅
    Q = ∅

    for each vertex u in G.V:
        INSERT(Q, u)

    while Q != ∅:
        u = EXTRACT_MIN(Q)
        S = S ∪ {u}

        for each vertex v in G.Adj[u]:
            RELAX(u, v, w)
            if the call of RELAX decreased v.d:
                DECREASE_KEY(Q, v, v.d)
```