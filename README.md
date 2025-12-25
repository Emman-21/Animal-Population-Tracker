<div align="center">
🐾✨ ANIMAL POPULATION TRACKER ✨🐾
A Console-Based C++ Population Monitoring System
</div>
📌 1. Project Title

Animal Population Tracker (C++ Console Application)

📝 2. Description / Overview

The Animal Population Tracker is a C++ console application designed to store, manage, and analyze animal population data across multiple years. It provides an interactive menu that allows users to add, search, delete, and display animal records, while automatically saving data to a file for future access. The system also performs population trend analysis by computing yearly percentage changes, helping users identify whether an animal population is increasing, decreasing, or stable.

🔄 3. CRUD Operations & Program Functionality
🟢 CREATE — Add Animal Species

✨ Allows users to insert a new animal record
✔ Enter animal name
✔ Input number of years (2–10)
✔ Provide population per year
✔ Automatically stored in a stack
✔ Data saved to animals.txt

📈 Population trends and summary are displayed immediately after insertion.

🔵 READ — View and Search Records
🔍 Search Animal Species

✨ Finds a specific animal by name
✔ Displays yearly population
✔ Shows percentage change per year
✔ Identifies overall trend
📈 Increasing | 📉 Decreasing | ➖ Stable

📊 Display All Animal Species

✨ Displays all stored animal data
✔ Uses stack reversal for correct order
✔ Each animal includes a detailed summary
✔ Clean and formatted console output

🔴 DELETE — Remove Animal Species

✨ Deletes an animal record by name
✔ Searches through the stack
✔ Removes the matched entry
✔ Restores remaining records properly
✔ Updates the saved file automatically

💾 PERSISTENCE — File Handling

✨ Ensures data is not lost
✔ Automatically saves records
✔ Loads data from file on startup
✔ Uses animals.txt as storage

🧩 4. Program Structure
🛠️ Main Components

MainInfos (struct)
Stores animal name, number of years, and population values

stack<MainInfos>
Manages animal records using LIFO order

Core Functions

displayAnimal() → shows trends & summary

savetoFile() → saves data

loadFromfile() → loads data

main() → controls program flow

📁 System Flow
User Input
   ↓
Stack (Animal Records)
   ↓
Trend Analysis
   ↓
animals.txt (File Storage)

▶️ 5. How to Run the Program
🧱 Step 1: Compile
g++ main.cpp -o animal_tracker

🚀 Step 2: Run
./animal_tracker


📌 The program automatically creates and loads animals.txt.

🖥️ 6. Sample Output
🐾 ANIMAL POPULATION TRACKER 🐾

Animal: Elephant Population Trends

Year        Population      Change(%)
2021        4150            -
2022        4300            3.61%
2023        4450            3.49%

SUMMARY
📈 Overall Trend: INCREASING
🔥 Highest change occurred between 2021 and 2022

👤 7. Author and Acknowledgement
✍️ Author

Emman Borillo

🙏 Acknowledgement

Special thanks to the instructor for guidance and to classmates and learning resources that contributed to the understanding of C++ data structures, file handling, and logical program design.

🌱 8. Other Sections
🚀 a. Future Enhancements

✨ Convert to full class-based OOP design
✨ Add update/edit functionality
✨ Implement sorting and filtering
✨ Improve search (case-insensitive)
✨ Add graphical visualization

📚 b. References

📖 C++ Documentation — cplusplus.com
📦 STL Stack & File Handling Tutorials
🎓 Course Lecture Materials

<div align="center">

🌟 Thank you for using the Animal Population Tracker! 🌟

</div>
