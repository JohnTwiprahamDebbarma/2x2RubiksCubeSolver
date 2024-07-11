#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
#include <cstdio>

using namespace std;

struct PuzzleState {
    vector<vector<int>> board;
    string path;
    string index;
};


void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

string make_str(const PuzzleState& state){
char ret[24];
for (int i=0; i<6; i++){
    for (int j=0; j<4; j++){
            if (state.board[i][j]==0){
                    ret[i*4+j] = 'W';
            }
            else if (state.board[i][j]==1){
                ret[i*4+j] = 'R';
            }
            else if (state.board[i][j]==2){
                ret[i*4+j] = 'B';
            }
            else if (state.board[i][j]==3){
                ret[i*4+j] = 'O';
            }
            else if (state.board[i][j]==4){
                ret[i*4+j] = 'G';
            }
            else if (state.board[i][j]==5){
                ret[i*4+j] = 'Y';
            }
    }
}
return ret;
}

//NSEWTB
// Function to check if the current state is the goal state
bool isGoalState(const PuzzleState& state) {
    if ((state.board[0][0]==state.board[0][1])&&(state.board[0][0]==state.board[0][2])&&(state.board[0][0]==state.board[0][3])&&(state.board[0][1]==state.board[0][2])&&(state.board[0][1]==state.board[0][3])&&(state.board[0][2]==state.board[0][3])){
    if ((state.board[1][0]==state.board[1][1])&&(state.board[1][0]==state.board[1][2])&&(state.board[1][0]==state.board[1][3])&&(state.board[1][1]==state.board[1][2])&&(state.board[1][1]==state.board[1][3])&&(state.board[1][2]==state.board[1][3])){
    if ((state.board[2][0]==state.board[2][1])&&(state.board[2][0]==state.board[2][2])&&(state.board[2][0]==state.board[2][3])&&(state.board[2][1]==state.board[2][2])&&(state.board[2][1]==state.board[2][3])&&(state.board[2][2]==state.board[2][3])){
    if ((state.board[3][0]==state.board[3][1])&&(state.board[3][0]==state.board[3][2])&&(state.board[3][0]==state.board[3][3])&&(state.board[3][1]==state.board[3][2])&&(state.board[3][1]==state.board[3][3])&&(state.board[3][2]==state.board[3][3])){
    if ((state.board[4][0]==state.board[4][1])&&(state.board[4][0]==state.board[4][2])&&(state.board[4][0]==state.board[4][3])&&(state.board[4][1]==state.board[4][2])&&(state.board[4][1]==state.board[4][3])&&(state.board[4][2]==state.board[4][3])){
    if ((state.board[5][0]==state.board[5][1])&&(state.board[5][0]==state.board[5][2])&&(state.board[5][0]==state.board[5][3])&&(state.board[5][1]==state.board[5][2])&&(state.board[5][1]==state.board[5][3])&&(state.board[5][2]==state.board[5][3])){
        return true;
    }
    }
    }
    }
    }
}
return false;
}
//TLFriReB
PuzzleState U(const PuzzleState& currentState) {
    PuzzleState nextState = currentState;
    nextState.board[0][0] = currentState.board[0][3];
    nextState.board[0][1] = currentState.board[0][0];
    nextState.board[0][2] = currentState.board[0][1];
    nextState.board[0][3] = currentState.board[0][2];

    nextState.board[1][1] = currentState.board[2][0];
    nextState.board[1][2] = currentState.board[2][1];
    nextState.board[2][0] = currentState.board[3][3];
    nextState.board[2][1] = currentState.board[3][0];
    nextState.board[3][3] = currentState.board[4][2];
    nextState.board[3][0] = currentState.board[4][3];
    nextState.board[4][2] = currentState.board[1][1];
    nextState.board[4][3] = currentState.board[1][2];

    nextState.path += "U";
    nextState.index = make_str(nextState);
    return nextState;
}

