PPT
![](../pics/WhatsApp%20Image%202025-07-18%20at%2012.14.39_30fb8bd5.jpg)
![](../pics/WhatsApp%20Image%202025-07-18%20at%2012.14.44_2507d2fd.jpg)
![](../pics/WhatsApp%20Image%202025-07-18%20at%2012.17.49_cfecf7f2.jpg)
![](../pics/WhatsApp%20Image%202025-07-18%20at%2012.19.02_f9389c1d.jpg)
![](../pics/WhatsApp%20Image%202025-07-18%20at%2012.20.39_38c8aa42.jpg)
![](../pics/Pasted%20image%2020250718122212.png)
![](../pics/Pasted%20image%2020250718122528.png)
![](../pics/Pasted%20image%2020250718122626.png)
![](../pics/Pasted%20image%2020250718122709.png)
![](../pics/Pasted%20image%2020250718122817.png)
![](../pics/Pasted%20image%2020250718122837.png)
![](../pics/Pasted%20image%2020250718122948.png)
![](../pics/Pasted%20image%2020250718123121.png)
![](../pics/Pasted%20image%2020250718123422.png)
![](../pics/Pasted%20image%2020250718123652.png)
![](../pics/Pasted%20image%2020250718123759.png)
![](../pics/Pasted%20image%2020250718123903.png)
![](../pics/Pasted%20image%2020250718124127.png)
![](../pics/Pasted%20image%2020250718124216.png)
![](../pics/Pasted%20image%2020250718124525.png)
![](../pics/Pasted%20image%2020250718124900.png)
![](../pics/Pasted%20image%2020250718125020.png)


Leetcode Questions
https://nextleet.com/sheet/zs-associates

## Product of Array Except Itself
https://leetcode.com/problems/product-of-array-except-self/
✅ 1. Brute Force 🔹 Time: O(n²) 🔹 Space: O(1) extra, O(n) result

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        
        for (int i = 0; i < n; i++) {
            int prod = 1;
            for (int j = 0; j < n; j++) {
                if (i != j) prod *= nums[j];
            }
            res[i] = prod;
        }
        return res;
    }
};
```

🧪 Dry Run for Input: `[1, 2, 3, 4]`

|i|Loop (j)|Elements Used|Product|res[i]|
|---|---|---|---|---|
|0|j=1,2,3|2×3×4|24|24|
|1|j=0,2,3|1×3×4|12|12|
|2|j=0,1,3|1×2×4|8|8|
|3|j=0,1,2|1×2×3|6|6|

🔚 Output: `[24, 12, 8, 6]`

✅ 2. Division (with Zero Handling) 🔹 Time: O(n) 🔹 Space: O(1) extra, O(n) result

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1, zeroCount = 0;
        
        for (int num : nums) {
            if (num != 0) prod *= num;
            else zeroCount++;
        }
        
        int n = nums.size();
        vector<int> res(n);
        
        if (zeroCount > 1) return vector<int>(n, 0);
        
        for (int i = 0; i < n; i++) {
            if (zeroCount == 1) 
                res[i] = (nums[i] == 0) ? prod : 0;
            else 
                res[i] = prod / nums[i];
        }
        return res;
    }
};
```

🧪 Dry Run for Input: `[1, 2, 3, 4]`

|i|Total Product|nums[i]|res[i] = prod / nums[i]|
|---|---|---|---|
|-|24|-|-|
|0|24|1|24 / 1 = 24|
|1|24|2|24 / 2 = 12|
|2|24|3|24 / 3 = 8|
|3|24|4|24 / 4 = 6|

🔚 Output: `[24, 12, 8, 6]` ⚠️ Handles zero safely → if 1 zero, only that index gets product, rest are 0.

✅ 3. Prefix & Suffix Arrays 🔹 Time: O(n) 🔹 Space: O(n) extra

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n), pref(n), suff(n);
        
        pref[0] = 1, suff[n - 1] = 1;
        
        for (int i = 1; i < n; i++) 
            pref[i] = pref[i - 1] * nums[i - 1];
        
        for (int i = n - 2; i >= 0; i--) 
            suff[i] = suff[i + 1] * nums[i + 1];
        
        for (int i = 0; i < n; i++) 
            res[i] = pref[i] * suff[i];
        
        return res;
    }
};
```

🧪 Dry Run for Input: `[1, 2, 3, 4]`

**Step 1: Prefix Array**

|i|pref[i] = pref[i-1] × nums[i-1]|Value|
|---|---|---|
|0|- (base)|1|
|1|1 × 1|1|
|2|1 × 2|2|
|3|2 × 3|6|

→ `pref = [1, 1, 2, 6]`

**Step 2: Suffix Array**

|i|suff[i] = suff[i+1] × nums[i+1]|Value|
|---|---|---|
|3|- (base)|1|
|2|1 × 4|4|
|1|4 × 3|12|
|0|12 × 2|24|

→ `suff = [24, 12, 4, 1]`

**Step 3: Final Result**

|i|res[i] = pref[i] × suff[i]|
|---|---|
|0|1 × 24 = 24|
|1|1 × 12 = 12|
|2|2 × 4 = 8|
|3|6 × 1 = 6|

🔚 Output: `[24, 12, 8, 6]`

✅ 4. Optimized Prefix & Suffix (No Extra Arrays) 🔹 Time: O(n) 🔹 Space: O(1) extra

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        
        for (int i = 1; i < n; i++) 
            res[i] = res[i - 1] * nums[i - 1];
        
        int postfix = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= postfix;
            postfix *= nums[i];
        }
        return res;
    }
};
```

