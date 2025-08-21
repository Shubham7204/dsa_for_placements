# Chapter 5: REST API Basics

REST APIs are the backbone of modern web applications, and Node.js is a popular choice for building them. This chapter covers the fundamentals of REST and RESTful APIs, their structure, and key guidelines to ensure you have a solid foundation for interview questions.

## 1. What are REST and RESTful APIs?

**REST (Representational State Transfer)** is an architectural style for designing networked applications, providing guidelines for creating scalable APIs. A **RESTful API** is a service that adheres to these guidelines, ensuring efficient and standardized communication between clients and servers.

### Flow Diagram
```
User → Browser → UI Server (React/Angular) → REST API (Node.js) → Database
```

### How It Works
1. A user enters a URL in the browser.
2. The browser sends a request to the UI server (e.g., React, Angular).
3. The UI server processes static content (HTML, CSS) and forwards dynamic data requests to the REST API.
4. The REST API fetches data from the database and returns it in JSON format.
5. The UI server converts JSON to HTML and sends it to the browser.

### Example
**GET Request to REST API**:
```javascript
// Assume a Node.js REST API endpoint
app.get('/users', (req, res) => {
  res.json({ users: [{ id: 1, name: 'John' }, { id: 2, name: 'Jane' }] });
});
```

### Definition
**REST**: An architectural style for designing networked applications, focusing on accurate data transfer.  
**RESTful API**: A service following REST principles, typically using HTTP and JSON for communication.

## 2. What are the HTTP Request and Response Structure in UI and REST API?

Understanding the structure of HTTP requests and responses is crucial for working with REST APIs. Let’s break it down.

### Flow Diagram
```
Browser → UI Server → REST API → Database
```

### HTTP Request Structure
- **From Browser to UI Server**:
  ```http
  POST /signup HTTP/1.1
  Host: example.com
  Content-Type: application/json
  Content-Length: 67

  {
    "username": "john_doe",
    "password": "secure123"
  }
  ```
  - **Action/Method**: POST (indicates the action, e.g., GET, POST).
  - **URL**: `/signup` (endpoint on the UI server).
  - **Headers**: `Content-Type` (format), `Host` (server address).
  - **Body**: JSON payload with user data.

- **From UI Server to REST API**:
  ```http
  POST /api/signup HTTP/1.1
  Host: api.example.com
  Content-Type: application/json
  Content-Length: 67

  {
    "username": "john_doe",
    "password": "secure123"
  }
  ```
  - Same structure, but the `Host` is now the API server’s address.

### HTTP Response Structure
- **From REST API to UI Server**:
  ```http
  HTTP/1.1 201 Created
  Content-Type: application/json
  Content-Length: 45

  {
    "message": "User created",
    "userId": 123
  }
  ```
  - **Status Code**: 201 (indicates success).
  - **Headers**: `Content-Type` (JSON), `Content-Length`.
  - **Body**: JSON response with data.

- **From UI Server to Browser**:
  ```http
  HTTP/1.1 200 OK
  Content-Type: text/html
  Content-Length: 120

  <html>
    <body>
      <h1>User created successfully!</h1>
    </body>
  </html>
  ```
  - UI server converts JSON to HTML for browser rendering.

### Definition
**HTTP Request/Response**: Requests include method, URL, headers, and optional body; responses include status code, headers, and body (JSON from API, HTML from UI server).

## 3. What are the Top Five REST Guidelines and Their Advantages?

RESTful APIs follow specific guidelines to ensure scalability and maintainability. Here are the top five:

### Guidelines and Advantages
1. **Separation of Client and Server**:
   - **Guideline**: Client (UI) and server (API) are developed independently.
   - **Advantage**: Simplifies maintenance; allows multiple clients (web, mobile) to use the same API.
   - **Example**: A Node.js API serves both a React web app and a mobile app.
