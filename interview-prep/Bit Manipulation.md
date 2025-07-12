## 1. Single Number

### Problem Statement

You are given a non-empty array of integers `nums`. Every integer appears twice except for one. Return the integer that appears only once. You must implement a solution with O(n) runtime complexity and use only O(1) extra space.

**Example 1:**

```java
Input: nums = [3,2,3]
Output: 2
```

**Example 2:**

```java
Input: nums = [7,6,6,7,8]
Output: 8
```

**Constraints:**

- `1 <= nums.length <= 10000`
- `-10000 <= nums[i] <= 10000`

### Recommended Time & Space Complexity

**Hint 1**: A brute force approach would iterate through the array, checking each element using a nested loop. If a duplicate is found, we continue to the next element; otherwise, the current element is the required number. This results in an `O(n^2)` solution. Can you think of a better way? Maybe a data structure can help detect duplicates efficiently.

**Hint 2**: We use a hash set, iterating through the array and adding elements that are not in the set while removing those that are already present. After the iteration, the required number remains in the hash set. This results in an `O(n)` space solution. Can you further optimize it? Maybe a bitwise operator could be useful here.

**Hint 3**: Think about the bitwise XOR `("^")`. What is the result when two identical numbers are XORed?

**Hint 4**: When two identical numbers are XORed, they cancel out, resulting in zero. Since every number appears twice except for one, the XOR of the entire array gives the number that appears only once.

---

## **1. Brute Force**

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            bool flag = true;
            for (int j = 0; j < nums.size(); j++) {
                if (i != j && nums[i] == nums[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return nums[i];
            }
        }
        return -1; 
    }
};
```

**Time & Space Complexity**

- **Time complexity: O(n²)**
- **Space complexity: O(1)**

### Dry Run for Brute Force (Example: nums = [3,2,3])

|i|nums[i]|j|nums[j]|i != j|nums[i] == nums[j]|flag|Action|
|---|---|---|---|---|---|---|---|
|0|3|0|3|false|true|true|continue|
|0|3|1|2|true|false|true|continue|
|0|3|2|3|true|true|false|break|
|0|3|-|-|-|-|false|continue to next i|
|1|2|0|3|true|false|true|continue|
|1|2|1|2|false|true|true|continue|
|1|2|2|3|true|false|true|continue|
|1|2|-|-|-|-|true|return 2|

---

## **2. Hash Set**

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num)) {
                seen.erase(num);
            } else {
                seen.insert(num);
            }
        }
        return *seen.begin();
    }
};

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int findElementWithFrequencyOne(const vector<int>& nums) {
    map<int, int> mpp;

    // Count frequency of each element
    for (int i = 0; i < nums.size(); i++) {
        mpp[nums[i]]++;
    }

    // Find and return the first element with frequency 1
    for (auto it : mpp) {
        if (it.second == 1) {
            return it.first;
        }
    }

    return -1; // If no such element found
}
```

**Time & Space Complexity**

- **Time complexity: O(n)**
- **Space complexity: O(n)**

### Dry Run for Hash Set (Example: nums = [3,2,3])

|Iteration|num|seen.count(num)|Action|seen after action|
|---|---|---|---|---|
|1|3|0|insert|{3}|
|2|2|0|insert|{3, 2}|
|3|3|1|erase|{2}|
|End|-|-|return|2|

---

## **3. Sorting**

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int i = 0;
        while (i < nums.size() - 1) {
            if (nums[i] == nums[i + 1]) {
                i += 2;
            } else {
                return nums[i];
            }
        }
        return nums[i];
    }
};
```

**Time & Space Complexity**

- **Time complexity: O(nlog n)**
- **Space complexity: O(1) or O(n) depending on the sorting algorithm.**

### Dry Run for Sorting (Example: nums = [3,2,3])

|Step|Action|Array State|i|nums[i]|nums[i+1]|Condition|Action|
|---|---|---|---|---|---|---|---|
|1|sort|[2,3,3]|-|-|-|-|-|
|2|while|[2,3,3]|0|2|3|2 != 3|return 2|

---

## **4. Bit Manipulation**

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int num : nums) {
            res ^= num;
        }
        return res;
    }
};
```

**Time & Space Complexity**

- **Time complexity: O(n)**
- **Space complexity: O(1)**

### Dry Run for Bit Manipulation (Example: nums = [3,2,3])

|Iteration|num|res (before)|res ^ num|res (after)|Binary Representation|
|---|---|---|---|---|---|
|Initial|-|0|-|0|000|
|1|3|0|0 ^ 3|3|011|
|2|2|3|3 ^ 2|1|001|
|3|3|1|1 ^ 3|2|010|
|End|-|2|-|2|return 2|

### XOR Properties Used:

- `a ^ a = 0` (any number XORed with itself is 0)
- `a ^ 0 = a` (any number XORed with 0 is the number itself)
- XOR is commutative and associative

