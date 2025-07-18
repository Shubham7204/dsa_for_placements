OA

###### 1 .Problem Statement You are given a **2D vector** called `leaveTimes`, where:

###### - Each element is of the form `[employee_id, leave_time]`
###### - `employee_id` is an integer from `0` to `25` representing a nurse labeled `'a'` to `'z'`
###### - Time starts at `t = 0`
###### - **Only one nurse works at a time**, and **the next nurse starts immediately when the previous one finishes**

###### Your task is to find the **nurse (as a character)** who had the **longest single shift**. Note: **Consecutive shifts of the same nurse are considered separate**. If there is a **tie** in duration, return the nurse with **lexicographically smaller character** (i.e., `'a' < 'b' < 'c'`).

```cpp
#include <bits/stdc++.h>
using namespace std;

char findLargestSingleSlot(vector<vector<int>>& leaveTimes) {
   unordered_map<char, int> mpp;
   for (int i = 0; i < leaveTimes.size(); i++) {
       int id = leaveTimes[i][0];
       char ch = 'a' + id;
       int duration;
       if (i == 0)
           duration = leaveTimes[0][1];
       else
           duration = leaveTimes[i][1] - leaveTimes[i - 1][1];
       mpp[ch] = max(mpp[ch], duration);
   }
   char ans = 'z';
   int maxShift = -1;
   for (auto it : mpp) {
       if (it.second > maxShift || (it.second == maxShift && it.first < ans)) {
           maxShift = it.second;
           ans = it.first;
       }
   }
   return ans;
}
```

`char findLargestSingleSlot(vector<vector<int>>& leaveTimes)`

using input:

`leaveTimes = {     {0, 3},     {2, 5},     {0, 9},     {1, 15} };`

## Step-by-step Dry Run

### Initialization:
`unordered_map<char, int> mpp;`
→ empty map `{}`

### 🔁 Loop 1: Calculate durations and fill `mpp`

#### i = 0:
`id = 0 → ch = 'a' duration = leaveTimes[0][1] = 3`
→ `mpp['a'] = 3`
**mpp = { 'a' → 3 }**
#### i = 1:
`id = 2 → ch = 'c' duration = 5 - 3 = 2`
→ `mpp['c'] = 2`
**mpp = { 'a' → 3, 'c' → 2 }**
#### i = 2:
`id = 0 → ch = 'a' duration = 9 - 5 = 4`
→ `mpp['a'] = max(3, 4) = 4`
**mpp = { 'a' → 4, 'c' → 2 }**
#### i = 3:
`id = 1 → ch = 'b' duration = 15 - 9 = 6`
→ `mpp['b'] = 6`
**mpp = { 'a' → 4, 'b' → 6, 'c' → 2 }**
### 🔁 Loop 2: Find max shift and corresponding nurse

#### Initial:
`char ans = 'z' int maxShift = -1`
#### it = { 'a', 4 }
`4 > -1 → maxShift = 4, ans = 'a'`

#### it = { 'b', 6 }
`6 > 4 → maxShift = 6, ans = 'b'`

#### it = { 'c', 2 }
`2 < 6 → no change`

### ✅ Final Result:
`return 'b';`

| Employee | Shifts       | Shift Durations | Max Duration |
| -------- | ------------ | --------------- | ------------ |
| a        | [0–3], [5–9] | 3, 4            | 4            |
| c        | [3–5]        | 2               | 2            |
| b        | [9–15]       | 6 ✅             | 6            |


###### **2 .Problem Statement:** You are given two integer arrays `arr1` and `arr2`, both of length `n`. In one operation, you can **swap any two elements (at any positions)** within either `arr1` or `arr2`. You can perform **any number of such operations** on **either of the arrays**. Your goal is to **maximize** the following expression:

$$\text{Total Sum} = \sum_{i=1}^{n} i \cdot (arr2[i] - arr1[i])$$

(Note: indexing is 1-based in the formula)

After performing any number of swaps on both arrays to rearrange them in optimal order, compute the **maximum possible value** of the above expression. Since the final answer can be large, **return it modulo $10^9 + 7$**.

**Input:**

- Two arrays of integers: `arr1`, `arr2`, each of size `n`

**Output:**

- An integer: Maximum possible value of the expression modulo $10^9 + 7$

**Constraints:**

- $1 \leq n \leq 10^5$
- $-10^9 \leq arr1[i], arr2[i] \leq 10^9$

✅ Key Idea: We want to maximize: $$\sum_{i=1}^{n} i \cdot (arr2[i] - arr1[i]) = \sum_{i=1}^{n} i \cdot arr2[i] - \sum_{i=1}^{n} i \cdot arr1[i]$$

To do this:

- Place **largest** `arr2` values at **largest indices** (to be multiplied with higher `i`)
- Place **smallest** `arr1` values at **largest indices** (because they are subtracted)

✅ So, sort:

- `arr2` in **ascending**
- `arr1` in **descending**

Then apply the formula using 1-based indexing:

```cpp
sum += i * (arr2[i] - arr1[i])
```

✅ Final C++ Code (Optimized)

```cpp
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
typedef long long ll;

int maxWeightedDifferenceSum(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size();
    
    // Step 1: Sort arrays in optimal order
    sort(arr1.rbegin(), arr1.rend()); // arr1 descending
    sort(arr2.begin(), arr2.end());   // arr2 ascending
    
    // Step 2: Apply formula
    ll result = 0;
    for (int i = 0; i < n; i++) {
        ll diff = (ll)arr2[i] - (ll)arr1[i];
        result += ((diff % MOD) * (i + 1)) % MOD;
        result %= MOD;
    }
    
    if (result < 0) result += MOD;
    return (int)result;
}

int main() {
    vector<int> arr1 = {2, 1, 3, 4};
    vector<int> arr2 = {2, 3, 2, 3};
    cout << maxWeightedDifferenceSum(arr1, arr2) << endl;
    return 0;
}
```

✅ Full Dry Run (Step-by-step) Input:

```cpp
arr1 = [2, 1, 3, 4]
arr2 = [2, 3, 2, 3]
```

After Sorting:

```cpp
arr1 = [4, 3, 2, 1] // Descending
arr2 = [2, 2, 3, 3] // Ascending
```

Now compute:

|i (1-based)|arr2[i-1]|arr1[i-1]|arr2 - arr1|i × (arr2 - arr1)|
|---|---|---|---|---|
|1|2|4|-2|1 × (-2) = -2|
|2|2|3|-1|2 × (-1) = -2|
|3|3|2|1|3 × 1 = 3|
|4|3|1|2|4 × 2 = 8|

Total sum = -2 - 2 + 3 + 8 = **7**

Apply modulo: $7 \bmod (10^9 + 7) = 7$

✅ Final Output:

```
7
```

✅ Summary (For Interviews / Notes):

- **Formula**: $\sum i \cdot (arr2[i] - arr1[i])$
- **Allowed**: Any number of swaps in both arrays
- **Sort Strategy**:
    - `arr2`: ascending
    - `arr1`: descending
- **Time Complexity**: $O(n \log n)$
- **Space Complexity**: $O(1)$ (in-place sort)