2. **Stateless**:
   - **Guideline**: Each request is independent; the server stores no session data.
   - **Advantage**: Lightweight server, simplifies scaling.
   - **Example**: API doesn’t store user session; client sends all required data.
3. **Uniform Interface**:
   - **Guideline**: URLs uniquely identify resources (e.g., `/api/shoes` for shoes).
   - **Advantage**: Predictable, easy-to-understand APIs.
   - **Example**:
     ```javascript
     app.get('/api/shoes', (req, res) => res.json({ shoes: [...] }));
     ```
4. **Cacheable**:
   - **Guideline**: Responses can be cached to improve performance.
   - **Advantage**: Faster response times for frequent requests.
   - **Example**: Cache `/api/users` response to reduce database queries.
5. **Layered System**:
   - **Guideline**: Use modular architecture (e.g., MVC).
   - **Advantage**: Enhances modularity, maintainability.
   - **Example**: Separate controllers, models, and routes in Node.js.

### Definition
**REST Guidelines**: Principles like separation of client/server, statelessness, uniform interface, cacheability, and layered system ensure scalable, maintainable APIs.

## 4. What is the Difference Between REST API and SOAP API?

REST and SOAP are two approaches to building APIs, but REST is more popular today. Let’s compare them.

### Comparison
| **Feature**                | **REST API**                              | **SOAP API**                              |
|----------------------------|-------------------------------------------|-------------------------------------------|
| **Type**                   | Architectural style                       | Protocol (Simple Object Access Protocol)  |
| **Protocol**               | HTTP/HTTPS only                          | HTTP, SMTP, etc.                          |
| **Data Format**            | JSON, XML (lightweight)                  | XML (heavier)                             |
| **State**                  | Stateless                                | Stateful or stateless                     |
| **Error Handling**         | HTTP status codes (200, 404, etc.)       | Custom fault mechanism                    |
| **Performance**            | Lightweight, faster                      | Slower due to XML processing              |

### Definition
**REST vs. SOAP**: REST is a lightweight, stateless architectural style using HTTP and JSON; SOAP is a protocol using XML, often slower and more complex.

---

# Chapter 6: HTTP Methods and Status Codes

HTTP methods and status codes are critical for REST API communication. This chapter explores their roles and implementation in Node.js.

## 1. What are HTTP Verbs and HTTP Methods?

**HTTP methods** (or verbs) define the action a client wants to perform on a resource. Common methods include GET, POST, PUT, DELETE, and PATCH.

### Flow Diagram
```
Browser → UI Server → REST API (GET/POST/PUT/DELETE) → Database
```

### Example
```javascript
const express = require('express');
const app = express();

app.get('/api/users', (req, res) => res.json({ users: [...] }));
app.post('/api/users', (req, res) => res.json({ message: 'User created' }));
```

### Definition
**HTTP Methods**: A set of functions (GET, POST, PUT, DELETE, etc.) that define actions on resources in a REST API.

## 2. What are GET, POST, PUT, and DELETE HTTP Methods?

### Definitions and Examples
1. **GET**: Retrieves data from a resource.
   ```javascript
   app.get('/api/users', (req, res) => {
     res.json({ users: [{ id: 1, name: 'John' }, { id: 2, name: 'Jane' }] });
   });
   app.get('/api/users/:id', (req, res) => {
     res.json({ user: { id: req.params.id, name: 'John' } });
   });
   ```
   - **Use Case**: Fetch all users or a single user by ID.

2. **POST**: Submits data to create a new resource.
   ```javascript
   app.post('/api/users', (req, res) => {
     const user = req.body; // { name: 'John', email: 'john@example.com' }
     res.status(201).json({ message: 'User created', user });
   });
   ```
   - **Use Case**: Create a new user with provided data.

3. **PUT**: Updates an existing resource or creates it if it doesn’t exist.
   ```javascript
   app.put('/api/users/:id', (req, res) => {
     const user = req.body; // { name: 'John', email: 'new@example.com' }
     res.json({ message: `User ${req.params.id} updated`, user });
   });
   ```
   - **Use Case**: Update user details completely.

