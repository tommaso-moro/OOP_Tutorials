#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>

template<typename T> class list {
public:
    list(); //constructor that creates an empty list
    void push_back(const T& item); //adds item to the end
    //list<T>::const_iterator begin(); //returns constant iterator
    //list<T>::const_iterator end(); // returns constant iterator
};

class Sheet {
private:
    int width; //n of characters
    int height; //n of characters

public:
    Sheet(int width, int height) : width(width), height(height) {};
    int getWidth() {
        return width;
    }
    int getHeight() {
        return height;
    }

    ~Sheet() {};
};

class TextElement {
protected:
    std::string text;
    int nCharacters;

public:
    TextElement(std::string text) : text(text) {
        (this->text) += "\n";
        nCharacters = (this->text).length();
    }
    int getNumberOfCharacters() {
        return text.length();
    }

    virtual void print(int maxWidth) = 0;
    virtual ~TextElement() {};
};

class Leaflet {
    private:
        int identifier;
        Sheet *sheet;
        int nCharacters = 0;
        std::vector<TextElement*> textElements;
    public:
        Leaflet(int id): identifier(id) {};
        void assignSheet(Sheet &sheet) {
            this->sheet = &sheet;
        }

        void addTextElement(TextElement& textElement) {
            int incomingNumOfChar = textElement.getNumberOfCharacters();
            if (nCharacters + incomingNumOfChar > 999) {
                std::cerr << "Cannot add text element to paragraph as it would exceed the 1000 characters limit." << std::endl;
            } else {
                textElements.push_back(&textElement);
                nCharacters += incomingNumOfChar;
            }
        }

        void print() {
            int maxWidth = sheet->getWidth();
            int maxHeight = sheet->getHeight();
            int maxNumOfCharAllowedBySheet = maxWidth*maxHeight;
            if (nCharacters > maxNumOfCharAllowedBySheet) {
                std::cerr << "Cannot print: sheet is not large enough to contain " << nCharacters << " characters" << std::endl;
            } else {
                for (int i = 0; i < textElements.size(); i++) {
                    textElements[i]->print(maxWidth);
                }
            }
        }

        ~Leaflet() {};

};


class Heading : public TextElement {
    private:
        static int headingsCount;
        int prefix;

    public:
        Heading(std::string text) : TextElement(text) {
            headingsCount++;
            prefix = headingsCount;
            this->text = std::to_string(prefix) + ". " + (this->text);
        }

        static int getHeadingsCount() {
            return headingsCount;
        }

        void print(int maxWidth) override {
            if (nCharacters < maxWidth) {
                std::cout << text << std::endl;
            } else {
                int newLineIndex = maxWidth;
                for (int i = 0; i < nCharacters; i++) {
                    if (i == newLineIndex) {
                        std::cout << std::endl;
                        std::cout << "   " << text[i];
                        newLineIndex += maxWidth;
                    } else {
                        std::cout << text[i];
                    }
                }
            }
        }

        ~Heading() {
            headingsCount--;
        }

};

class Paragraph : public TextElement {
    public:
        Paragraph(std::string text) : TextElement(text) {
            this->text = "  " + (this->text) + "\n";
        };

        void print(int maxWidth) override {
            if (nCharacters < maxWidth) {
                std::cout << text << std::endl;
            } else {
                int newLineIndex = maxWidth;
                for (int i = 0; i < nCharacters; i++) {
                    if (i == newLineIndex) {
                        std::cout << std::endl;
                        if (text[i] == ' ') {
                            std::cout << " " << text[i];
                        } else {
                            std::cout << "  " << text[i];
                        }
                        newLineIndex += maxWidth;
                    } else {
                        std::cout << text[i];
                    }
                }
                std::cout << "\n\n" << std::endl;
            }
        }

};

int Heading::headingsCount = 0;

int main() {
    Leaflet myLeaflet = Leaflet(1);
    Sheet* smallSheet = new Sheet(50, 50);
    Sheet* tinySheet = new Sheet(20, 40);
    Heading heading1 = Heading("Importance of Bees");
    Paragraph paragraph1 = Paragraph("Globally there are more honey bees than other types of bee and pollinating insects, so it is the world's most important pollinator of food crops. In addition, honey bees play a significant role in the pollination of other important crops such as cotton and flax.");
    Heading heading2 = Heading("Threats to Bees");
    Paragraph paragraph2 = Paragraph("Threats to bees include habitat loss, climate change, toxic pesticides and disease.");

    myLeaflet.assignSheet(*smallSheet);

    myLeaflet.addTextElement(heading1);
    myLeaflet.addTextElement(paragraph1);
    myLeaflet.addTextElement(heading2);
    myLeaflet.addTextElement(paragraph2);

    myLeaflet.print();

    myLeaflet.assignSheet(*tinySheet);

    myLeaflet.print();

    delete smallSheet;
    delete tinySheet;


};