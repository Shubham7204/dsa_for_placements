# Chapter 1: Node.js Basics and Fundamentals

This chapter covers the foundational concepts of Node.js, including what it is, how it differs from frameworks, and its role in server-side development. Even if you’re familiar with Node.js, revisiting these basics will solidify your understanding and help you avoid common misconceptions.

## 1. What is Node.js?

**Node.js** is neither a programming language nor a framework—it’s a **runtime environment** that allows JavaScript to run on the server side. Unlike languages like Python or Java, or frameworks like Django or Spring, Node.js provides the infrastructure to execute JavaScript code outside the browser.

### How It Works
- **JavaScript Engines**: Browsers use engines like V8 (Chrome), Chakra (Edge), or SpiderMonkey (Firefox) to run JavaScript on the client side.
- **Node.js and V8**: Node.js uses Chrome’s **V8 engine** to execute JavaScript on the server, enabling backend development with JavaScript.

### Example
```javascript
console.log("Hello from Node.js!");
```
Running this with `node app.js` outputs:
```
Hello from Node.js!
```

### Diagram
```
Browser (Client-Side)       Node.js (Server-Side)
  └── V8 Engine                └── V8 Engine
       └── Executes JS              └── Executes JS
```

### Definition
**Node.js**: A runtime environment for executing JavaScript code on the server side, powered by Chrome’s V8 engine.

## 2. What is the difference between a Framework and a Runtime Environment?

A **runtime environment** executes code, while a **framework** simplifies development with reusable tools and libraries.

### Comparison
| **Aspect**            | **Runtime Environment**                     | **Framework**                              |
|-----------------------|--------------------------------------------|--------------------------------------------|
| **Purpose**           | Executes code, manages memory, I/O         | Simplifies app development with tools      |
| **Examples**          | Node.js (JavaScript), JVM (Java), CPython  | Express (Node.js), Spring (Java), Django   |
| **Role**              | Provides infrastructure for code execution | Offers structured libraries and functions |

### Example
- **Node.js**: Executes JavaScript code.
- **Express.js**: A framework built on Node.js for building web applications and APIs.

### Definition
**Runtime Environment vs. Framework**: A runtime environment (e.g., Node.js) executes code and manages resources; a framework (e.g., Express.js) provides tools to simplify development.

## 3. What is the difference between Node.js and Express.js?

- **Node.js**: A runtime environment for running JavaScript on the server.
- **Express.js**: A framework built on Node.js to simplify web application and API development.

### Example
**Node.js (Raw)**:
```javascript
const http = require("http");
http.createServer((req, res) => {
  res.writeHead(200, { "Content-Type": "text/plain" });
  res.end("Hello from Node.js!");
}).listen(3000);
```

**Express.js**:
```javascript
const express = require("express");
const app = express();
app.get("/", (req, res) => res.send("Hello from Express!"));
app.listen(3000);
```

### Key Points
- **Node.js**: Handles low-level server operations.
- **Express.js**: Simplifies routing, middleware, and API development.

### Definition
**Node.js vs. Express.js**: Node.js is a runtime for server-side JavaScript; Express.js is a framework on top of Node.js for building web applications and APIs.

## 4. What are the differences between Client-Side and Server-Side JavaScript?

Client-side and server-side JavaScript differ in execution environment, responsibilities, and available APIs.

### Flow Diagram
```
User → Browser (Client-Side) → UI Server (Angular/React) → Node.js API (Server-Side) → Database
```

### Differences
| **Aspect**           | **Client-Side (Browser)**         | **Server-Side (Node.js)**                    |
| -------------------- | --------------------------------- | -------------------------------------------- |
| **Execution**        | Runs in the browser               | Runs on the server                           |
| **Languages**        | HTML, CSS, JavaScript             | JavaScript                                   |
| **Objects**          | `document`, `window`, `navigator` | `request`, `response`, `server`              |
| **Responsibilities** | UI rendering, user interaction    | Business logic, data storage, authentication |
| **Example APIs**     | `document.getElementById`         | `http.createServer`                          |

### Example
**Client-Side**:
```javascript
document.getElementById("myDiv").textContent = "Hello!";
```

**Server-Side**:
```javascript
const http = require("http");
http.createServer((req, res) => {
  res.end("Hello from server!");
}).listen(3000);
```

### Definition
**Client-Side vs. Server-Side**: Client-side JavaScript (browser) handles UI and interactions; server-side JavaScript (Node.js) manages business logic and data.

---

