- [ ] https://leetcode.com/problems/search-suggestions-system/
- [ ] https://leetcode.com/problems/count-pairs-of-connectable-servers-in-a-weighted-tree-network/description/
- [ ] https://leetcode.com/problems/beautiful-arrangement/description/
- [ ] https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
- [ ] https://leetcode.com/problems/valid-parentheses
- [ ] Given and array of integers ‘arr’ and a integer ‘k’, find a subarray from ‘arr’
so size ‘k’ which has unique elements and sum its sum is maximum and
return it’s sum. For example, if, arr = [2, 4, 6, 4, 6, 4, 5, 2] and k=3
The answer would be sum of [6, 4, 5] = 15, cause all other subarray with
unique element have less sum. [6, 4, 6] has sum of 16 but all elements are
not unique.
- [ ] What sorting algorithms you know of tell me their space and time
complexity? Which one will you use to sort a linked list of size n.
- [ ] How would you detect a cycle in linked list.
- [ ] - [https://www.geeksforgeeks.org/given-a-sequence-of-words-print-all-anagrams-together/](https://www.geeksforgeeks.org/given-a-sequence-of-words-print-all-anagrams-together/)
- [ ] 1. [https://www.geeksforgeeks.org/count-minimum-number-of-fountains-to-be-activated-to-cover-the-entire-garden/](https://www.geeksforgeeks.org/count-minimum-number-of-fountains-to-be-activated-to-cover-the-entire-garden/)
- [ ] 1. [https://www.geeksforgeeks.org/decimal-equivalent-of-binary-linked-list/](https://www.geeksforgeeks.org/decimal-equivalent-of-binary-linked-list/)
- [ ] https://leetcode.com/problems/remove-duplicate-letters/description/
- [ ] https://www.geeksforgeeks.org/lexicographically-smallest-string-formed-by-removing-duplicates/
- [ ] https://www.geeksforgeeks.org/program-check-input-character-alphabet-digit-special-character/
- [ ] https://www.geeksforgeeks.org/dsa/find-length-of-longest-substring-with-at-most-k-normal-characters/
- [ ] https://www.educative.io/answers/how-to-check-if-a-number-is-palindrome
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