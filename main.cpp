#include  <iostream>
#include  <thread>
#include  <mutex>


using namespace std;

mutex mtx;
mutex mtx2;
int train_count = 0;

void road(string train_name, int travel_time)
{
    mtx.lock();
    cout << "train " << train_name << " on the way" << endl;
    mtx.unlock();
    this_thread::sleep_for(chrono::seconds(travel_time));
    mtx.lock();
    cout << "train " << train_name << " arrived at the station" << endl;
    mtx.unlock();

    mtx2.lock();
    this_thread :: sleep_for(chrono :: seconds(1));
    cout << "depart train " << train_name << endl;
    mtx2.unlock();

    cout << "train " << train_name << " departing from the station" << endl;

}

int main()
{
    thread a (road, "A", 5); 
    thread b (road, "B", 10); 
    thread c (road, "C", 15); 

    a.join();
    b.join();
    c.join();

    return 0;
}