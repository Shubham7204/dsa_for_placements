# Chapter 9: Component Lifecycle Methods (Part 1)

React’s **component lifecycle methods** are crucial for understanding how class components work. These methods are invoked at specific stages of a component’s life, allowing developers to control initialization, updates, and cleanup. Let’s explore six key questions.

## 1. What are Component Lifecycle Phases?

Every React class component goes through three lifecycle phases:

1. **Mounting Phase**: The component is created and inserted into the DOM.
2. **Updating Phase**: The component re-renders due to changes in state or props.
3. **Unmounting Phase**: The component is removed from the DOM.

### Details
- **Mounting**: Methods execute before the component is rendered (e.g., constructor, render).
- **Updating**: Triggered by state or prop changes, re-rendering the component.
- **Unmounting**: Occurs when the component is replaced or removed.

### Definition
**Component Lifecycle Phases**: Mounting (creation and DOM insertion), Updating (re-rendering due to state/prop changes), and Unmounting (removal from DOM).

## 2. What are Component Lifecycle Methods?

Each lifecycle phase has specific methods that execute in sequence, allowing developers to hook into the component’s lifecycle.

### Lifecycle Methods
- **Mounting Phase**:
  1. `constructor`
  2. `static getDerivedStateFromProps`
  3. `render`
  4. `componentDidMount`
- **Updating Phase**:
  1. `static getDerivedStateFromProps`
  2. `shouldComponentUpdate`
  3. `render`
  4. `getSnapshotBeforeUpdate`
  5. `componentDidUpdate`
- **Unmounting Phase**:
  1. `componentWillUnmount`

### Key Points
- **Render in Both Phases**: `render` is called during mounting (initial render) and updating (re-render).
- **Focus on Key Methods**: For interviews, focus on `constructor`, `render`, `componentDidMount`, `componentDidUpdate`, and `componentWillUnmount`.

### Definition
**Component Lifecycle Methods**: Special methods called at various stages of a component’s lifecycle (mounting, updating, unmounting).

## 3. What are Constructors in Class Components? When to Use Them?

The `constructor` is the first method called during the **mounting phase**. It’s a specialized function that runs automatically when a component is instantiated.

### Example
```jsx
import React, { Component } from 'react';

class ExampleComponent extends Component {
  constructor(props) {
    super(props);
    this.state = { count: 0 };
  }

  render() {
    return <h2>Count: {this.state.count}</h2>;
  }
}

export default ExampleComponent;
```

### How It Works
- **Automatic Invocation**: Called when the component is created (e.g., from `App.js` or `index.js`).
- **Purpose**: Initializes state or performs setup before rendering.
- **Execution**: Runs before `render`, ensuring state is ready for the UI.

### When to Use
- Initialize component state (e.g., `this.state = { count: 0 }`).
- Set up bindings or initial configurations.

### Definition
**Constructor**: A specialized function in class components that initializes state or performs setup before rendering, called automatically during mounting.

## 4. What is the role of the `super` keyword in the Constructor?

The `super` keyword calls the parent class’s (`React.Component`) constructor, ensuring proper initialization.

### Example
```jsx
class ExampleComponent extends React.Component {
  constructor(props) {
    super(props); // Calls React.Component's constructor
    this.state = { count: 0 };
  }

  render() {
    return <h2>Count: {this.state.count}</h2>;
  }
}
```

### Why `super`?
- **Rule**: A child class constructor must call the parent class constructor.
- **Impact**: Omitting `super(props)` causes errors, as the component won’t initialize properly.

### Key Points
1. Calls the parent class (`React.Component`) constructor.
2. Ensures parent class initialization logic (e.g., `props` setup) runs.

### Definition
**super Keyword**: Used in a class component’s constructor to call the parent class constructor, ensuring proper initialization.

## 5. What is the role of the `render` method in the Component Lifecycle?

The `render` method is responsible for returning the JSX that defines the component’s UI.

### Example
```jsx
class ExampleComponent extends React.Component {
  constructor(props) {
    super(props);
    this.state = { count: 0 };
  }

  render() {
    return <h2>Count: {this.state.count}</h2>;
  }
}
```

