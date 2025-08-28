## Chapter 4: Node.js Built-in Modules (Continued)

We’ll start by completing the coverage of Node.js’s built-in modules, focusing on the `http` module’s practical implementation.

### 1. What is the role of the `createServer` method of the `http` module?

The **`createServer` method** of the `http` module creates an HTTP server that listens for incoming requests and sends responses back to the client.

#### Implementation (5 Steps)
1. **Import the `http` module**.
2. **Create the server** using `http.createServer`, passing a callback function to handle requests and responses.
3. **Define request handling logic** in the callback, which executes when a request is received.
4. **Set a port number** for the server to listen on.
5. **Start the server** using the `listen` method.

#### Code Example
```javascript
const http = require("http");

// Create server
const server = http.createServer((req, res) => {
  res.writeHead(200, { "Content-Type": "text/plain" });
  res.end("Hello World!");
});

// Set port and start server
const PORT = 3000;
server.listen(PORT, () => {
  console.log(`Server running at http://localhost:${PORT}`);
});
```

#### Testing
Run `node server.js`, open a browser, and visit `http://localhost:3000`. You’ll see:
```
Hello World!
```

#### Flow Diagram
```
Client → HTTP Request → http.createServer → Callback Logic → HTTP Response → Client
```

#### Definition
**`createServer` Method**: Creates an HTTP server that listens on a specified port and handles requests via a callback function.

---

## Chapter 5: Express.js Basics

Express.js is a lightweight framework built on Node.js to simplify web application and API development. This chapter covers its advantages and basic setup.

### 1. What are the advantages of using Express.js with Node.js?

Express.js enhances Node.js development with four key advantages:
1. **Simplified Web Development**: Provides built-in methods for routing, middleware, and more.
2. **Middleware Support**: Simplifies request and response handling.
3. **Flexible Routing System**: Easily directs requests to appropriate handlers based on URL and method.
4. **Template Engine Integration**: Supports server-side rendering of dynamic HTML.

#### Definition
**Express.js Advantages**: Simplifies development, supports middleware, provides flexible routing, and integrates with template engines.

### 2. How do you install Express.js in a Node.js project?

Express.js is a third-party module installed via NPM.

#### Steps
1. Open the terminal in your project directory.
2. Run:
   ```bash
   npm install express
   ```

#### Definition
**Installing Express.js**: Use `npm install express` to add Express.js to your Node.js project.

### 3. How to create an HTTP server using Express.js?

Express.js simplifies HTTP server creation compared to the `http` module, requiring just four steps.

#### Steps
1. **Install Express.js**: `npm install express`.
2. **Import Express**: Load the module.
3. **Create an Express app**: Initialize the server.
4. **Start the server**: Use the `listen` method with a port.

#### Code Example
```javascript
const express = require("express");
const app = express();
const PORT = 3000;

app.get("/", (req, res) => {
  res.send("Hello from Express!");
});

app.listen(PORT, () => {
  console.log(`Server running at http://localhost:${PORT}`);
});
```

#### Why Use Express.js Over `http` Module?
- **Simpler syntax**: No need for `createServer`.
- **Additional features**: Middleware, routing, and template engines.

#### Definition
**Express.js Server Creation**: Import Express, create an app, define routes, and start the server with `app.listen`.

### 4. How do you create and start an Express.js application?

This question reinforces the previous one, focusing on the steps to create and start an Express app.

#### Steps
1. **Import Express** and create an app instance.
2. **Define routes** (e.g., `app.get`).
3. **Start the server** with `app.listen`.

#### Code Example
```javascript
const express = require("express");
const app = express();

app.get("/", (req, res) => res.send("Welcome to Express!"));

app.listen(3000, () => console.log("Server started on port 3000"));
```

#### Definition
**Express.js Application**: Create with `express()`, define routes, and start with `app.listen`.

---

## Chapter 6: Express.js Middleware

Middleware functions are the backbone of Express.js, acting as intermediaries between requests and responses. This chapter explores middleware concepts and implementations.

### 1. What is Middleware in Express.js? When to use it?

**Middleware** is a function that processes HTTP requests, performs operations (e.g., logging, authentication), and passes control to the next middleware or route handler.

#### Flow Diagram
```
Client → HTTP Request → Middleware 1 → Middleware 2 → Route Handler → HTTP Response → Client
```

#### When to Use Middleware
- **Logging**: Record request details.
- **Authentication**: Validate user credentials.
- **Security**: Add headers or sanitize inputs.
- **Data Parsing**: Process request bodies.

#### Definition
**Middleware**: A function in Express.js that handles HTTP requests, performs operations, and passes control to the next middleware or handler.

### 2. How to implement Middleware in Express.js?

Middleware is implemented in four steps:
1. **Create an Express app**.
2. **Define a middleware function** with `req`, `res`, and `next` parameters.
3. **Use the middleware** with `app.use`.
4. **Start the server**.

#### Code Example
```javascript
const express = require("express");
const app = express();

