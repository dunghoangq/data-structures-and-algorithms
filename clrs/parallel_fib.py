"""
Parallel Fibonacci Implementation.

CLRS mentioned Parallel Fibonacci as a basic Fork-Join Parallelism.
The traditionally sequential implementation is slow on large number.

Pseudocode:
    parallel_fib(n):
        if n <= 1
            return n
        else
            x = spawn parallel_fib(n-1) # spawned child - don't wait for subroutine to return
            y = parallel_fib(n-2)       # parent - in parallel with spawned subroutine
            sync                        # wait for spawned subroutine (all spawned children) to finish
            return x + y

Complexity:
    - Work (T_1):  O(phi^n) - Same as sequential.
    - Span (T_inf): O(n) - The depth of the recursion tree.
"""

import concurrent.futures

def _fib(n: int) -> int:
    """Sequential helper to compute Fibonacci."""
    if n <= 1:
        return n
    return _fib(n - 1) + _fib(n - 2)

def parallel_fib(n: int) -> int:
    """
    Returns fibonacci number at index n-th using fork-join parallelism.

    Args:
        n (int): Index of the number in Fib seq.

    Returns:
        int: The value.
    """
    # We use a ProcessPoolExecutor for true parallelism across CPU cores.
    # In a real application, you would pass the executor as an argument
    # to avoid creating a new pool at every recursive step.
    with concurrent.futures.ProcessPoolExecutor() as executor:
        return _parallel_fib_recursive(n, executor)

def _parallel_fib_recursive(n: int, executor: concurrent.futures.ProcessPoolExecutor) -> int:
    """Recursive helper that handles the fork-join logic."""
    # Base case for the algorithm
    if n <= 1:
        return n
    
    # Grain Size / Threshold:
    # Spawning a process in Python is expensive (O(ms)). 
    # If n is small, sequential is significantly faster.
    if n <= 20:
        return _fib(n)

    # 'spawn' parallel_fib(n-1)
    # We submit the task to the process pool
    future_x = executor.submit(_fib, n - 1)
    
    # Parent computes parallel_fib(n-2)
    # In this implementation, we call the sequential version for the parent 
    # branch to keep the pool from being flooded with recursive management.
    y = _parallel_fib_recursive(n - 2, executor)
    
    # 'sync' - wait for the future and return the sum
    x = future_x.result()
    return x + y