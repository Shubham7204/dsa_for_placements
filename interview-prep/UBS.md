```cpp
#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; 
    long long sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++) {

        if (sum == 0) start = i;

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }

        if (sum < 0) {
            sum = 0;
        }
    }

    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << "]n";

    return maxi;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}
```
## Dry Run: Kadane's Algorithm

**Input Array:** `arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4}`
**Size of Array:** `n = 9`

**Initial Values:**
* `maxi = LONG_MIN` (a very small negative number, effectively negative infinity)
* `sum = 0`
* `start = 0`
* `ansStart = -1`
* `ansEnd = -1`

---

**Loop Starts: `for (int i = 0; i < n; i++)`**

---

### **Iteration 1: `i = 0`, `arr[i] = -2`**

1.  **`if (sum == 0) start = i;`**: `sum` is `0`. Condition `(0 == 0)` is **true**.
    * `start` becomes `0`. (Current start of potential subarray)
2.  **`sum += arr[i];`**: `sum = 0 + (-2) = -2`.
3.  **`if (sum > maxi)`**: `sum` (`-2`) is greater than `maxi` (`LONG_MIN`). Condition `(-2 > LONG_MIN)` is **true**.
    * `maxi = -2`. (New maximum sum found)
    * `ansStart = start` (which is `0`).
    * `ansEnd = i` (which is `0`).
4.  **`if (sum < 0)`**: `sum` (`-2`) is less than `0`. Condition `(-2 < 0)` is **true**.
    * `sum = 0`. (Reset sum because a negative sum will only reduce future sums)

**End of Iteration 1 State:**
* `maxi = -2`
* `sum = 0`
* `start = 0`
* `ansStart = 0`
* `ansEnd = 0`

---

### **Iteration 2: `i = 1`, `arr[i] = 1`**

1.  **`if (sum == 0) start = i;`**: `sum` is `0`. Condition `(0 == 0)` is **true**.
    * `start` becomes `1`. (New potential start of subarray)
2.  **`sum += arr[i];`**: `sum = 0 + 1 = 1`.
3.  **`if (sum > maxi)`**: `sum` (`1`) is greater than `maxi` (`-2`). Condition `(1 > -2)` is **true**.
    * `maxi = 1`.
    * `ansStart = start` (which is `1`).
    * `ansEnd = i` (which is `1`).
4.  **`if (sum < 0)`**: `sum` (`1`) is not less than `0`. Condition `(1 < 0)` is **false**.
    * `sum` remains `1`.

**End of Iteration 2 State:**
* `maxi = 1`
* `sum = 1`
* `start = 1`
* `ansStart = 1`
* `ansEnd = 1`

---

### **Iteration 3: `i = 2`, `arr[i] = -3`**

1.  **`if (sum == 0) start = i;`**: `sum` is `1`. Condition `(1 == 0)` is **false**.
    * `start` remains `1`.
2.  **`sum += arr[i];`**: `sum = 1 + (-3) = -2`.
3.  **`if (sum > maxi)`**: `sum` (`-2`) is not greater than `maxi` (`1`). Condition `(-2 > 1)` is **false**.
    * `maxi`, `ansStart`, `ansEnd` remain unchanged.
4.  **`if (sum < 0)`**: `sum` (`-2`) is less than `0`. Condition `(-2 < 0)` is **true**.
    * `sum = 0`.

**End of Iteration 3 State:**
* `maxi = 1`
* `sum = 0`
* `start = 1`
* `ansStart = 1`
* `ansEnd = 1`

---

### **Iteration 4: `i = 3`, `arr[i] = 4`**

1.  **`if (sum == 0) start = i;`**: `sum` is `0`. Condition `(0 == 0)` is **true**.
    * `start` becomes `3`. (New potential start of subarray)
2.  **`sum += arr[i];`**: `sum = 0 + 4 = 4`.
3.  **`if (sum > maxi)`**: `sum` (`4`) is greater than `maxi` (`1`). Condition `(4 > 1)` is **true**.
    * `maxi = 4`.
    * `ansStart = start` (which is `3`).
    * `ansEnd = i` (which is `3`).