### How It Works
- **Mounting Phase**: Renders the initial UI to the DOM.
- **Updating Phase**: Re-renders the UI when state or props change.
- **Purpose**: Defines what appears in the browser (DOM).

### Key Points
- Present in both mounting and updating phases.
- Must return JSX or `null`.
- Use technical terms like “DOM” in interviews for professionalism.

### Definition
**render Method**: Returns React elements to be rendered to the DOM during mounting and updating phases.

## 6. How can State be maintained in a Class Component?

State in class components is managed using `this.state` and `this.setState`.

### Example
```jsx
class Counter extends React.Component {
  constructor(props) {
    super(props);
    this.state = { count: 0 };
    this.handleIncrement = this.handleIncrement.bind(this);
  }

  handleIncrement() {
    this.setState((prevState) => ({ count: prevState.count + 1 }));
  }

  render() {
    return (
      <div>
        <p>Count: {this.state.count}</p>
        <button onClick={this.handleIncrement}>Increment</button>
      </div>
    );
  }
}
```

### How It Works
1. **Initialize State**: Set initial state in `constructor` (e.g., `this.state = { count: 0 }`).
2. **Update State**: Use `this.setState` to update state and trigger a re-render.
3. **Render**: Display updated state in the DOM via `this.state`.

### Output
Clicking “Increment” updates `count` and re-renders the UI, making the component **stateful**.

### Definition
**State Management in Class Components**: Uses `this.setState` to update state and `this.state` to render it in the DOM.

## 7. What is the role of the `componentDidMount` method in the Component Lifecycle?

The `componentDidMount` method runs **after** the component is rendered to the DOM, ideal for **side effects** like data fetching.

### Example
```jsx
class DataFetcher extends React.Component {
  constructor(props) {
    super(props);
    this.state = { data: null };
  }

  componentDidMount() {
    fetch('https://api.example.com/data')
      .then((response) => response.json())
      .then((data) => this.setState({ data }));
  }

  render() {
    return <div>{this.state.data ? this.state.data : 'Loading...'}</div>;
  }
}
```

### How It Works
1. **Timing**: Executes after `render` in the mounting phase.
2. **Purpose**: Handles side effects (e.g., API calls, subscriptions).
3. **State Update**: Updates state with fetched data, triggering a re-render in the updating phase.

### Definition
**componentDidMount**: A lifecycle method called after a component is rendered to the DOM, used for side effects like data fetching.

---

# Chapter 10: Controlled and Uncontrolled Components

Forms are a core part of web applications, and React handles them using **controlled** and **uncontrolled** components. Let’s explore eight questions.

## 1. What are Controlled Components in React?

A **controlled component** has form elements (e.g., input, checkbox) controlled by React state.

### Example
```jsx
import { useState } from 'react';

function ControlledForm() {
  const [inputValue, setInputValue] = useState('');

  const handleInputChange = (e) => {
    setInputValue(e.target.value);
  };

  return (
    <div>
      <input type="text" value={inputValue} onChange={handleInputChange} />
      <p>Input: {inputValue}</p>
    </div>
  );
}
```

### How It Works
- **State Control**: `inputValue` state stores the input’s value.
- **Event Handling**: `onChange` updates the state with `setInputValue`.
- **Rendering**: The input and UI reflect the state.

### Output
Typing in the input updates the paragraph below in real-time.

### Definition
**Controlled Component**: A component where form elements are managed by React state, ensuring synchronized updates.

## 2. What are the differences between Controlled and Uncontrolled Components?

### Controlled Component Example
```jsx
function ControlledForm() {
  const [inputValue, setInputValue] = useState('');

  const handleInputChange = (e) => {
    setInputValue(e.target.value);
  };

  return (
    <div>
      <input type="text" value={inputValue} onChange={handleInputChange} />
      <p>Input: {inputValue}</p>
    </div>
  );
}
```

### Uncontrolled Component Example
```jsx
import { useRef } from 'react';

function UncontrolledForm() {
  const inputRef = useRef();

  const handleSubmit = () => {
    console.log(inputRef.current.value);
  };

  return (
    <div>
      <input type="text" ref={inputRef} />
      <button onClick={handleSubmit}>Submit</button>
    </div>
  );
}
```

