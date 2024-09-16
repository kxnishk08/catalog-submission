README.txt

Overview
--------
This program performs Lagrange interpolation to find a secret constant term from a set of points provided in JSON format. It uses the JsonCpp library to parse JSON input.

Prerequisites
-------------
1. **JsonCpp Library**: This code depends on the JsonCpp library for JSON parsing. You need to install this library before compiling and running the program.

   - **On Ubuntu/Debian**:
     sudo apt-get install libjsoncpp-dev

   - **On macOS**:
     brew install jsoncpp

   - **On Windows**:
     Download and build the JsonCpp library from its GitHub repository: https://github.com/open-source-parsers/jsoncpp

2. **C++ Compiler**: You need a C++ compiler that supports C++11 or later. GCC and Clang are recommended for Unix-like systems, and MSVC is recommended for Windows.

Building the Program
---------------------
To compile the program, link it with the JsonCpp library. Use the following commands based on your system:

- **On Unix-like systems (Linux/macOS)**:
  g++ -std=c++11 -o lagrange_interpolation lagrange_interpolation.cpp -ljsoncpp

- **On Windows**:
  Adjust the compiler command according to your environment. Specify the path to the JsonCpp library and include directories if needed.

Running the Program
--------------------
1. **Prepare JSON Input**: Create a JSON string with points for interpolation in the following format:

   {
       "keys": {
           "n": 4,
           "k": 3
       },
       "1": {
           "base": "10",
           "value": "4"
       },
       "2": {
           "base": "2",
           "value": "111"
       },
       "3": {
           "base": "10",
           "value": "12"
       },
       "6": {
           "base": "4",
           "value": "213"
       }
   }

   `"n"` is the number of points and `"k"` is the number of points used for interpolation. Each point is defined by its `x` value, the base, and the value in that base.

2. **Run the Program**: Execute the compiled program. It will prompt you to enter the JSON input.

   ./lagrange_interpolation

   Paste the JSON input when prompted and press Enter. The program will output the computed secret constant term.

Example
-------
Enter JSON input:
{
    "keys": {
        "n": 4,
        "k": 3
    },
    "1": {
        "base": "10",
        "value": "4"
    },
    "2": {
        "base": "2",
        "value": "111"
    },
    "3": {
        "base": "10",
        "value": "12"
    },
    "6": {
        "base": "4",
        "value": "213"
    }
}

Output:
The constant term (secret) is: <computed_value>

Troubleshooting
---------------
- **Error Parsing JSON Input**: Ensure the JSON is properly formatted. Use a JSON validator to check for syntax errors.
- **Library Issues**: If you encounter issues with JsonCpp, ensure it is correctly installed and linked.

License
-------
This project is licensed under the MIT License. See the LICENSE file for details.