# 2. Number of One Bits

**You are given an unsigned integer** `n`. Return the number of `1` bits in its binary representation.

**You may assume** `n` is a non-negative integer which fits within 32-bits.

**Example 1:**

```java
Input: n = 00000000000000000000000000010111
Output: 4
```

**Example 2:**

```java
Input: n = 01111111111111111111111111111101
Output: 30
```

### Recommended Time & Space Complexity

You should aim for a solution with `O(1)` time and `O(1)` space.

**Hint 1** The given integer is a `32`-bit integer. Can you think of using bitwise operators to iterate through its bits? Maybe you should consider iterating `32` times.

**Hint 2** We iterate `32` times `(0 to 31)` using index `i`. The expression `(1 << i)` creates a bitmask with a set bit at the `i`-th position. How can you check whether the `i`-th bit is set in the given number? Maybe you should consider using the bitwise-AND `("&")`.

**Hint 3** Since the mask has a set bit at the `i`-th position and all `0`s elsewhere, we can perform a bitwise-AND with `n`. If `n` has a set bit at the `i`-th position, the result is positive; otherwise, it is `0`. We increment the global count if the result is positive and return it after the iteration.

---

## **1. Bit Mask - I**

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            if ((1 << i) & n) {
                res++;
            }
        }
        return res;
    }
};
```

**Time & Space Complexity**

- **Time complexity: O(1)**
- **Space complexity: O(1)**

### Dry Run for Bit Mask - I (Example: n = 11 = 1011 in binary)

|i|1 << i|Binary of (1 << i)|(1 << i) & n|Binary AND Result|Condition|res|
|---|---|---|---|---|---|---|
|0|1|0001|1|0001|true|1|
|1|2|0010|2|0010|true|2|
|2|4|0100|0|0000|false|2|
|3|8|1000|8|1000|true|3|
|4|16|10000|0|0000|false|3|
|...|...|...|...|...|...|...|
|31|2147483648|10000000000000000000000000000000|0|0000|false|3|

**Final Result: 3**

---

## **2. Bit Mask - II**

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n != 0) {
            res += (n & 1) ? 1 : 0;
            n >>= 1;
        }
        return res;
    }
};
```

**Time & Space Complexity**

- **Time complexity: O(1)**
- **Space complexity: O(1)**

### Dry Run for Bit Mask - II (Example: n = 11 = 1011 in binary)

|Iteration|n (decimal)|n (binary)|n & 1|(n & 1) ? 1 : 0|res|n >>= 1|n after shift|
|---|---|---|---|---|---|---|---|
|1|11|1011|1|1|1|n >>= 1|5 (0101)|
|2|5|0101|1|1|2|n >>= 1|2 (0010)|
|3|2|0010|0|0|2|n >>= 1|1 (0001)|
|4|1|0001|1|1|3|n >>= 1|0 (0000)|
|5|0|0000|-|-|3|exit|-|

**Final Result: 3**

---

## **3. Bit Mask (Optimal)**

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            n &= n - 1;
            res++;
        }
        return res;
    }
};
```

**Time & Space Complexity**

- **Time complexity: O(1)**
- **Space complexity: O(1)**

### Dry Run for Bit Mask (Optimal) (Example: n = 11 = 1011 in binary)

|Iteration|n (decimal)|n (binary)|n - 1|(n-1) binary|n & (n-1)|Result binary|res|
|---|---|---|---|---|---|---|---|
|1|11|1011|10|1010|10|1010|1|
|2|10|1010|9|1001|8|1000|2|
|3|8|1000|7|0111|0|0000|3|
|4|0|0000|-|-|-|-|3|

**Final Result: 3**

**Key Insight:** `n & (n-1)` removes the rightmost set bit from n.

---

## **4. Built-In Function**

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};
```

**Time & Space Complexity**

- **Time complexity: O(1)**
- **Space complexity: O(1)**

### Dry Run for Built-In Function (Example: n = 11 = 1011 in binary)

|Input|Function Call|Direct Result|
|---|---|---|
|11|__builtin_popcount(11)|3|

**Final Result: 3**

**Note:** `__builtin_popcount()` is a GCC built-in function that directly counts the number of set bits in an integer.

# 3. Counting Bits

**Given an integer** `n`, count the number of `1`'s in the binary representation of every number in the range `[0, n]`.

**Return an array** `output` where `output[i]` is number of `1`'s in the binary representation of `i`.

**Example 1:**

```java
Input: n = 4
Output: [0,1,1,2,1]
```

**Explanation: 0 --> 0 1 --> 1 2 --> 10 3 --> 11 4 --> 100**

**Constraints:**

- `0 <= n <= 1000`

### Recommended Time & Space Complexity

You should aim for a solution with `O(n)` time and `O(n)` space, where `n` is the given integer.

