#include <iostream>
//#include <list>
#include <string>
//#include <map>
//#include <vector>

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

int main(void){
//std::cout << "Create object" << std::endl;
HelloWorldName::HelloWorld * HelloWorldObject = new HelloWorldName::HelloWorld();
std::string teststring = "Check with std::string class";
HelloWorldObject->GiveName("Check With const char*");
HelloWorldObject->GiveName(teststring);
//HelloWorldObject->Run();
delete HelloWorldObject;
//std::cout << "Object created" << std::endl;
}
