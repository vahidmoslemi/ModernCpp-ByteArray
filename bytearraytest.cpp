#include "bytearraytest.h"

TEST_F(ByteArrayTest, DefaultEmpty) {
    ByteArray data;
    EXPECT_EQ(data.getSize(), 0);
    EXPECT_EQ(data.data(), nullptr);
}

TEST_F(ByteArrayTest, ConstCStrConstructor) {
    ByteArray data{"12345678"};
    EXPECT_EQ(data.getSize(), 8);
    EXPECT_EQ(data.data()[7], '8');
    EXPECT_EQ(data.data()[0], '1');
    EXPECT_EQ(data.data()[8], '\0');
}

TEST_F(ByteArrayTest, RValueConstructor) {
    ByteArray data{ByteArray{"12345678"}};
    EXPECT_EQ(data.getSize(), 8);
    EXPECT_EQ(data.data()[7], '8');
    EXPECT_EQ(data.data()[0], '1');
    EXPECT_EQ(data.data()[8], '\0');
}

TEST_F(ByteArrayTest, SizeConstructor) {
    ByteArray data(10);
    EXPECT_EQ(data.getSize(), 10);
    //Default value is zero
    EXPECT_EQ(data.data()[9], 0);
    EXPECT_EQ(data.data()[0], 0);
    EXPECT_EQ(data.data()[10], '\0');
}


TEST_F(ByteArrayTest, CStrCostructorAndDestructor) {
    char* cstr = new char(5);
    memset(cstr,'1',4);
    cstr[4]='\0';
    {
        try {
            ByteArray data(cstr,4);
            cstr=nullptr;
            EXPECT_EQ(data.getSize(), 4);
            EXPECT_EQ(data.data()[3], '1');
            EXPECT_EQ(data.data()[0], '1');
        } catch (...) {
            std::cout<<"Invalid Constructor argument";
            exit(0)   ;
        }
    }
}

TEST_F(ByteArrayTest, CopyConstructor) {
    ByteArray data{ba1};
    EXPECT_EQ(data.getSize(), 8);
    EXPECT_EQ(data.data()[7], '8');
    EXPECT_EQ(data.data()[0], '1');
}

TEST_F(ByteArrayTest, CopyAssignment){
    ba2 = ba1;
    EXPECT_EQ(ba2.getSize(), 8);
    EXPECT_EQ(ba2.data()[7], '8');
    EXPECT_EQ(ba2.data()[0], '1');
}

TEST_F(ByteArrayTest, MoveAssignment){
    ba2 = ByteArray{"MyData"};
    EXPECT_EQ(ba2.getSize(), 6);
    EXPECT_EQ(ba2.data()[5], 'a');
    EXPECT_EQ(ba2.data()[0], 'M');
}

TEST_F(ByteArrayTest, SetCStrData){
    char* cstr = new char(5);
    memset(cstr,'1',4);
    cstr[4]='\0';
    ba1.setData(cstr,4);
    cstr = nullptr;

    EXPECT_EQ(ba1.getSize(), 4);
    EXPECT_EQ(ba1.data()[3], '1');
    EXPECT_EQ(ba1.data()[0], '1');
}

TEST_F(ByteArrayTest, SetConstCStrData){
    ba1.setData("abcd",4);
    EXPECT_EQ(ba1.getSize(), 4);
    EXPECT_EQ(ba1.data()[3], 'd');
    EXPECT_EQ(ba1.data()[0], 'a');
}

TEST_F(ByteArrayTest, EqualityOperator){
    ByteArray data{ba1};
    EXPECT_EQ(ba1==ba2, false);
    EXPECT_EQ(ba1==data, true);

    data = "Hello";
    EXPECT_EQ(ba2==data, true);
}

TEST_F(ByteArrayTest, ConcatOperator){
    ByteArray data = ba1+ba2;
    EXPECT_EQ(data=="12345678Hello", true);
}

TEST_F(ByteArrayTest, Split){
    auto part2_value = datastream.split(',')[1].split(':')[1];
    EXPECT_EQ(part2_value=="val2", true);
}

TEST_F(ByteArrayTest, Release){
    auto data = ba2.release();
    EXPECT_EQ(ba2.getSize(),0);
    EXPECT_EQ(ba2.data(),nullptr);
    EXPECT_EQ(data[0]=='H',true);
    EXPECT_EQ(data[4]=='o',true);
    EXPECT_EQ(strlen(data)==5,true);
}

TEST_F(ByteArrayTest, Mid){
    auto right_section = ba1.mid(0,4);
    EXPECT_EQ(right_section.getSize(), 4);
    EXPECT_EQ(right_section.data()[3], '4');
    EXPECT_EQ(right_section.data()[0], '1');
}

TEST_F(ByteArrayTest, StdStringConstructor){
    std::string mydata="mydata";
    ByteArray data(mydata);
    EXPECT_EQ(mydata.data()[0]=='m',true);
    EXPECT_EQ(mydata.data()[4]=='t',true);
}

TEST_F(ByteArrayTest, IndexOperator){
    std::string mydata="mydata";
    ByteArray data(mydata);
    EXPECT_EQ(mydata[0]=='m',true);
    mydata[5]='1';
    EXPECT_EQ(mydata.data()[5]=='1',true);
}