4. **DELETE**: Removes a resource.
   ```javascript
   app.delete('/api/users/:id', (req, res) => {
     res.json({ message: `User ${req.params.id} deleted` });
   });
   ```
   - **Use Case**: Delete a user by ID.

### Definition
**GET/POST/PUT/DELETE**: GET retrieves data, POST creates resources, PUT updates or creates resources, DELETE removes resources.

## 3. What is the Difference Between PUT and PATCH Methods?

Both **PUT** and **PATCH** update resources, but they differ in scope.

### Comparison
| **Aspect**         | **PUT**                              | **PATCH**                            |
|--------------------|--------------------------------------|--------------------------------------|
| **Update Type**    | Complete resource replacement        | Partial resource update              |
| **Request Body**   | All fields required                 | Only fields to update                |
| **Example**        | Replace entire user object          | Update only email and age            |

### Example
**PUT Request**:
```http
PUT /api/users/123 HTTP/1.1
Content-Type: application/json

{
  "name": "John",
  "email": "new@example.com",
  "age": 30
}
```
- Replaces the entire user resource with ID 123.

**PATCH Request**:
```http
PATCH /api/users/123 HTTP/1.1
Content-Type: application/json

{
  "email": "updated@example.com",
  "age": 31
}
```
- Updates only the specified fields (email, age).

### Definition
**PUT vs. PATCH**: PUT replaces the entire resource; PATCH updates specific fields.

## 4. Explain the Concept of Idempotent in RESTful APIs

**Idempotent** operations produce the same result regardless of how many times they’re executed.

### Idempotent Methods
- **GET**: Fetching `/api/users` always returns the same list (if unchanged).
- **PUT**: Updating `/api/users/123` with the same data yields the same result.
- **DELETE**: Deleting `/api/users/123` multiple times has no additional effect after the first.

### Non-Idempotent Method
- **POST**: Creating a new user with `/api/users` creates a new user each time.

### Example
```javascript
app.get('/api/users', (req, res) => res.json({ users: [...] })); // Idempotent
app.post('/api/users', (req, res) => res.json({ userId: Math.random() })); // Non-idempotent
```

### Definition
**Idempotent**: Operations (GET, PUT, DELETE) that produce the same result when repeated; POST is non-idempotent as it creates new resources.

## 5. What is the Role of Status Codes in RESTful APIs?

**Status codes** indicate the outcome of a client’s request to the API.

### Common Status Codes
| **Code** | **Meaning**                     | **Description**                              |
|----------|---------------------------------|----------------------------------------------|
| **1xx**  | Informational                  | Request received, processing (rarely used).   |
| **2xx**  | Success                        | Request successful.                          |
| **200**  | OK                             | Request successful with content.             |
| **201**  | Created                        | Resource created successfully.               |
| **204**  | No Content                     | Request successful, no content returned.     |
| **3xx**  | Redirection                    | Request redirected (rare in APIs).           |
| **4xx**  | Client Error                   | Issue with the client request.               |
| **400**  | Bad Request                    | Invalid request format/data.                 |
| **401**  | Unauthorized                   | Authentication failed.                       |
| **403**  | Forbidden                      | Authorized but access denied.                |
| **404**  | Not Found                      | Resource not found.                          |
| **5xx**  | Server Error                   | Issue on the server side.                    |
| **500**  | Internal Server Error          | Server failure (e.g., database down).        |

### Example
```javascript
app.get('/api/users/:id', (req, res) => {
  if (!userExists(req.params.id)) {
    return res.status(404).json({ error: 'User not found' });
  }
  res.status(200).json({ user: { id: req.params.id, name: 'John' } });
});
```

### Definition
**Status Codes**: Numeric codes in HTTP responses indicating the result of a request (success, client error, server error).

