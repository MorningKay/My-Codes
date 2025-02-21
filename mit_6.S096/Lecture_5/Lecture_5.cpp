#include <stdio.h>

// 1. Basic Class Example

// class Rectangle
// {
//     int *width;
//     int *height;

// public:
//     Rectangle(int, int); // constructor
//     ~Rectangle(); // destructor
//     void printMe()
//     {
//         // 'method' / member function
//         printf("Dimensions: %d by %d\n", *width, *height);
//     }
// };

// Rectangle::Rectangle(int w, int h)
// {
//     // constructor definition
//     width = new int;
//     height = new int;
//     *width = w;
//     *height = h;
// }

// Rectangle::~Rectangle()
// {
//     delete width;
//     delete height;
// }

// int main()
// {
//     Rectangle box(5, 7);
//     box.printMe();
// }


// 2. Function Template Example

// template <class typeParam>
// typeParam max(typeParam a, typeParam b)
// {
//     return (a > b ? a : b);
// }

// int main()
// {
//     int a = 3, b = 7;
//     double c = 5.5, d = 1.5;
//     printf("%d\n", max(a, b));
//     printf("%f\n", max(c, d));
// }


// 3. Class Template Example

template <class T>
class mypair
{
    T a, b;
public:
    mypair(T first, T second)
    {
        a = first;
        b = second;
    }
    T getmax();
};

template <class T>
T mypair<T>::getmax()
{
    return a > b ? a : b;
}

int main()
{
    mypair<int> myints(100, 75);
    printf("%d\n", myints.getmax()); // 100
}