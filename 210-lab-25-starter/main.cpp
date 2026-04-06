#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <fstream>
#include <algorithm>
#include <iomanip>
using namespace std;
using namespace std::chrono;

int main() {
    //RACE 1
    //VECTOR
    // Start timing for vector 
    auto vs = high_resolution_clock::now();

    vector<string> v1;
    ifstream fin;
    fin.open("codes.txt");
    string temp;
    //reading codes into vector
    while(fin >> temp){
        v1.push_back(temp);
    }
    // End timing
    auto ve = high_resolution_clock::now();

    // Calculate duration
    auto vd = duration_cast<nanoseconds>(ve - vs);
    int vdr = vd.count();

    //SET
    // Start timing for set
    //resetting the cursor for file input
    fin.clear();
    fin.seekg(0, ios::beg);
    auto ss = high_resolution_clock::now();
    //declaring set
    set<string> s1;
    while(fin >> temp){
        s1.insert(temp);
    }

    // End timing
    auto se = high_resolution_clock::now();

    // Calculate duration
    auto sd = duration_cast<nanoseconds>(se - ss);
    int sdr = sd.count();

    //LIST
    // Start timing for list
    fin.clear();
    fin.seekg(0, ios::beg);

    auto ls = high_resolution_clock::now();
    //declaring set
    list<string> l1;
    while(fin >> temp){
        l1.push_back(temp);
    }

    // End timing
    auto le = high_resolution_clock::now();

    // Calculate duration
    auto ld = duration_cast<nanoseconds>(le - ls);
    int ldr = ld.count();

    //RACE 2
    //resetting the cursor for file input
    //VECTOR
    auto vs2 = high_resolution_clock::now();

    //sorting vector
    sort(v1.begin(), v1.end());

    // End timing
    auto ve2 = high_resolution_clock::now();

    // Calculate duration
    auto vd2 = duration_cast<nanoseconds>(ve2 - vs2);
    int vdr2 = vd2.count();

    //SET
    int sdr2 = -1; //set is already sorted

    //LIST
    auto ls2 = high_resolution_clock::now();

    //sorting list
    l1.sort();

    // End timing
    auto le2 = high_resolution_clock::now();

    // Calculate duration
    auto ld2 = duration_cast<nanoseconds>(le2 - ls2);
    int ldr2 = ld2.count();

    //RACE 3
    //VECTOR
    string val = "TESTCODE";

    auto vs3 = high_resolution_clock::now();

    //inserting in vector
    int mid = v1.size()/2;
    v1.insert(v1.begin() + mid, val);


    // End timing
    auto ve3 = high_resolution_clock::now();

    // Calculate duration
    auto vd3 = duration_cast<nanoseconds>(ve3 - vs3);
    int vdr3 = vd3.count();

    //LIST
    auto ls3 = high_resolution_clock::now();

    //inserting in list
    auto it = l1.begin();
    advance(it, mid);
    l1.insert(it, val);
    


    // End timing
    auto le3 = high_resolution_clock::now();

    // Calculate duration
    auto ld3 = duration_cast<nanoseconds>(le3 - ls3);
    int ldr3 = ld3.count();

    //SET
    auto ss3 = high_resolution_clock::now();

    //inserting in set
    s1.insert(val);

    // End timing
    auto se3 = high_resolution_clock::now();

    // Calculate duration
    auto sd3 = duration_cast<nanoseconds>(se3 - ss3);
    int sdr3 = sd3.count();

    //Race 4
    //VECTOR
    auto vs4 = high_resolution_clock::now();

    //deleting middle 
    v1.erase(v1.begin()+mid);
    
    // End timing
    auto ve4 = high_resolution_clock::now();

    // Calculate duration
    auto vd4 = duration_cast<nanoseconds>(ve4 - vs4);
    int vdr4 = vd4.count();

    //LIST
    auto ls4 = high_resolution_clock::now();

    //deleting middle 
        auto it4 = l1.begin();
        advance(it4, mid);
        l1.erase(it4);
    
    // End timing
    auto le4 = high_resolution_clock::now();

    // Calculate duration
    auto ld4 = duration_cast<nanoseconds>(le4 - ls4);
    int ldr4 = ld4.count();

    //SET
    auto ss4 = high_resolution_clock::now();

    //deleting middle 
    auto it3 = s1.begin();
    advance(it3, mid);
    s1.erase(it3);
    
    // End timing
    auto se4 = high_resolution_clock::now();

    // Calculate duration
    auto sd4 = duration_cast<nanoseconds>(se4 - ss4);
    int sdr4 = sd4.count();

    //output table
    cout << left
         << setw(12) << "Operation"
         << setw(12) << "Vector"
         << setw(12) << "List"
         << setw(12) << "Set" << '\n';

    cout << left
         << setw(12) << "Read"
         << setw(12) << vdr
         << setw(12) << ldr
         << setw(12) << sdr << '\n';

    cout << left
         << setw(12) << "Sort"
         << setw(12) << vdr2
         << setw(12) << ldr2
         << setw(12) << sdr2 << '\n';

    cout << left
         << setw(12) << "Insert"
         << setw(12) << vdr3
         << setw(12) << ldr3
         << setw(12) << sdr3 << '\n';

    cout << left
         << setw(12) << "Delete"
         << setw(12) << vdr4
         << setw(12) << ldr4
         << setw(12) << sdr4 << '\n';


    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/