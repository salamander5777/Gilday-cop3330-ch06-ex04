/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Michael Gilday
 */

#include <iostream>
#include <vector>

//Chapter 6, exercise #4 - (Program that takes in user input of a name and a digit matched to it, and then adds the combination of the name and digit to a list. Each name must be unique or an error will occur, once each desired name is added the program can be stopped by entering 'Noname 0' which will then print out the whole list.)
class Name_value{
  public:
    std::string names;
    int scores;

    Name_value(std::string name, int value): names(name), scores(value){}
};

void proper_input(){
  std::vector<Name_value> total_input;
  std::string name_input;
  int value_input;
  int error_handle = 1;

  while (std::cin){ //Will continually loop for user input until 'NoName 0' is input or an error has occured.
    //Reads in user input for pair of name and integer.
    if(error_handle == 1){
      std::cin >> name_input >> value_input;
    }

    //This if statement will break out of the 'while' loop and print the list of pairs if 'NoName 0' is input or if a name has been input twice.
    if((name_input == "NoName" && value_input == 0) || error_handle == 0){
      for (int i=0; i<total_input.size(); ++i){
        std::cout << "(" << total_input[i].names << ", " << total_input[i].scores << ")\n";
      }
      break;
    }
    else{ //This else statement will verify whether a name has been input twice, if not then the current input value pair will be added to the vector array.
      for (int i=0; i<total_input.size(); ++i){
        if(name_input == total_input[i].names){
          std::cout << "Error - Duplicate name entered: '" << name_input << "'\n\n";
          error_handle = 0;
        }
      }

      if(error_handle == 1){
        total_input.push_back(Name_value(name_input, value_input));
      }
    }
  }
}
