/**
	CS219 Section 1001	

	This file will take in a text file following the format of OPERATION OPERAND1 OPERAND2 where it will use the operation specified in the text file on the two operands and display the answer to the terminal.

	@file main.cpp
	@author Austin Ah Mau
	@version 1.0 1/26/2022
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const int NUM_ARGS = 2;

/**
	Goes through a provided text file and performs the appropriate arithmetic on the operands in the file.

	@param argc - argument count
	@param argv[] - character array that holds arguments passed to main
	@return 0
*/

int main(int argc, char* argv[]){
	std::string operation, operand1, operand2;
	std::vector<std::string> operations, operands1, operands2;

	//checks for correct number of arguments
	if(argc < NUM_ARGS){
		std::cout << "correct usage:" << std::endl;
		std::cout << argv[0] << " filename" << std::endl;
		return 0;
	}

	//opens file and stores contents into vectors
	std::ifstream myFile;
	myFile.open(argv[1]);
	if(myFile){
		while(myFile >> operation >> operand1 >> operand2){
			operations.push_back(operation);
			operands1.push_back(operand1);
			operands2.push_back(operand2);
		}
	myFile.close();
	}

	else{
		std::cout << "file does not exist" << std::endl;
	}

	//converts operands to unsigned ints and displays the operation answer of the two operands to the terminal
	for(int i = 0; i < operations.size(); i++){
		if(operations.at(i) == "ADD"){
			uint32_t num1 = std::stoul(operands1.at(i), 0, 16);
			uint32_t num2 = std::stoul(operands2.at(i), 0, 16);

			std::cout << operations.at(i) << ": " << operands1.at(i) << " + " << operands2.at(i) << " = 0x" << std::hex << std::uppercase << num1 + num2 << std::endl;
		}
	}

return 0;
}
