// Compare eigen with traditional way of calculating large amount of standard
// deviation

#include <Eigen/Dense>
#include <gtest/gtest.h>
#include "types.h"

namespace
{

struct Data
{
    float ax, ay, az;
    float gx, gy, gz;
};

#define SAMPLE_COUNT 200
#define OUTPUT_COUNT 100
#define STRIDE (sizeof(Data) / sizeof(float))

static Data g_inputData[SAMPLE_COUNT];
static Data g_outputData[OUTPUT_COUNT];

} // namespace

class ZeroDetectTest : public ::testing::Test
{
public:
    static void SetUpTestCase()
    {
        for (size_t i = 0; i < countof(g_inputData); i++)
        {
            Data& d = g_inputData[i];
            d.ax = (rand() + 1) * 0.0001f;
            d.ay = (rand() + 1) * 0.0001f;
            d.az = (rand() + 1) * 0.0001f;
            d.gx = (rand() + 1) * 0.0001f;
            d.gy = (rand() + 1) * 0.0001f;
            d.gz = (rand() + 1) * 0.0001f;
        }
    }

    void TearDown()
    {
        std::cout << "g_outputData[0]: " << g_outputData[0].ax << ", " << g_outputData[0].ay << ", "
                  << g_outputData[0].az << std::endl;
    }

    void calcStdvEigen()
    {
        auto dataMatrix = Eigen::MatrixXf::Map((float*)g_inputData, 6, SAMPLE_COUNT);
        Eigen::MatrixXf ag_mean = Eigen::MatrixXf::Zero(6, OUTPUT_COUNT);
        for (size_t idx = 0; idx < OUTPUT_COUNT; ++idx)
        {
            ag_mean += dataMatrix.middleCols(idx, OUTPUT_COUNT);
        }
        ag_mean /= static_cast<float>(OUTPUT_COUNT);
        auto agStdv = Eigen::ArrayXXf::Map((float*)g_outputData, 6, OUTPUT_COUNT);
        agStdv.setZero();
        for (size_t idx = 0; idx < OUTPUT_COUNT; ++idx)
        {
            agStdv += (dataMatrix.middleCols(idx, OUTPUT_COUNT) - ag_mean).array().square();
        }
        agStdv /= static_cast<float>(OUTPUT_COUNT);
        agStdv = agStdv.sqrt();
    }

    void calcStdvTraditional()
    {
        for (size_t i = 0; i < countof(g_outputData); i++)
        {
            Data& output = g_outputData[i];
            output.ax = _calculateStdv(&g_inputData[i].ax, OUTPUT_COUNT);
            output.ay = _calculateStdv(&g_inputData[i].ay, OUTPUT_COUNT);
            output.az = _calculateStdv(&g_inputData[i].az, OUTPUT_COUNT);
            output.gx = _calculateStdv(&g_inputData[i].gx, OUTPUT_COUNT);
            output.gy = _calculateStdv(&g_inputData[i].gy, OUTPUT_COUNT);
            output.gz = _calculateStdv(&g_inputData[i].gz, OUTPUT_COUNT);
        }
    }

    float _calculateStdv(float* start, int sampleCount)
    {
        float sum = 0;
        float* end = start + sampleCount * STRIDE;
        for (float* p = start; p < end; p += STRIDE)
        {
            sum += *p;
        }

        float avg = sum / sampleCount;
        float squareSum = 0;
        for (float* p = start; p < end; p += STRIDE)
        {
            float diff = *p - avg;
            squareSum += diff * diff;
        }
        float squareAvg = squareSum / sampleCount;
        return sqrtf(squareAvg);
    }
};

#define REPEAT 10000

TEST_F(ZeroDetectTest, eigen)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        calcStdvEigen();
    }
}

TEST_F(ZeroDetectTest, traditional)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        calcStdvTraditional();
    }
}