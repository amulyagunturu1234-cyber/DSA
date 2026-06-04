class Solution {
public:
    // Constants for state colors
    const int DRAW = 0, MOUSE_WIN = 1, CAT_WIN = 2;
    const int MOUSE_TURN = 0, CAT_TURN = 1;

    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();

        // color[mouse][cat][turn] = DRAW/MOUSE_WIN/CAT_WIN
        vector<vector<vector<int>>> color(n, vector<vector<int>>(n, vector<int>(2, DRAW)));

        // degree[mouse][cat][turn] = number of moves available
        // (we decrement this as we eliminate losing moves)
        vector<vector<vector<int>>> degree(n, vector<vector<int>>(n, vector<int>(2, 0)));

        // Step 1: Fill in the degree table
        for (int m = 0; m < n; m++) {
            for (int c = 0; c < n; c++) {
                degree[m][c][MOUSE_TURN] = graph[m].size(); // mouse can move to any neighbor
                degree[m][c][CAT_TURN]   = graph[c].size(); // cat can move to any neighbor

                // Cat cannot move to node 0 (hole), so subtract those
                for (int node : graph[c]) {
                    if (node == 0) {
                        degree[m][c][CAT_TURN]--;
                        break;
                    }
                }
            }
        }

        // BFS queue stores {mouse, cat, turn}
        queue<tuple<int,int,int>> q;

        // Step 2: Seed base cases
        for (int i = 0; i < n; i++) {
            for (int t = 0; t < 2; t++) {
                // Mouse at hole = Mouse wins (skip cat=0 since cat can't be at hole)
                if (i != 0) {
                    color[0][i][t] = MOUSE_WIN;
                    q.push({0, i, t});
                }

                // Cat at same position as mouse = Cat wins
                // (i != 0 because cat can't be at hole)
                if (i != 0) {
                    color[i][i][t] = CAT_WIN;
                    q.push({i, i, t});
                }
            }
        }

        // Step 3: Reverse BFS — propagate known results backwards
        while (!q.empty()) {
            auto [mouse, cat, turn] = q.front();
            q.pop();

            int currentColor = color[mouse][cat][turn];

            // Find all PARENT states that could have led to this state
            // If current turn is MOUSE_TURN, previous turn was CAT_TURN
            // So parent had cat moving → we look at cat's previous positions
            // If current turn is CAT_TURN, previous turn was MOUSE_TURN
            // So parent had mouse moving → we look at mouse's previous positions

            int prevTurn = 1 - turn; // flip the turn

            if (prevTurn == MOUSE_TURN) {
                // Mouse moved to reach current state
                // So parent mouse position = any neighbor of current mouse pos
                for (int prevMouse : graph[mouse]) {
                    // skip if parent already colored
                    if (color[prevMouse][cat][prevTurn] != DRAW) continue;

                    // Mouse's turn in parent state
                    // Mouse wants to WIN → if any child is MOUSE_WIN, parent = MOUSE_WIN
                    if (currentColor == MOUSE_WIN) {
                        color[prevMouse][cat][prevTurn] = MOUSE_WIN;
                        q.push({prevMouse, cat, prevTurn});
                    }
                    // If current is CAT_WIN, decrement degree
                    // If ALL moves lead to CAT_WIN, then parent = CAT_WIN
                    else if (currentColor == CAT_WIN) {
                        degree[prevMouse][cat][prevTurn]--;
                        if (degree[prevMouse][cat][prevTurn] == 0) {
                            color[prevMouse][cat][prevTurn] = CAT_WIN;
                            q.push({prevMouse, cat, prevTurn});
                        }
                    }
                }
            } else {
                // Cat moved to reach current state
                // So parent cat position = any neighbor of current cat pos
                for (int prevCat : graph[cat]) {
                    // Cat cannot come from hole (node 0)
                    if (prevCat == 0) continue;

                    // skip if parent already colored
                    if (color[mouse][prevCat][prevTurn] != DRAW) continue;

                    // Cat's turn in parent state
                    // Cat wants to WIN → if any child is CAT_WIN, parent = CAT_WIN
                    if (currentColor == CAT_WIN) {
                        color[mouse][prevCat][prevTurn] = CAT_WIN;
                        q.push({mouse, prevCat, prevTurn});
                    }
                    // If current is MOUSE_WIN, decrement degree
                    // If ALL moves lead to MOUSE_WIN, then parent = MOUSE_WIN
                    else if (currentColor == MOUSE_WIN) {
                        degree[mouse][prevCat][prevTurn]--;
                        if (degree[mouse][prevCat][prevTurn] == 0) {
                            color[mouse][prevCat][prevTurn] = MOUSE_WIN;
                            q.push({mouse, prevCat, prevTurn});
                        }
                    }
                }
            }
        }

        // Step 4: Answer is the result of the starting state
        return color[1][2][MOUSE_TURN];
    }
};
