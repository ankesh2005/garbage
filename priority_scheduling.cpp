#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Process {
    int pid;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};

void swap(Process &a, Process &b) {
    Process temp = a;
    a = b;
    b = temp;
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

    for(int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> p[i].burst_time;
        cout << "Enter priority for process " << i + 1 << " (lower number = higher priority): ";
        cin >> p[i].priority;
    }

    // Sort processes by priority (ascending)
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(p[i].priority > p[j].priority) {
                swap(p[i], p[j]);
            }
        }
    }

    p[0].waiting_time = 0;
    for(int i = 1; i < n; i++) {
        p[i].waiting_time = 0;
        for(int j = 0; j < i; j++) {
            p[i].waiting_time += p[j].burst_time;
        }
    }

    for(int i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].burst_time + p[i].waiting_time;
    }

    cout << "\nPID\tBurst\tPriority\tWaiting\tTurnaround\n";
    for(int i = 0; i < n; i++) {
        cout << p[i].pid << "\t" << p[i].burst_time << "\t" << p[i].priority
             << "\t\t" << p[i].waiting_time << "\t" << p[i].turnaround_time << endl;
    }

    float avg_wait = 0, avg_turn = 0;
    for(int i = 0; i < n; i++) {
        avg_wait += p[i].waiting_time;
        avg_turn += p[i].turnaround_time;
    }
    avg_wait /= n;
    avg_turn /= n;

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time: " << avg_wait;
    cout << "\nAverage Turnaround Time: " << avg_turn << endl;

    return 0;
}