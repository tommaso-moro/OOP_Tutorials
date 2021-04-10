#include"team.hpp"
#include<iostream>

Team::Team(UKUniversity university) : university(university) {};
Team::~Team(){};

void Team::addTeamMember(TeamMember teamMember) {
    TeamMember *ptrToTeamMember = &teamMember;
    teamMembers.push_back(ptrToTeamMember);
    //I don't perform checks here because the checks are in the "teamCompliesWithRules()" method
};

void Team::memberLeaves(TeamMember &teamMember) {
    std::vector<TeamMember*> newTeamMembers; // cerate new list of members which will replace the one in the current state
    for (int i = 0; i < teamMembers.size(); i++) {
        TeamMember* itrTeamMemberPtr = teamMembers[i]; //fetch pointer 
        TeamMember itrTeamMember = *itrTeamMemberPtr; //dereference it 
        if (!(itrTeamMember == teamMember)) { // compare it with func param
            newTeamMembers.push_back(itrTeamMemberPtr); // add member to new list if member is not the one who leaves
        }
    }
    teamMembers = newTeamMembers;
};

bool Team::teamCompliesWithRules() {
    //RULE 1: 
        //a) exactly 1 university -> ensured by the way the state is set up with enum
        //b) exactly 4 students. Check below:
    int nTeamMembers = teamMembers.size();
    if (nTeamMembers != 4) { 
        std::cerr << "Invalid number of team members!" << std::endl;
        return false;
    }

    //RULE 2: each student's university must be the same as the team's
    for (int i = 0; i < nTeamMembers; i++) {
        TeamMember* itrTeamMemberPtr = teamMembers[i];
        TeamMember itrTeamMember = *itrTeamMemberPtr;
        if (!(itrTeamMember.getUniversity() == (this->university))) {
            std::cerr << "Student university doesn't match team university" << std::endl;
            return false;
        }
    }

    //RULE 3: each student must be aged between 18 and 40
    for (int i = 0; i < nTeamMembers; i++) {
        TeamMember* itrTeamMemberPtr = teamMembers[i];
        TeamMember itrTeamMember = *itrTeamMemberPtr;
        int memberAge = itrTeamMember.getAge();
        if ((memberAge < 18) || (memberAge > 40)) {
            std::cerr << "Invalid member age" << std::endl;
            return false;
        }
    }

    //RULE 4: average age must be less than 25
    float ageMember1 = float((*teamMembers[0]).getAge());
    float ageMember2 = float((*teamMembers[1]).getAge());
    float ageMember3 = float((*teamMembers[2]).getAge());
    float ageMember4 = float((*teamMembers[3]).getAge());
    float averageAge = average(ageMember1, ageMember2, ageMember3, ageMember4);
    if (!(averageAge < 25)) {
        std::cerr << "Invalid average age" << std::endl;
        return false;
    }

    //RULE 5: there must be exactly one team captain
    int nCaptains = 0;
    for (int i = 0; i < nTeamMembers; i++) {
        TeamMember* itrTeamMemberPtr = teamMembers[i];
        TeamMember itrTeamMember = *itrTeamMemberPtr;
        if (itrTeamMember.isTeamCaptain() == true) {
            nCaptains++;
        }
    }
    if (nCaptains != 1) {
        std::cerr << "Invalid number of team captains!" << std::endl;
        return false;
    }
    return true;
};

