#ifndef TEAM_HPP
#define TEAM_HPP

#include"teamMember.hpp"
#include<vector>

class Team {
    UKUniversity university;
    std::vector<TeamMember*> teamMembers;

    public:
        Team(UKUniversity university);
        ~Team();

        //methods
        bool teamCompliesWithRules();
        void addTeamMember(TeamMember teamMember);
        void memberLeaves(TeamMember & teamMember);
};

#endif