/*
 * 禁止类继承
 */
template <typename T>
class smart_ptr final {
public:
  explicit smart_ptr(T* ptr = nullptr)  // explicit 要显式转型
    : ptr_(ptr) {}
  ~smart_ptr()
  {
    delete ptr_;
  }
  T* get() const { return ptr_; }

  T& operator*() const { return *ptr_; }  
  T* operator->() const { return ptr_; }  
  operator bool() const { return ptr_; }

   smart_ptr(const smart_ptr&)    = delete;  
   smart_ptr(smart_ptr&&)    = delete;  
   smart_ptr& operator=(const smart_ptr&)    = delete;
   smart_ptr& operator=(smart_ptr&&)    = delete;

   T* release() {T* ret = ptr_; prt_ = nullptr; return ret;}

   void exchange_with(smart_ptr<T>& h) {
    swap(ptr_, h.ptr_);
   }
   
   void exchange_with(T*& p) {
    swap(ptr_, p);
   }

private:
  T* ptr_;
};