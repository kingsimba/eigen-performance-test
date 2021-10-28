# Tests for understanding the performance of float vs double, or Eigen vs handcrafted code

## `eigen_unittest.cpp`

Compare eigen with traditional way of calculating large amount of standard deviation

```
Result (Raspberry PI model 4B - Compiled with GCC 8.3 with -O3):
Eigen: 1071 ms
Traditional: 2464 ms

Result (AMD Ryzen 5 4600G - Compiled with clang 13.0.0 with -O3):
Eigen: 129 ms
Traditional: 777 ms

Result (AMD Ryzen 5 4600G - Compiled with clang 13.0.0 without -O3):
Eigen: 8750 ms (without optimization, Eigen is unbearably slow)
Traditional: 3201 ms
```