// Define middleware
const myMiddleware = (req, res, next) => {
  console.log("Middleware executed!");
  next(); // Pass control to the next middleware
};

// Use middleware
app.use(myMiddleware);

app.get("/", (req, res) => res.send("Hello from Express!"));

app.listen(3000, () => console.log("Server running on port 3000"));
```

#### Output
```
Middleware executed!
```

#### Definition
**Middleware Implementation**: Define a function with `req`, `res`, `next`, and execute it using `app.use`.

### 3. What is the purpose of the `app.use` function in Express.js?

The **`app.use` function** executes middleware globally for all incoming requests.

#### Code Example
```javascript
const express = require("express");
const app = express();

app.use((req, res, next) => {
  console.log(`Request URL: ${req.url}`);
  next();
});

app.listen(3000);
```

#### Definition
**`app.use`**: Executes middleware globally for all requests, regardless of method or URL.

### 4. What is the purpose of the `next` parameter in Express.js?

The **`next` parameter** is a callback function that passes control to the next middleware in the stack.

#### Code Example
```javascript
const express = require("express");
const app = express();

app.use((req, res, next) => {
  console.log("First middleware");
  next();
});

app.use((req, res, next) => {
  console.log("Second middleware");
  res.send("Response from second middleware");
});

app.listen(3000);
```

#### Output
```
First middleware
Second middleware
```

#### Definition
**`next` Parameter**: A callback function that transfers control to the next middleware in the Express.js request pipeline.

### 5. How to use Middleware globally for a specific route?

Middleware can be applied to specific routes by passing a URL path to `app.use`.

#### Code Example
```javascript
const express = require("express");
const app = express();

const myMiddleware = (req, res, next) => {
  console.log("Middleware for /example");
  next();
};

app.use("/example", myMiddleware);

app.get("/example", (req, res) => res.send("Route with middleware"));

app.listen(3000);
```

#### Testing
- Visit `http://localhost:3000/example`: Middleware executes.
- Visit `http://localhost:3000/`: Middleware does not execute.

#### Definition
**Route-Specific Middleware**: Use `app.use("/path", middleware)` to apply middleware only to requests matching the specified path.

### 6. What is the Request Pipeline in Express.js?

The **request pipeline** is the sequence of middleware functions that process an HTTP request before reaching the route handler.

#### Flow Diagram
```
Request → Middleware 1 → Middleware 2 → ... → Route Handler → Response
```

#### Definition
**Request Pipeline**: A series of middleware functions that handle and process incoming HTTP requests in Express.js.

### 7. What are the types of Middleware in Express.js?

Express.js supports five types of middleware:
1. **Application-Level Middleware**: Applied globally to all requests.
2. **Router-Level Middleware**: Applied to specific routes.
3. **Error-Handling Middleware**: Handles errors in the pipeline.
4. **Built-in Middleware**: Provided by Express (e.g., `express.static`).
5. **Third-Party Middleware**: External libraries (e.g., `helmet`, `body-parser`).

#### Definition
**Middleware Types**: Application-level, router-level, error-handling, built-in, and third-party middleware.

### 8. What is the difference between Application-Level and Router-Level Middleware?

#### Comparison
| **Aspect**                | **Application-Level Middleware** | **Router-Level Middleware** |
|---------------------------|----------------------------------|-----------------------------|
| **Scope**                 | Global, all requests            | Specific routes             |
| **Example**               | `app.use(middleware)`           | `app.use("/path", middleware)` |

#### Code Example
**Application-Level**:
```javascript
app.use((req, res, next) => {
  console.log("Global middleware");
  next();
});
```

**Router-Level**:
```javascript
app.use("/api", (req, res, next) => {
  console.log("API middleware");
  next();
});
```

#### Definition
**Application-Level vs. Router-Level**: Application-level middleware applies globally; router-level applies to specific routes.

### 9. What is Error-Handling Middleware? How to implement it?

**Error-handling middleware** captures and processes errors, logging details and sending user-friendly responses.

#### Implementation
- Define middleware with an additional `err` parameter.
- Place it last in the pipeline to catch errors from previous middleware.

