#include<iostream>
#include<string>
#include<vector>

const int MINIMUM_APPLICATION_SCORE = 66;
enum ApplicantType {NAF, PAF, BOTH}; // get rid of "BOTH"

class ApplicationForm {
private:
    std::string applicantName;
    int applicantYearOfBirth;
    double applicantOSMark;
    ApplicantType applicationType;

public:
    ApplicationForm(std::string name, int yearOfBirth, double OSMark) : applicantName(name), applicantYearOfBirth(yearOfBirth), \
        applicantOSMark(OSMark) {};

    virtual ~ApplicationForm() {};

    double getOSMark() const {
        return applicantOSMark;
    }

    ApplicantType getApplicationType() {
        return applicationType;
    }

    virtual double getApplicationTypeSpecificMark() const = 0;

protected:
    ApplicantType setApplicationType(ApplicantType type) {
        this->applicationType = type;
    };
};

class NAFApplication : public ApplicationForm {
private:
    double applicantCompNetworksMark;

public:
    NAFApplication(std::string name, int yearOfBirth, double OSMark, double applicantCompNetworksMark) : ApplicationForm(name, yearOfBirth, OSMark) {
        this->applicantCompNetworksMark = applicantCompNetworksMark;
        setApplicationType(NAF);
    }

    double getApplicationTypeSpecificMark() const override {
        return applicantCompNetworksMark;
    }

    ~NAFApplication() {};

};

class PAFApplication : public ApplicationForm {
private:
    double applicantProgrammingMark;

public:
    PAFApplication(std::string name, int yearOfBirth, double OSMark, double applicantProgrammingMark) : ApplicationForm(name, yearOfBirth, OSMark) {
        this->applicantProgrammingMark = applicantProgrammingMark;
        setApplicationType(PAF);
    }

    double getApplicationTypeSpecificMark() const override {
        return applicantProgrammingMark;
    }

    ~PAFApplication() {};
};

class Applicant {
private:
    std::string name;
    int yearOfBirth;
    ApplicantType applicantType;
    double applicantOSMark;
    double applicantProgrammingMark = 0;
    double applicantCompNetworksMark = 0;


public:
    Applicant(std::string name, int yearOfBirth, ApplicantType applicantType, double OSMark) : name(name), \
    yearOfBirth(yearOfBirth), applicantType(applicantType), applicantOSMark(OSMark) {
    }

    NAFApplication* makeNAFApplication(double compNetworksMark) {
        this->applicantCompNetworksMark = compNetworksMark;
        NAFApplication* newNAF = new NAFApplication(name, yearOfBirth, applicantOSMark, this->applicantCompNetworksMark);
        return newNAF;
    }

    PAFApplication* makePAFApplication(double programmingMark) {
        this->applicantProgrammingMark = programmingMark;
        PAFApplication* newPAF = new PAFApplication(name, yearOfBirth, applicantOSMark, this->applicantProgrammingMark);
        return newPAF;
    }
};

class HRPersonnel {
private:
    std::string name;
    int yearOfBirth;
    std::vector<ApplicationForm*> applicationForms;
    int applicationFormsCapacity;

public:
    HRPersonnel(std::string name, int yearOfBirth, int applicationFormsCapacity) : name(name), yearOfBirth(yearOfBirth), \
        applicationFormsCapacity(applicationFormsCapacity) {};

    void receivesApplication(ApplicationForm &applicationForm) {
        if (applicationFormsCapacity > 0) {
            applicationForms.push_back(&applicationForm);
            applicationFormsCapacity--;
        }
    }

    double computeApplicationScore(ApplicationForm* application) {
        return ((application->getApplicationTypeSpecificMark())+(application->getOSMark()))/2;
    }

    void removePoorAFs() {
        for (int i = 0; i < applicationForms.size(); i++) {
            double applicationScore = computeApplicationScore(applicationForms[i]);
            if (applicationScore < MINIMUM_APPLICATION_SCORE) {
                delete applicationForms[i];
            }
        }
    }

    int getNumOfAFs() const {
        return applicationForms.size();
    }
    //count AFs
    //remove AFs below 77
};

int main() {

        HRPersonnel helen = HRPersonnel("Helen", 1975, 50);
        Applicant peter = Applicant("Peter", 1986, NAF, 65);
        Applicant susan = Applicant("Susan", 1989, BOTH, 70);

        NAFApplication* peterNAF = peter.makeNAFApplication(75);
        helen.receivesApplication(*(peterNAF));

        NAFApplication* susanNAF = susan.makeNAFApplication(60);
        PAFApplication* susanPAF = susan.makePAFApplication(80);

        helen.receivesApplication(*(susanNAF));
        helen.receivesApplication(*(susanPAF));

        std::cout << helen.getNumOfAFs() << std::endl;
        helen.removePoorAFs();

        helen.getNumOfAFs();

        std::cout << helen.getNumOfAFs() << std::endl;
}