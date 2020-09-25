#include <iostream>
#include <thread>
#include <chrono>

struct Processer
{

    explicit Processer(int i_=0):i(i_){}
  void operator()()
  {
      std::cout<<"process: "<<i<<std::endl;
      std::this_thread::sleep_for(std::chrono::seconds(i));
      std::cout<<"process: "<<i<<"done"<<std::endl;
  }

      int i;
};

int main() {
    for(int i=0 ; i<10;++i){
        Processer p1(i);
        std::thread t1(p1);
        t1.detach();
    }
    std::this_thread::sleep_for(std::chrono::seconds(20));
    return 0;
}
