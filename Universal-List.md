# Universal list — data structures & algorithms

Reference tables for structures and algorithms used across the Mercury-CPP notes. The **Algorithms** half merges **core ideas** (searching, sorting, baseline graphs) with an **extended set**: classic DP problems, advanced graph matchings/cuts/connectivity, string construction algorithms, extra number theory / geometry / selection / heuristics, and expression parsing—organized so simpler topics precede the specialized ones they build on.

## Data structures

### Arrays

| Term | Definition |
|------|------------|
| **Array** | Contiguous indexed sequence of elements in memory, fixed logical layout, accessed by subscript. |
| **Dynamic Array** | Array whose size grows or shrinks (typically doubling capacity) while keeping amortized O(1) append at the end. |
| **Static Array** | Array whose size is fixed at allocation time and cannot change during program execution. |
| **Jagged Array** | Array of arrays where inner rows may have different lengths (ragged rows). |
| **Sparse Array** | Storage for mostly-default values using a compact map or structure so only non-default entries cost space. |
| **Circular Array** | Fixed-size buffer where indices wrap modulo length, used as ring storage for queues or streams. |
| **Multi-dimensional Array** | Array indexed by two or more coordinates (matrix, tensor slice) laid out in row-major or column-major order. |
| **Prefix Sum Array** | Auxiliary array where each position stores the sum of the original array from the start up to that index. |
| **Difference Array** | Array paired with the original so range adds are O(1) on the diff structure and the true values are recovered by prefix sum. |

### Linked lists

| Term | Definition |
|------|------------|
| **Singly Linked List** | Linear sequence of nodes each holding data and one pointer to the next node. |
| **Doubly Linked List** | Linked list whose nodes store pointers to both successor and predecessor. |
| **Circular Linked List** | Linked list whose last node points back to the first, forming a cycle. |
| **Circular Doubly Linked List** | Doubly linked list whose head’s previous is tail and tail’s next is head. |
| **Skip List** | Probabilistic layered linked structure that approximates balanced search in O(log n) expected time. |
| **Unrolled Linked List** | Linked list where each node stores a small block of elements to improve cache locality. |
| **XOR Linked List** | Doubly linked list encoded with a single pointer per node using XOR of neighbor addresses. |
| **Self Organizing List** | Linked list that reorders nodes on access (e.g. move-to-front) to speed up frequent keys. |

### Stacks

| Term | Definition |
|------|------------|
| **Stack** | LIFO container supporting push and pop at one end only. |
| **Min Stack** | Stack augmented to return the minimum among current elements in O(1) per operation. |
| **Max Stack** | Stack augmented to return the maximum among current elements in O(1) per operation. |
| **Monotonic Stack** | Stack kept in strictly increasing or decreasing order to answer next-greater or span problems in one pass. |
| **Persistent Stack** | Stack whose versions share structure so older versions remain queryable after updates. |

### Queues

| Term | Definition |
|------|------------|
| **Queue** | FIFO container supporting enqueue at the rear and dequeue at the front. |
| **Circular Queue** | Queue implemented on a fixed array with front and rear indices wrapping modulo capacity. |
| **Deque** | Double-ended queue allowing insert and delete at both front and rear in O(1). |
| **Priority Queue** | Abstract queue that always removes the element with highest (or lowest) priority first, usually via a heap. |
| **Monotonic Queue** | Deque maintaining order of values or indices to solve sliding-window min/max in linear time. |
| **Double Ended Priority Queue** | Structure supporting efficient extract-min and extract-max (or similar dual-end priorities). |

### Hashing

| Term | Definition |
|------|------------|
| **Hash Table** | Key-to-slot mapping using a hash function with collision resolution for average O(1) lookup. |
| **Hash Map** | Associative container mapping keys to values backed by a hash table. |
| **Hash Set** | Set of keys backed by a hash table with no separate value field. |
| **Ordered Hash Map** | Hash map that additionally preserves insertion order or sorted iteration depending on implementation. |
| **Robin Hood Hashing** | Open-addressing scheme that steals slots from “richer” probes to bound longest probe length. |
| **Cuckoo Hashing** | Two (or more) tables and hash functions; each key lives in one of few slots, displaced keys are rehashed in a chain. |

### Trees

| Term | Definition |
|------|------------|
| **Binary Tree** | Tree where each node has at most two labeled children (left and right). |
| **Binary Search Tree** | Binary tree obeying in-order sorted key invariant: left subtree keys < node < right subtree keys. |
| **AVL Tree** | BST where heights of left and right subtrees differ by at most one, rebalanced with rotations. |
| **Red Black Tree** | BST colored red/black with height rules ensuring O(log n) worst-case depth and rotations on update. |
| **Splay Tree** | Self-adjusting BST that moves accessed nodes to the root via splay operations for amortized efficiency. |
| **Treap** | BST keyed by value whose heap priority on nodes yields expected balanced shape like a random BST. |
| **Cartesian Tree** | Heap-ordered tree built from a sequence whose inorder traversal is that sequence. |
| **AA Tree** | Variant of red-black tree using level instead of color to enforce balance with simpler cases. |
| **Scapegoat Tree** | BST that rebuilds entire subtrees when balance factor exceeds a threshold (scapegoat subtree). |
| **Weight Balanced Tree** | Balanced tree maintaining subtree sizes or weights to keep height logarithmic in total weight. |
| **Threaded Binary Tree** | Binary tree with extra threads replacing null child pointers to successors/predecessors for traversal without stack. |
| **Complete Binary Tree** | Every level full except possibly the last, which is filled left to right. |
| **Perfect Binary Tree** | All internal nodes have two children and all leaves are at the same depth. |
| **Full Binary Tree** | Every node has either zero or two children (no node with exactly one child). |
| **Balanced Binary Tree** | Binary tree whose height is O(log n), often maintained by AVL, red-black, or similar rules. |
| **Expression Tree** | Binary tree whose leaves are operands and internal nodes are operators representing an expression. |
| **Tournament Tree** | Complete binary tree used to run pairwise comparisons (e.g. finding min in rounds). |
| **Ternary Tree** | Tree where each node has up to three children. |
| **N-ary Tree** | Tree where each node has an arbitrary bounded or unbounded number of children. |
| **K-ary Tree** | Tree where each node has at most K children for a fixed constant K. |

### Heap structures

