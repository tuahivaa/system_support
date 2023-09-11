REPORT HW1

INTRODUCTION:

    This C++ program is designed to process a CSV file containing dates and their respective rates. 
    The program reads this data and stores it in a hashmap for efficient retrieval. 
    Users can interact with the program to look up rates for specific dates, calculate average rates, and find the difference between a specific date's rate and the calculated average rate. 
    Additionally, users can exit the program at any time by entering '-z'.

HOW TO RUN THE CODE:
	There are 2 ways:

        EASY way: run the "homework_1.exe" execution file, and the application will run in a terminal
        
        HARD way: 
            To run your "homework_1.cpp" file, you'll need to compile it using a C++ compiler and then execute the compiled binary. Here are the step-by-step instructions to run your C++ program:

                Step 1: Install a C++ Compiler

                    If you don't already have a C++ compiler installed on your computer, you'll need to install one. 
                    A popular C++ compiler is g++, which is available on most Unix-based systems (Linux, macOS) and can also be used on Windows with tools like MinGW. 
                    You can check if g++ is installed by opening a terminal/command prompt and typing: g++ --version

                If it's not installed, you can install it based on your operating system.

                Linux: You can typically install g++ using your package manager. For example, on Ubuntu, you can use: 
                    
                    sudo apt-get update
                    sudo apt-get install g++

                macOS: You can install g++ using Homebrew if you have it installed:

                    brew install gcc
                
                Windows: You can use MinGW to install g++. You can download the MinGW installer from the official website: https://osdn.net/projects/mingw/

                Step 2: Create a Directory

                    Create a directory (folder) for your project and place your "homework_1.cpp" file in this directory. 
                    This makes it easier to manage your project files.

                Step 3: Open a Terminal/Command Prompt

                    Open a terminal or command prompt on your computer. You will use this terminal to compile and run your C++ program.

                Step 4: Navigate to the Directory

                    Use the cd command to navigate to the directory where your "homework_1.cpp" file is located. For example, if your file is in the "Documents" folder: cd Documents

                Step 5: Compile the C++ Program

                    Compile your C++ program using the g++ command followed by the source code file name ("homework_1.cpp") and an output file name. 
                    The output file can be named anything you like, but conventionally, it's named "a.out" on Unix-based systems. On Windows, you can name it "homework_1.exe" if you prefer.
                    Here's the command to compile your program: g++ homework_1.cpp -o homework_1

                    This command tells the compiler to compile "homework_1.cpp" and create an output file named "homework_1" (or "homework_1.exe" on Windows).

                Step 6: Run the Compiled Program

                    After successfully compiling your program, you can run it. Use the following command:

                    On Unix-based systems (Linux/macOS): ./homework_1
                    On Windows: homework_1.exe

                    Replace "homework_1" with the name you chose for the output file in the compilation step.

                Step 7: Interact with Your Program

                    Once you run your program, it should start executing, and you can interact with it as described in your program's functionality.

                Step 8: Exit the Program

                    To exit the program, follow the instructions you provided in your code, which is typically by entering CONTROL-Z or another specified command.

                    That's it! You've successfully compiled and run your "homework_1.cpp" file.

                

EXPLANATION of my functions:

average():
    Since I'm using a hasmap, I am passing my hasmap that has the date for key, and rate for value, and I'm passing the user's input date.
    From there, it's pretty straighforward, I'm looking in the hasmap if the user's input date as it loops through the hasmap. Looping through It
    allows me to calculate the average of the rate, when the user's input date is reach it stops.
    Within the for-loop I have a counter that I use to divide the sum of the rate so it has an accurate average.

find_rate():
    I pass my hasmap of <date,rate>, and the user's input date.
    Since it's a hasmap, I can see if the user's input date exist as a key, if it does, I return the value associated with it,
    if not, I return -1.0
    I return -1.0 so later if it returned a value less than 0, we know no dates was found, then we can print an error message.

main():
    I read through the file, I skip the header, I don't really do anything with it, I just skip it.
    then in a while-loop, until the user inputs the EOF, it will prompt the user for a date in a correct format, I use the above function 
    to find the rate associated with the date, and to find the average.
    When the user prompts an EOF, it exit the program with a message that says so.
    


CONCLUSION:

    This C++ program provides a user-friendly interface for accessing and analyzing historical rate data stored in a CSV file. 
    Users can efficiently look up rates, calculate average rates, and compare specific rates to historical averages. 
    The program offers valuable insights for users working with financial data and can be easily terminated with the '-z' command.