**Hint 1** A straightforward approach would be to iterate from `0` to `n` using `i`, and for each `i`, iterate through its bits to count the number of set bits. This would result in an `O(n \log n)` approach. Can you think of a better way? Maybe you should try identifying a pattern by observing the bitwise representation of consecutive numbers.

**Hint 2** For example, to compute set bits for `7`, add `1` to the count of set bits in `3`, which was previously computed by adding `1` to the count of set bits in `1`. Observing the pattern, for numbers less than `4`, add `1` to the count from two positions before. For numbers less than `8`, add `1` to the count from four positions before. Can you derive a dynamic programming relation from this?

**Hint 3** We find an offset for the current number based on the number before `offset` positions. The dynamic programming relation is `dp[i] = 1 + dp[i - offset]`, where `dp[i]` represents the number of set bits in `i`. The offset starts at `1` and updates when encountering a power of `2`. To simplify the power of `2` check, if `offset * 2` equals the current number, we update `offset` to the current number.

---

## **1. Bit Manipulation - I**

```cpp
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        for (int num = 1; num <= n; num++) {
            for (int i = 0; i < 32; i++) {
                if (num & (1 << i)) {
                    res[num]++;
                }
            }
        }
        return res;
    }
};
```

**Time & Space Complexity**

- **Time complexity: O(n log n)**
- **Space complexity:**
    - **O(1) extra space.**
    - **O(n) space for the output array.**

### Dry Run for Bit Manipulation - I (Example: n = 4)

|num|Binary|i|1 << i|num & (1 << i)|res[num] after increment|
|---|---|---|---|---|---|
|1|0001|0|1|1|1|
|1|0001|1|2|0|1|
|1|0001|2|4|0|1|
|1|0001|3|8|0|1|
|2|0010|0|1|0|0|
|2|0010|1|2|2|1|
|2|0010|2|4|0|1|
|2|0010|3|8|0|1|
|3|0011|0|1|1|1|
|3|0011|1|2|2|2|
|3|0011|2|4|0|2|
|3|0011|3|8|0|2|
|4|0100|0|1|0|0|
|4|0100|1|2|0|0|
|4|0100|2|4|4|1|
|4|0100|3|8|0|1|

**Final Result: [0,1,1,2,1]**

---

## **2. Bit Manipulation - II**

```cpp
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int num = i;
            while (num != 0) {
                res[i]++;
                num &= (num - 1);
            }
        }
        return res;
    }
};
```

**Time & Space Complexity**

- **Time complexity: O(n log n)**
- **Space complexity:**
    - **O(1) extra space.**
    - **O(n) space for the output array.**

### Dry Run for Bit Manipulation - II (Example: n = 4)

|i|num (initial)|Binary|num & (num-1)|num after|res[i] after increment|
|---|---|---|---|---|---|
|1|1|0001|0|0|1|
|2|2|0010|0|0|1|
|3|3|0011|2|2|1|
|3|2|0010|0|0|2|
|4|4|0100|0|0|1|

**Final Result: [0,1,1,2,1]**

---

## **3. In-Built Function**

```cpp
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            res[i] = __builtin_popcount(i);
        }
        return res;
    }
};
```

**Time & Space Complexity**

- **Time complexity: O(n log n)**
- **Space complexity:**
    - **O(1) extra space.**
    - **O(n) space for the output array.**

### Dry Run for In-Built Function (Example: n = 4)

|i|Binary|__builtin_popcount(i)|res[i]|
|---|---|---|---|
|0|0000|0|0|
|1|0001|1|1|
|2|0010|1|1|
|3|0011|2|2|
|4|0100|1|1|

**Final Result: [0,1,1,2,1]**

---

## **4. Bit Manipulation (DP)**

```cpp
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1);
        int offset = 1;

        for (int i = 1; i <= n; i++) {
            if (offset * 2 == i) {
                offset = i;
            }
            dp[i] = 1 + dp[i - offset];
        }
        return dp;
    }
};
```

**Time & Space Complexity**

- **Time complexity: O(n)**
- **Space complexity:**
    - **O(1) extra space.**
    - **O(n) space for the output array.**

### Dry Run for Bit Manipulation (DP) (Example: n = 4)

|i|offset|offset * 2|offset * 2 == i|new offset|i - offset|dp[i - offset]|dp[i]|
|---|---|---|---|---|---|---|---|
|1|1|2|false|1|0|0|1|
|2|1|2|true|2|0|0|1|
|3|2|4|false|2|1|1|2|
|4|2|4|true|4|0|0|1|

**Final Result: [0,1,1,2,1]**

---

## **5. Bit Manipulation (Optimal)**

```cpp
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
};
```

**Time & Space Complexity**

- **Time complexity: O(n)**
- **Space complexity:**
    - **O(1) extra space.**
    - **O(n) space for the output array.**