| Term | Definition |
|------|------------|
| **Binary Heap** | Complete binary tree storing keys in heap order, usually in an array index formula. |
| **Min Heap** | Heap where each parent’s key is less than or equal to its children’s keys. |
| **Max Heap** | Heap where each parent’s key is greater than or equal to its children’s keys. |
| **Binomial Heap** | Collection of binomial trees supporting mergeable heaps with efficient decrease-key in some variants. |
| **Fibonacci Heap** | Lazy heap with cascading cuts giving excellent amortized bounds for graph algorithms with decrease-key. |
| **Pairing Heap** | Heap represented as multiway trees merged in pairs, simple and fast in practice. |
| **Skew Heap** | Self-adjusting binary heap mergeable in amortized logarithmic time without explicit balance metadata. |
| **Leftist Heap** | Mergeable heap using null-path length to keep left subtrees deeper for efficient merge. |
| **Soft Heap** | Approximate priority queue that allows controlled corruption of keys to beat comparison lower bounds. |

### Trie structures

| Term | Definition |
|------|------------|
| **Trie** | Rooted tree where edges are labeled with characters and paths from the root spell prefixes of stored strings. |
| **Compressed Trie** | Trie where chains of degree-one nodes are merged into single edges labeled with multi-character strings. |
| **Radix Tree** | Compressed trie over strings or bitstrings used for longest-prefix lookup and compact storage. |
| **Patricia Trie** | Practical radix trie variant using bit or character skips (often “Patricia” = practical algorithm to retrieve). |
| **Suffix Trie** | Trie containing every suffix of a string (often replaced by suffix tree for linear space). |
| **Bitwise Trie** | Trie whose edges are labeled 0 or 1, used for integers, XOR maximization, or IP prefixes. |
| **Ternary Search Trie** | Trie node with three branches (low, equal, high) per character for space–time tradeoffs on string keys. |

### Segment structures

| Term | Definition |
|------|------------|
| **Segment Tree** | Binary tree over an array range splitting intervals in half for range queries and point updates in O(log n). |
| **Lazy Segment Tree** | Segment tree that postpones range updates by storing pending tags on nodes until they are needed. |
| **Persistent Segment Tree** | Segment tree whose versions share nodes so past range states remain queryable. |
| **Dynamic Segment Tree** | Sparse segment tree allocating children on demand for huge coordinate ranges. |
| **2D Segment Tree** | Nested segment trees for rectangle sum or update on a matrix. |
| **Fenwick Tree** | Implicit tree on index bits supporting prefix sums and point updates in O(log n) with minimal memory. |
| **Binary Indexed Tree** | Same structure as a Fenwick tree: array-based BIT using least significant bit indexing. |
| **Sparse Table** | Static O(1) range minimum (or idempotent) queries after O(n log n) preprocessing on overlapping blocks. |
| **Wavelet Tree** | Nested bitvectors partitioning alphabet recursively for rank/select and range quantile on sequences. |
| **Merge Sort Tree** | Segment tree node stores sorted multiset of its range’s values for order-statistics style queries. |
| **Interval Tree** | Balanced BST keyed by interval low endpoint storing intervals for stabbing or overlap queries. |
| **Range Tree** | Multi-level tree answering orthogonal range queries (e.g. 2D dominance) in polylog time. |

### Set structures

| Term | Definition |
|------|------------|
| **Disjoint Set Union** | Union–find structure maintaining disjoint sets with union and find operations. |
| **Union Find** | Same as DSU: parent-pointer forest with union by rank or size and path compression. |
| **Persistent DSU** | DSU whose history is partially retained (often with extra complexity or rollback stack). |
| **Ordered Set** | Set container iterating keys in sorted order (e.g. balanced BST in standard libraries). |
| **Multiset** | Bag allowing duplicate keys with multiplicity, usually tree- or heap-backed. |
| **Policy Based Data Structure** | GNU PBDS extension offering ordered statistics tree and tree-based multiset in C++. |

### Graph structures

| Term | Definition |
|------|------------|
| **Graph** | Pair (V, E) of vertices and edges relating pairs of vertices. |
| **Directed Graph** | Graph whose edges are ordered pairs (arrows from tail to head). |
| **Undirected Graph** | Graph whose edges are unordered pairs (two-way adjacency). |
| **Weighted Graph** | Graph where each edge carries a numeric weight (distance, cost, capacity). |
| **Multigraph** | Graph allowing multiple edges between the same pair of vertices (and sometimes self-loops). |
| **DAG** | Directed acyclic graph: no directed cycle exists. |
| **Adjacency Matrix** | V×V matrix where entry (i,j) stores edge presence or weight between i and j. |
| **Adjacency List** | Array of lists: each vertex stores its neighbors (and optionally edge weights). |
| **Edge List** | Graph stored as a list of (u, v) or (u, v, w) tuples without per-vertex index unless built. |

### String structures

| Term | Definition |
|------|------------|
| **Suffix Array** | Sorted array of all suffix start indices of a string, often with LCP array for string algorithms. |
| **Suffix Tree** | Compressed trie of all suffixes of a string, built in linear time for a fixed alphabet. |
| **Suffix Automaton** | Minimal DFA recognizing all substrings of a string, linear size, used for counting and matching. |
| **Palindromic Tree** | Data structure (Eertree) tracking distinct palindromes and their fail links in a string online. |
| **Rope** | Balanced tree of string chunks supporting split, concat, and substring in logarithmic time. |
| **Gap Buffer** | Two stacks with a gap cursor in a text buffer for efficient local insert/delete in editors. |
| **Piece Table** | Text model mapping logical sequence to immutable pieces and a piece descriptor table for edits. |

### Spatial / geometric

| Term | Definition |
|------|------------|
| **KD Tree** | k-dimensional space partition tree alternating axis splits for nearest-neighbor search. |
| **Quad Tree** | Tree recursively subdividing 2D space into four quadrants for points or regions. |
| **Octree** | Three-dimensional analog of quadtree with eight octants per subdivision. |
| **R Tree** | Balanced tree grouping nearby rectangles for spatial indexing and window queries on disk. |
| **BSP Tree** | Binary space partition by hyperplanes dividing space for rendering or collision. |
| **Bounding Volume Hierarchy** | Tree of nested simple volumes (boxes, spheres) approximating object geometry for fast intersection tests. |

### Database / storage

