#include <iostream>

using namespace std;

class Cat
{
public:
    // static member's value is shared between all Cat instances
    static int howManyCats;

    explicit Cat(int newAge = 1) : age(newAge)  { howManyCats++; }
    virtual ~Cat() { howManyCats--; }

    virtual int getAge() const { return age; }
    virtual void setAge(int newAge) { age = newAge; }

private:
    int age;
};

int Cat::howManyCats = 0;

int main0(int argc, char* argv[])
{
    const int maxCats = 5;
    Cat *catHouse[maxCats];

    for (int i = 0; i < maxCats; ++i)
    {
        catHouse[i] = new Cat(i);
    }

    for (auto *i : catHouse) {
        cout << "There are " << Cat::howManyCats << " cats left." << endl;
        cout << "Removing the one which is " << i->getAge() << " years old" << endl;
        delete i;
        i = nullptr;
    }
    return 0;
}
