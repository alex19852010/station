#include  <iostream>
#include  <thread>
#include  <mutex>


using namespace std;

mutex mtx;
mutex mtx2;
string command;

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
    
    while(command != "depart")
    {
        cout << "enter command depart for " << train_name << endl;
        cin >> command;
        if (command == "depart")
        {
            command = "";
            break;
        }
    }
    mtx2.unlock();

    cout << "train " << train_name << " departing from the station" << endl;

}

int main()
{
    thread a (road, "A", 7); 
    thread b (road, "B", 14); 
    thread c (road, "C", 21); 

    a.join();
    b.join();
    c.join();

    return 0;

     }