#### Code Example
```javascript
const express = require("express");
const app = express();

app.use((req, res, next) => {
  // Simulate an error
  next(new Error("Something went wrong!"));
});

app.use((err, req, res, next) => {
  console.error(err.stack); // Log error
  res.status(500).send("Error: " + err.message); // User-friendly response
});

app.listen(3000);
```

#### Output
```
Error: Something went wrong!
```

#### Tip
Always place error-handling middleware **last** to catch errors from all previous middleware.

#### Definition
**Error-Handling Middleware**: Middleware with an `err` parameter to capture, log, and respond to errors.

### 10. What is Built-in Middleware? How to serve static files from Express.js?

**Built-in middleware** is provided by Express.js, such as `express.static` for serving static files (e.g., images, CSS).

#### Code Example
```javascript
const express = require("express");
const app = express();

app.use(express.static("public"));

app.listen(3000);
```

#### Folder Structure
```
project/
├── public/
│   └── image.jpg
├── server.js
```

#### Testing
Visit `http://localhost:3000/image.jpg` to access the file.

#### Definition
**Built-in Middleware**: Middleware provided by Express.js, like `express.static`, for serving static files without authentication.

### 11. What are Third-Party Middleware? Give some examples.

**Third-party middleware** are external libraries installed via NPM to add functionality.

#### Examples
- **helmet**: Adds security headers.
- **body-parser**: Parses request bodies.
- **compression**: Compresses responses.

#### Code Example
```javascript
const express = require("express");
const helmet = require("helmet");
const bodyParser = require("body-parser");
const compression = require("compression");

const app = express();

app.use(helmet());
app.use(bodyParser.json());
app.use(compression());

app.listen(3000);
```

#### Installation
```bash
npm install helmet body-parser compression
```

#### Definition
**Third-Party Middleware**: External libraries installed via NPM to enhance Express.js functionality.

### 12. Can you summarize all the types of Middleware?

#### Summary
- **Application-Level**: Global middleware for all requests (`app.use`).
- **Router-Level**: Route-specific middleware (`app.use("/path")`).
- **Error-Handling**: Catches errors (`err, req, res, next`).
- **Built-in**: Provided by Express (e.g., `express.static`).
- **Third-Party**: External libraries (e.g., `helmet`).

#### Definition
**Middleware Summary**: Express.js supports application-level, router-level, error-handling, built-in, and third-party middleware for flexible request processing.

### 13. What are the advantages of using Middleware in Express.js?

Middleware provides five key advantages:
1. **Modularity**: Breaks down functionality into reusable functions.
2. **Reusability**: Middleware can be reused across routes.
3. **Improved Request Handling**: Simplifies validation, logging, etc.
4. **Flexible Control Flow**: Control which middleware applies to which routes.
5. **Third-Party Middleware**: Extends functionality with external libraries.

#### Definition
**Middleware Advantages**: Modularity, reusability, improved request handling, flexible control, and third-party integration.

---

## Chapter 7: Express.js Routing

Routing directs incoming HTTP requests to appropriate handlers based on URL and method. This chapter explores routing concepts and implementations.

### 1. What is Routing in Express.js?

**Routing** is the process of directing HTTP requests to specific handler functions based on the request’s URL path and method (GET, POST, etc.).

#### Flow Diagram
```
Client → HTTP Request → Middleware → Router → Controller (Handler) → Response
```

#### Example
For an e-commerce app:
- `/orders` → `OrdersController.getOrders`
- `/products` → `ProductsController.getProducts`

#### Definition
**Routing**: Directs HTTP requests to appropriate handler functions based on URL and method.

### 2. What is the difference between Middleware and Routing?

#### Comparison
| **Aspect**    | **Middleware**                     | **Routing**                   |
| ------------- | ---------------------------------- | ----------------------------- |
| **Nature**    | Function                           | Process                       |
| **Role**      | Processes requests (e.g., logging) | Directs requests to handlers  |
| **Execution** | Can modify request or end cycle    | Matches URL/method to handler |

#### Definition
**Middleware vs. Routing**: Middleware processes requests; routing directs requests to handlers.

### 3. How to implement Routing? How do you define Routes in Express.js?

Routes are defined using `app.method` (e.g., `app.get`, `app.post`) with a path and handler.

#### Code Example
```javascript
const express = require("express");
const app = express();

app.get("/", (req, res) => res.send("Home Page"));
app.post("/login", (req, res) => res.send("Login Processed"));

app.listen(3000);
```

#### Definition
**Route Definition**: Use `app.method(path, handler)` to define routes for specific HTTP methods and paths.

### 4. How to handle Routing in real applications?

In real applications, routes redirect requests to controllers for modularity.

