#include <iostream>

using namespace std;

class Dog
{
public:
    explicit Dog(int newAge = 1) : age(newAge) { howManyDogs++; }
    virtual ~Dog() { howManyDogs--; }

    virtual int getAge() { return age; }
    virtual void setAge(int newAge) { age = newAge; }

    static int getHowMany() { return howManyDogs; }

private:
    int age;
    static int howManyDogs;
};

int Dog::howManyDogs = 0;

void countDogs()
{
    cout << "There are " << Dog::getHowMany() << " dogs left." << endl;
}

int main()
{
    const int maxDogs = 5;
    Dog *dogHouse[maxDogs];

    for (int i = 0; i < maxDogs; ++i) {
        dogHouse[i] = new Dog(i);
        countDogs();
    }

    for (auto *i : dogHouse) {
        delete i;
        countDogs();
    }

    return 0;
}
