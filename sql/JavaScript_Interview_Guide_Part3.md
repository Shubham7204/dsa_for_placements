# Chapter 8: DOM (Document Object Model)

The **Document Object Model (DOM)** is a cornerstone of web development, enabling JavaScript to dynamically manipulate web pages. This chapter covers how to select, modify, create, and remove DOM elements, with detailed explanations and code snippets.

## 1. What is the DOM? What is the difference between HTML and the DOM?

The **DOM** is a tree-like representation of a web page’s structure, allowing JavaScript to dynamically access and manipulate its content. HTML, on the other hand, is the static markup language defining the page’s structure.

### Example
**HTML**:
```html
<html>
  <head>
    <title>My Page</title>
  </head>
  <body>
    <p>Hello World</p>
  </body>
</html>
```

**DOM Representation** (Simplified):
```
Document
└── html
    ├── head
    │   └── title: "My Page"
    └── body
        └── p: "Hello World"
```

### Explanation
- **HTML**: A text-based markup for developers to write and read.
- **DOM**: A memory-based tree structure (nodes) that browsers use to render and manipulate the page.
- **Dynamic Updates**: JavaScript modifies the DOM (e.g., adding a `<p>`), which updates the HTML displayed.

### Definition
**DOM**: The Document Object Model represents a web page as a tree-like structure, enabling JavaScript to dynamically access and manipulate content. **HTML vs. DOM**: HTML is static markup; DOM is the dynamic, in-memory representation.

## 2. How do you select, modify, create, and remove DOM elements?

JavaScript provides methods to interact with the DOM in four categories:
1. **Selecting**: `getElementById`, `getElementsByClassName`, `getElementsByTagName`, `querySelector`, `querySelectorAll`.
2. **Modifying**: `textContent`, `innerHTML`, `setAttribute`, `removeAttribute`, `style.setProperty`, `classList.add/remove/toggle`.
3. **Creating**: `createElement`, `createTextNode`, `cloneNode`, `appendChild`.
4. **Removing**: `remove`, `removeChild`.
5. **Event Handling**: `addEventListener`, `removeEventListener`.

### Definition
**DOM Manipulation**: Selecting, modifying, creating, and removing elements to make web pages dynamic.

## 3. What are Selectors in JavaScript?

**Selectors** retrieve specific DOM elements based on IDs, classes, or tags.

### Example
```html
<div id="myDiv">Hello</div>
```
```javascript
let element = document.getElementById("myDiv");
console.log(element.textContent); // Hello
```

### Common Selectors
1. `getElementById`: Selects a single element by ID.
2. `getElementsByClassName`: Selects multiple elements by class (returns HTMLCollection).
3. `getElementsByTagName`: Selects multiple elements by tag (returns HTMLCollection).
4. `querySelector`: Selects the first matching element (CSS selector).
5. `querySelectorAll`: Selects all matching elements (returns NodeList).

### Definition
**Selectors**: JavaScript methods to retrieve DOM elements by ID, class, or tag for manipulation.

## 4. What is the difference between `getElementById`, `getElementsByClassName`, and `getElementsByTagName`?

- **`getElementById`**: Selects one element by unique ID.
- **`getElementsByClassName`**: Selects multiple elements by class name (HTMLCollection).
- **`getElementsByTagName`**: Selects multiple elements by tag name (HTMLCollection).

### Example
```html
<div id="myId">ID Element</div>
<div class="myClass">Class 1</div>
<div class="myClass">Class 2</div>
<p>Paragraph 1</p>
<p>Paragraph 2</p>
```

**getElementById**:
```javascript
let idElement = document.getElementById("myId");
console.log(idElement.textContent); // ID Element
```

**getElementsByClassName**:
```javascript
let classElements = document.getElementsByClassName("myClass");
for (let i = 0; i < classElements.length; i++) {
  console.log(classElements[i].textContent); // Class 1, Class 2
}
```

**getElementsByTagName**:
```javascript
let tagElements = document.getElementsByTagName("p");
for (let i = 0; i < tagElements.length; i++) {
  console.log(tagElements[i].textContent); // Paragraph 1, Paragraph 2
}
```