# Chapter 2: Main Features of Node.js

Node.js’s popularity stems from its powerful features. This chapter explores these features, their advantages, and how they work internally.

## 1. What are the seven main features of Node.js?

Node.js has seven key features that make it a top choice for backend development:
1. **Single-Threaded**: Uses one thread for execution.
2. **Asynchronous**: Executes tasks concurrently without waiting.
3. **Event-Driven**: Operations are triggered by events.
4. **V8 Engine**: Powered by Chrome’s fast JavaScript engine.
5. **Cross-Platform**: Runs on Windows, Linux, macOS.
6. **NPM**: Node Package Manager for dependency management.
7. **Real-Time Capabilities**: Ideal for bidirectional communication (e.g., chat apps).

### Definition
**Node.js Features**: Single-threaded, asynchronous, event-driven architecture with V8, cross-platform support, NPM, and real-time capabilities.

## 2. What is Single-Threaded Programming?

**Single-threaded programming** uses one thread to execute tasks sequentially.

### Example
```javascript
console.log("Task 1");
console.log("Task 2");
console.log("Task 3");
```

### Flow
```
Thread T1 → Task 1 → Wait → Task 2 → Wait → Task 3 → Complete
```

### Key Points
- **Synchronous**: Tasks wait for the previous task to complete.
- **Blocking**: Each task blocks the next until finished.

### Definition
**Single-Threaded Programming**: A single thread executes tasks sequentially, often synchronously.

## 3. What is Synchronous Programming?

**Synchronous programming** executes tasks one after another, waiting for each to complete.

### Example
```javascript
function task1() { console.log("Task 1"); }
function task2() { console.log("Task 2"); }
task1(); // Takes 10s
task2(); // Takes 8s
// Total: 18s
```

### Issues
- **Performance**: Total time is the sum of task durations.
- **Blocking**: Tasks block subsequent tasks.

### Definition
**Synchronous Programming**: Tasks execute sequentially, blocking the next task until completion.

## 4. What is Multi-Threaded Programming?

**Multi-threaded programming** uses multiple threads to execute tasks in parallel, ideal for CPU-intensive tasks.

### Flow
```
Thread T1 → Task 1
Thread T2 → Task 2
Thread T3 → Task 3
```

### Example
```javascript
// Pseudo-code (Node.js is single-threaded)
function task1() { console.log("Task 1"); }
function task2() { console.log("Task 2"); }
// Threads T1, T2 run tasks in parallel
```

### Key Points
- **Advantages**: Faster for CPU-intensive tasks.
- **Disadvantages**: Risk of deadlocks; complex to manage.

### Definition
**Multi-Threaded Programming**: Multiple threads execute tasks in parallel, suitable for heavy computations.

## 5. What is Asynchronous Programming?

**Asynchronous programming** allows tasks to run concurrently without blocking, using a single thread.

### Flow
```
Thread T1 → Initiate Task 1 → Initiate Task 2 → Initiate Task 3
          ↳ Task 1 Complete → Event → Handle
          ↳ Task 2 Complete → Event → Handle
```

### Example
```javascript
setTimeout(() => console.log("Task 1"), 10000); // 10s
setTimeout(() => console.log("Task 2"), 8000);  // 8s
// Total time: ~10s (concurrent)
```

### Benefits
- **Non-Blocking**: Tasks don’t wait for others.
- **Performance**: Faster execution for I/O-bound tasks.

### Definition
**Asynchronous Programming**: Single-threaded, non-blocking execution using events, ideal for I/O operations.

## 6. What is the difference between Synchronous and Asynchronous Programming?

### Comparison
| **Aspect**      | **Synchronous**            | **Asynchronous**                  |
| --------------- | -------------------------- | --------------------------------- |
| **Execution**   | Sequential, blocking       | Concurrent, non-blocking          |
| **Performance** | Slower (sum of task times) | Faster (concurrent execution)     |
| **Use Case**    | Simple, linear tasks       | I/O-bound tasks (e.g., API calls) |
| **Example**     | `console.log` in sequence  | `setTimeout`, `Promises`          |

### Definition
**Synchronous vs. Asynchronous**: Synchronous programming is blocking and sequential; asynchronous is non-blocking and concurrent, leveraging events.

## 7. What are Events, Event Queue, Event Loop, and Event-Driven Architecture in Node.js?

- **Event**: A signal that an action (e.g., request) has occurred.
- **Event Emitter**: Source generating events.
- **Event Queue**: Stores events for processing.
- **Event Loop**: Processes events one by one from the queue.
- **Event-Driven Architecture**: Operations driven by events.

