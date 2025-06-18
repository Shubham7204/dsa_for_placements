# TCP/IP Protocol Suite: Structured Notes

## Introduction to Communication and Protocols

- **Human Communication Analogy**:
    - For two people to communicate successfully, they must share a common language so both can understand each other.
    - Similarly, in computer networks, computers need a common message format to communicate effectively.
- **Key Requirements for Computer Communication**:
    - Computers must know:
        - How long the message is.
        - Which part of the message is the actual data.
        - Which part contains the sender’s and receiver’s addresses.
    - This information ensures successful communication between computers.
- **Challenges**:
    - If one computer uses ASCII and another uses Unicode, communication fails unless translations are performed back and forth.
- **Protocols**:
    - Protocols are the agreed-upon set of ground rules that make communication possible in computer networks.
    - **TCP/IP**: A set of protocols that supports network communication.

## What is a Network and Communication?

- **Network**:
    - In its most basic form, a network consists of two computers connected via a LAN cable, sharing data with the help of network interface cards (NICs).
- **Communication**:
    - The process of sending messages from one place to another through a wired or wireless medium.
    - Messages can include files, voice conversations, streaming videos, or anything communicable in digital form.
- **Message Transmission**:
    - Messages are not sent as a single unit.
    - They are broken into small data units, transmitted through the network, and restored at the receiver into the original message.

## TCP/IP Protocol Suite Overview

- **Role of TCP and IP**:
    - **TCP (Transmission Control Protocol)**:
        - Breaks messages into smaller data units called **segments**.
        - Hands segments to the IP layer.
        - At the receiver, the TCP module combines segments to form the original message.
        - ![](../pics/Pasted%20image%2020250618214513.png)
    - **IP (Internet Protocol)**:
        - Deals with routing segments through networks to their final destination.
- **Alternative to TCP: UDP**:
    - **UDP (User Datagram Protocol)**:
        - Part of the TCP/IP protocol suite.
        - Less reliable but generally faster than TCP.
    - **TCP vs. UDP**:
        - **TCP**: Highly reliable, ensures delivery, but slower.
        - **UDP**: Less reliable, no guaranteed delivery, but faster.
- **Why Called TCP/IP?**:
    - Despite including numerous protocols, the suite is referred to as TCP/IP due to heavy dependence on TCP and historical reasons.
- **TCP/IP vs. OSI Model**:
    - **TCP/IP**: A practical network model designed to support communication across computers from different manufacturers, developed to meet the needs of the original Internet design.
    - **OSI (Open System Interconnection) Model**: Primarily used for research purposes.
- **TCP/IP Structure**:
    - Consists of numerous protocols bundled at different layers, not just TCP and IP.
    - **Layers and Data Units**:
        - **Application Layer**: Application message.
        - **Transport Layer**: TCP segment (for TCP) or UDP datagram (for UDP).
        - **Network Layer**: IP packet.
        - **Data Link Layer**: Ethernet frame.
        - **Physical Layer**: Signals (electrical, light, or radio).
        - ![](../pics/Pasted%20image%2020250618214656.png)
        - ![](../pics/Pasted%20image%2020250618214714.png)
## Encapsulation and Decapsulation Process

- **Encapsulation (Sender Side)**:
    - The topmost layer, the application layer, generates a message.
    - The message is passed to lower layers at the sending node.
    - Each layer encapsulates the message from the layer above by adding its own header, making the data unit larger as it moves down the chain.
- **Decapsulation (Receiver Side)**:
    - At the receiving node, each peer layer removes its corresponding header and passes the remainder upward, layer by layer, until the message reaches the application layer.
    - ![](../pics/Pasted%20image%2020250618214756.png)

## Detailed Explanation of TCP/IP Layers

### 1. Physical Layer

- **Function**:
    - The place where actual communication takes place.
    - Converts digitally represented messages (sequence of zeros and ones) into signals and transmits them over the local media.
- **Types of Signals**:
    - **Electrical**: For copper cables (e.g., LAN cables).
    - **Light**: For optical fiber.
    - **Radio**: For air or vacuum (wireless).
- **Dependence on Media**:
    - The signal generated depends on the type of media used to connect the two devices.
