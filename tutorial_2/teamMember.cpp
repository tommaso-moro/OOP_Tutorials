#include"teamMember.hpp"

TeamMember::TeamMember(std::string name, UKUniversity university, int age) : name(name), university(university), age(age) {};

TeamMember::~TeamMember(){};

TeamMember::TeamMember(TeamMember &teamMember) {
    this->name = teamMember.name;
    this->age = teamMember.age;
    this->university = teamMember.university;
    this->isCaptain = teamMember.isCaptain;
}

bool TeamMember::operator==(const TeamMember &teamMember) const {
    if (((this->name == teamMember.name) && (this->isCaptain == teamMember.isCaptain)) && ((this->university == teamMember.university) \
    && (this->age == teamMember.age))) {
        return true;
    } else {
        return false;
    }
};

UKUniversity TeamMember::getUniversity() {
    return university;
};

int TeamMember::getAge() {
    return age;
};

void TeamMember::makeTeamCaptain() {
    isCaptain = true;
};

bool TeamMember::isTeamCaptain() {
    return isCaptain;
};