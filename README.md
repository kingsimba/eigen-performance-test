# Float Performance Tests

This project contains some tests of float point arithmetic and comparison.

Some tests use [Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page) library.

| Test                | Ryzen 4600G | Pi model 4B | Orange Pi   |    RK3588S* |     RK3588* |
| ------------------- | ----------- | ----------- | ----------- | ----------- | ----------- |
| **EigenMatrix**     | **2.702s**  | **23.936s** | **20.478s** |  **9.074s** |  **8.673s** |
| float               | 1.266s      | 7.996s      | 6.719s      |      3.846s |      3.671s |
| double              | 1.436s      | 15.939s     | 13.759s     |      5.228s |      5.002s |
| **FloatArithmetic** | **21.867s** | **106.64s** | **87.289s** | **36.366s** | **34.899s** |
| floatSin            | 2.293s      | 12.525s     | 8.978s      |      6.029s |      5.774s |
| floatSinEigen       | 1.627s      | 10.687s     | 7.895s      |      5.577s |      5.356s |
| doubleSin           | 6.485s      | 26.205s     | 22.153s     |      9.803s |      9.396s |
| doubleSinEigen      | 6.629s      | 26.222s     | 21.965s     |      8.534s |      8.203s |
| floatSqrt           | 1.336s      | 3.575s      | 3.126s      |      0.993s |      0.954s |
| floatSqrtEigen      | 0.331s      | 3.572s      | 3.126s      |      0.993s |      0.952s |
| doubleSqrt          | 2.141s      | 11.909s     | 10.024s     |      2.219s |      2.132s |
| doubleSqrtEigen     | 1.025s      | 11.945s     | 10.022s     |      2.218s |      2.131s |
| **FloatComparison** | **5.834s**  | **16.063s** | **13.396s** |  **8.146s** |  **7.828s** |
| float2float         | 1.947s      | 5.179s      | 4.29s       |       2.71s |      2.608s |
| float2double        | 1.947s      | 5.26s       | 4.51s       |      2.736s |      2.627s |
| double2double       | 1.94s       | 5.624s      | 4.596s      |        2.7s |      2.593s |
| **StdDev**          | **2.84s**   | **10.934s** | **8.811s**  |  **4.248s** |  **4.076s** |
| eigen               | 0.369s      | 3.563s      | 2.662s      |      1.014s |       0.97s |
| traditional         | 2.471s      | 7.371s      | 6.149s      |      3.234s |      3.106s |

* RK3588S are tested on Orange Pi CM5
* RK3588 are tested on Orange Pi Plus 5
