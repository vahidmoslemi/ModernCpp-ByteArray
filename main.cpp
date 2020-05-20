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
