# 1. Insert Interval

**You are given an array of non-overlapping intervals** `intervals` where `intervals[i] = [start_i, end_i]` represents the start and the end time of the `ith` interval. `intervals` is initially sorted in ascending order by `start_i`.

**You are given another interval** `newInterval = [start, end]`.

**Insert** `newInterval` into `intervals` such that `intervals` is still sorted in ascending order by `start_i` and also `intervals` still does not have any overlapping intervals. You may merge the overlapping intervals if needed.

**Return** `intervals` after adding `newInterval`.

**Note: Intervals are _****non-overlapping****_ if they have no common point. For example, [1,2] and [3,4] are non-overlapping, but [1,2] and [2,3] are overlapping.**

**Example 1:**

```java
Input: intervals = [[1,3],[4,6]], newInterval = [2,5]
Output: [[1,6]]
```

**Example 2:**

```java
Input: intervals = [[1,2],[3,5],[9,10]], newInterval = [6,7]
Output: [[1,2],[3,5],[6,7],[9,10]]
```

**Constraints:**

- `0 <= intervals.length <= 1000`
- `newInterval.length == intervals[i].length == 2`
- `0 <= start <= end <= 1000`

## Recommended Time & Space Complexity

You should aim for a solution with `O(n)` time and `O(1)` extra space, where `n` is the size of the input array.

## Hint 1

The given intervals are non-overlapping and sorted in ascending order based on the start value. Try to visualize them as line segments and consider how a new interval can be inserted. Maybe you should analyze different cases of inserting a new interval.

## Hint 2

First, we append all intervals to the output list that have an end value smaller than the start value of the new interval. Then, we encounter one of three cases: we have appended all intervals, we reach an interval whose start value is greater than the new interval's end, or we find an overlapping interval. Can you think of a way to handle these cases efficiently?

## Hint 3

We iterate through the remaining intervals, updating the new interval if its end value is greater than or equal to the current interval's start value. We adjust the start and end of the new interval to the minimum and maximum values, respectively. After this, any remaining intervals are appended to the output list, and we return the result.

---

## **1. Linear Search**

```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(), i = 0;
        vector<vector<int>> res;

        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }

        while (i < n && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);

        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};
```

### **Dry Run:**

**Input:** `intervals = [[1,3],[4,6]]`, `newInterval = [2,5]`

|Step|i|Current Interval|Action|res|newInterval|
|---|---|---|---|---|---|
|1|0|[1,3]|intervals[0][1]=3 >= newInterval[0]=2, exit first loop|[]|[2,5]|
|2|0|[1,3]|newInterval[1]=5 >= intervals[0][0]=1, merge|[]|[1,5]|
|3|1|[4,6]|newInterval[1]=5 >= intervals[1][0]=4, merge|[]|[1,6]|
|4|2|-|i >= n, exit second loop|[]|[1,6]|
|5|-|-|Add newInterval to res|[[1,6]]|[1,6]|

**Output:** `[[1,6]]`

**Time & Space Complexity:**

- **Time complexity: O(n)**
- **Space complexity:**
    - **O(1) extra space.**
    - **O(n) space for the output list.**

---

## **2. Binary Search**

```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) {
            return {newInterval};
        }

        int n = intervals.size();
        int target = newInterval[0];
        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (intervals[mid][0] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        intervals.insert(intervals.begin() + left, newInterval);

        vector<vector<int>> res;
        for (const auto& interval : intervals) {
            if (res.empty() || res.back()[1] < interval[0]) {
                res.push_back(interval);
            } else {
                res.back()[1] = max(res.back()[1], interval[1]);
            }
        }

        return res;
    }
};
```

### **Dry Run:**

**Input:** `intervals = [[1,3],[4,6]]`, `newInterval = [2,5]`

|Step|left|right|mid|intervals[mid][0]|Action|
|---|---|---|---|---|---|
|1|0|1|0|1|1 < 2, left = 1|
|2|1|1|1|4|4 >= 2, right = 0|
|3|1|0|-|-|left > right, exit|

Insert `[2,5]` at position 1: `intervals = [[1,3],[2,5],[4,6]]`

|Step|Current Interval|res.back()|Action|res|
|---|---|---|---|---|
|1|[1,3]|-|res empty, add|[[1,3]]|
|2|[2,5]|[1,3]|res.back()[1]=3 >= interval[0]=2, merge|[[1,5]]|
|3|[4,6]|[1,5]|res.back()[1]=5 >= interval[0]=4, merge|[[1,6]]|

**Output:** `[[1,6]]`

**Time & Space Complexity:**

- **Time complexity: O(n)**
- **Space complexity:**
    - **O(1) extra space.**
    - **O(n) space for the output list.**

---

## **3. Greedy**

```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int newStart = newInterval[0];
        int newEnd = newInterval[1];
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            if (intervals[i][0] > newEnd) {
                res.push_back(newInterval);
                copy(intervals.begin() + i, intervals.end(), back_inserter(res));
                return res;
            } else if (intervals[i][1] < newStart) {
                res.push_back(intervals[i]);
            } else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        res.push_back(newInterval);
        return res;
    }
};
```

### **Dry Run:**

**Input:** `intervals = [[1,3],[4,6]]`, `newInterval = [2,5]`

|Step|i|Current Interval|Condition Check|Action|res|newInterval|
|---|---|---|---|---|---|---|
|1|0|[1,3]|intervals[0][0]=1 <= newEnd=5|Check next condition|[]|[2,5]|
|2|0|[1,3]|intervals[0][1]=3 >= newStart=2|Merge intervals|[]|[1,5]|
|3|1|[4,6]|intervals[1][0]=4 <= newEnd=5|Check next condition|[]|[1,5]|
|4|1|[4,6]|intervals[1][1]=6 >= newStart=1|Merge intervals|[]|[1,6]|
|5|-|-|Loop ends, add newInterval|[[1,6]]|[1,6]||

