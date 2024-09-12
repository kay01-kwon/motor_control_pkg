#ifndef SCOPED_PTR_HPP
#define SCOPED_PTR_HPP

#include <cassert>

template <typename T>
class scoped_ptr
{
    public: 
    explicit scoped_ptr(T* ptr = nullptr) : ptr_(ptr)
    {
    }

    ~scoped_ptr()
    {
        delete ptr_;
    }

    T* get() const
    {
        return ptr_;
    }

    T* operator->() const
    {
        assert(ptr_ != nullptr);
        return ptr_;
    }

    T* operator=(T* ptr)
    {
        if (ptr_ != ptr)
        {
            delete ptr_;
            ptr_ = ptr;
        }
    }

    private:
    T* ptr_;
};


#endif