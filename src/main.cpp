#include "../include/tools_op.h"
int exec(int argc, char *argv[])
{
    if (argc < 2) {
        return -1;
    }
    vector<string> args;
    for (int i = 2; i < argc; i++) {
        args.push_back(argv[i]);
    }
    ToolsOp::TryMatchAndExec(argv[1], args);
}
int main(int argc, char *argv[])
{
    return exec(argc, argv);
}