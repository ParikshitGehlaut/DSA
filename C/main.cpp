#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Define a structure for a process
struct Process {
    int id;               // Process ID
    int arrivalTime;       // Arrival time of the process
    vector<int> bursts;    // CPU and I/O burst durations alternately
    int burstIndex;        // Current burst index (alternating between CPU and I/O)
    int remainingTime;     // Remaining time in the current burst

    Process(int id, int arrivalTime, vector<int> bursts)
        : id(id), arrivalTime(arrivalTime), bursts(bursts), burstIndex(0), remainingTime(bursts[0]) {}

    // Check if the process has more bursts (CPU or I/O) to execute
    bool isFinished() {
        return burstIndex >= bursts.size();
    }
};

// Function to simulate time progression
void simulateTime(vector<Process>& processes) {
    queue<Process*> readyQueue;
    int currentTime = 0;
    int runningProcessIndex = -1;

    while (true) {
        bool allProcessesFinished = true;

        // Check for new processes arriving at the current time
        for (auto& process : processes) {
            if (process.arrivalTime == currentTime) {
                cout << "Time " << currentTime << ": Process " << process.id << " arrives.\n";
                readyQueue.push(&process);
            }
        }

        // If there's no running process, get one from the ready queue
        if (runningProcessIndex == -1 && !readyQueue.empty()) {
            Process* nextProcess = readyQueue.front();
            readyQueue.pop();
            runningProcessIndex = nextProcess->id;
            cout << "Time " << currentTime << ": Process " << nextProcess->id << " starts CPU burst.\n";
        }

        // If there's a running process, update its remaining time
        if (runningProcessIndex != -1) {
            Process& runningProcess = processes[runningProcessIndex];

            runningProcess.remainingTime--;
            if (runningProcess.remainingTime == 0) {
                cout << "Time " << currentTime << ": Process " << runningProcess.id << " completes CPU burst.\n";
                runningProcess.burstIndex++;
                if (!runningProcess.isFinished()) {
                    runningProcess.remainingTime = runningProcess.bursts[runningProcess.burstIndex];
                } else {
                    cout << "Time " << currentTime << ": Process " << runningProcess.id << " finishes.\n";
                    runningProcessIndex = -1;
                }
            }
        }

        // Check if all processes are finished
        for (auto& process : processes) {
            if (!process.isFinished()) {
                allProcessesFinished = false;
                break;
            }
        }

        if (allProcessesFinished) {
            break;
        }

        currentTime++;  // Increment the time
    }
}

int main() {
    // Sample process list: First value is the arrival time, followed by alternating CPU and I/O bursts
    vector<Process> processes = {
        Process(0, 0, {20, 4, 12, 5, 6, 10, -1}),
    };

    simulateTime(processes);

    return 0;
}
