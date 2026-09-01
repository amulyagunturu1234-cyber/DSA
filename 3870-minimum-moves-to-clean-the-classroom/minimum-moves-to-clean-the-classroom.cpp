class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;
        int cnt = 0;

        // Give every litter cell a number: 0, 1, 2...
        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = cnt;
                    cnt++;
                }
            }
        }

        // No litter
        if (cnt == 0)
            return 0;

        /*
            mask:
            1 = litter is NOT collected
            0 = litter is collected

            Example: 3 litter cells

            111 -> none collected
            101 -> middle collected
            000 -> all collected
        */

        int fullMask = (1 << cnt) - 1;

        // visited[row][col][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << cnt, false)
                )
            )
        );

        // row, col, remaining energy, mask
        queue<tuple<int, int, int, int>> q;

        q.push({sr, sc, energy, fullMask});

        visited[sr][sc][energy][fullMask] = true;

        int moves = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int size = q.size();

            // Process one BFS level
            while (size--) {

                auto [r, c, currEnergy, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == 0)
                    return moves;

                // No energy -> cannot move
                if (currEnergy == 0)
                    continue;

                // Try 4 directions
                for (int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    // Outside grid
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    // Obstacle
                    if (classroom[nr][nc] == 'X')
                        continue;

                    // Every normal move costs 1 energy
                    int newEnergy = currEnergy - 1;

                    // Reset area
                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    int newMask = mask;

                    // If we reach litter, collect it
                    if (classroom[nr][nc] == 'L') {

                        int litterNumber = id[nr][nc];

                        newMask = newMask & ~(1 << litterNumber);
                    }

                    // Haven't visited this exact state
                    if (!visited[nr][nc][newEnergy][newMask]) {

                        visited[nr][nc][newEnergy][newMask] = true;

                        q.push({
                            nr,
                            nc,
                            newEnergy,
                            newMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};