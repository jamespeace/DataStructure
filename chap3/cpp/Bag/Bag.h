class Bag
{
public:
    Bag(int bagCapacity = 10);
    ~Bag();

    int Size() const;
    bool IsEmpty() const;
    int Element() const;

    void Push(const int);
    void Pop();

private:
    int *array;
    int capacity;
    int top;
};

