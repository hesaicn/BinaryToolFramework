#include "../include/tools_op.h"


bool ToolsOp::Register(ToolsOp op)
{
    vector<ToolsOp>::iterator iter;
    iter = std::find_if(toolsOps_.begin(), toolsOps_.end(), [op](ToolsOp &o)
                { return o.options_.name == op.options_.name; });
    
    if (iter == toolsOps_.end())
    {
        toolsOps_.push_back(op);
        return true;
    }
    return false;
}

vector<ToolsOp>& ToolsOp::GetAllOps()
{
    return toolsOps_;
}