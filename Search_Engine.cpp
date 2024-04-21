#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

std::unordered_map<std::string, std::vector<std::string>> index;

void addPage(const std::string& page, const std::vector<std::string>& keywords) {
    for (const auto& keyword : keywords) {
        index[keyword].push_back(page);
    }
}

void search(const std::string& keyword) {
    if (index.find(keyword) != index.end()) {
        std::cout << "Pages containing '" << keyword << "':" << std::endl;
        for (const auto& page : index[keyword]) {
            std::cout << "- " << page << std::endl;
        }
    } else {
        std::cout << "No pages found containing '" << keyword << "'." << std::endl;
    }
}

int main() {
    addPage("example.com/page1", {"apple", "banana", "cherry"});
    addPage("example.com/page2", {"banana", "orange"});
    addPage("example.com/page3", {"apple", "grape"});

    std::string keyword;
    std::cout << "Enter keyword to search: ";
    std::cin >> keyword;

    search(keyword);

    return 0;
}
