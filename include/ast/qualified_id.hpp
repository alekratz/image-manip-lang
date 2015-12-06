#ifndef AST_QUALIFIED_ID_HPP
#define AST_QUALIFIED_ID_HPP

#include "expr.hpp"
#include <vector>

namespace ast {

class qualified_id;
typedef std::shared_ptr<qualified_id> qualified_id_p;

class qualified_id 
    : public expr
{
public:
    qualified_id(cstref value)
        { members.push_back(value); }
    qualified_id() = default;
    virtual ~qualified_id() = default;

public:
    virtual void accept(visitor* guest);
    virtual void children_accept(visitor* guest);
    virtual void traverse_top_down(visitor* guest);
    virtual void traverse_bottom_up(visitor* guest);

    auto begin() { return members.begin(); }
    auto end() { return members.end(); }
    auto size() { return members.size(); }

    auto str(cstref divider = ".")
    {
        std::string result;
        for(size_t i = 0; i < members.size(); i++)
        {
            result += members[i];
            if(i + 1 < members.size())
                result += divider;
        }
        return result;
    }
public:
    std::vector<std::string> members;
};

} /* namespace ast */
#endif