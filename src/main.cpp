#include "../include/tools_op.h"
#include <iostream>
#include <getopt.h>
#include <map>
#include <string>
using namespace std;
int exec(int argc, char *argv[])
{
    if (argc < 2) {
        return -1;
    }
    vector<string> args;
    for (int i = 2; i < argc; i++) {
        args.push_back(argv[i]);
    }
    vector<ToolsOp> &ops = ToolsOp::GetAllOps();
    auto it = std::find_if(ops.begin(), ops.end(), [&](ToolsOp &op) {
        return op.GetOpName() == argv[1];
    });
    if (it == ops.end()) {
        return -EPERM;
    }
    int send = 0;
    vector<option> options;
    vector<ToolsOp::MatchRules> rules = it->GetMatchRules();
    for (auto &i : rules) {
        options.emplace_back(option {
            .name = i.name.c_str(),
            .has_arg = required_argument,
            .flag = nullptr,
            .val = send++,
        });
    }
    vector<string> arg;
    options.emplace_back(option { nullptr, 0, nullptr, 0 });
    int opt;
    while((opt = getopt_long_only(argc, argv, "", options.data(), nullptr)) != -1) {
        // cout << optarg << opt << endl;
        arg.emplace_back(string(optarg));
    }
    it->exec(arg);
    return -EPERM;
}
int main(int argc, char *argv[])
{
    return exec(argc, argv);
}