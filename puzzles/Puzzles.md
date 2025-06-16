### Puzzle 1 : 3 Ants and a Triangle

**Problem Statement:**  
Three ants are sitting at the three corners of a triangle. Each ant randomly chooses one of the two adjacent edges and starts walking along it. What is the probability that **any two ants collide**?

**Explanation:**
![](../pics/Pasted%20image%2020250616125209.png)
![](../pics/Pasted%20image%2020250616125222.png)
- Each ant has **2 possible choices**: it can move either **clockwise (CW)** or **counterclockwise (CCW)** along the triangle.    
- Therefore, the total number of possible direction combinations for the 3 ants is:
    2^3 = 8
- A **collision happens** when **at least two ants meet on the same edge from opposite directions**.
- A **collision does _not_ happen only in 2 specific cases**:
    1. All ants choose to move **clockwise**.
    2. All ants choose to move **counterclockwise**.
- These are the only 2 out of the 8 possible direction combinations where **no two ants collide**.

**Hence:**
- **Number of non-collision cases** = 2
- **Number of collision cases** = 8 − 2 = 6

### Probability Calculations

**Probability of Collision**  
$P(\text{Collision}) = \frac{6}{8} = \frac{3}{4}$

**Probability of No Collision**  
$P(\text{No Collision}) = \frac{2}{8} = \frac{1}{4}$

**✅ Final Answer:**  
The **probability that any two ants collide** is **¾ or 75%**.
![|470x313](../pics/Pasted%20image%2020250616125947.png)

### Puzzle 2 : Heaven and Hell

**Problem Statement:**

You are standing before **two gates**:
- One gate leads to **Heaven**, the other to **Hell**.
    
There are **two gatekeepers**:
- One gatekeeper **always tells the truth**.
- The other **always lies**.
    
You **don’t know which gate leads where**, and you **don’t know which gatekeeper is truthful**.

You are allowed to ask **only one question** to **one gatekeeper**, and based on the answer, you must determine the gate to **Heaven**.
### ✅ Solution:

**Ask the following question to either gatekeeper:**
> “If I were to ask the _other_ gatekeeper which gate leads to Heaven, what would they say?”
Then, **choose the opposite gate** from the one they point to.
### Why This Works:
Let’s consider both possibilities:
#### 1. You ask the **truthful** gatekeeper:
- They will truthfully tell you what the **lying** gatekeeper would say.
- The liar would point you to the **wrong gate (Hell)**.
- So the **truth-teller truthfully repeats the liar’s false answer** → they also point to **Hell**.
#### 2. You ask the **lying** gatekeeper:
- They will **lie about what the truthful** gatekeeper would say.
- The truth-teller would correctly point to **Heaven**, but the liar will **falsely report that they would point to Hell**.
- So again, you are pointed to **Hell**.

In **both cases**, you are directed to the **Hell gate**.  
So, the correct move is to choose the **other gate**, which leads to **Heaven**.

**✅ Final Answer:**
> **“If I asked the other gatekeeper which gate leads to Heaven, what would they say?”**  
> → **Then choose the opposite gate.**

![|0x0](../pics/Pasted%20image%2020250616125854.png)

### Puzzle 3: 10 Coins Puzzle

**Problem Statement:**

You are blindfolded, and there are **10 coins** placed in front of you on a table.  
You are told that exactly **5 coins are heads up** and **5 are tails up**, but you **cannot distinguish heads or tails by touch**.

You are allowed to **touch and flip** the coins as many times as you want, but you **cannot see them**.

**Task:**  
Can you divide the coins into **two piles**, such that **each pile has the same number of heads-up coins**?
### ✅ Solution: **Yes, it is possible.**

### 🔍 How It Works:

1. **Randomly select any 5 coins** and separate them as **Pile 1**.  
    The remaining 5 coins will be **Pile 2**.    
2. **Flip every coin in Pile 1.**

### 💡 Why This Works:

Let’s say in Pile 1, there are `x` coins that are heads up.  
That means in Pile 2, there are `5 - x` heads (since total heads = 5).