| Term | Definition |
|------|------------|
| **B Tree** | Self-balancing search tree with large fanout and all leaves at equal depth for block-oriented storage. |
| **B+ Tree** | B-tree variant where keys live in internal nodes for routing and all records sit in linked leaves. |
| **LSM Tree** | Log-structured merge tree batching writes into sorted runs flushed and compacted in levels (e.g. RocksDB). |

### Advanced / specialized

| Term | Definition |
|------|------------|
| **Persistent Array** | Array whose older versions remain accessible after updates via path copying or fat nodes. |
| **Persistent Trie** | Trie sharing nodes across versions for immutable string-set history. |
| **Persistent Queue** | Queue supporting enqueue/dequeue while retaining access to prior front/back states. |
| **Persistent Heap** | Heap with versioned roots for historical extract-min queries. |
| **Link Cut Tree** | Dynamic forest supporting path aggregates and link/cut in amortized logarithmic time. |
| **Euler Tour Tree** | Forest represented by Euler tours in splay or treap sequences for subtree/path updates. |
| **Heavy Light Decomposition** | Partition tree edges into O(log n) chains so path queries reduce to segment trees on chains. |
| **Centroid Decomposition** | Recursive removal of tree centroids to answer path or distance queries with smaller depth. |
| **Van Emde Boas Tree** | Structure for bounded integer universe supporting min/max/successor in O(log log U) time. |
| **Bloom Filter** | Bit array with multiple hash functions approximating set membership with possible false positives. |
| **Counting Bloom Filter** | Bloom filter using counters instead of bits to allow approximate deletions. |
| **Cuckoo Filter** | Space-efficient set membership structure based on partial-key cuckoo hashing with deletions. |
| **HyperLogLog** | Sketch estimating cardinality of a multiset using leading zeros in hashed buckets. |
| **Order Statistic Tree** | Augmented balanced BST supporting find-by-rank and rank-of-key in O(log n). |
| **Finger Tree** | Functional deque with efficient concatenation and splitting using measured annotations. |
| **Segment Tree Beats** | Segment tree with chmax/chmin style range updates maintained by stored max/min structure. |
| **Li Chao Tree** | Dynamic segment tree over lines or segments for lower envelope queries at integer x. |
| **Dancing Links** | Doubly linked grid of 1/0 cells used by Algorithm X for exact cover (e.g. Sudoku). |
| **Union Split Find** | Variant maintaining partitions with split operations on sequences (less common than DSU). |
| **Dynamic Connectivity Structure** | Data structure inserting/deleting edges while answering whether two vertices are connected. |

---

## Algorithms

### Searching

| Term | Definition |
|------|------------|
| **Linear Search** | Scan elements sequentially until the target is found or the array ends. |
| **Binary Search** | Halve the search interval by comparing with the middle element on sorted data. |
| **Ternary Search** | Divide domain into thirds to find unimodal function extremum in continuous or discrete settings. |
| **Jump Search** | Jump ahead by √n steps on sorted array then linear scan back for the target block. |
| **Interpolation Search** | Estimate probe position by linear interpolation of key between endpoints on sorted numeric arrays. |
| **Exponential Search** | Double index from start until overshoot then binary search within the last range on unbounded or large sorted data. |
| **Fibonacci Search** | Divide interval using Fibonacci numbers instead of halves to reduce subtraction cost on sorted arrays. |

### Sorting

| Term | Definition |
|------|------------|
| **Bubble Sort** | Repeatedly swap adjacent out-of-order pairs until no swaps occur. |
| **Selection Sort** | Repeatedly select the smallest remaining element and swap it to the front of the unsorted suffix. |
| **Insertion Sort** | Build sorted prefix by inserting each next element into its correct position by shifting. |
| **Merge Sort** | Divide array in half, sort halves recursively, merge two sorted halves in linear time. |
| **Quick Sort** | Partition around a pivot and recurse on subarrays (average O(n log n), worst O(n²) without care). |
| **Heap Sort** | Build a max-heap then repeatedly extract max to the end of the array. |
| **Shell Sort** | Insertion sort on gapped subsequences with decreasing gap sequence. |
| **Counting Sort** | Stable sort counting frequencies of keys in a bounded integer range then prefix-fill output. |
| **Radix Sort** | Sort keys digit by digit (least or most significant) using a stable O(n) digit sort each pass. |
| **Bucket Sort** | Distribute keys into buckets, sort buckets individually, concatenate (good when uniform over range). |
| **Tim Sort** | Hybrid stable sort merging runs of naturally ordered data (Python, Java Arrays.sort for objects). |
| **IntroSort** | Quick sort switching to heap sort when recursion depth exceeds limit to guarantee O(n log n) worst case. |
| **Cycle Sort** | Places each element in its final position by following permutation cycles (minimal writes). |
| **Cocktail Sort** | Bidirectional bubble pass alternating left-to-right and right-to-left. |
| **Comb Sort** | Bubble sort with shrinking gap (like shell gaps) to eliminate turtles earlier. |
| **Pigeonhole Sort** | Map each key to a pigeonhole index then read holes in order when key range is small. |
| **Tree Sort** | Insert all elements into BST then inorder traversal yields sorted order. |
| **Bitonic Sort** | Compare-exchange network producing a bitonic sequence then merging halves (parallel-friendly). |
| **External Sort** | Sort data larger than memory using multiway merge of sorted runs on disk. |
| **Median of Medians** | Pivot choice groups of five guaranteeing partition balance—worst-case **O(n)** deterministic select (Blum–Floyd–Pratt–Rivest–Tarjan). |
| **Patience Sorting** | Pile cards with patience rules—number of piles equals **LIS length**; with binary search yields O(n log n) LIS recovery. |
| **Counting Inversions (Merge Sort)** | During merge step count cross-inversions when right element moves before leftovers of left—O(n log n). |
| **K-way Merge** | Combine k sorted lists using min-heap of size k—O(N log k) for total N elements (multiway merge sort run merging). |
| **Introselect (BFPRT Select)** | Median-of-medians selection to guarantee linear-time nth-element in worst case (cousin of IntroSort’s hybrid spirit). |

### Array / prefix / window

