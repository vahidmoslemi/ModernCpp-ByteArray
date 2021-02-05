# ModernCpp-ByteArray
ByteArray implementaion is very frequently needed in embedded device software development and data manipulator applications.
In such cases you could concern memory leaks, passing parameters to functions and return output from them, and so on,
Specially when you work with other Framesworks to handle some requested features (UI/etc).

As in my faviorate one (Qt):  you should be able to handle Qt DataTypes (QString/QByteArray) in your pure C++ logic code section.

## Structure
To do so I have developed a pure modern C++ ByteArray data type based on char array and have tested in Linux and Android projects.
It is going to be a fully functional container, and now supports construction based on char*, const char* and also move and copy constructors(ByteArray& and ByeArray&&).
I have implemented move constructor and assignment operator to boost run-time performance.

In Addition to the above methods, mid, split and concatinating multiple ByteArrays (using operator+) and equality operator(==) has bin implemented.

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

## UnitTesting
In order to have more applicable sample codes, you can refer to the UnitTest provided by the project (bytearraytest.cpp)
I have used GoogleTest as my unit testing library for the C++ programming, because it is practical, simple and fast to develop.

### Install GoogleTest on Linux from source
```sh 
git clone https://github.com/google/googletest.git
cd googletest
mkdir build
cd build
cmake ..
make
sudo make install
```

## Build Sample Code (based on UnitTesting)
```sh
g++  bytearraytest.cpp bytearray.cpp main.cpp -lgtest -lgmock -lpthread -o test  && ./test
```

## For Qt Developers
1- GoogleTest is integrated out of the box to the QtCreator. [ReadMore...](https://doc.qt.io/qtcreator/creator-autotest.html)

2- You can simply open project file (ModernCpp-ByteArray.pro) in Qt Creator.

# Feel free to use any code snippet, but cite to my github page.