Now, when you **flip all 5 coins in Pile 1**:
- The `x` heads become tails.
- The remaining `5 - x` tails become heads.

So after flipping, **Pile 1 now has `5 - x` heads**, and  
**Pile 2 already had `5 - x` heads**.

✅ **Both piles now have an equal number of heads!**

### 🧠 Example:
Initial state (unknown to you, but for understanding):
- **Pile 1**: H T T T T → (1 head)
- **Pile 2**: H H H H T → (4 heads)
Now, flip all coins in Pile 1:
- Becomes: T H H H H → (4 heads)
Both piles now have **4 heads each** 🎯

**✅ Final Answer:**
> Randomly split the coins into two piles of 5, then **flip all coins in one pile**.  
> After flipping, both piles will contain the **same number of heads**.

![|520x292](../pics/10%20Coins%20Puzzle%20__%2010%20Coins%20Blindfolded%20Puzzle%20__%20Interview%20Puzzles%200-53%20screenshot.png)
![|520x292](../pics/10%20Coins%20Puzzle%20__%2010%20Coins%20Blindfolded%20Puzzle%20__%20Interview%20Puzzles%202-27%20screenshot.png)
![|520x292](../pics/10%20Coins%20Puzzle%20__%2010%20Coins%20Blindfolded%20Puzzle%20__%20Interview%20Puzzles%203-3%20screenshot.png)![|523x294](../pics/10%20Coins%20Puzzle%20__%2010%20Coins%20Blindfolded%20Puzzle%20__%20Interview%20Puzzles%203-34%20screenshot.png)

### Puzzle 4: Mislabeled Jars

**Problem Statement:**
You are given **three jars**, each labeled as follows:
- **Jar A**: Candies
- **Jar B**: Sweets
- **Jar C**: Candies and Sweets (Mixed)

However, **all three labels are incorrect**.

You are allowed to **pick only one item** from **any one jar** (just one eatable).  
Each jar contains only **candies**, **sweets**, or a **mixture** of both.  
All eatables are **identical in shape**, so you **cannot distinguish them by touch**—only by seeing what you pick.

**Question:**  
What is the **minimum number of picks** required to correctly **label all the jars**, and how?

![|430x265](../pics/Pasted%20image%2020250616135153.png)
### Answer: **Only 1 pick is needed.**

### 🔍 Explanation:

Since **all the labels are incorrect**, the jar labeled as **"Candies and Sweets"** (Jar C) **cannot** contain the mixture.  
So it must contain either **only candies** or **only sweets**.

**Step-by-step logic:**

1. **Pick one eatable from the jar labeled "Candies and Sweets" (Jar C)**.
    - Suppose you pick a **candy**.
    - That means **Jar C actually contains only candies** (since it cannot be a mixture, as the label is wrong).
2. Now that you know **Jar C contains only candies**, and **its label was "Candies and Sweets" (wrong)**, you can deduce:
    - The jar **labeled "Sweets"** (Jar B) **cannot contain sweets**, so it must contain the **mixture**.
    - That leaves the jar **labeled "Candies"** (Jar A) with **sweets**.
3. Final Correct Labels:
    - **Jar A (originally labeled Candies)** → **Sweets**
    - **Jar B (originally labeled Sweets)** → **Candies and Sweets (Mixture)**
    - **Jar C (originally labeled Candies and Sweets)** → **Candies**
### ✅ Final Answer:

> **Only 1 pick is required—from the jar labeled "Candies and Sweets".**  
> Based on what you draw, you can deduce and correct all three labels logically.

![|496x305](../pics/Pasted%20image%2020250616135207.png)![|499x307](../pics/Pasted%20image%2020250616135220.png)

### Puzzle 5: 50 Red and 50 Blue Marbles

**Problem Statement:**
You are given **two boxes**, each containing **marbles**:
- One box has **50 red marbles**.
- The other has **50 blue marbles**.
    
You can **reshuffle** the marbles between the two boxes **in any way you like**.