---

# Chapter 7: Serialization, Deserialization, and API Documentation

This chapter covers serialization/deserialization, versioning, and API documentation—key concepts for building robust REST APIs.

## 1. What is CORS in RESTful APIs?

**CORS (Cross-Origin Resource Sharing)** is a browser security feature that restricts web pages from accessing resources on different domains, subdomains, protocols, or ports unless explicitly allowed.

### Scenarios Where CORS Restricts Access
1. Different domain: `interview.com` cannot access `xyz.com`.
2. Subdomain: `interview.com` cannot access `api.interview.com`.
3. Protocol: `http://interview.com` cannot access `https://interview.com`.
4. Port: `interview.com:3000` cannot access `interview.com:4000`.

### Example
```javascript
// Without CORS, this request fails due to browser restrictions
fetch('http://api.example.com/data') // Blocked by CORS
```

### Definition
**CORS**: A browser security mechanism that restricts cross-origin resource sharing unless explicitly allowed by the server.

## 2. How to Remove CORS Restrictions on RESTful APIs?

To allow cross-origin requests, use the `cors` middleware in Express.

### Example
**Enable CORS for All Domains**:
```javascript
const express = require('express');
const cors = require('cors');
const app = express();

app.use(cors()); // Allow all domains
app.get('/api/data', (req, res) => res.json({ data: 'Hello' }));
app.listen(3000);
```

**Configure CORS for Specific Domains**:
```javascript
const express = require('express');
const cors = require('cors');
const app = express();

app.use(cors({
  origin: 'http://example.com' // Allow only example.com
}));
app.get('/api/data', (req, res) => res.json({ data: 'Hello' }));
app.listen(3000);
```

### Definition
**Removing CORS Restrictions**: Use the `cors` middleware to allow cross-origin requests, optionally configuring specific domains.

## 3. What are Serialization and Deserialization?

**Serialization** converts an object into a format (e.g., JSON) for transmission. **Deserialization** converts the received format back into an object.

### Flow Diagram
```
REST API 1 → Serialize Object to JSON → Network → REST API 2 → Deserialize JSON to Object
```

### Why Use Serialization?
- Objects are handled differently across technologies (Node.js, Java, .NET).
- JSON is a universal format, making it ideal for cross-platform communication.

### Example
```javascript
// Serialization
const user = { name: 'John', age: 30 };
const jsonString = JSON.stringify(user); // {"name":"John","age":30}

// Deserialization
const parsedObject = JSON.parse(jsonString); // { name: 'John', age: 30 }
```

### Definition
**Serialization**: Converting an object to a transmittable format (e.g., JSON).  
**Deserialization**: Converting the format back to an object.

## 4. What are the Types of Serialization?

### Types
1. **Binary Serialization**: Converts data to binary/byte format.
2. **XML Serialization**: Converts data to XML format.
3. **JSON Serialization**: Converts data to JSON format (most popular).

### Definition
**Serialization Types**: Binary (bytes), XML, and JSON (most common in REST APIs).

## 5. How to Serialize and Deserialize in Node.js?

Node.js uses `JSON.stringify` for serialization and `JSON.parse` for deserialization.

### Example
**Serialization**:
```javascript
const user = { name: 'John', age: 30 };
const jsonString = JSON.stringify(user);
console.log(jsonString); // {"name":"John","age":30}
```

**Deserialization**:
```javascript
const jsonString = '{"name":"John","age":30}';
const user = JSON.parse(jsonString);
console.log(user); // { name: 'John', age: 30 }
```

### Definition
**Serialize/Deserialize in Node.js**: Use `JSON.stringify` to convert objects to JSON; use `JSON.parse` to convert JSON to objects.

## 6. Explain the Concept of Versioning in RESTful APIs

**Versioning** maintains multiple API versions to support backward compatibility for clients not ready for updates.