PuzzleState U_prime(const PuzzleState& currentState){
    PuzzleState nextState = currentState;
    nextState.board[0][0] = currentState.board[0][1];
    nextState.board[0][1] = currentState.board[0][2];
    nextState.board[0][2] = currentState.board[0][3];
    nextState.board[0][3] = currentState.board[0][0];

    nextState.board[1][1] = currentState.board[4][2];
    nextState.board[1][2] = currentState.board[4][3];
    nextState.board[2][0] = currentState.board[1][1];
    nextState.board[2][1] = currentState.board[1][2];
    nextState.board[3][3] = currentState.board[2][0];
    nextState.board[3][0] = currentState.board[2][1];
    nextState.board[4][2] = currentState.board[3][3];
    nextState.board[4][3] = currentState.board[3][0];
    nextState.path += "U_prime";
    nextState.index = make_str(nextState);
    return nextState;
}

PuzzleState R(const PuzzleState& currentState){
    PuzzleState nextState = currentState;
    nextState.board[3][0] = currentState.board[3][3];
    nextState.board[3][1] = currentState.board[3][0];
    nextState.board[3][2] = currentState.board[3][1];
    nextState.board[3][3] = currentState.board[3][2];
//4321->0452
    nextState.board[2][1] = currentState.board[5][3];
    nextState.board[2][2] = currentState.board[5][0];
    nextState.board[5][3] = currentState.board[4][1];
    nextState.board[5][0] = currentState.board[4][2];
    nextState.board[4][1] = currentState.board[0][1];
    nextState.board[4][2] = currentState.board[0][2];
    nextState.board[0][1] = currentState.board[2][1];
    nextState.board[0][2] = currentState.board[2][2];
    nextState.path += "R";
    nextState.index = make_str(nextState);
    return nextState;
}

PuzzleState R_prime(const PuzzleState& currentState){
    PuzzleState nextState = currentState;
    nextState.board[3][0] = currentState.board[3][1];
    nextState.board[3][1] = currentState.board[3][2];
    nextState.board[3][2] = currentState.board[3][3];
    nextState.board[3][3] = currentState.board[3][0];
//4321->0452
    nextState.board[2][1] = currentState.board[0][1];
    nextState.board[2][2] = currentState.board[0][2];
    nextState.board[5][3] = currentState.board[2][1];
    nextState.board[5][0] = currentState.board[2][2];
    nextState.board[4][1] = currentState.board[5][3];
    nextState.board[4][2] = currentState.board[5][0];
    nextState.board[0][1] = currentState.board[4][1];
    nextState.board[0][2] = currentState.board[4][2];
    nextState.path += "R_prime";
    nextState.index = make_str(nextState);
    return nextState;
}

PuzzleState F(const PuzzleState& currentState){
    PuzzleState nextState = currentState;
    nextState.board[2][0] = currentState.board[2][3];
    nextState.board[2][1] = currentState.board[2][0];
    nextState.board[2][2] = currentState.board[2][1];
    nextState.board[2][3] = currentState.board[2][2];

    nextState.board[1][3] = currentState.board[5][3];
    nextState.board[1][2] = currentState.board[5][2];
    nextState.board[3][3] = currentState.board[0][3];
    nextState.board[3][2] = currentState.board[0][2];
    nextState.board[5][3] = currentState.board[3][3];
    nextState.board[5][2] = currentState.board[3][2];
    nextState.board[0][3] = currentState.board[1][3];
    nextState.board[0][2] = currentState.board[1][2];
    nextState.path += "F";
    nextState.index = make_str(nextState);
    return nextState;
}

PuzzleState F_prime(const PuzzleState& currentState){
    PuzzleState nextState = currentState;
    nextState.board[2][0] = currentState.board[2][1];
    nextState.board[2][1] = currentState.board[2][2];
    nextState.board[2][2] = currentState.board[2][3];
    nextState.board[2][3] = currentState.board[2][0];

    nextState.board[5][3] = currentState.board[1][3];
    nextState.board[5][2] = currentState.board[1][2];
    nextState.board[3][3] = currentState.board[5][3];
    nextState.board[3][2] = currentState.board[5][2];
    nextState.board[1][3] = currentState.board[0][3];
    nextState.board[1][2] = currentState.board[0][2];
    nextState.board[0][3] = currentState.board[3][3];
    nextState.board[0][2] = currentState.board[3][2];
    nextState.path += "F_prime";
    nextState.index = make_str(nextState);
    return nextState;
}

