#include  <iostream>
#include <memory>
#include <vector>

using namespace std;

class Schopincaart
{
    private:

            vector <string> items;

    public:
            void additem(const string& item)
            {
              items.push_back(item);
            } 
            
            void showitem() const
            {
                cout << "item baket: ";
                for(auto i : items)
                {
                   cout << i << " ";
                   cout << endl;
                }

            }

};

class Client
{
    private:
            string name;
            shared_ptr <Schopincaart> cart;

    public:
            Client(string _name)
            {
                name = _name;
                cart = make_shared<Schopincaart>();
            }

            
            void buy(string item)
            {
               cout << "in baket add product: " << item << endl;
               cart->additem(item);

            }

            void showkart() const
            {
                cout << name << " in baket priduct: " << endl;
                cart->showitem();
            }

};


int main()
{
    

    Client alice("Alice");
    Client bob("Bob");

    alice.buy("Apple");
    bob.buy("Banana");

    alice.showkart(); // Alice видит Содержимое корзины: Apple Banana
    bob.showkart();   // Bob видит Содержимое корзины: Apple Banana


    

return 0;

}