### Why Versioning?
- New API versions may introduce breaking changes.
- Clients can continue using older versions to avoid disruptions.

### Example
```javascript
// Version 1
app.get('/api/v1/users', (req, res) => res.json({ users: [...] }));

// Version 2
app.get('/api/v2/users', (req, res) => res.json({ users: [...], newField: true }));
```

### Definition
**Versioning**: Maintaining multiple API versions (e.g., `/api/v1`, `/api/v2`) to ensure compatibility with clients.

## 7. What is an API Document? What are Popular Documentation Formats?

An **API document** describes the functionality, endpoints, and request/response structures of a REST API for client consumption.

### Example
**Swagger Documentation**:
```yaml
paths:
  /users:
    get:
      summary: Get list of users
      responses:
        200:
          description: Success
          content:
            application/json:
              schema:
                type: array
                items:
                  type: object
                  properties:
                    id: { type: integer }
                    name: { type: string }
```

### Popular Formats
- **Swagger/OpenAPI**: Widely used, machine-readable.
- **RAML**: RESTful API Modeling Language.
- **API Blueprint**: Simple, human-readable format.

### Definition
**API Document**: A guide detailing API endpoints, methods, and structures for client use, often in Swagger, RAML, or API Blueprint formats.

## 8. What is the Typical Structure of a REST API Project in Node.js?

A Node.js REST API project follows a modular structure for maintainability.

### Folder Structure
```
my-api/
├── node_modules/          # NPM dependencies
├── src/
│   ├── controllers/       # Business logic (GET, POST, etc.)
│   │   ├── products.js
│   │   ├── users.js
│   ├── models/            # Data schemas (e.g., Product, User)
│   │   ├── product.js
│   │   ├── user.js
│   ├── routes/            # Route definitions
│   │   ├── products.js
│   │   ├── users.js
│   ├── utils/             # Helper functions (validation, error handling)
│   │   ├── error.js
│   │   ├── validation.js
│   ├── app.js             # Main entry point
├── .gitignore             # Ignore node_modules, etc.
├── package.json           # Project metadata and dependencies
```

### Example
**app.js**:
```javascript
const express = require('express');
const app = express();

app.use(express.json());
app.use('/api/products', require('./src/routes/products'));
app.use('/api/users', require('./src/routes/users'));

app.listen(3000, () => console.log('Server running on port 3000'));
```

**routes/products.js**:
```javascript
const express = require('express');
const router = express.Router();
const productController = require('../controllers/products');

router.get('/', productController.getProducts);
module.exports = router;
```

### Definition
**REST API Structure**: A modular setup with folders for controllers, models, routes, utils, and main entry (app.js), plus `package.json` and `.gitignore`.

---

# Chapter 8: Authentication and Authorization

Authentication and authorization are critical for securing REST APIs. This chapter covers their concepts, types, and implementation in Node.js.

## 1. What are Authentication and Authorization?

- **Authentication**: Verifies a user’s identity (e.g., username/password login).
- **Authorization**: Determines what a user can access based on their role (e.g., student, teacher).

### Analogy
- **Authentication**: Proving you’re a student at a school by showing your ID.
- **Authorization**: Accessing only student-specific features (e.g., view grades, not edit them).

### Flow Diagram
```
Browser → Login (Authentication) → API (Authorization) → Resources
```

### Example
```javascript
app.post('/login', (req, res) => {
  const { username, password } = req.body;
  if (username === 'student' && password === 'pass123') {
    res.json({ message: 'Authenticated', role: 'student' });
  } else {
    res.status(401).json({ error: 'Invalid credentials' });
  }
});
```

### Definition
**Authentication**: Verifying user identity.  
**Authorization**: Controlling access to resources based on roles.

## 2. What are the Types of Authentication in Node.js?

