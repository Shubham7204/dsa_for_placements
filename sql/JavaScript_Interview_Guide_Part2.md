# Chapter 5: Loops (Continued)

Loops are essential for repeating tasks in programming. Let’s dive into the detailed questions about loops, their types, and when to use them in real-world applications.

## 1. What is a Loop? What are the types of Loops in JavaScript?

A **loop** allows you to run a block of code repeatedly until a condition is met. Here’s a simple diagram to visualize a loop:

**Diagram**:
1. **Start**: Initialize a counter (e.g., `i = 0`).
2. **Condition Check**: If true, execute the code block.
3. **Update Counter**: Increment/decrement, then recheck the condition.
4. **Exit**: Stop when the condition is false.

### Types of Loops
JavaScript supports five loop types:
1. **for**: Fixed iterations.
2. **while**: Condition-based iterations.
3. **do-while**: Runs at least once.
4. **for...of**: Iterates over iterable values (e.g., arrays, strings).
5. **for...in**: Iterates over object properties.

### Example (for Loop)
```javascript
for (let i = 0; i < 3; i++) {
  console.log(i); // 0, 1, 2
}
```

### Definition
**Loop**: A programming construct to execute a code block repeatedly until a condition is met. Types include `for`, `while`, `do-while`, `for...of`, and `for...in`.

## 2. What is the difference between `while` and `for` Loops? When to use each?

- **`for` Loop**: Ideal for a known number of iterations, with initialization, condition, and increment in one line.
- **`while` Loop**: Best for condition-based iterations, where the number of iterations is unknown.

### Example
**for Loop**:
```javascript
for (let i = 0; i < 3; i++) {
  console.log(i); // 0, 1, 2
}
```

**while Loop**:
```javascript
let i = 0;
while (i < 3) {
  console.log(i); // 0, 1, 2
  i++;
}
```

**while Loop (Condition Only)**:
```javascript
let condition = true;
while (condition) {
  console.log("Running...");
  break; // Prevents infinite loop
}
```

### When to Use
- **for Loop**: Use when iterating over arrays or a fixed range (e.g., rendering list items).
- **while Loop**: Use when iterations depend on a dynamic condition (e.g., reading data until none remains).

### Definition
**for vs. while**: `for` loops are compact for fixed iterations with initialization and increment; `while` loops are flexible for condition-based iterations without requiring counters.

## 3. What is the difference between `while` and `do-while` Loops?

- **`while` Loop**: Checks the condition before executing; skips if the condition is false.
- **`do-while` Loop**: Executes at least once, then checks the condition.

### Diagram
- **while**: `Condition → Code → Exit (if false)`.
- **do-while**: `Code → Condition → Repeat (if true)`.

### Example
**while Loop**:
```javascript
let k = 0;
while (k > 1) {
  console.log(k); // Skipped (condition false)
}
```

**do-while Loop**:
```javascript
let k = 0;
do {
  console.log(k); // 0 (runs once)
  k++;
} while (k > 1);
```

### Definition
**while vs. do-while**: `while` checks the condition first and may not run; `do-while` runs at least once before checking.

## 4. What is the difference between `break` and `continue` Statements?

- **`break`**: Terminates the loop entirely.
- **`continue`**: Skips the current iteration, moving to the next.

### Example
**break**:
```javascript
for (let i = 1; i <= 5; i++) {
  if (i === 3) break;
  console.log(i); // 1, 2
}
```

**continue**:
```javascript
for (let i = 1; i <= 5; i++) {
  if (i === 3) continue;
  console.log(i); // 1, 2, 4, 5
}
```

### Definition
**break vs. continue**: `break` exits the loop; `continue` skips the current iteration and continues the loop.

## 5. What is the difference between `for` and `for...of` Loops?

- **`for` Loop**: General-purpose, requires manual index management.
- **`for...of` Loop**: Simplified for iterating over iterable values (e.g., arrays, strings).

### Example
**for Loop**:
```javascript
let arr = ["A", "B", "C"];
for (let i = 0; i < arr.length; i++) {
  console.log(arr[i]); // A, B, C
}
```

**for...of Loop**:
```javascript
let arr = ["A", "B", "C"];
for (let val of arr) {
  console.log(val); // A, B, C
}
```

### When to Use
- **for Loop**: Use for complex iterations or non-iterable data.
- **for...of Loop**: Use for simple iteration over arrays or strings.

