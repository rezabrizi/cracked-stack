
#pragma once
#include <algorithm>
#include <climits>
#include <vector>

namespace on {
    class stack{

    public:
        void push(int element)
        {
            stack.push_back(element);
        }

        int pop()
        {
            if (stack.empty())
                throw std::runtime_error("stack is empty");
            int top = stack.back();
            stack.pop_back();
            return top;
        }

        bool increment(size_t x, int v)
        {

            size_t n = stack.size();
            size_t i = (n < x) ? 0 : n-x;

            std::vector <int> temp (std::begin(stack)+i, stack.end());

            for (size_t j = 0; j < temp.size(); j++)
            {
                if (INT_MAX - temp[j] > v)
                {
                    temp[j] += v;
                }
                else
                {
                    return false;
                }
            }

            std::copy(temp.begin(), temp.end(), stack.begin()+i);
            return true;
        }

    private:
        std::vector<int> stack;
    };

}


