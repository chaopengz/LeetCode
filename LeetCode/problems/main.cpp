#include "032.cpp"

int main()
{
    Solution s;
    std::cout << s.longestValidParentheses("()(()") << std::endl; //2
    std::cout << s.longestValidParentheses("(()(()") << std::endl;//2
    std::cout << s.longestValidParentheses("(()(()))") << std::endl;//8
    std::cout << s.longestValidParentheses("()(())") << std::endl;//6
    std::cout << s.longestValidParentheses("())") << std::endl;//2
    std::cout << s.longestValidParentheses(")(((((()())()()))()(()))(") << std::endl;
}