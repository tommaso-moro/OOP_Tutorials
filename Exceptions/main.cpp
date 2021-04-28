#include<iostream>
#include<exception>

class AnyError : public std::exception {
protected:
    std::string explanation;

public:
    AnyError(const std::string& msg) noexcept : \
    explanation(msg) {};

    const char* what() const noexcept override {
        return explanation.c_str();
    }
};

class InvalidEmailAddress : public AnyError {
public:
    InvalidEmailAddress(const std::string& msg, const std::string emailAddress) noexcept : AnyError(msg) {
        explanation = explanation + ": " + emailAddress + " is not a valid email address.";
    };
};

void createEmailAddress(const std::string emailAddress) {
    if (!(emailAddress.find('@') != std::string::npos)) {
        throw InvalidEmailAddress("Error creating email address", emailAddress);
    } else {
        std::cout << "Email address created successfully!" << std::endl;
    }
}


int main() {
    try {
        createEmailAddress("tommy@gmail.com");
    } catch (const InvalidEmailAddress& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        createEmailAddress("tommygmail.com");
    } catch (const InvalidEmailAddress& e) {
        std::cout << e.what() << std::endl;
    }
}