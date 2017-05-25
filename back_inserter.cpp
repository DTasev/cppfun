#include <vector>
#include <algorithm>
#include <iostream>

class MyClass{
    public:
    MyClass(int n):_n(n){}
    friend std::ostream& operator<<(std::ostream& os, const MyClass& dt){
        os << dt._n;
    }
    
    inline bool operator==(const MyClass& rhs) const {
        return _n == rhs._n;
    }

    private:
    int _n;
};

template <class T>
void print(const std::vector<T> &vec, const std::string &separator=" ", const std::string& end="\n"){
    std::for_each(vec.begin(), vec.end(), [&separator, &end](const T& n){
        std::cout << n << separator;
    });
    std::cout << end;
}
int main(){
    std::vector<MyClass> vec = {1,2,3,4,5,6,7,8,9,10};
    std::cout << "Before:" << '\n';
    print(vec);

    std::remove_if(vec.begin(), vec.end(), [](const MyClass& n){return n==3;});
    print(vec);
    std::remove_copy_if(vec.begin(), vec.end(), vec.begin(), [](const MyClass& n){return n == 5;});
    print(vec);
}