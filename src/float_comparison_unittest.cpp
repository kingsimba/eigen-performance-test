#include <gtest/gtest.h>
#include <Eigen/Dense>

namespace
{

#define SAMPLE_COUNT 100000

static float g_floatData[SAMPLE_COUNT];
static double g_doubleData[SAMPLE_COUNT];

volatile bool g_result = false;

} // namespace

class FloatComparison : public ::testing::Test
{
public:
    static void SetUpTestCase()
    {
        for (size_t i = 0; i < SAMPLE_COUNT; i++)
        {
            g_floatData[i] = (rand() + 1) * 0.0001f;
        }
        for (size_t i = 0; i < SAMPLE_COUNT; i++)
        {
            g_doubleData[i] = (rand() + 1) * 0.0001f;
        }
    }

    void SetUp() { g_result = false; }

    void TearDown() { printf("%d", g_result); }
};

#define REPEAT 300000

TEST_F(FloatComparison, float2float)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        for (int idx = 1; idx < SAMPLE_COUNT; ++idx)
        {
            g_result ^= g_floatData[idx] < g_floatData[idx - 1];
        }
    }
}

TEST_F(FloatComparison, float2double)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        for (int idx = 1; idx < SAMPLE_COUNT; ++idx)
        {
            g_result ^= g_floatData[idx] < g_doubleData[idx - 1];
        }
    }
}

TEST_F(FloatComparison, double2double)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        for (int idx = 1; idx < SAMPLE_COUNT; ++idx)
        {
            g_result ^= g_doubleData[idx] < g_doubleData[idx - 1];
        }
    }
}
