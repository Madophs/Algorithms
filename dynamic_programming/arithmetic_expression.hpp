#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int64_t>> Matrix;

class MinMaxArithmeticExpression
{
public:
    MinMaxArithmeticExpression(const string& i_expression);
    void parseExpression();
    Matrix& getMaxMemo();
    Matrix& getMinMemo();
    inline int64_t opx(const int64_t& a, const int64_t& b, const char& oper);
    string constructMaxSolution();
    string constructMinSolution();
    void evaluate();
    int64_t max() const;
    int64_t min() const;
private:
    void minMax(const int& i, const int& j);
    string do_constructSolution(const uint32_t& targetY, const uint32_t& targetX, const int64_t& targetValue);

    bool do_constructIfTargetFound(string& result, const int32_t& targetValue,
        const Matrix& memo1, const int32_t& rowi, const int32_t& rowj,
        const Matrix& memo2, const int32_t& rowy, const int32_t& rowx);

    inline bool solutionConstructionComplete(string& result, const int32_t& targetValue,
            const int32_t& rowi, const int32_t& rowj,
            const int32_t& rowy, const int32_t& rowx);

    string m_expression;
    vector<int> m_constants;
    vector<char> m_operands;
    Matrix m_minMemo, m_maxMemo;
};
