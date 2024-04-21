#include <iostream>
#include <fstream>
#include <string>
#include <map>

class PasswordManager {
private:
    std::map<std::string, std::string> credentials;
    std::string filename;

public:
    PasswordManager(const std::string& filename) : filename(filename) {}

    void addCredential(const std::string& service, const std::string& username, const std::string& password) {
        credentials[service] = username + ":" + password;
    }

    void saveToFile() {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const auto& [service, credential] : credentials) {
                file << service << "," << credential << std::endl;
            }
            file.close();
        } else {
            std::cerr << "Unable to open file for writing!" << std::endl;
        }
    }

    void loadFromFile() {
        std::ifstream file(filename);
        if (file.is_open()) {
            credentials.clear();
            std::string line;
            while (std::getline(file, line)) {
                size_t pos = line.find(",");
                if (pos != std::string::npos) {
                    std::string service = line.substr(0, pos);
                    std::string credential = line.substr(pos + 1);
                    credentials[service] = credential;
                }
            }
            file.close();
        } else {
            std::cerr << "Unable to open file for reading!" << std::endl;
        }
    }

    std::string getCredential(const std::string& service) {
        if (credentials.find(service) != credentials.end()) {
            return credentials[service];
        }
        return "Service not found!";
    }
};

int main() {
    PasswordManager manager("credentials.txt");

    // Example usage
    manager.addCredential("gmail", "user@example.com", "password123");
    manager.addCredential("facebook", "user@example.com", "securePassword");
    manager.saveToFile();

    manager.loadFromFile();
    std::cout << manager.getCredential("gmail") << std::endl;

    return 0;
}