### Dry Run for Bit Manipulation (Optimal) (Example: n = 4)

|i|Binary|i >> 1|dp[i >> 1]|i & 1|dp[i]|
|---|---|---|---|---|---|
|1|0001|0|0|1|1|
|2|0010|1|1|0|1|
|3|0011|1|1|1|2|
|4|0100|2|1|0|1|

**Final Result: [0,1,1,2,1]**

**Key Insight:** `dp[i] = dp[i >> 1] + (i & 1)` means the count of bits in `i` equals the count of bits in `i/2` plus 1 if `i` is odd (has rightmost bit set).

# 4. Reverse Bits

**Given a 32-bit unsigned integer** `n`, reverse the bits of the binary representation of `n` and return the result.

**Example 1:**

```java
Input: n = 00000000000000000000000000010101
Output:    2818572288 (10101000000000000000000000000000)
```

**Explanation: Reversing** `00000000000000000000000000010101`, which represents the unsigned integer `21`, gives us `10101000000000000000000000000000` which represents the unsigned integer `2818572288`.

### Recommended Time & Space Complexity

You should aim for a solution with `O(1)` time and `O(1)` space.

**Hint 1** Given a 32-bit integer, what is the position of bit `i` after reversing the bits? Maybe you should observe the bit positions before and after reversal to find a pattern.

**Hint 2** After reversing the bits, the bit at position `i` moves to position `31 - i`. Can you use this observation to construct the reversed number efficiently?

**Hint 3** We initialize `res` to `0` and iterate through the bits of the given integer `n`. We extract the bit at the `i`-th position using `((n >> i) & 1)`. If it is `1`, we set the corresponding bit in `res` at position `(31 - i)` using `(res |= (1 << (31 - i)))`.

In example 1, The binary of 6 is 110 if we reverse 110 then we will get 011 which is the binary of 3. So, all we have to do is to convert the decimal number(base 10) into binary(base 2) and then reverse the binary number and then convert it into decimal.

One by one bit in the binary representation of n is being obtained with the help of bitwise right shift operation and they are being accumulated in rev with the help of bitwise left shift operation.

**Right Shift :** Takes two numbers, right shifts the bits of the first operand, and the second operand decides the number of places to shift.

```
eg: let's take N=32; which is 100000 in Binary Form.
If "N is right-shifted by 2" i.e N=N>>2 then N will become N=N/(2^2). Thus, N=32/(2^2)=8 which can be written as 1000.
```

**Left Shift :** Takes two numbers, the left shifts the bits of the first operand, and the second operand decides the number of places to shift.

```
eg: let's take N=22; which is 00010110 in Binary Form.
If "N is left-shifted by 2" i.e N=N<<2 then N will become N=N*(2^2). Thus, N=22*(2^2)=88 which can  be written as 01011000.
```

```cpp
#include<iostream>
using namespace std;

int reverseBits(int n)
{
    int rev = 0;
    while (n > 0) {
        rev <<= 1;
 
        if (n & 1 == 1)
            rev ^= 1;
        n >>= 1;
    }
 
    return rev;
}
```
### Initial Setup:
- `n = 5`
- `rev = 0`
### Iteration Table:

|Step|`n` (dec)|`n` (bin)|`rev` (before shift)|`rev <<= 1`|`n & 1`|Add bit to `rev`?|`rev` (after update)|`n >>= 1`|
|---|---|---|---|---|---|---|---|---|
|1|5|101|0|0|1|Yes (`^=1`)|1|2|
|2|2|010|1|10 (2)|0|No|2|1|
|3|1|001|2|100 (4)|1|Yes (`^=1`)|5|0|

### Final Result:
- `rev = 5`
- Binary of input `5` = `101`
- Reversed = `101` → Still `5` because it is symmetric in binary

## **1. Brute Force**

```cpp
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string binary = "";
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                binary += '1';
            } else {
                binary += '0';
            }
        }
        
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            if (binary[31 - i] == '1') { 
                res |= (1 << i);
            }
        }
        
        return res;
    }
};
```

**Time & Space Complexity**

- **Time complexity: O(1)**
- **Space complexity: O(1)**

### Dry Run for Brute Force (Example: n = 5 = 101 in binary)

**First Loop - Building binary string:**

|i|1 << i|n & (1 << i)|binary|
|---|---|---|---|
|0|1|1|"1"|
|1|2|4|"10"|
|2|4|4|"101"|
|3|8|0|"1010"|
|4|16|0|"10100"|
|...|...|...|...|
|31|2147483648|0|"10100000000000000000000000000000"|

**Second Loop - Building result:**

