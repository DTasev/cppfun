// Type your code here, or load an example.
template<class T>
struct smartptr{
    smartptr(T* ptr): m_ptr(ptr){}
    ~smartptr(){delete ptr;}

    // can't pass by reference
    // can only pass by value

    T * m_ptr = nullptr;
};