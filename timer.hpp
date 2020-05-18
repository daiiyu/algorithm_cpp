#include <chrono>
#include <iostream>

using namespace std::chrono;
class Timer
{
    using Time = std::chrono::time_point<std::chrono::system_clock>;
public:
    Timer()
    :start(std::chrono::system_clock::now())
    {

    }
    virtual ~Timer(){
        end = system_clock::now();
       duration<double> diff=  end - start;
       std::cout<<diff.count() <<std::endl;
    }
private:
    Time start;
    Time end;
};