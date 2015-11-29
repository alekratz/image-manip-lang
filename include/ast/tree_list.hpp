#ifndef AST_TREE_LIST_HPP
#define AST_TREE_LIST_HPP

#include "tree.hpp"
#include "exec.hpp"
#include <vector>

namespace ast {

template<typename contained_t>
class tree_list
{
public:
    tree_list() = default;
    virtual ~tree_list() = default;
public:
    std::vector<contained_t> members;
    void push_back(const contained_t& ptr)
        { members.push_back(ptr); }
    void push_front(const contained_t& ptr)
        { members.insert(members.begin(), ptr); }
    auto begin() { return members.begin(); }
    auto end() { return members.end(); }
    void merge(const tree_list<contained_t>& other)
    {
        auto& them = other.members;
        members.reserve(members.size() + them.size());
        members.insert(members.cend(). them.cbegin(), them.cend());
    }
};

typedef tree_list<exec_p> line_list;
typedef std::shared_ptr<line_list> line_list_p;

} /* namespace ast */
#endif