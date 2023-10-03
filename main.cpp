#include  <iostream>
#include  <thread>
#include  <mutex>


using namespace std;

mutex mtx;
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
    // unique_lock<mutex> lock(mtx);
    // train_count++;

    // cout << "Train " << train_name << " has arrived at the station." << endl;

    // while (train_count > 1) {
    //     cout << "Train " << train_name << " is waiting for the station to be available." << endl;
    //     lock.unlock();
    //     this_thread::sleep_for(chrono::seconds(1));
    //     lock.lock();
    // }

    // cout << "Train " << train_name << " is departing from the station." << endl;
    // train_count--;
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