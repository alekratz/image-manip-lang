#ifndef AST_TREE_LIST_HPP
#define AST_TREE_LIST_HPP

#include "tree.hpp"
#include "line.hpp"
#include "expr.hpp"
#include <vector>

namespace ast {

template<typename contained_t>
class tree_list
    : public tree
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
    auto size() { return members.size(); }
    void merge(const tree_list<contained_t>& other)
    {
        auto& them = other.members;
        members.reserve(members.size() + them.size());
        members.insert(members.cend(). them.cbegin(), them.cend());
    }

public:
    virtual void accept(visitor* guest) = 0;
    virtual void children_accept(visitor* guest)
    {
        accept(guest);
        for(auto iter = members.begin(); iter != members.end(); iter++)
            (*iter)->accept(guest);
    }
    virtual void traverse_top_down(visitor* guest)
    {
        accept(guest);
        for(auto iter = members.begin(); iter != members.end(); iter++)
            (*iter)->traverse_top_down(guest);
    }

    virtual void traverse_bottom_up(visitor* guest)
    {
        for(auto iter = members.begin(); iter != members.end(); iter++)
            (*iter)->traverse_bottom_up(guest);
        accept(guest);
    }

};

class args_list
    : public tree_list<expr_p>
{
private:
    typedef tree_list<expr_p> base_t;
public:
    virtual void accept(visitor* guest);
    virtual void children_accept(visitor* guest);
};
typedef std::shared_ptr<args_list> args_list_p;

class line_list
    : public tree_list<line_p>
{
private:
    typedef tree_list<line_p> base_t;
public:
    virtual void accept(visitor* guest);
    virtual void children_accept(visitor* guest);
};
typedef std::shared_ptr<line_list> line_list_p;

} /* namespace ast */
#endif