|i|31 - i|binary[31 - i]|res before|1 << i|res after|
|---|---|---|---|---|---|
|0|31|'0'|0|1|0|
|1|30|'0'|0|2|0|
|2|29|'1'|0|4|4|
|3|28|'0'|4|8|4|
|4|27|'1'|4|16|20|
|...|...|...|...|...|...|
|31|0|'1'|20|2147483648|2147483668|

**Final Result: 2147483668**

---

## **2. Bit Manipulation**

```cpp
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            uint32_t bit = (n >> i) & 1;
            res += (bit << (31 - i));
        }
        return res;
    }
};
```

**Time & Space Complexity**

- **Time complexity: O(1)**
- **Space complexity: O(1)**

### Dry Run for Bit Manipulation (Example: n = 5 = 101 in binary)

|i|n >> i|(n >> i) & 1|bit|31 - i|bit << (31 - i)|res before|res after|
|---|---|---|---|---|---|---|---|
|0|5|1|1|31|2147483648|0|2147483648|
|1|2|0|0|30|0|2147483648|2147483648|
|2|1|1|1|29|536870912|2147483648|2684354560|
|3|0|0|0|28|0|2684354560|2684354560|
|4|0|0|0|27|0|2684354560|2684354560|
|...|...|...|...|...|...|...|...|
|31|0|0|0|0|0|2684354560|2684354560|

**Final Result: 2684354560**

---

## **3. Bit Manipulation (Optimal)**

```cpp
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = n;
        ret = (ret >> 16) | (ret << 16);
        ret = ((ret & 0xff00ff00) >> 8) | ((ret & 0x00ff00ff) << 8);
        ret = ((ret & 0xf0f0f0f0) >> 4) | ((ret & 0x0f0f0f0f) << 4);
        ret = ((ret & 0xcccccccc) >> 2) | ((ret & 0x33333333) << 2);
        ret = ((ret & 0xaaaaaaaa) >> 1) | ((ret & 0x55555555) << 1);
        return ret;
    }
};
```

**Time & Space Complexity**

- **Time complexity: O(1)**
- **Space complexity: O(1)**

### Dry Run for Bit Manipulation (Optimal) (Example: n = 5 = 00000000000000000000000000000101)

|Step|Operation|ret before|ret after|Binary representation|
|---|---|---|---|---|
|0|Initial|5|5|00000000000000000000000000000101|
|1|Swap 16-bit halves|5|327680|00000000000001010000000000000000|
|2|Swap 8-bit chunks|327680|83886080|00000101000000000000000000000000|
|3|Swap 4-bit chunks|83886080|1342177280|01010000000000000000000000000000|
|4|Swap 2-bit chunks|1342177280|2684354560|10100000000000000000000000000000|
|5|Swap 1-bit chunks|2684354560|2684354560|10100000000000000000000000000000|

**Detailed breakdown:**

- **Step 1:** `(ret >> 16) | (ret << 16)` - Swaps the upper and lower 16 bits
- **Step 2:** Uses mask `0xff00ff00` and `0x00ff00ff` to swap 8-bit chunks
- **Step 3:** Uses mask `0xf0f0f0f0` and `0x0f0f0f0f` to swap 4-bit chunks
- **Step 4:** Uses mask `0xcccccccc` and `0x33333333` to swap 2-bit chunks
- **Step 5:** Uses mask `0xaaaaaaaa` and `0x55555555` to swap 1-bit chunks

**Final Result: 2684354560**

# 5. Missing Number

**Given an array** `nums` containing `n` integers in the range `[0, n]` without any duplicates, return the single number in the range that is missing from `nums`.

**Follow-up: Could you implement a solution using only** `O(1)` extra space complexity and `O(n)` runtime complexity?

**Example 1:**

```java
Input: nums = [1,2,3]
Output: 0
```

**Explanation: Since there are 3 numbers, the range is [0,3]. The missing number is 0 since it does not appear in nums.**

**Example 2:**

```java
Input: nums = [0,2]
Output: 1
```

**Constraints:**

- `1 <= nums.length <= 1000`

### Recommended Time & Space Complexity

You should aim for a solution with `O(n)` time and `O(1)` space, where `n` is the size of the input array.

**Hint 1** A brute force approach would iterate through the range of numbers from `0` to `n`, checking if each number is present in the given array. If a number is missing, it is returned. This results in an `O(n^2)` solution. Can you think of a better way? Maybe a data structure could help optimize this process.

**Hint 2** We can use a hash set by inserting the given array elements into it. Then, we iterate through the range of numbers from `0` to `n` and use the hash set for `O(1)` lookups to find the missing number. Can you think of a way to further optimize this? Maybe a bitwise operator could be useful.

**Hint 3** We can use bitwise XOR. When two identical numbers are XORed, the result is `0`. Using this property, we can efficiently find the missing number.

**Hint 4** We first compute the bitwise XOR of numbers from `0` to `n`. Then, we iterate through the array and XOR its elements as well. The missing number remains in the final XOR result since all other numbers appear twice—once in the range and once in the array—while the missing number is XORed only once.

