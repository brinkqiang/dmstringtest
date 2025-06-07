
#include "dmstringtest.h"
#include "gtest.h"
#include "dmstring.hpp"

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

TEST_F(frame_dmstringtest, SplitBySingleChar) {
    std::string to_split = "apple,banana,cherry";
    std::vector<std::string> expected = {"apple", "banana", "cherry"};
    std::vector<std::string> result = dmstring::split(to_split, ",");
    ASSERT_EQ(result, expected);
}