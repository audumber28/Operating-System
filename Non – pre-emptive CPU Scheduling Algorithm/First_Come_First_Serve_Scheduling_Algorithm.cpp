#include <iostream>
#include <iomanip>
using namespace std;

int order[10];

int average(int *matrix, int n) {
    int avg = 0;
    for (int i = 0; i < n; i++)
        avg += matrix[i];
    return avg / n;
}

void sort_arr(int arr[], int n) {
    int copy[n];
    for (int i = 0; i < n; i++) {
        order[i] = i;
        copy[i] = arr[i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (copy[i] > copy[j]) {
                int temp = copy[i];
                copy[i] = copy[j];
                copy[j] = temp;

                int t = order[i];
                order[i] = order[j];
                order[j] = t;
            }
        }
    }
}

void calc(int burst[], int arr[], int n) {
    sort_arr(arr, n);
    int complete[n], TAT[n], WT[n], time = 0;

    for (int i = 0; i < n; i++) {
        time += burst[order[i]];
        complete[order[i]] = time;
    }

    
    for (int i = 0; i < n; i++)
        TAT[i] = complete[i] - arr[i];
    for (int i = 0; i < n; i++)
        WT[i] = TAT[i] - burst[i];

    
    cout << "\nGantt Chart:\n";
    cout << " ";
    for (int i = 0; i < n; i++)
        cout << "-------";
    cout << "\n|";
    for (int i = 0; i < n; i++)
        cout << "  P" << order[i] + 1 << "  |";
    cout << "\n ";
    for (int i = 0; i < n; i++)
        cout << "-------";
    cout << "\n0";
    for (int i = 0; i < n; i++)
        cout << setw(7) << complete[order[i]];
    cout << "\n\n";

   
    cout << "Process\tBT\tAT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t"
             << burst[i] << "\t"
             << arr[i] << "\t"
             << TAT[i] << "\t"
             << WT[i] << endl;
    }

    
    cout << "\nAverage waiting time : " << average(WT, n);
    cout << "\nAverage turn-around time : " << average(TAT, n);
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int burst[n], arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << endl;
        cout << "Enter Burst Time: ";
        cin >> burst[i];
        cout << "Enter Arrival Time: ";
        cin >> arr[i];
    }

    cout << endl;
    calc(burst, arr, n);
    return 0;
}