### Differences
1. **State Management**:
   - Controlled: Uses state to manage form values.
   - Uncontrolled: Directly accesses DOM values via `useRef`.
2. **Rendering**:
   - Controlled: Re-renders on state changes.
   - Uncontrolled: Minimal re-renders, as no state is involved.
3. **Event Handling**:
   - Controlled: Updates state on every change.
   - Uncontrolled: Accesses values on demand (e.g., on submit).
4. **Best Practice**:
   - Controlled: Recommended for most React forms.
   - Uncontrolled: Useful for specific scenarios (e.g., integrating with non-React libraries).

### Definition
**Controlled vs. Uncontrolled**: Controlled components use state for form values, while uncontrolled components use refs, with controlled being the standard practice.

## 3. What are the characteristics of Controlled Components?

### Characteristics
1. **State Control**: Form element values are stored in state.
2. **Event Handling**: Changes trigger event handlers (e.g., `onChange`).
3. **State Update**: Event handlers update state with new values.
4. **Rendering**: Component re-renders to reflect updated state.

### Example
```jsx
function ControlledForm() {
  const [inputValue, setInputValue] = useState('');

  const handleInputChange = (e) => {
    setInputValue(e.target.value); // Updates state
  };

  return (
    <div>
      <input type="text" value={inputValue} onChange={handleInputChange} />
      <p>Input: {inputValue}</p> // Reflects state
    </div>
  );
}
```

### Definition
**Controlled Component Characteristics**: State-controlled values, event-driven updates, and re-rendering based on state changes.

## 4. What are the advantages of using Controlled Components in React Forms?

### Advantages
1. **Single Source of Truth**: State manages all form values, ensuring consistency.
2. **Predictable Updates**: Facilitates validation, dynamic rendering, and lifecycle integration.
3. **Better Control**: Easier to manipulate and validate form data.

### Example
```jsx
function FormWithValidation() {
  const [inputValue, setInputValue] = useState('');

  const handleInputChange = (e) => {
    const value = e.target.value;
    if (value.length <= 10) {
      setInputValue(value); // Validate before updating state
    }
  };

  return (
    <div>
      <input type="text" value={inputValue} onChange={handleInputChange} />
      <p>{inputValue.length > 0 ? inputValue : 'Enter text'}</p>
    </div>
  );
}
```

### Definition
**Controlled Component Advantages**: Ensures a single source of truth, predictable updates, and better control for form handling.

## 5. How to handle Forms in React?

The preferred approach is using **controlled components**.

### Definition
**Form Handling**: Use controlled components to manage form state and updates in React.

## 6. How can you handle multiple Input Fields in a Controlled Form?

Maintain separate state variables for each input and update them via `onChange`.

### Example
```jsx
function MultiInputForm() {
  const [formData, setFormData] = useState({ name: '', email: '' });

  const handleChange = (e) => {
    const { name, value } = e.target;
    setFormData((prev) => ({ ...prev, [name]: value }));
  };

  return (
    <div>
      <input type="text" name="name" value={formData.name} onChange={handleChange} />
      <input type="email" name="email" value={formData.email} onChange={handleChange} />
      <p>Name: {formData.name}</p>
      <p>Email: {formData.email}</p>
    </div>
  );
}
```

### Definition
**Multiple Input Handling**: Use a single state object with dynamic keys updated via `onChange`.

## 7. How do you handle Form Validation in a Controlled Component?

Use conditional rendering and validate input values before updating state.

### Example
```jsx
function ValidatedForm() {
  const [inputValue, setInputValue] = useState('');
  const [error, setError] = useState('');

  const handleChange = (e) => {
    const value = e.target.value;
    if (value.length < 3) {
      setError('Input must be at least 3 characters');
    } else {
      setError('');
      setInputValue(value);
    }
  };

  return (
    <div>
      <input type="text" value={inputValue} onChange={handleChange} />
      {error && <p style={{ color: 'red' }}>{error}</p>}
      <p>Input: {inputValue}</p>
    </div>
  );
}
```

### Definition
**Form Validation**: Validate inputs in event handlers and use conditional rendering to display errors.

## 8. In what scenarios might using Uncontrolled Components be advantageous?

