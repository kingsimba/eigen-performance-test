# Float Performance Tests

This project contains some tests of float point arithmetic and comparison.

Some tests use [Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page) library.

| Test                | Ryzen 4600G | Pi model 4B | Orange Pi   |
| ------------------- | ----------- | ----------- | ----------- |
| **EigenMatrix**     | **2.702s**  | **23.936s** | **20.478s** |
| float               | 1.266s      | 7.996s      | 6.719s      |
| double              | 1.436s      | 15.939s     | 13.759s     |
| **FloatArithmetic** | **21.867s** | **106.64s** | **87.289s** |
| floatSin            | 2.293s      | 12.525s     | 8.978s      |
| floatSinEigen       | 1.627s      | 10.687s     | 7.895s      |
| doubleSin           | 6.485s      | 26.205s     | 22.153s     |
| doubleSinEigen      | 6.629s      | 26.222s     | 21.965s     |
| floatSqrt           | 1.336s      | 3.575s      | 3.126s      |
| floatSqrtEigen      | 0.331s      | 3.572s      | 3.126s      |
| doubleSqrt          | 2.141s      | 11.909s     | 10.024s     |
| doubleSqrtEigen     | 1.025s      | 11.945s     | 10.022s     |
| **FloatComparison** | **5.834s**  | **16.063s** | **13.396s** |
| float2float         | 1.947s      | 5.179s      | 4.29s       |
| float2double        | 1.947s      | 5.26s       | 4.51s       |
| double2double       | 1.94s       | 5.624s      | 4.596s      |
| **StdDev**          | **2.84s**   | **10.934s** | **8.811s**  |
| eigen               | 0.369s      | 3.563s      | 2.662s      |
| traditional         | 2.471s      | 7.371s      | 6.149s      |
