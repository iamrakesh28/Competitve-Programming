#include <queue>

void update(ifstream &fp, string msg, ResultStruct &r_obj, bool correct) {
    if (correct) {
        r_obj.result = true;
        r_obj.score = 1.0f;
        r_obj.message = msg;
    }
    else {
        r_obj.result = false;
        r_obj.score = 0;
        r_obj.message = msg;
    }
    fp.close();
}

bool valid(int i, int j, int n, int m) {
  if (i >= 0 && i < n && j >= 0 && j < m)
    return true;
  return false;
}

void path_checker(vector <pair <int, int>> &path, ifstream &inp, ResultStruct &r_obj) {
    int n, m;
    inp >> n >> m;
    vector <string> mat(n);
    vector <vector <bool>> visit(n, vector <bool> (m, false));
    vector <vector <int>> dist(n, vector <int> (m, 0));
    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
    for (int i = 0; i < n; ++i)
        inp >> mat[i];
    queue <pair <int, int>> q;
    pair <int, int> S, T;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (mat[i][j] == '#')
                visit[i][j] = true;
            else if (mat[i][j] == '*') {
                visit[i][j] = true;
                q.push({i, j});
            }
            else if (mat[i][j] == 'S')
                S = {i, j};
            else if (mat[i][j] == 'T')
                T = {i, j};
    if (path[0] != S || path[path.size() - 1] != T)
        return update(inp, "Source/Destination not same as in the input", r_obj, false);
    
    // computes virus reaching time
    while (q.size()) {
        auto u = q.front();
        q.pop();
        for (int d = 0; d < 4; ++d) {
            int r, c;
            r = dr[d] + u.first, c = dc[d] + u.second;
            if (valid(r, c, n, m) && visit[r][c] == false) {
                visit[r][c] = true;
                dist[r][c] = dist[u.first][u.second] + 1;
                q.push({r, c});
            }
        }
    }
    
    // checks the path
    int time_ = 0;
    for (int i = 0; i < path.size() - 1; ++i) {
        auto cur = path[i];
        auto nxt = path[i + 1];
        if (dist[cur.first][cur.second] <= time_)
            return update(inp, "Landed in a infected city", r_obj, false);
        bool val = false;
        for (int d = 0; d < 4; ++d) {
            int r, c;
            r = dr[d] + cur.first, c = dc[d] + cur.second;
            if (valid(r, c, n, m) && make_pair(r, c) == nxt) {
                val = true;
                break;
            }
        }
        if (val == false)
            return update(inp, "Invalid move", r_obj, false);
        time_++;
    }
    auto cur = path[path.size() - 1];
    if (dist[cur.first][cur.second] <= time_)
        return update(inp, "Landed in a infected city", r_obj, false);
    return update(inp, "Correct Answer", r_obj, true);
}

void run_custom_checker(const TestStruct t_obj,
                        ResultStruct &r_obj) {
    //Don't print anything to STDOUT in this function
    //Enter your custom checker scoring logic here
    ifstream fp(t_obj.testcase_output_path, ios :: in);
    if (fp.is_open() == false)
        return update(fp, "Error in reading output file", r_obj, false);
    int size;
    fp >> size;
    if (size == -1) {
        ifstream exp(t_obj.testcase_expected_output_path, ios :: in);
        if (exp.is_open() == false)
            return update(fp, "Error in reading expected output file", r_obj, false);
        int ans;
        exp >> ans;
        exp.close();
        if (ans == -1)
            return update(fp, "Correct Answer", r_obj, true);
        return update(fp, "Wrong answer, there exists a path", r_obj, false);
    }
    else if (size < 0)
        return update(fp, "Path length is invalid", r_obj, false);
    vector <pair <int, int>> ans;
    int x, y;
    while (fp >> x >> y)
        ans.push_back({x - 1, y - 1});
    if (ans.size() != size)
       return update(fp, "Total number of cities is inconsistent", r_obj, false);
    ifstream inp(t_obj.testcase_input_path, ios :: in);
    if (inp.is_open() == false)
        return update(fp, "Error in reading input file", r_obj, false);
    fp.close();
    return path_checker(ans, inp, r_obj);
}
