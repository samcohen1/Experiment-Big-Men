// size_capacity.cpp
// Vector size versus capacity

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vec;
    cout << "vec: size: " << vec.size() 
         << " capacity: " << vec.capacity() << endl;

    for(int i = 0; i < 24; i++) {
        vec.push_back(i);
        cout << "vec: size: " << vec.size() 
             << " capacity: " << vec.capacity() << endl;
    }

    /*
        The vector's size is the number of elements it contains that have been added into the vector. Capacity is the number of elements it is able
        to contain before needing to reallocate memory for the vector.
    */

   /*
        The capacity of the vector doubles each time the vector requires more contiguous space in memory. It does this in order to create a
        balance between memory overhead with performance. We do not want to have too many memory allocations and we do not want to have a large
        amount of unused allocated memory space. Doubling helps us find a good balance between these two.
   */

    return 0;
}