#### Steps
1. **Import Express**.
2. **Apply middleware** (e.g., logging, authentication).
3. **Import controllers**.
4. **Define routes** to map to controller methods.
5. **Start the server**.

#### Code Example
```javascript
const express = require("express");
const app = express();

// Middleware
app.use((req, res, next) => {
  console.log("Logging request");
  next();
});

// Controller
const orderController = {
  getOrderById: (req, res) => res.send(`Order ID: ${req.params.id}`),
};

// Routes
app.get("/orders/:id", orderController.getOrderById);

app.listen(3000);
```

#### Definition
**Real Application Routing**: Use middleware, controllers, and `app.method` to handle routes modularly.

### 5. What are Route Handlers?

**Route handlers** are callback functions that process requests and generate responses for a specific route.

#### Code Example
```javascript
app.get("/", (req, res) => {
  res.send("This is a route handler");
});
```

#### Definition
**Route Handler**: A callback function that processes requests for a specific route.

### 6. What are Route Parameters in Express.js?

**Route parameters** are dynamic values in the URL, accessed via `req.params`.

#### Code Example
```javascript
const express = require("express");
const app = express();

app.get("/users/:userId", (req, res) => {
  res.send(`User ID: ${req.params.userId}`);
});

app.listen(3000);
```

#### Testing
Visit `http://localhost:3000/users/123` → `User ID: 123`.

#### Definition
**Route Parameters**: Dynamic URL segments accessed via `req.params` for flexible routing.

### 7. What are Router Objects and Router Methods? How to implement them?

**Router objects** are mini Express applications for handling routes modularly. **Router methods** (e.g., `router.get`) define routes on the router.

#### Steps
1. Create a router with `express.Router()`.
2. Define routes using router methods.
3. Export the router.
4. Mount the router with `app.use`.

#### Code Example
**routes/users.js**:
```javascript
const express = require("express");
const router = express.Router();

router.get("/", (req, res) => res.send("User List"));
module.exports = router;
```

**app.js**:
```javascript
const express = require("express");
const app = express();
const userRouter = require("./routes/users");

app.use("/api", userRouter);
app.listen(3000);
```

#### Definition
**Router Objects and Methods**: `express.Router()` creates a router for modular routing; methods like `router.get` define routes.

### 8. What are the types of Router Methods?

Four main router methods:
- `router.get`: Handles GET requests.
- `router.post`: Handles POST requests.
- `router.put`: Handles PUT requests.
- `router.delete`: Handles DELETE requests.

#### Definition
**Router Methods**: `get`, `post`, `put`, `delete` handle specific HTTP methods.

### 9. What is the difference between `app.get` and `router.get` methods?

#### Comparison
| **Aspect**      | **`app.get`**               | **`router.get`**            |
| --------------- | --------------------------- | --------------------------- |
| **Scope**       | Defined on main app         | Defined on router object    |
| **Mounting**    | Automatically mounted       | Requires `app.use` to mount |
| **Reusability** | Not reusable across modules | Reusable via export/import  |

#### Code Example
**`app.get`**:
```javascript
app.get("/", (req, res) => res.send("Home"));
```

**`router.get`**:
```javascript
const router = express.Router();
router.get("/", (req, res) => res.send("Router Home"));
app.use("/api", router);
```

#### Definition
**`app.get` vs. `router.get`**: `app.get` defines routes on the main app; `router.get` defines reusable routes on a router object.

### 10. What is `express.Router` in Express.js?

**`express.Router`** is a class that creates a router object for modular routing.

#### Code Example
```javascript
const router = express.Router();
router.get("/", (req, res) => res.send("Router Route"));
app.use("/api", router);
```

#### Definition
**`express.Router`**: A class that creates a router object for organizing routes modularly.

### 11. Share a real application use of Routing.

Routing is used for **authentication** based on request headers.

#### Code Example
**routes/auth.js**:
```javascript
const express = require("express");
const router = express.Router();

const authMiddleware = (req, res, next) => {
  if (req.headers.authorization) {
    next();
  } else {
    res.status(401).send("Unauthorized");
  }
};

router.get("/protected", authMiddleware, (req, res) => {
  res.send("Protected Route Accessed");
});

module.exports = router;
```

**app.js**:
```javascript
const express = require("express");
const app = express();
const authRouter = require("./routes/auth");

app.use("/api", authRouter);
app.listen(3000);
```

#### Testing
- With `Authorization` header: Access granted.
- Without header: `Unauthorized`.

#### Definition
**Real Application Routing**: Use routing with middleware for tasks like authentication.

### 12. What is Route Chaining in Express.js?

**Route chaining** defines multiple handlers for a single route, executed sequentially.