Then, a **box is chosen at random** (with equal probability), and **one marble is picked randomly** from that box.

**Your goal:**  
**Maximize the probability** of selecting a **red marble**.

### ✅ Optimal Strategy:
**Place 1 red marble in Box 1 (B1)** and the **remaining 49 red + 50 blue marbles in Box 2 (B2)**.
### 🔍 Explanation:

Let’s define:
- **P(B1)** = probability of choosing Box 1 = ½
- **P(B2)** = probability of choosing Box 2 = ½

Let’s now compute the total probability **P(R)** of picking a red marble.
### 🔢 Step-by-step Calculation:

- **Box 1 (B1):** 1 red marble → P(R | B1) = 1
- **Box 2 (B2):** 49 red, 50 blue → 99 total marbles  
    → P(R | B2) = 49 / 99
### 🎯 Total Probability Formula

**Formula:**  
$P(R) = P(B_1) \cdot P(R \mid B_1) + P(B_2) \cdot P(R \mid B_2)$

**Calculation:**  
$P(R) = \frac{99 + 49}{198} = \frac{148}{198} \approx \mathbf{0.7475}$

### ✅ Final Answer:

> By putting **1 red marble in one box** and **the rest in the other**, you **maximize the probability** of selecting a red marble to approximately **0.7475** (or **74.75%**).

This strategy smartly uses the box selection randomness to boost your chances.

![|549x309](../pics/Probability%20Question%20_%20Can%20you%20solve%20this%20tricky%20Logic%20Puzzle%20_%201-59%20screenshot.png)![|542x305](../pics/Probability%20Question%20_%20Can%20you%20solve%20this%20tricky%20Logic%20Puzzle%20_%202-58%20screenshot.png)![|527x296](../pics/Probability%20Question%20_%20Can%20you%20solve%20this%20tricky%20Logic%20Puzzle%20_%203-14%20screenshot.png)

### Puzzle 6: Minimum Cuts to Pay Daily

**Problem Statement:**  
You hired a worker for **5 days** and have **1 gold bar** to pay them. You must pay **1/5 of the gold bar each day**, at the end of the day.  
You can **cut the gold bar** but want to minimize the number of cuts.

🔸 **What's the _minimum number of cuts_** needed to do this?
### ✅ Answer: **2 cuts**

## Solution Explanation
![](../pics/Pasted%20image%2020250616144235.png)

We need to divide the gold bar in such a way that we can pay the worker daily using **only 2 cuts**.

This can be done in **two ways**, both resulting in daily payments using a combination of **giving and taking back** parts of gold.
### 🔹 **Option 1: Pieces of 1, 2, 2 Units**

Cut the gold bar into:
- One piece of **1 unit**
- Two pieces of **2 units**

Now use this table to pay the worker:

|**Day**|**Gold with Vendor**|**Gold with Worker**|**Action / Comment**|
|---|---|---|---|
|Day 0|[1, 2, 2]|[]|Initial state|
|Day 1|[2, 2]|[1]|Give 1 unit|
|Day 2|[1, 2]|[2]|Take back 1, give 2|
|Day 3|[2]|[1, 2]|Give 1 unit|
|Day 4|[1]|[2, 2]|Take back 1, give other 2|
|Day 5|[]|[1, 2, 2]|Give back 1 unit (total = 5 units)|
✅ **Worker gets exactly 1/5 more each day**

### 🔹 **Option 2: Pieces of 1, 1, 3 Units**
Cut the gold bar into:
- Two pieces of **1 unit**
- One piece of **3 units**

Now use this table:

|**Day**|**Gold with Vendor**|**Gold with Worker**|**Action / Comment**|
|---|---|---|---|
|Day 0|[1, 1, 3]|[]|Initial state|
|Day 1|[1, 3]|[1]|Give 1 unit|
|Day 2|[3]|[1, 1]|Give other 1 unit|
|Day 3|[1, 1]|[3]|Take back both 1s, give 3 unit|
|Day 4|[1]|[1, 3]|Give 1 unit|
|Day 5|[]|[1, 1, 3]|Give final 1 unit (total = 5)|

