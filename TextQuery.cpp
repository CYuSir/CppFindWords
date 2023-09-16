#include "TextQuery.h"

#include "QueryResult.h"


std::string make_plural(size_t n, const std::string &word, const std::string &suffix) {
    return (n > 1) ? word + suffix : word;
}

TextQuery::TextQuery(std::ifstream &is) : file(new vector<string>) {
    std::string text;
    if (!is.is_open()) {
        std::cout << "file ptr is nullptr." << std::endl;
        return;
    }
    while (getline(is, text)) {
        file->push_back(text);
        int n = file->size() - 1;
#if 1
        std::sregex_iterator wordIterator(text.begin(), text.end(), word_regex);
        std::sregex_iterator endIterator;

        std::string word;
        while (wordIterator != endIterator) {
            word = wordIterator->str();
            auto &lines = wm[word];
            if (!lines) {
                // lines.reset(new set<line_no>);
                lines = std::make_shared<set<line_no>>();
            }
            lines->insert(n);

            ++wordIterator;
        }
#else
        std::istringstream line(text);

        std::string word;
        while (line >> word) {
            auto &lines = wm[word];
            if (!lines) {
                // lines.reset(new set<line_no>);
                lines = std::make_shared<set<line_no>>();
            }
            lines->insert(n);
        }
#endif
    }
}

QueryResult TextQuery::query(const std::string &sought) const {
    static std::shared_ptr<set<line_no>> nodata(new set<line_no>);

    auto loc = wm.find(sought);
    if (loc == wm.end()) {
        return QueryResult(sought, nodata, file);
    } else {
        return QueryResult(sought, loc->second, file);
    }
}

std::ostream &print(ostream &os, const QueryResult &qr) {
    os << qr.sought << " occurs " << qr.lines->size() << " " << make_plural(qr.lines->size(), "time", "s") << endl;

    for (auto num : *qr.lines) {
        os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
    }

    return os;
}