#### Code Example
```javascript
const express = require("express");
const app = express();

const middleware1 = (req, res, next) => {
  console.log("Middleware 1");
  next();
};

const middleware2 = (req, res, next) => {
  console.log("Middleware 2");
  next();
};

app.get("/", middleware1, middleware2, (req, res) => {
  res.send("Route Handler");
});

app.listen(3000);
```

#### Output
```
Middleware 1
Middleware 2
Route Handler
```

#### Definition
**Route Chaining**: Defining multiple handlers for a single route for modularity and readability.

### 13. What is Route Nesting in Express.js?

**Route nesting** organizes related routes hierarchically under a common URL prefix.

#### Definition
**Route Nesting**: Grouping related routes (e.g., `/users/profile`) under a common prefix (e.g., `/users`) for modularity.

### 14. How to implement Route Nesting in Express.js?

#### Steps
1. Create separate router files for related routes.
2. Define nested routes in each file.
3. Export routers.
4. Mount routers in the main app.

#### Code Example
**routes/users.js**:
```javascript
const express = require("express");
const router = express.Router();

router.get("/", (req, res) => res.send("User List"));
router.get("/profile", (req, res) => res.send("User Profile"));

module.exports = router;
```

**routes/products.js**:
```javascript
const express = require("express");
const router = express.Router();

router.get("/", (req, res) => res.send("Product List"));
router.get("/features", (req, res) => res.send("Product Features"));

module.exports = router;
```

**app.js**:
```javascript
const express = require("express");
const app = express();
const userRouter = require("./routes/users");
const productRouter = require("./routes/products");

app.use("/users", userRouter);
app.use("/products", productRouter);

app.listen(3000);
```

#### Testing
- `http://localhost:3000/users/profile` → `User Profile`
- `http://localhost:3000/products/features` → `Product Features`

#### Definition
**Route Nesting Implementation**: Use `express.Router` to define nested routes and mount them with `app.use`.

---

## Chapter 8: Template Engines in Express.js

Template engines enable server-side rendering of dynamic HTML. This chapter covers their purpose and implementation.

### 1. What are Template Engines in Express.js?

**Template engines** generate dynamic HTML by combining static templates with data.

#### Flow Diagram
```
Data → Template Engine → HTML Template → Dynamic HTML → Client
```

#### Use Case
Server-side rendering for dynamic web pages.

#### Definition
**Template Engines**: Libraries that combine static HTML templates with data to generate dynamic HTML.

### 2. Name some Template Engine Libraries.

Popular template engines:
- **EJS** (Embedded JavaScript)
- **Handlebars**
- **Pug**
- **Mustache**
- **Nunjucks**

#### Definition
**Template Engine Libraries**: Libraries like EJS, Handlebars, and Pug for server-side rendering.

### 3. How to implement the EJS Templating Engine in an Express.js application?

EJS (Embedded JavaScript) is implemented in five steps:
1. **Install EJS**: `npm install ejs`.
2. **Create a views folder** with an EJS template (e.g., `index.ejs`).
3. **Set the view engine** to EJS.
4. **Set the views directory**.
5. **Render the template** with data.

#### Code Example
**views/index.ejs**:
```html
<!DOCTYPE html>
<html>
<head>
  <title><%= title %></title>
</head>
<body>
  <h1><%= title %></h1>
  <p>Static HTML content</p>
</body>
</html>
```

**server.js**:
```javascript
const express = require("express");
const path = require("path");
const app = express();

// Set view engine
app.set("view engine", "ejs");
app.set("views", path.join(__dirname, "views"));

// Route to render EJS template
app.get("/", (req, res) => {
  res.render("index", { title: "Dynamic Title" });
});

app.listen(3000, () => console.log("Server running on port 3000"));
```

#### Testing
Visit `http://localhost:3000`:
```
Dynamic Title
Static HTML content
```

#### Definition
**EJS Implementation**: Install EJS, create templates, set view engine and directory, and render with `res.render`.

---

## Interview Tips
- **Explain with Examples**: Use real-world scenarios (e.g., “In my last project, I used middleware for authentication”).
- **Show Confidence**: Knowing implementations (e.g., EJS, routing) boosts your ability to explain concepts.
- **Practice Code**: Run the provided snippets to understand their behavior.
- **Stay Positive**: Keep applying and learning from feedback.

Congratulations on mastering Express.js fundamentals! You’re now equipped to handle questions on middleware, routing, and template engines. Stay tuned for Part 3, covering **REST APIs** and more. Share your success stories in the comments, and keep pushing toward your dream Node.js developer role!