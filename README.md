#  LAN Chat Application (C - Winsock)
A simple **LAN-based chatting application** built in **C** using **Socket Programming (Winsock API)** on Windows.  
It allows **two computers on the same network** to communicate in real-time — one acts as the **server**, and the other as the **client**.

##  How It Works

The application has **two parts**:

1. **Server (`server.c`)**
   - Listens for client connections.
   - Sends and receives messages.

2. **Client (`client.c`)**
   - Connects to the server using its IP address.
   - Exchanges messages in real-time.

---

##  Setup & Run

### Clone the repository
```bash
git clone https://github.com/yourusername/lan-chat-app.git
cd lan-chat-app
```

### Compile both file using MinGW or any C compiler:
```bash
gcc server.c -o server -lws2_32
gcc client.c -o client -lws2_32
```

### Run the server
```bash
server.exe
 ```

### Run the Client in another pc with same LAN network
```bash
client.exe
```

---

<p align="center">
  <strong>Author:</strong> <br>Prabin Karki <br>
   BE in Electronics, Communication and Information Technology
</p>
