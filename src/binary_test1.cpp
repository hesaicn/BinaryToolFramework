#include "../include/tools_op.h"
#include <iostream>
using namespace std;
static string help()
{
    return "Usage: 1231231";
}

static int exec(vector<string> args)
{
    for (auto &i : args)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

static bool g_isok = ToolsOp::Register(ToolsOp::ToolsOption{
    .name = "test1",
    .rules = {
        {
            .name = "filePath",
            .isRepeat = true,
        },
    },
    .help = help,
    .exec = exec,
});