// 1) DevelopaMenudrivenprogramtodemonstrate the followingoperations ofArrays
// ——MENU——-
// 1.CREATE
// 2.DISPLAY
// 3.INSERT
// 4.DELETE
// 5. LINEAR SEARCH
// 6. EXIT

#include <iostream>
using namespace std;

int main() {
    int arr[100];
    int n = 0;
    int choice, pos, value, search, found;

    do {
        cout << "\n\n--- MENU ---\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";

        cout << "Enter your choice: ";
        cin >> choice;

    switch (choice) {

      case 1:
            cout << "Enter number of elements: ";
            cin >> n;

            cout << "Enter array elements:\n";
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }

            cout << "Array created successfully.";
            break;

    case 2:
            cout << "Array elements: ";
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            break;

     case 3:
            cout << "Enter position: ";
            cin >> pos;

            cout << "Enter value: ";
            cin >> value;
    for (int i = n; i >= pos; i--) {
                arr[i] = arr[i - 1];
            }

        arr[pos - 1] = value;
            n++;

        cout << "Element inserted successfully.";
            break;

        case 4:
            cout << "Enter position to delete: ";
            cin >> pos;

            // Shift elements to the left
            for (int i = pos - 1; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }

            n--;

     cout << "Element deleted successfully.";
        break;
        case 5:
            cout << "Enter element to search: ";
            cin >> search;

            found = 0;

    for (int i = 0; i < n; i++) {
         if (arr[i] == search) {
        cout << "Element found at position " << i + 1;
             found = 1;
               break;
                }
            }

    if (found == 0) {
         cout << "Element not found.";
            }

          break;

    case 6:
          cout << "Program ended.";
            break;

        default:
            cout << "Invalid choice!";
        }

    } while (choice != 6);

    return 0;
}