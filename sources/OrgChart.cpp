#include <queue>
#include <iostream>
#include <stdexcept>

#include "OrgChart.hpp"

namespace ariel {

    // constractor:
    OrgChart::OrgChart() : _rootNode(nullptr) {}

    // destractor:
    OrgChart::~OrgChart() {
        this->clearChart();
    }

    // set root:
    OrgChart &OrgChart::add_root(const string &rootNodeObject) {

        if (_rootNode == nullptr) {
            NodeObject *rootNode = new NodeObject(rootNodeObject);
            this->_rootNode = rootNode;
        } else {
            string previousName = this->_rootNode->getName();
            this->_rootNode->setName(rootNodeObject);
            this->_namesMap.erase(previousName);
        }
        this->_namesMap.insert({rootNodeObject, this->_rootNode});

        return *this;
    }

    // add elements:
    OrgChart &OrgChart::add_sub(const string &father, const string &kid) {
        auto find = this->_namesMap.find(father);
        if (find != this->_namesMap.end()) {
            NodeObject *nodeObj = find->second;
            NodeObject *newKid = new NodeObject(kid);
            nodeObj->addKid(newKid);
            this->_namesMap.insert({kid, newKid});

        }
        else {
            throw invalid_argument("object is not found!");
        }
        return *this;
    }

    // clean chart:
    void OrgChart::clearChart() {
        if (_rootNode == nullptr) {
            return;
        }
        queue<NodeObject *> deleteQ;
        for (NodeObject *kid: this->_rootNode->getKids()) {
            deleteQ.push(kid);
        }
        delete this->_rootNode;
        while (!deleteQ.empty()) {
            NodeObject *toDelete = deleteQ.front();
            deleteQ.pop();
            for (NodeObject *kid: toDelete->getKids()) {
                deleteQ.push(kid);
            }
            delete toDelete;
        }
    }

    // Level Iterator:

    LevelIterator OrgChart::begin() {
        if(this->_rootNode == nullptr){
            throw invalid_argument("chart is empty, there is no root node!");
        }
        return LevelIterator(this->_rootNode);
    }

    LevelIterator OrgChart::end() {
        if(this->_rootNode == nullptr){
            throw invalid_argument("chart is empty, there is no root node!");
        }
        return LevelIterator(nullptr);
    }

    LevelIterator OrgChart::begin_level_order() {
        if(this->_rootNode == nullptr){
            throw invalid_argument("chart is empty, there is no root node!");
        }
        return LevelIterator(this->_rootNode);
    }

    LevelIterator OrgChart::end_level_order() {
        if(this->_rootNode == nullptr){
            throw invalid_argument("chart is empty, there is no root node!");
        }
        return LevelIterator(nullptr);
    }

    // Pre Order Iterator:
    PreOrderIterator OrgChart::begin_preorder() {
        if(this->_rootNode == nullptr){
            throw invalid_argument("chart is empty, there is no root node!");
        }
        return PreOrderIterator(this->_rootNode);
    }

    PreOrderIterator OrgChart::end_preorder() {
        if(this->_rootNode == nullptr){
            throw invalid_argument("chart is empty, there is no root node!");
        }
        return PreOrderIterator(nullptr);
    }

    // Reverse Iterator:
    ReverseIterator OrgChart::begin_reverse_order() {
        if(this->_rootNode == nullptr){
            throw invalid_argument("chart is empty, there is no root node!");
        }
        return ReverseIterator(this->_rootNode);
    }

    ReverseIterator OrgChart::reverse_order() {
        if(this->_rootNode == nullptr){
            throw invalid_argument("chart is empty, there is no root node!");
        }
        return OrgChart::end_reverse_order();
    }

    ReverseIterator OrgChart::end_reverse_order() {
        if(this->_rootNode == nullptr){
            throw invalid_argument("chart is empty, there is no root node!");
        }
        return ReverseIterator(nullptr);
    }


    // operators:

    ostream &operator<<(ostream &outputStream, const OrgChart &chart) {
        outputStream << "...";
        return outputStream;
    }
}