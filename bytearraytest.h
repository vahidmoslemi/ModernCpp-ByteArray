#ifndef BYTEARRAYTEST_H
#define BYTEARRAYTEST_H

#include "bytearray.h"
#include <iostream>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

class ByteArrayTest : public ::testing::Test
{
protected:
    void SetUp() override{
        ba1.setData("12345678",8);
    }
//    void TearDown() override;

    ByteArray ba1;
    ByteArray ba2{"Hello"};
    ByteArray datastream {"prop1:val1,prop2:val2,prop3:val3"};
};

#endif // BYTEARRAYTEST_H