| Term | Definition |
|------|------------|
| **Kadane’s Algorithm** | Linear scan keeping best subarray sum ending at current index for maximum subarray sum. |
| **Sliding Window** | Maintain aggregate over a contiguous subarray of fixed or variable size as it moves along the sequence. |
| **Two Pointer Technique** | Advance two indices from ends or start under monotonicity to solve search or partition in O(n). |
| **Prefix Sum** | Precompute cumulative sums so any interval sum is difference of two prefix values in O(1). |
| **Difference Array Technique** | Store increments at range boundaries then prefix-sum once to apply many range adds. |
| **Monotonic Stack Technique** | Use increasing/decreasing stack to solve next greater element or histogram area in linear time. |
| **Monotonic Queue Technique** | Deque tracking min/max in sliding window in amortized O(1) per step. |
| **Coordinate Compression** | Map large coordinate values to ranks 0..k-1 preserving order for indexing structures. |
| **Meet in the Middle** | Split exponential search space in half and combine halves with hashing for subset problems. |
| **Reservoir Sampling** | Single-pass uniform random sample of k items from unknown-length stream using fixed memory. |
| **Quickselect** | Randomized or median-of-medians partition to find kth smallest in average O(n) time. |
| **Boyer Moore Voting Algorithm** | Find majority element by pairing distinct values and canceling counts in one pass. |
| **Dutch National Flag Algorithm** | Three-way partition array into values <, =, > pivot in one scan (Dijkstra’s flag). |
| **Floyd Cycle Detection Algorithm** | Tortoise and hare pointers to detect cycle and optionally find start in linked list or function graph. |

### Recursion / backtracking

| Term | Definition |
|------|------------|
| **Backtracking** | Depth-first trial of choices with undo when constraints fail to enumerate solutions. |
| **Branch and Bound** | Search tree pruned by bounds on objective so suboptimal branches are not fully explored. |
| **N Queens Algorithm** | Place N non-attacking queens on N×N board via backtracking with column/diagonal checks. |
| **Rat in a Maze** | Find path from start to exit in grid maze using DFS/backtracking with blocked cells. |
| **Sudoku Solver** | Fill empty cells with digits 1–9 respecting row/column/box constraints via backtracking. |
| **Tower of Hanoi** | Recursive puzzle moving disks between pegs obeying size order with 2^n−1 moves optimal. |

### Graph traversal

| Term | Definition |
|------|------------|
| **Breadth First Search** | Explore graph layer by layer using a queue, shortest unweighted path from a source. |
| **Depth First Search** | Explore graph along edges going deep then backtrack, using stack or recursion. |
| **Iterative Deepening DFS** | Repeated DFS with increasing depth limit to mimic BFS memory while keeping DFS stack small. |

### Shortest path

| Term | Definition |
|------|------------|
| **Dijkstra’s Algorithm** | Non-negative edge weights: greedy relaxation from closest unsettled vertex using a priority queue. |
| **Bellman Ford Algorithm** | Relax all edges V−1 times to find shortest paths allowing negative edges, detects negative cycles. |
| **Floyd Warshall Algorithm** | Dynamic programming over all intermediate vertices for all-pairs shortest paths in O(V³). |
| **Johnson’s Algorithm** | Reweight graph with Bellman–Ford hub then run Dijkstra from each vertex for sparse all-pairs. |
| **SPFA** | Queue-based Bellman–Ford variant relaxing only vertices whose distance recently improved. |
| **0-1 BFS** | Shortest path on graph with edge weights 0 or 1 using deque (push front for 0, back for 1). |
| **A* Search Algorithm** | Best-first search from start to goal using cost-so-far plus heuristic estimate to goal. |
| **Shortest Path in DAG** | Single-source: relax edges once in topological order in O(V+E); weights can be negative if no cycle. |
| **Longest Path in DAG** | Negate weights and run shortest, or DP with topo order for longest weighted path (NP-hard on general graphs). |
| **Multi-source BFS** | Initialize queue with several sources; first hit layers give distance to nearest source in O(V+E) unweighted. |
| **Multi-source Dijkstra** | Super-source connecting to all starts with zero edge—one Dijkstra for nearest-facility distances (non-negative weights). |
| **Bidirectional BFS** | Search forward from start and backward from goal meeting in middle cuts branching factor ~`b^(d/2)` on unweighted graphs. |
| **Bidirectional Dijkstra** | Two priority queues from both ends until fronts meet—useful on road networks with non-negative weights. |
| **Dial’s Algorithm (Bucket Dijkstra)** | Dijkstra for small integer weights W: buckets modulo `(W·V)` give O(W·V+E) like radix heap level 0 (also “Dial’s IMP” variant). |

### Minimum spanning tree

| Term | Definition |
|------|------------|
| **Kruskal’s Algorithm** | Sort edges by weight, add edge if it connects two different DSU components until tree complete. |
| **Prim’s Algorithm** | Grow MST from a seed vertex always adding cheapest edge to a new vertex outside the tree. |
| **Boruvka’s Algorithm** | Repeatedly add cheapest edge incident to each component in parallel until one tree remains. |

### Strongly connected components

| Term | Definition |
|------|------------|
| **Kosaraju’s Algorithm** | Two DFS passes: order by finish time on G, then DFS on transpose to peel SCCs. |
| **Tarjan’s Algorithm** | One DFS with lowlink numbers to find SCCs and articulation points in single pass. |
| **Condensation Graph Construction** | Contract each strongly connected component to one vertex of the **condensation DAG** (DAG of SCCs) for acyclic reachability problems. |
| **Bridge Tree / Block-Cut Tree** | Compress 2-edge-connected components separated by bridges (and analogously articulation points) into a tree or cactus-style structure for path queries. |

### Flow / matching

| Term | Definition |
|------|------------|
| **Ford Fulkerson Algorithm** | Augment flow along residual paths until max flow reached (capacity-scaling variants improve bound). |
| **Edmonds Karp Algorithm** | Ford–Fulkerson using shortest augmenting path by BFS giving O(VE²) bound. |
| **Dinic’s Algorithm** | Level graph blocking flow augmentations for O(V²E) or better on unit networks. |
| **Push Relabel Algorithm** | Preflow with height labels and local pushes/relabels for fast max flow in practice. |
| **Hopcroft Karp Algorithm** | BFS layering plus DFS matching for bipartite maximum matching in O(E√V). |
| **Hungarian Algorithm** | Polynomial algorithm for assignment problem (minimum weight perfect matching in bipartite graphs). |
| **Min-Cost Max-Flow (MCMF)** | Augment flow along cheapest residual paths (possibly with potentials) until max flow reached—minimizes total cost for fixed flow value. |
| **Successive Shortest Augmenting Path** | MCMF variant: repeatedly send flow along shortest-path (by cost) in residual graph with Johnson-style potentials for non-negative reduced costs. |