### Key Points
- **HTMLCollection**: Array-like, supports `length` and indexing, but not array methods like `push`.
- **Use Cases**:
  - `getElementById`: For unique elements (e.g., form inputs).
  - `getElementsByClassName`: For styling multiple elements with the same class.
  - `getElementsByTagName`: For tag-based operations (e.g., updating all `<p>` tags).

### Definition
**getElementById vs. getElementsByClassName vs. getElementsByTagName**: `getElementById` selects one element by ID; others select multiple elements by class or tag, returning an HTMLCollection.

## 5. What is the difference between `querySelector` and `querySelectorAll`?

- **`querySelector`**: Returns the first element matching a CSS selector.
- **`querySelectorAll`**: Returns all matching elements (NodeList).

### Example
```html
<div class="myClass">Element 1</div>
<div class="myClass">Element 2</div>
```

**querySelector**:
```javascript
let element = document.querySelector(".myClass");
console.log(element.textContent); // Element 1
```

**querySelectorAll**:
```javascript
let elements = document.querySelectorAll(".myClass");
elements.forEach(el => console.log(el.textContent)); // Element 1, Element 2
```

### Key Points
- **NodeList**: Array-like, supports `forEach`, unlike HTMLCollection.
- **Use Cases**:
  - `querySelector`: For single-element updates (e.g., a specific button).
  - `querySelectorAll`: For batch operations (e.g., styling all elements with a class).

### Definition
**querySelector vs. querySelectorAll**: `querySelector` selects the first matching element; `querySelectorAll` selects all, returning a NodeList.

## 6. What are the methods to modify elements’ properties and attributes?

JavaScript provides methods to update element content, attributes, and styles.

### Common Methods
1. `textContent`: Sets plain text content.
2. `innerHTML`: Sets HTML content.
3. `setAttribute`: Adds/modifies attributes.
4. `removeAttribute`: Removes attributes.
5. `style.setProperty`: Sets CSS properties.
6. `classList.add/remove/toggle`: Manages CSS classes.

### Definition
**Modifying DOM**: Methods like `textContent`, `innerHTML`, `setAttribute`, and `classList` update element properties and attributes.

## 7. What is the difference between `innerHTML` and `textContent`?

- **`textContent`**: Sets/gets plain text, ignoring HTML tags.
- **`innerHTML`**: Sets/gets HTML content, rendering tags.

### Example
```html
<div id="element1">Hello</div>
<div id="element2">World</div>
```

```javascript
let el1 = document.getElementById("element1");
let el2 = document.getElementById("element2");

el1.textContent = "Plain Text"; // Sets plain text
el2.innerHTML = "<strong>Happy</strong>"; // Renders as bold

console.log(el1.textContent); // Plain Text
console.log(el2.innerHTML); // <strong>Happy</strong>
```

### Output in Browser
- `element1`: "Plain Text" (plain text).
- `element2`: "Happy" (bold due to `<strong>`).

### When to Use
- **textContent**: For safe text updates (e.g., user input display).
- **innerHTML**: For rendering HTML (e.g., dynamic components).

### Definition
**innerHTML vs. textContent**: `textContent` handles plain text; `innerHTML` renders HTML content.

## 8. How to add and remove properties of HTML elements in the DOM?

Use `setAttribute` to add/modify attributes and `removeAttribute` to delete them.

### Example
```html
<div id="myElement">Content</div>
```

**Add Attribute**:
```javascript
let element = document.getElementById("myElement");
element.setAttribute("data-info", "newValue");
console.log(element.getAttribute("data-info")); // newValue
```

**Remove Attribute**:
```javascript
element.removeAttribute("data-info");
console.log(element.getAttribute("data-info")); // null
```

### Output in Browser
```html
<!-- After setAttribute -->
<div id="myElement" data-info="newValue">Content</div>
<!-- After removeAttribute -->
<div id="myElement">Content</div>
```

### Definition
**Add/Remove Attributes**: `setAttribute` adds/modifies attributes; `removeAttribute` deletes them.

## 9. How to add and remove styles from HTML elements in the DOM?

Use `style.setProperty` for inline styles and `classList` methods for CSS classes.

### Example
```html
<div id="myElement">Content</div>
<style>
  .highlight { background-color: yellow; }
</style>
```

