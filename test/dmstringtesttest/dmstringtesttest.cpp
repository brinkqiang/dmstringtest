
#include "dmstringtest.h"
#include "gtest.h"

class env_dmstringtest
{
public:
    void init(){}
    void uninit(){}
};

class frame_dmstringtest : public testing::Test
{
public:
    virtual void SetUp()
    {
        env.init();
    }
    virtual void TearDown()
    {
        env.uninit();
    }
protected:
    env_dmstringtest env;
};

TEST_F(frame_dmstringtest, init)
{
    Idmstringtest* module = dmstringtestGetModule();
    if (module)
    {
        module->Test();
        module->Release();
    }
}
