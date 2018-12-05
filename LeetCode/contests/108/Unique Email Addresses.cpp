//
// Created by laryzhang on 2018/11/1.
//
#include "../head.h"

class Solution
{
public:
    std::vector<std::string> split(const std::string &str, char delimiter)
    {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(str);
        while (std::getline(tokenStream, token, delimiter))
        {
            tokens.push_back(token);
        }
        return tokens;
    }

    int numUniqueEmails(vector<string> &emails)
    {
        int ans = 0;
        unordered_map<string, vector<string>> domains;

        for (auto email: emails)
        {
            std::vector<std::string> tokens = split(email, '@');
            std::string local = tokens[0];
            std::string domain = tokens[1];
            std::transform(local.begin(), local.end(), local.begin(), ::tolower);
            if (local.find('.') != std::string::npos)
            {
                std::string temp;
                std::remove_copy(local.begin(), local.end(), std::back_inserter(temp), '.');
//                std::replace(local.begin(), local.end(), '.', '');
                local = temp;
            }
            if (local.find('+') != std::string::npos)
            {
                local = split(local, '+')[0];
            }

            std::vector<string> exist_names = domains[domain];
            if (std::find(exist_names.begin(), exist_names.end(), local) == exist_names.end())//not in
            {
                domains[domain].push_back(local);
            }
        }
        for (auto it = domains.begin(); it != domains.end(); it++)
        {
            ans += it->second.size();
        }
        return ans;
    }
};