4.  **`if (sum < 0)`**: `sum` (`4`) is not less than `0`. Condition `(4 < 0)` is **false**.
    * `sum` remains `4`.

**End of Iteration 4 State:**
* `maxi = 4`
* `sum = 4`
* `start = 3`
* `ansStart = 3`
* `ansEnd = 3`

---

### **Iteration 5: `i = 4`, `arr[i] = -1`**

1.  **`if (sum == 0) start = i;`**: `sum` is `4`. Condition `(4 == 0)` is **false**.
    * `start` remains `3`.
2.  **`sum += arr[i];`**: `sum = 4 + (-1) = 3`.
3.  **`if (sum > maxi)`**: `sum` (`3`) is not greater than `maxi` (`4`). Condition `(3 > 4)` is **false**.
    * `maxi`, `ansStart`, `ansEnd` remain unchanged.
4.  **`if (sum < 0)`**: `sum` (`3`) is not less than `0`. Condition `(3 < 0)` is **false**.
    * `sum` remains `3`.

**End of Iteration 5 State:**
* `maxi = 4`
* `sum = 3`
* `start = 3`
* `ansStart = 3`
* `ansEnd = 3`

---

### **Iteration 6: `i = 5`, `arr[i] = 2`**

1.  **`if (sum == 0) start = i;`**: `sum` is `3`. Condition `(3 == 0)` is **false**.
    * `start` remains `3`.
2.  **`sum += arr[i];`**: `sum = 3 + 2 = 5`.
3.  **`if (sum > maxi)`**: `sum` (`5`) is greater than `maxi` (`4`). Condition `(5 > 4)` is **true**.
    * `maxi = 5`.
    * `ansStart = start` (which is `3`).
    * `ansEnd = i` (which is `5`).
4.  **`if (sum < 0)`**: `sum` (`5`) is not less than `0`. Condition `(5 < 0)` is **false**.
    * `sum` remains `5`.

**End of Iteration 6 State:**
* `maxi = 5`
* `sum = 5`
* `start = 3`
* `ansStart = 3`
* `ansEnd = 5`

---

### **Iteration 7: `i = 6`, `arr[i] = 1`**

1.  **`if (sum == 0) start = i;`**: `sum` is `5`. Condition `(5 == 0)` is **false**.
    * `start` remains `3`.
2.  **`sum += arr[i];`**: `sum = 5 + 1 = 6`.
3.  **`if (sum > maxi)`**: `sum` (`6`) is greater than `maxi` (`5`). Condition `(6 > 5)` is **true**.
    * `maxi = 6`.
    * `ansStart = start` (which is `3`).
    * `ansEnd = i` (which is `6`).
4.  **`if (sum < 0)`**: `sum` (`6`) is not less than `0`. Condition `(6 < 0)` is **false**.
    * `sum` remains `6`.

**End of Iteration 7 State:**
* `maxi = 6`
* `sum = 6`
* `start = 3`
* `ansStart = 3`
* `ansEnd = 6`

---

### **Iteration 8: `i = 7`, `arr[i] = -5`**

1.  **`if (sum == 0) start = i;`**: `sum` is `6`. Condition `(6 == 0)` is **false**.
    * `start` remains `3`.
2.  **`sum += arr[i];`**: `sum = 6 + (-5) = 1`.
3.  **`if (sum > maxi)`**: `sum` (`1`) is not greater than `maxi` (`6`). Condition `(1 > 6)` is **false**.
    * `maxi`, `ansStart`, `ansEnd` remain unchanged.
4.  **`if (sum < 0)`**: `sum` (`1`) is not less than `0`. Condition `(1 < 0)` is **false**.
    * `sum` remains `1`.

**End of Iteration 8 State:**
* `maxi = 6`
* `sum = 1`
* `start = 3`
* `ansStart = 3`
* `ansEnd = 6`

---

### **Iteration 9: `i = 8`, `arr[i] = 4`**

1.  **`if (sum == 0) start = i;`**: `sum` is `1`. Condition `(1 == 0)` is **false**.
    * `start` remains `3`.
