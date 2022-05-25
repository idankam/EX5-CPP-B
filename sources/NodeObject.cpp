#include "NodeObject.hpp"
#include <iostream>

namespace ariel {

    // constractors:
    NodeObject::NodeObject() {}
    NodeObject::NodeObject(const string &name) : _name(name) {}
    NodeObject::NodeObject(const string &name, const vector<NodeObject *> &kids) : _name(name), _kids(kids) {}

    size_t NodeObject::size() {
        return this->_name.size();
    }

    size_t NodeObject::length() {
        return size();
    }

    char NodeObject::at(size_t pos){
        return _name.at(pos);
    }

    ostream &operator<<(ostream &outputStream, const NodeObject &currNodeObject) {
        outputStream << currNodeObject._name << " ";
        return outputStream;
    }

    bool operator==(const NodeObject &obj, const string &name) {
        return (obj.getName() == name);
    }

    bool operator==(const string &name, const NodeObject &obj) {
        return (obj.getName() == name);
    }

    const vector<NodeObject *> &NodeObject::getKids() const {
        return _kids;
    }

    const string &NodeObject::getName() const {
        return _name;
    }

    void NodeObject::addKid(NodeObject *newKid) {
        this->_kids.push_back(newKid);
    }

    void NodeObject::setName(const string &name) {
        _name = name;
    }

}