- **Common Protocol**:
    - **Ethernet**: Specifies the types of cables for data transmission:
        - **Twisted pair cable**, **coaxial cable**, or **fiber optic cable** for standard Ethernet.
        - **Twisted pair cable** or **fiber optic cable** for Fast Ethernet or Gigabit Ethernet.

### 2. Data Link Layer

- **Data Unit**: **Ethernet frame**.
- **Sublayers**:
    - **Medium Access Control (MAC) Sublayer**:
        - **Data Encapsulation**:
            - Adds a header (containing sender and receiver MAC addresses) and a trailer (4 bytes of error-checking data) to the IP packet from the network layer.
            - ![](../pics/Pasted%20image%2020250618222818.png)
        - **MAC Address**:
            - A unique 6-byte address embedded in the network interface card (NIC) by the manufacturer.
        - **Accessing the Media**:
            - Uses **Carrier Sense Multiple Access with Collision Detection (CSMA/CD)**:
                - Each computer listens to the cable before sending data.
                - If the network is clear, the computer transmits.
                - If another computer is transmitting, the sender waits and retries when the line is clear.
                - Collisions occur when two computers transmit simultaneously.
                - After a collision, each computer stops, waits a random amount of time, and retransmits.
                - Collisions are normal, and the delay caused is minimal, not significantly affecting transmission speed.
                - ![](../pics/Pasted%20image%2020250618222843.png)
    - **Logical Link Control (LLC) Sublayer**:
        - **Flow Control**:
            - Restricts the amount of data the sender can send to avoid overwhelming the receiver, which has limited processing speed and memory.
            - The receiver informs the sender to slow down before limits are exceeded to prevent data loss.
            - In the data link layer, flow control restricts the number of frames sent.
            - ![](../pics/Pasted%20image%2020250618222929.png)
        - **Error Control**:
            - Involves error detection and retransmission.
            - Uses error-checking bytes in the frame’s trailer for error detection.
            - Employs **Automatic Repeat Request (ARQ)**:
                - The receiver sends an acknowledgment when a frame is received.
                - If no acknowledgment is received (due to a lost or damaged frame), the sender retransmits the frame.
                - ![](../pics/Pasted%20image%2020250618223015.png)
        - **Packet Resizing**:
            - Resizes IP packets from the network layer to fit into data link layer frames, if needed.
        - **Note**: LLC services (flow control, error control, resizing) are often bypassed, as the transport layer provides similar functionality.

### 3. Network Layer

- **Data Unit**: **IP packet**.
- **Implementation**:
    - Implemented as software within the computer’s operating system.
    - ![](../pics/Pasted%20image%2020250618223144.png)
- **Functions**:
    - **Logical Addressing**:
        - The transport layer passes TCP segments or UDP datagrams to the network layer.
        - The network layer adds sender and receiver **IP addresses** to form an IP packet.
        - Every computer in a network has a unique IP address to ensure packets reach the correct destination across different networks.
    - **Routing**:
        - Moves IP packets from source to destination across networks using routers.
        - **Within a Network**:
            - Routing is not needed.
            - ![](../pics/Pasted%20image%2020250618223246.png)
            - The **Address Resolution Protocol (ARP)** takes the destination IP address from the IP packet and returns the MAC address of the destination computer.
            - The MAC address is used to create an Ethernet frame, which is delivered directly to the destination.
        - **Across Networks**:
            - When sending to a node outside the network (e.g., to the Internet), the network layer uses routers.
            - Example: Computer A (Network 1) sends data to Computer B (Network 2) via a router:
                - The sender uses the router’s MAC address as the destination MAC address in the Ethernet frame.
                - The router receives the frame, extracts the IP packet, and forwards it to its network layer.
                - The network layer detects a mismatch in the destination IP address and sends the packet to the data link layer, updating the destination MAC address to Computer B’s MAC address (obtained via ARP).
                - The Ethernet frame is delivered to Computer B.
            - **Note**: The destination IP address remains unchanged, but the MAC address changes at each hop.
            - ![](../pics/Pasted%20image%2020250618223456.png)
    - **Path Determination**:
        - Chooses the best possible path for data delivery from source to destination.
        - Uses protocols like:
            - **Open Shortest Path First (OSPF)**.
            - **Border Gateway Protocol (BGP)**.
            - **Intermediate System to Intermediate System (IS-IS)**.