2.  **`sum += arr[i];`**: `sum = 1 + 4 = 5`.
3.  **`if (sum > maxi)`**: `sum` (`5`) is not greater than `maxi` (`6`). Condition `(5 > 6)` is **false**.
    * `maxi`, `ansStart`, `ansEnd` remain unchanged.
4.  **`if (sum < 0)`**: `sum` (`5`) is not less than `0`. Condition `(5 < 0)` is **false**.
    * `sum` remains `5`.

**End of Iteration 9 State:**
* `maxi = 6`
* `sum = 5`
* `start = 3`
* `ansStart = 3`
* `ansEnd = 6`

---

**Loop Ends.**

---

### **After the loop (in `maxSubarraySum` function):**

1.  **Printing the subarray:**
    * `cout << "The subarray is: [";`
    * The loop `for (int i = ansStart; i <= ansEnd; i++)` will run from `i = 3` to `i = 6`.
        * `i = 3`: `cout << arr[3] << " ";` (prints `4 `)
        * `i = 4`: `cout << arr[4] << " ";` (prints `-1 `)
        * `i = 5`: `cout << arr[5] << " ";` (prints `2 `)
        * `i = 6`: `cout << arr[6] << " ";` (prints `1 `)
    * `cout << "]n";` (prints `]n` - note: this should likely be `]\n` for a proper newline character).

    **Output:** `The subarray is: [4 -1 2 1 ]n`

2.  **Return `maxi`:**
    * The function returns the final value of `maxi`, which is `6`.

---

### **In `main` function:**

1.  `long long maxSum = maxSubarraySum(arr, n);`
    * The `maxSubarraySum` function is called, and its return value (`6`) is stored in `maxSum`.
2.  `cout << "The maximum subarray sum is: " << maxSum << endl;`
    * This will print: `The maximum subarray sum is: 6`

---

### **Final Output:**
The subarray is: [4 -1 2 1 ]n The maximum subarray sum is: 6


- [ ] https://leetcode.com/problems/search-suggestions-system/
![](../pics/Search%20Suggestions%20System%20-%20Leetcode%201268%20-%20Python%205-27%20screenshot.png)![](../pics/Search%20Suggestions%20System%20-%20Leetcode%201268%20-%20Python%207-47%20screenshot.png)
![](../pics/Search%20Suggestions%20System%20-%20Leetcode%201268%20-%20Python%206-35%20screenshot.png)
![](../pics/Search%20Suggestions%20System%20-%20Leetcode%201268%20-%20Python%205-38%20screenshot.png)
```cpp
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {

        sort(products.begin(), products.end());  // Sort lexicographically

        int n = products.size();
        int l = 0, r = n - 1;

        vector<vector<string>> res;

        for (int i = 0; i < searchWord.size(); i++) {
            char c = searchWord[i];

            // Move left pointer forward
            while (l <= r && (products[l].size() <= i || products[l][i] != c)) {
                l++;
            }
            // Move right pointer backward
            while (l <= r && (products[r].size() <= i || products[r][i] != c)) {
                r--;
            }

            // Collect up to 3 matching products
            vector<string> match;
            for (int j = 0; j < 3 && l + j <= r; j++) {
                match.push_back(products[l + j]);
            }
            res.push_back(match);
        }   
        return res;
    }
};
```

- [ ] https://leetcode.com/problems/count-pairs-of-connectable-servers-in-a-weighted-tree-network/description/

- [ ] https://leetcode.com/problems/beautiful-arrangement/description/


- [ ] https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
```cpp
class Solution{
	public:
		int maxProfit(vector<int> &prices){
			int profit = 0;
			int mini = prices[0];
			int n = prices.size();

			for(int i = 0; i<n; i++){
				int cost = prices[i]-mini;
				profit = max(profit, cost);
				mini = min(mini, prices[i]);
			}
		}
		return profit;
}
```

