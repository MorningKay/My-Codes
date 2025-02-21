#include <stdio.h>

// 1. slicing

// struct Cow
// {
//     void speak()
//     {
//         printf("Moo.\n");
//     }
// };

// struct Werecow : public Cow
// {
//     bool transformed;
//     void speak()
//     {
//         if (transformed)
//             printf("Aaooooh!\n");
//         else
//             printf("Moo.\n");
//     }
// };

// int main()
// {
//     Werecow wcow;
//     wcow.transformed = true;

//     Cow cows[2];
//     cows[0] = Cow();
//     cows[1] = wcow;

//     for (int i = 0; i < 2; i++)
//         cows[i].speak();
//     wcow.speak();

//     // output:
//     // Moo.
//     // Moo.
//     // Aaooooh!
// }


// 2. pointer

// class Shape
// {
//     public:
//         void draw()
//         {
//             printf("shape\n");
//         }
// };

// class Circle : public Shape
// {
//     public:
//         void draw()
//         {
//             printf("circle\n");
//         }
// };

// int main()
// {
//     Circle *circle = new Circle;
//     circle->draw(); // "circle"

//     Shape *shape = new Circle;
//     shape->draw(); // "shape"

//     // draw() is non-virtual
//     // so it's compiled like a C call
// }


// 3. virtual
// pure virtual methods

class Goofball {
    public:
        int x;
};

class Stupid : public Goofball { };
class Dumb : public Goofball { };

class Oops : public Stupid, public Dumb {
    int fail();
};

int Oops::fail() {
    Stupid::x = 1; Dumb::x = 2;
    return Stupid::x + Dumb::x; // 3
}


class Goofball {
    public:
        int x;
};

class Stupid : virtual public Goofball { };
class Dumb : virtual public Goofball { };

class Oops : public Stupid, public Dumb {
    int fail();
};

int Oops::fail() {
    Stupid::x = 1; Dumb::x = 2;
    return Stupid::x + Dumb::x; // 4
}