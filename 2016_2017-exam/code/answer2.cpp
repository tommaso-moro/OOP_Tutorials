#include<iostream>
#include<string>
#include<vector>

//how to deal with the codependency between Label and Bag?

const double WALNUT_FAT_PERCENTAGE = 0.6521;
const double ALMOND_FAT_PERCENTAGE = 0.5064;
enum NutType { WALNUT, ALMOND };


class Nut {
protected:
    double weight;
    NutType nutType;

public:
    Nut(NutType nutType, double weight) : nutType(nutType), weight(weight) {};
    double getWeight() {
        return weight;
    }
    NutType getNutType() {
        return nutType;
    }
};

class BNI {
private:
    double totalEnergy = 0;
    double totalFatContent = 0;

    double getNutFatContent(Nut &nut) {
        if (nut.getNutType() == WALNUT) {
            return (nut.getWeight())*WALNUT_FAT_PERCENTAGE;
        } else {
            return (nut.getWeight())*ALMOND_FAT_PERCENTAGE;
        }
    }

    double getNutEnergy(Nut &nut) {
        double nutFatContent = getNutFatContent(nut);
        double energyFromGramsOfFat = nutFatContent*9;
        double energyFromGramsOfNonFat = (nut.getWeight() - nutFatContent)*4;
        return energyFromGramsOfFat+energyFromGramsOfNonFat;
    }

    double computeTotalEnergy(std::vector<Nut*> bagNuts) {
        double energy = 0;
        for (int i = 0; i < bagNuts.size(); i++) {
            double nutEnergy = getNutEnergy(*(bagNuts[i]));
            energy += nutEnergy;
        }
        return energy;
    }

    double computeTotalFatContent(std::vector<Nut*> bagNuts) {
        double fatContent = 0;
        for (int i = 0; i < bagNuts.size(); i++) {
            double nutFatContent = getNutFatContent(*(bagNuts[i]));
            fatContent += nutFatContent;
        }
        return fatContent;
    }


public:
    BNI(std::vector<Nut*> nuts) {
        totalEnergy = computeTotalEnergy(nuts);
        totalFatContent = computeTotalFatContent(nuts);
    }

    double getTotalFatContent() {
        return totalFatContent;
    }

    double getTotalEnergy() {
        return totalEnergy;
    }
};

class Label {
private:
    std::string labelText;

public:
    Label(std::vector<Nut*> bagNuts) {
        BNI bagNutsBNI = BNI(bagNuts);
        setLabelText(bagNutsBNI);
    }

    void setLabelText(BNI &bagNutsBNI) {
        double nutsEnergy = bagNutsBNI.getTotalEnergy();
        double nutsFat = bagNutsBNI.getTotalFatContent();
        labelText = "Total of " + std::to_string(nutsEnergy) + " kcal (" + std::to_string(nutsFat) + "g in fat)";
        if (nutsFat > 20.0) {
            labelText += " [high in fat]";
        }
    }

    std::string getLabelText() {
        return labelText;
    }

};

class Bag {
private:
    Label* label;
    std::vector<Nut*> nuts;
    int nutCapacity;

public:
    Bag(int nutCapacity) : nutCapacity(nutCapacity) {};
    ~Bag() {
        delete label;
        for (int i = 0; i < nuts.size(); i++) {
            delete nuts[i];
        }
    }

    void addNut(Nut &nut) {
        if (nuts.size() < nutCapacity) {
            nuts.push_back(&nut);
        } else {
            std::cerr << "Cannot add nut: max number of nuts exceeded for bag" << std::endl;
        }
    }

    std::vector<Nut*> getNuts() {
        return nuts;
    }

    void addLabel(Label &label) {
        this->label = &label;
    }

    void printLabel() {
        std::cout << label->getLabelText() << std::endl;
    }


};




int main() {
    Nut* walnut1 = new Nut(WALNUT, 8);
    Nut* walnut2 = new Nut(WALNUT, 13);
    Nut* almond1 = new Nut(ALMOND, 1.5);
    Nut* walnut3 = new Nut(WALNUT, 16);
    Bag myBag = Bag(5);

    myBag.addNut(*(walnut1));
    myBag.addNut(*(almond1));

    Label* label1 = new Label(myBag.getNuts());
    myBag.addLabel(*(label1));

    myBag.addNut(*(walnut2));
    myBag.addNut(*(walnut3));

    Label* label2 = new Label(myBag.getNuts());
    myBag.addLabel(*(label2));

    myBag.printLabel();

}