### Flow Diagram
```
Event Emitter → Event Queue → Event Loop → Event Handler
```

### Example
```javascript
const EventEmitter = require("events");
const myEmitter = new EventEmitter();

myEmitter.on("myEvent", () => console.log("Event handled!"));
myEmitter.emit("myEvent");
```

### Definition
**Events in Node.js**: Events signal actions, stored in an event queue, processed by the event loop, and handled by listeners in an event-driven architecture.

## 8. What are the main features and advantages of Node.js?

### Features and Advantages
| **Feature**        | **Advantage**                                    |
| ------------------ | ------------------------------------------------ |
| **Asynchronous**   | Handles multiple concurrent requests efficiently |
| **V8 Engine**      | Fast code execution                              |
| **Event-Driven**   | Efficient for real-time apps (e.g., chat)        |
| **Cross-Platform** | Runs on any OS, enhancing flexibility            |
| **JavaScript**     | No need to learn new languages                   |
| **NPM**            | Simplifies dependency management                 |
| **Real-Time**      | Ideal for bidirectional communication            |

### Definition
**Node.js Advantages**: Asynchronous, fast (V8), event-driven, cross-platform, JavaScript-based, scalable, and dependency-managed via NPM.

## 9. What are the disadvantages of Node.js? When to use or not use Node.js?

### When to Use Node.js
- **Real-Time Apps**: Chat, gaming, collaborative tools.
- **Lightweight APIs**: Scalable REST APIs.
- **Microservices**: Modular, scalable architecture.

### When Not to Use Node.js
- **CPU-Intensive Tasks**: Video processing, heavy algorithms (better suited for multi-threaded technologies).

### Definition
**Node.js Disadvantages**: Not ideal for CPU-intensive tasks due to its single-threaded nature; best for real-time, I/O-bound applications.

---

# Chapter 3: Project Setup and Modules

This chapter covers setting up a Node.js project and understanding modules, a core concept for structuring Node.js applications.

## 1. How to set up a Node.js project?

