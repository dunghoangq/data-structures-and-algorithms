CLRS Problems: Representations of Graph
=========================================

## 20.1-1
> Given an adjacency-list representation of a directed graph, how long does it take to compute the out-degree of every vertex? How long does it take to compute the in-degrees?
------------------------------
$G = (V, E)$
- |V| := # vertices
- |E| := # edges

e.g., 
- 1: [2, 3]
- 2: [3]
- 3: [4]
- 4: [1, 2]

-> So it'd take $O(|E|)$ to compute the out-degree of every vertex.
But for in-degrees, manually we consider every vertex v in V, look up for v in every set of edges, so roughly $O(|V||E|)$.

---------------------------

## 20.1-2
> Give an adjacency-list representation for a complete binary tree on 7 vertices. Give an equivalent adjacency-matrix representation. Assume that the edges are undirected and that the vertices are numbered from 1 to 7 as in a binary heap.
-------------------------------
- 1: [2]
- 2: [1, 3, 4]
- 3: [2]
- 4: [2, 6]
- 5: [6]
- 6: [4, 5, 7]
- 7: [6]

-------------------------------

## 20.1-3
> The transpose of a directed graph $G = (V, E)$ is the graph $G^{T} = (V, E^{T})$, where $E^{T} = \{(v, u) \in V \times V: (u,v) \in E\}$. That is, $G^{T}$ is $G$ with all its edges reversed. Describe efficient algorithms for computing $T^{T}$ from $G$, for both the adjacency-list and adjacency-matrix representations of $G$. Analyse the running times of your algorithms.
----------------------------------
Not very fast algo
### Adjacency list
```python
TRANSPOSE_GRAPH(V , E):         # O(|V|+|E|)
    E_T = {}

    for u in V:                 # Θ(|V|)
        for v in E[u]:          # O(|E|)
            E_T[v].append(u)
```

### Adjacency matrix
```python
TRANSPOSE_GRAPH(V, E: matrix):  # Θ(|V|^2)
    Create new matrix new_E having same size with E, all cell = 0
    for i in range(|V|):        # Θ(|V|)
        for j in range(|V|):    # Θ(|V|)
            if E[i][j] == 1:
                new_E[j][i] = 1
```

-----------------------------------

## 20.1-4
> Given an adjacency-list representation of a multigraph $G = (V, E)$, describe an $O(V + E)$-time algorithm to compute the adjacency-list representation of the "equivalent" undirected graph $G'=(V,E')$, where $E'$ consists of the edges in $E$ with all multiple edges between two vertices replaced by a single edge and with all self-loops removed.
--------------------------------

A multi-graph is a graph allowing multiple edges between two nodes.
- 1: [1, 2, 3, 4]
- 2: [1, 2, 5]

```python
MERGE_EDGES(G=(V, E)):                  # O(|V| + |E|)
    Let G_prime = (V, E_prime) with E_prime is blank.

    for u from 1 to |V|:                # Θ(|V|)
        for v in E[u]:                  # O(|E|)
            if v not in E_prime[u]:
                E_prime[u].append(v)
            if u not in E_prime[v]:
                E_prime[v].append(u)
```

---------------------------------

## 20.1-5
> The **square** of a directed graph $G=(V,E)$ is the graph $G^{2}=(V,E^{2})$ such that $(u,v) \in E^{2}$ if and only if $G$ contains a path with at most two edges between $u$ and $v$. Describe efficient algorithms for computing $G^{2}$ from $G$ for both the adjacency-list and adjacency-matrix representations of $G$. Analyse the running times of your algorithms.
-----------------------------------

In $G$, we have exactly 2-long path A - B - C, then in the $G' = G^{2}$, A and C are connected.
They call it **square** because for an adjacency-matrix $A$, if we do matrix multiplication $A \times A = A^{2}$:
- The $A_{ij}^{2}$ tells you the **number of different ways** to get from %i% to $j$ in exactly two steps.
- If the result is > 0, an edge exists in the squared graph.

In $G^{2}$, we only keep the new nodes in the adjacency list of every node. i,e,. we only keep $C$ and drop $B$ from $A$'s list.

e.g., adjacency list
- 1: [2]
- 2: [3]

then 1: [2, 3]

### Adjacency list
```python
SQUARE_GRAPH(G=(V, E)):                 # O(|V|.|E|^2)
    Let G_squared = (V, E_squared)
    
    for u in V:                         # Θ(|V|)
        for v in E[u]:                  # O(|E|)
            for w in E[v]:              # O(|E|)
                E_squared[u].append(w)
```

### Adjacency matrix
```python
SQUARE_GRAPH(G=(V, E)):                     # O(|V|^3)
    Let G_quared = (V, E_squared)

    for i in |V|:                           # Θ(|V|)
        for j in |V|:                       # Θ(|V|)
            if E[i][j] == 1:
                for w in |V|:               # O(|V|)
                    if E[j][w] == 1:
                        E_squared[i][w] = 1 
```

---------------------------

## 20.1-6
> Most graph algorithms that take an adjacency-matrix representation as input require $\Omega(V^2)$ time, but there are some exceptions. Show how to determine whether a directed graph $G$ contains a **universal sink** - a vertex with in-degree $|V| - 1$ and out-degree 0 - in $O(V)$ time, given an adjacency matrix for $G$.

---------------------------

## 20.1-7
> The **incidence matrix** of a directed graph $G=(V,E)$ with no self-loops is a $|V|\times |E|$ matrix $B=(b_{ij})$ such that
> ```math
> b_{ij} = \begin{cases}
>   -1 \text{ if edge } j \text{ leaves vertex } i, \\
>   1 \text{ if edge } j \text{ enters vertex } i, \\
>   0 \text{ otherwise}
> \end{cases}
> ```
> Describe what the entries of the matrix product $BB^T$ represent, where $B^T$ is the transpose of B.

---------------------------

## 20.1-8
> Suppose that instead of a linked list, each array entry $\text{Adj}[u]$ is a hash table containing the vertices $v$ for which $(u,v) \in E$, which collisions resolved by chaining. Under the assumption of uniform independent hashing, if all edge lookups are equally likely, what is the expected time to determine whether an edge is in the graph? What disadvantages does this scheme have? Suggest an alternate data structure for each edge list that solves these problems. Does you alternative have disadvantages compared with the hash table?