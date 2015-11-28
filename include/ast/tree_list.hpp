#ifndef AST_TREE_LIST_HPP
#define AST_TREE_LIST_HPP

#include "tree.hpp"
#include <vector>

namespace ast {

class tree_list
{
public:
    tree_list() = default;
    virtual ~tree_list() = 0;
public:
    std::vector<tree_p> members;
    void push_back(const tree_p& ptr) 
        { members.push_back(ptr); }
    void push_front(const tree_p& ptr) 
        { members.insert(members.begin(), ptr); }
    auto begin() { return members.begin(); }
    auto end() { return members.end(); }
};

typedef std::shared_ptr<tree_list> tree_list_p;

} /* namespace ast */
#endif