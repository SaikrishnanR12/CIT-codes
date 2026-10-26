#include <iostream>
#include <memory>
using namespace std;
// Resource class
class Resource
{
    int id;
public:
    Resource(int i = 0) : id(i) { cout << "Resource " << id << " acquired" << endl; }
    ~Resource() { cout << "Resource " << id << " released" << endl; }
    void use() { cout << "Resource " << id << " is being used" << endl; }
};
// Manual Smart Pointer using RAII
class MySmartPointer
{
private:
    Resource* ptr;
public:
    MySmartPointer(Resource* p) { ptr = p; }
    ~MySmartPointer()
    {
        delete ptr;
        cout << "Manual smart pointer destroyed" << endl;
    }
    Resource* operator->() { return ptr; }
    // Disable copying to avoid double deletion
    MySmartPointer(const MySmartPointer&) = delete;
    MySmartPointer& operator=(const MySmartPointer&) = delete;
};
int main()
{
    cout << "----- Manual RAII Smart Pointer -----" << endl;
    {
        MySmartPointer smartPtr(new Resource(1));
        smartPtr->use();
    }
    cout << "\n----- unique_ptr (with ownership transfer) -----" << endl;
    {
        unique_ptr<Resource> p1 = make_unique<Resource>(2);
        p1->use();
        unique_ptr<Resource> p2 = move(p1);
        cout << "p1 empty after move: " << (p1 == nullptr ? "yes" : "no") << endl;
        p2->use();
    }
    cout << "\n----- shared_ptr (reference counting) -----" << endl;
    {
        shared_ptr<Resource> s1 = make_shared<Resource>(3);
        cout << "Count after creation: " << s1.use_count() << endl;
        {
            shared_ptr<Resource> s2 = s1;
            shared_ptr<Resource> s3 = s1;
            s1->use();
            cout << "Count with 3 owners: " << s1.use_count() << endl;
        }
        cout << "Count after inner scope: " << s1.use_count() << endl;
    }
    cout << "\nProgram completed successfully." << endl;
    return 0;
}