- **Protocol**:
    - **IP**: The single standard protocol for this layer, unreliable (no delivery guarantee or error checking, handled by the transport layer).
- **Devices**:
    - Routers and gateways, sometimes called **Layer 3 switches**, operate at this layer.
    - ![](../pics/Pasted%20image%2020250618223548.png)

### 4. Transport Layer

- **Data Unit**: **TCP segment** (for TCP) or **UDP datagram** (for UDP).
- **Implementation**:
    - Implemented as software within the computer’s operating system.
- **Function**:
    - Receives messages from the application layer and selects either **TCP** or **UDP** for transmission.
    - ![](../pics/Pasted%20image%2020250618223740.png)
- **TCP (Transmission Control Protocol)**:
    - **Segmentation**:
        - Divides large messages into smaller pieces and adds a header to form TCP segments.
    - **Connection-Oriented**:
        - Establishes a connection before data transfer via a **three-way handshake**:
            1. The sender (client) sends a packet to the receiver (server) requesting a connection.
            2. The server sends an acknowledgment to the client.
            3. The client acknowledges the server, completing the connection establishment.
            4. ![](../pics/Pasted%20image%2020250618223812.png)
    - **Data Transfer Features**:
        - **Error-Free Data Transfer**:
            - Uses a **checksum** field in the TCP segment.
            - The sender calculates and includes a checksum value.
            - The receiver recalculates the checksum; if it doesn’t match, the segment is discarded, and no acknowledgment is sent, triggering retransmission.
            - When the checksum matches, the segment is accepted, ensuring error-free transfer.
            - ![](../pics/Pasted%20image%2020250618223915.png)
        - **Ordered Data Transfer**:
            - Adds sequence numbers to TCP segments.
            - The receiver uses sequence numbers to reconstruct the message in the correct order.
            - ![](../pics/Pasted%20image%2020250618223935.png)
        - **Retransmission of Lost Segments**:
            - The receiver sends an acknowledgment for each TCP segment received.
            - If no acknowledgment is received, the sender retransmits the segment.
        - **Discarding Duplicate Segments**:
            - If the receiver gets duplicate segments (e.g., due to retransmission), sequence numbers identify duplicates, which are discarded.
        - **Congestion Throttling (Flow Control)**:
            - Aims to send segments as fast as possible without loss.
            - Sets a timer for each segment; if acknowledged before the timer expires, transmission speed increases.
            - If segments are unacknowledged, TCP retransmits them and slows the transmission rate to manage congestion.
    - **Connection Termination**:
        - Uses a **four-way handshake**:
            1. One endpoint sends a finish message.
            2. The other endpoint acknowledges.
            3. The process is repeated in reverse to terminate the connection.
            4. ![](../pics/Pasted%20image%2020250618224137.png)
- **UDP (User Datagram Protocol)**:
    - Does not support segmentation; applications must send messages small enough to fit into one UDP datagram.
    - **Unreliable**:
        - No guarantee that datagrams will be received or in the correct order.
        - Lacks error checking and correction, making it faster.
    - Suitable for applications like **DNS**, **DHCP**, **SNMP**, **RIP**, and streaming videos, where speed is prioritized over reliability.
- **Summary**:
    - TCP is reliable, slower, and ensures in-order delivery.
    - UDP is faster, less reliable, and suited for applications where minor data loss is acceptable.

### 5. Application Layer

- **Function**:
    - Used by user applications (e.g., Google Chrome, Firefox, Microsoft Outlook) to pass messages from one computer to another in a network.
    - User applications do not reside in this layer but use application layer protocols to perform their activities.
    - ![](../pics/Pasted%20image%2020250618224235.png)
- **Examples**:
    - Web browsers use **HTTP** or **HTTPS** for web surfing.
    - Email programs use **POP3 (Post Office Protocol version 3)** or **SMTP (Simple Mail Transfer Protocol)** for email transfer.
