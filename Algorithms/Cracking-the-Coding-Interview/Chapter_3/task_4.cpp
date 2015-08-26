#include <iostream>
#include <stack>
#include <assert.h>
#include <deque>
#include "../../testing.h"

using Stack = std::stack<int>;
using std::cout;

void MoveTower(Stack* towerFrom, Stack* towerTmp, Stack* towerTo, int height) {
    if (height == 0) {
        return;
    }
    assert(height <= towerFrom->size());

    MoveTower(towerFrom, towerTo, towerTmp, height - 1);

    assert(!towerFrom->empty());
    assert(towerTo->empty() || towerTo->top() > towerFrom->top());
    towerTo->push(towerFrom->top());
    towerFrom->pop();

    MoveTower(towerTmp, towerFrom, towerTo, height - 1);
}


void CheckMoveTower(const std::deque<int>& tower) {
    Stack from(tower);
    Stack tmp;
    Stack to;
    MoveTower(&from, &tmp, &to, from.size());

    CHECK_EQUAL(from.empty(), true);
    CHECK_EQUAL(tmp.empty(), true);

    std::deque<int> movedTower;
    while (!to.empty()) {
        movedTower.push_front(to.top());
        to.pop();
    }
    CHECK_EQUAL(movedTower, tower);
}


int main() {
    std::deque<int> tower = {};
    CheckMoveTower(tower);

    tower = {1};
    CheckMoveTower(tower);

    tower = {5, 4, 3, 2, 1};
    CheckMoveTower(tower);

    tower = {10, 5, 1};
    CheckMoveTower(tower);


    return 0;
}
