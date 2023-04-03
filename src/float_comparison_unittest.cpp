#include <gtest/gtest.h>
#include <random>
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
        std::random_device rd;
        std::mt19937 e2(rd());

        std::uniform_real_distribution<> dist(0, 10);

        for (size_t i = 0; i < SAMPLE_COUNT; i++)
        {
            g_floatData[i] = dist(e2);
        }
        for (size_t i = 0; i < SAMPLE_COUNT; i++)
        {
            g_doubleData[i] = dist(e2);
        }
    }

    void SetUp() { g_result = false; }

    void TearDown() { printf("%d", g_result); }
};

#define REPEAT 10000

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