- **Role**:
    - Provides means to access information on the Internet.
- **Protocols**:
    - **Domain Name System (DNS)**: Translates IP addresses to domain names and vice versa.
    - **Dynamic Host Configuration Protocol (DHCP)**: Automatically assigns IP addresses to computers in a network.
    - **File Transfer Protocol (FTP)**: Transfers files on the Internet.
    - **Hypertext Transfer Protocol (HTTP/HTTPS)**: Sends and receives web pages.
    - **Internet Message Access Protocol (IMAP)**: Manages email messages on the Internet.
    - **Internet Relay Chat (IRC)**: Enables Internet chat.
    - **Post Office Protocol version 3 (POP3)**: Retrieves emails from remote servers.
    - **Simple Mail Transfer Protocol (SMTP)**: Transfers email messages on the Internet.
- **Implementation**:
    - Implemented as software within the computer’s operating system.

## Summary of TCP/IP Layers

1. **Physical Layer**: Converts binary sequences into signals (electrical, light, or radio) for transmission over media (e.g., Ethernet cables).
2. **Data Link Layer**: Handles framing (Ethernet frames), media access (CSMA/CD), flow control, and error control via MAC and LLC sublayers.
3. **Network Layer**: Manages logical addressing (IP addresses), routing, and path determination using IP.
4. **Transport Layer**: Provides reliable (TCP) or fast (UDP) data transfer with segmentation, error control, and flow control.
5. **Application Layer**: Enables user applications to access network services via protocols like HTTP, DNS, FTP, and SMTP.


# OSI Model: Structured Notes

## Introduction to the OSI Model

- **Purpose**:
    - The OSI (Open System Interconnection) Model defines how data is transferred from one computer to another in a computer network.
- **Basic Network**:
    - In its simplest form, a network consists of two computers connected via a LAN cable and connectors, sharing data with the help of network interface cards (NICs).
- **Challenge of Heterogeneous Systems**:
    - If one computer runs Microsoft Windows and another runs macOS, communication requires a standardized framework to ensure compatibility.
- **OSI Model Overview**:
    - Introduced by the **International Organization for Standardization (ISO)** in 1984.
    - Consists of **7 layers**: Application, Presentation, Session, Transport, Network, Data Link, and Physical.
    - Each layer is a package of protocols that facilitates communication between computers or networks of different architectures.
    - ![](../pics/Pasted%20image%2020250618231803.png)

## What Are Layers?

- **Layer Definition**:
    - Each layer contains a set of protocols, not the applications themselves (e.g., Chrome, Firefox).
    - Protocols enable applications to function correctly in a network or the Internet.

## Detailed Explanation of OSI Layers

### 1. Application Layer

- **Function**:
    - Used by **network applications** (e.g., Google Chrome, Firefox, Outlook, Skype) to access network services.
    - Network applications do not reside in this layer but rely on application layer protocols to perform their tasks.
- **Examples of Network Applications**:
    - Web browsers (using **HTTP** or **HTTPS** for web surfing).
    - Email clients like Outlook (using **SMTP** for email transfer).
- **Protocols**:
    - Provide the basis for various network services:
        - **File Transfer**: **FTP** (File Transfer Protocol).
        - **Web Surfing**: **HTTP** or **HTTPS** (Hypertext Transfer Protocol).
        - **Emails**: **SMTP** (Simple Mail Transfer Protocol).
        - **Virtual Terminals**: **Telnet**.
    - Dozens of protocols collectively form the application layer.
- **Role**:
    - Provides services for network applications to perform user activities (e.g., file transfer, web surfing, email).

### 2. Presentation Layer

- **Function**:
    - Receives data from the application layer (in the form of characters and numbers) and prepares it for transmission.
- **Key Functions**:
    - **Translation**:
        - Converts data into a machine-understandable binary format (e.g., ASCII to EBCDIC).
    - **Data Compression**:
        - Reduces the number of bits used to represent data (lossy or lossless).
        - Decreases file size, enabling faster transmission.
        - ![](../pics/Pasted%20image%2020250618232725.png)
        - Critical for real-time video and audio streaming.
    - **Encryption/Decryption**:
        - Encrypts data at the sender for security and decrypts it at the receiver.
        - Uses **SSL (Secure Sockets Layer)** protocol to enhance the security of sensitive data.
