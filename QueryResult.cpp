#include "QueryResult.h"

QueryResult::QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p,
                         std::shared_ptr<std::vector<std::string>> f)
    : sought(s), lines(p), file(f) {}