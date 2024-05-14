#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
template <typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag,
             tree_order_statistics_node_update>;
//red black trees.
//*find_by_order();//it finds the element at that index
//order_of_key();//it find the number of elements strictly less than the key
