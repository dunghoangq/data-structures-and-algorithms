# Greedy Algorithms

- Simpler than DP. Some problems don't need DP to solve.

## 1. Activity-Selection Problem

Arrange a conference room, $n$ proposed activities $S = \{ a_1, a_2,...,a_n \}$. The room can only serve one activity at a time. Activity $a_i$ has a start time $s_i$, and a finish time $f_i$ ($0 \leq s_i \leq f_i \leq \infin$). Duration for activity $a_i$ is half open $[s_i, f_i)$. $a_i$ and $a_j$ are compatible if $s_j \geq f_i$ or $s_i \geq f_j$. Assume finish times are sorted ($f_1 \leq f_2 \leq ... \leq f_n$). -> Find a max-size subset of mutually compatible activities.

|i|1|2|3|4|5|6|7|8|9|10|11|
|-|-|-|-|-|-|-|-|-|-|-|-|
|$s_i$|1|3|0|5|3|5|6|7|8|2|12
|$f_i$|4|5|6|7|9|9|10|11|12|14|16|

The formula in DP approach:

```math
c[i,j] = \begin{cases}
0 & \text{if } S_{i,j} = \emptyset  \\
\max{\{ c[i,k] + c[k,j] + 1 \}} : a_k \in S_{i,j} & \text{if } S_{i,j} \neq \emptyset
\end{cases}
```

> *Can we choose an activity to add to an optimal solution without having to first solve all the subproblems???*

### 1.1 Recursive Greedy

- top-down
- input arrays $s$ and $f$
- output mutually compatible activities set for subproblem $S_k$

```python
RECURSIVE_ACTIVITY_SELECTOR(s, f, k, n)
    m = k + 1

    while m <= n and s[m] < f[k]:
        m += 1
    
    if m <= n:
        return {a_m} ∪ RECURSIVE_ACTIVITY_SELECTOR(s, f, m, n)
    else:
        return ∅
```

### 1.2 Iterative Greedy

```python
GREEDY_ACT_SELECTOR(s, f, n)
    A = {a_1}
    k = 1

    for m = 2 to n:
        if s[m] >= f[k]:
            A = A ∪ {a_m}
            k = m
    
    return A
```