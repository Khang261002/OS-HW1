# OS-HW1

## Description
This C++ program implements a simple shell command utility that allows users to interact with various file and directory operations. The program provides a menu-driven interface with options to perform actions such as listing directory contents, printing the working directory, creating and deleting directories, displaying messages, and concatenating files.

## Instructions for Use
1. **Compilation:**
   - Compile the source code using a C++ compiler. For example:
     ```bash
     g++ HW1.cpp -o shell_utility
     ```

2. **Execution:**
   - Run the compiled executable to start the program:
     ```bash
     ./shell_utility
     ```

3. **Menu Options:**
   - The program presents a menu with the following options:
     ```
     1. List directory contents
     2. Print working directory
     3. Create new directory in the current directory
     4. Display a message
     5. Concatenate and display content of a file
     6. Exit
     ```
   - Choose an option by entering the corresponding number.

4. **Notes:**
   - When entering file or directory names with spaces, the program handles it appropriately.
   - The program uses system commands, so ensure that the commands (`dir`, `cd`, `mkdir`, `rmdir`, `echo`, `type`) are available in the system environment.