### Advanced graph algorithms (paths, matchings, cuts, connectivity)

| Term | Definition |
|------|------------|
| **Hierholzer’s Algorithm** | Builds Eulerian circuit/cycle by greedily extending a trail and splicing loops, in O(E) for Eulerian graphs. |
| **Kuhn’s Algorithm** | DFS augmenting-path algorithm for **maximum bipartite matching** (alternating paths from unmatched left vertices), O(VE) typical. |
| **Edmonds’ Blossom Algorithm** | Shrinks odd-length blossoms to find **maximum matching in general (non-bipartite) graphs** in polynomial time. |
| **Chu-Liu / Edmonds’ Algorithm** | **Directed MST (arborescence)**: minimum-cost rooted spanning tree in a directed graph—contract cycles and recurse. |
| **Karger’s Minimum Cut** | Randomly contract edges until two vertices remain; repeat for high success probability—Monte Carlo global min-cut in near-quadratic randomized time. |
| **Gabow’s Algorithms** | Family including **scaling max-flow** / matching improvements (Gabow 1985) and efficient data structures for network algorithms—context-specific “Gabow” usually means a scaling or disjoint-set technique in that paper lineage. |
| **Tarjan’s Offline LCA** | Answer batch LCA queries in O(V+E+q·α(V)) using **union-find** on DFS traversal (`+1` queries) or Tarjan–Vishkin variations. |
| **Euler Tour + RMQ LCA** | Record Euler tour of tree with depth; LCA = shallowest node between u,v in tour interval → ±1 RMQ or sparse table O(1) query after O(n log n) prep. |
| **DSU Rollback (Undo Union–Find)** | Maintain stack of union operations to **pop/rollback** for divide-and-conquer or offline queries—store merged root’s previous parent. |
| **Offline Dynamic Connectivity** | Answer connectivity queries over time by **divide-and-conquer on time** segments with DSU rollback, or Link–Cut Tree for fully online variant. |

### Tree algorithms

| Term | Definition |
|------|------------|
| **Binary Lifting** | Precompute 2^k-th ancestors to answer LCA and k-th ancestor in O(log n) per query. |
| **Euler Tour Technique** | Linearize subtree ranges via DFS entry/exit times for segment-tree updates on subtrees. |
| **Heavy Light Decomposition** | Decompose tree edges into O(log n) chains so each root-to-node path meets O(log n) segment trees for aggregates. |
| **Centroid Decomposition** | Recursively remove a centroid so each subtree is at most half the size, enabling divide-and-conquer on paths through centroids. |
| **Lowest Common Ancestor** | Problem/technique: deepest node ancestor to two given nodes (binary lifting, RMQ on Euler tour, etc.). |
| **Morris Traversal** | Inorder binary tree traversal in O(1) extra space by temporarily threading right pointers. |
| **Tree Flattening** | Map subtree to contiguous array index range via Euler tour for static or dynamic queries. |
| **Rerooting DP** | Dynamic programming on tree computing answer for every root by propagating reroot transitions. |
| **DSU on Tree (Sack Technique)** | For subtree frequency queries: small-to-large merge of child frequency maps so each vertex contributes O(log n) amortized—answers many “color count in subtree” offline queries. |
| **Small-to-Large Merging** | Heuristic merging smaller map/set into larger to bound total O(n log n) work (same principle as DSU on tree for Mo’s on tree variants). |
| **Tree Diameter Algorithm** | Two BFS/DFS from arbitrary farthest, then again from that farthest—tree’s diameter length (pairs of furthest nodes). |
| **Tree Isomorphism** | Decide if two unrooted trees are structurally identical—canonical forms via AHU hashing, centroid rooting, or pruning leaves iteratively. |

### String algorithms

| Term | Definition |
|------|------------|
| **Knuth Morris Pratt Algorithm** | Linear substring search using failure function of pattern to skip redundant comparisons. |
| **Rabin Karp Algorithm** | Rolling hash of window compared to pattern for multi-pattern or single search with collision check. |
| **Z Algorithm** | Computes Z-array: longest common prefix of string with each suffix, used in matching and palindromes. |
| **Boyer Moore Algorithm** | Substring search skipping using bad-character and good-suffix rules from the right of pattern. |
| **Aho Corasick Algorithm** | Multi-pattern automaton (trie + failure links) scanning text once for all patterns. |
| **Manacher’s Algorithm** | Linear-time longest palindromic substring/radius array using mirrored palindrome expansion. |
| **Kasai Algorithm** | Builds LCP array from suffix array in linear time using height trick on suffix ranks. |
| **Ukkonen’s Algorithm** | Online linear-time construction of suffix tree incrementally extending the active point. |
| **Prefix Function Algorithm** | Computes π for KMP: length of longest proper prefix of prefix that is also a suffix. |
| **Suffix Automaton Construction** | Incremental linear-time build of minimal DFA for all substrings—extend with `last`, `clone`, and transition copying (Maxlen, link). |
| **Suffix Array Construction (Prefix Doubling)** | Sort cyclic ranks, double length each phase O(n log n); with radix sort O(n log n) or O(n) on integers after refinement tricks. |
| **Suffix Array Construction (SA-IS)** | Induced sorting **linear-time** SA for integer alphabets (Nong–Zhang–Chan algorithm class). |
| **Suffix Array Construction (DC3 / Skew)** | Divide sample suffixes modulo 3, recurse, merge—O(n) for integer/ranked alphabet in theory. |
| **Eertree (Palindromic Tree)** | Online structure for distinct palindromes with `fail` link like Aho–Corasick—counts/each palindrome in amortized O(1) per char. |
| **Duval’s Algorithm** | **Lyndon factorization** of a string into nonincreasing lexicographic Lyndon words in O(n) with three-pointer scan. |
| **Lyndon Factorization** | Unique decomposition `s = w₁ w₂ … wₖ` where each `wᵢ` is strictly smallest among its rotations (Lyndon word). |
| **Booth’s Algorithm** | Lexicographically **minimal string rotation** in O(n) via failure-function style on doubled string. |
| **Boyer–Moore–Horspool Algorithm** | Simplified Boyer–Moore using only **bad-character** on pattern’s last character per shift—simple and fast in practice. |
| **Shift-And / Bitap Algorithm** | Bit-parallel exact matching for short patterns—mask shifts AND/OR with alphabet bitmasks, O(⌈m/w⌉·n) machine words `w`. |
| **Rope Concatenation / Split** | Balanced-tree (e.g. treap, B-tree) of chunks for O(log n) split/concat and indexed access—text-editor ropes. |

