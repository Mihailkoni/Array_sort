#include <iostream>
#include <vector> 
#include <chrono> 
#include <fstream> 
#include <string> 
#include <iomanip> 
#include "Array_Sort.h"
using namespace std;
using namespace chrono;

void read_File(vector<key>&arr,const string& filename) {
    string line;
    int p1, p2, p3, count = 0;

    ifstream in("Input.txt");
    if (in.is_open()) {
        while (getline(in, line)) {
            count += 1;
            key k;
            k.group.l = line[0];
            k.group.num = stoi(line.substr(1, 4));
            p1 = line.find_first_of(' ');
            p2 = line.find_first_of(' ', p1 + 1);
            k.fio.surname = line.substr(p1 + 1, p2 - p1);
            p3 = line.find_last_of(' ');
            k.fio.name = line.substr(p2 + 1, p3 - p2);
            k.fio.patronymic = line.substr(p3 + 1);
            k.s = count;
            arr.push_back(k);
        }
    }
}

void write_File(vector<key>& arr, duration<double> diff,const string& filename) {
    ofstream file(filename);
    long n = arr.size();
    if (file.is_open()) {
        for (int i = 0; i < n; i++) {
            file << arr[i].group.l << arr[i].group.num << " " << arr[i].fio.surname << arr[i].fio.name << arr[i].fio.patronymic << " " << arr[i].s << "\n";
        }
        file << fixed << diff.count() << " s" << "\n";
    }
}

void Call_Bubble_Sort() {
    vector<key> arrB;
    read_File(arrB, "Input.txt");

    long n = arrB.size();
    // Upgrate Bubble sort time
    auto startB = high_resolution_clock::now();
    bubble_Sort(arrB, n);
    auto endB = high_resolution_clock::now();
    duration<double> diffB = endB - startB;
    //

    // Output Bubble
    write_File(arrB, diffB, "Output Buble.txt");

}

void Call_Shell_Sort() {
    vector<key> arrSh;
    read_File(arrSh, "Input.txt");

    long sh = arrSh.size();

    // Shell sort time
    auto startSh = high_resolution_clock::now();
    shell_Sort(arrSh, sh);
    auto endSh = high_resolution_clock::now();
    duration<double> diffSh = endSh - startSh;
    //

    // Output Shell
    write_File(arrSh, diffSh, "Output Shell.txt");
    //
}

int main() {
   Call_Shell_Sort();
   Call_Bubble_Sort();
   return 0;
}
