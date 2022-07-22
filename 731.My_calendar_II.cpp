// You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a triple booking.

// A triple booking happens when three events have some non-empty intersection (i.e., some moment is common to all the three events.).

// The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end), the range of real numbers x such that start <= x < end.

// Implement the MyCalendarTwo class:

// MyCalendarTwo() Initializes the calendar object.
// boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without causing a triple booking. Otherwise, return false and do not add the event to the calendar.


#include "_structs.h"

using namespace std;

// class MyCalendarTwo {
// public:

//     vector<vector<int>> book1;
//     vector<vector<int>> book2;

//     MyCalendarTwo() {}
    
//     bool book(int start, int end) {
//         for (auto &b2: book2) {
//             if (checkIntersection(start, end, b2)) return false;
//         }
//         bool isInserted = false;
//         for (auto &b1: book1) {
//             if (checkIntersection(start, end, b1)) {
//                 book2.push_back({max(start, b1[0]), min(end, b1[1])});
//                 b1[0] = min(b1[0], start);
//                 b1[1] = max(b1[1], end);
//                 isInserted = true;
//             }
//         }
//         if (!isInserted) book1.push_back({start, end});
//         return true;

//     }

//     bool checkIntersection(int start, int end, vector<int> b) {
//         if (start < b[1] && end > b[0]) return true;
//         return false;
//     }
// };

class MyCalendarTwo {
public:

    // <day, booking change on this day>
    map<int, int> bookCount;

    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        
        // +1 if the booking starts today, -1 if ends
        bookCount[start] ++;
        bookCount[end] --;

        // numbers of bookings in this day
        int currBook = 0;

        // check if the number of current bookings exceeds 2
        for (auto& [day, c]: bookCount) {
            currBook += c;
            if (currBook >= 3) {
                bookCount[start] --;
                bookCount[end] ++;
                return false;
            }
        }

        return true;

    }
};

int main() {
    MyCalendarTwo* mt = new MyCalendarTwo();
    vector<vector<int>> books = {{47, 50}, {1, 10}, {27, 36}, {40, 47}, {20, 27}, {15, 23}, {10, 18}, {27, 36}, {17, 25}, {8, 17}, {24, 33}};
    for (auto v: books) {
        cout << mt->book(v[0], v[1]);
    }
}

// map is ordered
// traverse the map to access day in order