**Output:** `[[1,6]]`

**Time & Space Complexity:**

- **Time complexity: O(n)**
- **Space complexity:**
    - **O(1) extra space.**
    - **O(n) space for the output list.**

# 2. Merge Intervals

**Given an array of** `intervals` where `intervals[i] = [start_i, end_i]`, merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

**You may return the answer in any order.**

**Note: Intervals are _****non-overlapping****_ if they have no common point. For example,** `[1, 2]` and `[3, 4]` are non-overlapping, but `[1, 2]` and `[2, 3]` are overlapping.

**Example 1:**

```java
Input: intervals = [[1,3],[1,5],[6,7]]
Output: [[1,5],[6,7]]
```

**Example 2:**

```java
Input: intervals = [[1,2],[2,3]]
Output: [[1,3]]
```

**Constraints:**

- `1 <= intervals.length <= 1000`
- `intervals[i].length == 2`
- `0 <= start <= end <= 1000`

## Recommended Time & Space Complexity

You should aim for a solution as good or better than `O(nlogn)` time and `O(n)` space, where `n` is the size of the input array.

## Hint 1

Sorting the given intervals in ascending order based on their start values is beneficial, as it helps in identifying overlapping intervals efficiently. How can you determine if two intervals overlap?

## Hint 2

If two intervals are sorted in ascending order by their start values, they overlap if the start value of the second interval is less than or equal to the end value of the first interval.

## Hint 3

We iterate through the sorted intervals from left to right, starting with the first interval in the output list. From the second interval onward, we compare each interval with the last appended interval. Can you determine the possible cases for this comparison?

## Hint 4

The two cases are: if the current interval overlaps with the last appended interval, we update its end value to the maximum of both intervals' end values and continue. Otherwise, we append the current interval and proceed.

---

## **1. Sorting**

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        output.push_back(intervals[0]);

        for (auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            int lastEnd = output.back()[1];

            if (start <= lastEnd) {
                output.back()[1] = max(lastEnd, end);
            } else {
                output.push_back({start, end});
            }
        }
        return output;
    }
};
```

### **Dry Run:**

**Input:** `intervals = [[1,3],[1,5],[6,7]]`

**After sorting:** `[[1,3],[1,5],[6,7]]`

|Step|Current Interval|output|lastEnd|start <= lastEnd?|Action|output|
|---|---|---|---|---|---|---|
|Init|-|[]|-|-|Add intervals[0]|[[1,3]]|
|1|[1,3]|[[1,3]]|3|1 <= 3 ✓|Merge: max(3,3)|[[1,3]]|
|2|[1,5]|[[1,3]]|3|1 <= 3 ✓|Merge: max(3,5)|[[1,5]]|
|3|[6,7]|[[1,5]]|5|6 <= 5 ✗|Add new interval|[[1,5],[6,7]]|

**Output:** `[[1,5],[6,7]]`

**Time & Space Complexity:**

- **Time complexity: O(nlogn)**
- **Space complexity:**
    - **O(1) or O(n) space depending on the sorting algorithm.**
    - **O(n) for the output list.**

---

## **2. Sweep Line Algorithm**

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int, int> mp;
        for (const auto& interval : intervals) {
            mp[interval[0]]++;
            mp[interval[1]]--;
        }

        vector<vector<int>> res;
        vector<int> interval;
        int have = 0;
        for (const auto& [i, count] : mp) {
            if (interval.empty()) {
                interval.push_back(i);
            }
            have += count;
            if (have == 0) {
                interval.push_back(i);
                res.push_back(interval);
                interval.clear();
            }
        }
        return res;
    }
};
```

### **Dry Run:**

**Input:** `intervals = [[1,3],[1,5],[6,7]]`

**Build map:**

|Position|Count|mp|
|---|---|---|
|1|+1|{1: 1}|
|3|-1|{1: 1, 3: -1}|
|1|+1|{1: 2, 3: -1}|
|5|-1|{1: 2, 3: -1, 5: -1}|
|6|+1|{1: 2, 3: -1, 5: -1, 6: 1}|
|7|-1|{1: 2, 3: -1, 5: -1, 6: 1, 7: -1}|

**Process events:**

|Position|Count|have|interval|have == 0?|Action|res|
|---|---|---|---|---|---|---|
|1|2|2|[1]|No|Continue|[]|
|3|-1|1|[1]|No|Continue|[]|
|5|-1|0|[1]|Yes|Add [1,5]|[[1,5]]|
|6|1|1|[6]|No|Continue|[[1,5]]|
|7|-1|0|[6]|Yes|Add [6,7]|[[1,5],[6,7]]|

**Output:** `[[1,5],[6,7]]`

**Time & Space Complexity:**

- **Time complexity: O(nlogn)**
- **Space complexity: O(n)**

---

