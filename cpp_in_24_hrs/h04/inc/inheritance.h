#include <iostream>

using namespace std;

class PJMask
{
public:
    // enums
    enum MEMBER_TYPE
    {
        HUMAN = 0,
        ROBOT = 1
    };

    // constructors & destructor
    PJMask() = default;
    PJMask(PJMask &) = default;
    PJMask(MEMBER_TYPE member_type, int age) : _member(member_type), _age(age)
    {
        cout << "It's a PJMask!" << endl;
    }
    ~PJMask() = default;



    // properties
    MEMBER_TYPE getMember() const { return _member; }
    void setMember(MEMBER_TYPE m) { _member = m; }

    int getAge() const { return _age; }
    void setAge(int a) { _age = a; }

    // functions
    virtual void const exclamation()
    {
        cout << "This PJMask shout: ";
    }

private:
    MEMBER_TYPE _member = MEMBER_TYPE ::HUMAN;
    int _age = 0;
};

class PJRobot : public PJMask
{
public:
    // constructors and destructor
    PJRobot() = default;
    PJRobot(PJRobot&)  = default;
    ~PJRobot() = default;

    void const exclamation() override
    {
        cout << "Doo-Weep!" << endl;
    }

};


int main(int argc, char* argv[])
{
    PJRobot robot;
    robot.PJMask::exclamation();
    return 0;
}
