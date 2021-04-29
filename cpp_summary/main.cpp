#include<iostream>
#include<vector>
#include<string>


// //////////////////////////////////////// //
// /////////////// TEMPLATES ////////////// //
// //////////////////////////////////////// //

class Furniture {
public:
    int weight;

public:
    Furniture(int weight) : weight(weight) {};
    ~Furniture() {
        //delete this;
    };

};

template <typename T, const int FURNITURE_CAPACITY = 50>
class House {
private:
    T identifier;
    Furniture* furniture[FURNITURE_CAPACITY];
    int furnitureOccupancy = 0;

public:
    House(T id) : identifier(id) {
        for (int i = 0; i < FURNITURE_CAPACITY; i++) {
            furniture[i] = nullptr;
        }
    }

    void addFurniture(Furniture &pieceOfFurniture) {
        if (furnitureOccupancy < FURNITURE_CAPACITY) {
            furniture[furnitureOccupancy] = &pieceOfFurniture;
            furnitureOccupancy++;
            std::cout << "Piece of furniture added correctly!" << std::endl;
        } else {
            std::cerr << "Cannot add more furniture to this house!" << std::endl;
            std::cerr << "Deleting piece of furniture..." << std::endl;
            delete &pieceOfFurniture;
        }
    }

};

template <typename T, typename C, typename A>
class MultipleTemplateArgs {
private:
    T t;
    C c;
    A a;

public:
    MultipleTemplateArgs(T t, C c, A a) : t(t), c(c), a(a) {};
    T getT() const {
        return t;
    }
    C getC() const {
        return c;
    }
    A getA() const {
        return a;
    }
};

void templates() {
    int const myHouseMaxCapacity = 3; //has to be const in order to be a template param!
    House<std::string, myHouseMaxCapacity> myHouse = House<std::string, myHouseMaxCapacity>("Tommy's house");
    House<std::string, 5> matiHouse = House<std::string, 5>("Mati's house");
    Furniture* myChair = new Furniture(25);
    myHouse.addFurniture(*(myChair));
    myHouse.addFurniture(*(myChair));
    myHouse.addFurniture(*(myChair));
    myHouse.addFurniture(*(myChair));
    matiHouse.addFurniture(*(myChair));
    matiHouse.addFurniture(*(myChair));
    matiHouse.addFurniture(*(myChair));
    matiHouse.addFurniture(*(myChair));
    matiHouse.addFurniture(*(myChair));

    MultipleTemplateArgs<int, double, std::string> myMTA = MultipleTemplateArgs<int, double, std::string>(3, 5.5, "test");
    std::cout << myMTA.getT() << std::endl;
    std::cout << myMTA.getC() << std::endl;
    std::cout << myMTA.getA() << std::endl;

}


// //////////////////////////////////////// //
// ///////// MULTIPLE INHERITANCE ///////// //
// //////////////////////////////////////// //

enum RunningShoeBrand {NIKE, ADIDAS, HOKA_ONE_ONE};

std::string getRunningShoeBrandAsString(RunningShoeBrand &brand) {
    switch(brand) {
        case NIKE:
            return "Nike";
            break;
        case ADIDAS:
            return "Adidas";
            break;
        case HOKA_ONE_ONE:
            return "Hoka One One";
            break;
        default:
            return "Not recognized";
            break;
    }
}

class Athlete {
protected:
    std::string name;

public:
    Athlete(std::string name) : name(name) {};
    std::string getName() {
        return name;
    }
    virtual void printAthleteInfo() {
        std::cout << "\nAthlete info: " << std::endl;
        std::cout << "\tAthlete name: " << getName() << std::endl;
    }

};

class Runner : public Athlete {
protected:
    RunningShoeBrand shoe;

public:
    Runner(std::string name, RunningShoeBrand shoe) : Athlete(name), shoe(shoe) {};
    void printAthleteInfo() override {
        Athlete::printAthleteInfo();
        std::cout << "\tAthlete's shoes: " << getRunningShoeBrandAsString(shoe) << std::endl;
    }
};