---

## **1. Sorting**

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                return i;
            }
        }
        return n;
    }
};
```

**Time & Space Complexity**

- **Time complexity: O(n log n)**
- **Space complexity: O(1) or O(n) depending on the sorting algorithm.**

### Dry Run for Sorting (Example: nums = [1,2,3])

|Step|Action|nums|n|
|---|---|---|---|
|1|Initialize|[1,2,3]|3|
|2|Sort|[1,2,3]|3|

**For loop iteration:**

|i|nums[i]|i|nums[i] != i|Action|
|---|---|---|---|---|
|0|1|0|true|return 0|

**Final Result: 0**

---

## **2. Hash Set**

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i <= n; i++) {
            if (num_set.find(i) == num_set.end()) {
                return i;
            }
        }
        return -1;
    }
};
```

**Time & Space Complexity**

- **Time complexity: O(n)**
- **Space complexity: O(n)**

### Dry Run for Hash Set (Example: nums = [1,2,3])

|Step|Action|num_set|n|
|---|---|---|---|
|1|Initialize|{1,2,3}|3|

**For loop iteration:**

|i|num_set.find(i) == num_set.end()|Action|
|---|---|---|
|0|true|return 0|

**Final Result: 0**

---

## **3. Bitwise XOR**

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xorr = n;  
        for (int i = 0; i < n; i++) {
            xorr ^= i ^ nums[i];
        }
        return xorr;
    }
};
```

**Time & Space Complexity**

- **Time complexity: O(n)**
- **Space complexity: O(1)**

### Dry Run for Bitwise XOR (Example: nums = [1,2,3])

|Step|Action|n|xorr|
|---|---|---|---|
|1|Initialize|3|3|

**For loop iteration:**

|i|nums[i]|i ^ nums[i]|xorr before|xorr ^= (i ^ nums[i])|xorr after|
|---|---|---|---|---|---|
|0|1|1|3|3 ^ 1|2|
|1|2|3|2|2 ^ 3|1|
|2|3|1|1|1 ^ 1|0|

**Final Result: 0**

**XOR Logic:**

- Initial: xorr = 3
- XOR with all indices: 3 ^ 0 ^ 1 ^ 2 = 3 ^ 3 = 0
- XOR with all array elements: 0 ^ 1 ^ 2 ^ 3 = 0 ^ 6 = 6...
- Actually: xorr = 3 ^ (0^1) ^ (1^2) ^ (2^3) = 3 ^ 1 ^ 3 ^ 1 = 0

---

## **4. Math**

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            res += i - nums[i];
        }
        return res;
    }
};
```

**Time & Space Complexity**

- **Time complexity: O(n)**
- **Space complexity: O(1)**

### Dry Run for Math (Example: nums = [1,2,3])

|Step|Action|res|
|---|---|---|
|1|Initialize|3|

**For loop iteration:**

|i|nums[i]|i - nums[i]|res before|res += (i - nums[i])|res after|
|---|---|---|---|---|---|
|0|1|-1|3|3 + (-1)|2|
|1|2|-1|2|2 + (-1)|1|
|2|3|-1|1|1 + (-1)|0|

**Final Result: 0**

**Math Logic:**

- Expected sum of [0,1,2,3] = 0+1+2+3 = 6
- Actual sum of [1,2,3] = 1+2+3 = 6
- res = n + (sum of indices) - (sum of array) = 3 + (0+1+2) - (1+2+3) = 3 + 3 - 6 = 0

# 6. Sum of Two Integers

**Given two integers `a` and `b`, return the sum of the two integers without using the `+` and `-` operators.**

**Example 1:**

```java
Input: a = 1, b = 1
Output: 2
```

**Example 2:**

```java
Input: a = 4, b = 7
Output: 11
```

**Constraints:**

- `-1000 <= a, b <= 1000`

**Recommended Time & Space Complexity** You should aim for a solution with `O(1)` time and `O(1)` space.

**Hint 1** A brute force approach would use the addition operator. Can you think of a way to perform addition without using it? Maybe you should consider solving this using bit manipulation.

**Hint 2** We can use the bitwise XOR operator to perform addition. If both `a` and `b` have `1` at the same bit position, the sum at that position is `0`, and a carry of `1` is generated. If the bits are different, the sum at that position is `1`. Additionally, we account for the carry from the previous step in the next iteration.

**Hint 3** We iterate bit by bit from `0` to `31` since the given integers are 32-bit. We track the carry, initially set to `0`, and initialize the result as `res`. During iteration, the XOR of the bits at the `i`-th position of both integers and the carry determines the current bit of `res`. How can you handle negative numbers?

