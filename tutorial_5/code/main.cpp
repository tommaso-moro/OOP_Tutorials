#include<iostream>

#include "seniorPA.hpp"
#include "fixedPenaltyFine.hpp"
#include "juniorPA.hpp"
#include "excessChargeFine.hpp"


using namespace std;

int main() {
    SeniorPA spa = SeniorPA("Charon", 666);
    FixedPenaltyFine* fpFine1 = new FixedPenaltyFine("16/02/2006", "09H50", "LO52RNA", 26);
    spa.issueFine(fpFine1);

    fixedPenaltyAmount = 120;

    JuniorPA jpa = JuniorPA("Nelson", 111);
    ExcessChargeFine* expFine1 = new ExcessChargeFine("17/02/2006", "10H15", "B14NCA", 14, 15);
    jpa.issueFine(expFine1);

    cout << "Nelson's salary: " << jpa.calculateSalary() << endl;


}