### Scenarios
1. **Non-React Libraries**: When integrating with libraries that directly manipulate the DOM.
2. **Simple Forms**: When state management is unnecessary (e.g., one-time form submission).

### Example
```jsx
function UncontrolledForm() {
  const inputRef = useRef();

  const handleSubmit = () => {
    console.log(inputRef.current.value);
  };

  return (
    <div>
      <input type="text" ref={inputRef} />
      <button onClick={handleSubmit}>Submit</button>
    </div>
  );
}
```

### Definition
**Uncontrolled Component Advantages**: Useful for non-React integrations or simple forms where state is unnecessary.

---

# Chapter 11: Code Splitting in React

**Code splitting** improves performance by loading only necessary code chunks on demand. Let’s cover eight questions.

## 1. What is Code Splitting in React?

Without code splitting, a React app bundles all files (JS, CSS, images) into a single request, slowing initial load times. Code splitting splits the bundle into smaller **chunks** loaded on demand.

### Example
- **Without Code Splitting**: All files load when the user visits the site.
- **With Code Splitting**: Only required files (e.g., CSS for a specific page) load initially.

### Definition
**Code Splitting**: A technique to split a JavaScript bundle into smaller chunks loaded on demand, improving performance.

## 2. How to implement Code Splitting in React?

### Steps
1. Use `React.lazy` to dynamically import components.
2. Wrap lazy-loaded components in `Suspense` with a fallback UI.
3. Configure Webpack for dynamic imports.

### Example
**Child Component** (`CodeSplitComponent.js`):
```jsx
function CodeSplitComponent() {
  return <div>Code Split Component</div>;
}

export default CodeSplitComponent;
```

**Parent Component** (`App.js`):
```jsx
import { lazy, Suspense } from 'react';

const CodeSplitComponent = lazy(() => import('./CodeSplitComponent'));

function App() {
  return (
    <div>
      <Suspense fallback={<div>Loading...</div>}>
        <CodeSplitComponent />
      </Suspense>
    </div>
  );
}

export default App;
```

**Webpack Configuration** (simplified `webpack.config.js`):
```javascript
module.exports = {
  // ... other config
  output: {
    chunkFilename: '[name].chunk.js', // Dynamic chunks
  },
};
```

### How It Works
- **Lazy Import**: `lazy(() => import('./CodeSplitComponent'))` loads the component only when needed.
- **Suspense**: Displays `Loading...` until the component is fetched.
- **Webpack**: Generates chunks visible in the browser’s Network tab.

### Definition
**Code Splitting Implementation**: Use `React.lazy` for dynamic imports, `Suspense` for loading states, and Webpack for chunk generation.

## 3. What is the role of `lazy` and `Suspense` in React?

### lazy
`React.lazy` enables dynamic (asynchronous) component imports.

### Suspense
`Suspense` displays a fallback UI while the lazy-loaded component is fetched.

### Example
```jsx
const LazyComponent = lazy(() => import('./LazyComponent'));

function App() {
  return (
    <Suspense fallback={<div>Loading...</div>}>
      <LazyComponent />
    </Suspense>
  );
}
```

### Definitions
- **lazy**: A function that dynamically imports components for code splitting.
- **Suspense**: Displays a fallback UI until the lazy-loaded component is ready.

## 4. What are the pros and cons of Code Splitting?

### Pros
1. **Faster Initial Load**: Loads only necessary code, reducing initial load time.
2. **Optimized Bandwidth**: Transfers less data, ideal for slow networks.
3. **Improved Caching**: Smaller chunks are easier to cache.
4. **Parallel Loading**: Multiple chunks load simultaneously.
5. **Easier Maintenance**: Modular code is easier to manage.

### Cons
1. **Increased Complexity**: Managing chunks complicates development.
2. **Tooling Dependency**: Requires Webpack or similar tools.
3. **Runtime Errors**: Dynamic imports may cause errors if misconfigured.
4. **More Requests**: Multiple chunks increase HTTP requests.
5. **Learning Curve**: Requires understanding dynamic imports and best practices.

### Definition
**Code Splitting Pros and Cons**: Improves performance but adds complexity and tooling dependencies.

## 5. What is the role of the `import` function in Code Splitting?

The `import()` function returns a Promise for dynamic module loading.

