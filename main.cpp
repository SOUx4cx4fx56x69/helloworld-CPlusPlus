#include <iostream>
//#include <list>
#include <string>
//#include <map>
//#include <vector>
#include <math.h> 

namespace HelloWorldName{

class HelloWorld{
//private:
std::string Name;
public:
  HelloWorld(void);
  template <typename T> void GiveName(T & pointer_to_variable);
  void Run(void);
  ~HelloWorld(void);
  //template <typename a_t>HelloWorld operator*(a_t & a);
};

}

template <typename T> void HelloWorldName :: HelloWorld :: GiveName(T & pointer_to_variable){
  this->Name = pointer_to_variable; 
  this->Run();
 }

void HelloWorldName :: HelloWorld :: Run(void){
std::cout << "Hello, world which have a name as " << this->Name << std::endl;
}


HelloWorldName ::  HelloWorld :: HelloWorld (void){
 std::cout << "Inited Hello world class" << std::endl;
 std::cout << "Write your name: ";
 std::getline(std::cin,this->Name);
 std::cout << "\n";
 this->Run();
} 
HelloWorldName ::  HelloWorld :: ~HelloWorld (void){
 std::cout << "\n\nRun delete\n";
} 

namespace size_of{
template <typename Type> int size_of(const char * name){
 std::cout << "Size of " << name << " == " << sizeof(Type) << std::endl;
 return sizeof(Type);
}

}

namespace chars{
void from_to_write(int from,int to){
for(int i = from;i <= to;i++) std::cout << (char)i << " 0x" << std::hex << i << std::endl;
}
}

namespace limits{
template <typename Type> int min_value_of_type(const char*name,bool sig){
if ( sig ){
std::cout << "max value of " << name << " " << (pow(2, (sizeof(Type)*8) ) / 2 - 1)*-1 <<std::endl;
}else{
return 0;
}

}
template <typename Type> void max_value_of_type(const char*name,bool sig){

if ( sig ){
std::cout << "max value of " << name << " " << pow(2, (sizeof(Type)*8) ) / 2 - 1 <<std::endl;
}else{
std::cout << "max value of " << name << " " << pow(2, (sizeof(Type)*8) ) <<std::endl;
}


//return pow(2, (sizeof(Type)*8) );
}


}


int main(void){
//std::cout << "Create object" << std::endl;
HelloWorldName::HelloWorld * HelloWorldObject = new HelloWorldName::HelloWorld();
std::string teststring = "Check with std::string class";
HelloWorldObject->GiveName("Check With const char*");
HelloWorldObject->GiveName(teststring);
//HelloWorldObject->Run();
delete HelloWorldObject;
//std::cout << "Object created" << std::endl;
size_of::size_of<char>("char");
size_of::size_of<int>("int");
size_of::size_of<long long>("long long");
chars::from_to_write(48,57);
limits::min_value_of_type<char>("char",true);
limits::max_value_of_type<char>("char",true);
}
