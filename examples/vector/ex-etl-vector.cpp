#include <iostream>
#include <utility>
#include <vector>
#include "../../etl/include/etl/vector.h"

struct Monkey
{
    double height = 5.2;
    int n_bananas = 1;
    void Grow() { height = 1.5 * (height + 1.0); }
    void Feed(int more_bananas) { n_bananas += more_bananas; }
    void Eat() { n_bananas = std::max(n_bananas - 1, 0); }
    Monkey(double c_height, int c_n_bananas) : height(c_height), n_bananas(c_n_bananas) {}
};

std::ostream &operator<<(std::ostream &os, Monkey const &monkey)
{
    os << "Height:\t" << monkey.height << "\tBananas:\t" << monkey.n_bananas;
    return (os);
}

constexpr size_t MAX_NUM_MONKEYS = 3;

int main()
{
    // std::vector<Monkey> barrel;
    etl::vector<Monkey, MAX_NUM_MONKEYS> barrel;
    barrel.push_back(Monkey(111.1, 1));
    std::cout << "Look at all my monkeys!\n";
    for (Monkey const &monkey : barrel)
    {
        std::cout << monkey << '\n';
    }

    std::cout << "\nA new monkey joins the party\n";
    barrel.push_back(Monkey(222.2, 2));

    std::cout << "\nLook at all my monkeys!\n";
    for (Monkey const &monkey : barrel)
    {
        std::cout << monkey << '\n';
    }
    return (0);
}
