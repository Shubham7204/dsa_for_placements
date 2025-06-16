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
$$
\text{Probability of Collision} = \frac{6}{8} = \frac{3}{4}
$$

$$
\text{Probability of No Collision} = \frac{2}{8} = \frac{1}{4}
$$
**✅ Final Answer:**  
The **probability that any two ants collide** is **¾ or 75%**.
![](../pics/Pasted%20image%2020250616125947.png)

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

![](../pics/Pasted%20image%2020250616125854.png)