### Definition
**for vs. for...of**: `for` loops are versatile with manual index control; `for...of` loops are concise for iterating iterable values.

## 6. What is the difference between `for...of` and `for...in` Loops?

- **`for...of`**: Iterates over values of iterables (e.g., arrays, strings).
- **`for...in`**: Iterates over enumerable properties (keys) of objects.

### Example
**for...of**:
```javascript
let arr = ["A", "B", "C"];
for (let val of arr) {
  console.log(val); // A, B, C
}
```

**for...in**:
```javascript
let obj = { a: 1, b: 2, c: 3 };
for (let key in obj) {
  console.log(key, obj[key]); // a 1, b 2, c 3
}
```

### Definition
**for...of vs. for...in**: `for...of` iterates over values of iterables; `for...in` iterates over object keys.

## 7. What is the purpose of the `forEach` method? Compare it with `for...of` and `for...in` Loops.

The `forEach` method iterates over arrays or objects, executing a callback for each element.

### Example
**forEach (Array)**:
```javascript
let arr = ["A", "B", "C"];
arr.forEach(val => console.log(val)); // A, B, C
```

**forEach (Object)**:
```javascript
let person = { name: "John", age: 30 };
Object.values(person).forEach(val => console.log(val)); // John, 30
Object.keys(person).forEach(key => console.log(key)); // name, age
```

**for...of (Array)**:
```javascript
let arr = ["A", "B", "C"];
for (let val of arr) {
  console.log(val); // A, B, C
}
```

**for...in (Object)**:
```javascript
let person = { name: "John", age: 30 };
for (let key in person) {
  console.log(key, person[key]); // name John, age 30
}
```

### Comparison
- **forEach vs. for...of**:
  - `forEach`: More concise, uses a callback, but cannot use `break` or `continue`.
  - `for...of`: Requires a variable, supports `break` and `continue`.
- **forEach vs. for...in**:
  - `forEach`: Works with `Object.keys` or `Object.values` for objects, more flexible for arrays.
  - `for...in`: Simpler syntax for object properties.

### Example (break/continue Limitation)
**for...of**:
```javascript
let arr = [1, 2, 3, 4];
for (let val of arr) {
  if (val === 3) break;
  console.log(val); // 1, 2
}
```

**forEach (Error)**:
```javascript
let arr = [1, 2, 3, 4];
arr.forEach(val => {
  if (val === 3) break; // Error: Illegal break statement
  console.log(val);
});
```

### When to Use
- **forEach**: When you need to iterate all elements without breaking (e.g., logging, simple transformations).
- **for...of**: When you need control with `break` or `continue` for arrays/strings.
- **for...in**: When iterating object properties.

### Definition
**forEach**: An array/object method that iterates elements with a callback, ideal for full iterations without breaks.

---

# Chapter 6: Functions

Functions are the heart of JavaScript, enabling reusable and modular code. Let’s explore 12 questions covering all aspects of functions.

## 1. What are Functions in JavaScript? What are the types?

A **function** is a reusable block of code performing a specific task, defined with parameters and a body.

### Example
```javascript
function add(a, b) {
  return a + b;
}
let result = add(3, 4); // 7
console.log(result);
```

### Types of Functions
1. **Named Functions**: Have a name identifier.
2. **Anonymous Functions**: No name, often used as callbacks.
3. **Function Expressions**: Functions assigned to variables.
4. **Arrow Functions**: Concise syntax with `=>`.
5. **IIFE**: Immediately Invoked Function Expressions.
6. **Callback Functions**: Passed as arguments to other functions.
7. **Higher-Order Functions**: Accept or return functions.

### Definition
**Functions**: Reusable code blocks for specific tasks. Types include named, anonymous, function expressions, arrow, IIFE, callback, and higher-order functions.

## 2. What is the difference between Named and Anonymous Functions?

- **Named Functions**: Have a name, reusable across multiple places.
- **Anonymous Functions**: No name, used for one-off tasks.

### Example
**Named Function**:
```javascript
function sum(a, b) {
  return a * b;
}
console.log(sum(4, 5)); // 20
```

**Anonymous Function**:
```javascript
console.log((function(a, b) { return a * b; })(4, 5)); // 20
```

### When to Use
- **Named**: For complex, reusable logic (e.g., utility functions).
- **Anonymous**: For simple, one-time tasks (e.g., event listeners).

### Definition
**Named vs. Anonymous**: Named functions have identifiers for reuse; anonymous functions lack names, used for single-use logic.

