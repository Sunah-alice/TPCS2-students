//
// Created by Sunah O on 11/03/2022
//
// SNU-ID: 2020-16586
//
// Homework 04
//

#include"file_stream.hpp"

void File_Stream::run(const std::string& infilePath,
                      const std::string& outfilePath)
{
    //We need a vector of clubs' information to store all the data
    std::vector<Club> clubs_list;

    //Now read the data from the input file
    In_File_Stream infile;
    infile.read_clubs_inform(infilePath, clubs_list);

    //Here we do something (Data Processing)

    //Finally, we write the post-processing data to the output file
    Out_File_Stream outfile;
    outfile.write_clubs_rank(outfilePath, &clubs_list);
}


void In_File_Stream::read_clubs_inform(const std::string& infilePath, std::vector<Club> &clubs_list)
{
    std::cout << "Reading from the input file ..." << std::endl;
    
    //Open file for reading
    std::fstream infile(infilePath, std::ios::in);
    if (infile.is_open())
    {
        std::string line;
        while (std::getline(infile,line))
        {
            //Load the information in each line
            //the user-defined constructor will read and parse the information.
            Club s(line);

            //We then store this piece of information to a list for later use
            clubs_list.push_back(s);
        }
        
        infile.close();
    }

    std::cout << "Finish Reading ..." << std::endl;
}

void Out_File_Stream::write_clubs_rank(const std::string& outfilePath, std::vector<Club>* clubs_list)
{
    std::cout << "Writing to a new file ..." << std::endl;

    //Open file for writing - overwrite the previous data
    std::fstream outfile(outfilePath, std::ios::out);
    if (outfile.is_open())
    {
        for (auto s : *clubs_list)
        {
            outfile << s.get_clubName() << " ";
            outfile << s.get_clubLeague() << " ";

            outfile << s.get_WP() << " ";
            outfile << s.get_GD() << "\n";

        }
        
        outfile.close();
    }

}