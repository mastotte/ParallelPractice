#include <iostream>
#include <mutex>
#include <chrono>
#include <random>
#include <thread>
#include <vector>
using namespace std;

enum{THINKING = 0, HUNGRY = 1, EATING = 2};
std::mutex table;
class Chopstick{
public:
    Chopstick() = default;

    void pickUp(){
        
    }

    void putDown(){

    }

};

std::vector <Chopstick*> chopsticks;

void philosopher(int thread_id){
    table.lock();
    chopsticks[thread_id]->pickUp();
    chopsticks[(thread_id+1)%5]->pickUp();
    // eat
    chopsticks[thread_id]->putDown();
    chopsticks[(thread_id+1)%5]->putDown();
    table.unlock();
}
int main()
{
    int n = 5; // number of philosophers
    for (int i = 0; i < 5; i++){
        chopsticks.push_back(new Chopstick);
    }
    
    std::thread t0(philosopher, 0);
    std::thread t1(philosopher, 1);
    std::thread t2(philosopher, 2);
    std::thread t3(philosopher, 3);
    std::thread t4(philosopher, 4);

    return 0;
}