```javascript
let element = document.getElementById("myElement");

// Add Style
element.style.setProperty("color", "blue");
element.classList.add("highlight");

// Remove Style
element.classList.remove("highlight");

// Toggle Style
element.classList.toggle("highlight"); // Adds if absent, removes if present
```

### Output in Browser
```html
<!-- After setProperty and classList.add -->
<div id="myElement" class="highlight" style="color: blue;">Content</div>
<!-- After classList.remove -->
<div id="myElement" style="color: blue;">Content</div>
```

### Definition
**Add/Remove Styles**: `style.setProperty` sets inline styles; `classList.add/remove/toggle` manages CSS classes.

## 10. How to create new elements in the DOM? What is the difference between `createElement` and `cloneNode`?

- **`createElement`**: Creates a new DOM element.
- **`cloneNode`**: Copies an existing element (with or without children).

### Example
**createElement**:
```html
<div id="parent"></div>
```
```javascript
let newDiv = document.createElement("div");
newDiv.textContent = "New Element";
document.getElementById("parent").appendChild(newDiv);
```

**cloneNode**:
```html
<div id="parent">Original</div>
```
```javascript
let parent = document.getElementById("parent");
let cloned = parent.cloneNode(true); // true copies children
cloned.textContent = "Cloned Element";
document.body.appendChild(cloned);
```

### Output in Browser
```html
<!-- createElement -->
<div id="parent"><div>New Element</div></div>
<!-- cloneNode -->
<div id="parent">Original</div><div id="parent">Cloned Element</div>
```

### Differences
- **createElement**: Creates a fresh element from scratch.
- **cloneNode**: Duplicates an existing element, copying its attributes and (if `true`) children.

### Definition
**createElement vs. cloneNode**: `createElement` creates new elements; `cloneNode` copies existing ones, optionally including children.

## 11. What is the difference between `createElement` and `createTextNode`?

- **`createElement`**: Creates a new HTML element (e.g., `<div>`).
- **`createTextNode`**: Creates a text node for an element’s content.

### Example
**createElement**:
```html
<div id="parent"></div>
```
```javascript
let newDiv = document.createElement("div");
newDiv.textContent = "New Div";
document.getElementById("parent").appendChild(newDiv);
```

**createTextNode**:
```html
<div id="parent">Existing</div>
```
```javascript
let parent = document.getElementById("parent");
let text = document.createTextNode(" New Text");
parent.appendChild(text);
```

### Output in Browser
```html
<!-- createElement -->
<div id="parent"><div>New Div</div></div>
<!-- createTextNode -->
<div id="parent">Existing New Text</div>
```

### Definition
**createElement vs. createTextNode**: `createElement` creates new HTML elements; `createTextNode` adds text nodes to existing elements.

---

# Chapter 9: Error Handling

Error handling ensures robust applications by managing runtime errors gracefully. This chapter covers key concepts and best practices.

## 1. What is Error Handling in JavaScript?

**Error handling** manages errors to prevent application crashes and provide meaningful feedback.

### Example
```javascript
try {
  console.log(undefinedVar); // ReferenceError
} catch (error) {
  console.log("Error occurred:", error.message); // Error occurred: undefinedVar is not defined
}
```

### Flow Diagram
```
Start → Try Block → Error? → Catch Block → End
          ↓ No Error    ↓
        Execute Code    Skip Catch
```

### Definition
**Error Handling**: The process of managing errors using `try`, `catch`, `finally`, and `throw` to ensure robust code execution.

## 2. What is the role of the `finally` Block?

The **`finally` block** executes code regardless of whether an error occurs.

### Example
```javascript
try {
  console.log("Trying...");
  throw new Error("Test Error");
} catch (error) {
  console.log("Caught:", error.message);
} finally {
  console.log("Finally executed"); // Always runs
}
```

### Output
```
Trying...
Caught: Test Error
Finally executed
```

### Definition
**finally Block**: Executes code after `try`/`catch`, regardless of errors, for cleanup or logging.

## 3. What is the purpose of the `throw` Statement?

The **`throw` statement** passes an error from a called function to the caller’s `catch` block.

### Example
```javascript
function validateUserAge(age) {
  if (typeof age !== "number") {
    throw new Error("Age must be a number");
  }
  return age;
}

function userData(age) {
  try {
    validateUserAge(age);
    console.log("Valid age");
  } catch (error) {
    console.log("Error:", error.message);
  }
}

userData("invalid"); // Error: Age must be a number
```

