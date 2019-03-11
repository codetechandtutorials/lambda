#include <iostream>  // for std::cout
#include <list>      // for std::list<>
#include <algorithm> // for std::for_each

/* normal way of printing your list of integers */
void print_int(int i) { std::cout << ":" << i << ":"; };
int main() {
    std::list<int> int_list = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::for_each(int_list.begin(), int_list.end(), print_int);
    return 0;
}

/* -------------------------------------------- */

/* lambda way of printing your list of integers */
// int main() {
//     std::list<int> int_list = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//     std::for_each(int_list.begin(), int_list.end(), [](int i){ std::cout << ":" << i << ":"; } );
//     return 0;
// }

/* -------------------------------------------- */

/* passing a value to your lambda function */
// int main() {
//     [](int i){ std::cout << ":" << i << ":"; } (42);
//     return 0;
// }

/* -------------------------------------------- */

/* store your lambda as a variable using auto */
// int main() {
//     auto func1 = [](int i){ std::cout << ":" << i << ":"; };
//     func1(42);
//     return 0;
// }

/* -------------------------------------------- */

/* calling a lambda that returns void */
// int main() {
//     [](){ std::cout << "this is just a test!\n"; } ();
//     return 0;
// }

/* -------------------------------------------- */

/* lambdas figure out what their return type is by the return in the function */
// int main()
// {
//     if ([](int i, int j) { return i / 2 == j; }(24, 12))
//     {
//         std::cout << "this returned true!";
//     }
//     else
//     {
//         std::cout << "this returned false!";
//     }
//     return 0;
// }

/* -------------------------------------------- */

/* lambdas that have more than one return statement, or if a type conversion is needed */
// int main()
// {
//     std::cout << "this lambda returns: "
//               << [](int x, int y) -> int { if (x > 5) { return x + y * .2; } else if (y < 2) { return x - y *.2; } else { return x * y *.2; } }(4, 3) << std::endl;

//     std::cout << "this lambda returns: "
//               << [](int x, int y) -> float { if (x > 5) { return x + y * .21f; } else if (y < 2) { return x - y *.21f; } else { return x * y *.21f; } }(4, 3) << std::endl;

//     std::cout << "this lambda returns: "
//               << [](int x, int y) -> double { if (x > 5) { return x + y * .2; } else if (y < 2) { return x - y *.2; } else { return x * y *.2; } }(4, 3) << std::endl;

//     std::cout << "this lambda returns: "
//               << [](double x, double y) -> int { return x + y; }(3.14, 2.7) << std::endl;
//     return 0;
// }

/* -------------------------------------------- */

/* lambdas can capture local variables */
// int main()
// {
//     double x = 15.55f;
//     double y = 12.12f;
//     [x, y]() {
//         int i = 7;
//         std::cout << "x=" << x << " y=" << y << " i=" << i << std::endl;
//     }();
//     return 0;
// }

/* -------------------------------------------- */

/* variable captures are a copy of the original, not a reference */
// int main() {
//     int x = 42;
//     auto func1 = [x](){ std::cout << "The value of x inside the lambda is: " << x << std::endl; };
//     func1();
//     for (int i = 0; i < 3; i++) {
//         x++;
//         func1();
//     }
//     std::cout << "but the value of x outside our lambda is now: " << x << std::endl;
//     return 0;
// }

/* -------------------------------------------- */

/* variable captures are a copy of the original, not a reference */
// int main() {
//     int x = 42;
//     auto func1 = [x](){ std::cout << "The value of x inside the lambda is: " << x << std::endl; };
//     func1();
//     for (int i = 0; i < 3; i++) {
//         x++;
//         func1();
//     }
//     std::cout << "but the value of x outside our lambda is now: " << x << std::endl;
//     return 0;
// }

/* -------------------------------------------- */

/* but, you can capture the variable as a reference if you want */
// int main() {
//     int x = 42;
//     auto func1 = [&x](){ std::cout << "The value of x inside the lambda is: " << x << std::endl; };
//     func1();
//     for (int i = 0; i < 3; i++) {
//         x++;
//         func1();
//     }
//     std::cout << "but the value of x outside our lambda is now: " << x << std::endl;
//     return 0;
// }

/* -------------------------------------------- */

/* lambda taking a reference and modifying it */
// int main()
// {
//     int x = 42;
//     auto func1 = [&x]() {
//         x++;
//         std::cout << "The value of x inside the lambda is: " << x << std::endl;
//     };
//     func1();
//     for (int i = 0; i < 3; i++)
//     {
//         func1();
//     }
//     std::cout << "but the value of x outside our lambda is now: " << x << std::endl;
//     return 0;
// }

/* -------------------------------------------- */

/* you do not have to store the lambda as an auto variable to do this */
// int main()
// {
//     int x = 42;

//     for (int i = 0; i < 3; i++)
//     {
//         [&x]() {
//             x += x;
//             std::cout << "The value of x inside the lambda is: " << x << std::endl;
//         }();
//     }
//     std::cout << "but the value of x outside our lambda is now: " << x << std::endl;
//     return 0;
// }

/* -------------------------------------------- */

/* shortcut to capture all local variables */
// int main()
// {
//     double x = 15.55f;
//     double y = 12.12f;
//     [=]() {
//         int i = 7;
//         std::cout << "x=" << x << " y=" << y << " i=" << i << std::endl;
//     }();
//     return 0;
// }

/* -------------------------------------------- */

/* shortcut to capture all local variables by reference */
// int main()
// {
//     double x = 15.55f;
//     double y = 12.12f;
//     for (int i = 0; i < 3; i++)
//     {
//         [&]() {
//             x += x;
//             y += y;
//             std::cout << "x=" << x << " y=" << y << std::endl;
//         }();
//     }
//     return 0;
// }

/* -------------------------------------------- */

/* a semi-real-world example of using a lambda with a class */
// #include <fstream>

// class Thing {
// public:
//     Thing() : m_data(0) {}
//     Thing(int d_) : m_data(d_) {};
//     void save(std::ofstream &os) const { os << m_data << "\n"; };
// private:
//     int m_data;
// };

// int main() {
//     Thing * zero = new Thing();
//     Thing * one = new Thing(1);
//     Thing * fortytwo = new Thing(42);
//     std::list<Thing *> thing_ptrs = { zero, one, fortytwo };
//     std::ofstream out_file("thing_output.rtf");
//     std::for_each (thing_ptrs.begin(), thing_ptrs.end(), [&out_file](Thing * ptr){ ptr->save(out_file); } );
//     return 0;
// }

/* -------------------------------------------- */

/* capturing members of a class requires use of `this` */
// class Thing
// {
//   public:
//     Thing() : m_criteria(0){};
//     Thing(int crit) : m_criteria(crit){};
//     int get_how_many_higher_than_criteria()
//     {
//         m_count = 0;
//         std::for_each(m_int_list.begin(), m_int_list.end(), [this](int i) { if (i > m_criteria) m_count++; });
//         return m_count;
//     };
//     void addToIntList(int i)
//     {
//         m_int_list.push_back(i);
//     };
//   private:
//     std::list<int> m_int_list;
//     int m_count;
//     int m_criteria;
// };

// int main()
// {
//     Thing thing(5);
//     for (int i = 0; i < 8; i++) {
//         thing.addToIntList(i+3);
//     }
//     std::cout << "There are " << thing.get_how_many_higher_than_criteria() << " higher than 5" << std::endl;
//     return 0;
// }

// references:
//   http://umich.edu/~eecs381/handouts/Lambda.pdf
//   https://en.cppreference.com/w/cpp/algorithm/for_each