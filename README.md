# Multithreaded-Square-Root-Sum-Calculator


# Project Purpose

The purpose of this project is to develop a multithreaded program that calculates the sum of square roots within a specified numerical range. The project explores three distinct synchronization methods, each involving different levels of parallelism and thread coordination. The main objectives and components of the project include:

## Multithreading and Synchronization

- Implement threads to concurrently calculate the square root of numbers within a given range.
- Explore various synchronization methods to manage access to shared resources, such as the global sum of square roots.

## Synchronization Methods

### Method 1 (d = 1)

- All threads simultaneously update the global sum without utilizing critical sections or mutex variables.

### Method 2 (d = 2)

- All threads update the global sum sequentially, utilizing a single shared mutex variable to protect the critical section.

### Method 3 (d = 3)

- Each thread employs a local variable to calculate the sum of square roots. After local sums are computed, a mutex-protected global sum is updated.

## Performance Analysis

- Evaluate and compare the performance of the three methods by measuring total time, user time, and system time for different input configurations.
- Investigate the impact of the number of threads on the overall execution time.

## Time Command and Output

- Execute the program using the Linux `time` command to obtain detailed information about the execution time, including user time, system time, and total time.

## Documentation

- Provide a comprehensive README file with instructions on compiling, executing, and interpreting the program results.
- Answer specific questions regarding correctness, speed, and the influence of the number of threads on performance.

In summary, the project aims to showcase the effectiveness of different synchronization methods in a multithreaded program and analyze their impact on overall performance under various input configurations and thread counts.
