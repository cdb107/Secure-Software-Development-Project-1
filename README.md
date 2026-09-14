# Secure-Software-Development-Project-1

## How to Run the Project
* Extract all submitted files into one folder.

    Run `LoginProgram.exe` from Windows File Explorer, or open PowerShell in the extracted folder and run:

    ```powershell
    .\LoginProgram.exe

    The test accounts are:
    Username  |   Password
    scientist	Scientist1
    engineer	Engineer2
    security	Security3

    - Use 1234567890 as a valid simulated MFA token.

## Running the tests
* Compile and run the validation tests:

    g++ tests/ValidationTest.cpp Validation.cpp -o ValidationTest.exe
    .\ValidationTest.exe

    Compile and run the login tests:

    g++ tests/LoginTest.cpp Database.cpp Validation.cpp usercreation.cpp -o LoginTest.exe
    .\LoginTest.exe

    A test result of 1 means the input passed. A result of 0 means the input failed.

## Requirements
* Database Requirements
    - Array for Username / Password combinations (Use String types for both, Possibly make User class to keep everything separated)
    - Passwords must be output and stored in a .txt file

## Program Behaviors
* Login requirements
    - Prompt for username (Visible)
    - Prompt for Password (Not Visible, either '*' or blank)
    - Must compare entries with database
    - if successful: present welcome message
    - if not: handle in "Secure Software Development" way
    
* Password Policy Methods
    * Method 1 - SQL Injection
       - Check for following characters: / - ; "
       - If any are present, the input fails
         
    * Method 2 - Password Policy
       - 8-12 characters long
       - Minimum one each of an uppercase and lowercase character
       - Minimum one numeric letter (1, 2, 3, etc)

    * Method 3 - Integer Overflow
       - If using Java use int data type
       - If using C++ use signed int data type
      