Five main authentication types used in Node.js and other technologies:
1. **Basic Authentication**: Username/password sent in plain text.
2. **API Key Authentication**: Single key shared with clients.
3. **Token-Based Authentication**: Tokens (e.g., JWT) for secure access.
4. **JWT Authentication**: A type of token-based authentication using JSON Web Tokens.
5. **Multi-Factor Authentication**: Multiple verification steps (e.g., password + OTP).
6. **Certificate-Based Authentication**: Uses digital certificates (less common).

### Definition
**Authentication Types**: Basic, API key, token-based, JWT, multi-factor, and certificate-based methods for verifying user identity.

## 3. What is Basic Authentication?

**Basic authentication** verifies a user’s identity using a username and password sent in plain text.

### Example
```javascript
app.post('/login', (req, res) => {
  const { username, password } = req.body;
  if (username === 'user' && password === 'pass') {
    res.json({ message: 'Authenticated' });
  } else {
    res.status(401).json({ error: 'Invalid credentials' });
  }
});
```

### Disadvantages
- Passwords sent in plain text (security risk).
- Passwords stored as plain text in the database (vulnerable to breaches).

### Definition
**Basic Authentication**: Uses username/password for identity verification, but insecure due to plain text transmission.

## 4. What are the Security Risks Associated with Storing Passwords as Plain Text in Node.js?

Storing passwords as plain text in the database poses significant risks.

### Risks
1. **Unauthorized Access**: Hackers accessing the database can use plain text passwords to log in.
2. **Compromised Accounts**: Users reusing passwords across platforms risk multiple account breaches.

### Example
**Insecure Storage**:
```javascript
// Database table (insecure)
{
  username: 'john_doe',
  password: 'pass123' // Plain text
}
```

**Secure Storage**:
```javascript
// Database table (secure)
{
  username: 'john_doe',
  password: 'hashed_password_with_salt' // Encrypted
}
```

### Definition
**Plain Text Password Risks**: Exposure to unauthorized access and compromise of other accounts due to password reuse.

## 5. What is the Role of Hashing and Salt in Securing Passwords?

**Hashing** encrypts a password using an algorithm (e.g., SHA-256). **Salt** adds a random string to the password before hashing for extra security.

### Flow
```
Password → Add Salt → Hash → Secure Password
```

### Example
```javascript
const crypto = require('crypto');

function hashPassword(password) {
  const salt = crypto.randomBytes(16).toString('hex');
  const hash = crypto.createHash('sha256').update(salt + password).digest('hex');
  return `${salt}:${hash}`;
}

const securePassword = hashPassword('pass123');
console.log(securePassword); // e.g., "a1b2c3...:hashed_value"
```

### Why Salt?
- Prevents hackers from decoding passwords even if they know the hashing algorithm.

### Definition
**Hashing and Salt**: Hashing encrypts passwords; salt adds a random string to enhance security, making passwords harder to crack.

## 6. How Can We Create Hash Passwords in Node.js?

Use the `crypto` library to hash passwords with salt in five steps.

### Example
```javascript
const crypto = require('crypto');

function hashPassword(password) {
  // Step 1: Generate random salt
  const salt = crypto.randomBytes(16).toString('hex');
  
  // Step 2: Create hash object
  const hash = crypto.createHash('sha256');
  
  // Step 3: Combine salt and password
  hash.update(salt + password);
  
  // Step 4: Convert to hexadecimal string
  const hashedPassword = hash.digest('hex');
  
  // Step 5: Return salt and hash
  return `${salt}:${hashedPassword}`;
}

const securePassword = hashPassword('pass123');
console.log(securePassword); // e.g., "a1b2c3...:hashed_value"
```

### Definition
**Hash Passwords in Node.js**: Use `crypto.randomBytes` for salt, `crypto.createHash` for hashing, and combine them for secure storage.

## 7. What is API Key Authentication?

**API key authentication** uses a single key shared with clients to authenticate requests, avoiding username/password storage.

### Example
**Postman Request**:
```http
GET /api/data HTTP/1.1
Host: api.example.com
X-API-Key: abc123xyz
```