✅ **Same result—daily payment of exactly 1 unit more**
### ✅ Final Takeaway:

> **Minimum cuts needed: 2**  
> Either divide the gold as **[1, 2, 2]** or **[1, 1, 3]**  
> Use clever **give and take back** method to ensure daily payment

### Puzzle 7: 100 Doors Problem

**Problem Statement:**

There are **100 doors** in a row, all initially **closed**.  
A person walks past the doors **100 times**, and during each pass, they toggle the state of some doors:
- On the **1st pass**, they toggle **every door** (open all).
- On the **2nd pass**, they toggle **every 2nd door** (2, 4, 6, ...).
- On the **3rd pass**, they toggle **every 3rd door** (3, 6, 9, ...).
- ...
- On the **100th pass**, they toggle **only the 100th door**.

**Which doors remain open at the end?**
### ✅ Answer:

> Only the doors with numbers that are **perfect squares** remain open.  
> i.e., **1, 4, 9, 16, 25, 36, 49, 64, 81, 100**
### 🧠 Explanation:

A door is toggled on pass `i` **if `i` is a divisor** of the door number.
#### Example:
- Door 45 is toggled on passes: 1, 3, 5, 9, 15, 45 → total **6 times**
- Since it’s toggled even times → final state is **closed**
#### Key Insight:

- Every door is toggled once for **each of its divisors**
- Most numbers have **even number of divisors** (because divisors come in pairs, like (1, 45), (3, 15))
- But **perfect squares** (like 16) have one **unpaired divisor** (e.g., 4 × 4 = 16), making the total number of divisors **odd**

➡️ Only doors with **odd number of total divisors** stay **open**  
➡️ These correspond to **perfect square** door numbers
### ✅ Final List of Open Doors:

`1, 4, 9, 16, 25, 36, 49, 64, 81, 100`

These are all perfect squares between 1 and 100.
![](../pics/Pasted%20image%2020250616150748.png)
![](../pics/Pasted%20image%2020250616150836.png)
![](../pics/Pasted%20image%2020250616150915.png)
![](../pics/Pasted%20image%2020250616150935.png)
### Puzzle 8: Find the Top 3 Fastest Horses (Out of 25)

**Problem Statement:**

You have **25 horses** and a race track that allows only **5 horses at a time**.  
You can only know the **relative ranking** of horses in a race (not their exact times).  
You must determine the **fastest 3 horses** using the **minimum number of races**.
![](../pics/Pasted%20image%2020250617005147.png)
![](../pics/Pasted%20image%2020250617005153.png)
![](../pics/Pasted%20image%2020250617005200.png)
### ✅ Final Answer: **7 Races**
### 🧠 Step-by-Step Strategy:

#### **Step 1: Grouping and Initial Races (5 races)**
- Divide the 25 horses into **5 groups** of 5 each.
- Run **one race per group** to determine relative ranking within each group.
- After 5 races, you'll have 5 winners: **A1, B1, C1, D1, E1** (first-place horses of each group).

#### **Step 2: Race the Winners (6th race)**
- Race the **5 winners** from each group (A1 to E1).
- Let’s assume the result is:

`1st → A1   2nd → B1   3rd → C1   4th → D1   5th → E1`

So, **A1 is the fastest** horse overall.
Now we need to find **2nd and 3rd fastest horses**.

#### 🧠 Who are potential candidates for 2nd and 3rd?

