#include <gtest/gtest.h>
#include <Eigen/Dense>

namespace
{

#define SAMPLE_COUNT 10000

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
            g_floatData[i] = (rand() + 1) * 0.0001f;
        }
        for (size_t i = 0; i < SAMPLE_COUNT; i++)
        {
            g_doubleData[i] = (rand() + 1) * 0.0001f;
        }
    }
};

#define REPEAT 300
TEST_F(PerformanceTest, calcEigenCasualFloat)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        auto dataMatrix = Eigen::MatrixXf::Map(g_floatData, 6, SAMPLE_COUNT / 6);
        Eigen::MatrixXf quart = dataMatrix.adjoint() * dataMatrix;
        quart.inverse();
    }
}

TEST_F(PerformanceTest, calcEigenCasualDouble)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        auto dataMatrix = Eigen::MatrixXd::Map(g_doubleData, 6, SAMPLE_COUNT / 6);
        Eigen::MatrixXd quart = dataMatrix.adjoint() * dataMatrix;
        quart.inverse();
    }
}