## **3. Greedy**

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int max_val = 0;
        for (const auto& interval : intervals) {
            max_val = max(interval[0], max_val);
        }

        vector<int> mp(max_val + 1, 0);
        for (const auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            mp[start] = max(end + 1, mp[start]);
        }

        vector<vector<int>> res;
        int have = -1;
        int intervalStart = -1;
        for (int i = 0; i < mp.size(); i++) {
            if (mp[i] != 0) {
                if (intervalStart == -1) intervalStart = i;
                have = max(mp[i] - 1, have);
            }
            if (have == i) {
                res.push_back({intervalStart, have});
                have = -1;
                intervalStart = -1;
            }
        }

        if (intervalStart != -1) {
            res.push_back({intervalStart, have});
        }

        return res;
    }
};
```

### **Dry Run:**

**Input:** `intervals = [[1,3],[1,5],[6,7]]`

**Find max_val:** `max_val = 6`

**Build mp array (size 7):**

|Interval|start|end|mp[start]|Action|
|---|---|---|---|---|
|[1,3]|1|3|mp[1] = max(4, 0)|mp[1] = 4|
|[1,5]|1|5|mp[1] = max(6, 4)|mp[1] = 6|
|[6,7]|6|7|mp[6] = max(8, 0)|mp[6] = 8|

**Final mp:** `[0, 6, 0, 0, 0, 0, 8]`

**Process array:**

|i|mp[i]|intervalStart|have|have == i?|Action|res|
|---|---|---|---|---|---|---|
|0|0|-1|-1|No|Continue|[]|
|1|6|1|5|No|Continue|[]|
|2|0|1|5|No|Continue|[]|
|3|0|1|5|No|Continue|[]|
|4|0|1|5|No|Continue|[]|
|5|0|1|5|Yes|Add [1,5]|[[1,5]]|
|6|8|6|7|No|Continue|[[1,5]]|

**Final check:** `intervalStart = 6, have = 7` → Add `[6,7]`

**Output:** `[[1,5],[6,7]]`

**Time & Space Complexity:**

- **Time complexity: O(n+m)**
- **Space complexity: O(n)**

**Where n is the length of the array and m is the maximum start value among all the intervals.**

# 3. Non-overlapping Intervals

**Given an array of intervals** `intervals` where `intervals[i] = [start_i, end_i]`, return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

**Note: Intervals are _****non-overlapping****_ even if they have a common point. For example,** `[1, 3]` and `[2, 4]` are overlapping, but `[1, 2]` and `[2, 3]` are non-overlapping.

**Example 1:**

```java
Input: intervals = [[1,2],[2,4],[1,4]]
Output: 1
```

**Explanation: After [1,4] is removed, the rest of the intervals are non-overlapping.**

**Example 2:**

```java
Input: intervals = [[1,2],[2,4]]
Output: 0
```

**Constraints:**

- `1 <= intervals.length <= 1000`
- `intervals[i].length == 2`
- `-50000 <= starti < endi <= 50000`

## Recommended Time & Space Complexity

You should aim for a solution with `O(nlogn)` time and `O(n)` space, where `n` is the size of the input array.

## Hint 1

If two intervals are sorted in ascending order by their start values, they overlap if the start value of the second interval is less than the end value of the first interval. And these are called overlapping intervals.

## Hint 2

A brute force approach would be to sort the given intervals in ascending order based on their start values and recursively explore all possibilities. This would be an exponential approach. Can you think of a better way? Maybe a greedy approach works here.

## Hint 3

We first sort the given intervals based on their start values to efficiently check for overlaps by comparing adjacent intervals. We then iterate through the sorted intervals from left to right, keeping track of the previous interval's end value as `prevEnd`, initially set to the end value of the first interval.

## Hint 4

We then iterate from the second interval. If the current interval doesn't overlap, we update `prevEnd` to the current interval's end and continue. Otherwise, we set `prevEnd` to the minimum of `prevEnd` and the current interval's end, greedily removing the interval that ends last to retain as many intervals as possible.

---

## **1. Recursion**

```cpp
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        return intervals.size() - dfs(intervals, 0, -1);
    }

private:
    int dfs(const vector<vector<int>>& intervals, int i, int prev) {
        if (i == intervals.size()) return 0;
        int res = dfs(intervals, i + 1, prev);
        if (prev == -1 || intervals[prev][1] <= intervals[i][0]) {
            res = max(res, 1 + dfs(intervals, i + 1, i));
        }
        return res;
    }
};
```

### **Dry Run:**

**Input:** `intervals = [[1,2],[2,4],[1,4]]`

**After sorting:** `[[1,2],[1,4],[2,4]]`

|Call|i|prev|intervals[i]|Skip|Take (if valid)|Return|
|---|---|---|---|---|---|---|
|dfs(0,-1)|0|-1|[1,2]|dfs(1,-1)|1+dfs(1,0)|max(0,1+0)=1|
|dfs(1,-1)|1|-1|[1,4]|dfs(2,-1)|1+dfs(2,1)|max(1,1+0)=1|
|dfs(2,-1)|2|-1|[2,4]|dfs(3,-1)|1+dfs(3,2)|max(0,1+0)=1|
|dfs(3,-1)|3|-1|-|Base case|-|0|
|dfs(1,0)|1|0|[1,4]|dfs(2,0)|intervals[0][1]=2>intervals[1][0]=1|0|
|dfs(2,0)|2|0|[2,4]|dfs(3,0)|1+dfs(3,2)|max(0,1+0)=1|
|dfs(2,1)|2|1|[2,4]|dfs(3,1)|intervals[1][1]=4>intervals[2][0]=2|0|
|dfs(3,1)|3|1|-|Base case|-|0|
|dfs(3,0)|3|0|-|Base case|-|0|
|dfs(3,2)|3|2|-|Base case|-|0|

**Max non-overlapping intervals = 2, Total intervals = 3**

**Output:** `3 - 2 = 1`

**Time & Space Complexity:**

- **Time complexity: O(2^n)**
- **Space complexity: O(n)**

---

## **2. Dynamic Programming (Top-Down)**

```cpp
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });
        int n = intervals.size();
        vector<int> memo(n, -1);  

        int maxNonOverlapping = dfs(intervals, 0, memo);
        return n - maxNonOverlapping;
    }