## 3. What is a Function Expression?

A **function expression** assigns a function (usually anonymous) to a variable.

### Example
**Anonymous Function Expression**:
```javascript
let add = function(a, b) {
  return a + b;
};
console.log(add(3, 5)); // 8
```

**Named Function Expression** (Less Common):
```javascript
let add = function sum(a, b) {
  return a + b;
};
console.log(add(3, 5)); // 8
// console.log(sum(3, 5)); // Error: sum is not defined
```

### Definition
**Function Expression**: A function assigned to a variable, typically anonymous, for dynamic use.

## 4. What are Arrow Functions? What is their use?

**Arrow functions** provide a concise syntax for writing functions, introduced in ES6.

### Example
**Traditional Function**:
```javascript
function add(x, y) {
  return x + y;
}
console.log(add(2, 3)); // 5
```

**Arrow Function**:
```javascript
let add = (x, y) => x + y; // Implicit return
console.log(add(2, 3)); // 5
```

### Key Points
- No `return` needed for single expressions.
- Empty `()` for no parameters.
- No `this` binding (uses parent context).

### Definition
**Arrow Functions**: Concise function syntax (`=>`) for shorter, simpler code, often used in callbacks.

## 5. What are Callback Functions? What is their use?

A **callback function** is a function passed as an argument to another function, executed later.

### Example
```javascript
function add(x, y) {
  return x + y;
}
function display(operation, x, y) {
  let result = operation(x, y);
  console.log(`Result: ${result}`);
}
display(add, 3, 4); // Result: 7
```

### Benefits
- **Modularity**: Centralizes logic (e.g., `display` handles output).
- **Reusability**: Pass different functions (e.g., `multiply`, `subtract`) to the same higher-order function.
- **Clean Code**: Organizes complex logic in large applications.

### Definition
**Callback Functions**: Functions passed as arguments to other functions, enhancing modularity and reusability.

## 6. What is a Higher-Order Function?

A **higher-order function** either:
1. Takes one or more functions as arguments.
2. Returns a function as a result.

### Example
**Accepting a Function**:
```javascript
function hof(func, x) {
  return func(x);
}
let double = x => x * 2;
console.log(hof(double, 5)); // 10
```

**Returning a Function**:
```javascript
function createAdder(number) {
  return function(value) {
    return value + number;
  };
}
let add5 = createAdder(5);
console.log(add5(2)); // 7
```

### Definition
**Higher-Order Functions**: Functions that accept other functions as arguments or return functions, enabling flexible logic.

## 7. What is the difference between Arguments and Parameters?

- **Parameters**: Placeholders defined in a function declaration.
- **Arguments**: Actual values passed when calling the function.

### Example
```javascript
function add(a, b) { // a, b are parameters
  return a + b;
}
console.log(add(3, 4)); // 3, 4 are arguments
```

### Definition
**Parameters vs. Arguments**: Parameters are placeholders in function definitions; arguments are values passed during function calls.

## 8. How many ways can you pass Arguments to a Function?

JavaScript supports three ways to pass arguments:
1. **Positional Arguments**: Standard approach, passing values in order.
2. **Named Arguments**: Passing an object with key-value pairs.
3. **Arguments Object**: Using the built-in `arguments` object for dynamic arguments.

### Example
**Positional Arguments**:
```javascript
function add(a, b) {
  return a + b;
}
console.log(add(3, 4)); // 7
```

**Named Arguments**:
```javascript
function greet({ name, age }) {
  console.log(`Hello ${name}, age ${age}`);
}
let person = { name: "John", age: 30 };
greet(person); // Hello John, age 30
```

**Arguments Object**:
```javascript
function sum() {
  let total = 0;
  for (let i = 0; i < arguments.length; i++) {
    total += arguments[i];
  }
  return total;
}
console.log(sum(1, 2, 3)); // 6
```

### Definition
**Argument Passing**: Pass arguments positionally, as named objects, or via the `arguments` object for flexibility.

## 9. How do you use Default Parameters in a Function?

**Default parameters** allow setting fallback values for function parameters if no argument is provided.

### Example
```javascript
function greet(name = "Happy") {
  console.log(`Hello ${name}`);
}
greet(); // Hello Happy
greet("Amit"); // Hello Amit
```

### Definition
**Default Parameters**: Specify default values for function parameters, used when arguments are omitted.

## 10. What is the purpose of Event Handling in JavaScript?

