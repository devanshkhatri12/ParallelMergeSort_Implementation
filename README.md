# 🚀 Multithreaded Merge Sort — Faster Sorting with Parallelism

Sorting is fundamental to computer science, and classic algorithms like Merge Sort already deliver an efficient O(n log n) time complexity. But can we push this further using parallelism?

This project explores that idea by implementing:

    ✅ A Single-Threaded Merge Sort.
    ✅ A Parallel Merge Sort using std::thread
    ✅ Benchmarks on arrays up to 10 million elements

The goal is to observe how multithreading affects execution time, where it helps, and where it causes overhead.


# 🧠 Why Multithread Merge Sort?

Merge Sort follows a divide-and-conquer strategy:

1. Split the array into two halves
2. Recursively sort each half
3. Merge the two sorted halves

This splitting phase makes Merge Sort naturally parallelizable because:

- Sub-arrays are independent.
- No shared memory → no locks needed.
- Workload can be distributed across CPU cores.

However, blindly creating threads at every recursion level can:

- Exhaust OS thread limits.
- Increase context-switch overhead.
- Slow down sorting for small arrays.

To handle this, the project uses a depth threshold where recursion below a certain size falls back to the normal merge sort.

# ⚙️ Features

    ✅ Fully implemented Single-Threaded Merge Sort
    ✅ Fully implemented Parallel Merge Sort using std::thread
    ✅ Dynamic threading limit to avoid thread explosion
    ✅ Benchmarking support with std::chrono
    ✅ Support for very large arrays (10M+)
    ✅ Clean object-oriented design
    ✅ Works on MSYS2 / MinGW-w64 / Linux / macOS.

# 🏗️ Project Structure

```
/project
    │── mergeSort.hpp
    │── mergeSort.cpp
    │── parallelMergeSort.hpp
    │── parallelMergeSort.cpp
    │── main.cpp
    │── README.md
```

# 🧵 How Parallel Merge Sort Works

✅ Thread Creation Strategy

- For large array segments → create a new thread for one half
- For smaller segments → fallback to normal merge sort (avoids overhead)
- Uses CPU cores efficiently without exploding thread count

✅ No Mutex Needed

Each recursive call processes its own subarray, so there's no shared data race.

✅ Parallel Merge

After two child threads finish, both halves are sorted and merged normally.


## 📊 Updated Benchmark Results (Your Machine Recommended)

You can replace the below table with your own system's output.

### ✅ Example Benchmark (Based on C++ Implementation)

| Input Size   | Single-Threaded (t1) | Multi-Threaded (t2) | Faster Approach | Speedup |
|--------------|-----------------------|----------------------|-----------------|---------|
| 1,000        | 0.0011 s              | 0.0013 s             | Single Thread   | -13%    |
| 10,000       | 0.0136 s              | 0.0055 s             | Multi Thread    | +147%   |
| 100,000      | 0.1599 s              | 0.0378 s             | Multi Thread    | +222%   |
| 1,000,000    | 1.6211 s              | 0.3103 s             | Multi Thread    | +422%   |
| 10,000,000   | 18.2698 s             | 2.8734 s             | Multi Thread    | +535%   |

✅ **Multithreading wins massively for large input sizes**  
❌ **Overhead dominates for tiny inputs (1000 elements)**  


# ▶️ How to Compile

### ✅ Using g++ (MSYS2, Linux, Mac)




# 📈 What You Can Modify

    ✅ Change thread threshold
    ✅ Add thread pool implementation
    ✅ Try using std::async instead of threads
    ✅ Compare with OpenMP parallel merge sort

# 📝 Conclusion

This project demonstrates that:

    ✅ Merge Sort parallelizes extremely well
    ✅ Multithreading drastically reduces sorting time for large arrays
    ❌ Small arrays suffer due to thread-creation overhead
    ✅ CPU core count heavily influences performance
    ✅ Adaptive threading (threshold-based) gives best results

It is a practical demonstration of real-world parallelism, where algorithm design must balance CPU power, overheads, and workload distribution.


