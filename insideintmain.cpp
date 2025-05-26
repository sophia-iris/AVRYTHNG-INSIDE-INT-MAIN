#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;

    cout << "Enter number of transactions: ";
    cin >> n;

    if (n == 0) {
        cout << "No transactions to process." << endl;
        return 0;
    }

    string* dates = new string[n];
    double* amounts = new double[n];
    string* descriptions = new string[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter date (YYYY-MM-DD): ";
        cin >> dates[i];
        cout << "Enter amount: ";
        cin >> amounts[i];
        cout << "Enter description: ";
        cin >> descriptions[i];
    }

    double netBalance = 0, totalDeposits = 0, totalWithdrawals = 0;
    for (int i = 0; i < n; i++) {
        netBalance += amounts[i];
        if (amounts[i] > 0)
            totalDeposits += amounts[i];
        else
            totalWithdrawals += amounts[i];
    }

    double threshold;
    cout << "Enter withdrawal threshold: ";
    cin >> threshold;

    cout << "Transactions exceeding withdrawal threshold: ";
    for (int i = 0; i < n; i++) {
        if (amounts[i] <= -threshold) {
            cout << dates[i] << " | " << amounts[i] << " | " << descriptions[i] << endl;
        }
    }

    cout << "Total transactions: " << n << endl;
    cout << "Net balance: " << netBalance << endl;
    cout << "Total deposits: " << totalDeposits << endl;
    cout << "Total withdrawals: " << totalWithdrawals << endl;

    delete[] dates;
    delete[] amounts;
    delete[] descriptions;

    return 0;
}


