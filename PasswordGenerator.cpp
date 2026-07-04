#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;
string passwordStrength(int length, string password)
{
    int upperCount = 0;
    int lowerCount = 0;
    int numberCount = 0;
    int symbolCount = 0;
    int types = 0;
    for (int i = 0; i < length; i++)
    {
        if (isupper(password[i])) {
            upperCount++;
        }
        else if (islower(password[i])) {
            lowerCount++;
        }
        else if (isdigit(password[i])) {
            numberCount++;
        }
        else {
            symbolCount++;
        }
    }
    if (upperCount > 0) {
        types++;
    }
    if (lowerCount > 0) {
        types++;
    }
    if (numberCount > 0) {
        types++;
    }
    if (symbolCount > 0) {
        types++;
    }

    if (length < 8 || types == 1) {
        return "Strength: Weak\n";
    }
    else if (length < 12 || types <= 2) {
        return "Strength: Medium\n";
    }
    else {
        return "Strength: Strong\n";
    }
}
int main()
{
    srand(time(0));
    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lower = "abcdefghijklmnopqrstuvwxyz";
    string number = "0123456789";
    string symbol = "!@#$%^&*()_+-=";
    char choice;
    while (1)
    {
        int num, lengths, passwordCount;
        string chars = "";
        cout << "===== Password Generator =====\n";
        cout << "1. Generate Password\n";
        cout << "2. Exit\n";
        cout << "Enter your Choice: ";
        cin >> num;
        if (num == 1)
        {
            cout << "Enter password length: ";
            cin >> lengths;

            if (lengths > 0)
            {
                cout << "Include Uppercase? (Y/N): ";
                cin >> choice;
                if (choice == 'Y' || choice == 'y')
                    chars += upper;
                cout << "Include Lowercase? (Y/N): ";
                cin >> choice;
                if (choice == 'Y' || choice == 'y')
                    chars += lower;
                cout << "Include Numbers? (Y/N): ";
                cin >> choice;
                if (choice == 'Y' || choice == 'y')
                    chars += number;
                cout << "Include Symbols? (Y/N): ";
                cin >> choice;
                if (choice == 'Y' || choice == 'y')
                    chars += symbol;
                if (chars.empty())
                {
                    cout << "You must select at least one character type.\n";
                    continue;
                }
                cout << "Passwords Count: ";
                cin >> passwordCount;
                if (passwordCount > 0)
                {
                    for (int j = 0; j < passwordCount; j++)
                    {
                        string password = "";
                        for (int i = 0; i < lengths; i++)
                        {
                            int index = rand() % chars.length();
                            password += chars[index];
                        }
                        cout << "Generated Password: " << password << endl;
                        cout << passwordStrength(lengths, password);
                    }
                }
                else
                {
                    cout << "Password Count must be greater than 0.\n";
                }
            }
            else
            {
                cout << "Password length must be greater than 0.\n";
            }
        }
        else if (num == 2)
        {
            break;
        }
        else
        {
            cout << "Invalid Choice.\n";
        }
    }
    return 0;
}