🧪 Dry Run for Input: `[1, 2, 3, 4]`

**Step 1: Left Pass (Prefix Product in **`res`)

|i|res[i]|curr|
|---|---|---|
|0|1|1|
|1|1 × 1 = 1|1×1=1|
|2|1 × 2 = 2|1×2=2|
|3|2 × 3 = 6|2×3=6|

→ `res = [1, 1, 2, 6]`

**Step 2: Right Pass (Postfix Multiplication)**

|i|res[i] × postfix|postfix after|
|---|---|---|
|3|6 × 1 = 6|1×4 = 4|
|2|2 × 4 = 8|4×3 = 12|
|1|1 × 12 = 12|12×2 = 24|
|0|1 × 24 = 24|24×1 = 24|

🔚 Final Output: `[24, 12, 8, 6]`


![](../pics/Product%20of%20Array%20Except%20Self%20(LeetCode%20238)%20_%20Full%20solution%20with%20visuals%20_%20Study%20Algorithms%206-26%20screenshot.png)
![](../pics/Product%20of%20Array%20Except%20Self%20(LeetCode%20238)%20_%20Full%20solution%20with%20visuals%20_%20Study%20Algorithms%208-28%20screenshot.png)
![](../pics/Product%20of%20Array%20Except%20Self%20(LeetCode%20238)%20_%20Full%20solution%20with%20visuals%20_%20Study%20Algorithms%2010-17%20screenshot.png)
![](../pics/Product%20of%20Array%20Except%20Self%20(LeetCode%20238)%20_%20Full%20solution%20with%20visuals%20_%20Study%20Algorithms%2010-45%20screenshot.png)
![](../pics/Product%20of%20Array%20Except%20Self%20(LeetCode%20238)%20_%20Full%20solution%20with%20visuals%20_%20Study%20Algorithms%2012-34%20screenshot.png)