### Disadvantages
- Keys can be shared easily, leading to unauthorized access.
- Less secure than token-based methods.

### Definition
**API Key Authentication**: Uses a shared key for authentication, simple but less secure due to potential key sharing.

## 8. What is Token-Based Authentication and JWT Authentication?

**Token-based authentication** uses tokens to verify users without storing session data. **JWT (JSON Web Token)** is a popular token-based authentication method.

### JWT Authentication Flow (8 Steps)
1. Client sends username/password via POST request.
2. API validates credentials in the database.
3. If valid, API generates a JWT and sends it to the client.
4. Client stores the JWT in local storage or cookies.
5. For subsequent requests, the client includes the JWT in the request header.
6. API validates the JWT signature.
7. If valid, API sends the requested data.
8. Client displays data in the browser.

### Flow Diagram
```
Browser → POST /login (username, password) → API → JWT → Browser (Store JWT)
Browser → GET /data (JWT in header) → API (Validate JWT) → Data
```

### Example
```javascript
const jwt = require('jsonwebtoken');

app.post('/login', (req, res) => {
  const { username, password } = req.body;
  if (username === 'user' && password === 'pass') {
    const token = jwt.sign({ username }, 'secret_key');
    res.json({ token });
  } else {
    res.status(401).json({ error: 'Invalid credentials' });
  }
});

app.get('/data', (req, res) => {
  const token = req.headers.authorization;
  try {
    jwt.verify(token, 'secret_key');
    res.json({ data: 'Protected data' });
  } catch (err) {
    res.status(401).json({ error: 'Invalid token' });
  }
});
```

### Definition
**Token-Based Authentication**: Uses tokens for secure, stateless authentication.  
**JWT Authentication**: A token-based method using JSON Web Tokens for secure data exchange.

## 9. What are the Parts of a JWT Token?

A **JWT** consists of three parts, separated by dots (`.`):
1. **Header**: Contains token type (`JWT`) and signing algorithm (e.g., HMAC SHA256).
2. **Payload**: Contains claims (e.g., issuer, subject, expiration).
3. **Signature**: Verifies token integrity, created by encoding header and payload.

### Example
**JWT**:
```
eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJzdWIiOiIxMjMiLCJuYW1lIjoiSm9obiIsImV4cCI6MTY1MDAwMDAwMH0.signature
```

- **Header**: `{"alg":"HS256","typ":"JWT"}`
- **Payload**: `{"sub":"123","name":"John","exp":1650000000}`
- **Signature**: Encoded combination of header and payload.

### Definition
**JWT Parts**: Header (type, algorithm), payload (claims), and signature (validation).

## 10. Where Does a JWT Token Reside in the Request?

The **JWT** is included in the **Authorization** header of HTTP requests, typically with the `Bearer` prefix.

### Example
**Postman Request**:
```http
GET /api/data HTTP/1.1
Host: api.example.com
Authorization: Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9...
```

### Definition
**JWT in Request**: Resides in the `Authorization` header as `Bearer <token>`.

---

# Chapter 9: Error Handling and Debugging

Error handling and debugging are essential for building reliable Node.js applications. This chapter covers techniques to manage errors and debug code effectively.

## 1. What is Error Handling? How Many Ways Can You Implement Error Handling in Node Applications?

**Error handling** manages errors during program execution, ensuring proper logging and user-friendly responses.

### Techniques
1. **Try-Catch Block**: For synchronous operations.
2. **Error-First Callbacks**: For asynchronous operations.
3. **Promises with `.catch()`**: For promise-based async operations.
4. **Try-Catch with Async/Await**: For async/await operations.
5. **Middleware (Express)**: For handling errors in REST APIs.

### Definition
**Error Handling**: Managing errors during execution using try-catch, callbacks, promises, async/await, or middleware.

## 2. How to Handle Errors in Synchronous Operations Using Try-Catch-Finally?