### Dynamic programming

| Term | Definition |
|------|------------|
| **Memoization** | Top-down DP caching recursive subproblem results in a table or map. |
| **Tabulation** | Bottom-up DP filling an iteration order that respects dependency direction without recursion. |
| **Bitmask DP** | State includes a subset bitmask over a small universe (e.g. traveling salesman on n≤20). |
| **Digit DP** | Count numbers in interval satisfying digit constraints by DP on position, tightness, and carries. |
| **Tree DP** | Dynamic programming on rooted tree where transitions merge children subtrees into parent state. |
| **Profile DP** | Grid DP state is a boundary “profile” (e.g. plug DP) for tiling or connectivity problems. |
| **SOS DP** | Sum over supersets or subsets using zeta/Möbius on subsets in O(k·2^k). |
| **Divide and Conquer DP Optimization** | When cost quadrangle inequality holds, split point monotonicity speeds Knuth-style transitions. |
| **Knuth Optimization** | Speeds interval DP when quadrangle inequality and monotonicity of argmin split points hold. |
| **Convex Hull Trick** | Maintain lower hull of lines to query min/max at x for linear transition functions in amortized log or deque. |
| **Matrix Exponentiation DP** | Represent linear recurrence or small state machine as matrix power for fast nth term. |
| **0/1 Knapsack** | Each item used at most once: DP `dp[i][w]` or space-optimized 1D over weights—maximize value with capacity constraint. |
| **Unbounded Knapsack** | Unlimited copies per item: recurrence allows `dp[w-a_i]` same layer; sometimes solvable as complete knapsack with monotonic queue tricks. |
| **Bounded Knapsack** | Each item has a count limit: binary splitting into 0/1 items, monotone queue optimization, or DP on multiplicity. |
| **Subset Sum** | Decide or count ways to hit exact sum using bitset or boolean DP over items (special knapsack with value=weight). |
| **Partition Equal Subset Sum** | Split multiset into two equal-sum parts ⇔ subset sum to half of total; pseudo-polynomial in sum. |
| **Coin Change (Minimum Coins)** | Unbounded or bounded coins: minimize number of coins to reach amount (BFS on amounts or DP min coins). |
| **Coin Change (Number of Ways)** | Count combinations/orderings depending on statement—classically combinations via DP `ways[sum] += ways[sum-c]`. |
| **Longest Increasing Subsequence (LIS)** | `dp[i]` length ending at i gives O(n²); patience sorting / binary search on tails gives O(n log n). |
| **Longest Common Subsequence (LCS)** | Classic 2D DP on two sequences comparing last characters; also derivable from LCS DAG. |
| **Longest Common Substring** | Contiguous match: DP with reset when chars differ; or rolling hash + binary search on length. |
| **Edit Distance (Levenshtein)** | Minimum insert/delete/replace to transform string A into B; 2-row or full matrix DP. |
| **Matrix Chain Multiplication** | Order of parentheses minimizing scalar multiplies: interval DP on chain of matrix dimensions. |
| **Rod Cutting** | Unbounded lengths with prices: unbounded knapsack–style maximize revenue for rod length `n`. |
| **Egg Dropping** | Minimize worst-case trials with `e` eggs and `f` floors: DP on (eggs, floors) or optimized monotonic search. |
| **Weighted Interval Scheduling** | Jobs with start, end, weight—sort by end time, DP with binary search on last non-overlapping predecessor. |
| **Palindrome Partitioning DP** | Min cuts or count ways to partition string into palindromes using palindrome preprocessing + interval/cuts DP. |
| **Interval DP** | Optimal cost on segment `[l,r]` by merging or splitting at `k`—matrix chain, optimal BST, burst balloons style. |
| **DAG DP** | Process vertices in topological order so all predecessors resolved—shortest/longest path, paths count in DAG. |
| **Catalan DP** | Count structures obeying Catalan recurrence (balanced parentheses, BST shapes, convex polygon triangulation counts)—closed form or tabulated `C_n`. |

### Greedy

| Term | Definition |
|------|------------|
| **Huffman Coding** | Build optimal prefix-free code by repeatedly merging two least frequent subtrees (greedy on frequencies). |
| **Activity Selection** | Choose maximum non-overlapping intervals by repeatedly picking earliest finishing compatible interval. |
| **Fractional Knapsack** | Take items by value/weight ratio greedily until capacity (divisible items allowed). |
| **Job Sequencing** | Schedule jobs with deadlines and profits by greedy on profit with DSU or slot filling. |

### Number theory

