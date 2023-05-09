

#include "Array.h"

int Array::getSize() {
    return size;
}

int Array::getDimension()
{
    return dimension;
}
int Array::calculateSize(vector<pair<int, int>> ranges)
{
    int size = 1;
    for (auto& x : ranges) {
        size *= (x.second - x.first + 1);
    }
    data.resize(size);
    for (int i = 0; i < size; i++) {
        data[i] = i;
    }
    return size;
}
Array::Array(vector<pair<int, int>>& ranges, int dimension){
    size=calculateSize(ranges);
    this->ranges=ranges;
    this->dimension=dimension;
}
int Array::directAccess(vector<int> indices)
{
    int index = indices[dimension - 1] - ranges[dimension - 1].first;
    int product = 1;
    for (int i = dimension - 2; i >= 0; i--) {
        index += (indices[i] - ranges[i].first) * product;
        product *= (ranges[i + 1].second - ranges[i + 1].first + 1);
    }
    return data[index];
}
int Array::accessAyleaf(vector<int> indices)
{
    int index = indices[0] - ranges[0].first;
    for (int i = 1; i < dimension; i++) {
        int product = 1;
        for (int j = 0; j < i; j++) {
            product *= (ranges[j + 1].second - ranges[j + 1].first + 1);
        }
        index += (indices[i] - ranges[i].first) * product;
    }
    return data[index];
}
void Array::getDefingVectors(int index, vector<int>& rowVector, vector<int>& colVector) {
    int product = 1;
    for (int i = dimension - 1; i >= 0; i--) {
        rowVector[i] = (index / product) % (ranges[i].second - ranges[i].first + 1) + ranges[i].first;
        product *= (ranges[i].second - ranges[i].first + 1);
    }
    product = 1;
    for (int i = 0; i < dimension; i++) {
        colVector[i] = (index / product) % (ranges[i].second - ranges[i].first + 1) + ranges[i].first;
        product *= (ranges[i].second - ranges[i].first + 1);
    }
}