Follow these seven steps to set up a Node.js project:
1. **Install Node.js**: Download and install from [nodejs.org](https://nodejs.org).
2. **Install Code Editor**: Use VS Code or any editor.
3. **Create Project Folder**: E.g., `my-first-project`.
4. **Open in Editor**: Open the folder in VS Code.
5. **Initialize Project**: Run `npm init -y` in the terminal to create `package.json`.
6. **Create Main File**: Create `app.js`.
7. **Run Project**: Use `node app.js`.

### Example
```bash
mkdir my-first-project
cd my-first-project
npm init -y
touch app.js
node app.js
```

**app.js**:
```javascript
console.log("My first Node.js project!");
```

### Definition
**Node.js Project Setup**: Install Node.js, create a project folder, initialize with `npm init`, and run with `node app.js`.

## 2. What is NPM? What is the role of the `node_modules` folder?

- **NPM**: Node Package Manager, used to manage dependencies.
- **node_modules**: Stores installed dependencies for the project.

### Example
```bash
npm install express
```
This creates `node_modules/express` with Express.js files.

### Key Points
- **NPM Commands**: `npm install`, `npm update`, `npm uninstall`.
- **node_modules**: Never modify manually; managed by NPM.

### Definition
**NPM and node_modules**: NPM manages project dependencies; `node_modules` stores them for use in the project.

## 3. What is the role of the `package.json` file?

**`package.json`** contains project metadata and dependency information.

### Example
```json
{
  "name": "my-first-project",
  "version": "1.0.0",
  "description": "A Node.js project",
  "author": "Your Name",
  "license": "MIT",
  "dependencies": {
    "express": "^4.17.1"
  }
}
```

### Definition
**package.json**: Stores project metadata (name, version, etc.) and manages dependencies.

## 4. What are Modules in Node.js? What is the difference between a Function and a Module?

- **Module**: A reusable piece of functionality, typically a single JavaScript file.
- **Function**: A specific set of instructions within a module.

### Example
**myModule.js**:
```javascript
function sayHello() {
  return "Hello!";
}
module.exports = sayHello;
```

**app.js**:
```javascript
const sayHello = require("./myModule");
console.log(sayHello()); // Hello!
```

### Differences
- **Module**: Encapsulates functionality (e.g., `myModule.js`).
- **Function**: Performs a specific task within a module.

### Definition
**Modules vs. Functions**: Modules encapsulate functionality (often a file); functions are specific tasks within modules.

## 5. How many ways are there to export a Module?

Two ways to export modules:
1. **`module.exports` Object**: Assign functions/variables explicitly.
2. **Direct Export**: Assign a single function/variable to `module.exports`.

### Example
**module.exports**:
```javascript
function sayHello() { return "Hello!"; }
function sayGoodbye() { return "Goodbye!"; }
module.exports = { sayHello, sayGoodbye };
```

**Direct Export**:
```javascript
module.exports = function sayHello() { return "Hello!"; };
```

### Definition
**Module Export**: Use `module.exports` for multiple exports or direct export for a single function/variable.

## 6. What will happen if you do not export a Module?

If a module is not exported, its contents (functions, variables) are not accessible outside the file.

### Example
**myModule.js** (Not Exported):
```javascript
function sayHello() { return "Hello!"; }
```

**app.js**:
```javascript
const sayHello = require("./myModule");
console.log(sayHello); // undefined
```

### Definition
**Non-Exported Module**: Functions/variables are private to the module and inaccessible externally.

## 7. How to import single or multiple functions from a Module?

- **Single Function**: Import directly with `require`.
- **Multiple Functions**: Import as an object and access by name.

### Example
**myModule.js**:
```javascript
function sayHello() { return "Hello!"; }
function sayGoodbye() { return "Goodbye!"; }
module.exports = { sayHello, sayGoodbye };
```

**app.js**:
```javascript
const myModule = require("./myModule");
console.log(myModule.sayHello()); // Hello!
console.log(myModule.sayGoodbye()); // Goodbye!

// Single Function
const sayHello = require("./myModule").sayHello;
console.log(sayHello()); // Hello!
```

### Definition
**Module Import**: Use `require` to import single or multiple functions from a module.

## 8. What is a Module Wrapper Function?

Node.js automatically wraps each module in a function to execute it, simplifying development.

### Example
**app.js**:
```javascript
console.log("Hello!");
```

**Internal Wrapper**:
```javascript
(function(exports, require, module, __filename, __dirname) {
  console.log("Hello!");
})();
```

### Definition
**Module Wrapper Function**: Node.js wraps module code in a function before execution, providing `exports`, `require`, etc.

## 9. What are the types of Modules in Node.js?

Three types of modules:
1. **Built-in (Core) Modules**: Provided by Node.js (e.g., `fs`, `http`).
2. **Local Modules**: User-defined modules created for the project.
3. **Third-Party Modules**: External packages installed via NPM (e.g., `express`).

### Example
**Built-in**:
```javascript
const fs = require("fs");
```

**Local**:
```javascript
const myModule = require("./myModule");
```

**Third-Party**:
```bash
npm install express
```
```javascript
const express = require("express");
```

### Definition
**Module Types**: Built-in (core), local (user-defined), and third-party (NPM-installed) modules.

---

# Chapter 4: Top Built-in Modules

This chapter explores the most commonly used built-in Node.js modules, essential for real-world projects.

## 1. What are the top five built-in modules commonly used in Node.js projects?

The top five built-in modules are:
1. **fs**: File system operations.
2. **path**: Path manipulation.
3. **os**: Operating system information.
4. **events**: Event handling.
5. **http**: HTTP server creation.

### Definition
**Top Built-in Modules**: `fs`, `path`, `os`, `events`, and `http` are widely used for file, path, OS, event, and server operations.

## 2. Explain the role of the `fs` Module. Name some functions of it.

The **fs (File System) module** provides methods for interacting with the file system (reading, writing, deleting files).

### Example
**Read File**:
```javascript
const fs = require("fs");
fs.readFile("example.txt", "utf8", (err, data) => {
  if (err) return console.error(err);
  console.log(data);
});
```

**Write File**:
```javascript
fs.writeFile("example.txt", "New content", (err) => {
  if (err) return console.error(err);
  console.log("File written");
});
```

### Key Functions
- `readFile`: Reads file content asynchronously.
- `writeFile`: Writes content to a file.
- `appendFile`: Appends data to a file.
- `unlink`: Deletes a file.
- `readdir`: Reads directory contents.
- `mkdir`: Creates a directory.
- `rmdir`: Removes a directory.

### Definition
**fs Module**: Provides methods for file system operations like reading, writing, and managing files/directories.

## 3. Explain the role of the `path` Module. Name some functions of it.

The **path module** provides utilities for manipulating file paths and URLs.

### Example
**Join Path**:
```javascript
const path = require("path");
const fullPath = path.join("folder", "subfolder", "file.txt");
console.log(fullPath); // folder/subfolder/file.txt
```

**Parse Path**:
```javascript
const parsed = path.parse("/home/user/file.txt");
console.log(parsed);
// { root: '/', dir: '/home/user', base: 'file.txt', ext: '.txt', name: 'file' }
```

### Key Functions
- `join`: Joins path segments.
- `parse`: Converts a path to an object (root, dir, base, etc.).
- `resolve`: Resolves a path to absolute.
- `normalize`: Normalizes a path (removes redundant slashes).
- `basename`: Gets the file name.
- `dirname`: Gets the directory name.

### Definition
**path Module**: Provides utilities for joining, parsing, and manipulating file paths.

## 4. Explain the role of the `os` Module. Name some functions of it.

The **os module** provides methods to interact with the operating system, useful for cross-platform applications.

### Example
```javascript
const os = require("os");
console.log(os.type()); // Operating system type (e.g., Linux)
console.log(os.userInfo()); // User info
console.log(os.totalmem()); // Total memory (bytes)
console.log(os.freemem()); // Free memory (bytes)
```

### Key Functions
- `type`: Returns OS type (e.g., Linux, Windows).
- `userInfo`: Returns user information.
- `totalmem`: Returns total system memory.
- `freemem`: Returns free memory.
- `platform`: Returns OS platform.

### Definition
**os Module**: Provides methods to access operating system information for cross-platform compatibility.

## 5. Explain the role of the `events` Module. How to handle events in Node.js?

The **events module** enables event-driven programming by handling events via the `EventEmitter` class.

### Example
```javascript
const EventEmitter = require("events");
const myEmitter = new EventEmitter();

// Register event listener
myEmitter.on("myEvent", () => console.log("Event triggered!"));

// Emit event
myEmitter.emit("myEvent");
```

### Flow
```
EventEmitter → Register Listener (on) → Emit Event (emit) → Execute Handler
```

### Key Points
- **Register First**: Listeners must be registered before emitting events.
- **Use Case**: Handling API requests, file operations, etc.

### Definition
**events Module**: Provides `EventEmitter` for registering and handling events in Node.js.

## 6. What are Event Arguments?

**Event arguments** are additional data passed when emitting an event, received by the event handler.

### Example
```javascript
const EventEmitter = require("events");
const myEmitter = new EventEmitter();

myEmitter.on("myEvent", (arg1, arg2) => {
  console.log(`Args: ${arg1}, ${arg2}`); // Args: Hello, World
});

myEmitter.emit("myEvent", "Hello", "World");
```

### Definition
**Event Arguments**: Data passed with an event to the handler for custom logic.

## 7. What is the difference between a Function and an Event?

- **Function**: A reusable code block performing a specific task.
- **Event**: A signal that an action has occurred, triggering functions.

### Example
**Function**:
```javascript
function sayHello() { return "Hello!"; }
console.log(sayHello()); // Hello!
```

**Event**:
```javascript
const EventEmitter = require("events");
const myEmitter = new EventEmitter();
myEmitter.on("request", () => console.log("Request received"));
myEmitter.emit("request");
```

### Definition
**Function vs. Event**: Functions execute tasks; events signal actions, triggering functions.

## 8. What is the role of the `http` Module in Node.js?

The **http module** creates an HTTP server to handle requests and responses, enabling Node.js to serve APIs.

### Flow Diagram
```
User → Browser → UI Server → Node.js (http module) → Database
```

### Example
```javascript
const http = require("http");
http.createServer((req, res) => {
  res.writeHead(200, { "Content-Type": "text/plain" });
  res.end("Hello from Node.js!");
}).listen(3000);
```

### Definition
**http Module**: Creates an HTTP server to listen for and respond to client requests.

---

# Final Interview Tips
- **Understand Node.js Basics**: Clearly explain Node.js as a runtime, not a framework.
- **Master Features**: Relate features (e.g., asynchronous, event-driven) to advantages (e.g., scalability).
- **Practice Modules**: Be comfortable with built-in modules like `fs`, `path`, and `http`.
- **Code Regularly**: Write and test code snippets to reinforce concepts.
- **Stay Positive**: Keep applying for jobs and learning from feedback.

Congratulations on mastering the fundamentals of Node.js! Stay tuned for the next part, covering **Express.js**, **REST APIs**, and more. Share your job success stories in the comments to motivate others, and keep pushing forward—where there’s a will, there’s a way!