// Week 1 CADT Homework
#include <iostream>

using namespace std;

int counter = 1;
int arr[100] = {1,2,3,4,5}; // Assume we have 5 elements in the array with 100 max elements in array

// Print the results of the changed array
void PrintChangedArray() {
    cout << "New Values: ";
    for (int i = 0; i < 5 + (counter - 1) ; i++)
    {
        if (arr[i] != '\0')
        {
            cout << arr[i] << " " ;
        }
    }
    cout << endl;   
}

// Replace and remove element in array
void ReplaceandDelete(char selection, int arrIndex) {
    int temparray[5 + counter];
    int count = 0;

    switch (selection)
    {
    case 'R':
        int newNumber;
        cout << "New Number: ";
        std::cin >> newNumber;


        // Check if said element in array is not \0
        if (arr[arrIndex] != '\0')
        {
            // Copy every shified number to a temp array
            for (int i = arrIndex; i < 5 + (counter - 1); i++)
            {
                temparray[count] = arr[i];
                count++;
            }

            count = 0;
            counter++;

            // Apply temp array to main array to complete shifing
            for (int i = arrIndex; i < 5 + (counter - 1); i++)
            {
                arr[i + 1] = temparray[count];
                count++;
            }
        } 

        // Place the number into said element in array
        arr[arrIndex] = newNumber;
        cout << "Replacing Number Sucessful" << endl;
        break;
    
    case 'D':
        // "Deletes" (Replaces) the said element in array with \0
        arr[arrIndex] = '\0';
        // counter--;
        cout << "Deleting Number Sucessful" << endl;
        break;
    }

    // Print results
    PrintChangedArray();
}

int main() {
    // Make some variables
    char selection;
    int arrIndex;
    bool madeInvaildChoice = false;

    // Asks for selection
    do
    {
        cout << "Choose an option: " << endl;
        cout << "(R)eplace an element in array" << endl;
        cout << "(D)elete an element in array" << endl;
        do
        {
            cout << "> ";
            std::cin >> selection;

            // Selector and making sure inputs don't go out of bounds
            switch (selection)
            {
            case 'R':
                // Replace an element in array
                cout << "Which element in array: ";
                std::cin >> arrIndex;

                // Prevents out of bounds
                if (arrIndex >= 0 && arrIndex <= 5 + (counter - 2))
                {
                    ReplaceandDelete(selection, arrIndex);
                    madeInvaildChoice = false;
                } else {
                    cout << "Out of Bounds" << endl;
                    madeInvaildChoice = true;
                }
            break;

            case 'D':
                // Deletes an element in array
                cout << "Which element in array: ";
                std::cin >> arrIndex;

                // Prevents out of bounds
                if (arrIndex >= 0 && arrIndex <= 5 + (counter - 2))
                {
                    ReplaceandDelete(selection, arrIndex);
                    madeInvaildChoice = false;
                } else {
                    cout << "Out of Bounds" << endl;
                    madeInvaildChoice = true;
                }
            break;

            default:
                cout << "Invaild Choice" << endl;
                madeInvaildChoice = true;
            break;
            }
        } while (madeInvaildChoice);
    } while (true); 
}