- [ ] https://leetcode.com/problems/valid-parentheses

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            char it = s[i];

            if (it == '(')
                st.push(')');
            else if (it == '{')
                st.push('}');
            else if (it == '[')
                st.push(']');
            else {
                if (st.empty() || st.top() != it) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();  //This is important!
    }
};
```

- [ ] Given and array of integers ‘arr’ and a integer ‘k’, find a subarray from ‘arr’
so size ‘k’ which has unique elements and sum its sum is maximum and
return it’s sum. For example, if, arr = [2, 4, 6, 4, 6, 4, 5, 2] and k=3
The answer would be sum of [6, 4, 5] = 15, cause all other subarray with
unique element have less sum. [6, 4, 6] has sum of 16 but all elements are
not unique.

```cpp
#include <bits/stdc++.h>
using namespace std;

pair<int, vector<int>> maxUniqueSubarraySum(vector<int>& arr, int k) {
    unordered_map<int, int> freq;
    int n = arr.size(), left = 0, currSum = 0, maxSum = 0;
    int startIdx = -1; // To store start index of max sum subarray

    for (int right = 0; right < n; ++right) {
        freq[arr[right]]++;
        currSum += arr[right];

        // Shrink window if duplicate found
        while (freq[arr[right]] > 1) {
            freq[arr[left]]--;
            currSum -= arr[left];
            left++;
        }

        // If current window is of size k and all elements are unique
        if (right - left + 1 == k) {
            if (currSum > maxSum) {
                maxSum = currSum;
                startIdx = left;
            }
            // Slide the window forward
            freq[arr[left]]--;
            currSum -= arr[left];
            left++;
        }
    }

    // Extract the subarray
    vector<int> result;
    if (startIdx != -1) {
        for (int i = startIdx; i < startIdx + k; ++i)
            result.push_back(arr[i]);
    }

    return {maxSum, result};
}

