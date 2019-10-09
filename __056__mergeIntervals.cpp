#include <iostream>
#include <vector>
using namespace std;


vector<Interval> merge(vector<Interval>& intervals) {
    if(intervals.size() == 0)   return intervals;
    // sort the Intervals by the starting time with a lambda function
    sort(intervals.begin(), intervals.end(),
         [](Interval a, Interval b){return a.start < b.start;});
    
    vector<Interval> res;
    for (int i = 0; i < intervals.size() - 1; i++) {
        if(intervals[i].end < intervals[i + 1].start)  continue;
        else{
            intervals[i].end = max(intervals[i].end, intervals[i + 1].end);
            intervals.erase(intervals.begin() + i + 1);
            i--;
        }
    }
    return intervals;
}

//struct Intervals{
//    int start;
//    int end;
//    Intervals(): start(0), end(0){}
//    Intervals(int start, int end): start(start), end(end) {}
//};
//
//
//bool compareIntervals(Intervals a, Intervals b){
//    return a.start < b.start;
//}
//
//void sortIntervals(vector<Intervals> &intervals){
//    sort(intervals.begin(), intervals.end(), compareIntervals);
//}
//
//void printVector2D(vector<Intervals> &intervals){
//    cout << "[";
//    for (int i = 0; i < intervals.size(); i++) {
//        cout << "[" << intervals[i].start << ", " << intervals[i].end << "]";
//        if(i != intervals.size() - 1)   cout << ", ";
//    }
//    cout << "]";
//}
//
//vector<Intervals> mergeIntervals(vector<Intervals> &intervals){
//    sortIntervals(intervals);
////    printVector2D(intervals);
//    vector<Intervals> res;
//    for (int i = 0; i < intervals.size() - 1; i++) {
//        if(intervals[i].end < intervals[i + 1].start)  {
////            cout << "no merge operation" << endl;
//        }
//        else{
////            cout << "merge" << endl;
//            intervals[i].end = max(intervals[i].end, intervals[i + 1].end);
//            intervals.erase(intervals.begin() + i + 1);
//            i--;
//        }
//    }
//    return intervals;
//}



int main(){
    vector<Intervals> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    printVector2D(intervals);
    cout << "  --MERGE-->  ";
    vector<Intervals> res = mergeIntervals(intervals);
    printVector2D(res);
    cout << endl;
    return 0;
}
