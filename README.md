Experiment 1: Basic Hardware Components and Networking Commands
1. AIM
To study and identify the fundamental hardware components used in computer networks, including NIC, Switch, Router, and UTP CAT6 Cable, and understand the working of commonly used networking commands for network configuration, connectivity testing, and troubleshooting.

2. THEORY
A. Networking Hardware Components
1. Network Interface Card (NIC)

A NIC is a hardware component that allows a computer or device to connect to a network.
It can provide wired or wireless connectivity.
Every NIC has a unique 48-bit MAC address used for identification at the Data Link Layer.
2. Switch

A switch is a networking device that connects multiple devices within a Local Area Network (LAN).
It operates mainly at Layer 2 (Data Link Layer) of the OSI model.
It uses MAC addresses to identify devices and forward Ethernet frames to the appropriate ports.
3. Router

A router connects two or more different networks and enables communication between them.
It operates at Layer 3 (Network Layer) of the OSI model.
It uses IP addresses and routing tables to forward packets towards their destinations.
4. UTP CAT6 Cable

Unshielded Twisted Pair (UTP) CAT6 is a commonly used Ethernet cable for wired networking.
It consists of four pairs of twisted copper wires.
Twisting helps reduce electromagnetic interference and crosstalk.
CAT6 supports data transmission speeds up to 10 Gbps over shorter distances, typically up to 55 metres.
B. Common Networking Commands
1. ping

Used to check whether a destination device is reachable over an IP network.
It uses ICMP Echo Request and Echo Reply messages.
It also provides information about packet loss and round-trip time.
2. tracert / traceroute

Used to identify the path taken by packets to reach a destination.
It displays the intermediate routers, also known as hops.
It uses the Time-To-Live (TTL) field in IP packets.
3. ipconfig / ifconfig

Used to display the network configuration of a system.
It provides information such as IP address, subnet mask, and default gateway.
ipconfig is commonly used in Windows, while ifconfig is used in Linux-based systems.
4. netstat -an

Displays active network connections and listening ports.
It provides information about TCP and UDP connections.
It helps in examining the network activity of a system.
5. nslookup

Used to obtain information about domain names and their corresponding IP addresses.
It communicates with DNS servers to perform name resolution.
It helps verify DNS configuration and domain accessibility.
6. arp -a

Displays the ARP cache maintained by the system.
It shows the mapping between IPv4 addresses and MAC addresses.
It helps understand how devices are identified within a local network.
3. EXPLANATION / PROCEDURE
Identified the major networking hardware components, including NIC, Switch, Router, and UTP CAT6 Cable.
Studied the functions and working principles of each networking device.
Opened the Command Prompt to execute basic networking commands.
Used ping 127.0.0.1 to check the local TCP/IP protocol stack.
Executed ipconfig /all to view the IP configuration and MAC address of the system.
Used ping 8.8.8.8 to test network connectivity.
Executed tracert google.com to observe the route followed by packets.
Used netstat -ano to examine active connections and listening ports.
Executed arp -a to view IP-to-MAC address mappings.
Used nslookup google.com to understand DNS name resolution.
4. IMPORTANT COMMANDS SUMMARY
Command	Purpose
ping	Tests network connectivity
tracert	Displays the route to a destination
ipconfig	Displays IP configuration
netstat -an	Displays active connections
nslookup	Performs DNS lookup
arp -a	Displays ARP cache
5. CONCLUSION
Studied the basic hardware components of computer networking and understood their roles in establishing communication between devices. Also explored commonly used networking commands for checking connectivity, viewing IP configurations, tracing network routes, inspecting active connections, and understanding DNS and ARP operations.
