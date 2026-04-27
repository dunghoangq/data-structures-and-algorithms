"""
Merge Sort Implementation.

This module provide an implementation of Merge Sort
as described in CLRS book as an example of Divide and Conquer method.

Complexity:
    - Time:     O(n log n)
    - Space:    O(n) auxiliary (requires temp arrays)
"""

def merge(A: list[int], p: int, q: int, r: int) -> None:
    """
    Merges Left and Right arrays, used for Merge Sort.

    Assuming that the subarrays A[p:q] and A[q+1:r] were already recursively sorted.
    It merges the two sorted subarrays to form a single sorted subarray that replaces the current array A[p:r].

    It's analogous to card-playing, two piles of cards facing up on a table.
    Each pile is sorted with the smallest-value ones on top, which is to be face down on the table.
    Recursively choose the smaller of the two cards on top of the piles,
    then place it face down.

    Args:
        A (list[int]): Input array.
        p, q, r (int): Indices into the array A such that p <= q < r.
    
    Returns:
        None: Merge inplace.
    """
    # In Python, slicing is [start:stop], where stop is exclusive.
    # To include indices q and r, we must add 1 to the stop index.
    L, R = A[p : q + 1], A[q + 1 : r + 1]

    i = j = 0
    k = p

    while i < len(L) and j < len(R):
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
        k += 1
    
    # Once one of L or R reaches the end, copy the remainder
    #   of the other to the end of A[p:r]
    while i < len(L):
        A[k] = L[i]
        i += 1
        k += 1
    while j < len(R):
        A[k] = R[j]
        j += 1
        k += 1

def merge_sort(A: list[int], p: int, r: int) -> None:
    """
    Sorts the input array A in non-decreasing order using Merge Sort.

    Run recursively.
    Use the merge function defined above.

    Args:
        A (list[int]): Input array.
        p, r (int): Indices that define A's range to be sorted (inclusive).
    
    Returns:
        None: Inplace sort.
    """
    if p >= r:
        return

    q = (p + r) // 2            # midpoint of A

    merge_sort(A, p, q)         # recursively sort A[p:q]
    merge_sort(A, q + 1, r)     # recursively sort A[q + 1, r]

    # Merge A[p:q] and A[q+1:r] into A[p:r]
    merge(A, p, q, r)