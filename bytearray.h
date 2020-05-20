/*
 * Pure modern C++ ByteArray type implemented as a wrapper over char*
 * Supports move semantics to provide good performance in daily usage
 * actual data inside a ByteArray is a null terminated char array
 * m_data_length holds the actual length == strlen(m_data)
 *
 * Written in 2020 by Vahid Moslemi Vayeghan
 *
 * Hope this type help many developers in daily use projects to pass and
 * return char* values in a safe and simple manner
 */

#ifndef BYTEARRAY_H
#define BYTEARRAY_H

#include<vector>

class ByteArray
{
public:
    //construct as empty, by data_length or by const value
    ByteArray();
    /**
     * @brief ByteArray : copy constructor
     */
    ByteArray(ByteArray&);

    /**
     * @brief ByteArray : Move Constructor
     */
    ByteArray(ByteArray&&);
    explicit ByteArray(unsigned long t_data_size);
    ByteArray(const char* t_data);
    explicit ByteArray(char* t_data,unsigned long t_data_size);
    ~ByteArray();

    /**
     * @brief operator =  Copy Assignment Operator
     * @param other
     * @return
     */
    ByteArray& operator=(const ByteArray&  other);

    /**
     * @brief operator +
     * @param other
     * @return
     */
    ByteArray operator+(const ByteArray &other);

    /**
     * @brief operator = Move Assignment Operator
     * @param other
     * @return
     */
    ByteArray& operator=(ByteArray&&  other);

	bool operator==(ByteArray&  other);
	bool operator==(const ByteArray&  other);
	
    /**
     * @brief setData : copy data into the ByteArray
     * @param t_data
     * @param t_data_size
     */
    void setData(const char* t_data, unsigned long t_data_size);

    /**
     * @brief setData : move data into the ByteArray. data will be controlled by ByteArray from now on
     * @param t_data
     * @param t_data_size
     */
    void setData(char* t_data, unsigned long t_data_size);

    /**
     * @brief release : release data control and return data pointer to new holder
     *                  it would be better to first getting data size using getSize methods
     *                  before invoking release method
     * @return
     */
    char* release(){
        char* tmp = m_data;
        m_data = nullptr;
        m_data_size = 0;
        return tmp;
    }

    /**
     * @brief release : release data control and return data pointer to new holder
     *                  it would be better to first getting data size using getSize methods
     *                  before invoking release method
     * @return
     */
    const char* data() const{
        return m_data;
    }

    /**
     * @brief getSize : returns size of the char array which holds data
     * @return
     */
    unsigned long getSize() const { return m_data_size;}

    ByteArray mid(unsigned long from,unsigned long len) const
    {
        ByteArray result(len);
        std::copy(m_data+from,m_data+from+len,result.m_data);
        return  result;
    }

    std::vector<ByteArray> split(char delimiter) const;

private:
    unsigned long m_data_size;
    char* m_data;
};

#endif // BYTEARRAY_H
