#include <gtest/gtest.h>
#include <Eigen/Dense>

namespace
{

#define SAMPLE_COUNT 100000

static float g_floatData[SAMPLE_COUNT];
static double g_doubleData[SAMPLE_COUNT];

} // namespace

class FloatArithmetic : public ::testing::Test
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

TEST_F(FloatArithmetic, floatSin)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        for (auto& d : g_floatData)
        {
            d = sinf(d);
        }
    }
}

TEST_F(FloatArithmetic, floatSinEigen)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        auto data = Eigen::ArrayXf::Map(g_floatData, SAMPLE_COUNT);
        data = data.sin();
    }
}

TEST_F(FloatArithmetic, doubleSin)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        for (auto& d : g_doubleData)
        {
            d = sin(d);
        }
    }
}

TEST_F(FloatArithmetic, doubleSinEigen)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        auto data = Eigen::ArrayXd::Map(g_doubleData, SAMPLE_COUNT);
        data = data.sin();
    }
}

TEST_F(FloatArithmetic, floatSqrt)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        for (auto& d : g_floatData)
        {
            d = sqrtf(d);
        }
    }
}

TEST_F(FloatArithmetic, floatSqrtEigen)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        auto data = Eigen::ArrayXf::Map(g_floatData, SAMPLE_COUNT);
        data = data.sqrt();
    }
}

TEST_F(FloatArithmetic, doubleSqrt)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        for (auto& d : g_doubleData)
        {
            d = sqrt(d);
        }
    }
}

TEST_F(FloatArithmetic, doubleSqrtEigen)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        auto data = Eigen::ArrayXd::Map(g_doubleData, SAMPLE_COUNT);
        data = data.sqrt();
    }
}
