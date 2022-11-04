#ifndef FILE_STREAM_H
#define FILE_STREAM_H

#include<fstream>
#include<string>
#include<vector>
#include<iostream>

#include"Club.hpp"

//This class is to run the program
class File_Stream
{
public:
    void run(const std::string& infilePath,
             const std::string& outfilePath);
};

class In_File_Stream
{
public:
    void read_clubs_inform(const std::string& infilePath, std::vector<Club> &clubs_list);

};

class Out_File_Stream
{
public:
    void write_clubs_rank(const std::string& outfilePath, std::vector<Club>* clubs_list);
};

#endif