//
// Created by Sunah O on 11/03/2022
//
// SNU-ID: 2020-16586
//
// Homework 04
//

#include "Club.hpp"

Club::Club(std::string Input_Information)
{
    std::stringstream this_club(Input_Information);
    
    //Extracts and parses characters sequentially from the stream 
    //to interpret them as the representation of a value of the proper type
    //Note: this stream should be in the same order 
    //with respect to the information in the input file
    //Input ex. SeoulFC K1 2 1 0 2 3 - SeoulFC which belongs to K1 league is scoring 1:0 and 2:3 for two recent matchs
    this_club >> _clubName;
    this_club >> _clubLeague;
    this_club >> _no_m;

    //if the club hasn't done any match recently
    if (_no_m == 0) 
    {
        std::cout << "There is an error in the input file!\n";
        std::cout << "The league should have at least 1 match \n";
        
    }
    //Save match scores into vector (two int per one match - size: _no_m *2)
    //_matchs vector's first two numbers are for first match score
    //ex. _matchs {1, 0, 2, 3}  first match 1(me):0(opponent)
    _matchs.resize(_no_m * 2);
    for (unsigned int i = 0; i < _no_m*2; ++i)
    {
        this_club >> _matchs[i];
        
    }

    //Compute the winning point and goal difference after getting the data from stringstream
    comp_WP();
    comp_GD();

}

std::string Club::get_clubName() const
{
    return _clubName;
}

std::string Club::get_clubLeague() const
{
    return _clubLeague;
}

std::vector<int> Club::get_matchs() const
{
    return _matchs;
}

int Club::get_WP() const
{
    return _WP;
}

int Club::get_GD() const
{
    return _GD;
}

int Club::comp_WP()
{
    //compute winning point
    //In this case we assume the scores depends on
    //the input file.

    unsigned int win = 0;
    unsigned int lose = 0;
    unsigned int tie = 0;
    for (int i = 0; i < _no_m*2; i = i + 2){
        if(_matchs[i] > _matchs[i+1]) {
            win += 1;
        }else if(_matchs[i] < _matchs[i+1]){
            lose += 1;
        }else if(_matchs[i] == _matchs[i+1]){
            tie += 1;
        }
    }
    
    //If win, gain 3 points. If tie, gain 1 points. If lose, no point.
    _WP = win * 3 + tie * 1;
    
    return _WP;
}

int Club::comp_GD()
{
    //compute goal difference
    //In this case we assume the scores depends on
    //the input file.
    int Total = 0;
    for (int i = 0; i < _no_m*2; i = i + 2){
        int a = _matchs[i];
        Total += a;
        int b = _matchs[i+1];
        Total -= b;
    }
    
    //club's score - opponents' score
    _GD = Total;
    return _GD;
}