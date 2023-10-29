//
// Created by B on 8/12/2023.
//
using namespace std;
#include <vector>
#include <sstream>
#include "resources.h"

void resources::set_patterns() {
    ifstream json_file("pattern.json");

    if (!json_file) {
        cout << "CAN'T OPEN JSON" << endl;
        return;
    }
    string json_data(
            (istreambuf_iterator<char>(json_file)),
            (istreambuf_iterator<char>())
    );
    json_file.close();

    size_t pos = 0;
    while (pos != string::npos) {
        pos = json_data.find("\"name\": \"", pos);
        if (pos != string::npos) {
            pos += 9;
            //  pattern name
            size_t nameEnd = json_data.find("\"", pos);
            if (nameEnd != string::npos) {
                string patternName = json_data.substr(pos, nameEnd - pos);

                size_t pattern_start = json_data.find("[[", nameEnd);
                size_t pattern_end = json_data.find("]]", pattern_start);

                if (pattern_start != string::npos && pattern_end != string::npos) {
                    string patternData = json_data.substr(pattern_start, pattern_end - pattern_start + 2);

                    // Example: Parsing the pattern data
                    vector<vector<int>> patt;
                    size_t rowStart = patternData.find("[[");
                    size_t rowEnd = patternData.find("],", rowStart);
                    while (rowEnd != string::npos) {
                        // Extract a row of data
                        string row = patternData.substr(rowStart + 2, rowEnd - rowStart - 2);
                        vector<int> patt_row;

                        istringstream row_stream(row);
                        string cell;
                        while (getline(row_stream, cell, ',')) {
                            patt_row.push_back(stoi(cell));
                        }
                        patt.push_back(patt_row);
                        rowStart = patternData.find("[", rowEnd);
                        rowEnd = patternData.find("],", rowStart);
                    }

                    if (rowStart != string::npos) {
                        string lastRow = patternData.substr(rowStart + 2, patternData.size() - rowStart - 4);
                        vector<int> lastPatternRow;
                        istringstream lastRowStream(lastRow);
                        string cell;
                        while (getline(lastRowStream, cell, ',')) {
                            lastPatternRow.push_back(stoi(cell));
                        }
                        patt.push_back(lastPatternRow);
                    }

                    patterns[patternName] = patt;
                }
            }
        }
    }
}
string resources::random(){
        string u = "smiles";
        int n = ((rand() % patterns.size()));
        auto it = patterns.begin();
        for (int i=0;i<n;i++){
            u=it->first;
            it++;
        }
        return u;
}