PuzzleState R2(const PuzzleState& currentState){
    PuzzleState nextState = currentState;
    nextState.board[3][0] = currentState.board[3][3];
    nextState.board[3][1] = currentState.board[3][0];
    nextState.board[3][2] = currentState.board[3][1];
    nextState.board[3][3] = currentState.board[3][2];

    nextState.board[2][1] = currentState.board[5][3];
    nextState.board[2][2] = currentState.board[5][0];
    nextState.board[5][3] = currentState.board[4][1];
    nextState.board[5][0] = currentState.board[4][2];
    nextState.board[4][1] = currentState.board[0][1];
    nextState.board[4][2] = currentState.board[0][2];
    nextState.board[0][1] = currentState.board[2][1];
    nextState.board[0][2] = currentState.board[2][2];

    PuzzleState nextTonextState = nextState;
    nextTonextState.board[3][0] = nextState.board[3][3];
    nextTonextState.board[3][1] = nextState.board[3][0];
    nextTonextState.board[3][2] = nextState.board[3][1];
    nextTonextState.board[3][3] = nextState.board[3][2];

    nextTonextState.board[2][1] = nextState.board[5][3];
    nextTonextState.board[2][2] = nextState.board[5][0];
    nextTonextState.board[5][3] = nextState.board[4][1];
    nextTonextState.board[5][0] = nextState.board[4][2];
    nextTonextState.board[4][1] = nextState.board[0][1];
    nextTonextState.board[4][2] = nextState.board[0][2];
    nextTonextState.board[0][1] = nextState.board[2][1];
    nextTonextState.board[0][2] = nextState.board[2][2];

    nextTonextState.path += "R2";
    nextTonextState.index = make_str(nextTonextState);
    return nextTonextState;
}

PuzzleState U2(const PuzzleState& currentState){
    PuzzleState nextState = currentState;
    nextState.board[0][0] = currentState.board[0][3];
    nextState.board[0][1] = currentState.board[0][0];
    nextState.board[0][2] = currentState.board[0][1];
    nextState.board[0][3] = currentState.board[0][2];

    nextState.board[1][1] = currentState.board[2][0];
    nextState.board[1][2] = currentState.board[2][1];
    nextState.board[2][0] = currentState.board[3][3];
    nextState.board[2][1] = currentState.board[3][0];
    nextState.board[3][3] = currentState.board[4][2];
    nextState.board[3][0] = currentState.board[4][3];
    nextState.board[4][2] = currentState.board[1][1];
    nextState.board[4][3] = currentState.board[1][2];

    PuzzleState nextTonextState = nextState;
    nextTonextState.board[0][0] = nextState.board[0][3];
    nextTonextState.board[0][1] = nextState.board[0][0];
    nextTonextState.board[0][2] = nextState.board[0][1];
    nextTonextState.board[0][3] = nextState.board[0][2];

    nextTonextState.board[1][1] = nextState.board[2][0];
    nextTonextState.board[1][2] = nextState.board[2][1];
    nextTonextState.board[2][0] = nextState.board[3][3];
    nextTonextState.board[2][1] = nextState.board[3][0];
    nextTonextState.board[3][3] = nextState.board[4][2];
    nextTonextState.board[3][0] = nextState.board[4][3];
    nextTonextState.board[4][2] = nextState.board[1][1];
    nextTonextState.board[4][3] = nextState.board[1][2];

    nextTonextState.path += "U2";
    nextTonextState.index = make_str(nextTonextState);
    return nextTonextState;
}

