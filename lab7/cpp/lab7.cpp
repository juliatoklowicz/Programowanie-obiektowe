#include <iostream>
#include <string>

using namespace std;

template <typename T>
T maximum(T const & a,T const & b)
{
    return a > b ? a: b;
}

template <typename T>
class X
{
private:
    T x;
public:
    X() {};
    X(T x_come) : x(x_come)
    {

    }
    const T & getX() const
    {
        return x;
    }
    friend ostream& operator<< (ostream& os, const X & x_obj)
    {
        os << x_obj.x;
        return os;
    }
};

template <typename T>
bool operator > (X<T> const & a, X<T> const& b)
{
    return a.getX() > b.getX();
}

template <>
bool operator > (X<string> const & a, X<string> const & b)
{
    return a.getX().size() > b.getX().size();
}

template < typename T, typename C = X<T> >
class Y
{
    T zmienna;
    C klasaX;
};

template < typename T>
class A
{
  typename T::id i;
public:
    void f() { i.g(); }
};

class B
{
public:
    class id
    {
    public:
        void g() { }
    };   
};

int main()
{
    cout << maximum(6, 7) << endl;
    cout << maximum(6.3, 7.3) << endl;
    //cout << maximum(6.5, 7) << endl;  //blad ze wzgledu na 2 rozne typy 
    cout << maximum<double>(4, 5) << endl;
    cout << maximum<double>(4.1, 5.7) << endl;
    cout << maximum<int>(4.6, 3) << endl;
    cout << maximum<double>(4.6, 3) << endl;
    cout << maximum<bool>(4.6, 3) << endl;
    //cout << maximum<string>(4.6, 3) << endl;
    //cout << maximum<string>("aaa", "bb") << endl;
    //cout << maximum(X(4) , X(3)) ;
    Y<int> y;
    Y<int, double> y2;
    auto maxLambda = [](auto a, auto b) { return a > b ? a : b; };
    bool b = maxLambda(3,3.14);
    auto c = maxLambda(3,3.14);
    
    A<B> ab;
    ab.f();

}
