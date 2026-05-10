# Dynamic Programming

**Optimisation** problems. Has a **table** to save answers. Unlike *Divide and Conquer*, it solves **joint/overlap subproblems**.

Steps:
1. Characterise the structure of an optimal solution.
2. Recursively define the value of an optimal solution.
3. Compute the value of an optimal solution, typically in a bottom-up fashion.
4. Construct an optimal solution from computed information.

------------------------------

## 1. Rod Cutting

A steel rod of length $n$ []-[]-[]-...-[]. Cut them into shorter rods. Each cut is free. -> Best way to cut up the rods, maximising revenue $r_n$???

Price for cutting i inches.
| $i$ | 1 | 2 | ... |
|-----|---|---|-----|
| price ($p_i$) | $p_1$ | $p_2$ | ... |

If the price $p_n$ is large enough, no need to cut the rod.

From the left end, for each size $i=1,2,...,n-1$, we have two options: cut or not cut. -> There are $2^{n-1}$ ways of cutting.

If the rod length $n$ is cut into $n = i_1 + i_2 + ... i_k$, the revenue is $r_n = p_{i_1} + p_{i_2} + ... p_{i_k}$.

Dynamic Programming means we have already computed revenue $r_i$ for a $i$-length rod, and it is stored in a table. So for $r_{i+1}$, we only look up the table to check the previous revenues to get the max one, assign it to the current $r_{i+1}$.

```math
r_n = \text{max}\{ p_n, p_1 + r_{n-1}, p_2 + r_{n-2},..., p_{n-1} + r_1 \}
```
or
```math
r_n = \text{max}\{ p_i + r_{n-i}: 1 \leq i \leq n \}
```

**Optimal Substructure**: optimal solution for independent subproblem.

### 1.1 Recursive Top-down Implementation

A rod length $n$ with price array $p[1:n]$.

```python
CUT_ROD(p, n):
    if n == 0:
        return 0
    
    q = -inf

    for i = 1 to n:
        q = max{q, p[i] + CUT_ROD(p, n-1)}
    return q
```
This approach is inefficient for large $n$. Try the *inductive approach* instead.

**Asymptotic Analysis**

Let $T(n)$:= # calls made to **CUT_ROD(p, n)**, which is also # nodes in a subtree whose root is labeled n in the recursion tree.
```math
T(0) = 0, T(n) = 1 + \sum_{j=0}^{n-1}T(j) = 2^n
```

The tree looks like this ($n=4$)
```
CUT_ROD(4)
- CUT_ROD(3)
    - CUT_ROD(2)
        - CUT_ROD(1)
        - CUT_ROD(0)
    - CUT_ROD(1)
        - CUT_ROD(0)
    - CUT_ROD(0)
- CUT_ROD(2)
    - CUT_ROD(1)
        - CUT_ROD(0)
    - CUT_ROD(0)
- CUT_ROD(1)
    - CUT_ROD(0)
- CUT_ROD(0)
```
That's why we shouldn't use this approach.

### 1.2 Applying DP to Solve Rod Cutting

How to solve each subproblem only once?

#### 1.2.1 Top-down with Memoisation

```python
MEMOISED_CUT_ROD(p, n):     # Θ(n^2)
    let r[0:n] a new array
    for i = 0 to n:
        r[i] = -inf
    return MEMOISED_CUT_ROD_AUX(p, n, r)

MEMOISED_CUT_ROD_AUX(p, n, r):
    if r[n] >= 0:
        return r[n]
    if n == 0:
        q = 0
    else:
        q = -inf
        for i = 1 to n:
            q = max{q, p[i] + MEMOISED_CUT_ROD_AUX(p, n-i, r)}
    r[n] = q
    return q
```

#### 1.2.2 Bottom-up

```python
BOTTOM_UP_CUT_ROD(p, n):    # Θ(n^2)
    let r[0:n] new array
    r[0] = 0
    for j = 1 to n:
        q = -inf
        for i = 1 to j:
            q = max{q, p[i] + r[j-i]}
        r[j] = q
    return r[n]
```

