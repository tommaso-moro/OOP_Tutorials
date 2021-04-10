#ifndef TEAMMEMBER_HPP
#define TEAMMEMBER_HPP

#include"helper.hpp"
#include<string>

class TeamMember {
    std::string name;
    UKUniversity university;
    int age;
    bool isCaptain = false;

    public:
        TeamMember(std::string name, UKUniversity university, int age);
        TeamMember(TeamMember &teamMember); //copy constructor
        ~TeamMember();

        // == operator overloading
        bool operator==(const TeamMember &teamMember) const;

        //methods
        UKUniversity getUniversity();
        int getAge();
        void makeTeamCaptain();
        bool isTeamCaptain();

};

#endif