private:
    int dfs(const vector<vector<int>>& intervals, int i, vector<int>& memo) {
        if (i >= intervals.size()) return 0;
        if (memo[i] != -1) return memo[i];

        int res = 1;
        for (int j = i + 1; j < intervals.size(); j++) {
            if (intervals[i][1] <= intervals[j][0]) {
                res = max(res, 1 + dfs(intervals, j, memo));
            }
        }
        memo[i] = res;
        return res;
    }
};
```

### **Dry Run:**

**Input:** `intervals = [[1,2],[2,4],[1,4]]`

**After sorting by end time:** `[[1,2],[1,4],[2,4]]`

|Call|i|intervals[i]|Check j|intervals[j]|Valid?|Max Result|memo[i]|
|---|---|---|---|---|---|---|---|
|dfs(0)|0|[1,2]|j=1|[1,4]|2≤1? No|res=1|-|
||||j=2|[2,4]|2≤2? Yes|max(1,1+dfs(2))|-|
|dfs(2)|2|[2,4]|j=3|-|-|res=1|memo[2]=1|
|dfs(0)|0|[1,2]|-|-|-|max(1,1+1)=2|memo[0]=2|

**Max non-overlapping intervals from start = 2**

**Output:** `3 - 2 = 1`

**Time & Space Complexity:**

- **Time complexity: O(n²)**
- **Space complexity: O(n)**

---

## **3. Dynamic Programming (Bottom-Up)**

```cpp
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });
        int n = intervals.size();
        vector<int> dp(n, 0);  

        for (int i = 0; i < n; i++) {
            dp[i] = 1;  
            for (int j = 0; j < i; j++) {
                if (intervals[j][1] <= intervals[i][0]) {  
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }

        int maxNonOverlapping = *max_element(dp.begin(), dp.end());  
        return n - maxNonOverlapping;
    }
};
```

### **Dry Run:**

**Input:** `intervals = [[1,2],[2,4],[1,4]]`

**After sorting by end time:** `[[1,2],[1,4],[2,4]]`

|i|intervals[i]|j|intervals[j]|intervals[j][1] <= intervals[i][0]?|dp[i] calculation|dp|
|---|---|---|---|---|---|---|
|0|[1,2]|-|-|-|dp[0] = 1|[1,0,0]|
|1|[1,4]|0|[1,2]|2 <= 1? No|dp[1] = 1|[1,1,0]|
|2|[2,4]|0|[1,2]|2 <= 2? Yes|max(1, 1+1) = 2|[1,1,2]|
|2|[2,4]|1|[1,4]|4 <= 2? No|dp[2] = 2|[1,1,2]|

**Max element in dp = 2**

**Output:** `3 - 2 = 1`

**Time & Space Complexity:**

- **Time complexity: O(n²)**
- **Space complexity: O(n)**

---

## **4. Dynamic Programming (Binary Search)**

```cpp
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });
        int n = intervals.size();
        vector<int> dp(n);
        dp[0] = 1;

        for (int i = 1; i < n; i++) {
            int idx = bs(i, intervals[i][0], intervals);
            if (idx == 0) {
                dp[i] = dp[i - 1];
            } else {
                dp[i] = max(dp[i - 1], 1 + dp[idx - 1]);
            }
        }
        return n - dp[n - 1];
    }

    int bs(int r, int target, vector<vector<int>>& intervals) {
        int l = 0;
        while (l < r) {
            int m = (l + r) >> 1;
            if (intervals[m][1] <= target) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
};
```

### **Dry Run:**

**Input:** `intervals = [[1,2],[2,4],[1,4]]`

**After sorting by end time:** `[[1,2],[1,4],[2,4]]`

|i|intervals[i]|target|Binary Search|idx|dp[i] calculation|dp|
|---|---|---|---|---|---|---|
|0|[1,2]|-|-|-|dp[0] = 1|[1,0,0]|
|1|[1,4]|1|Find last interval with end ≤ 1|0|idx=0, dp[1]=dp[0]=1|[1,1,0]|
|2|[2,4]|2|Find last interval with end ≤ 2|1|max(dp[1], 1+dp[0])=max(1,2)=2|[1,1,2]|

**Output:** `3 - 2 = 1`

**Time & Space Complexity:**

- **Time complexity: O(nlogn)**
- **Space complexity: O(n)**

---

## **5. Greedy (Sort By Start)**

```cpp
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int res = 0;
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if (start >= prevEnd) {
                prevEnd = end;
            } else {
                res++;
                prevEnd = min(end, prevEnd);
            }
        }
        return res;
    }
};
```

### **Dry Run:**

**Input:** `intervals = [[1,2],[2,4],[1,4]]`

**After sorting by start:** `[[1,2],[1,4],[2,4]]`

|i|intervals[i]|start|end|start >= prevEnd?|Action|res|prevEnd|
|---|---|---|---|---|---|---|---|
|Init|[1,2]|-|-|-|Initialize|0|2|
|1|[1,4]|1|4|1 >= 2? No|Remove, min(4,2)=2|1|2|
|2|[2,4]|2|4|2 >= 2? Yes|Keep|1|4|

**Output:** `1`

**Time & Space Complexity:**

- **Time complexity: O(nlogn)**
- **Space complexity: O(1) or O(n) depending on the sorting algorithm.**

---

## **6. Greedy (Sort By End)**

```cpp
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });
        int res = 0;
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if (start < prevEnd) {
                res++;
            } else {
                prevEnd = end;
            }
        }
        return res;
    }
};
```

### **Dry Run:**

**Input:** `intervals = [[1,2],[2,4],[1,4]]`

**After sorting by end:** `[[1,2],[1,4],[2,4]]`

|i|intervals[i]|start|end|start < prevEnd?|Action|res|prevEnd|
|---|---|---|---|---|---|---|---|
|Init|[1,2]|-|-|-|Initialize|0|2|
|1|[1,4]|1|4|1 < 2? Yes|Remove|1|2|
|2|[2,4]|2|4|2 < 2? No|Keep|1|4|

**Output:** `1`

**Time & Space Complexity:**

- **Time complexity: O(nlogn)**
- **Space complexity: O(1) or O(n) depending on the sorting algorithm.**

# 4. Meeting Rooms

**Given an array of meeting time interval objects consisting of start and end times** `[[start_1,end_1],[start_2,end_2],...] (start_i < end_i)`, determine if a person could add all meetings to their schedule without any conflicts.

**Example 1:**

```java
Input: intervals = [(0,30),(5,10),(15,20)]
Output: false
```

**Explanation:**

- `(0,30)` and `(5,10)` will conflict
- `(0,30)` and `(15,20)` will conflict

**Example 2:**

```java
Input: intervals = [(5,8),(9,15)]
Output: true
```

**Note:**

- **(0,8),(8,10) is not considered a conflict at 8**

**Constraints:**

- `0 <= intervals.length <= 500`
- `0 <= intervals[i].start < intervals[i].end <= 1,000,000`

**Recommended Time & Space Complexity** You should aim for a solution with `O(nlogn)` time and `O(n)` space, where `n` is the size of the input array.

**Hint 1** If two intervals are sorted in ascending order by their start values, they overlap if the start value of the second interval is less than the end value of the first interval. And these are called overlapping intervals.

**Hint 2** A brute force approach would be to check every pair of intervals and return `false` if any overlap is found. This would be an `O(n^2)` solution. Can you think of a better way? Maybe you should visualize the given intervals as line segments.

**Hint 3** We should sort the given intervals based on their start values, as this makes it easier to check for overlaps by comparing adjacent intervals. We then iterate through the intervals from left to right and return `false` if any adjacent intervals overlap.

## 1. Brute Force

```cpp
/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            Interval& A = intervals[i];
            for (int j = i + 1; j < n; j++) {
                Interval& B = intervals[j];
                if (min(A.end, B.end) > max(A.start, B.start)) {
                    return false;
                }
            }
        }
        return true;
    }
};
```

**Dry Run:**

|Step|i|j|A|B|min(A.end, B.end)|max(A.start, B.start)|Overlap?|Action|
|---|---|---|---|---|---|---|---|---|
|Input: [(0,30),(5,10),(15,20)]|||||||||
|1|0|1|(0,30)|(5,10)|min(30,10)=10|max(0,5)=5|10>5=true|return false|

**Time & Space Complexity**

- **Time complexity: O(n²)**
- **Space complexity: O(1)**

## 2. Sorting

```cpp
/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& x, auto& y) { 
            return x.start < y.start; 
        });
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start < intervals[i - 1].end) {
                return false;
            }
        }
        return true;
    }
};
```

**Dry Run:**

|Step|Action|intervals|i|intervals[i].start|intervals[i-1].end|Overlap?|Result|
|---|---|---|---|---|---|---|---|
|Input: [(0,30),(5,10),(15,20)]||||||||
|1|Sort by start|[(0,30),(5,10),(15,20)]||||||
|2|Check i=1|[(0,30),(5,10),(15,20)]|1|5|30|5<30=true|return false|

**Example 2 Dry Run:**

|Step|Action|intervals|i|intervals[i].start|intervals[i-1].end|Overlap?|Result|
|---|---|---|---|---|---|---|---|
|Input: [(5,8),(9,15)]||||||||
|1|Sort by start|[(5,8),(9,15)]||||||
|2|Check i=1|[(5,8),(9,15)]|1|9|8|9<8=false|continue|
|3|Loop complete||||||return true|

**Time & Space Complexity**

- **Time complexity: O(n log n)**
- **Space complexity: O(1) or O(n) depending on the sorting algorithm**

# 5. Meeting Rooms II

**Given an array of meeting time interval objects consisting of start and end times** `[[start_1,end_1],[start_2,end_2],...] (start_i < end_i)`, find the minimum number of days required to schedule all meetings without any conflicts.

**Note: (0,8),(8,10) is not considered a conflict at 8.**

**Example 1:**

```java
Input: intervals = [(0,40),(5,10),(15,20)]
Output: 2
```

**Explanation: day1: (0,40) day2: (5,10),(15,20)**

**Example 2:**

```java
Input: intervals = [(4,9)]
Output: 1
```

**Constraints:**

- `0 <= intervals.length <= 500`
- `0 <= intervals[i].start < intervals[i].end <= 1,000,000`

**Recommended Time & Space Complexity** You should aim for a solution with `O(nlogn)` time and `O(n)` space, where `n` is the size of the input array.

**Hint 1** Try to visualize the meetings as line segments on a number line representing start and end times. The number of rooms required is the maximum number of overlapping meetings at any point on the number line. Can you think of a way to determine this efficiently?

**Hint 2** We create two arrays, start and end, containing the start and end times of all meetings, respectively. After sorting both arrays, we use a two-pointer based approach. How do you implement this?

**Hint 3** We use two pointers, `s` and `e`, for the start and end arrays, respectively. We also maintain a variable `count` to track the current number of active meetings. At each iteration, we increment `s` while the start time is less than the current end time and increase `count`, as these meetings must begin before the earliest ongoing meeting ends.

**Hint 4** Then, we increment `e` and decrement `count` as a meeting has ended. At each step, we update the result with the maximum value of active meetings stored in `count`.

## 1. Min Heap

```cpp
/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a.start < b.start;
        });
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (const auto& interval : intervals) {
            if (!minHeap.empty() && minHeap.top() <= interval.start) {
                minHeap.pop();
            }
            minHeap.push(interval.end);
        }
        return minHeap.size();
    }
};
```

**Dry Run:**

|Step|Action|intervals (sorted)|Current Interval|minHeap|minHeap.top()|Condition|minHeap after|
|---|---|---|---|---|---|---|---|
|Input: [(0,40),(5,10),(15,20)]||||||||
|1|Sort|[(0,40),(5,10),(15,20)]||||||
|2|Process (0,40)|[(0,40),(5,10),(15,20)]|(0,40)|[]|-|heap empty|[40]|
|3|Process (5,10)|[(0,40),(5,10),(15,20)]|(5,10)|[40]|40|40≤5? false|[10,40]|
|4|Process (15,20)|[(0,40),(5,10),(15,20)]|(15,20)|[10,40]|10|10≤15? true|[20,40]|
|5|Return|||[20,40]|||size=2|

**Time & Space Complexity**

- **Time complexity: O(n log n)**
- **Space complexity: O(n)**

## 2. Sweep Line Algorithm

```cpp
/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> mp;
        for (auto& i : intervals) {
            mp[i.start]++;
            mp[i.end]--;
        }
        int prev = 0, res = 0;
        for (auto& [key, value] : mp) {
            prev += value;
            res = max(res, prev);
        }
        return res;
    }
};
```

**Dry Run:**

|Step|Action|intervals|mp|key|value|prev|res|
|---|---|---|---|---|---|---|---|
|Input: [(0,40),(5,10),(15,20)]||||||||
|1|Build map|[(0,40),(5,10),(15,20)]|{0:1, 5:1, 10:-1, 15:1, 20:-1, 40:-1}|||0|0|
|2|Process key=0||{0:1, 5:1, 10:-1, 15:1, 20:-1, 40:-1}|0|1|0+1=1|max(0,1)=1|
|3|Process key=5||{0:1, 5:1, 10:-1, 15:1, 20:-1, 40:-1}|5|1|1+1=2|max(1,2)=2|
|4|Process key=10||{0:1, 5:1, 10:-1, 15:1, 20:-1, 40:-1}|10|-1|2+(-1)=1|max(2,1)=2|
|5|Process key=15||{0:1, 5:1, 10:-1, 15:1, 20:-1, 40:-1}|15|1|1+1=2|max(2,2)=2|
|6|Process key=20||{0:1, 5:1, 10:-1, 15:1, 20:-1, 40:-1}|20|-1|2+(-1)=1|max(2,1)=2|
|7|Process key=40||{0:1, 5:1, 10:-1, 15:1, 20:-1, 40:-1}|40|-1|1+(-1)=0|max(2,0)=2|
|8|Return||||||2|

**Time & Space Complexity**

- **Time complexity: O(n log n)**
- **Space complexity: O(n)**

## 3. Two Pointers

```cpp
/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start, end;
        
        for (const auto& i : intervals) {
            start.push_back(i.start);
            end.push_back(i.end);
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int res = 0, count = 0, s = 0, e = 0;
        while (s < intervals.size()) {
            if (start[s] < end[e]) {
                s++;
                count++;
            } else {
                e++;
                count--;
            }
            res = max(res, count);
        }
        return res;
    }
};
```

**Dry Run:**

|Step|start array|end array|s|e|start[s]|end[e]|Condition|Action|count|res|
|---|---|---|---|---|---|---|---|---|---|---|
|Input: [(0,40),(5,10),(15,20)]|||||||||||
|1|[0,5,15]|[40,10,20]|||||||||
|2|[0,5,15]|[10,20,40]|0|0|0|10|0<10? true|s++, count++|1|1|
|3|[0,5,15]|[10,20,40]|1|0|5|10|5<10? true|s++, count++|2|2|
|4|[0,5,15]|[10,20,40]|2|0|15|10|15<10? false|e++, count--|1|2|
|5|[0,5,15]|[10,20,40]|2|1|15|20|15<20? true|s++, count++|2|2|
|6|s=3, exit loop|||||||||2|

**Time & Space Complexity**

- **Time complexity: O(n log n)**
- **Space complexity: O(n)**

## 4. Greedy

```cpp
/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int, int>> time;
        for (const auto& i : intervals) {
            time.push_back({i.start, 1});
            time.push_back({i.end, -1});
        }
        
        sort(time.begin(), time.end(), [](auto& a, auto& b) {
            return a.first == b.first ? a.second < b.second : a.first < b.first;
        });
        
        int res = 0, count = 0;
        for (const auto& t : time) {
            count += t.second;
            res = max(res, count);
        }
        return res;
    }
};
```

**Dry Run:**

|Step|Action|time array|Current pair|count|res|
|---|---|---|---|---|---|
|Input: [(0,40),(5,10),(15,20)]||||||
|1|Build time array|[(0,1),(40,-1),(5,1),(10,-1),(15,1),(20,-1)]||0|0|
|2|Sort time array|[(0,1),(5,1),(10,-1),(15,1),(20,-1),(40,-1)]||0|0|
|3|Process (0,1)|[(0,1),(5,1),(10,-1),(15,1),(20,-1),(40,-1)]|(0,1)|0+1=1|max(0,1)=1|
|4|Process (5,1)|[(0,1),(5,1),(10,-1),(15,1),(20,-1),(40,-1)]|(5,1)|1+1=2|max(1,2)=2|
|5|Process (10,-1)|[(0,1),(5,1),(10,-1),(15,1),(20,-1),(40,-1)]|(10,-1)|2+(-1)=1|max(2,1)=2|
|6|Process (15,1)|[(0,1),(5,1),(10,-1),(15,1),(20,-1),(40,-1)]|(15,1)|1+1=2|max(2,2)=2|
|7|Process (20,-1)|[(0,1),(5,1),(10,-1),(15,1),(20,-1),(40,-1)]|(20,-1)|2+(-1)=1|max(2,1)=2|
|8|Process (40,-1)|[(0,1),(5,1),(10,-1),(15,1),(20,-1),(40,-1)]|(40,-1)|1+(-1)=0|max(2,0)=2|
|9|Return||||2|

**Time & Space Complexity**

- **Time complexity: O(n log n)**
- **Space complexity: O(n)**

# 6. Minimum Interval to Include Each Query

**You are given a 2D integer array** `intervals`, where `intervals[i] = [left_i, right_i]` represents the `ith` interval starting at `left_i` and ending at `right_i` **(inclusive)**.

**You are also given an integer array of query points** `queries`. The result of `query[j]` is the **length of the shortest interval** `i` such that `left_i <= queries[j] <= right_i`. If no such interval exists, the result of this query is `-1`.

**Return an array** `output` where `output[j]` is the result of `query[j]`.

**Note: The length of an interval is calculated as** `right_i - left_i + 1`.

**Example 1:**

```java
Input: intervals = [[1,3],[2,3],[3,7],[6,6]], queries = [2,3,1,7,6,8]
Output: [2,2,3,5,1,-1]
```

**Explanation:**

- **Query = 2: The interval** `[2,3]` is the smallest one containing 2, it's length is 2.
- **Query = 3: The interval** `[2,3]` is the smallest one containing 3, it's length is 2.
- **Query = 1: The interval** `[1,3]` is the smallest one containing 1, it's length is 3.
- **Query = 7: The interval** `[3,7]` is the smallest one containing 7, it's length is 5.
- **Query = 6: The interval** `[6,6]` is the smallest one containing 6, it's length is 1.
- **Query = 8: There is no interval containing 8.**

**Constraints:**

- `1 <= intervals.length <= 1000`
- `1 <= queries.length <= 1000`
- `1 <= left_i <= right_i <= 10000`
- `1 <= queries[j] <= 10000`

**Recommended Time & Space Complexity** You should aim for a solution as good or better than `O(nlogn + mlogm)` time and `O(n + m)` space, where `m` is the size of the array `queries` and `n` is the size of the array `intervals`.

**Hint 1** A brute force approach would be to iterate through each query and, for each query, check all intervals to find the result. This would be an `O(m * n)` solution. Can you think of a better way? Maybe processing the queries in sorted order could help.

**Hint 2** We sort the intervals by start value and process the queries in ascending order. Using a pointer `i`, we add intervals to a min-heap while their start values are less than or equal to the query, storing their end values and sizes.

**Hint 3** The min-heap is ordered by interval size. We remove elements from the heap while the top element's end value is less than the current query. The result for the query is the top element's size if the heap is non-empty; otherwise, it is `-1`.

## 1. Brute Force

```cpp
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> res;
        for (int q : queries) {
            int cur = -1;
            for (auto& interval : intervals) {
                int l = interval[0], r = interval[1];
                if (l <= q && q <= r) {
                    if (cur == -1 || (r - l + 1) < cur) {
                        cur = r - l + 1;
                    }
                }
            }
            res.push_back(cur);
        }
        return res;
    }
};
```

**Dry Run:**

|Step|Query|Current Interval|l|r|Condition|Length|cur|Action|
|---|---|---|---|---|---|---|---|---|
|Input: intervals = [[1,3],[2,3],[3,7],[6,6]], queries = [2,3,1]|||||||||
|1|q=2|[1,3]|1|3|1≤2≤3? true|3-1+1=3|cur=-1, so cur=3|cur=3|
|2|q=2|[2,3]|2|3|2≤2≤3? true|3-2+1=2|2<3? true|cur=2|
|3|q=2|[3,7]|3|7|3≤2≤7? false|-|-|skip|
|4|q=2|[6,6]|6|6|6≤2≤6? false|-|-|skip|
|5|q=2 result||||||cur=2|res=[2]|
|6|q=3|[1,3]|1|3|1≤3≤3? true|3-1+1=3|cur=-1, so cur=3|cur=3|
|7|q=3|[2,3]|2|3|2≤3≤3? true|3-2+1=2|2<3? true|cur=2|
|8|q=3 result||||||cur=2|res=[2,2]|

**Time & Space Complexity**

- **Time complexity: O(m * n)**
- **Space complexity: O(1) extra space, O(m) space for the output array.**

Where `m` is the length of the array `queries` and `n` is the length of the array `intervals`.

## 2. Sweep Line Algorithm

```cpp
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<vector<int>> events;
        // Create events for intervals
        for (int i = 0; i < intervals.size(); i++) {
            events.push_back({intervals[i][0], 0, intervals[i][1] - intervals[i][0] + 1, i});
            events.push_back({intervals[i][1], 2, intervals[i][1] - intervals[i][0] + 1, i});
        }
        
        // Create events for queries
        for (int i = 0; i < queries.size(); i++) {
            events.push_back({queries[i], 1, i});
        }
        
        // Sort by time and type (end before query)
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });
        
        vector<int> ans(queries.size(), -1);
        // Min heap storing [size, index]
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> inactive(intervals.size(), false);
        
        for (const auto& event : events) {
            if (event[1] == 0) { // Interval start
                pq.push({event[2], event[3]});
            } else if (event[1] == 2) { // Interval end
                inactive[event[3]] = true;
            } else { // Query
                int queryIdx = event[2];
                while (!pq.empty() && inactive[pq.top().second]) {
                    pq.pop();
                }
                if (!pq.empty()) {
                    ans[queryIdx] = pq.top().first;
                }
            }
        }
        
        return ans;
    }
};
```

**Dry Run:**

|Step|Event|Type|Action|pq|inactive|ans|
|---|---|---|---|---|---|---|
|Input: intervals = [[1,3],[2,3]], queries = [2]|||||||
|1|Build events||events = [(1,0,3,0),(3,2,3,0),(2,0,2,1),(3,2,2,1),(2,1,0)]||[false,false]|[-1]|
|2|Sort events||events = [(1,0,3,0),(2,0,2,1),(2,1,0),(3,2,3,0),(3,2,2,1)]||[false,false]|[-1]|
|3|(1,0,3,0)|start|pq.push({3,0})|[(3,0)]|[false,false]|[-1]|
|4|(2,0,2,1)|start|pq.push({2,1})|[(2,1),(3,0)]|[false,false]|[-1]|
|5|(2,1,0)|query|ans[0] = pq.top().first = 2|[(2,1),(3,0)]|[false,false]|[2]|
|6|(3,2,3,0)|end|inactive[0] = true|[(2,1),(3,0)]|[true,false]|[2]|
|7|(3,2,2,1)|end|inactive[1] = true|[(2,1),(3,0)]|[true,true]|[2]|

**Time & Space Complexity**

- **Time complexity: O((n+m)log(n+m))**
- **Space complexity: O(n+m)**

Where `m` is the length of the array `queries` and `n` is the length of the array `intervals`.

## 3. Min Heap

```cpp
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // Sort intervals based on the start value
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[0] < b[0];
        });

        vector<int> sortedQueries = queries;
        sort(sortedQueries.begin(), sortedQueries.end());
        map<int, int> res;

        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] > b[1]);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> minHeap(cmp);

        int i = 0;
        for (int q : sortedQueries) {
            while (i < intervals.size() && intervals[i][0] <= q) {
                int l = intervals[i][0];
                int r = intervals[i][1];
                minHeap.push({r - l + 1, r});
                i++;
            }

            while (!minHeap.empty() && minHeap.top()[1] < q) {
                minHeap.pop();
            }

            res[q] = minHeap.empty() ? -1 : minHeap.top()[0];
        }

        vector<int> result(queries.size());
        for (int j = 0; j < queries.size(); j++) {
            result[j] = res[queries[j]];
        }
        return result;
    }
};
```

**Dry Run:**

|Step|Query|i|Action|minHeap|Result|
|---|---|---|---|---|---|
|Input: intervals = [[1,3],[2,3]], queries = [2]||||||
|1|Sort intervals||intervals = [[1,3],[2,3]]|||
|2|Sort queries||sortedQueries = [2]|||
|3|q=2|0|intervals[0][0]=1≤2? true|||
|4||0|Add [1,3]: push({3,3})|[{3,3}]||
|5||1|intervals[1][0]=2≤2? true|||
|6||1|Add [2,3]: push({2,3})|[{2,3},{3,3}]||
|7||2|i=2, exit while loop|[{2,3},{3,3}]||
|8|q=2||minHeap.top()[1]=3≥2? true|[{2,3},{3,3}]||
|9|q=2||res[2] = minHeap.top()[0] = 2|[{2,3},{3,3}]|res[2]=2|

**Time & Space Complexity**

- **Time complexity: O(nlogn + mlogm)**
- **Space complexity: O(n+m)**

Where `m` is the length of the array `queries` and `n` is the length of the array `intervals`.

## 4. Min Segment Tree (Lazy Propagation)

```cpp
class SegmentTree {
public:
    int n;
    vector<int> tree;
    vector<int> lazy;

