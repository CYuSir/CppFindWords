#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class QueryResult;

std::regex word_regex("[a-zA-Z]+");

std::string make_plural(size_t, const std::string&, const std::string& suffix = "s");

class TextQuery {
   public:
    using line_no = std::vector<std::string>::size_type;

    TextQuery(std::ifstream&);

    QueryResult query(const std::string&) const;

   private:
    // 输入文件
    std::shared_ptr<std::vector<std::string>> file;
    // 每个单词到他所在的行号的集合的映射
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};