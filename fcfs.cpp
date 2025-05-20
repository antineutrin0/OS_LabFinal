#include <bits/stdc++.h>
using namespace std;

struct pcb {
    int pid, burstTime, arivalTime, compTime, waitingTime, tatime;
};

int main() {
    pcb p[10], temp;
    int n;
    cout << "Enter Number of processes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter arrival time and burst time of Process " << i + 1 << ": ";
        cin >> p[i].arivalTime >> p[i].burstTime;
        p[i].pid = i + 1;
    }

    // Sort processes by arrival time
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].arivalTime > p[j + 1].arivalTime) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    int sum = 0, totalWaiting = 0, totalTat = 0;

    for (int i = 0; i < n; i++) {
        if (sum < p[i].arivalTime) sum = p[i].arivalTime; // handle CPU idle time
        sum += p[i].burstTime;
        p[i].compTime = sum;
        p[i].tatime = p[i].compTime - p[i].arivalTime;
        p[i].waitingTime = p[i].tatime - p[i].burstTime;
        totalWaiting += p[i].waitingTime;
        totalTat += p[i].tatime;
    }

    cout << "\nPID\tArrival\tBurst\tCompletion\tTAT\tWaiting\n";
    for (int i = 0; i < n; i++) {
        cout << p[i].pid << "\t" << p[i].arivalTime << "\t" << p[i].burstTime << "\t" 
             << p[i].compTime << "\t\t" << p[i].tatime << "\t" << p[i].waitingTime << endl;
    }

    cout << "\nAverage Waiting Time: " << (float)totalWaiting / n << endl;
    cout << "Average Turnaround Time: " << (float)totalTat / n << endl;

    return 0;
}

