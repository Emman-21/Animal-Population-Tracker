#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <stack>
#include <cmath>
#include <limits>


using namespace std;

void warmGreetings()
{
    cout << "\033[1;33m";
    cout << "\t\t=============================================================================" << endl;
    cout << "\t\t\t\tWELCOME TO THE ANIMAL POPULATION TRACKER!\033[0m\n";
    cout << "\t\t\t\t\t       Description \n";
    cout << "\t     It is designed to monitor and manage the population data of various animal species.\n";
    cout << "\t   It allows users to add new animal records, search for specific species, delete entries,\n";
    cout << "\t           display all stored data, and save records to a file for future access.\n";
    cout << "\t\t\033[1;33m =============================================================================\n" << endl;
    cout << "\033[0m";
}

void farewell_Greetings()
{
    cout << "\033[1;33m";
    cout << "\t\t=============================================================================\n";
    cout << "\t\t\t     THANK YOU FOR USING THE ANIMAL POPULATION TRACKER! \n";
    cout << "\t\t=============================================================================\n";
    cout << "\033[0m";
}

struct MainInfos
{
    string animal;
    int numYears;
    int population[10];
};

stack<MainInfos> animalStack;

void displayAnimal(const MainInfos &info)
{
    int Startyear = 2025 - info.numYears;

    cout << "\t\t=============================================================================\n";
    cout << "\t\t\t\t\t" << info.animal << " POPULATION TRENDS\n";
    cout << "\t\t=============================================================================\n\n";

    cout << "\t\t            Year\t\tPopulation\t\tChange(%)\n";
    cout << "\t\t            " << Startyear << "\t\t  " << info.population[0] << "\t\t\t   -\n";

    for(int i = 1; i < info.numYears; i++)
    {
        int prev = info.population[i - 1];
        int curr = info.population[i];
        double change = ((double)(curr - prev) / prev) * 100.0;

        cout << "\t\t\t    " << Startyear + i << "\t\t  " << curr << "\t\t";
        cout << "\t " << fixed << setprecision(2) << change << "%\n";
    }

    cout << "\033[1;34m";
    cout << "\n\t\t--------------------------------SUMMARY--------------------------------------\n\n";
    cout << "\033[0m";

    string trend;
    int first = info.population[0];
    int last = info.population[info.numYears - 1];

    if(last > first)
    {
        trend = "\033[0;32mINCREASING\033[0m";
    }
    else if(last < first)
    {
        trend = "\033[0;31mDECREASING\033[0m";
    }
    else 
    {
        trend = "\033[0;36mSTABLE\033[0m";
    }

    cout << "\t\t - Overall Trend: " << trend << "\n\n";
    cout << "\t\t - The " << info.animal << " population is consistently " << trend << " over the years.\n\n";

    double maxChange = 0.0;
    int Year1 = 0, Year2 = 0;

    for(int i = 1; i < info.numYears; i++)
    {
        double tempchange = ((double)(info.population[i] - info.population[i-1]) / info.population[i-1]) * 100.0;
        if(abs(tempchange) > abs(maxChange))
        {
            maxChange = tempchange;
            Year1 = Startyear + i - 1;
            Year2 = Startyear + i;
        }
    }

    cout << "\t\t - The highest percentage change is between the year " << Year1 << " and " << Year2 << "\n";
    cout << "\n\t\t=============================================================================\n\n";
}

void savetoFile()
{
    ofstream saveFile("animals.txt");
    stack<MainInfos> tempstack = animalStack;

    while(!tempstack.empty())
    {
        MainInfos info = tempstack.top();
        tempstack.pop();

        saveFile << info.animal << endl;
        saveFile << info.numYears << endl;
        
        for(int i = 0; i < info.numYears; ++i)
        {
            saveFile << info.population[i];
            if(i < info.numYears - 1)
                saveFile << " ";
        }
        saveFile << endl;
    }
    saveFile.close();
}

void loadFromfile()
{
    ifstream loadFile("animals.txt");
    if(!loadFile)
        return;

    MainInfos info;

    while(getline(loadFile, info.animal))
    {
        loadFile >> info.numYears;
        for(int i = 0; i < info.numYears; ++i)
            loadFile >> info.population[i];
        loadFile.ignore(numeric_limits<streamsize>::max(), '\n');
        animalStack.push(info);
    }
    loadFile.close();
}