class NNRunner : public Runner {
private:
    int numRacesWon;

public:
    NNRunner(std::string name, RunningShoeBrand shoe, int numRacesWon) : Runner(name, shoe), numRacesWon(numRacesWon) {};
    void printAthleteInfo() override {
        Runner::printAthleteInfo();
        std::cout << "\tWins: " << numRacesWon << std::endl;
    }

};

class A {
public:
    A() {};
    virtual ~A() {
        std::cout << "A's destructor called" << std::endl;
    }
};

class B : public A {
public:
    B() {};
    virtual ~B() {
        std::cout << "B's destructor called" << std::endl;
    }
};

class C : public B {
public:
    C() {};
    ~C() {
        std::cout << "C's destructor called" << std::endl;
    }
};

void inheritance() {
    Athlete anyoneWhoWorksOut = Athlete("anyone");
    Runner me = Runner("Tommy", NIKE);
    NNRunner kipchoge = NNRunner("Eliud Kipchoge", NIKE, 15);
    anyoneWhoWorksOut.printAthleteInfo();
    me.printAthleteInfo();
    kipchoge.printAthleteInfo();

    Athlete bekeleAsAthlete = NNRunner("Kenenisa Bekele", NIKE, 10);
    Runner bekeleAsRunner = NNRunner("Kenenisa Bekele", NIKE, 10);
    NNRunner bekeleAsNNRunner = NNRunner("Kenenisa Bekele", NIKE, 10);

    bekeleAsAthlete.printAthleteInfo();
    bekeleAsRunner.printAthleteInfo();
    bekeleAsNNRunner.printAthleteInfo();

    // Pointers to a derived class may be implicitly converted to pointers to their
    // base class but not vice-versa.
    // So this is allowed:
    Runner* derivedAthlete = new Runner("name", NIKE);
    Athlete* athlete = derivedAthlete;
    athlete->printAthleteInfo(); //calls Runner's printAthleteInfo(), not the base class's version
    // With multiple inheritance:
    NNRunner* derivedRunner = new NNRunner("Joshua Cheptegei", NIKE, 6);
    Runner* attempt1 = derivedRunner; // this is ok
    Athlete* attempt2 = derivedRunner; // this is ok
    Athlete* attempt3 = attempt2; // this is ok

    // But this is NOT allowed:
    Athlete* test1 = new Athlete("test1");
    // NOT ALLOWED: Runner* test = test1;
    // will throw "error: cannot initialize a variable of type 'Runner *' with an lvalue of type 'Athlete *'"

    // destructors
    delete derivedAthlete;
    //if I do "delete athlete" here I'll get an error because by deleting derivedAthlete I also deleted athlete (see line 178)

    //A a = new A();
    //B b = new B();
    C* c = new C();
    delete c; //calls C's destructor -> then B's destructor -> then A's destructor

}

// //////////////////////////////////////// //
// /////////// ABSTRACT CLASSES /////////// //
// //////////////////////////////////////// //

class Computer {
protected:
    int RAMCapacity;
    int HDCapacity;
    bool isOn = false;

public:
    Computer(int RAMCapacity, int HDCapacity) : RAMCapacity(RAMCapacity), HDCapacity(HDCapacity) {};
    virtual void powerOn() = 0; //"virtual {function} = 0" -> means the derived class has to instantiate this method (or if not it'll be an abstract class)
    virtual void powerOff() = 0;
    bool isComputerOn() {
        return isOn;
    }
};

class MacbookPro : public Computer {
public:
    MacbookPro(int RAMCapacity, int HDCapacity) : Computer(RAMCapacity, HDCapacity) {};
    void powerOn() override {
        isOn = true;
    }
    void powerOff() override {
        isOn = false;
    }
};