### Definition
**throw Statement**: Stops function execution and passes an error to the caller’s `catch` block.

## 4. What is Error Propagation?

**Error propagation** passes errors from a called function to the caller using `throw`.

### Example
```javascript
function inner() {
  throw new Error("Inner error");
}
function outer() {
  try {
    inner();
  } catch (error) {
    console.log(error.message); // Inner error
  }
}
outer();
```

### Definition
**Error Propagation**: Passing errors from called functions to callers using `throw` and `try`/`catch`.

## 5. What are the best practices for Error Handling?

1. **Use try/catch**: Always wrap risky code in `try`/`catch`.
2. **Descriptive Messages**: Use clear error messages (e.g., “Invalid input” vs. “Error”).
3. **Avoid Swallowing Errors**: Never leave `catch` blocks empty, as it hides issues.
4. **Log Errors**: Log errors for debugging and analysis.

### Example
```javascript
try {
  let data = JSON.parse(invalidJson); // SyntaxError
} catch (error) {
  console.error("Parsing failed:", error.message); // Log error
}
```

### Definition
**Error Handling Best Practices**: Use `try`/`catch`, descriptive messages, avoid empty `catch`, and log errors.

## 6. What are the different types of Errors in JavaScript?

JavaScript has four common error types:
1. **SyntaxError**: Incorrect syntax (e.g., missing parenthesis).
2. **ReferenceError**: Accessing undefined variables.
3. **TypeError**: Using incorrect types (e.g., calling a string method on a number).
4. **RangeError**: Accessing out-of-bounds indices.

### Example
**SyntaxError**:
```javascript
console.log("Hello"; // SyntaxError: missing )
```

**ReferenceError**:
```javascript
console.log(undefinedVar); // ReferenceError: undefinedVar is not defined
```

**TypeError**:
```javascript
let num = 123;
num.toUpperCase(); // TypeError: toUpperCase is not a function
```

**RangeError**:
```javascript
let arr = [1, 2, 3];
arr[10]; // RangeError: Invalid array length
```

### Definition
**Error Types**: `SyntaxError` (syntax issues), `ReferenceError` (undefined variables), `TypeError` (wrong type operations), `RangeError` (out-of-bounds access).

---

# Chapter 10: Objects

Objects are fundamental for storing and managing data as key-value pairs. This chapter covers object creation, manipulation, and advanced structures like `Set` and `Map`.

## 1. What are Objects in JavaScript?

An **object** is a data type representing real-world entities with properties (key-value pairs) and methods.

### Example
```javascript
let person = {
  name: "John",
  hobbies: ["reading", "gaming"],
  greet: function() {
    return `Hello, ${this.name}`;
  }
};
console.log(person.name); // John
console.log(person.hobbies[0]); // reading
console.log(person.greet()); // Hello, John
```

### Property Types
- Strings, numbers, arrays, functions, nested objects.

### Definition
**Objects**: Data types storing key-value pairs, representing real-world entities with properties and methods.

## 2. In how many ways can you create an Object?

JavaScript offers three ways to create objects:
1. **Object Literal**: Most common, using `{}`.
2. **Object Constructor**: Using `new Object()`.
3. **Object.create**: Inheriting from a parent object.

### Example
**Object Literal**:
```javascript
let person = {
  name: "John",
  age: 30
};
console.log(person); // { name: "John", age: 30 }
```

**Object Constructor**:
```javascript
let person = new Object();
person.name = "John";
person.age = 30;
console.log(person); // { name: "John", age: 30 }
```

**Object.create**:
```javascript
let parent = { city: "Delhi" };
let man = Object.create(parent);
man.name = "John";
console.log(man.city); // Delhi (inherited)
```

### Definition
**Object Creation**: Use object literals (`{}`), `Object` constructor, or `Object.create` for inheritance.

## 3. What is the difference between an Array and an Object?

- **Array**: Ordered collection of values, indexed numerically.
- **Object**: Unordered collection of key-value pairs.

### Example
```javascript
let arr = [1, 2, 3];
let obj = { a: 1, b: 2, c: 3 };
```

