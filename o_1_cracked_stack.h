
#pragma once
#include <algorithm>
#include <vector>
#include <climits>

namespace o1 {
    class stack{

    public:
        stack(): top_increment(0){}

        void push(int element)
        {
            elements.push_back(element);
            v_increment.push_back(0);
        }

        int pop()
        {
            if (elements.empty())
                throw std::runtime_error("stack is empty!");

            int stack_top = elements.back();
            int temp = top_increment;

            top_increment -= v_increment.back();
            v_increment.pop_back();
            elements.pop_back();

            if (INT_MAX - stack_top >= top_increment)
                return stack_top + temp;
            throw std::runtime_error ("Element is too big! ");
        }

        void increment(size_t x, int v)
        {
            if (x <= 0)
                throw std::runtime_error("You have to at least increment 1 element");
            size_t idx = (x > elements.size()) ? 0: elements.size()-x;
            if (INT_MAX - top_increment < v)
                throw std::runtime_error("Increment is overflowing!");

            top_increment += v;
            v_increment[idx] += v;
        }

    private:
        std::vector<int> elements;
        std::vector<int> v_increment;
        int top_increment;
    };
}