    SegmentTree(int N) {
        this->n = N;
        tree.assign(4 * N, INT_MAX);
        lazy.assign(4 * N, INT_MAX);
    }

    void propagate(int treeidx, int lo, int hi) {
        if (lazy[treeidx] != INT_MAX) {
            tree[treeidx] = min(tree[treeidx], lazy[treeidx]);
            if (lo != hi) {
                lazy[2 * treeidx + 1] = min(lazy[2 * treeidx + 1], lazy[treeidx]);
                lazy[2 * treeidx + 2] = min(lazy[2 * treeidx + 2], lazy[treeidx]);
            }
            lazy[treeidx] = INT_MAX;
        }
    }

    void update(int treeidx, int lo, int hi, int left, int right, int val) {
        propagate(treeidx, lo, hi);
        
        if (lo > right || hi < left) return;

        if (lo >= left && hi <= right) {
            lazy[treeidx] = min(lazy[treeidx], val);
            propagate(treeidx, lo, hi);
            return;
        }

        int mid = (lo + hi) / 2;
        update(2 * treeidx + 1, lo, mid, left, right, val);
        update(2 * treeidx + 2, mid + 1, hi, left, right, val);
        
        tree[treeidx] = min(tree[2 * treeidx + 1], tree[2 * treeidx + 2]);
    }

