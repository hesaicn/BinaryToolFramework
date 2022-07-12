#include "../include/tools_op.h"
#include <iostream>
using namespace std;
static string help()
{
    return "Usage: 1231231";
}

static int exec(vector<string> args)
{
    for (auto &i : args) {
        cout << i << " ";
    }
    cout << endl;
}

ToolsOp::ToolsOption a = {
    .name = "test1",
    .help = help,
    .exec = exec,
};
ToolsOp::Register(a);