### Differences
1. **Structure**:
   - Array: Values only, indexed (0, 1, 2).
   - Object: Key-value pairs.
2. **Syntax**:
   - Array: Square brackets `[]`.
   - Object: Curly braces `{}`.
3. **Order**:
   - Array: Ordered by index.
   - Object: Unordered properties.

### Definition
**Array vs. Object**: Arrays are ordered value collections; objects are unordered key-value pairs.

## 4. How to add, modify, or delete properties of an Object?

Use dot notation or `delete` to manage object properties.

### Example
```javascript
let person = {};
// Add
person.name = "John";
// Modify
person.name = "Jane";
// Delete
delete person.name;
console.log(person); // {}
```

### Definition
**Object Property Management**: Add/modify with dot notation; delete with `delete` keyword.

## 5. Explain the difference between Dot Notation and Bracket Notation

- **Dot Notation**: Simple, uses property names directly.
- **Bracket Notation**: Flexible, supports dynamic property names.

### Example
```javascript
let person = { name: "John", age: 30 };
console.log(person.name); // Dot: John
console.log(person["name"]); // Bracket: John

let prop = "name";
console.log(person[prop]); // Bracket: John
console.log(person.prop); // Dot: undefined
```

### When to Use
- **Dot Notation**: For static, known property names.
- **Bracket Notation**: For dynamic property names (e.g., stored in variables).

### Definition
**Dot vs. Bracket Notation**: Dot notation is simpler for static properties; bracket notation is required for dynamic properties.

## 6. What are some common methods to iterate over the properties of an Object?

Three ways to iterate object properties:
1. **`for...in` Loop**: Iterates keys.
2. **`Object.keys` with `forEach`**: Iterates keys.
3. **`Object.values` with `forEach`**: Iterates values.

### Example
```javascript
let person = { name: "John", age: 30 };

// for...in
for (let prop in person) {
  console.log(prop, person[prop]); // name John, age 30
}

// Object.keys
Object.keys(person).forEach(prop => {
  console.log(prop, person[prop]); // name John, age 30
});

// Object.values
Object.values(person).forEach(value => {
  console.log(value); // John, 30
});
```

### Definition
**Object Iteration**: Use `for...in`, `Object.keys`, or `Object.values` to loop over object properties or values.

## 7. How do you check if a property exists in an Object?

Three methods to check property existence:
1. **`in` Operator**: Checks if a property exists.
2. **`hasOwnProperty`**: Checks if an object directly owns a property.
3. **Compare with `undefined`**: Checks if a property is defined.

### Example
```javascript
let person = { name: "John" };

// in Operator
console.log("name" in person); // true
console.log("city" in person); // false

// hasOwnProperty
console.log(person.hasOwnProperty("name")); // true
console.log(person.hasOwnProperty("city")); // false

// undefined Check
console.log(person.name !== undefined); // true
console.log(person.city !== undefined); // false
```

### Definition
**Property Existence**: Use `in`, `hasOwnProperty`, or `undefined` checks to verify if a property exists.

## 8. How do you clone or copy an Object?

Three ways to clone objects:
1. **Spread Syntax (`...`)**: Shallow copy.
2. **`Object.assign`**: Shallow copy.
3. **`JSON.parse(JSON.stringify)`**: Deep copy.

### Example
```javascript
let original = { name: "John" };

// Spread Syntax
let clonedSpread = { ...original };

// Object.assign
let clonedAssign = Object.assign({}, original);

// JSON Methods
let clonedDeep = JSON.parse(JSON.stringify(original));

console.log(clonedSpread); // { name: "John" }
```

### Definition
**Object Cloning**: Use spread syntax, `Object.assign` (shallow), or `JSON.parse/JSON.stringify` (deep) to copy objects.

## 9. What is the difference between Deep Copy and Shallow Copy?

- **Shallow Copy**: Copies top-level properties; nested objects share references.
- **Deep Copy**: Copies all levels, creating independent objects.

### Example
```javascript
let person = { name: "John", address: { city: "Delhi" } };

// Shallow Copy
let shallowCopy = Object.assign({}, person);
shallowCopy.address.city = "Mumbai";
console.log(person.address.city); // Mumbai (original modified)

// Deep Copy
let deepCopy = JSON.parse(JSON.stringify(person));
deepCopy.address.city = "Bangalore";
console.log(person.address.city); // Delhi (original unchanged)
```