    int query(int treeidx, int lo, int hi, int idx) {
        propagate(treeidx, lo, hi);
        if (lo == hi) return tree[treeidx];
        
        int mid = (lo + hi) / 2;
        if (idx <= mid) return query(2 * treeidx + 1, lo, mid, idx);
        else return query(2 * treeidx + 2, mid + 1, hi, idx);
    }

    void update(int left, int right, int val) {
        update(0, 0, n - 1, left, right, val);
    }

    int query(int idx) {
        return query(0, 0, n - 1, idx);
    }
};

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> points;

        for (const auto& interval : intervals) {
            points.push_back(interval[0]);
            points.push_back(interval[1]);
        }
        for (int q : queries) {
            points.push_back(q);
        }

        sort(points.begin(), points.end());
        points.erase(unique(points.begin(), points.end()), points.end());

        // compress the coordinates
        unordered_map<int, int> compress;
        for (int i = 0; i < points.size(); ++i) {
            compress[points[i]] = i;
        }

        SegmentTree segTree(points.size());

        for (const auto& interval : intervals) {
            int start = compress[interval[0]];
            int end = compress[interval[1]];
            int len = interval[1] - interval[0] + 1;
            segTree.update(start, end, len);
        }

        vector<int> ans;
        for (int q : queries) {
            int idx = compress[q];
            int res = segTree.query(idx);
            ans.push_back(res == INT_MAX ? -1 : res);
        }

        return ans;
    }
};
```

**Dry Run:**

|Step|Action|points|compress|segTree updates|Query|Result|
|---|---|---|---|---|---|---|
|Input: intervals = [[1,3],[2,3]], queries = [2]|||||||
|1|Collect points|[1,3,2,3,2]|||||
|2|Sort & unique|[1,2,3]|||||
|3|Build compress|[1,2,3]|{1:0, 2:1, 3:2}||||
|4|Create segTree|||segTree(3)|||
|5|Update [1,3]|||start=0, end=2, len=3|||
|6||||segTree.update(0,2,3)|||
|7|Update [2,3]|||start=1, end=2, len=2|||
|8||||segTree.update(1,2,2)|||
|9|Query q=2||||idx=compress[2]=1||
|10|||||segTree.query(1) = 2|ans=[2]|

**Time & Space Complexity**

- **Time complexity: O((n+m)logk)**
- **Space complexity: O(k) extra space, O(m) space for the output array.**

Where `m` is the length of the array `queries`, `n` is the length of the array `intervals` and `k` is the number of unique points.