### Example
```jsx
const LazyComponent = lazy(() => import('./LazyComponent'));
```

### Definition
**import Function**: Enables dynamic loading of modules for code splitting.

## 6. What is the purpose of the `fallback` property in `Suspense`?

The `fallback` property displays a loading UI while the lazy-loaded component is fetched.

### Example
```jsx
<Suspense fallback={<div>Loading...</div>}>
  <LazyComponent />
</Suspense>
```

### Definition
**fallback Property**: Provides a temporary UI during dynamic component loading.

## 7. Can you dynamically load CSS files using Code Splitting in React?

Yes, CSS files can be loaded on demand with dynamic imports.

### Example
```jsx
import('./styles.css').then(() => {
  console.log('CSS loaded');
});
```

### Definition
**CSS Code Splitting**: Dynamically loads CSS files alongside components.

## 8. How do you inspect and analyze generated chunks in a React application?

Use tools like **Webpack Bundle Analyzer** to inspect chunk size and composition.

### Definition
**Chunk Analysis**: Use Webpack Bundle Analyzer to evaluate code-splitting chunks.

---

# Chapter 12: Miscellaneous Advanced React Topics

Let’s cover 10 advanced topics that often appear in senior-level interviews.

## 1. What is a Higher-Order Component (HOC) in React?

A **Higher-Order Component (HOC)** is a function that takes a component and returns an enhanced version with additional features.

### Example
**HOC** (`withLogger.js`):
```jsx
function withLogger(WrappedComponent) {
  return function EnhancedComponent(props) {
    console.log('Logging props:', props);
    return (
      <div>
        <p>I am from Logger</p>
        <WrappedComponent {...props} />
      </div>
    );
  };
}
```

**Main Component** (`HocUser.js`):
```jsx
function HocUser() {
  return <div>My Component Content</div>;
}

export default withLogger(HocUser);
```

**Usage** (`index.js`):
```jsx
import HocUser from './HocUser';

function App() {
  return <HocUser />;
}
```

**Output**:
```
Logging props: {}
<div>
  <p>I am from Logger</p>
  <div>My Component Content</div>
</div>
```

### How It Works
- **HOC**: `withLogger` adds logging and a wrapper `<p>` to `HocUser`.
- **Export**: Wraps the main component for enhanced functionality.
- **Use Case**: Error logging, authentication, or adding shared logic.

### Definition
**HOC**: A function that takes a component and returns a new component with added features.

## 2. What are the five ways to style React Components? Explain Inline Styles.

### Five Ways
1. **Inline Styles**: Apply styles directly in JSX.
2. **CSS Stylesheets**: Use external CSS files.
3. **CSS Modules**: Scoped CSS for components.
4. **Global Stylesheets**: App-wide CSS.
5. **CSS Frameworks**: Bootstrap, Material-UI, etc.

### Inline Styles Example
```jsx
function Component() {
  const styles = {
    color: 'blue',
    fontSize: '16px',
  };

  return <div style={styles}>Styled Text</div>;
}
```

### How Inline Styles Work
- Styles are defined as a JavaScript object.
- Applied via the `style` attribute in JSX.
- Suitable for small, dynamic styles but not for complex applications.

### Definition
**Styling Methods**: Inline styles, CSS stylesheets, CSS modules, global styles, and frameworks; inline styles use JavaScript objects in JSX.

## 3. What are the differences between React and React Native?

### Differences
1. **Type**:
   - React: Library for web interfaces.
   - React Native: Framework for mobile apps.
2. **Purpose**:
   - React: Builds web UIs.
   - React Native: Builds mobile UIs.
3. **Platform**:
   - React: Runs in web browsers.
   - React Native: Runs on iOS/Android.
4. **UI Components**:
   - React: Uses HTML/CSS.
   - React Native: Uses native components (e.g., `View`, `Text`).
5. **Deployment**:
   - React: Deployed as web apps.
   - React Native: Deployed via app stores.

### Definition
**React vs. React Native**: React is a web library, while React Native is a mobile framework with native components.

## 4. What is GraphQL?

**GraphQL** is a query language for APIs, allowing precise data fetching.

### Example
```graphql
query {
  user(id: 1) {
    name
    email
  }
}
```

