# Float Performance Tests

This project contains some tests of float point arithmetic and comparison.

Some tests uses [Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page) library.

| Test                | Ryzen 4600G |
| ------------------- | ----------- |
| **EigenMatrix**     | **2.702s**  |
| float               | 1.266s      |
| double              | 1.436s      |
| **FloatArithmetic** | **21.867s** |
| floatSin            | 2.293s      |
| floatSinEigen       | 1.627s      |
| doubleSin           | 6.485s      |
| doubleSinEigen      | 6.629s      |
| floatSqrt           | 1.336s      |
| floatSqrtEigen      | 0.331s      |
| doubleSqrt          | 2.141s      |
| doubleSqrtEigen     | 1.025s      |
| **FloatComparison** | **5.834s**  |
| float2float         | 1.947s      |
| float2double        | 1.947s      |
| double2double       | 1.94s       |
| **StdDev**          | **2.84s**   |
| eigen               | 0.369s      |
| traditional         | 2.471s      |
