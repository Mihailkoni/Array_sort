#pragma once
#include <iostream>
#include <vector> 
#include <string> 
using namespace std;

struct key {
    int s;
    struct group {
        char l;
        int num; 
    }group;

    struct fio {
        string surname; 
        string name; 
        string patronymic; 
    }fio;
};

void bubble_Sort(vector<key>& arr, long& n) {
    bool swapped;
    key temp;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if ((arr[j].group.l > arr[j + 1].group.l) || ((arr[j].group.l == arr[j + 1].group.l) && (arr[j].group.num > arr[j + 1].group.num)) || ((arr[j].group.l == arr[j + 1].group.l) && (arr[j].group.num == arr[j + 1].group.num) && (arr[j].fio.surname.compare(arr[j + 1].fio.surname) > 0)) || ((arr[j].group.l == arr[j + 1].group.l) && (arr[j].group.num == arr[j + 1].group.num) && (arr[j].fio.surname.compare(arr[j + 1].fio.surname) == 0) && (arr[j].fio.name.compare(arr[j + 1].fio.name) > 0)) || ((arr[j].group.l == arr[j + 1].group.l) && (arr[j].group.num == arr[j + 1].group.num) && (arr[j].fio.surname.compare(arr[j + 1].fio.surname) == 0) && (arr[j].fio.name.compare(arr[j + 1].fio.name) == 0) && (arr[j].fio.patronymic.compare(arr[j + 1].fio.patronymic) > 0))) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (swapped == false) { // upgrate buble_sort
            break; 
        }
    }
}


int increment(long inc[], long size) {
    int p1, p2, p3, s;

    p1 = p2 = p3 = 1;
    s = -1;
    do {
        if (++s % 2) {
            inc[s] = 8 * p1 - 6 * p2 + 1;
        }
        else {
            inc[s] = 9 * p1 - 9 * p3 + 1;
            p2 *= 2;
            p3 *= 2;
        }
        p1 *= 2;
    } while (3 * inc[s] < size);

    return s > 0 ? --s : 0;
}

void shell_Sort(vector<key>& arr, long& size) {
    long inc, i, j, seq[40];
    int s;
    key temp;
    s = increment(seq, size);
    while (s >= 0) {
        inc = seq[s--];

        for (i = inc; i < size; i++) {
            temp = arr[i];
            for (j = i - inc; (j >= 0) && ((arr[j].group.l > temp.group.l) || ((arr[j].group.l == temp.group.l) && (arr[j].group.num > temp.group.num)) || ((arr[j].group.l == temp.group.l) && (arr[j].group.num == temp.group.num) && (arr[j].fio.surname.compare(temp.fio.surname) > 0)) || ((arr[j].group.l == temp.group.l) && (arr[j].group.num == temp.group.num) && (arr[j].fio.surname.compare(temp.fio.surname) == 0) && (arr[j].fio.name.compare(temp.fio.name) > 0)) || ((arr[j].group.l == temp.group.l) && (arr[j].group.num == temp.group.num) && (arr[j].fio.surname.compare(temp.fio.surname) == 0) && (arr[j].fio.name.compare(temp.fio.name) == 0) && (arr[j].fio.patronymic.compare(temp.fio.patronymic) > 0))); j -= inc)
                arr[j + inc] = arr[j];
            arr[j + inc] = temp;
        }
    }
}