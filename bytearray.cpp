#include "bytearray.h"
#include <cstring>
#include <memory>

ByteArray::ByteArray()
{
    m_data_size = 0;
    m_data = nullptr;
}

ByteArray::ByteArray(ByteArray& other)
{
    m_data_size = other.m_data_size;
    m_data = new char [m_data_size+1]; //null terminated
    m_data[m_data_size]='\0';
    std::copy(other.m_data,other.m_data+other.m_data_size,m_data);
}

ByteArray::ByteArray(ByteArray&& other)
{
    m_data_size = other.m_data_size + 1;
    m_data = other.m_data;
    m_data[m_data_size]='\0';
    other.m_data = nullptr;
    other.m_data_size = 0;
}

ByteArray::ByteArray(unsigned long t_data_size){
    m_data_size = t_data_size;
    m_data = new char[m_data_size + 1];
    m_data[m_data_size]='\0';
}

ByteArray::ByteArray(const char* t_data) : m_data_size{strlen(t_data)}
{
    m_data = new char [m_data_size + 1];
    std::copy(t_data,t_data+m_data_size,m_data);
    m_data[m_data_size]='\0';
}

ByteArray::ByteArray(char* t_data,unsigned long t_data_size) : m_data_size{t_data_size}
{
    m_data = t_data;
}

ByteArray::~ByteArray()
{
    delete [] m_data;
    m_data = nullptr;
    m_data_size = 0;
}


//Copy Assignment Operator
ByteArray& ByteArray::operator=(const ByteArray&  other)
{
    //avoid self copy
    if(this!=&other)
    {
        delete[] m_data;
        m_data=nullptr;
        m_data_size = other.m_data_size;
        m_data = new char[m_data_size + 1];
        std::copy(other.m_data,other.m_data + m_data_size,m_data);
        m_data[m_data_size]='\0';
    }
    return *this;
}

//Move Assignment Operator
ByteArray& ByteArray::operator=(ByteArray&&  other)
{
    //avoid self copy
    if(this!=&other)
    {
        delete[] m_data;
        m_data_size = other.m_data_size;
        m_data = other.m_data;
        other.m_data = nullptr;
        other.m_data_size = 0;
    }
    return *this;
}

void ByteArray::setData(const char* t_data, unsigned long t_data_size)
{
    delete[] m_data;
    m_data_size = t_data_size;
    m_data=new char[m_data_size + 1];
    std::copy(t_data,t_data + m_data_size, m_data);
    m_data[m_data_size]='\0';
}

void ByteArray::setData(char* t_data, unsigned long t_data_size)
{
    delete[] m_data;
    m_data_size = t_data_size;
    m_data = t_data;
}

std::vector<ByteArray> ByteArray::splite(char delimiter)
{
    std::vector<ByteArray> result;
    unsigned long from=0;
    for(unsigned long i=0; i<m_data_size;i++)
    {
        if(m_data[i]==delimiter)
        {
            if(i>from)
                result.push_back(this->mid(from,i-from));

            from = i+1;
        }
    }
    //if delimiter not found
    if(from==0)
    {
        result.push_back(ByteArray{this->data()});
    }
    return result;
}
