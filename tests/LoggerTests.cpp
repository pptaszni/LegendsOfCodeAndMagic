/*
 * @author Pawel Ptasznik
 */

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Logger.hpp"

/*
 * Some dummy test for Logger, not really needed ...
 */
class LoggerShould: public ::testing::Test {
protected:
    LoggerShould(): sut_("LoggerShould") {}
    Logger sut_;
};

TEST_F(LoggerShould, logMessages)
{
    int numIterations = 10;
    for (int i = 0; i < numIterations; i++) {
        sut_.info("One two three");
        sut_.debug("Four five six");
    }
}
