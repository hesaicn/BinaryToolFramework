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

    static void Register(struct ToolsOption op)
    {
        vector<ToolsOption>::iterator iter;
        iter = find(options_.begin(), options_.end(), [op](ToolsOption &o)
                    { return o.name == op.name; });
        if (iter == options_.end())
        {
            options_.push_back(op);
        }
    }

    static int TryMatchAndExec(const string &command, const vector<string> &args) {
        vector<ToolsOption>::iterator iter;
        iter = find(options_.begin(), options_.end(), [command](ToolsOption &o)
                    { return o.name == command; });
        if (iter == options_.end()) {
            return -1;
        }
        return iter->exec(args);
    }

    ToolsOp() {}
    ~ToolsOp() {};
private:
    static vector<ToolsOption> options_;
};
// #endif