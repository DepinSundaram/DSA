#include <iostream>
template<typename T>

class SmartPtr {
public:
    SmartPtr() : m_ptr(nullptr), m_ref_count(new int(0)) {}
    SmartPtr(T* ptr) : m_ptr(ptr), m_ref_count(new int(1)) {}
    SmartPtr(const SmartPtr& other) : m_ptr(other.m_ptr), m_ref_count(other.m_ref_count) {
        ++(*m_ref_count);
    }
    SmartPtr& operator=(const SmartPtr& other) {
        if (this == &other) {
            return *this;
        }

        if (--(*m_ref_count) == 0) {
            delete m_ptr;
            delete m_ref_count;
        }
        m_ptr = other.m_ptr;
        m_ref_count = other.m_ref_count;
        ++(*m_ref_count);

        return *this;
    }

    ~SmartPtr() {
        if (--(*m_ref_count)) {
            delete m_ptr;
            delete m_ref_count;
        }
    }

    void* operator*() const { return m_ptr;}
    void* operator->() const { return m_ptr;}
    int getRefCount() const { return *m_ref_count;}
private:
    T* m_ptr;
    int* m_ref_count;
};


class MyClass {
public:
    MyClass(int value) : m_value(value) {
        std::cout << "MyClass constructor" << std::endl;
    }

    ~MyClass() {
        std::cout << "MyClass destructor" << std::endl;
    }

    int getValue() const {
        return m_value;
    }

private:
    int m_value;
};

int main() {
    SmartPtr ptr1(new MyClass(42));
    SmartPtr ptr2 = ptr1;
    std::cout << "ptr1 ref count: " << ptr1.getRefCount() << std::endl;
    std::cout << "ptr2 ref count: " << ptr2.getRefCount() << std::endl;
    SmartPtr ptr3;
    ptr3 = ptr1;
    std::cout << "ptr1 ref count: " << ptr1.getRefCount() << std::endl;
    std::cout << "ptr2 ref count: " << ptr2.getRefCount() << std::endl;
    std::cout << "ptr3 ref count: " << ptr3.getRefCount() << std::endl;
}