**Event handling** responds to user actions (e.g., clicks, keypresses) on a web page, making it interactive.

### Example
**Anonymous Callback**:
```javascript
let button = document.getElementById("myButton");
button.addEventListener("click", () => {
  alert("Button clicked!");
});
```

**Named Callback**:
```javascript
function handleClick() {
  alert("Button clicked!");
}
let button = document.getElementById("myButton");
button.addEventListener("click", handleClick);
```

### Common Events
- `click`, `mouseover`, `keydown`, `keyup`, `submit`, `focus`, `blur`, `change`, `load`, `resize`.

### Definition
**Event Handling**: Responding to user actions using `addEventListener` to attach events and callback functions.

## 11. What are First-Class Functions in JavaScript?

JavaScript treats functions as **first-class citizens**, meaning they can:
1. Be assigned to variables.
2. Be passed as arguments.
3. Be returned from functions.

### Example
**Assign to Variable**:
```javascript
let sayHello = function() {
  console.log("Hello");
};
sayHello(); // Hello
```

**Pass as Argument**:
```javascript
function hof(func) {
  func();
}
hof(() => console.log("Callback")); // Callback
```

**Return a Function**:
```javascript
function createGreeter() {
  return function(name) {
    console.log(`Hello ${name}`);
  };
}
let greet = createGreeter();
greet("John"); // Hello John
```

### Definition
**First-Class Functions**: Functions treated like variables, assignable, passable, and returnable.

## 12. What are Pure and Impure Functions?

- **Pure Functions**: Always produce the same output for the same input, with no side effects.
- **Impure Functions**: May produce different outputs for the same input, often with side effects.

### Example
**Pure Function**:
```javascript
function add(a, b) {
  return a + b;
}
console.log(add(2, 3)); // 5 (always same)
```

**Impure Function**:
```javascript
let total = 0;
function addToTotal(value) {
  total += value; // Modifies external state
  return total;
}
console.log(addToTotal(5)); // 5
console.log(addToTotal(5)); // 10 (different output)
```

### Differences
1. **Consistency**:
   - Pure: Same input, same output.
   - Impure: Same input, different output possible.
2. **State Modification**:
   - Pure: No external state changes.
   - Impure: Can modify external state.
3. **Side Effects**:
   - Pure: None (e.g., no logging, no external updates).
   - Impure: Can have side effects (e.g., updating globals).

### Definition
**Pure vs. Impure Functions**: Pure functions are predictable with no side effects; impure functions may alter state or produce side effects.

## 13. What is Function Currying in JavaScript?

**Function currying** transforms a function with multiple arguments into a series of nested functions, each taking a single argument.

### Example
**Regular Function**:
```javascript
function multiply(a, b) {
  return a * b;
}
console.log(multiply(2, 3)); // 6
```

**Curried Function**:
```javascript
function curriedMultiply(a) {
  return function(b) {
    return a * b;
  };
}
let double = curriedMultiply(2);
console.log(double(3)); // 6
let triple = curriedMultiply(3);
console.log(triple(3)); // 9
```

### Benefits
- **Reusability**: Create specialized functions (e.g., `double`, `triple`).
- **Modularity**: Break complex logic into smaller functions.
- **Specialization**: Reuse curried functions across contexts.

### Definition
**Function Currying**: Transforms a multi-argument function into nested single-argument functions for reusability and modularity.

## 14. What are `call`, `apply`, and `bind` in JavaScript?

These methods control the `this` context and argument passing for functions.

### Example
```javascript
function sayHello(message) {
  console.log(`${message}, ${this.name}`);
}
let person = { name: "John" };
```

**call**:
```javascript
sayHello.call(person, "Hello"); // Hello, John
```

**apply**:
```javascript
sayHello.apply(person, ["Hello"]); // Hello, John
```

**bind**:
```javascript
let greet = sayHello.bind(person);
greet("Hello"); // Hello, John
```

### Differences
- **`call`**: Invokes the function with a specified `this` and individual arguments.
- **`apply`**: Invokes the function with a specified `this` and an array of arguments.
- **`bind`**: Returns a new function with a fixed `this`, invoked later.

### Definition
**call, apply, bind**: Methods to manipulate `this` context and pass arguments, with `call` and `apply` invoking immediately and `bind` creating a reusable function.

---

# Chapter 7: Strings

Strings are crucial for handling text data. Let’s cover six questions on strings and their operations.

## 1. What is a String?

