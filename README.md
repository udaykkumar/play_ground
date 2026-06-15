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
├── ds/                              # Data structures & algorithms
│   ├── c/                           #   C implementations
│   │   ├── graph/
│   │   ├── list/
│   │   ├── queue/
│   │   ├── stack/
│   │   └── tree/
│   ├── cpp/                         #   C++ implementations
│   │   ├── binary-tree/
│   │   ├── binary-search-tree/
│   │   ├── sll/                     #   Single linked list
│   │   ├── dll/                     #   Double linked list
│   │   ├── improved-dll/
│   │   ├── circular-sll/
│   │   ├── red-black-tree/
│   │   └── misc/
│   ├── graphs/                      #   Graph algorithms
│   └── python/                      #   Python implementations
│
├── books/                           # Book exercises
│   ├── learncpp/                    #   learncpp.com
│   ├── lectures/                    #   Lecture code samples
│   ├── modern-cpp-challenge/        #   "The Modern C++ Challenge"
│   └── effective-cpp/               #   "55 Specific Ways..."
│
├── leetcode/                        # LeetCode problems
│   ├── blind75/                     #   Blind 75
│   ├── problems/                    #   Per-problem directories
│   └── online/                      #   Online judge solutions (Boost tests)
│
├── misc/                            # Miscellaneous algorithm programs
│
├── projects/                        # Standalone projects
│   ├── btree/                       #   B-tree implementation
│   ├── cms/                         #   Content management system
│   ├── ping-pong/                   #   Ping-pong game (ncurses)
│   ├── scheduler/                   #   Job scheduler
│   ├── servers/                     #   Server experiments
│   └── python-tools/                #   Python utilities
│
├── cmake/                           # CMake modules (GitUtils, FindGLEW)
├── CMakeLists.txt                   # Top-level build
└── .travis.yml                      # CI configuration
```

## License

This is a personal learning repository. No formal license is applied.