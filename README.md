# My Performance Tests of Eigen

## Eigen vs handcrafted code (`eigen_unittest.cpp`)

Compare eigen with traditional way of calculating large amount of standard deviation

| Test                       | Ryzen 4600G |
| -------------------------- | ----------- |
| calcEigenCasualFloat       | 0.919s      |
| calcEigenCasualDouble      | 1.767s      |
| calcEigenSinFloat          | 1.553s      |
| calcTranditionalSinFloat   | 2.383s      |
| calcEigenSinDouble         | 6.097s      |
| calcTranditionalSinDouble  | 6.153s      |
| calcEigenSqrtFloat         | 0.317s      |
| calcTranditionalSqrtFloat  | 1.323s      |
| calcEigenSqrtDouble        | 1.035s      |
| calcTranditionalSqrtDouble | 2.14s       |
| **PerformanceTest**        | **23.688s** |
| cmpLessFloatFloat          | 0.952s      |
| cmpLessFloatDouble         | 2.076s      |
| cmpLessDoubleDouble        | 2.091s      |
| cmpLessDoubleFloat         | 2.005s      |
| **ComparisonTest**         | **7.124s**  |
| eigen                      | 0.132s      |
| traditional                | 0.817s      |
| **ZeroDetectTest**         | **0.949s**  |