int main()
{
    loadFromfile();
    warmGreetings();

    int choice;

    do{
        cout << "\033[1;34m";
        cout << "\t\t\t\t  -----------------MENU-----------------\n";
        cout << "\t\t\t\t  1 Add Animal Species\n";
        cout << "\t\t\t\t  2 Search Animal Species\n";
        cout << "\t\t\t\t  3 Delete Animal Species\n";
        cout << "\t\t\t\t  4 Display All Animal Species\n";
        cout << "\t\t\t\t  5 Exit\n";
        cout << "\t\t\t\t  Enter option (1,2,3,4,5): ";
        cout << "\033[0m";

        if(!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n\t\t\t\033[1;31mInvalid Input. Please enter a number (1 - 5).\033[0m\n";
            cout << "\n\t\t=============================================================================\n\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;

        switch(choice)
        {
            case 1:
            {
                MainInfos info;
                
                cout << "\033[1;36m";
                cout << "\t\t=============================================================================\n";
                cout << "\t\t\t\t\t     INSERTING ANIMAL\n";
                cout << "\t\t=============================================================================\n\n";
                cout << "\033[0m";
                cout << "\t\tInsert an Animal Species: ";
                getline(cin, info.animal);

                cout << "\t\tEnter the number of years of population data (2 - 10): ";
                if(!(cin >> info.numYears))
                {
                    cout << "\n\t\t\t\033[1;31m   Invalid input. Number of years must be an integer.\033[0m\n";
                    cout << "\n\t\t=============================================================================\n\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                if(info.numYears < 2 || info.numYears > 10)
                {
                    cout << "\n\t\t\t\033[1;31m   Invalid number of years. Must be between 2 and 10.\033[0m\n\n";
                    cout << "\t\t=============================================================================\n\n";
                    break;
                }

                cout << endl;
                int Startyear = 2025 - info.numYears;

                for(int i = 0; i < info.numYears; i++)
                {
                    cout << "\t\tEnter the population for year " << Startyear + i << ": ";
                    
                    while(!(cin >> info.population[i]) || info.population[i] < 0)
                    {
                        cout << "\t\t\033[1;31mInvalid population number. \033[0mPlease enter a positive integer: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                animalStack.push(info);
                savetoFile();
                displayAnimal(info);
                break;
            }

            case 2:
            {
                if(animalStack.empty())
                {
                    cout << "\t\t=============================================================================\n";
                    cout << "\n\t\t\t\t\t   No animals to search.\n\n";
                    cout << "\t\t=============================================================================\n\n";
                    break;
                }

                string searchAnimal;
                cout << "\033[1;32m";
                cout << "\t\t=============================================================================\n";
                cout << "\t\t\t\t\tSEARCHING ANIMAL SPECIES\n";
                cout << "\t\t=============================================================================\n\n";
                cout << "\033[0m";
                cout << "\t\tSearch Animal Species: ";
                getline(cin, searchAnimal);
                cout << endl;

                stack<MainInfos> tempStack = animalStack;
                bool found = false;

                while(!tempStack.empty())
                {
                    if(tempStack.top().animal == searchAnimal)
                    {
                        displayAnimal(tempStack.top());
                        found = true;
                        break;
                    }
                    tempStack.pop();
                }

                if(!found)
                {
                    cout << "\t\t\t\t\t    Animal not found.\n\n";
                    cout << "\t\t=============================================================================\n\n";
                }
                break;
            }

            case 3:
            {
                if(animalStack.empty())
                {
                    cout << "\t\t=============================================================================\n";
                    cout << "\n\t\t\t\t\t   No animals to delete\n\n";
                    cout << "\t\t=============================================================================\n\n";
                    break;
                }

                string deleteAnimal;
                cout << "\033[0;31m";
                cout << "\t\t=============================================================================\n";
                cout << "\t\t\t\t\t  DELETE ANIMAL SPECIES\n";
                cout << "\t\t=============================================================================\n";
                cout << "\033[0m";
                cout << "\t\tEnter the name of animal you want to delete: ";
                getline(cin, deleteAnimal);

                stack<MainInfos> tempStack;
                bool found = false;

                while(!animalStack.empty())
                {
                    if(animalStack.top().animal == deleteAnimal)
                    {
                        animalStack.pop();
                        found = true;
                        cout << "\n\t\t\t\t\t\033[1;32m" << deleteAnimal << " deleted successfully!\033[0m\n";
                        cout << "\t\t=============================================================================\n\n";
                        break;
                    }
                    else
                    {
                        tempStack.push(animalStack.top());
                        animalStack.pop();
                    }
                }

                while(!tempStack.empty())
                {
                    animalStack.push(tempStack.top());
                    tempStack.pop();
                }

                if(!found)
                {
                    cout << "\n\t\t\t\t\t    Animal not found.\n\n";
                    cout << "\t\t=============================================================================\n\n";
                }
                savetoFile();
                break;
            }

            case 4:
            {
                if(animalStack.empty())
                {
                    cout << "\t\t=============================================================================\n";
                    cout << "\n\t\t\t\t    No animal species recorded yet.\n\n";
                    cout << "\t\t=============================================================================\n\n";
                    break;
                }

                stack<MainInfos> tempStack = animalStack;
                stack<MainInfos> reverseStack;
                
                cout << "\033[1;35m";
                cout << "\t\t=============================================================================\n";
                cout << "\t\t\t\tHERE ARE ALL OF THE ANIMALS YOU INSERTED\n";
                cout << "\t\t=============================================================================\n";
                cout << "\033[0m";

                while(!tempStack.empty())
                {
                    reverseStack.push(tempStack.top());
                    tempStack.pop();
                }

                while(!reverseStack.empty())
                {
                    displayAnimal(reverseStack.top());
                    reverseStack.pop();
                }
                break;
            }

            case 5:
            {
                farewell_Greetings();
                break;
            }

            default:
                cout << "\t\t=============================================================================\n\n";
                cout << "\t\t\t\033[1;31m     Invalid choice. Please enter a number from 1 to 5.\033[0m\n\n";
                cout << "\t\t=============================================================================\n\n";
                break;
        }

    }while(choice != 5);

    return 0;
}
