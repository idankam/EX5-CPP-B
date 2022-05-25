#ifndef NodeObjectHPP
#define NodeObjectHPP

#include <string>
#include <vector>

using namespace std;

namespace ariel {

    class NodeObject {

    private:
        vector<NodeObject *> _kids;
        string _name;
        
    public:
        NodeObject();
        NodeObject(const string &name);
        NodeObject(const string &name, const vector<NodeObject *> &kids);
        
        void setName(const string &name);
        const string &getName() const;

        void addKid(NodeObject *newkid);
        const vector<NodeObject *> &getKids() const;
        size_t size();
        size_t length();
        char at(size_t pos);

        const string getName() {return _name;}
        friend ostream &operator<<(ostream &outputStream, const NodeObject &currNodeObject);
        friend bool operator==(const NodeObject obj, const string name);
        friend bool operator==(const string name, const NodeObject obj);
        
   };
}

#endif
