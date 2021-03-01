#include <iostream>
#include <304.h>

using namespace std;

int main(int argc, char const *argv[])
{
    //Solution s;
    
    vector<vector<int>> a = {{}};

    NumMatrix n(a);

    n.sumRegion(0,0,1,1);

    system("pause");
    return 0;
}