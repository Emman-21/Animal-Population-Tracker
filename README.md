<div align="center"> <img src="https://github.com/user-attachments/assets/fb320ea0-0b1c-49c7-bac1-203125de2bab" width="1000"> </div>
🐾✨ Animal Population Tracker ✨🐾

Animal Population Tracker – A console-based C++ application for tracking and analyzing animal population trends across multiple years.

🌿 Description / Overview

The Animal Population Tracker is a C++ console application designed to help users record, manage, and analyze population data of different animal species over time.
It provides an interactive menu system that allows users to add, search, delete, and display animal records while automatically saving data for future use.

The system also performs population trend analysis by computing yearly percentage changes, allowing users to determine whether an animal population is increasing, decreasing, or stable.

This project helps solve the problem of manual data tracking by organizing records efficiently using data structures and file handling.

🧑‍💻 Program Structure

Main Program – Serves as the entry point, handles user input, menu navigation, and calls all supporting functions.

AnimalPopulationTracker/
│
├── README.md
│
├── animals.txt              (saved animal records)
│
├── main.cpp                 (main source code)
│
├── Functions
│   ├── warmGreetings()
│   ├── farewell_Greetings()
│   ├── displayAnimal()
│   ├── savetoFile()
│   └── loadFromfile()
│
└── Data Structure
    └── stack<MainInfos>

🗝️ Key Features
➕ 1. Add Animal Species

Register a new animal population record by providing:

Animal name

Number of years (2–10)

Population data per year

✔ Automatically stored in a stack
✔ Saved to animals.txt
✔ Displays population trend and summary immediately

🔎 2. Search Animal Species

Search for a specific animal by name and view:

Yearly population data

Percentage change per year

Overall trend:

📈 Increasing

📉 Decreasing

➖ Stable

🗑️ 3. Delete Animal Species

Remove an existing animal record:

Searches through stored data

Deletes the selected animal

Restores remaining records properly

Updates the saved file automatically

📊 4. Display All Animal Species

Shows all stored animal records:

Maintains insertion order using stack reversal

Displays full population tables

Includes trend summary for each animal

💾 5. File Handling Integration

The system automatically:

Loads saved data at program startup

Saves all changes instantly

Uses animals.txt for persistent storage

🔄 CRUD Operations Summary
Operation	Functionality
Create	Add new animal species and population data
Read	Search and display animal records
Update	(Planned for future enhancement)
Delete	Remove animal species from records
🧩 Program Logic Overview
User Input
   ↓
stack<MainInfos>
   ↓
Population Analysis
   ↓
animals.txt (Persistent Storage)

▶️ How to Run the Program
🧱 Step 1: Compile
g++ main.cpp -o animal_tracker

🚀 Step 2: Run
./animal_tracker


📌 The program automatically creates and loads animals.txt.

🌻 Sample Output
Start
=============================================================================
            WELCOME TO THE ANIMAL POPULATION TRACKER
=============================================================================

Animal: Elephant Population Trends

Year        Population      Change(%)
2021        4150            -
2022        4300            3.61%
2023        4450            3.49%

-------------------------------- SUMMARY --------------------------------

Overall Trend: INCREASING
Highest percentage change occurred between 2021 and 2022

🏆 Acknowledgements
👩‍🏫 Instructor

Special thanks to our instructor for guidance and support in understanding C++ fundamentals, data structures, and file handling, which made the successful completion of this project possible.

👨‍🎓 Author

Emman Borillo

🔨 Future Enhancements

While the current system effectively manages population data, future improvements may include:

Converting the program into a full OOP class-based design

Adding update/edit functionality for records

Implementing sorting and filtering

Case-insensitive searching

Adding graphical visualization of population trends

Migrating from text files to a database system

🌟 Thank you for using the Animal Population Tracker! 🌟
