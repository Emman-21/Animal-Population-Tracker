<div align="center">

# 🐕Animal Population Tracker🐾

A console-based C++ application for tracking and analyzing animal population trends across multiple years.

</div>

## 👀Overview

The Animal Population Tracker is a comprehensive C++ console application designed to help researchers, conservationists, and wildlife enthusiasts record, manage, and analyze population data of different animal species over time. The system provides an intuitive menu-driven interface that enables users to perform complete CRUD operations while maintaining persistent data storage.

By automating population trend analysis through yearly percentage change calculations, the application helps identify whether animal populations are increasing, decreasing, or remaining stable—providing valuable insights for conservation efforts and wildlife management.

## 🔍 Features

### 🙉 Core Functionality

- **🔹Add Animal Species** - Register new animal population records with multi-year data tracking (2-10 years)
- **🔹Search Records** - Query specific animal species and view detailed population statistics
- **🔹Delete Records** - Remove obsolete or incorrect animal data entries
- **🔹Display All Records** - View comprehensive population tables for all tracked species
- **🔹Persistent Storage** - Automatic file-based data persistence using `animals.txt`
- **🔹Trend Analysis** - Automated calculation of population changes and trend identification

### 🥸 Population Analysis

The system automatically calculates:
- Year-over-year percentage changes
- Overall population trends (Increasing/Decreasing/Stable)
- Highest percentage change periods
- Comprehensive statistical summaries

## 🎯 Technical Architecture

### ♦️ Project Structure
```
AnimalPopulationTracker/
│
├── README.md                    # Project documentation
├── animals.txt                  # Persistent data storage
├── main.cpp                     # Main source code
│
├── Functions/
│   ├── warmGreetings()          # Welcome message display
│   ├── farewell_Greetings()     # Exit message display
│   ├── displayAnimal()          # Animal data visualization
│   ├── savetoFile()             # Data persistence handler
│   └── loadFromfile()           # Data loading handler
│
└── Data Structures/
    └── stack<MainInfos>         # Primary data storage structure
```

### ♦️ CRUD Operations

| Operation | Functionality | Status |
|-----------|--------------|--------|
| **Create** | Add new animal species and population data | ✅ Implemented |
| **Read** | Search and display animal records | ✅ Implemented |
| **Update** | Modify existing animal records | 🔄 Planned |
| **Delete** | Remove animal species from records | ✅ Implemented |

### ♦️ Data Flow
```
User Input → Menu System → stack<MainInfos> → Population Analysis → animals.txt
                                    ↑                                      ↓
                                    └──────────── Data Loading ────────────┘
```

## 🗺️ Getting Started

### 🔹Prerequisites

- C++ compiler (GCC 7.0+ or equivalent)
- Standard C++ Library
- Terminal/Command Line Interface

### 🔹 Installation

1. Clone or download the project repository
2. Navigate to the project directory

### 🔹 Compilation
```bash
g++ main.cpp -o animal_tracker
```

### 🔹 Execution
```bash
./animal_tracker
```

The program will automatically create `animals.txt` if it doesn't exist and load any previously saved data.

## 👤 Usage Example

### ♦️ Sample Input
```
Animal Name: Elephant
Number of Years: 3

Year 2021 Population: 4150
Year 2022 Population: 4300
Year 2023 Population: 4450
```

### ♦️ Sample Output
```
=============================================================================
            WELCOME TO THE ANIMAL POPULATION TRACKER
=============================================================================

Animal: Elephant Population Trends

Year        Population      Change(%)
--------------------------------------------
2021        4150            -
2022        4300            +3.61%
2023        4450            +3.49%

-------------------------------- SUMMARY --------------------------------

Overall Trend: INCREASING
Highest percentage change occurred between 2021 and 2022
```

## ♦️ Future Enhancements

The following improvements are planned for future releases:

- [ ] Full object-oriented programming (OOP) class-based architecture
- [ ] Update/Edit functionality for existing records
- [ ] Advanced sorting and filtering capabilities
- [ ] Case-insensitive search functionality
- [ ] Graphical visualization of population trends
- [ ] Export functionality (CSV, JSON formats)
- [ ] Database integration (SQLite/MySQL)
- [ ] Data validation and error handling improvements
- [ ] Multi-user support with authentication

## ♦️ Contributing

Contributions are welcome! If you'd like to improve this project, please:

1. Fork the repository
2. Create a feature branch
3. Commit your changes
4. Submit a pull request

## 📚 Acknowledgments

**Instructor:** Special thanks to our instructor for providing guidance and support in understanding C++ fundamentals, data structures, and file handling techniques that made this project possible.

**Author:** Emman Borillo

## 🪪 License

This project is developed for educational purposes.

## 📞 Contact

For questions, suggestions, or feedback, please contact the project author.

---

<div align="center">

**⭐ Thank you for using the Animal Population Tracker! ⭐**

</div>