**Hint 4** To handle negative numbers, if the final result exceeds the maximum positive 32-bit integer, it means the number should be negative. We adjust it using bitwise operations: flipping the bits with `res ^ ((2 ^ 32) - 1)` and applying `~` to restore the correct two's complement representation. This ensures the result correctly represents signed 32-bit integers.

---

## **1. Brute Force**

```cpp
class Solution {
public:
    int getSum(int a, int b) {
        return a + b;
    }
};
```

**Time & Space Complexity**

- **Time complexity: O(1)**
- **Space complexity: O(1)**

### Dry Run Table for Brute Force:

|Input a|Input b|Output|
|---|---|---|
|1|1|2|
|4|7|11|

---

## **2. Bit Manipulation**

```cpp
class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0, res = 0, mask = 0xFFFFFFFF;

        for (int i = 0; i < 32; i++) {
            int a_bit = (a >> i) & 1;
            int b_bit = (b >> i) & 1;
            int cur_bit = a_bit ^ b_bit ^ carry;
            carry = (a_bit + b_bit + carry) >= 2 ? 1 : 0;
            if (cur_bit) {
                res |= (1 << i);
            }
        }

        if (res > 0x7FFFFFFF) {
            res = ~(res ^ mask);
        }
        
        return res;
    }
};
```

**Time & Space Complexity**

- **Time complexity: O(1)**
- **Space complexity: O(1)**

### Dry Run Table for Bit Manipulation (a = 4, b = 7):

|i|a_bit|b_bit|carry|cur_bit|res|carry_next|
|---|---|---|---|---|---|---|
|0|0|1|0|1|1|0|
|1|0|1|0|1|3|0|
|2|1|1|0|0|3|1|
|3|0|0|1|1|11|0|
|4-31|0|0|0|0|11|0|

Final result: 11

---

## **3. Bit Manipulation (Optimal)**

```cpp
class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int carry = (a & b) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};
```

**Time & Space Complexity**

- **Time complexity: O(1)**
- **Space complexity: O(1)**

### Dry Run Table for Optimal Bit Manipulation (a = 4, b = 7):

|Iteration|a (binary)|b (binary)|a & b|carry|a ^ b|New a|New b|
|---|---|---|---|---|---|---|---|
|Initial|100|111|-|-|-|4|7|
|1|100|111|100|1000|011|3|8|
|2|011|1000|0000|0000|1011|11|0|
|End|-|-|-|-|-|11|0|

Final result: 11

### Dry Run Table for Optimal Bit Manipulation (a = 1, b = 1):

|Iteration|a (binary)|b (binary)|a & b|carry|a ^ b|New a|New b|
|---|---|---|---|---|---|---|---|
|Initial|1|1|-|-|-|1|1|
|1|1|1|1|10|0|0|2|
|2|0|10|00|00|10|2|0|
|End|-|-|-|-|-|2|0|

Final result: 2

# 7. Reverse Integer

**You are given a signed 32-bit integer `x`.**

**Return `x` after reversing each of its digits. After reversing, if `x` goes outside the signed 32-bit integer range `[-2^31, 2^31 - 1]`, then return `0` instead.**

**Solve the problem without using integers that are outside the signed 32-bit integer range.**

**Example 1:**

```java
Input: x = 1234
Output: 4321
```

**Example 2:**

```java
Input: x = -1234
Output: -4321
```

**Example 3:**

```java
Input: x = 1234236467
Output: 0
```

**Constraints:**

- `-2^31 <= x <= 2^31 - 1`

**Recommended Time & Space Complexity** You should aim for a solution with `O(1)` time and `O(1)` space.

**Hint 1** A straightforward approach would be to convert the given integer to a string, reverse it, convert it back to an integer using a long type, and return 0 if the result exceeds the integer range. Can you think of a better way?

**Hint 2** We initially declare the result `res` as an `int` with a value of `0`. We iterate through the given integer, extracting digits one by one. Before appending a digit to `res`, we consider multiple cases. Can you determine them? Maybe you should think about overflow.

**Hint 3** Let `MAX` be the maximum positive integer and `MIN` be the minimum negative integer. We iterate through each digit and check for overflow before updating `res`. If `res > MAX / 10` or `res < MIN / 10`, return `0`. If `res == MAX / 10` and the current digit is greater than `MAX % 10`, return `0`. If `res == MIN / 10` and the current digit is less than `MIN % 10`, return `0`. Otherwise, append the digit to `res` and continue.

---

## **1. Brute Force**

```cpp
class Solution {
public:
    int reverse(int x) {
        int org = x;
        x = abs(x);
        string strX = to_string(x);
        std::reverse(strX.begin(), strX.end());
        long long res = stoll(strX); 
        if (org < 0) {
            res *= -1;
        }
        if (res < -(1LL << 31) || res > (1LL << 31) - 1) {
            return 0;
        }
        return static_cast<int>(res);
    }
};
```

**Time & Space Complexity**