### Definition
**Deep vs. Shallow Copy**: Shallow copies share nested object references; deep copies create fully independent copies.

## 10. What is a `Set` Object in JavaScript?

A **`Set`** is a collection of unique values, ignoring duplicates.

### Example
```javascript
let mySet = new Set([1, 2, 2, 3]);
mySet.add(4); // Add value
mySet.add(2); // Ignored (duplicate)
console.log(mySet); // Set { 1, 2, 3, 4 }

console.log(mySet.size); // 4
console.log(mySet.has(2)); // true
mySet.delete(3); // Remove 3
```

### Use Case
Remove duplicates from an array:
```javascript
let arr = [1, 2, 2, 3];
let unique = [...new Set(arr)]; // [1, 2, 3]
```

### Definition
**Set Object**: A collection of unique values with methods like `add`, `has`, `delete`, and `size`.

## 11. What is a `Map` Object in JavaScript?

A **`Map`** is a collection of key-value pairs where keys and values can be any type.

### Example
```javascript
let myMap = new Map();
myMap.set("name", "John");
myMap.set(1, "Number Key");
console.log(myMap.get("name")); // John
console.log(myMap.has(1)); // true
myMap.delete("name");
```

### Definition
**Map Object**: A key-value collection with any key type and ordered insertion, using `set`, `get`, `has`, and `delete`.

## 12. What is the difference between `Map` and Object?

### Example
```javascript
let obj = { name: "John" };
let map = new Map([["name", "John"], [1, "Number Key"]]);
```

### Differences
1. **Key Types**:
   - Object: Strings or symbols.
   - Map: Any type (strings, numbers, objects, etc.).
2. **Order**:
   - Object: No guaranteed order.
   - Map: Maintains insertion order.
3. **Use Case**:
   - Object: Simple key-value pairs with string/symbol keys.
   - Map: Complex key types or ordered data.

### Definition
**Map vs. Object**: `Map` supports any key type and maintains order; objects are limited to string/symbol keys with no order guarantee.

---

# Chapter 11: Events

Events make web pages interactive by responding to user actions. This chapter covers event types, handling, and advanced concepts like delegation and bubbling.

## 1. What are Events? How are Events Triggered?

**Events** are user or browser actions (e.g., clicks, keypresses) that trigger JavaScript code.

### Flow
1. User interacts (e.g., clicks a button).
2. Event fires, running a handler function.
3. Page updates (e.g., displays an alert).

### Example
```html
<button id="myButton">Click Me</button>
```
```javascript
let button = document.getElementById("myButton");
button.addEventListener("click", handleClick);
function handleClick() {
  alert("Button clicked!");
}
```

### Definition
**Events**: Actions like clicks or keypresses that trigger handler functions to update the page.

## 2. What are the Types of Events in JavaScript?

Common events include:
- `click`: Button or element click.
- `mouseover`: Mouse hovers over an element.
- `keydown`/`keyup`: Keyboard key press/release.
- `submit`: Form submission.
- `focus`/`blur`: Element gains/loses focus.
- `change`: Input value changes.
- `load`/`resize`: Page loads or window resizes.

### Example
```javascript
button.addEventListener("mouseover", () => console.log("Hovered"));
```

### Definition
**Event Types**: Actions like `click`, `mouseover`, `keydown`, etc., handled by event listeners.

## 3. What is an Event Object in JavaScript?

The **event object** is automatically created by the browser when an event fires, providing details about the event.

### Example
```html
<button id="myButton">Click Me</button>
```
```javascript
let button = document.getElementById("myButton");
button.addEventListener("click", (event) => {
  console.log(event.type); // click
  console.log(event.target); // <button id="myButton">Click Me</button>
});
```

### Definition
**Event Object**: An object passed to event handlers, containing properties like `type` and `target` for event details.

## 4. What is Event Delegation in JavaScript?

**Event delegation** attaches a single event listener to a parent element to handle events for its children, improving performance.

### Example
```html
<ul id="myList">
  <li>Item 1</li>
  <li>Item 2</li>
  <li>Item 3</li>
</ul>
```
```javascript
let list = document.getElementById("myList");
list.addEventListener("click", (event) => {
  console.log(event.target.textContent); // Logs clicked item’s text
});
```

