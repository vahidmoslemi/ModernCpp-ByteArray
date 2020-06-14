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
    m_data_size = other.m_data_size;
    m_data = other.m_data;
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
    try {
        if(t_data_size<=0 || t_data[t_data_size]!='\0')
        {
            throw("Invalid cstr data given. ByteArray will be initialized as empty.");
        }
        m_data = t_data;

    } catch (const char* ex) {
        m_data=nullptr;
        m_data_size=0;
        throw(ex);
    }
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

std::vector<ByteArray> ByteArray::split(char delimiter) const
{
    std::vector<ByteArray> result;
    unsigned long from=0;
	unsigned long i=0;
    while(i<m_data_size)
    {
        if(m_data[i]==delimiter)
        {
            if(i>from)
                result.push_back(this->mid(from,i-from));

            from = i+1;
        }
        i++;
    }
    //if data is remained
    if(from<m_data_size)
    {
        result.push_back(this->mid(from,i-from));
    }
    return result;
}

ByteArray ByteArray::operator+( const ByteArray &other)
{
	//allocate storage to concatinated output
    ByteArray bytearray_cat(m_data_size+other.m_data_size);
	
	//copy first part
    std::copy(m_data,m_data + m_data_size, bytearray_cat.m_data);
	//copy second part
    std::copy(other.m_data,other.m_data + other.m_data_size, bytearray_cat.m_data+m_data_size);
	return bytearray_cat;
}

bool ByteArray::operator==(ByteArray&  other)
{
    bool result = (m_data_size==other.m_data_size);

    unsigned long int i=0;
    while(result && i<m_data_size)
    {
        result = (m_data[i]==other.m_data[i]);
		i++;
    }
    return result;
}


bool ByteArray::operator==(const ByteArray&  other)
{
    bool result = (m_data_size==other.m_data_size);

    unsigned long int i=0;
    while(result && i<m_data_size)
    {
        result = (m_data[i]==other.m_data[i]);
		i++;
    }
    return result;
}