### Relation to React
- React components use GraphQL queries to fetch data for rendering.
- Both are developed by Facebook, ensuring compatibility.

### Definition
**GraphQL**: A query language for APIs, used with React to fetch data efficiently.

## 5. What are the top three ways to achieve State Management in React? When to use each?

### Top Three Methods
1. **useState Hook**: Manages state in functional components.
2. **Context API**: Shares global data without prop drilling.
3. **Redux**: Centralized state management for large apps.

### When to Use
- **useState**: For simple, isolated state in single components.
  ```jsx
  const [count, setCount] = useState(0);
  ```
- **Context API**: For medium-sized apps to avoid prop drilling.
  ```jsx
  const MyContext = createContext();
  ```
- **Redux**: For large-scale apps with complex state.
  ```javascript
  const store = createStore(reducer);
  ```

### Definition
**State Management**: Use `useState` for simple components, Context API for medium apps, and Redux for complex, scalable apps.

## 6. How can you implement Authentication in a React Application?

Use **JWT (JSON Web Token)** authentication for secure data access.

### Steps
1. User enters credentials in the browser (React frontend).
2. Credentials are sent to the API via a POST request.
3. API validates credentials and returns a JWT token.
4. Client stores the token in local storage.
5. Token is sent in the header of subsequent requests.
6. API validates the token’s signature.
7. If valid, API returns data.
8. Client renders the data.

### Example Flow
- **Login**:
  ```jsx
  async function login(username, password) {
    const response = await fetch('/api/login', {
      method: 'POST',
      body: JSON.stringify({ username, password }),
    });
    const { token } = await response.json();
    localStorage.setItem('token', token);
  }
  ```
- **Authenticated Request**:
  ```jsx
  async function fetchData() {
    const token = localStorage.getItem('token');
    const response = await fetch('/api/data', {
      headers: { Authorization: `Bearer ${token}` },
    });
    return response.json();
  }
  ```

### Definition
**JWT Authentication**: A process where the client sends credentials, receives a JWT token, and uses it for authenticated API requests.

## 7. What is the use of React Profiler?

The **React Profiler** analyzes performance by measuring component rendering times.

### Example
```jsx
import { Profiler } from 'react';

function App() {
  function onRender(id, phase, actualDuration) {
    console.log(`ID: ${id}, Phase: ${phase}, Duration: ${actualDuration}ms`);
  }

  return (
    <Profiler id="MyComponent" onRender={onRender}>
      <MyComponent />
    </Profiler>
  );
}
```

### How It Works
- Wrap components in `<Profiler>`.
- The `onRender` callback logs timing data (start, end, duration).
- Helps identify slow-rendering components.

### Definition
**React Profiler**: A tool to measure and analyze component rendering performance.

## 8. What is the difference between Fetch and Axios for API calls in React?

### Fetch Example
```jsx
async function fetchData() {
  const response = await fetch('https://api.example.com/data');
  const data = await response.json();
  return data;
}
```

### Axios Example
```jsx
import axios from 'axios';

async function fetchData() {
  const response = await axios.get('https://api.example.com/data');
  return response.data;
}
```

**Install Axios**:
```bash
npm install axios
```

### Differences
1. **Type**:
   - Fetch: Built-in JavaScript function.
   - Axios: Third-party library.
2. **Features**:
   - Fetch: Simple, Promise-based API.
   - Axios: Supports interceptors for request/response handling (e.g., token injection).

### When to Use
- **Fetch**: For simple HTTP requests.
- **Axios**: For complex scenarios with interceptors (e.g., authentication).

### Definition
**Fetch vs. Axios**: Fetch is built-in and simple; Axios is feature-rich with interceptors for advanced use cases.

## 9. What are the popular Testing Libraries for React?

### Top Libraries
1. **Jest**: General testing framework.
2. **React Testing Library**: Tests React components’ UI behavior.
3. **Enzyme**: Manipulates and tests component output.
4. **Cypress**: End-to-end testing for apps.

### Definition
**Testing Libraries**: Jest, React Testing Library, Enzyme, and Cypress are popular for testing React applications.

## 10. How can you optimize Performance in a React Application?

### Five Techniques
1. **Memoization** (`useMemo`, `useCallback`):
   ```jsx
   const memoizedValue = useMemo(() => computeExpensiveValue(a, b), [a, b]);
   ```
