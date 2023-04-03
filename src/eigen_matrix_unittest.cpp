#include <gtest/gtest.h>
#include <Eigen/Dense>
#include <random>

namespace
{

struct MatrixFloat
{
    float m[16];
};

struct MatrixDouble
{
    double m[16];
};

#define SAMPLE_COUNT 10000

MatrixFloat g_floatData[SAMPLE_COUNT];
MatrixDouble g_doubleData[SAMPLE_COUNT];

float g_floatResult = 0;
float g_doubleResult = 0;

} // namespace

class EigenMatrix : public ::testing::Test
{
public:
    static void SetUpTestCase()
    {
        std::random_device rd;
        std::mt19937 e2(rd());

        std::uniform_real_distribution<> dist(0, 10);

        for (size_t i = 0; i < SAMPLE_COUNT; i++)
        {
            for (size_t j = 0; j < 16; j++)
            {
                g_floatData[i].m[j] = dist(e2);
            }
        }
        for (size_t i = 0; i < SAMPLE_COUNT; i++)
        {
            for (size_t j = 0; j < 16; j++)
            {
                g_doubleData[i].m[j] = dist(e2);
            }
        }
    }

    static void TearDownTestCase() { printf("%f %f\n", g_floatResult, g_doubleResult); }
};

#define REPEAT 6000
TEST_F(EigenMatrix, float)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        for (size_t j = 0; j < SAMPLE_COUNT; j++)
        {
            auto dataMatrix = Eigen::Matrix4f::Map(&g_floatData[j].m[0], 4, 4);
            Eigen::Matrix4f quart = dataMatrix.adjoint() * dataMatrix;
            g_floatResult += quart.inverse().sum();
        }
    }
}

TEST_F(EigenMatrix, double)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        for (size_t j = 0; j < SAMPLE_COUNT; j++)
        {
            auto dataMatrix = Eigen::Matrix4d::Map(&g_doubleData[j].m[0], 4, 4);
            Eigen::Matrix4d quart = dataMatrix.adjoint() * dataMatrix;
            g_doubleResult += quart.inverse().sum();
        }
    }
}