- **Time complexity: O(1)**
- **Space complexity: O(1)**

### Dry Run Table for Brute Force (x = 1234):

|Step|Variable|Value|
|---|---|---|
|Initial|x|1234|
|Initial|org|1234|
|abs(x)|x|1234|
|to_string(x)|strX|"1234"|
|reverse|strX|"4321"|
|stoll|res|4321|
|org < 0 check|res|4321 (no change)|
|Range check|res|4321 (within range)|
|Final return|-|4321|

### Dry Run Table for Brute Force (x = -1234):

|Step|Variable|Value|
|---|---|---|
|Initial|x|-1234|
|Initial|org|-1234|
|abs(x)|x|1234|
|to_string(x)|strX|"1234"|
|reverse|strX|"4321"|
|stoll|res|4321|
|org < 0 check|res|-4321|
|Range check|res|-4321 (within range)|
|Final return|-|-4321|

---

## **2. Recursion**

```cpp
class Solution {
public:
    int reverse(int x) {
        long res = rec(abs(x), 0) * (x < 0 ? -1 : 1);
        if (res < INT_MIN || res > INT_MAX) {
            return 0;
        }
        return (int)res;
    }

private:
    long rec(int n, long rev) {
        if (n == 0) {
            return rev;
        }
        rev = rev * 10 + n % 10;
        return rec(n / 10, rev);
    }
};
```

**Time & Space Complexity**

- **Time complexity: O(1)**
- **Space complexity: O(1)**

### Dry Run Table for Recursion (x = 1234):

|Call|n|rev|n % 10|rev * 10 + n % 10|n / 10|Return|
|---|---|---|---|---|---|---|
|rec(1234, 0)|1234|0|4|4|123|rec(123, 4)|
|rec(123, 4)|123|4|3|43|12|rec(12, 43)|
|rec(12, 43)|12|43|2|432|1|rec(1, 432)|
|rec(1, 432)|1|432|1|4321|0|rec(0, 4321)|
|rec(0, 4321)|0|4321|-|-|-|4321|

Final result: 4321 * 1 = 4321

---

## **3. Iteration**

```cpp
class Solution {
public:
    int reverse(int x) {
        const int MIN = -2147483648; // -2^31
        const int MAX = 2147483647;  // 2^31 - 1

        int res = 0;
        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            if (res > MAX / 10 || (res == MAX / 10 && digit > MAX % 10))
                return 0;
            if (res < MIN / 10 || (res == MIN / 10 && digit < MIN % 10))
                return 0;
            res = (res * 10) + digit;
        }

        return res;
    }
};
```

**Time & Space Complexity**

- **Time complexity: O(1)**
- **Space complexity: O(1)**

### Dry Run Table for Iteration (x = 1234):

|Iteration|x|digit|res|MAX/10|MIN/10|Overflow Check|res * 10 + digit|
|---|---|---|---|---|---|---|---|
|Initial|1234|-|0|214748364|-214748364|-|-|
|1|123|4|0|214748364|-214748364|Pass|4|
|2|12|3|4|214748364|-214748364|Pass|43|
|3|1|2|43|214748364|-214748364|Pass|432|
|4|0|1|432|214748364|-214748364|Pass|4321|

Final result: 4321

### Dry Run Table for Iteration (x = -1234):

|Iteration|x|digit|res|MAX/10|MIN/10|Overflow Check|res * 10 + digit|
|---|---|---|---|---|---|---|---|
|Initial|-1234|-|0|214748364|-214748364|-|-|
|1|-123|-4|0|214748364|-214748364|Pass|-4|
|2|-12|-3|-4|214748364|-214748364|Pass|-43|
|3|-1|-2|-43|214748364|-214748364|Pass|-432|
|4|0|-1|-432|214748364|-214748364|Pass|-4321|

Final result: -4321

### Dry Run Table for Iteration (x = 1234236467):

|Iteration|x|digit|res|MAX/10|MIN/10|Overflow Check|Result|
|---|---|---|---|---|---|---|---|
|Initial|1234236467|-|0|214748364|-214748364|-|-|
|1|123423646|7|0|214748364|-214748364|Pass|7|
|2|12342364|6|7|214748364|-214748364|Pass|76|
|3|1234236|4|76|214748364|-214748364|Pass|764|
|4|123423|6|764|214748364|-214748364|Pass|7646|
|5|12342|3|7646|214748364|-214748364|Pass|76463|
|6|1234|2|76463|214748364|-214748364|Pass|764632|
|7|123|4|764632|214748364|-214748364|Pass|7646324|
|8|12|3|7646324|214748364|-214748364|Pass|76463243|
|9|1|2|76463243|214748364|-214748364|Pass|764632432|
|10|0|1|764632432|214748364|-214748364|Overflow!|0|

Final result: 0 (overflow detected)