2. **React Fragments**: Avoid unnecessary DOM nodes.
   ```jsx
   return (
     <>
       <h1>Title</h1>
       <p>Content</p>
     </>
   );
   ```
3. **Lazy Loading** (`React.lazy`):
   ```jsx
   const LazyComponent = lazy(() => import('./LazyComponent'));
   ```
4. **Code Splitting**: Split bundles into chunks (covered earlier).
5. **Optimize Images**: Compress images and use lazy loading.

### Definition
**Performance Optimization**: Use memoization, Fragments, lazy loading, code splitting, and image optimization to enhance React app performance.

## 11. Explain Reactive Programming with an Example

**Reactive Programming** focuses on reacting to changes and events asynchronously and declaratively.

### Example
On Google, typing in the search bar triggers real-time suggestions. The UI reacts to each keystroke, fetching and rendering data without blocking.

### Example in React
```jsx
function SearchBar() {
  const [query, setQuery] = useState('');
  const [suggestions, setSuggestions] = useState([]);

  useEffect(() => {
    async function fetchSuggestions() {
      const response = await fetch(`https://api.example.com/suggestions?q=${query}`);
      const data = await response.json();
      setSuggestions(data);
    }
    if (query) fetchSuggestions();
  }, [query]);

  return (
    <div>
      <input type="text" value={query} onChange={(e) => setQuery(e.target.value)} />
      <ul>
        {suggestions.map((s) => (
          <li>{s}</li>
        ))}
      </ul>
    </div>
  );
}
```

### Definitions
- **Reactive Programming**: Reacts to changes/events asynchronously and declaratively.
- **Declarative**: Specifies what to achieve (e.g., JSX).
- **Asynchronous**: Non-blocking operations (e.g., API calls).

## 12. In how many ways can we implement Reactive Programming in React?

### Methods
1. **State and Props**: React to state/prop changes.
2. **React Hooks**: `useState`, `useEffect` for reactive updates.
3. **Event Handling**: `onChange`, `onClick` for user interactions.
4. **Context API**: React to global state changes.
5. **Redux**: React to centralized state updates.
6. **Component Lifecycle Methods**: Handle changes in class components.
7. **Async/Await**: Handle asynchronous data fetching.
8. **RxJS/Observables**: Advanced reactive streams (common in Angular but usable in React).

### Example (Hooks)
```jsx
function Counter() {
  const [count, setCount] = useState(0);

  return (
    <div>
      <p>Count: {count}</p>
      <button onClick={() => setCount(count + 1)}>Increment</button>
    </div>
  );
}
```

### Definition
**Reactive Programming in React**: Use state/props, Hooks, event handling, Context, Redux, lifecycle methods, async/await, or RxJS to react to changes.

## 13. How to pass Data from a Child Component to a Parent Component in React?

Use **callback functions** to pass data from child to parent.

### Example
**Parent Component**:
```jsx
function Parent() {
  const handleData = (data) => {
    console.log('Data from child:', data);
  };

  return <Child sendData={handleData} />;
}
```

**Child Component**:
```jsx
function Child({ sendData }) {
  const handleClick = () => {
    sendData('Hello from Child');
  };

  return <button onClick={handleClick}>Send Data</button>;
}
```

### How It Works
1. Define a callback function (`handleData`) in the parent.
2. Pass the callback as a prop (`sendData`) to the child.
3. Child invokes the callback with data (`sendData('Hello from Child')`).
4. Parent processes the data (e.g., logs it).

### Definition
**Child-to-Parent Data**: Pass a callback function from parent to child, which the child invokes to send data back.

---

# Final Interview Tips
- **Be Technical**: Use terms like “DOM” instead of “UI” to sound professional.
- **Practice Code**: Run the provided snippets to reinforce concepts.
- **Stay Confident**: Rejections are normal—keep applying and learning.
- **Revise Key Points**: Focus on 3–4 points per answer for clarity.
- **Share Success**: Comment with your job offer stories to inspire others!

Congratulations on completing this comprehensive React interview guide! You’re now equipped to tackle any React interview with confidence. Keep practicing, never give up, and best of luck in your career!