| Term | Definition |
|------|------------|
| **Euclidean Algorithm** | Repeated remainder gcd(a,b)=gcd(b,a mod b) until zero for greatest common divisor. |
| **Extended Euclidean Algorithm** | Finds integers x,y with ax+by=gcd(a,b) for modular inverses and Diophantine solutions. |
| **Sieve of Eratosthenes** | Mark multiples of each prime up to n to list primes in O(n log log n) time. |
| **Segmented Sieve** | Run sieve on interval [L,R] using primes up to √R without storing all numbers up to R. |
| **Euler Totient Algorithm** | Compute φ(n) by product formula over distinct prime factors or sieve totients up to n. |
| **Chinese Remainder Theorem** | Reconstruct x modulo product of coprime moduli from residues modulo each factor. |
| **Fermat Little Theorem** | If p is prime and gcd(a,p)=1 then a^(p−1) ≡ 1 (mod p); used for inverse when p is prime. |
| **Miller Rabin Primality Test** | Probabilistic compositeness test using modular squaring and witness checks for large primes. |
| **Pollard Rho Algorithm** | Randomized factor finding using Floyd cycle detection on pseudo-random polynomial mod n. |
| **Lucas Theorem** | Relates binomial coefficients modulo prime p to base-p digits of n and k for combinatorics mod p. |
| **Sieve of Atkin** | Alternative prime sieve using modulo-60 wheel and flip rules—O(n / log log n) time and lower constants controversy vs Eratosthenes in practice. |
| **Wheel Factorization** | Skip multiples of first k primes using modular arithmetic pattern (wheel) to speed trial division or segmented sieving. |
| **Baby-Step Giant-Step** | Discrete log in group: find `x` with `a^x = b` using `O(√m)` space/time meet-in-the-middle (Shanks). |
| **Tonelli–Shanks Algorithm** | Finds square roots modulo **odd prime** `p` when they exist—used in quadratic residue computations and some cryptosystems. |
| **Berlekamp–Massey Algorithm** | Finds **shortest linear recurrence** satisfied by a given sequence over a field—minimal polynomial for linear-feedback shift register. |
| **Möbius Inversion** | Invert sums over divisors: `g(n)=Σ_{d\|n} f(d)` ⇔ `f(n)=Σ_{d\|n} μ(d)g(n/d)` for arithmetic functions; basis for inclusion–exclusion on divisors. |
| **Fast Zeta Transform (FZT)** | On subset lattice: compute `g[S]=Σ_{T⊆S} f[T]` for all `S` in O(k·2^k) by SOS-style DP (supersum / subset sum transforms). |
| **Fast Möbius Transform (FMT)** | Inverse of subset zeta: recover `f` from `g` via Möbius on subsets—used in subset convolutions. |
| **Primitive Root Finding** | Generator `g` of multiplicative group mod `p` (cyclic)—factor `p−1`, test candidates with `gcd` conditions; used in NTT primitive roots analogs. |
| **Legendre’s Formula** | Exponent of prime `p` in `n!`: `e_p(n!)=Σ_{i≥1} ⌊n/p^i⌋`—factorials, binomial valuations, trailing zeros. |
| **Pollard Rho Variants** | Floyd/Brent cycle detection, random `f(x)=x²+c mod n`, batch GCD—tuning for 64-bit factorization in contests. |
| **Trial Division** | Test divisibility up to `√n` (or with wheel)—baseline factorization and small prime checks. |
| **Prime Factorization by Sieve** | Precompute **smallest prime factor (SPF)** for each integer up to N in O(N log log N), then factor each query in O(log n). |

### Mathematics

| Term | Definition |
|------|------------|
| **Binary Exponentiation** | Compute a^n in O(log n) multiplications by squaring while multiplying accumulator for set bits. |
| **Fast Modular Exponentiation** | Binary exponentiation with modulo at each multiply to avoid overflow in modular arithmetic. |
| **Matrix Exponentiation** | Raise a square matrix to n-th power by squaring for linear recurrences and graph walks. |
| **Gaussian Elimination** | Row-reduce augmented matrix to solve linear systems or invert matrix over reals or finite fields. |
| **Strassen Matrix Multiplication** | Divide-and-conquer 7-multiplication recursion beating O(n³) for large dense matrices asymptotically. |
| **Karatsuba Multiplication** | Multiply large integers by three half-size multiplications instead of four (divide and conquer). |
| **FFT** | Fast Fourier transform converts convolution to pointwise product in O(n log n) for polynomial multiply. |
| **Fast Walsh Hadamard Transform** | XOR/AND/OR convolution of 0–1 vectors via butterfly operations analogous to FFT. |

### Geometry

| Term | Definition |
|------|------------|
| **Graham Scan** | Sort points by polar angle around lowest point then stack scan for convex hull O(n log n). |
| **Jarvis March** | Gift wrapping convex hull by repeatedly choosing leftmost next point O(nh) for h hull vertices. |
| **Monotone Chain Algorithm** | Andrew’s scan: sort points, build lower and upper hull chains in O(n log n). |
| **Rotating Calipers** | Pair parallel lines/supporting lines rotating around convex polygon for diameter, width, etc. |
| **Sweep Line Algorithm** | Process geometric events in sorted order (e.g. vertical line) to count intersections or build structures. |
| **Closest Pair of Points** | Divide plane, recurse, merge checking only strip near split line in O(n log n). |
| **Line Intersection Algorithm** | Solve two linear equations or parametric forms to find intersection point of two lines/segments. |
| **Bentley–Ottmann Sweep Line** | Report **all k segment intersections** in O((n+k) log n) by sweeping vertical line with AVL of active segments and event queue. |
| **Half-Plane Intersection** | Intersection of many half-planes is a (possibly empty) convex polygon—incremental or divide-and-conquer clipping. |
| **Minkowski Sum** | `{a+b : a∈A, b∈B}` of polygons—vertex walk on two convex boundaries for robot obstacles swollen by shape. |
| **Point in Polygon (Ray Casting)** | Cast ray from point, count odd/even crossings with polygon edges—works for simple polygons. |
| **Point in Polygon (Winding Number)** | Signed angle / turn summation around point; robust for non-simple cases with careful epsilon rules. |
| **Convex Polygon Intersection** | Intersect two convex polygons in O(n+m) by rotating calipers or incremental clipping (Sutherland–Hodgman style). |
| **Polygon Area (Shoelace Formula)** | `A = ½ |Σ (x_i y_{i+1} - x_{i+1} y_i)|` for simply connected polygon vertices in order. |
| **Polygon Triangulation** | Partition simple polygon into triangles in O(n) (Chazelle) or practical ear-clipping O(n²)—used in rendering and area integrals. |

### Range query

| Term | Definition |
|------|------------|
| **Mo’s Algorithm** | Offline sqrt decomposition reordering queries on array to answer range mode/frequency in O((n+q)√n) style bounds. |
| **Sparse Table Algorithm** | Static range minimum (or other idempotent range query) in O(1) per query after O(n log n) preprocessing on overlapping intervals. |
| **Lazy Propagation** | Deferred application of range updates on segment tree until query forces push to children. |
| **Fenwick Tree Operations** | Point update and prefix sum (or range with tricks) on BIT in O(log n). |

### Bit manipulation

| Term | Definition |
|------|------------|
| **Brian Kernighan Algorithm** | Clear lowest set bit: `n & (n-1)` to count set bits or strip bits in loops. |
| **Gray Code Generation** | Reflective binary ordering where successive codes differ by one bit for rotary encoders. |

### Game / AI

