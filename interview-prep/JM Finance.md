OA
https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/ 

https://www.geeksforgeeks.org/dsa/shortest-path-between-two-nodes-in-array-like-representation-of-binary-tree/

https://xobin.com/c-programming-preview-questions

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int min_bottles;

// Helper function with parameters
void helper(int remaining, int count, const vector<int>& bottleSizes) {
    if (remaining == 0) {
        min_bottles = min(min_bottles, count);
        return;
    }

    for (int bottle : bottleSizes) {
        if (bottle <= remaining) {
            helper(remaining - bottle, count + 1, bottleSizes);
        }
    }
}

// Main function
int bottles_required(int gallons_of_beer, const vector<int>& bottleSizes) {
    min_bottles = INT_MAX;

    // Sort bottle sizes in descending order for greedy-like behavior
    vector<int> sortedBottles = bottleSizes;
    sort(sortedBottles.rbegin(), sortedBottles.rend());

    helper(gallons_of_beer, 0, sortedBottles);
    return min_bottles;
}
```

https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/description/

```cpp
class Solution {
public:
    int countOrders(int n) {
        long long result = 1;
        int MOD = 1e9 + 7;
        
        for (int i = 1; i <= n; i++) {
            result = result * i % MOD;           // for pickup placements
            result = result * (2 * i - 1) % MOD;  // for delivery placements
        }
        return result;
    }
};
```

Let’s dry run for `n = 3`:

|i|result before|i (pickup)|(2i - 1) (delivery)|result after|
|---|---|---|---|---|
|1|1|×1|×1|1 × 1 × 1 = **1**|
|2|1|×2|×3|1 × 2 × 3 = **6**|
|3|6|×3|×5|6 × 3 × 5 = **90**|

https://www.geeksforgeeks.org/dsa/pairs-with-gcd-equal-to-one-in-the-given-range/

https://leetcode.com/problems/excel-sheet-column-number/description/

```cpp
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        for (char c : columnTitle) {
            int value = c - 'A' + 1;
            res = res * 26 + value;
        }
        return res;
    }
};
```

https://studyx.ai/questions/4m02j5l/the-function-calculate-trip-cost-accepts-the-2-parameters-int-mileage-and-int-fuel-price

```cpp
#include <iostream>
#include <cmath> // for ceil

using namespace std;

int calculate_trip_cost(int mileage, int fuel_price) {
    // Total distance of the trip
    int distance = 500;

    // Calculate the number of gallons needed (rounded up)
    int gallons = ceil((double)distance / mileage);

    // Calculate total cost
    int total_cost = gallons * fuel_price;

    return total_cost;
}

int main() {
    // Test Case 1
    int mileage1 = 15, fuel_price1 = 100;
    cout << "Output: " << calculate_trip_cost(mileage1, fuel_price1) << endl; // Output: 3400

    // Test Case 2
    int mileage2 = 25, fuel_price2 = 110;
    cout << "Output: " << calculate_trip_cost(mileage2, fuel_price2) << endl; // Output: 2200

    return 0;
}
```

https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/description/ 
