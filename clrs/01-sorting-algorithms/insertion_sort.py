"""
Insertion Sort Implementation.

This module provides an implementation of the Insertion Sort algorithm as described
in "Introduction to Algorithms" (CLRS). Insertion sort works efficiently for
small datasets or nearly sorted arrays.

Complexity:
    - Time: O(n^2) worst/average case, O(n) best case.
    - Space: O(1) auxiliary (In-place).
"""

def insertion_sort(A: list[int], n: int):
    """
    Sorts a list of integers in non-decreasing order using insertion sort.

    It's analogous to sorting a deck of cards in your hands: you pick one card
    and insert it into its correct position relative to the cards already held.

    Args:
        A (list[int]): The sequence of n numbers to be sorted.
        n (int): The number of elements in the list to sort.

    Returns:
        None: The list is sorted in-place.

    Example:
        >>> nums = [5, 2, 4, 6, 1, 3]
        >>> insertion_sort(nums, len(nums))
        >>> nums
        [1, 2, 3, 4, 5, 6]
    """
    for j in range(1, n):
        key = A[j]
        # Insert A[j] into the sorted sequence A[0...j-1]
        i = j - 1
        while i >= 0 and A[i] > key:
            A[i + 1] = A[i]
            i = i - 1
        A[i + 1] = key