#include <iostream>
#include <vector>

template<typename T>
struct Segment_tree{

    Segment_tree() : arr(std::vector<T>()), size(0) {
        std::cout << "Segment_tree() " << this << std::endl;}

    ~Segment_tree() {
        std::cout << "~Segment_tree() " << this << std::endl;}

    Segment_tree& operator=(const Segment_tree& other){
        if(&other == this)
            return *this;
        arr = other.arr;
        size = other.size();
        std::cout << "copy tree " << this << std::endl;}

    Segment_tree& operator=(Segment_tree&& other){
        if(&other == this)
            return *this;
        std::swap(arr, other.arr);
        std::swap(size, other.size);
        std::cout << "move and swap tree " << this << std::endl;
        return *this;}

    Segment_tree(Segment_tree&& other) : arr(std::move(other.arr)), size(arr.size()){
        std::cout << "move tree " << this << std::endl;}

    Segment_tree(std::vector<T>&& vec) : arr(std::move(vec)), size(arr.size()){
        std::cout << "move vec " << this << std::endl;}

    Segment_tree(const std::vector<T>& vec) : arr(vec), size(arr.size()){
        std::cout << "copy vec " << this << std::endl;}

private:

    std::vector<T> arr;
    size_t size;

};

int main()
{
//    std::vector<int> a{3,5,6,3,2,1,76,4};
    Segment_tree<int> b{std::vector<int>{23,5,6,7}};
//    Segment_tree<int> h(std::move(b));
//    Segment_tree<int> t(a);

    Segment_tree<int> bb(std::move(b));
//    Segment_tree<int>();

    return 0;
}
