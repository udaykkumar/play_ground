# play_ground

A C/C++ playground for data structures, algorithms, coding challenges, and small projects — built with CMake, tested with Boost.Test, and benchmarked with Google Benchmark.

## Prerequisites

- GCC 7+ or Clang with C++17 support
- CMake 3.14+
- Ninja (recommended) or Make
- Boost (unit_test_framework)
- ncurses

Ubuntu/Debian:
```bash
sudo apt update && sudo apt install -y build-essential cmake ninja-build libboost-test-dev libncurses-dev
```

## Build

With Ninja (faster):
```bash
cmake -B build -G Ninja
cmake --build build
```

With Make:
```bash
cmake -B build
cmake --build build
```

## Run Tests

```bash
cd build && ctest --output-on-failure
```

Or simply:
```bash
cd build && make test        # if using Make
cd build && ninja test       # if using Ninja
```

Run a single test by name:
```bash
ctest -R binary-tree-test --output-on-failure
```

Google Test and Google Benchmark are fetched automatically at configure time via `cmake/GitUtils.cmake`.

## Project Layout

```
├── dsalgo_play_c_*          # C data structures (graph, list, queue, stack, tree)
├── dsalgo_play_cpp_*        # C++ data structures (linked lists, binary tree, BST)
├── dsalgo_play_general_graphs  # Graph algorithms
├── dsalgo_play_python       # Python algorithm implementations
│
├── books_play_learncpp      # Exercises from learncpp.com
├── books_play_lectures      # Lecture code samples
├── books_play_the_modern_cpp_challenge  # "The Modern C++ Challenge" solutions
├── books_play_55_specific_ways_to_improve_your_programs_and_design
│
├── misc_play_blind_75       # Blind 75 LeetCode problems
├── misc_play_lc             # Additional LeetCode problems
├── misc_play_programs       # Miscellaneous algorithm programs
├── online_play_lc           # Online judge solutions with Boost tests
│
├── projects_play_btree      # B-tree implementation
├── projects_play_cms        # Content management system
├── projects_play_ping_pong  # Ping-pong game (ncurses)
├── projects_play_scheduler  # Job scheduler
├── projects_play_servers    # Server experiments
├── projects_play_python_tools  # Python utilities
│
├── cmake/                   # CMake modules (GitUtils, FindGLEW)
├── CMakeLists.txt           # Top-level build
└── .travis.yml              # CI configuration
```

## License

This is a personal learning repository. No formal license is applied.