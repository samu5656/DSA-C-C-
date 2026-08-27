#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

bool compare(Process a, Process b) {
    if (a.arrivalTime == b.arrivalTime)
        return a.pid < b.pid;
    return a.arrivalTime < b.arrivalTime;
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

    // Input
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "\nProcess " << p[i].pid << endl;
        cout << "Arrival Time: ";
        cin >> p[i].arrivalTime;
        cout << "Burst Time: ";
        cin >> p[i].burstTime;
    }

    // Sort according to arrival time
    sort(p.begin(), p.end(), compare);

    int currentTime = 0;
    double totalWT = 0, totalTAT = 0;

    // FCFS Scheduling
    for (int i = 0; i < n; i++) {

        // CPU is idle until process arrives
        if (currentTime < p[i].arrivalTime)
            currentTime = p[i].arrivalTime;

        currentTime += p[i].burstTime;

        p[i].completionTime = currentTime;
        p[i].turnaroundTime = p[i].completionTime - p[i].arrivalTime;
        p[i].waitingTime = p[i].turnaroundTime - p[i].burstTime;

        totalWT += p[i].waitingTime;
        totalTAT += p[i].turnaroundTime;
    }

    // Output
    cout << left << setw(8) << "PID"
         << setw(8) << "AT"
         << setw(8) << "BT"
         << setw(8) << "CT"
         << setw(10) << "TAT"
         << setw(8) << "WT" << endl;

    for (auto process : p) {
        cout << left << setw(8) << process.pid
             << setw(8) << process.arrivalTime
             << setw(8) << process.burstTime
             << setw(8) << process.completionTime
             << setw(10) << process.turnaroundTime
             << setw(8) << process.waitingTime
             << endl;
    }

    cout << "\nAverage Turnaround Time = " << totalTAT / n << endl;
    cout << "Average Waiting Time    = " << totalWT / n << endl;

    return 0;
}