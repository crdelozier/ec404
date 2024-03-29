#include <iostream>
#include <vector>
#include <algorithm>

class MemoryAddress {
public:
    MemoryAddress(void* address, const std::string& identifier) : address(address), identifier(identifier) {}

    void* getAddress() const {
        return address;
    }

    std::string getIdentifier() const {
        return identifier;
    }

private:
    void* address;
    std::string identifier;
};

class MemoryAddressList {
private:
  void sortAddresses() {
    std::sort(addresses.begin(), addresses.end(), [](const MemoryAddress& a, const MemoryAddress& b) {
	return a.getAddress() < b.getAddress();
      });
  }
 
public:
    void addAddress(void* address, const std::string& identifier) {
        addresses.push_back(MemoryAddress(address, identifier));
	sortAddresses();
    }

    void printAddresses() const {
        for (const auto& address : addresses) {
            std::cout << "Identifier: " << address.getIdentifier() << ", Address: " << address.getAddress() << std::endl;
        }
    }

private:
    std::vector<MemoryAddress> addresses;
};
