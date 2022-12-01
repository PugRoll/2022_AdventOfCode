#include <iostream>
#include <fstream>
#include <string>

int main (int argc, char** argv) {

    std::cout<< "2022 Advent of Code --- Day 1\n";
    std::cout<< "************************************************************\n";
    
    //Create a file object to handle data set 
    std::ifstream in_fp;
    in_fp.open("Day1.txt");

    //String to getlines
    std::string str;
   
    int max = 0;
    int max2 =0;
    int max3 = 0;
    int currCals = 0;
    int countElves = 1;

    //Lets handle using this with and without cli args
    if(argc == 1) {
        //If no arguments passed then we assume no verbose functionality and run calcs
        if(in_fp.is_open()) {
        //Check to make sure not EOF
        while (in_fp.good()) {
            std::getline (in_fp, str);
            //Detect when we find a blank line 
            if(!str.size()) {
                //Handle when maximum has changed:
                //Keep track of top three maximums in pack
                if(currCals > max3) {
                    //Set max3  
                    max3 = currCals;
                    if(max3 > max2) {
                    //if max3  if bigger than max2 swap values
                        int tmp = max2;
                        max2 = max3;
                        max3 = tmp;
                        //finally if max2 is larger than max, swap
                        if(max2 > max) {
                                int tmp2 = max;
                                max = max2;
                                max2 = tmp2;
                            }
                        }
                    }                
                    //Handle new elf values
                    currCals = 0;
                    countElves++;
                }
                //When we are parsing info
                else {
                    //Print nums for fun visualization
                    currCals += std::stoi(str); //Sum total the values
                 
                }
            }
        }
    }
    else if(argv[1] == "-v" || "--verbose") {
    //Ensure we have opened the file
        if(in_fp.is_open()) {
            //Check to make sure not EOF
            while (in_fp.good()) {
                std::getline (in_fp, str);
                //Detect when we find a blank line 
                if(!str.size()) {
                    //Handle when maximum has changed:
                    //Keep track of top three maximums in pack
                    if(currCals > max3) {
                        //Set max3  
                        max3 = currCals;
                        if(max3 > max2) {
                        //if max3  if bigger than max2 swap values
                        int tmp = max2;
                        max2 = max3;
                        max3 = tmp;
                        //finally if max2 is larger than max, swap
                            if(max2 > max) {
                                int tmp2 = max;
                                max = max2;
                                max2 = tmp2;
                            }
                        }

                    }

                    std::printf("Elf %d, Calories: %d --- Current Maximum: %d\n", countElves, currCals, max);
                    std::cout << "-------------------------------- BREAK --------------------------------\n";
                    //Handle new elf values
                    currCals = 0;
                    countElves++;
                }
                //When we are parsing info
                else {
                    //Print nums for fun visualization
                    std::cout << str << "\n";
                    currCals += std::stoi(str); //Sum total the values
                 
                }
            }
        }
    }

    //Print the maximum
    std::printf("Maximum calories in elf pack:\n Top: 1: %d\t 2: %d\t 3: %d\n", max, max2, max3);
    std::printf("Calories carried amongst these elves: %d\n", (max + max2 + max3)); 
    std::cout << "***********************************************************\n";
    std::cout << "END_2022 Advent of Code --- Day 1\n";

    return 0;

}
