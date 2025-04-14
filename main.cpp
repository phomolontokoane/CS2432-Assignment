#include <iostream>
#include "Manager.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Manager m1("The man", "Vandam", 69, 10000);    
    Manager m2 = m1;

    // cout << m2.getName();

    return 0;
}
