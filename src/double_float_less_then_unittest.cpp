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
            g_floatData[i] = (rand() + 1) * 0.0001f;
        }
        for (size_t i = 0; i < SAMPLE_COUNT; i++)
        {
            g_doubleData[i] = (rand() + 1) * 0.0001f;
        }
    }


    void cmpLessFloatFloat(){
        for(int idx = 0; idx < SAMPLE_COUNT; ++idx){
            g_floatData[idx] = g_floatData[idx] < 100.0f;
        }
    }
    void cmpLessFloatDouble(){
        for(int idx = 0; idx < SAMPLE_COUNT; ++idx){
            g_doubleData[idx] = g_doubleData[idx] < 100.0;
        }
    }

    void cmpLessDoubleDouble(){
        for(int idx = 0; idx < SAMPLE_COUNT; ++idx){
            g_doubleData[idx] = g_doubleData[idx] < 100.0;
        }
    }
    void cmpLessDoubleFloat(){
        for(int idx = 0; idx < SAMPLE_COUNT; ++idx){
            g_doubleData[idx] = g_doubleData[idx] < 100.0f;
        }
    }

};

#define REPEAT 10000

TEST_F(PerformanceTest, cmpLessFloatFloat)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        cmpLessFloatFloat();
    }
}

TEST_F(PerformanceTest, cmpLessFloatDouble)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        cmpLessFloatDouble();
    }
}

TEST_F(PerformanceTest, cmpLessDoubleDouble)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        cmpLessDoubleDouble();
    }
}

TEST_F(PerformanceTest, cmpLessDoubleFloat)
{
    for (size_t i = REPEAT; i != 0; i--)
    {
        cmpLessDoubleFloat();
    }
}
