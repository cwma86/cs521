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

    inline void setSrc(int src)
    { src_ = src;}

    inline int getSrc() const
    {return src_;}

    inline void setDest(int dest)
    { dest_ = dest;}

    inline int getDest() const
    {return dest_;}

    inline void setWeight(int weight)
    { weight_ = weight;}

    inline int getWeight() const
    {return weight_;}

private:
    int src_;
    int dest_;
    int weight_;
};
#endif