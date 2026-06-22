#include <string>
#include <vector>

class Solution {
public:
    string entityParser(string text) {
        // Entities aur un ke characters ki list
        vector<pair<string, string>> entities = {
            {"&quot;", "\""},
            {"&apos;", "'"},
            {"&gt;", ">"},
            {"&lt;", "<"},
            {"&frasl;", "/"},
            {"&amp;", "&"} // &amp; aakhir mein
        };
        
        for (auto& p : entities) {
            size_t pos = text.find(p.first);
            while (pos != string::npos) {
                text.replace(pos, p.first.length(), p.second);
                pos = text.find(p.first, pos + p.second.length());
            }
        }
        return text;
    }
};
