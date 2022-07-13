#include "../include/tools_op.h"
#include <iostream>
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
    if (it != ops.end()) {
        return it->exec(args);
    }
    return -EPERM;
}
int main(int argc, char *argv[])
{
    return exec(argc, argv);
}