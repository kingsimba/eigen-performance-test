# Float Performance Tests

This project contains some tests of float point arithmetic and comparison.

Some tests use [Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page) library.

| Test                | Ryzen 4600G | Pi model 4B |
| ------------------- | ----------- | ----------- |
| **EigenMatrix**     | **2.702s**  | **23.936s** |
| float               | 1.266s      | 7.996s      |
| double              | 1.436s      | 15.939s     |
| **FloatArithmetic** | **21.867s** | **106.64s** |
| floatSin            | 2.293s      | 12.525s     |
| floatSinEigen       | 1.627s      | 10.687s     |
| doubleSin           | 6.485s      | 26.205s     |
| doubleSinEigen      | 6.629s      | 26.222s     |
| floatSqrt           | 1.336s      | 3.575s      |
| floatSqrtEigen      | 0.331s      | 3.572s      |
| doubleSqrt          | 2.141s      | 11.909s     |
| doubleSqrtEigen     | 1.025s      | 11.945s     |
| **FloatComparison** | **5.834s**  | **16.063s** |
| float2float         | 1.947s      | 5.179s      |
| float2double        | 1.947s      | 5.26s       |
| double2double       | 1.94s       | 5.624s      |
| **StdDev**          | **2.84s**   | **10.934s** |
| eigen               | 0.369s      | 3.563s      |
| traditional         | 2.471s      | 7.371s      |
