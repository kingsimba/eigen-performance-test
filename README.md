# Float Performance Tests

This project contains some tests of float point arithmetic and comparison.

Some tests uses [Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page) library.

| Test                | Ryzen 4600G |
| ------------------- | ----------- |
| float               | 1.11s       |
| double              | 2.035s      |
| **EigenMatrix**     | **3.145s**  |
| float2float         | 1.939s      |
| float2double        | 1.957s      |
| double2double       | 1.95s       |
| **FloatComparison** | **5.846s**  |
| floatSin            | 2.205s      |
| floatSinEigen       | 1.554s      |
| doubleSin           | 6.601s      |
| doubleSinEigen      | 6.664s      |
| floatSqrt           | 1.337s      |
| floatSqrtEigen      | 0.307s      |
| doubleSqrt          | 2.143s      |
| doubleSqrtEigen     | 1.032s      |
| **FloatTest**       | **21.843s** |
| traditional         | 2.472s      |
| eigen               | 0.394s      |
| **StdDev**          | **2.866s**  |
