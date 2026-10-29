cmake_minimum_required(VERSION 3.29)
project(LabRab2_sem3)

set(CMAKE_CXX_STANDARD 20)

add_executable(LabRab2_sem3 main.cpp
        structs/array.cpp
        structs/array.h
        structs/stack.cpp
        structs/stack.h
        structs/dlist.cpp
        structs/dlist.h
        structs/queue.cpp
        structs/queue.h
        structs/slist.cpp
        structs/slist.h
        structs/cbt.cpp
        structs/cbt.h
        tasks/tasks.h
        tasks/task1_asteroids.cpp
        tasks/task1_asteroids.h
        tasks/task2_set.cpp
        tasks/task2_set.h
        tasks/task3_turtles.cpp
        tasks/task3_turtles.h
        tasks/task4_histogram.cpp
        tasks/task4_histogram.h
        tasks/task5_tree.cpp
        tasks/task5_tree.h
        tasks/task6_hash.cpp
        tasks/task6_hash.h
        tasks/task7_cache.cpp
        tasks/task7_cache.h
        structs/hashtable_chaining.h
        structs/hashtable_chaining.cpp
        structs/hashtable_cuckoo.h
        structs/hashtable_cuckoo.cpp
        structs/set.h
        structs/set.cpp
        structs/lfu_cache.h
        structs/lfu_cache.cpp)
