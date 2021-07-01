# Striver SDE Sheet [30 Days Challenge]

Link to the SDE Sheet: [view](https://docs.google.com/document/d/1SM92efk8oDl8nyVw8NHPnbGexTS9W-1gmTEYfEurLWQ/edit)

Collection of the solutions in C++

## Important Questions

S.No. | Question Name | Logic Used | Topic | Date |
------|---------------|------------|-------|------|
1 | [Missing and Repeating](https://github.com/vineethm1627/SDE_Sheet_Striver/blob/main/Day-01_Arrays/missing_repeating.cpp) | repeated xor | Bit Manipulation | 02 June 21 |
2 | [Duplicate Number](https://github.com/vineethm1627/SDE_Sheet_Striver/blob/main/Day-01_Arrays/duplicate_number.cpp) | Linked List Cycle Detection | Arrays and Linked List | 02 June 21 |
3 | [Merge Sorted Space in O(1) Space](https://github.com/vineethm1627/SDE_Sheet_Striver/blob/main/Day-01_Arrays/merge_sorted_arrays.cpp) | Gap Method: Shear Sort | Sorting | 02 June 21 |
4 | [Set Matrix Zeros](https://github.com/vineethm1627/SDE_Sheet_Striver/blob/main/Day-02_Arrays/set_matrix_zeros.cpp) | in place, bottom to top, right to left | Matrix | 03 June 21 |
5 | [Reverse Pairs Count](https://github.com/vineethm1627/SDE_Sheet_Striver/blob/main/Day-03_Arrays_Maths/reverse_pairs.cpp) | count inversions using merge sort | Arrays | 04 June 21 |
6 | [Reverse in Groups of K](https://github.com/vineethm1627/SDE_Sheet_Striver/blob/main/Day-06_LinkedList/reverse_groups_k.cpp) | addFirst, original and temp pointers | Linked List | 06 June 21 |
7 | [Clone list with random pointers](https://github.com/vineethm1627/SDE_Sheet_Striver/blob/main/Day-07_Two_Pointers/clone_list.cpp) | adjacent copy nodes | Linked List | 07 June 21 |
8 | [Trapping Rainwater](https://github.com/vineethm1627/SDE_Sheet_Striver/blob/main/Day-07_Two_Pointers/trapping_rainwater.cpp) | 2 pointers, min(max_left, max_right) - arr[i] | Two Pointers | 07 June 21 | 
9 | [Job Sequencing](https://github.com/vineethm1627/SDE_Sheet_Striver/blob/main/Day-08_Greedy/job_sequencing.cpp) | n-slots, job index in sorted array | Greedy | 08 June 21 |
10 | [Minimum Railways Platforms](https://github.com/vineethm1627/SDE_Sheet_Striver/blob/main/Day-08_Greedy/min_platforms_railway.cpp) | sorted: arrival vs dep times | Greedy | 08 June 21 |
11 | [Combination Sum without repetition](https://github.com/vineethm1627/SDE_Sheet_Striver/blob/main/Day-09_Recursion/combination_sum_without_rep.cpp) | recursion with 2 options; avoid duplicates | Bactracking | 12 June 21 |
12 | [Permutations of an Array](https://github.com/vineethm1627/SDE_Sheet_Striver/blob/main/Day-10_Backtracking/print_permutations.cpp) | fixing first position, all swaps | Backtracking | 13 June 21 |
13 | [Rat in a Maze](https://github.com/vineethm1627/SDE_Sheet_Striver/blob/main/Day-10_Backtracking/rat_maze.cpp) | backtracking, dfs calls in 4 directions | Backtracking | 14 June 21 |
14 | [M Coloring Graph](https://github.com/vineethm1627/SDE_Sheet_Striver/blob/main/Day-10_Backtracking/M_coloring.cpp) | backtracking, trying every color | Bactracking | 17 June 21 |
15 | [Median of 2 Sorted Arrays](https://github.com/vineethm1627/SDE_Sheet_Striver/blob/main/Day-11_Binary_Search/median_2_sortedArrays.cpp) | Contribution size partitioning of smaller array | Binary Search | 17 June 21 |
16 | [Allocate min pages](https://github.com/vineethm1627/SDE_Sheet_Striver/blob/main/Day-11_Binary_Search/allocate_min_pages.cpp) | monotonic search space of min possible max upper bound | Binary Search | 25 June 21 |
17 | [Median in Row sorted matrix](https://github.com/vineethm1627/SDE_Sheet_Striver/blob/main/Day-11_Binary_Search/median_row_sorted.cpp) | count of left part of sorted array; upper_bound | Binary Search | 26 June 21 |
18 | [Count Total Set Bits](https://github.com/vineethm1627/SDE_Sheet_Striver/blob/main/Day-12_Bit_Manipulation/count_total_set_bits.cpp) | f(n)=x*2^(x-1)+(n-2^x+1)+f(n-2^x) | Recursion | 26 June 21 |
19 | [Find nearest power of 2 <= n](https://github.com/vineethm1627/SDE_Sheet_Striver/blob/main/Day-12_Bit_Manipulation/find_MSB.cpp) | one by one set all the bits | Bit Manipulation | 26 June 21 |
20 | [Square of a number](https://github.com/vineethm1627/SDE_Sheet_Striver/blob/main/Day-12_Bit_Manipulation/square_bit.cpp) | Left shift + recursion | Bit Manipulation | 27 June 21 |
21 | [LRU Cache Design](https://github.com/vineethm1627/SDE_Sheet_Striver/blob/main/Day-14_Stacks/LRU_cache.cpp) | Hashing + DLL {latest used on left near head} | Linked List | 30 June 21 |
22 | [Sliding Window Maximum](https://github.com/vineethm1627/SDE_Sheet_Striver/blob/main/Day-14_Stacks/sliding_window_max.cpp) | Deque + store max at dq front | Deque + Sliding Window | 01 July 21 |
23 | [Largest rectangle in Histogram](https://github.com/vineethm1627/SDE_Sheet_Striver/blob/main/Day-14_Stacks/largest_rectangle_histogram_2.cpp) | 3 vars: i-->nse, top = height, below top = pse | [view](largest_rectangle_histogram_2.cpp)
24 | [Longest Palindromic Substring](https://github.com/vineethm1627/SDE_Sheet_Striver/blob/main/Day-15_Strings/longest_palindromic_substring.cpp) | Two pointer consecutive + 1 gap apart expansion | Strings | 01 July 21 |