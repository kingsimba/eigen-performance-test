#include <gtest/gtest.h>
#include <Eigen/Dense>

namespace
{

#define SAMPLE_COUNT 100000

static float g_floatData[SAMPLE_COUNT];
static double g_doubleData[SAMPLE_COUNT];

} // namespace

class PerformanceTest : public ::testing::Test
{
public:
    static void SetUpTestCase()
    {
        for (size_t i = 0; i < SAMPLE_COUNT; i++)
        {
            g_floatData[i] = M_PIf32 * (float)i / 100.0f;
        }
        for (size_t i = 0; i < SAMPLE_COUNT; i++)
        {
            g_doubleData[i] = M_PI * (double)i / 100.0;
        }
    }


// eigen version
    void calcEigenSinFloat(){
        auto data = Eigen::ArrayXf::Map(g_floatData,SAMPLE_COUNT);
        data = data.sin();
    }

    void calcEigenSinDouble(){
        auto data = Eigen::ArrayXd::Map(g_doubleData,SAMPLE_COUNT);
        data = data.sin();
    }

    void calcEigenSqrtFloat(){
        auto data = Eigen::ArrayXf::Map(g_floatData,SAMPLE_COUNT);
        data = data.sqrt();
    }

    void calcEigenSqrtDouble(){
        auto data = Eigen::ArrayXd::Map(g_doubleData,SAMPLE_COUNT);
        data = data.sqrt();
    }

// Tranditional version
    void calcTranditionalSinFloat(){
        for(auto& d: g_floatData){
            d = sinf(d);
        }
    }

    void calcTranditionalSinDouble(){
        for(auto& d: g_doubleData){
            d = sin(d);
        }
    }

    void calcTranditionalSqrtFloat(){
        for(auto& d: g_floatData){
            d = sqrtf(d);
        }
    }

    void calcTranditionalSqrtDouble(){
        for(auto& d: g_doubleData){
            d = sqrt(d);
        }
    }
};

#define REPEAT 10
TEST_F(PerformanceTest, calcEigenSinFloat)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        calcEigenSinFloat();
    }
}

TEST_F(PerformanceTest, calcTranditionalSinFloat)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        calcTranditionalSinFloat();
    }
}



TEST_F(PerformanceTest, calcEigenSinDouble)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        calcEigenSinDouble();
    }
}

TEST_F(PerformanceTest, calcTranditionalSinDouble)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        calcTranditionalSinDouble();
    }
}

TEST_F(PerformanceTest, calcEigenSqrtFloat)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        calcEigenSqrtFloat();
    }
}

TEST_F(PerformanceTest, calcTranditionalSqrtFloat)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        calcTranditionalSqrtFloat();
    }
}

TEST_F(PerformanceTest, calcEigenSqrtDouble)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        calcEigenSqrtDouble();
    }
}

TEST_F(PerformanceTest, calcTranditionalSqrtDouble)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        calcTranditionalSqrtDouble();
    }
}
