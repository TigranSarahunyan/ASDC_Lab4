
#include "Array.cpp"
#include "Header.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    const int DIMENSION = 4;
    vector<pair<int, int>> intervals = {
            {5,2 },
            {-3, 6},
            {5, 8},
            {-4,-9}
    };
    cout << "Массив:\n";

    for (auto& x : intervals) {
        cout << x.first << "\t" << x.second << endl;
    }

    Array array(intervals, DIMENSION);
    vector<int> rowVector(array.getDimension()), colVector(array.getDimension());

    auto startTime = chrono::high_resolution_clock::now();
    cout << array.directAccess({5,-3,5,-4}) << endl;
    auto endTime = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime);

    cout << "Прямой доступ время  = " << duration.count() << " микросекунды" << endl;

    startTime = chrono::high_resolution_clock::now();
    cout << array.accessAyleaf({5,-3,5,-4}) << endl;
    endTime = chrono::high_resolution_clock::now();

    duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime);

    cout << "Метод доступа с вектором Айлиффа = " << duration.count() << " микросекунды" << endl;

    startTime = chrono::high_resolution_clock::now();
    array.getDefingVectors(1000, rowVector, colVector);
    endTime = chrono::high_resolution_clock::now();

    auto durationDefining = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);
    cout << "Метод доступа с определяющим вектором = " << durationDefining.count() << " микросекунды" << endl;

    return 0;
}