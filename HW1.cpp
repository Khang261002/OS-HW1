#include <cstdlib>
#include <iostream>
#include <string>

void list_dir_contents() {
    system("dir");
    return;
}

void print_dir() {
    system("cd");
    return;
}

bool create_dir() {
    std::string name;
    std::cout << "Please enter a name for your new directory: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    // Dealing with name with spaces
    std::string create = "mkdir \"" + name + "\"";
    std::string del = "rmdir /s /q \"" + name + "\"";

    int mkdirResult = system(create.c_str());
    if (mkdirResult != 0) {
        // Handle error if directory creation fails
        // For example, print an error message or exit the program
        return false;
    } else {
        std::cout << name + " has been created successfully!" << std::endl;
    }
    
    std::cout << "Press any key to delete the directory and continue." << std::endl;
    std::getchar();
    
    int delResult = system(del.c_str());
    if (delResult != 0) {
        // Handle error if directory deletion fails
        // For example, print an error message or exit the program
        return false;
    } else {
        std::cout << name + " has been deleted successfully!" << std::endl;
    }
    return true;
}

void display_message() {
    std::string message;
    std::cout << "Please enter a message you want to print: ";
    std::cin.ignore();
    std::getline(std::cin, message);

    std::string command = "echo " + message;
    int returnCode = system(command.c_str());

    // Checking if the command was executed successfully
    if (returnCode != 0) {
        std::cout << "Message display failed or returned non-zero: " << returnCode << std::endl;
    }
    return;
}

bool concatenate_files() {
    std::string files_names;
    std::cout << "Please enter names of files you want to concatenate and display: " << std::endl
            << "Names are separated by spaces. Different types of files might not be concatenated" << std::endl
            << "Use *.[extension] to choose all files with that extension in the current directory." << std::endl
            << "Your Input files: ";
    std::cin.ignore();
    std::getline(std::cin, files_names);

    std::string merged_filename;
    std::cout << "Please enter a name for your Output file: ";
    std::getline(std::cin, merged_filename);

    std::string command = "type " + files_names + " > " + merged_filename;
    int concatResult = system(command.c_str());
    if (concatResult != 0) {
        // Handle error if concatenation fails
        // For example, print an error message or exit the program
        return false;
    }
    return true;
}

int main() {
    bool running_flag = true;
    while (running_flag) {
        int option;
        std::cout << "----------------------------------------------------------------" << std::endl
                << "Input a number to choose what you want to do:" << std::endl
                << "1. List directory contents" << std::endl
                << "2. Print working directory" << std::endl
                << "3. Create new directory in the current directory" << std::endl
                << "4. Display a message" << std::endl
                << "5. Concatenate and display content of a file" << std::endl
                << "6. Exit" << std::endl
                << "What is your choice? ";
        std::cin >> option;
        while(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Bad entry. Enter a NUMBER: ";
            std::cin >> option;
        }

        switch (option) {
            case 1:
                list_dir_contents();
                break;
            case 2:
                print_dir();
                break;
            case 3:
                if (!create_dir()) {
                    return 1;
                }
                break;
            case 4:
                display_message();
                break;
            case 5:
                if (!concatenate_files()) {
                    return 1;
                }
                break;
            case 6:
                std::cout << "Exiting..." << std::endl;
                running_flag = false;
                break;
            default:
                std::cout << "Error: Unknown option!!! Please try again." << std::endl;
                continue;
        }
    }
    std::cout << "Program ended!";
    return 0;
}