| Term | Definition |
|------|------------|
| **Minimax Algorithm** | Two-player zero-sum game tree search maximizing own score assuming opponent minimizes it. |
| **Alpha Beta Pruning** | Minimax with bounds that skip branches provably worse than already explored alternatives. |
| **Simulated Annealing** | Probabilistic optimization accepting worse moves with decreasing temperature to escape local minima. |
| **Genetic Algorithm** | Maintain population of solutions, select, crossover, mutate toward better fitness over generations. |
| **Hill Climbing** | Greedy local search moving to best neighbor until no improvement (local optimum risk). |
| **Gradient Descent** | Iteratively move parameters opposite the gradient of loss to minimize differentiable objectives. |

### Randomized

| Term | Definition |
|------|------------|
| **Randomized QuickSort** | Choose random pivot to achieve expected O(n log n) regardless of input order. |
| **Randomized Select** | Quickselect with random pivot for expected linear kth element selection. |
| **Monte Carlo Algorithm** | Randomized algorithm that may be wrong with small bounded probability but always fast. |
| **Las Vegas Algorithm** | Randomized algorithm that always returns correct answer but runtime is random (e.g. quickselect worst case rare). |
| **Randomized Contraction (Karger–style)** | Edge contraction at random toward min-cut certificate—same family as Karger’s min-cut (see Advanced graph algorithms). |
| **Beam Search** | Pruned best-first search keeping only top-β candidates per depth—common in decoding and heuristic planning. |
| **Iterative Deepening A* (IDA*)** | Repeated depth-limited search with increasing `f = g+h` threshold—A* memory savings for huge branching factor. |
| **Monte Carlo Tree Search (MCTS)** | UCT-style random playouts with tree policy updating visit/win counts—used in games (Go, chess engines) and planning. |

### Compression

| Term | Definition |
|------|------------|
| **Huffman Coding** | Optimal prefix code from symbol frequencies (same as greedy Huffman above in role as compressor). |
| **LZW Compression** | Dictionary-based encoder replacing repeated phrases with growing code table indices in stream. |

### Distributed / systems

| Term | Definition |
|------|------------|
| **Consistent Hashing** | Hash ring mapping nodes and keys so few keys remap when servers join or leave the cluster. |
| **MapReduce** | Programming model: map emits key–values, shuffle groups, reduce aggregates in parallel batches. |
| **Paxos Algorithm** | Consensus protocol for agreeing on one value among fault-prone processors with majority quorums. |
| **Raft Consensus Algorithm** | Leader-based replicated log consensus easier to reason about than classical Paxos for practitioners. |

### Cryptography

| Term | Definition |
|------|------------|
| **RSA Algorithm** | Public-key cryptosystem based on difficulty of factoring product of two large primes. |
| **Diffie Hellman Key Exchange** | Two parties derive shared secret over public channel using discrete log hardness in a group. |
| **AES** | Symmetric block cipher standard using substitution–permutation network with fixed key sizes (e.g. 128/192/256). |
| **SHA Hashing** | Family of cryptographic hash functions producing fixed-length digests from arbitrary messages. |
| **ElGamal Encryption** | Public-key encryption based on discrete logarithm in cyclic groups (related to DH). |

### Paradigms / techniques

| Term | Definition |
|------|------------|
| **Divide and Conquer** | Split problem into independent subproblems, solve recursively, combine (merge sort, closest pair). |
| **Dynamic Programming** | Solve overlapping subproblems once and reuse answers in optimal order (memoization or tabulation). |
| **Greedy Method** | Repeatedly choose locally best option hoping global optimum (proof or exchange argument needed). |
| **Backtracking** | Systematic depth-first trial of choices with undo when constraints fail to enumerate valid configurations. |
| **Branch and Bound** | Search with upper/lower bounds to prune branches that cannot improve incumbent solution. |
| **Sliding Window** | Maintain aggregate over a contiguous subarray of fixed or variable size while advancing its start or end in one pass. |
| **Two Pointers** | Advance two indices from one or both ends of a sequence using monotonicity to avoid redundant checks. |
| **Recursion** | Function calls itself on smaller subinstances until base case combines results. |
| **Memoization** | Store computed results of subproblems in a table keyed by arguments to avoid recomputation in recursive algorithms. |
| **Offline Query Processing** | Answer batch of queries after preprocessing or reordering (e.g. Mo’s, sweep with events). |
| **Binary Search on Answer** | Monotone predicate on integer/real answer: binary search smallest/largest feasible value. |
| **Bitmasking** | Represent small sets as integers with bitwise AND/OR/XOR for combinatorial enumeration. |
| **Meet in the Middle** | Split a set into two halves, enumerate subset sums of each half, then combine with sorting or hashing for exact targets. |

### Parsing, expressions, and streaming selection

| Term | Definition |
|------|------------|
| **Shunting Yard Algorithm** | Dijkstra’s two-stack method converts **infix** expressions with parentheses and precedence to **RPN** (postfix) in one linear scan. |
| **Reverse Polish Notation Conversion** | Output of shunting yard or recursive descent: operators follow operands—easy to evaluate with a stack. |
| **Expression Evaluation** | Typically RPN stack evaluation or recursive descent with precedence climbing for infix—combines lexical tokens and operator semantics. |
| **Top-k via Heap** | Maintain **min-heap** of size k while streaming: yields k largest; **max-heap** variant for k smallest—O(n log k) time. |
| **Reservoir Sampling Variants** | Vitter’s algorithm, stratified streams—uniform k-sample from unknown-length stream in one pass; weighted extensions for unequal probabilities. |

---

## How to use this extended list

- **Order inside `## Algorithms`:** generic patterns appear first **(Searching → Sorting → …)**; **foundational graph flows** (BFS variants, DAG shortest paths) sit with **Shortest path**; **matchings, cuts, Euler tours, and offline connectivity** are grouped under **Advanced graph algorithms**; **classic DP knapsacks and sequence DP** extend **Dynamic programming** without duplicating paradigm definitions above.
- **Structures vs algorithms:** where a topic is primarily a **data structure** (e.g. **Euler Tour Tree**, **Suffix Automaton**), you will also find a **construction or usage** row under **String** / **Tree** / **Data structures** elsewhere in this file.
- **Duplicates consolidated:** **Karger’s min-cut**, **Tarjan offline LCA**, and **Euler tour / RMQ** appear once in the most natural subsection; cross-reference mentally with **Tree algorithms** when solving LCA batch problems.