void abstractClasses() {
    MacbookPro myMacbookPro = MacbookPro(16, 512);
    myMacbookPro.powerOn();
    std::cout << myMacbookPro.isComputerOn() << std::endl;
    myMacbookPro.powerOff();
    std::cout << myMacbookPro.isComputerOn() << std::endl;

}

// //////////////////////////////////////// //
// ////// INHERITANCE with templates ////// //
// //////////////////////////////////////// //

template <typename T, const int NUM_KEYS = 88>
class Piano {
protected:
    int numKeys = NUM_KEYS;
    T smth;

public:
    Piano(T smth) : smth(smth) {};
    int getNumKeys() {
        return numKeys;
    }
};

template <typename T, const int NUM_KEYS = 80>
class Keyboard : public Piano<T, NUM_KEYS> {
private:
    int numMidiPorts;

public:
    Keyboard(T smth, int numMidiPorts) : Piano<T, NUM_KEYS>(smth), numMidiPorts(numMidiPorts) {};
};

void inheritanceWithTemplates() {
    Piano<int> myPiano = Piano<int>(5);
    Keyboard<std::string, 72> myKeyboard = Keyboard<std::string, 72>("test", 3);
    std::cout << myKeyboard.getNumKeys() << std::endl;
    std::cout << myPiano.getNumKeys() << std::endl;
}


// //////////////////////////////////////// //
// ///////// STATIC DATA MEMBERS ////////// //
// //////////////////////////////////////// //

class Pen {
private:
    static int count; // static data member

public:
    Pen() { count++; }
    static int getCount() { // getter has to be declared static
       return count;
    }
};

int Pen::count = 0; // needs to be initialized outside of the class

void staticDataMember() {
    Pen pen1 = Pen();
    std::cout << Pen::getCount() << std::endl; // can access it like this
    Pen pen2 = Pen();
    std::cout << Pen::getCount() << std::endl;
}

// //////////////////////////////////////// //
// ///////// OPERATORS OVERLOADING //////// //
// //////////////////////////////////////// //

enum Genre {TECHNO, POP, CLASSICAL, RAP, JAZZ};

class Song {
private:
    Genre genre;
    int durationInSeconds;
    std::string singer;
    int dailyListeners;

public:
    //constructor
    Song(Genre genre, int durationInSeconds, std::string singer, int dailyListeners) : genre(genre), durationInSeconds(durationInSeconds), \
        singer(singer), dailyListeners(dailyListeners) {};

    // assignment overloading
    Song& operator=(Song const &otherSong) {
        this->genre = otherSong.genre;
        this->durationInSeconds = otherSong.durationInSeconds;
        this->singer = otherSong.singer;
        this->dailyListeners = otherSong.dailyListeners;
        return *this;
    }

    // copy constructor
    Song(Song const &otherSong) {
        *this = otherSong;
    }

    // destructor
    ~Song() {};

    bool operator>(Song& otherSong) {
        if (otherSong.dailyListeners < this->dailyListeners) {
            return true;
        } else {
            return false;
        }
    }

    bool operator==(Song& otherSong) {
        if (singer == otherSong.singer && dailyListeners == otherSong.dailyListeners) {
            return true;
        } else {
            return false;
        }
    }

    bool operator<(Song& otherSong) {
        if (otherSong.dailyListeners > this->dailyListeners) {
            return true;
        } else {
            return false;
        }
    }
};


void operatorsOverloading() {
    Song mySong = Song(TECHNO, 120, "Ross From Friends", 1000);
    Song yourSong = Song(RAP, 150, "2Pac", 100000);
    std::cout << (yourSong > mySong) << std::endl;
    std::cout << (yourSong < mySong) << std::endl;

    Song anotherSong = Song(TECHNO, 120, "Ross From Friends", 1000);
    std::cout << (yourSong==mySong) << std::endl;
    std::cout << (anotherSong==mySong) << std::endl;
}