PuzzleState F2(const PuzzleState& currentState){
    PuzzleState nextState = currentState;
    nextState.board[2][0] = currentState.board[2][3];
    nextState.board[2][1] = currentState.board[2][0];
    nextState.board[2][2] = currentState.board[2][1];
    nextState.board[2][3] = currentState.board[2][2];

    nextState.board[1][3] = currentState.board[5][3];
    nextState.board[1][2] = currentState.board[5][2];
    nextState.board[3][3] = currentState.board[0][3];
    nextState.board[3][2] = currentState.board[0][2];
    nextState.board[5][3] = currentState.board[3][3];
    nextState.board[5][2] = currentState.board[3][2];
    nextState.board[0][3] = currentState.board[1][3];
    nextState.board[0][2] = currentState.board[1][2];

    PuzzleState nextTonextState = nextState;
    nextTonextState.board[2][0] = nextState.board[2][3];
    nextTonextState.board[2][1] = nextState.board[2][0];
    nextTonextState.board[2][2] = nextState.board[2][1];
    nextTonextState.board[2][3] = nextState.board[2][2];

    nextTonextState.board[1][3] = nextState.board[5][3];
    nextTonextState.board[1][2] = nextState.board[5][2];
    nextTonextState.board[3][3] = nextState.board[0][3];
    nextTonextState.board[3][2] = nextState.board[0][2];
    nextTonextState.board[5][3] = nextState.board[3][3];
    nextTonextState.board[5][2] = nextState.board[3][2];
    nextTonextState.board[0][3] = nextState.board[1][3];
    nextTonextState.board[0][2] = nextState.board[1][2];

    nextTonextState.path += "F2";
    nextTonextState.index = make_str(nextTonextState);
    return nextTonextState;
}


// Function to generate the next possible states from the current state
vector<PuzzleState> generateNextStates(const PuzzleState& currentState) {
    vector<PuzzleState> nextStates;

    PuzzleState nextState = U(currentState);
    nextStates.push_back(nextState);

    PuzzleState nextState1 = U_prime(currentState);
    nextStates.push_back(nextState1);

    PuzzleState nextState2 = U2(currentState);
    nextStates.push_back(nextState2);

    PuzzleState nextState3 = F(currentState);
    nextStates.push_back(nextState3);

    PuzzleState nextState4 = F_prime(currentState);
    nextStates.push_back(nextState4);

    PuzzleState nextState5 = F2(currentState);
    nextStates.push_back(nextState5);

    PuzzleState nextState6 = R(currentState);
    nextStates.push_back(nextState6);

    PuzzleState nextState7 = R_prime(currentState);
    nextStates.push_back(nextState7);

    PuzzleState nextState8 = R2(currentState);
    nextStates.push_back(nextState8);

    return nextStates;
}

// Function to solve the Puzzle Up it Up using BFS
string solveUpitUp(const vector<vector<int>>& initialBoard) {
    PuzzleState initialState;
    initialState.board = initialBoard;
    initialState.path = "";


    queue<PuzzleState> q;
    unordered_set<string> visited;

    q.push(initialState);
    visited.insert(initialState.index);

    while (!q.empty()) {
        PuzzleState currentState = q.front();
        q.pop();

        if (isGoalState(currentState)) {
            return currentState.path;
        }

        vector<PuzzleState> nextStates = generateNextStates(currentState);

        for (const auto& nextState : nextStates) {
            if (visited.find(nextState.index) == visited.end()) {
                q.push(nextState);
                visited.insert(nextState.index);
            }
        }
    }

    return "No solution found.";
}


int main() {
//WRBOGY
////TLFRReBo
    vector<vector<int>> initialBoard = {{4,5,3,2}, {5,5,0,3},{1,0,4,5},{1,1,3,2},{2,4,4,3},{0,1,2,0}};
//    PuzzleState initboard;
//    initboard.board = initialBoard;
//    make_str(initboard);
////
    string solution = solveUpitUp(initialBoard);
    cout << "Solution: " << solution << endl;

    return 0;
}
