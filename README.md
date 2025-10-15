## 🖥️ How It Works

The application has **two parts**:

1. **Server (`server.c`)**
   - Listens for client connections.
   - Sends and receives messages.

2. **Client (`client.c`)**
   - Connects to the server using its IP address.
   - Exchanges messages in real-time.

---

## 🚀 Setup & Run

### 🧱 Step 1: Clone the repository
```bash
git clone https://github.com/yourusername/lan-chat-app.git
cd lan-chat-app

#compile both file using MinGW or any C compiler:
gcc server.c -o server -lws2_32
gcc client.c -o client -lws2_32


#run the server
server.exe

#Run the Client in another pc with same LAN network
client.exe
```

Author
  Prabin Karki
  BE in Electronics, Communication and Information Technology
