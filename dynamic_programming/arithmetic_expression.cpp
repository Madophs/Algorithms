#include "arithmetic_expression.hpp"

constexpr int64_t MIN_VALUE = static_cast<int64_t>(numeric_limits<int>::min());
constexpr int64_t MAX_VALUE = static_cast<int64_t>(numeric_limits<int>::max());

template <typename... Values>
int64_t maxv(Values... vals)
{
    int64_t res = MIN_VALUE;
    for (auto& val : {vals...}) {
        res = max(static_cast<int64_t>(val), res);
    }
    return res;
}

template <typename... Values>
int64_t minv(Values... vals)
{
    int64_t res = MAX_VALUE;
    for (auto& val : {vals...}) {
        res = min(static_cast<int64_t>(val), res);
    }
    return res;
}

MinMaxArithmeticExpression::MinMaxArithmeticExpression(const string& i_expression)
    :m_expression(i_expression)
{
    this->parseExpression();
}

void MinMaxArithmeticExpression::parseExpression()
{
    string digit("");
    for (uint32_t i = 0; i < m_expression.length(); ++i) {
        const char& c = m_expression[i];
        if (isdigit(c)) {
            digit.push_back(c);
        } else {
            m_operands.push_back(c);
            m_constants.push_back(atoi(digit.c_str()));
            digit.clear();
        }
    }
    m_constants.push_back(atoi(digit.c_str()));
}

Matrix& MinMaxArithmeticExpression::getMaxMemo()
{
    return m_maxMemo;
}

Matrix& MinMaxArithmeticExpression::getMinMemo()
{
    return m_minMemo;
}

int64_t MinMaxArithmeticExpression::opx(const int64_t& a, const int64_t& b, const char& oper)
{
    switch (oper) {
        case '*':
            return a * b;
        case '+':
            return a + b;
        default:
            return a - b;
    }
}

void MinMaxArithmeticExpression::minMax(const int& i, const int& j)
{
    int64_t minval = MAX_VALUE;
    int64_t maxval = MIN_VALUE;
    for (int k = i; k < j; ++k) {
        int64_t a = opx(m_maxMemo[i][k], m_maxMemo[k+1][j], m_operands[k]);
        int64_t b = opx(m_maxMemo[i][k], m_minMemo[k+1][j], m_operands[k]);
        int64_t c = opx(m_minMemo[i][k], m_minMemo[k+1][j], m_operands[k]);
        int64_t d = opx(m_minMemo[i][k], m_maxMemo[k+1][j], m_operands[k]);
        minval = minv(a, b, c, d, minval);
        maxval = maxv(a, b, c, d, maxval);
    }
    m_minMemo[i][j] = minval;
    m_maxMemo[i][j] = maxval;
}

string MinMaxArithmeticExpression::constructMaxSolution()
{
    return do_constructSolution(0u, m_maxMemo.size()-1u, m_maxMemo.front().back());
}

string MinMaxArithmeticExpression::constructMinSolution()
{
    return do_constructSolution(0u, m_minMemo.size()-1u, m_minMemo.front().back());
}

bool MinMaxArithmeticExpression::do_constructIfTargetFound(string& result, const int32_t& targetValue,
        const Matrix& memo1, const int32_t& rowi, const int32_t& rowj,
        const Matrix& memo2, const int32_t& rowy, const int32_t& rowx)
{
    int64_t res = opx(memo1[rowi][rowj], memo2[rowy][rowx], m_operands[rowj]);
    if (res == targetValue) {
        result += do_constructSolution(rowi, rowj, memo1[rowi][rowj]);
        result += m_operands[rowj];
        result += do_constructSolution(rowy, rowx, memo2[rowy][rowx]);
        return true;
    }
    return false;
}

inline bool MinMaxArithmeticExpression::solutionConstructionComplete(
        string& result, const int32_t& targetValue,
        const int32_t& rowi, const int32_t& rowj,
        const int32_t& rowy, const int32_t& rowx)
{
    return do_constructIfTargetFound(result, targetValue, m_maxMemo, rowi, rowj, m_maxMemo, rowy, rowx)
        || do_constructIfTargetFound(result, targetValue, m_maxMemo, rowi, rowj, m_minMemo, rowy, rowx)
        || do_constructIfTargetFound(result, targetValue, m_minMemo, rowi, rowj, m_minMemo, rowy, rowx)
        || do_constructIfTargetFound(result, targetValue, m_minMemo, rowi, rowj, m_maxMemo, rowy, rowx);
}


string MinMaxArithmeticExpression::do_constructSolution(const uint32_t& targetY, const uint32_t& targetX, const int64_t& targetValue)
{
    if (targetY == targetX) {
        return to_string(targetValue);
    }
    string result = "(";
    uint32_t rowi = targetY, rowj = targetY;
    uint32_t rowy = targetY + 1u, rowx = targetX;
    while(!solutionConstructionComplete(result, targetValue, rowi, rowj, rowy, rowx)) {
        ++rowj, ++rowy;
    }
    return result + ")";
}

void MinMaxArithmeticExpression::evaluate()
{
    const int n = (int)m_constants.size();
    m_minMemo.resize(n, vector<int64_t>(n, 0ll)), m_maxMemo.resize(n, vector<int64_t>(n, 0ll));
    for (int i = 0; i < n; ++i) {
        m_minMemo[i][i] = m_maxMemo[i][i] = static_cast<int64_t>(m_constants[i]);
    }
    for (int s = 1; s < n; ++s) {
        for (int i = 0; i < n-s; ++i) {
            int j = i + s;
            minMax(i, j);
        }
    }
}

int64_t MinMaxArithmeticExpression::max() const
{
    return m_maxMemo.front().back();
}

int64_t MinMaxArithmeticExpression::min() const
{
    return m_minMemo.front().back();
}

