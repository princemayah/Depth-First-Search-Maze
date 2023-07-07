# Depth-First Search Maze

A C++ program that generates a maze using a randomized Prim's algorithm and connects neighboring cells using a depth-first search.

## Table of Contents
- [Introduction](#introduction)
- [Usage](#usage)
- [Example](#example)
- [Contributing](#contributing)
- [License](#license)


## Introduction

This program generates a maze by implementing a randomized Prim's algorithm. The maze is represented as a grid of cells, where each cell can be a wall or an open path. The algorithm randomly carves paths between cells until all cells have been visited. Then, a depth-first search is used to connect all cells in the maze.

The program provides a command-line interface for the user to input the row width, row height, and seed value for generating the maze. The resulting maze is printed to the console.

## Usage

To use this program, follow these steps:

1. Clone the repository or download the source code files
2. Compile the code using a C++ compiler
3. Run the compiled program
4. Enter the desired row width, row height, and seed value when prompted
5. The maze will be generated, connected, and printed to the console

## Example

Here's an example of running the program and generating a maze:

```cpp
Enter the row width: 25
Enter the row height: 25
Enter the seed value: 123

Maze:

   █████████████████████████
 █ █ █ █ █ █ █ █ █ █ █ █ █ █
██         █ █ █         ██
█   █ █ █ █     █ █   █ █ █
██ █ █ █ █       █   █ █ ██
█         █     █ █       █
██       █ █ █   █ █     ██
█     █     █   █   █ █   █
██ █ █     █         █ █ ██
█   █ █ █   █       █     █
██     █ █   █ █ █       ██
█     █     █ █ █         █
██ █ █         █ █ █ █ █ ██
█   █ █   █   █   █ █ █   █
██ █ █ █   █   █ █       ██
█ █       █   █   █       █
██         █     █   █ █ ██
█ █   █   █   █ █ █   █ █ █
██     █ █   █ █ █     █ ██
█ █   █   █ █     █   █   █
██   █ █ █ █           █ ██
█ █     █   █         █   █
██     █       █ █ █ █ █ ██
█   █   █       █ █ █     █
██ █       █ █           ██
█ █ █ █ █ █ █ █ █ █ █ █ █ █
███████████████████████
```

## Contributing

Contributions are welcomed! If you find any issues or have suggestions for improvement, please open an issue on the repository or submit a pull request. Your feedback and contributions will be greatly appreciated. 

## License

This code is licensed under the MIT License.