#### 1.2.3 Reconstructing a Solution

Both approaches don't return the solution but the array revenues. We can also think about printing an optimal solution.

We can do it with an extra array $s[1:n]$.
```python
EXTENDED_BOTTOM_UP_CUT_ROD(p, n):
    let r[0:n] and s[1:n] new arrays
    r[0] = 0

    for j = 1 to n:
        q = -inf
        for i = 1 to j:
            if q < p[i] + r[j-i]:
                q = p[i] + r[j-i]
                s[j] = i
        r[j] = q
    return r, s

PRINT_CUT_ROD_SOLUTION(p, n):
    r, s = EXTENDED_BOTTOM_UP_CUT_ROD(p, n)
    
    while n > 0:
        print s[n]
        n = n - s[n]
```


------------------------------

## 2. Matrix-Chain Multiplication

**Problem**

Multiply $n$ rectangular matrices $A_1...A_n$, for $A_i \in \mathbb{R}^{p_{i-1}\times p_i}$.

Costly based on Scalar Multiplication. If $A\in\mathbb{R}^{p\times q}, B\in\mathbb{R}^{q\times r}$, then the multiplication cost is $p\times q \times r$.

For $n=4$, there are 5 ways to parenthesise the product

```math
(A_1(A2(A_3 A_4))), \\
(A_1((A_2 A_3)A_4)), \\
((A_1 A_2)(A_3 A_4)), \\
((A_1(A_2 A_3))A_4), \\
(((A_1 A_2)A_3)A_4)
```

**Structure**

$(A_1...A_k A_{k+1}...A_n)$ is the multiplications of all subproducts. A pair of parentheses splits a product -> 2 subproducts between $k^{th}$ and $(k+1)^{th}$ matrices. -> Compute $A_{1:k}$ and $A_{k+1:n}$.

**Invariant**

Given an optimal parenthesisation $A_iA_{i+1}...A_j$, a split between $A_k$ and $A_{k+1}$ divides it into prefix subchain $A_i...A_k$ and suffix subchain $A_{k+1}...A_j$ are also optimal. Because if there's a less costly way to compute $A_i...A_k$, we replace it to have a less costly $A_i...A_j$. So the original one is not optimal anymore.

**Data Structure**

Min cost $A_i...A_j$ for $1 \leq i \leq j \leq n$, demension array $[p_0, p_1,...p_n]$.

Store multiplication costs in a $2\times 2$ matrix $m[1:n, 1:n]$.
- $i=j$ -> $m[i,j]=0$
- $i < j$ -> $\min\{m[i,j] = m[i,k] + m[k+1,j] + p_{i-1}p_kp_j: i \leq k < j\}$

**Using DP**

To rebuild the parenthesised matrix multiplication, we also need an auxiliary table $s[1:n-1,2:n]$

```python
MATRIX_CHAIN_ORDER(p, n):
    let m[1:n, 1:n] and s[1:n-1, 2:n] new tables

    for i = 1 to n:
        m[i,i] = 0
    for l = 2 to n: # chain length
        for i = 1 to n - l + 1: # start matrix A_i
            j = i + l - 1   # end matrix A_j
            m[i, j] = inf
            for k = 1 to j - 1:
                q = m[i,k] + m[k+1, j] + p[i-1]*p[k]*p[j]
                if q < m[i,j]:
                    m[i, j] = q
                    s[i, j] = k
    return m, s
```

To construct the optimal solution

```python
PRINT_OPTIMAL_PARENS(s, i, j):
    if i == j:
        print "A_i"
    else:
        print "("
            PRINT_OPTIMAL_PARENS(s, i, s[i,j])
            PRINT_OPTIMAL_PARENS(s, s[i,j]+1, j)
        print ")"
```

------------------------------

## 3. DP's Elements


------------------------------

## 4. Longest Common Subsequence


------------------------------

## 5. Optimal Binary Search Trees