- **Summary**:
    - Performs translation, compression, and encryption/decryption to ensure data is secure, compact, and in the correct format.

### 3. Session Layer

- **Analogy**:
    - Like hiring helpers for a party to set up, assist, clean, and close, the session layer manages communication sessions.
- **Functions**:
    - **Session Management**:
        - Sets up and manages connections, enables sending and receiving of data, and terminates sessions.
        - Tracks data packets to ensure they are correctly assigned to files (e.g., text or image files for a web page).
        - Example: A web browser opens separate sessions to download text and image files from a web server.
        - ![](../pics/Pasted%20image%2020250619002201.png)
    - **Authentication**:
        - Verifies user identity using a username and password before establishing a session.
    - **Authorization**:
        - Determines if a user has permission to access a file or resource.
        - If unauthorized, the user receives a message like “you are not authorized to access this page.”
- **Helpers**:
    - Uses **APIs (Application Programming Interfaces)** like **NetBIOS (Network Basic Input/Output System)** to allow applications on different computers to communicate.
- **Summary**:
    - Manages sessions, performs authentication, and checks authorization.

### 4. Transport Layer

- **Function**:
    - Controls the reliability of communication through **segmentation**, **flow control**, and **error control**.
- **Segmentation**:
    - Divides data from the session layer into smaller units called **segments**.
    - Each segment includes:
        - **Source and destination port numbers**: Direct segments to the correct application.
        - **Sequence numbers**: Reassemble segments in the correct order at the receiver.
        - ![](../pics/Pasted%20image%2020250619002317.png)
- **Flow Control**:
    - Regulates the amount of data transmitted to prevent overwhelming the receiver.
    - Example: If a server transmits at 50 Mbps but a mobile device can process only 10 Mbps, the transport layer instructs the server to adjust to 10 Mbps to avoid data loss or requests an increase if the rate is too low (e.g., 5 Mbps).
    - ![](../pics/Pasted%20image%2020250619002400.png)
- **Error Control**:
    - Detects and retransmits lost or corrupted segments using **automatic repeat request (ARQ)** schemes.
    - Adds a **checksum** to each segment to identify corrupted data.
    - ![](../pics/Pasted%20image%2020250619002433.png)
- **Protocols**:
    - **TCP (Transmission Control Protocol)**:
        - Provides **connection-oriented** transmission.
        - Reliable, ensures data delivery with feedback for retransmission of lost data.
        - Used for applications requiring full data delivery (e.g., web browsing, email, FTP).
    - **UDP (User Datagram Protocol)**:
        - Provides **connectionless** transmission.
        - Faster but unreliable, no feedback on delivery.
        - Used for applications where speed is critical and minor data loss is acceptable (e.g., online streaming, games, VoIP, TFTP, DNS).
- **Summary**:
    - Handles segmentation, flow control, error control, and supports connection-oriented (TCP) and connectionless (UDP) transmission.

### 5. Network Layer

- **Function**:
    - Transmits data segments (received from the transport layer) from one computer to another across different networks.
- **Data Unit**: **Packet**.
- **Key Functions**:
    - **Logical Addressing**:
        - Assigns sender and receiver **IP addresses** to each segment to form an IP packet.
        - Ensures packets reach the correct destination using unique IP addresses.
    - **Routing**:
        - Moves packets from source to destination based on **IPv4** or **IPv6** logical address formats.
        - Example: A packet from a Facebook server to Computer B (in Network 2) uses IP addresses and a subnet mask (e.g., 255.255.255.0) to route the packet to Network 2 and then to Computer B.
        - ![](../pics/Pasted%20image%2020250619003352.png)
    - **Path Determination**:
        - Selects the best path for data delivery using protocols like:
            - **Open Shortest Path First (OSPF)**.
            - **Border Gateway Protocol (BGP)**.
            - **Intermediate System to Intermediate System (IS-IS)**.
- **Devices**:
    - **Routers** operate at this layer.
- **Summary**:
    - Manages logical addressing, routing, and path determination for inter-network communication.

