#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace ::testing;

class job
{
public:
    virtual ~job() = default;
    virtual void tick() = 0;
};

class job_mock : public job
{
public:
    MOCK_METHOD(void, tick, (), (override));
};

TEST(HelloMock, Basic)
{
    NiceMock<job_mock> obj;

    EXPECT_CALL(obj, tick()).Times(1);
    obj.tick();
}
