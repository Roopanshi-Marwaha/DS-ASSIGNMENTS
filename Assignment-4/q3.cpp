#include <bits/stdc++.h>
using namespace std;

void interleave(queue<int> &q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Not possible (queue size must be even)\n";
        return;
    }

    int half = n / 2;
    queue<int> q1;

    // Step 1: Move first half to q1
    for (int i = 0; i < half; i++) {
        q1.push(q.front());
        q.pop();
    }

    // Step 2: Interleave elements of q1 and q (second half)
    while (!q1.empty()) {
        q.push(q1.front());
        q1.pop();

        q.push(q.front());
        q.pop();
    }
}

void display(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);

    cout << "Original Queue: ";
    display(q);

    cout << "After interleave: ";
    interleave(q);
    display(q);

    return 0;
}
