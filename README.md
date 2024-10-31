<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/Niks-Kozlovs/ToDoList">
    <img src="Resources/Logo.png" alt="Logo" width="250">
  </a>

  <h3 align="center">C++ To-Do List</h3>

  <p align="center">
    A simple to-do list created in C++/CLI, refactored to showcase improvements in coding skills developed over the past 7+ years.
    <br />
    <a href="https://github.com/Niks-Kozlovs/ToDoList/tree/master">View Original Version</a> ·
    <a href="https://github.com/Niks-Kozlovs/ToDoList/issues/new">Report Bug</a> ·
    <a href="https://github.com/Niks-Kozlovs/ToDoList/issues/new?labels=enhancement">Request Feature</a>
  </p>
</div>

---

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#about-the-project">About The Project</a></li>
    <li><a href="#features">Features</a></li>
    <li><a href="#improvements">Improvements</a></li>
    <li><a href="#built-with">Built With</a></li>
    <li><a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#build">Build</a></li>
      </ul>
    </li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>

---

## About The Project

![Product Screenshot][product-screenshot]

This repository features a refactored version of a To-Do List app originally created as an assignment. Refactoring this C++ project provided an opportunity to explore code improvements and modern design principles, offering insights into how my skills have evolved over time.

## Features

- Create to-do lists at a specified location.
- Set a due date and time to monitor time remaining before deadlines.
- Assign custom priority levels to tasks for easier prioritization.
- Group tasks into multiple lists for better organization.
- Sort and filter tasks within lists.
- Lists are stored as local text files for easy access outside the app, following [Obsidian's](https://obsidian.md/about) markdown principles.

## Improvements

This version focuses on code quality, organization, and efficiency, with key updates:

- **MVC Design Pattern**: Adopts the MVC pattern for clearer file structure and better separation of logic and user interface.
- **Object-Oriented Design**: Replaces hash tables with classes to support a cleaner, modular OOP approach.
- **Reduced Bugs and Enhanced Usability**: The improved structure makes task-loading and other processes simpler and more reliable, often requiring only minimal parameter adjustments.
- **Less Code, Greater Efficiency**: Implements the DRY (Don’t Repeat Yourself) principle, significantly reducing redundant code.
- **Simplified Logic**: Adopts KISS (Keep It Simple, Stupid) principles by using built-in libraries for date and time management, replacing the manual, error-prone implementations in the original code.
- **Improved Naming Conventions**: Variables and functions are now named more intuitively for easier understanding and navigation.

---

## Built With

- ![CPP][CPP]

---

## Getting Started

To run this app, ensure you have [Visual Studio](https://visualstudio.microsoft.com/) with `Desktop development with C++` installed.

### Prerequisites

- Visual Studio with the Desktop Development with C++ workload.

### Build

1. Open the project in Visual Studio.
2. Press `F5` to build and launch.

---

## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

---

## Contact

Niks Kozlovs - [@NiksKozlovs](https://x.com/NiksKozlovs) - kozlovs.niks1@gmail.com

[product-screenshot]: Resources/ProjectImage.png
[CPP]: https://img.shields.io/badge/-C++-blue?logo=cplusplus&style=for-the-badge
