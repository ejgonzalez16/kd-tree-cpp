# KD-Tree Implementation in C++ (2D)

This project contains a custom implementation of a **2D KD-Tree (k-dimensional tree)** using C++ templates.  
It supports insertion, spatial search, nearest-neighbor detection, height calculation, and multiple tree traversals.

The structure is implemented entirely from scratch using raw pointers, recursion, and manual memory handling.

---

## 🚀 Features

### ✔ 2D Point Support
Each node stores:
- `x` coordinate  
- `y` coordinate  
- a generic data value `T`

### ✔ Dynamic Tree Insertion
Points are inserted recursively, alternating comparison between:
- **X-axis** (depth % 2 == 0)  
- **Y-axis** (depth % 2 == 1)

### ✔ Nearest-Neighbor Search
The tree implements a recursive search function that:
- Traverses based on the splitting dimension  
- Computes Euclidean distance to the query point  
- Returns the closest node found  

### ✔ Tree Traversals
Supported traversal orders:
- **Pre-order**
- **In-order**
- **Post-order**
- **Level-order** (breadth-first)

### ✔ Node Utilities
Each `NodoKD<T>` includes:
- Getters and setters for coordinates and data  
- Height calculation  
- Counting children  
- Retrieving deepest or largest descendant  

### ✔ Manual Memory Management
- Raw pointer structure  
- Explicit destructor to free allocated nodes  
- Uses STL only for helper containers (vectors/lists)

---

## 🧠 Why a KD-Tree?

KD-Trees are widely used in:

- **Game development** (AI queries, collision approximations, spatial partitioning)
- **Spatial indexing**
- **Nearest-neighbor search**
- **Optimization for pathfinding**
- **Clustering / ML algorithms**

This implementation demonstrates:
- Understanding of recursive spatial structures  
- Branch partitioning logic  
- Manual memory handling in C++  
- Pruned search in metric spaces  

---