### Benefits
- Efficient for dynamic elements (e.g., added later).
- Reduces memory usage by minimizing listeners.

### Definition
**Event Delegation**: Attaching an event listener to a parent to handle child element events.

## 5. What is Event Bubbling in JavaScript?

**Event bubbling** propagates an event from the target element up through its ancestors.

### Example
```html
<div id="outer">
  <div id="inner">
    <button id="myButton">Click Me</button>
  </div>
</div>
```
```javascript
document.getElementById("outer").addEventListener("click", () => console.log("Outer"));
document.getElementById("inner").addEventListener("click", () => console.log("Inner"));
document.getElementById("myButton").addEventListener("click", () => console.log("Button"));
```

### Output (Clicking Button)
```
Button
Inner
Outer
```

### Definition
**Event Bubbling**: Events propagate from the target element up the DOM tree, triggering parent handlers.

## 6. How can you stop Event Propagation or Event Bubbling?

Use `event.stopPropagation()` to prevent an event from bubbling up.

### Example
```javascript
document.getElementById("myButton").addEventListener("click", (event) => {
  event.stopPropagation();
  console.log("Button");
});
document.getElementById("outer").addEventListener("click", () => console.log("Outer"));
```

### Output (Clicking Button)
```
Button
```

### Definition
**Stop Propagation**: `event.stopPropagation()` prevents events from bubbling to parent elements.

## 7. What is Event Capturing in JavaScript?

**Event capturing** handles events from the outermost ancestor down to the target, opposite of bubbling.

### Example
```javascript
document.getElementById("outer").addEventListener("click", () => console.log("Outer"), true);
document.getElementById("inner").addEventListener("click", () => console.log("Inner"), true);
document.getElementById("myButton").addEventListener("click", () => console.log("Button"), true);
```

### Output (Clicking Button)
```
Outer
Inner
Button
```

### Key Point
- Set `addEventListener`’s third parameter to `true` for capturing (default is `false` for bubbling).

### Definition
**Event Capturing**: Events propagate from the top ancestor down to the target element.

## 8. What is the purpose of the `event.preventDefault` Method?

**`event.preventDefault`** suppresses an element’s default behavior (e.g., link navigation).

### Example
```html
<a id="myLink" href="https://example.com">Click Me</a>
```
```javascript
document.getElementById("myLink").addEventListener("click", (event) => {
  event.preventDefault();
  console.log("Link click prevented");
});
```

### Definition
**event.preventDefault**: Prevents an element’s default behavior, allowing custom actions.

## 9. What is the use of the `this` Keyword in the context of Event Handling?

In event handlers, `this` refers to the element the event is attached to.

### Example
```html
<button id="myButton">Click Me</button>
```
```javascript
document.getElementById("myButton").addEventListener("click", function() {
  console.log(this.id); // myButton
});
```

### Definition
**this in Event Handling**: Refers to the element the event handler is attached to.

## 10. How do you remove an Event Handler from an Element?

Use `removeEventListener` to detach an event handler, specifying the event type and handler function.

### Example
```javascript
function handleClick() {
  console.log("Button clicked");
}
let button = document.getElementById("myButton");
button.addEventListener("click", handleClick);
button.removeEventListener("click", handleClick);
```

### Key Point
- The handler function must be named (not anonymous) to be removable.

### Definition
**Remove Event Handler**: `removeEventListener` detaches an event handler from an element.

---

# Final Interview Tips
- **Understand the DOM**: Practice manipulating elements with code snippets.
- **Master Error Handling**: Use `try`/`catch` and log errors effectively.
- **Know Objects**: Be comfortable with creation, iteration, and cloning.
- **Grasp Events**: Explain bubbling, capturing, and delegation clearly.
- **Practice Explaining**: Use diagrams or code to clarify concepts in interviews.
- **Stay Persistent**: Keep applying and learning from feedback.

Congratulations on completing Part 3! You’ve mastered **DOM**, **Error Handling**, **Objects**, and **Events**. Stay tuned for the final part, covering advanced JavaScript topics. Keep practicing, and share your job success stories in the comments to motivate others!