/*
GAS STATION

There are n gas stations along a circular route, where the amount of gas at the i-th station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the i-th station to its next (i + 1)-th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the sorting gas stations's index if you travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique.

e.g.1,

Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3

Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.

e.g.2,

Input: gas = [2,3,4], cost = [3,4,3]
Output: -1

Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.

----------------------------------

ALGORITHM

Greedy
- Time: O(n)
- Space: O(1)

Start at position s, run out of gas at station k, then no station between s and k can be a valid starting station.

For station t between s and k, we have 

bal[s:t] + bal[t:k] = bal[s:k] < 0
bal[t:k] = bal[s:k] - bal[s:t] < 0

Because we run out of gas at k, then at t we still have gas, else we run out of gas at t already, not have to wait till k.
Then if we start at t, we will run out of gas at k too.

CAN-COMPLETE-CIRCUIT(gas, cost)
    glob_balance = 0
    curr_balance = 0
    index = -1

    for i = 0 ... gas.length - 1
        curr_balance += gas[i] - cost[i]
        glob_balance += curr_balance

        if curr_balance < 0
            index = -1
            curr_balance = 0
        else
            if index = -1
                index = i
    
    if glob_balance == 0
        return index
    else
        return -1

*/

#include <iostream>
#include <vector>

int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
    int glob_balance = 0;
    int curr_balance = 0;
    int index = -1;

    for (int i = 0; i < gas.size(); i++) {
        int diff = gas[i] - cost[i];
        curr_balance += diff;
        glob_balance += diff;

        if (curr_balance < 0) {
            index = -1;
            curr_balance = 0;
        }
        else if (index == -1) index = i;
    }

    if (glob_balance >= 0) return index;
    else return -1;
}
