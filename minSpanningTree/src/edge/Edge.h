#ifndef Edge_h
#define Edge_h
class Edge {
public:
    Edge():
        src_(0),
        dest_(0),
        weight_(0)
    {}
    Edge(int src, int dest, int weight):
        src_(src),
        dest_(dest),
        weight_(weight)
    {}

    void setSrc(int src)
    { src_ = src;}

    int getSrc() const
    {return src_;}

    void setDest(int dest)
    { dest_ = dest;}

    int getDest() const
    {return dest_;}

    void setWeight(int weight)
    { weight_ = weight;}

    int getWeight() const
    {return weight_;}

private:
    int src_;
    int dest_;
    int weight_;
};
#endif