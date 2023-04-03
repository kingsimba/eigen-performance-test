#include <gtest/gtest.h>
#include <Eigen/Dense>

namespace
{

#define SAMPLE_COUNT 100000

static float g_floatData[SAMPLE_COUNT];
static double g_doubleData[SAMPLE_COUNT];

} // namespace

class FloatTest : public ::testing::Test
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

TEST_F(FloatTest, floatSin)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        for (auto& d : g_floatData)
        {
            d = sinf(d);
        }
    }
}

TEST_F(FloatTest, floatSinEigen)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        auto data = Eigen::ArrayXf::Map(g_floatData, SAMPLE_COUNT);
        data = data.sin();
    }
}

TEST_F(FloatTest, doubleSin)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        for (auto& d : g_doubleData)
        {
            d = sin(d);
        }
    }
}

TEST_F(FloatTest, doubleSinEigen)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        auto data = Eigen::ArrayXd::Map(g_doubleData, SAMPLE_COUNT);
        data = data.sin();
    }
}

TEST_F(FloatTest, floatSqrt)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        for (auto& d : g_floatData)
        {
            d = sqrtf(d);
        }
    }
}

TEST_F(FloatTest, floatSqrtEigen)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        auto data = Eigen::ArrayXf::Map(g_floatData, SAMPLE_COUNT);
        data = data.sqrt();
    }
}

TEST_F(FloatTest, doubleSqrt)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        for (auto& d : g_doubleData)
        {
            d = sqrt(d);
        }
    }
}

TEST_F(FloatTest, doubleSqrtEigen)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        auto data = Eigen::ArrayXd::Map(g_doubleData, SAMPLE_COUNT);
        data = data.sqrt();
    }
}
