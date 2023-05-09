#pragma once
#include "Header.h"


class Array {
    vector<pair<int, int>> ranges;
    vector<int> data;
    int size;
    int dimension;
public:
    int getSize();

    int getDimension();

    int calculateSize(vector<pair<int, int>> ranges);

    Array(vector<pair<int, int>> &ranges, int dimension);

    int directAccess(vector<int> indices);

    int accessAyleaf(vector<int> indices);

    void getDefingVectors(int index, vector<int> &rowVector, vector<int> &colVector);

};

