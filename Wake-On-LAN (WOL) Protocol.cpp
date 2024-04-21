#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

void sendMagicPacket(const std::string& macAddress) {
    std::vector<unsigned char> packet(102);
    std::stringstream ss(macAddress);
    for (int i = 0; i < 6; ++i) {
        unsigned int byte;
        ss >> std::hex >> byte;
        packet[i] = byte;
    }
    for (int i = 6; i < 102; ++i) {
        packet[i] = 0xFF;
    }

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        std::cerr << "Socket creation failed" << std::endl;
        return;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9);
    inet_pton(AF_INET, "255.255.255.255", &addr.sin_addr);

    if (sendto(sockfd, packet.data(), packet.size(), 0, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        std::cerr << "Sendto failed" << std::endl;
    }

    close(sockfd);
    std::cout << "Magic packet sent successfully!" << std::endl;
}

int main() {
    std::string macAddress;
    std::cout << "Enter MAC address (format XX:XX:XX:XX:XX:XX): ";
    std::cin >> macAddress;
    sendMagicPacket(macAddress);
    return 0;
}