Use **try-catch-finally** to handle errors in synchronous code, with `finally` executing regardless of errors.

### Example
```javascript
try {
  // Synchronous code
  throw new Error('Something went wrong');
  console.log('This won’t run');
} catch (error) {
  console.error('Error:', error.message);
} finally {
  console.log('This always runs');
}

// Output:
// Error: Something went wrong
// This always runs
```

### Definition
**Try-Catch-Finally**: `try` runs code, `catch` handles errors, `finally` executes regardless (e.g., for cleanup).

## 3. What is Error-First Callbacks?

**Error-first callbacks** handle errors in asynchronous operations by passing an error object as the first argument.

### Example
```javascript
function asyncOperation(callback) {
  setTimeout(() => {
    const error = new Error('Async error');
    callback(error, null); // Error-first
  }, 1000);
}

asyncOperation((error, result) => {
  if (error) {
    console.error('Error:', error.message);
    return;
  }
  console.log('Result:', result);
});

// Output: Error: Async error
```

### Definition
**Error-First Callbacks**: Asynchronous functions pass an error object as the first argument to a callback for error handling.

## 4. How to Handle Errors Using Promises?

Use the `.catch()` method to handle errors in promise-based operations.

### Example
```javascript
const myPromise = new Promise((resolve, reject) => {
  setTimeout(() => reject(new Error('Promise error')), 1000);
});

myPromise
  .then(result => console.log('Result:', result))
  .catch(error => console.error('Error:', error.message));

// Output: Error: Promise error
```

### Definition
**Promise Error Handling**: Use `.catch()` to handle errors in promise-based asynchronous operations.

## 5. How to Handle Errors Using Async/Await?

Use **try-catch** with async/await to handle errors in asynchronous code.

### Example
```javascript
async function fetchData() {
  try {
    const result = await new Promise((resolve, reject) => {
      setTimeout(() => reject(new Error('Async error')), 1000);
    });
    console.log('Result:', result);
  } catch (error) {
    console.error('Error:', error.message);
  }
}

fetchData();

// Output: Error: Async error
```

### Definition
**Async/Await Error Handling**: Use try-catch to handle errors in async/await operations.

## 6. How Can You Debug Node.js Applications?

Debugging Node.js applications involves identifying and fixing issues using various tools and techniques.

### Techniques
1. **console.log**: Log variables to inspect values.
2. **Debugger Statement**: Pause execution for inspection.
3. **Node.js Inspector**: Built-in debugging tool.
4. **VS Code Debugger**: Integrated debugging in VS Code.
5. **Chrome Developer Tools**: Debug Node.js apps via `node --inspect`.

### Example (console.log)
```javascript
function calculateSum(a, b) {
  console.log('Inputs:', a, b);
  return a + b;
}
console.log(calculateSum(2, 3)); // Inputs: 2 3, Output: 5
```

### Example (Debugger)
```javascript
function buggyFunction() {
  debugger; // Pause execution
  let result = 0 / 0; // NaN
  console.log(result);
}
buggyFunction();
```

### Definition
**Debugging Node.js**: Use console.log, debugger, Node.js inspector, VS Code, or Chrome DevTools to identify and fix issues.

---

# Final Interview Tips
- **Master REST APIs**: Understand REST principles, HTTP methods, and status codes thoroughly.
- **Practice Authentication**: Be ready to explain JWT and other authentication types with examples.
- **Handle Errors Confidently**: Know try-catch, promises, and async/await error handling.
- **Debug Effectively**: Mention debugging tools you’ve used (e.g., console.log, VS Code debugger).
- **Stay Resilient**: Keep learning, apply for jobs, and never give up, even after rejections.

Congratulations on completing this milestone! You’re now equipped to tackle REST API and error handling questions in Node.js interviews. Share your success stories in the comments to inspire others, and keep pushing forward—your dream job is within reach!