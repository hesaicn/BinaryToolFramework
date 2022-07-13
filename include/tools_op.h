// #ifndef TOOLS_OP_H
// #define TOOLS_OP_H

#include <functional>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class ToolsOp
{
public:
    struct ToolsOption
    {
        string name;
        function<string(void)> help;
        function<int(vector<string> args)> exec;
    };

    string GetOpName()
    {
        return options_.name;
    }

    int exec(vector<string> args) const
    {
        return options_.exec(args);
    }

    static bool Register(ToolsOp op);

    static vector<ToolsOp>& GetAllOps();

    ToolsOp(ToolsOption op) : options_(op) {}

    ~ToolsOp(){};

private:
    ToolsOption options_;
    static inline vector<ToolsOp> toolsOps_;
};
// #endif