int main() {
    vector<int> arr = {2, 4, 6, 4, 6, 4, 5, 2};
    int k = 3;

    auto [maxSum, subarray] = maxUniqueSubarraySum(arr, k);
    cout << "Max Sum: " << maxSum << "\nSubarray: ";
    for (int num : subarray) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
```

```cpp
vector<int> arr = {2, 4, 6, 4, 6, 4, 5, 2};
int k = 3;
```
### 🔧 Initial State:

```text
freq = {}  
left = 0  
right = 0 → moving rightward  
currSum = 0  
maxSum = 0  
startIdx = -1
```
### 📍 Step-by-step Dry Run:

#### ➤ right = 0 → arr[0] = 2

```text
freq = {2:1}
currSum = 2
Window size = 1 → < k → keep moving
```

#### ➤ right = 1 → arr[1] = 4

```text
freq = {2:1, 4:1}
currSum = 6
Window size = 2 → < k → continue
```

#### ➤ right = 2 → arr[2] = 6

```text
freq = {2:1, 4:1, 6:1}
currSum = 12
Window size = 3 = k ✔

→ currSum > maxSum → maxSum = 12, startIdx = 0

→ Slide window:
   freq[2]-- → 0 → remove
   currSum -= 2 → currSum = 10
   left = 1
```

#### ➤ right = 3 → arr[3] = 4

```text
freq[4] now = 2 → duplicate detected

Shrink:
   freq[4]-- → 1
   currSum -= 4 → currSum = 6
   left = 2

Insert 4 again:
   freq = {4:1, 6:1}
   currSum = 6 + 4 = 10
```

→ Window = 2 → continue
#### ➤ right = 4 → arr[4] = 6

```text
Duplicate again → freq[6] becomes 2

Shrink:
   freq[6]-- → 1
   currSum -= 6 → currSum = 4
   left = 3

Insert 6 again:
   currSum = 4 + 6 = 10
   freq[6] = 1
```

→ Window = 2 → continue
#### ➤ right = 5 → arr[5] = 4

```text
Duplicate again → freq[4] = 2

Shrink:
   freq[4]-- → 1
   currSum -= 4 → currSum = 6
   left = 4

Insert 4 again → currSum = 6 + 4 = 10

Window = 2 → continue
```
#### ➤ right = 6 → arr[6] = 5

```text
freq = {4:1, 6:1, 5:1}
currSum = 10 + 5 = 15

Window = 3 ✔  
→ currSum = 15 > maxSum = 12 ✔  
→ Update maxSum = 15, startIdx = 4

Slide:
   freq[4]-- → 0
   currSum -= 4 → currSum = 11
   left = 5
```
#### ➤ right = 7 → arr[7] = 2

```text
freq = {6:1, 5:1, 2:1}
currSum = 11 + 2 = 13

Window = 3 ✔  
→ currSum = 13 < maxSum → skip update

Slide:
   freq[6]-- → 0
   currSum -= 6 → currSum = 7
   left = 6
```
### ✅ Final Output:

- `maxSum = 15`
- `startIdx = 4`
- Subarray = `arr[4] to arr[6]` = `[6, 4, 5]`
### 🔚 Print:

```text
Max Sum: 15
Subarray: 6 4 5
```

- [ ] What sorting algorithms you know of tell me their space and time
complexity? Which one will you use to sort a linked list of size n.
- [ ] How would you detect a cycle in linked list.
- [ ] - [https://www.geeksforgeeks.org/given-a-sequence-of-words-print-all-anagrams-together/](https://www.geeksforgeeks.org/given-a-sequence-of-words-print-all-anagrams-together/)
- [ ]  [https://www.geeksforgeeks.org/count-minimum-number-of-fountains-to-be-activated-to-cover-the-entire-garden/](https://www.geeksforgeeks.org/count-minimum-number-of-fountains-to-be-activated-to-cover-the-entire-garden/)
- [ ] https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/description/

```cpp
class Solution {

public:

    int minTaps(int n, vector<int>& ranges) {
        vector<int> startEnd(n + 1, 0);

        for (int i = 0; i < ranges.size(); i++) {
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);

            startEnd[start] = max(startEnd[start], end);
        }

        int taps = 0;
        int currEnd = 0;
        int maxEnd = 0;

        for (int i = 0; i < n + 1; i++) {
            if (i > maxEnd) {
                return -1;
            }

            if (i > currEnd) {
                taps++;
                currEnd = maxEnd;
            }
            maxEnd = max(maxEnd, startEnd[i]);
        }
        return taps;
    }
};
```
- [ ] [https://www.geeksforgeeks.org/decimal-equivalent-of-binary-linked-list/](https://www.geeksforgeeks.org/decimal-equivalent-of-binary-linked-list/)
- [ ] https://leetcode.com/problems/remove-duplicate-letters/description/
https://www.youtube.com/watch?v=Dq_ObZwTY_Q

```cpp
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        vector<bool> seen(26, false);
        stack<char> st;

        for (char c : s) {
            freq[c - 'a']--;
            if (seen[c - 'a']) continue;

            while (!st.empty() && c < st.top() && freq[st.top() - 'a'] > 0) {
                seen[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            seen[c - 'a'] = true;
        }

        string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

```

- [ ] https://www.geeksforgeeks.org/lexicographically-smallest-string-formed-by-removing-duplicates/
- [ ] https://www.geeksforgeeks.org/program-check-input-character-alphabet-digit-special-character/
- [ ] https://www.geeksforgeeks.org/dsa/find-length-of-longest-substring-with-at-most-k-normal-characters/
- [ ] https://www.educative.io/answers/how-to-check-if-a-number-is-palindrome
```cpp
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int n) {
    int revNum = 0;
    int duplicate = n;

    while (n > 0) {
        int lastDigit = n % 10;
        revNum = (revNum * 10) + lastDigit;
        n = n / 10;
    }

    return duplicate == revNum;
}

int main() {
    int number = 4554;

    if (isPalindrome(number)) {
        cout << number << " is a palindrome number." << endl;
    } else {
        cout << number << " is not a palindrome number." << endl;
    }

    return 0;
}
```

**

How to find a missing number in an array of natural numbers

  

def missing(arr, n):

    total = n * (n + 1) // 2

    actual_sum = sum(arr)

    return total - actual_sum

  

arr = [1, 2, 3, 5, 6]

n = 6

print(missing(arr, n))

  

there are two sorted arrays given you have to merge them into one single sorted array

  

[https://takeuforward.org/data-structure/merge-two-sorted-arrays-without-extra-space/](https://takeuforward.org/data-structure/merge-two-sorted-arrays-without-extra-space/)

  
**
**![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXeWS_JP-BcvZ81hkIM1srVdVePsRet88XY1EBnxAC3u5ofgkhJChO6vvWd71WL8b0Kk6J-R8B3JPCwzp_6_IaCPqADEWP3GDL0il8l9UvM7B_pg79wvUASlVJJkX-6N1W3dYHgMQw?key=craUqSkHSWLlxkmJ164hAg)**

**

Write a recursive function Reverse(string str) that reverses the string using:

- Recursion  
      
    
- No auxiliary memory (no extra arrays/lists or new string construction)  
      
    
- Use a static/global string outside the function to store the result  
      
    
- Each recursive call should remove the last character from the string and append it to the result  
      
    

✅ C++ Answer (with static/global string):

  

#include <iostream>

using namespace std;

  

string reversed = ""; // Static/global variable to store reversed string

  

void Reverse(string str) {

    if (str.empty()) return;

  

    reversed += str[str.length() - 1]; // Append last character

    Reverse(str.substr(0, str.length() - 1)); // Recursive call on remaining string

}

  

int main() {

    string input = "hello";

    Reverse(input);

    cout << "Reversed: " << reversed << endl;

    return 0;

}

  

✅ Output:

  

Reversed: olleh

  

✅ Python Answer (with global variable):

  

reversed_str = ""  # Global variable to store reversed string

  

def Reverse(s):

    global reversed_str

    if not s:

        return

    reversed_str += s[-1]       # Append last character

    Reverse(s[:-1])             # Recursive call on remaining string

  

# Example usage

input_str = "hello"

Reverse(input_str)

print("Reversed:", reversed_str)

  

✅ Output:

Reversed: olleh

  

---

🧠 Note:

- Both implementations follow the constraints strictly.  
      
    
- They avoid auxiliary data structures and loop-based logic.  
      
    
- Only a single global/static string is used to build the result.  
      
    

  

✅ Problem Statement (Rephrased)

Given:

- A string s  
      
    
- A vector (list) of strings vec  
      
    

Find the lexicographically smallest string from vec that can be formed by rearranging the characters of s.

---

🧠 Key Observations

1. You are allowed to rearrange characters of s.  
      
    
2. From the rearranged versions of s, you want to match a string in vec.  
      
    
3. The valid strings are those in vec that are anagrams (or permutations) of s.  
      
    
4. Among all valid anagrams (i.e., present in vec), return the lexicographically smallest.  
      
    

---

💡 Approach

1. Sort the characters of the string s to prepare for frequency matching.  
      
    
2. Iterate over all strings in vec.  
      
    
3. For each string, check if it is an anagram of s (i.e., it contains the same characters with the same frequency).  
      
    
4. Store all such matching strings in a list.  
      
    
5. Return the lexicographically smallest from this list.  
      
    

---

🔧 Python Implementation

python

CopyEdit

def lexicographically_smallest_anagram(s, vec):

    from collections import Counter

    s_counter = Counter(s)

    valid = []

  

    for word in vec:

        if Counter(word) == s_counter:

            valid.append(word)

  

    if not valid:

        return "No valid anagram found"

    return min(valid)

  

# Example

s = "bca"

vec = ["abc", "acb", "cab", "bca", "xyz"]

print(lexicographically_smallest_anagram(s, vec))  # Output: "abc"

  

---

📈 Time & Space Complexity

- Time Complexity:  
      
    

- Counting characters in s: O(n)  
      
    
- Iterating over vec of size m with average string length k: O(m * k)  
      
    
- Overall: O(n + m * k)  
      
    

- Space Complexity: O(k) for counters and O(m) for valid matches.  
      
    

---

✅ Example Walkthrough

Let:

plaintext

CopyEdit

s = "bca"

vec = ["abc", "cab", "bca", "bac", "xyz", "def"]

  

- All of abc, cab, bca, bac are anagrams of "bca".  
      
    
- Lexicographically smallest among these is "abc".  
      
    

  
**

