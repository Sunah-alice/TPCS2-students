#ifndef CLUB_H
#define CLUB_H

#include<string>
#include<vector>
#include<iostream>
#include<sstream> //for stringstream

//Declaration of a class 
//that stores all input parameters loaded from a file
class Club
{
public:

    Club(std::string clubInformation); //User-defined default Constructor

    //member functions to query the data
    std::string get_clubName() const;
    std::string get_clubLeague() const;
    std::vector<int> get_matchs() const;
    int get_WP() const;
    int get_GD() const; 

private:
    std::string _clubName;
    std::string _clubLeague;
    std::vector<int> _matchs; //scores for matchs
    int _WP, _GD;
    unsigned int _no_m; //number of matchs

    //this is not a const member function
    //because we compute the WP, GD for each club 
    int comp_WP();
    int comp_GD();
};


#endif