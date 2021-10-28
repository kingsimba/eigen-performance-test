#include <gtest/gtest.h>
#include <Eigen/Dense>

namespace
{

#define SAMPLE_COUNT 100000

static float g_floatData[SAMPLE_COUNT];
static double g_doubleData[SAMPLE_COUNT];

} // namespace

class ComparisonTest : public ::testing::Test
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
};

#define REPEAT 300000

TEST_F(ComparisonTest, cmpLessFloatFloat)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        for (int idx = 0; idx < SAMPLE_COUNT; ++idx)
        {
            g_floatData[idx] = g_floatData[idx] < 100.0f;
        }
    }
}

TEST_F(ComparisonTest, cmpLessFloatDouble)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        for (int idx = 0; idx < SAMPLE_COUNT; ++idx)
        {
            g_doubleData[idx] = g_doubleData[idx] < 100.0;
        }
    }
}

TEST_F(ComparisonTest, cmpLessDoubleDouble)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        for (int idx = 0; idx < SAMPLE_COUNT; ++idx)
        {
            g_doubleData[idx] = g_doubleData[idx] < 100.0;
        }
    }
}

TEST_F(ComparisonTest, cmpLessDoubleFloat)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        for (int idx = 0; idx < SAMPLE_COUNT; ++idx)
        {
            g_doubleData[idx] = g_doubleData[idx] < 100.0f;
        }
    }
}
