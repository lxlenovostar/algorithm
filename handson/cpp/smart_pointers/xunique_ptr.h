/*
 * 实现智能指针unique_ptr的模版类
 * 1. 对原始指针的封装
 * 2. 支持make_unique()
 * 3. 如何释放的呢？
 */
template <typename T>
class Xuniqueptr {
private:
    T* elem;
public:
    explicit Xuniqueptr();
    ~Xuniqueptr()  { delete elem; }

    Xuniqueptr(const Xuniqueptr&) = delete;
    Xuniqueptr(Xuniqueptr&&) = delete;

    const Xuniqueptr &operator=(const Xuniqueptr&) = delete;
    const Xuniqueptr &operator=(Xuniqueptr&&) = delete;

    static T& instance();
    
    template< class T, class... Args >
    unique_ptr<T> make_unique( Args&&... args );
};