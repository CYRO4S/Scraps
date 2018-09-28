#include <iostream>

using namespace std;

enum { kIsSmaller, kIsLarger, kIsSame };

class Data
{
public:
    explicit Data(int newVal) : value(newVal) {}
    ~Data() = default;

    int compare(const Data &other_data)
    {
        if (value < other_data.value)
            return kIsSmaller;
        if (value > other_data.value)
            return kIsLarger;
        else
            return kIsSame;
    }
    void show() { cout << value << endl; }

private:
    int value;
};

class Node
{
public:
    Node() = default;
    virtual ~Node() = default;
    virtual Node* insert(Data *data) = 0;
    virtual void show() = 0;
};

class InternalNode : public Node
{
public:
    InternalNode(Data* newData, Node* newNext) : data(newData), next(newNext) {}
    ~InternalNode() override
    {
        delete next;
        delete data;
    }
    Node* insert(Data *otherData) override
    {
        int result = data->compare(*otherData);

        switch (result)
        {
            case kIsSame: {}
            case kIsLarger:
            {
                auto* dataNode = new InternalNode(otherData, this);
                return dataNode;
            }
            case kIsSmaller:
            {
                next = next->insert(otherData);
                return this;
            }
            default: {}
        }
        return this;
    }
    void show() override
    {
        data->show();
        next->show();
    }

private:
    Data* data;
    Node* next;
};

class TailNode : public Node
{
public:
    TailNode() = default;
    ~TailNode() override = default;
    Node* insert(Data* data) override
    {
        auto* dataNode = new InternalNode(data, this);
        return dataNode;
    }
    void show() override {}
};

class HeadNode : public Node
{
public:
    HeadNode()
    {
        next = new TailNode;
    }
    ~HeadNode() override { delete next; }
    void show() override { next->show(); }
    Node* insert(Data* data) override
    {
        next = next->insert(data);
        return this;
    }

private:
    Node* next;
};

class LinkedList
{
public:
    LinkedList()
    {
        head = new HeadNode;
    }
    ~LinkedList() { delete head; }
    void insert(Data* pData)
    {
        head->insert(pData);
    }
    void showAll() { head->show(); }
private:
    HeadNode* head;
};

int m()
{
    Data* pData;
    int val;
    LinkedList ll;


    Data &r();

    while (true)
    {
        cout << "What value (0 to stop)? ";
        cin >> val;
        if (!val)
            break;
        pData = new Data(val);
        ll.insert(pData);
    }

    ll.showAll();
    return 0;
}
