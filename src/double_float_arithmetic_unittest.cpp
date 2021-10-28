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
};

#define REPEAT 10000
TEST_F(PerformanceTest, calcEigenSinFloat)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        auto data = Eigen::ArrayXf::Map(g_floatData, SAMPLE_COUNT);
        data = data.sin();
    }
}

TEST_F(PerformanceTest, calcTranditionalSinFloat)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        for (auto& d : g_floatData)
        {
            d = sinf(d);
        }
    }
}

TEST_F(PerformanceTest, calcEigenSinDouble)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        auto data = Eigen::ArrayXd::Map(g_doubleData, SAMPLE_COUNT);
        data = data.sin();
    }
}

TEST_F(PerformanceTest, calcTranditionalSinDouble)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        for (auto& d : g_doubleData)
        {
            d = sin(d);
        }
    }
}

TEST_F(PerformanceTest, calcEigenSqrtFloat)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        auto data = Eigen::ArrayXf::Map(g_floatData, SAMPLE_COUNT);
        data = data.sqrt();
    }
}

TEST_F(PerformanceTest, calcTranditionalSqrtFloat)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        for (auto& d : g_floatData)
        {
            d = sqrtf(d);
        }
    }
}

TEST_F(PerformanceTest, calcEigenSqrtDouble)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        auto data = Eigen::ArrayXd::Map(g_doubleData, SAMPLE_COUNT);
        data = data.sqrt();
    }
}

TEST_F(PerformanceTest, calcTranditionalSqrtDouble)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        for (auto& d : g_doubleData)
        {
            d = sqrt(d);
        }
    }
}