https://leetcode.com/problems/distribute-candies-among-children-ii/
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> result;

        // Always include the first word
        result.push_back(words[0]);
        int lastGroup = groups[0];

        // Greedily take the next word only if group differs
        for (int i = 1; i < words.size(); ++i) {
            if (groups[i] != lastGroup) {
                result.push_back(words[i]);
                lastGroup = groups[i]; // Update group tracker
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"a", "b", "c", "d"};
    vector<int> groups = {1, 0, 1, 1};

    vector<string> result = sol.getLongestSubsequence(words, groups);

    cout << "Longest alternating subsequence: ";
    for (string word : result) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
```

words  = ["a", "b", "c", "d"]
groups = [ 1 ,  0 ,  1 ,  1 ]

| Step | i   | words[i] | groups[i] | lastGroup | groups[i] != lastGroup? | Action          | res             |
| ---- | --- | -------- | --------- | --------- | ----------------------- | --------------- | --------------- |
| Init | -   | "a"      | 1         | —         | —                       | Push first word | ["a"]           |
| 1    | 1   | "b"      | 0         | 1         | ✅ Yes                   | Push "b"        | ["a", "b"]      |
| 2    | 2   | "c"      | 1         | 0         | ✅ Yes                   | Push "c"        | ["a", "b", "c"] |
| 3    | 3   | "d"      | 1         | 1         | ❌ No                    | Skip "d"        | ["a", "b", "c"] |

https://leetcode.com/problems/longest-harmonious-subsequence/

> A **harmonious subsequence** is a subsequence where the difference between the maximum and minimum values is exactly **1**.  
> Return the **length of the longest** such subsequence.

## ✅ Approach 1: Using `unordered_map` (Frequency Map)
```cpp
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        int result = 0;

        // Count frequency of each number
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        // For each number, check if number + 1 exists
        for (int j = 0; j < nums.size(); j++) {
            int minNum = nums[j];
            int maxNum = nums[j] + 1;

            if (mp.count(maxNum)) {
                result = max(result, mp[minNum] + mp[maxNum]);
            }
        }

        return result;
    }
};
```
### 🧪 Dry Run Example:
Input:
`nums = [1, 3, 2, 2, 5, 2, 3, 7]`
### 🗃 Frequency Map:
|Number|Frequency|
|---|---|
|1|1|
|2|3|
|3|2|
|5|1|
|7|1|
### 🔁 Loop Over Map:
|key|key+1 exists?|mp[key]|mp[key+1]|sum|result (max)|
|---|---|---|---|---|---|
|1|Yes (2)|1|3|4|4|
|2|Yes (3)|3|2|5 ✅|5|
|3|No (4)|-|-|-|5|
|5|No (6)|-|-|-|5|
|7|No (8)|-|-|-|5|
### ✅ Final Output: `5`

## ✅ Approach 2: Two Pointer with Sorting

```cpp
class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int start = 0, maxlength = 0;

        for (int end = 0; end < nums.size(); end++) {
            while (nums[end] - nums[start] > 1) {
                start++;
            }
            if (nums[end] - nums[start] == 1) {
                maxlength = max(maxlength, end - start + 1);
            }
        }

        return maxlength;
    }
};
```
##### 🧪 Dry Run on `nums = [1, 3, 2, 2, 5, 2, 3, 7]`
###### 🔃 After Sorting:
`nums = [1, 2, 2, 2, 3, 3, 5, 7]`

| end | nums[end] | nums[start] | diff | Action            | maxLen |
| --- | --------- | ----------- | ---- | ----------------- | ------ |
| 0   | 1         | 1           | 0    | not 1 → skip      | 0      |
| 1   | 2         | 1           | 1    | ✅ update maxLen=2 | 2      |
| 2   | 2         | 1           | 1    | ✅ update maxLen=3 | 3      |
| 3   | 2         | 1           | 1    | ✅ update maxLen=4 | 4      |
| 4   | 3         | 1           | 2    | ❌ → shift start=2 | 4      |
|     | 3         | 2           | 1    | ✅ update maxLen=4 | 4      |
| 5   | 3         | 2           | 1    | ✅ update maxLen=4 | 4      |
| 6   | 5         | 2           | 3    | ❌ shift start→4→5 | -      |
|     | 5         | 3           | 2    | ❌ shift start=6   | -      |
| 7   | 7         | 5           | 2    | ❌ skip            | 4      |
### ✅ Final Output: `5`

|Approach|Time|Space|Best For|
|---|---|---|---|
|Hash Map|O(n)|O(n)|Simple & efficient|
|Two Pointer Sort|O(n log n)|O(1)|If space optimization is needed|
[1598. Crawler Log Folder](https://leetcode.com/problems/crawler-log-folder/)

The Leetcode file system keeps a log each time some user performs a _change folder_ operation.

The operations are described below:

- `"../"` : Move to the parent folder of the current folder. (If you are already in the main folder, **remain in the same folder**).
- `"./"` : Remain in the same folder.
- `"x/"` : Move to the child folder named `x` (This folder is **guaranteed to always exist**).

You are given a list of strings `logs` where `logs[i]` is the operation performed by the user at the `ith` step.

The file system starts in the main folder, then the operations in `logs` are performed.

Return _the minimum number of operations needed to go back to the main folder after the change folder operations._

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/09/09/sample_11_1957.png)

**Input:** logs = ["d1/","d2/","../","d21/","./"]
**Output:** 2
**Explanation:** Use this change folder operation "../" 2 times and go back to the main folder.

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/09/09/sample_22_1957.png)

**Input:** logs = ["d1/","d2/","./","d3/","../","d31/"]
**Output:** 3

**Example 3:**

**Input:** logs = ["d1/","../","../","../"]
**Output:** 0

## 🔸Method 1: Using `int depth` (Optimal & clean)
```cpp
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        for (string &s : logs) {
            if (s == "../") {
                depth = max(0, depth - 1);  // Go up only if not at root
            } else if (s == "./") {
                continue;                  // Stay in the same directory
            } else {
                depth++;                   // Go into a subdirectory
            }
        }
        return depth;
    }
};
```

- ⏱ Time: `O(n)`
- 📦 Space: `O(1)`
- ✅ Most efficient

## ✅ Input Example
logs = ["d1/", "d2/", "../", "d21/", "./"]

| Step | Operation | Explanation                            | Depth |
| ---- | --------- | -------------------------------------- | ----- |
| 1    | "d1/"     | Go into a folder → depth++             | 1     |
| 2    | "d2/"     | Go into a folder → depth++             | 2     |
| 3    | "../"     | Go back to parent → depth--            | 1     |
| 4    | "d21/"    | Go into a folder → depth++             | 2     |
| 5    | "./"      | Stay in the current folder → no change | 2     |
```cpp
class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;

        for (const string& op : logs) {
            if (op == "../") {
                if (!st.empty()) {
                    st.pop();  // Move one folder up
                }
            } else if (op != "./") {
                st.push(op);    // Go into a new directory
            }
        }
        return st.size();  // Depth equals stack size
    }
};
```

logs = ["d1/", "d2/", "../", "d21/", "./"]

| Step | Operation | Stack Before    | Action                    | Stack After     |
| ---- | --------- | --------------- | ------------------------- | --------------- |
| 1    | "d1/"     | []              | push "d1/"                | ["d1/"]         |
| 2    | "d2/"     | ["d1/"]         | push "d2/"                | ["d1/", "d2/"]  |
| 3    | "../"     | ["d1/", "d2/"]  | pop (go to parent folder) | ["d1/"]         |
| 4    | "d21/"    | ["d1/"]         | push "d21/"               | ["d1/", "d21/"] |
| 5    | "./"      | ["d1/", "d21/"] | no action                 | ["d1/", "d21/"] |
https://leetcode.com/problems/largest-1-bordered-square/description/
## Problem Description

- Given an event from time 0 to `eventTime`
- `n` non-overlapping meetings with start and end times
- Can reschedule at most `k` meetings while maintaining same duration and relative order
- Goal: maximize the longest continuous period of free time

## Approach (Sliding Window)

The key insight is that if we can move `k` meetings, we can consolidate `k+1` free time gaps into one continuous block. We use sliding window to find the maximum sum of any `k+1` consecutive gaps.

**Time Complexity:** O(n)  
**Space Complexity:** O(k)

```cpp
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeArray; //store durations of free gaps

        //ith event
        //ith start - i-1th ka end = free gap duration
        freeArray.push_back(startTime[0]);

        for(int i = 1; i < startTime.size(); i++) {
            freeArray.push_back(startTime[i] - endTime[i-1]);
        }

        freeArray.push_back(eventTime - endTime[endTime.size()-1]);

        //Khandani sliding window

        int i = 0;
        int j = 0;
        int maxSum = 0;
        int currSum = 0;

        int n = freeArray.size();
        while(j < n) {
            currSum += freeArray[j];

            if(i < n && j-i+1 > k+1) {
                currSum -= freeArray[i];
                i++;
            }

            maxSum = max(maxSum, currSum);
            j++;
        }

        return maxSum;
    }
};
```
## Dry Run Example

✅ **Inputs:**

```cpp
eventTime = 5, k = 1, startTime = [1, 3], endTime = [2, 5]
```
![](../pics/Pasted%20image%2020250709203947.png)
🔹 **STEP 1: Construct `freeArray`** We compute the gaps (free time) **before, between, and after meetings**.

📊 **Table: `freeArray` construction**

| Step               | Value                               | Explanation               |
| ------------------ | ----------------------------------- | ------------------------- |
| Before 1st meeting | `startTime[0] = 1`                  | Free time from 0 to 1     |
| Between meetings   | `startTime[1] - endTime[0] = 3 - 2` | Free time from 2 to 3     |
| After last meeting | `eventTime - endTime[1] = 5 - 5`    | Free time from 5 to 5 → 0 |

✅ **`freeArray = [1, 1, 0]`** (Total 3 free blocks)

🔹 **STEP 2: Sliding Window Logic** We use a sliding window of size **(k+1 = 2)** to find the **maximum sum** of any 2 free blocks.

🧠 **Goal:** Find the **maximum sum** of **any window of size ≤ 2** in `[1, 1, 0]`

🔁 **Dry Run Table (with sliding window)**

|i|j|freeArray[j]|currSum before|Action taken|currSum after|maxSum|
|---|---|---|---|---|---|---|
|0|0|1|0|Add 1 to currSum|1|1|
|0|1|1|1|Add 1 to currSum|2|2|
|1|2|0|2|Add 0 to currSum → window size = 3 > 2 → Subtract freeArray[0] = 1|1|2|
|-|3|-|-|Loop ends (j = 3 = n)|-|2|

📝 **Text Walkthrough**

1. `i = 0, j = 0`: Add `freeArray[0] = 1` → `currSum = 1` → maxSum becomes 1
2. `i = 0, j = 1`: Add `freeArray[1] = 1` → `currSum = 2` → maxSum becomes 2
3. `i = 0, j = 2`: Add `freeArray[2] = 0` → Window size = 3 → subtract `freeArray[0] = 1`, `i = 1`, `currSum = 1`
4. Loop ends (as `j = 3`), final `maxSum = 2`

✅ **Final Output:**

```cpp
return 2; // Maximum free time after rescheduling at most k=1 meeting
```