class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        unordered_map<string, int> hash1;
        for (auto& st : words)
        {
            hash1[st]++;
        }
        vector<int > ret;
        int len = words[0].size(), num = words.size();
        for (int flag = 0; flag < len; flag++)
        {
            unordered_map<string, int>hash2;
            for (int left = flag, right = flag, count = 0; right + len <= s.size(); right += len)
                //这里也是需要注意的小点 right+len<=s.size()
            {
                //发现出窗口不应该和判断绑在一块
                string in = s.substr(right, len);
                if (++hash2[in] <= hash1[in])count++;

                if (right - left + 1 > len * num)
                {
                    string out = s.substr(left, len);
                    if (hash2[out]-- <= hash1[out]) count--;
                    left += len;
                }

                if (count == num)
                    ret.push_back(left);
                //这道题主要是错在误以为出窗口是应该和判断同时进行，其实是可以分开进行的
            }
        }

        return ret;
    }
};