### 6. Data Link Layer

- **Function**:
    - Transfers data from one computer to another via a local medium (e.g., copper wire, optical fiber, air for radio signals).
- **Data Unit**: **Frame**.
- **Addressing**:
    - **Physical Addressing**: Assigns sender and receiver **MAC addresses** to each packet to form a frame.
    - **MAC Address**: A 12-digit alphanumeric number embedded in the NIC by the manufacturer.
    - ![](../pics/Pasted%20image%2020250619003651.png)
- **Implementation**:
    - Embedded as software in the NIC.
- **Key Functions**:
    - **Media Access**:
        - Allows upper layers to access the medium using **framing**.
        - Controls data placement and retrieval using **Media Access Control (MAC)** and **error detection**.
        - Uses **Carrier Sense Multiple Access (CSMA)** to avoid collisions when multiple devices share the same medium.
        - Adds error-detection bits to the frame’s tail to identify errors caused by media limitations.
        - ![](../pics/Pasted%20image%2020250619004129.png)
    - **Example Scenario**:
        - A desktop (connected to Router R1 via Ethernet) sends data to a laptop (connected to Router R2 via wireless).
        - The data link layer:
            - Encapsulates an IP packet into an **Ethernet frame** for the desktop-to-R1 link.
            - Router R1 decapsulates the frame, re-encapsulates it for the satellite link to Router R2.
            - Router R2 decapsulates and re-encapsulates it into a **wireless frame** for the laptop.
        - The laptop decapsulates the frame and forwards the IP packet to higher layers.
        - ![](../pics/Pasted%20image%2020250619003927.png)
- **Summary**:
    - Provides media access, controls data transmission, and performs error detection using framing and MAC.

### 7. Physical Layer

- **Function**:
    - Converts binary data (sequence of 0s and 1s) from the data link layer into signals for transmission over the local medium.
- **Types of Signals**:
    - **Electrical**: For copper cables (e.g., LAN cables).
    - **Light**: For optical fiber.
    - **Radio**: For wireless media (air).
- **Operation**:
    - At the sender: Converts frames into signals.
    - At the receiver: Converts signals back into bits and passes them as a frame to the data link layer.
- **Summary**:
    - Handles the physical transmission of data by converting binary sequences into appropriate signals.
    - ![](../pics/Pasted%20image%2020250619004242.png)

## Encapsulation and Decapsulation Process

- **Encapsulation (Sender Side)**:
    - Each layer adds headers (and sometimes trailers) to the data from the layer above:
        - **Application Layer**: Generates the message.
        - **Presentation Layer**: Translates, compresses, and encrypts the message.
        - **Session Layer**: Adds session management information.
        - **Transport Layer**: Segments data and adds port/sequence numbers.
        - **Network Layer**: Adds IP addresses to form packets.
        - **Data Link Layer**: Adds MAC addresses and error-detection bits to form frames.
        - **Physical Layer**: Converts frames into signals.
- **Decapsulation (Receiver Side)**:
    - Each layer removes its header (and trailer, if applicable) and passes the data to the layer above until the original message reaches the application layer, where it is displayed (e.g., on a web browser).

## Summary of OSI Layers

1. **Application Layer**: Provides protocols (e.g., HTTP, FTP, SMTP) for network applications to perform user tasks.
2. **Presentation Layer**: Handles translation (e.g., ASCII to EBCDIC), data compression, and encryption/decryption (using SSL).
3. **Session Layer**: Manages sessions, performs authentication, and checks authorization using APIs like NetBIOS.
4. **Transport Layer**: Ensures reliable communication via segmentation, flow control, and error control using TCP (connection-oriented) or UDP (connectionless).
5. **Network Layer**: Manages logical addressing (IP), routing, and path determination for inter-network communication.
6. **Data Link Layer**: Provides media access, framing, and error detection using MAC addresses and CSMA.
7. **Physical Layer**: Converts binary data into signals (electrical, light, or radio) for transmission over the medium.

## Conclusion

- The OSI Model’s seven layers work together to enable seamless data transfer between computers, even across different architectures, ensuring the smooth functioning of the Internet.