Only a limited set of horses could possibly beat A1. These are:
1. **A2, A3** – 2nd and 3rd from A1’s group
2. **B1, B2** – 1st and 2nd from group B (since B1 came 2nd overall)
3. **C1** – 1st from group C (since C1 came 3rd in the winners' race)
    
**Why only these?**
- Any horse that came 4th or 5th in a group can’t be in the top 3 overall.
- Similarly, any horse from groups D and E can't be in top 3 because their group winners (D1, E1) lost to A1, B1, and C1.

#### **Step 3: Final Race (7th race)**

Race these **5 horses**:
- A2
- A3
- B1
- B2
- C1

Assume result is:  
`1st → A2, 2nd → B1, 3rd → C1`

✅ Now, the overall top 3 horses are:
1. **A1** (fastest from 6th race)
2. **A2** (winner of 7th race)
3. **B1** (second in 7th race)

### Puzzle 9: Calculate Total Distance Travelled by a Bee

**Problem Statement:**
- Two trains are approaching each other on the same track.
- **Train A speed** = 50 km/h
- **Train B speed** = 70 km/h
- **Initial distance between them** = 100 km
- A bee starts flying from Train A towards Train B at **80 km/h**, and upon reaching a train, it immediately turns around and flies back.    
- This continues until the trains collide.

**Question:** What is the total distance travelled by the bee?
### ✅ Final Answer: **66.67 km (approx)**
![](../pics/Train%20and%20Bee%20Puzzle%20__%20Supersonic%20Bee%20and%20Train%20Puzzle%20__%20Job%20Interview%20Puzzles%206-35%20screenshot.png)

![](../pics/Train%20and%20Bee%20Puzzle%20__%20Supersonic%20Bee%20and%20Train%20Puzzle%20__%20Job%20Interview%20Puzzles%204-29%20screenshot.png)

![](../pics/Train%20and%20Bee%20Puzzle%20__%20Supersonic%20Bee%20and%20Train%20Puzzle%20__%20Job%20Interview%20Puzzles%204-0%20screenshot.png)
### 🧠 Intuition:

At first, this might seem complicated because the bee keeps flying back and forth endlessly. But instead of calculating each leg of the bee’s trip, we apply a **clever trick**:
### 🔍 Key Insight:

> **We just need to calculate how long the bee keeps flying.**

Once we know **how long** the bee flies, and we know the **bee's speed**, we can calculate:
`Total Distance = Bee Speed × Time`
### 🧮 Step-by-Step Calculation:

**Step 1: Find time until trains collide**

- The trains are moving **towards** each other, so their **relative speed** is:
    `50 km/h + 70 km/h = 120 km/h`
- Time to collide:
    `Distance / Relative Speed = 100 km / 120 km/h = 5/6 hours`
**Step 2: Calculate distance travelled by bee**
- Bee's speed = 80 km/h
- Time = 5/6 hours
- So:
    `Distance = 80 × (5/6) = 400/6 = 66.67 km`
### ✅ Final Answer: **The bee travels 66.67 km approximately.**
### 📝 Important Takeaway:

This puzzle is a classic example of **simplifying an infinite loop** (bee's back-and-forth trips) into a simple **distance = speed × time** problem, by calculating total time of the event.

Relative speed refers to the speed of one object as observed from another moving object. It's a fundamental concept in physics, particularly in kinematics.

The formula for relative speed depends on the direction of motion:

1. When two objects are moving in the same direction:
Relative speed = |Speed of object 1 - Speed of object 2|

2. When two objects are moving in opposite directions:
Relative speed = Speed of object 1 + Speed of object 2


### Puzzle 10:** How can you cut a round cake into 8 equal pieces using only 3 straight cuts?**

### ✅ Final Answer: **Stacking method – 3 cuts to make 8 equal pieces**

### 🍰 Step-by-Step Solution:
![](../pics/Pasted%20image%2020250617011041.png)
#### **Step 1: First Cut – Vertical Cut**
- Make a straight vertical cut **down the center** of the cake (as seen from above), dividing it into **2 equal halves**.
#### **Step 2: Second Cut – Another Vertical Cut (Perpendicular)**
- Rotate the cake 90 degrees and make another vertical cut down the center.
- Now, the cake is divided into **4 equal quarters** (like slicing a pizza into 4 slices).
#### **Step 3: Third Cut – Horizontal Cut Through the Middle (Layer-wise)**
- Now, make a **horizontal cut parallel to the base** of the cake (like cutting across layers).
- This slices all 4 pieces **horizontally in half**, creating a **total of 8 equal pieces**.
![](../pics/Pasted%20image%2020250617011053.png)

