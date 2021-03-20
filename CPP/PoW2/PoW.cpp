#define _CRT_SECURE_NO_WARNINGS
#include "sha256.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <time.h>

#define CLOCKS_PER_SEC ((clock_t)1000)

typedef long clock_t;

using namespace std;

string merkle(vector<string>& tr);
void calcNonce(string str, int z);

int main(int argc, char* argv[])
{
    int z = 0;
    if (argc == 2)  z = atoi(argv[1]);
    if (z == 0) z = 4;
    
    vector<string> tr = { "sender: abc, receiver: 123, amount: 1, tid: 100",
                          "sender: abc, receiver: 123, amount: 1, tid: 101",
                          "sender: abc, receiver: 123, amount: 1, tid: 102",
                          "sender: abc, receiver: 123, amount: 1, tid: 103",
                          "sender: abc, receiver: 123, amount: 1, tid: 104",
                          "sender: abc, receiver: 123, amount: 1, tid: 105",
                          "sender: abc, receiver: 123, amount: 1, tid: 106",
                          "sender: abc, receiver: 123, amount: 1, tid: 107" };

    vector<string> ha;
    for (int i = 0; i < tr.size(); ++i) {
        ha.push_back(sha256(sha256(tr[i])));
    }
    string block = "bid: 100, prevH: 1739f776d968cdaca6568f54b83642a9b156705cc6d9a02822f4fc97cee044, time: 2020.10.16.15.11" + merkle(ha);
    calcNonce(block, z);
    
    return 0;
}

string merkle(vector<string>& v)
{
    int size = v.size();
    if (size % 2 == 1) {
        v.push_back(v[size - 1]);
    }

    vector<string> t;
    for (int i = 0; i < size / 2; i++) {
        string o = sha256(sha256(v[i * 2] + v[i * 2 + 1]));
        t.push_back(o);
    }

    if (t.size() == 1) {
        return t[0];
    }
    else
        return merkle(t);
}

void calcNonce(string block, int z)
{
    string zstr = "0";
    for (int i = 1; i < z; i++)
        zstr += "0";

    time_t timer;
    struct tm* t, *tt;
    timer = time(NULL);
    t = localtime(&timer);
    cout << t->tm_hour <<" : "<< t->tm_min <<" : "<< t->tm_sec<<endl;
    clock_t startTime = clock();
    int nonce = 0;
    string h;

    while (1) {
        h = sha256(sha256(block + to_string(nonce)));
        printf("%10d :  %s\r", nonce, h.c_str());
        if (h.substr(0, z) == zstr){
            clock_t endTime = clock();
            double timeInSecond = (double)((endTime - startTime) / CLOCKS_PER_SEC);
            cout << "\ntime: " << timeInSecond << "s";

            timer = time(NULL);
            t = localtime(&timer);
            cout <<endl<< t->tm_hour << " : " << t->tm_min << " : " << t->tm_sec<< endl;
            break;
        }
        nonce++;
    }
}