A **string** is a data type for storing and manipulating text, typically defined with quotes.

### Example
```javascript
let str = "Hello World";
console.log(str); // Hello World
```

### Definition
**String**: A data type for storing and manipulating text, defined with single or double quotes.

## 2. What are Template Literals and String Interpolation?

**Template literals** (ES6) use backticks (\`) for multi-line strings and interpolation, embedding variables with `${}`.

### Example
```javascript
let name = "Happy";
let greeting = `Hello ${name}`; // String interpolation
console.log(greeting); // Hello Happy

// Multi-line
let multiLine = `Line 1
Line 2`;
console.log(multiLine);
```

### Definition
**Template Literals**: ES6 feature for string interpolation (`${variable}`) and multi-line strings using backticks.

## 3. What is the difference between Single Quotes, Double Quotes, and Backticks?

- **Single Quotes (`'`)**: Define standard strings.
- **Double Quotes (`"`)**: Identical to single quotes, less common.
- **Backticks (\`)**: Define template literals for interpolation and multi-line strings.

### Example
```javascript
let single = 'Hello';
let double = "World";
let template = `Hello ${single}`; // Interpolation
console.log(single, double, template); // Hello World Hello
```

### Definition
**Quotes vs. Backticks**: Single/double quotes define standard strings; backticks enable template literals for interpolation and multi-line strings.

## 4. What are some important String Operations in JavaScript?

JavaScript provides methods for string manipulation.

### Example
```javascript
let result = "Hello World";

// Concatenation
console.log(result + "!"); // Hello World!
console.log(result.concat("!")); // Hello World!

// Substring
let sub = result.substring(6, 11); // World
console.log(sub);

// Length
console.log(result.length); // 11

// Case Conversion
console.log(result.toUpperCase()); // HELLO WORLD
console.log(result.toLowerCase()); // hello world

// Split
let arr = result.split(" "); // ["Hello", "World"]
console.log(arr);

// Replace
let newStr = result.replace("World", "JavaScript"); // Hello JavaScript
console.log(newStr);

// Trim
let str = "  Hello  ";
console.log(str.trim()); // Hello
```

### Definition
**String Operations**: Include concatenation (`+`, `concat`), `substring`, `length`, `toUpperCase`, `toLowerCase`, `split`, `replace`, and `trim` for text manipulation.

## 5. What is String Immutability?

**String immutability** means strings cannot be modified in place; changes create a new string in memory.

### Example
```javascript
let str = "Hello";
str = str + " World"; // New string created
console.log(str); // Hello World
```

### Explanation
- JavaScript’s engine allocates memory for `str` at address A with value `"Hello"`.
- Concatenation creates a new string at address B with value `"Hello World"`.
- The original string at A remains unchanged.

### Definition
**String Immutability**: Strings cannot be modified directly; operations create new strings in memory.

## 6. In how many ways can you concatenate Strings?

JavaScript offers four ways to concatenate strings:
1. **Plus Operator (`+`)**: Simple concatenation.
2. **concat Method**: Method-based concatenation.
3. **Template Literals**: Using backticks and interpolation.
4. **join Method**: Joining array elements.

### Example
```javascript
let s1 = "Hello";
let s2 = "World";

// Plus Operator
console.log(s1 + " " + s2); // Hello World

// concat Method
console.log(s1.concat(" ", s2)); // Hello World

// Template Literals
console.log(`${s1} ${s2}`); // Hello World

// join Method
let arr = [s1, s2];
console.log(arr.join(" ")); // Hello World
```

### Definition
**String Concatenation**: Combine strings using `+`, `concat`, template literals, or `join` methods.

---

# Final Interview Tips
- **Memorize Key Terms**: Use terms like “hoisting,” “scope,” or “immutability” to impress interviewers.
- **Practice Code**: Run all snippets in a code editor to solidify understanding.
- **Revise Definitions**: Focus on 3–4 key points per question for quick recall.
- **Explain with Examples**: Use diagrams or code to clarify concepts in interviews.
- **Stay Resilient**: Keep applying, even after setbacks—your job is coming!
- **Share Your Success**: Comment with your job offer story to inspire others.

Congratulations on completing Part 2 of this JavaScript interview guide! You’ve mastered **Loops**, **Functions**, and **Strings**, bringing you closer to acing your interviews. Stay tuned for Part 3, covering **DOM**, **Error Handling**, **Objects**, and **Events**. Keep practicing, and best of luck!