// //////////////////////////////////////// //
// //////////////// ARRAYS //////////////// //
// //////////////////////////////////////// //

class Recipe {
private:
    int ingredientsCount = 0;
    int* ingredients;

public:
    Recipe() {
        ingredients = new int [ingredientsCount];
    };
    void addIngredient(int &ingredient) {
        int newIngredients[ingredientsCount++];
        for (int i = 0; i < ingredientsCount; i++) {
            newIngredients[i] = ingredient;
        }
        delete [] ingredients;
        ingredients = newIngredients;
    }
};

void arrays() {
    int array1[3];
    int* array2[3];
    int** array3[3];
    for (int i = 0; i < 3; i++) {
        array1[i] = i;
        array2[i] = &array1[i];
        array3[i] = &(array2[i]);
    };
    for (int i = 0; i < 3; i++) {
        std::cout << std::endl;
        std::cout << "array1[i]: " << array1[i] << std::endl;
        std::cout << "array2[i]: " << array2[i] << std::endl;
        std::cout << "*(array2[i]): " << *(array2[i]) << std::endl;
        std::cout << "array3[i]: " << array3[i] << std::endl;
        std::cout << "*(array3[i]): " << *(array3[i]) << std::endl;
        std::cout << "**(array3[i]): " << **(array3[i]) << std::endl;
        std::cout << std::endl;
    };

    int array1Size = sizeof(array1)/sizeof(int);

    int storeCapacity = 15;
    int* aStore = new int[storeCapacity];
    int** anotherStore = new int *[storeCapacity];
    delete [] aStore;
    delete [] anotherStore;



}


// //////////////////////////////////////// //
// ///////////////// MAPS ///////////////// //
// //////////////////////////////////////// //

/*
class ExtendableArray {
private :
int count , capacity ;

T * store ;

void resizeStore () {
        T * new_store = new T [ capacity ];
        for (int i = 0; i < count ; i ++)
            new_store [ i ] = store [ i ];
         delete [] store ;
        store = new_store ;
        1}
*/



// //////////////////////////////////////// //
// //////////// CHAR vs STRING //////////// //
// //////////////////////////////////////// //


void charVsString() {
    char ch1 = 'A';
    std::string s1 = "I am Tommy";

    char* ch2 = "I like climbing";
    std::cout << ch2 << std::endl; //creates an array where element is a char
    int itr = 0;
    while (ch2[itr] != '\0') { //char arrays end by default with a '\0', useful cause it means I can loop them!
        itr++;
    }
    std::cout << itr << std::endl;

    std::string s2 = (std::string) ch2; //kinda works but will have the weird character at the end tdue to '\0'
    std::cout << s2 << std::endl;

    char ch5[] = "Palms Trax";
    std::cout << ch5[3] << std::endl; // prints 'm'
    std::cout << ch5 << std::endl;


    //convert string to char
    //METHOD 1:
    int s1Length = s1.length();
    char ch3[s1Length+1];
    strcpy(ch3, s1.c_str());
    std::cout << ch3 << std::endl;

    //METHOD 2
    char ch4[s1Length+1];
    for (int i = 0; i < s1Length; i++) {
        char ch = (char) s1[i];
        ch4[i] = ch;
    }
    std::cout << ch4 << std::endl;


}



// //////////////////////////////////////// //
// //////////////// LAMBDAS /////////////// //
// //////////////////////////////////////// //



// //////////////////////////////////////// //
// //////////// BASIC FILE I/O //////////// //
// //////////////////////////////////////// //



// //////////////////////////////////////// //
// //////// BASIC FILE EXCEPTIONS ///////// //
// //////////////////////////////////////// //


int main() {
    //templates();
    //inheritance();
    //abstractClasses();
    //inheritanceWithTemplates();
    //staticDataMember();
    //operatorsOverloading();
    //arrays();
    charVsString();
}