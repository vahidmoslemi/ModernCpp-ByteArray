# ModernCpp-ByteArray
ByteArray implementaion is very frequently needed in embedded device and data manipulator applications.
In such cases you could concern memory leaks, passing parameters to functions and return output from them, and so on.
Also when you work other Framesworks to handle some features (UI/etc) like my faviorate one (Qt) you should be able to handle Qt DataTypes (QString/QByteArray) in your pure C++ logic code section.

To do so I have developed a pure modern C++ ByteArray data type based on char array and have tested in Linux and Android projects.
At the time it supports construction based on char*, const char* and also move and copy constructors.
I have implemented move constructor and assignment operator to boost run-time performance.

Currently suppored methods:
mid :     to get a sub-ByteArray from the original (based on copy)
split:    split ByteArray to a vector of ByteArrays based on given delimiter.
data:     get data as const char*  
release:  release data and return pointer to the stored char array
getSize:  get size of the data inside ByteArray object

Note: actual char array inside a ByteArray is null terminated to avoid undefined behavior.
