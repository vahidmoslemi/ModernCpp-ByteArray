# ModernCpp-ByteArray
ByteArray implementaion is very frequently needed in embedded device software development and data manipulator applications.
In such cases you could concern memory leaks, passing parameters to functions and return output from them, and so on.
Also when you work with other Framesworks to handle some requested features (UI/etc).

Like my faviorate one (Qt) you should be able to handle Qt DataTypes (QString/QByteArray) in your pure C++ logic code section.

## Structure
To do so I have developed a pure modern C++ ByteArray data type based on char array and have tested in Linux and Android projects.
At the time it supports construction based on char*, const char* and also move and copy constructors(ByteArray& and ByeArray&&).
I have implemented move constructor and assignment operator to boost run-time performance.

Additionally to the above methods mid, split and concatinating multiple ByteArrays are possible using overloaded + operator.

### Currently suppored methods:
```
mid :     	to get a sub-ByteArray from the original (based on copy).
split:    	split ByteArray to a vector of ByteArrays based on given delimiter.
data:     	get data as const char*.
release:  	release data and return pointer to the stored char array.
getSize:  	get size of the data inside ByteArray object.
operator+:	concatinate multiple ByteArrays
operator==	check equality of 2 ByteArrays
```
Note: actual char array inside a ByteArray is null terminated to avoid undefined behavior.


## Usage
Simply copy files into you project and include "bytearray.h"

```cpp
#include "bytearray.h"
#include <iostream>

int main(){
  ByteArray datastream = "prop1:val1,prop2:val2,prop3:val3";
  auto data_parts = datastream.split(',');
  std::cout<<"prop1 : "<<data_parts[0].split(':')[1].data()<<std::endl;
  
  ByteArray concat = data_parts[0] + "|" + data_parts[2];
  std::cout<<"new data stream:  "<<concat.data()<<std::endl;
  
  auto test = data_parts[0];
  if(test==data_parts[0])
	  std::cout<<"EQUAL"<<std::endl;
  else
	  std::cout<<"NOT EQUAL"<<std::endl;
  
  if(test=="prop1:val2")
	  std::cout<<"EQUAL"<<std::endl;
  else
	  std::cout<<"NOT EQUAL"<<std::endl;
  
  return 0;
} 

```

## Build Sample Code
```sh
g++ bytearray.cpp main.cpp -o test && ./test
```
