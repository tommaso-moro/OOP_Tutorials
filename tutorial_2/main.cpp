#include<iostream>
#include"team.hpp"

using namespace std;

int main() {
    Team team1 = Team(IMPERIAL_COLLEGE_LONDON);
    TeamMember teamMember1("Ivor Bigbrain", IMPERIAL_COLLEGE_LONDON, 20);
    TeamMember teamMember2("Prezza Buzza", IMPERIAL_COLLEGE_LONDON, 18);
    TeamMember teamMember3("Ivonna Singh", IMPERIAL_COLLEGE_LONDON, 25);
    TeamMember teamMember4("Yuman Google", IMPERIAL_COLLEGE_LONDON, 32);
    team1.addTeamMember(teamMember1);
    team1.addTeamMember(teamMember2);
    team1.addTeamMember(teamMember3);
    team1.addTeamMember(teamMember4);
    team1.memberLeaves(teamMember2);
    team1.teamCompliesWithRules();
}