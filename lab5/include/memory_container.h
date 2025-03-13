#ifndef MEMORY_CONTAINER_H
#define MEMORY_CONTAINER_H

#if __has_include(<memory_resource>)
#include <memory_resource>
#else
#include <experimental/memory_resource>
namespace std {
    namespace pmr = std::experimental::pmr;
}
#endif

#include <list>
#include <iostream>
#include <cstddef>
#include <iterator>

// Структура для хранения информации о блоках памяти
struct MemoryBlock {
    void* ptr;
    size_t size;
    bool is_free;
};

// fixed_memory_resource – наследник std::pmr::memory_resource,
// реализующий стратегию работы с фиксированным блоком памяти с повторным использованием.
class fixed_memory_resource : public std::pmr::memory_resource {
    char* buffer_;
    size_t buffer_size_;
    std::list<MemoryBlock> blocks_;

public:
    explicit fixed_memory_resource(size_t size);
    ~fixed_memory_resource();

private:
    void* do_allocate(size_t bytes, size_t alignment) override;
    void do_deallocate(void* p, size_t bytes, size_t alignment) override;
    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override;
};

// Шаблонный контейнер – однонаправленный список, использующий std::pmr::polymorphic_allocator.
template<typename T>
class singly_linked_list {
private:
    // Определяем тип узла до объявления итератора
    struct Node {
        T value;
        Node* next;
        Node(const T& val, Node* nxt = nullptr) : value(val), next(nxt) {}
    };

public:
    // Итератор, соответствующий std::forward_iterator_tag
    class iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type        = T;
        using difference_type   = std::ptrdiff_t;
        using pointer           = T*;
        using reference         = T&;

        iterator() : node_(nullptr) {}
        explicit iterator(Node* node) : node_(node) {}

        reference operator*() const { return node_->value; }
        pointer operator->() const { return &(node_->value); }

        iterator& operator++() {
            if (node_) node_ = node_->next;
            return *this;
        }

        iterator operator++(int) {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        bool operator==(const iterator& other) const { return node_ == other.node_; }
        bool operator!=(const iterator& other) const { return node_ != other.node_; }

    private:
        Node* node_;
        friend class singly_linked_list;
    };

    using allocator_type = std::pmr::polymorphic_allocator<Node>;

    explicit singly_linked_list(std::pmr::memory_resource* res = std::pmr::get_default_resource());
    ~singly_linked_list();

    // Вставка элемента в конец списка
    void push_back(const T& value);
    // Очистка списка
    void clear();
    // Текущий размер списка
    size_t size() const;

    iterator begin();
    iterator end();

private:
    Node* head_;
    Node* tail_;
    size_t size_;
    std::pmr::polymorphic_allocator<Node> alloc_;
};

//////////////////////////////
// Реализация шаблонных методов

template<typename T>
singly_linked_list<T>::singly_linked_list(std::pmr::memory_resource* res)
        : head_(nullptr), tail_(nullptr), size_(0), alloc_(res)
{}

template<typename T>
singly_linked_list<T>::~singly_linked_list() {
    clear();
}

template<typename T>
void singly_linked_list<T>::push_back(const T& value) {
    Node* new_node = alloc_.allocate(1);
    alloc_.construct(new_node, value, nullptr);
    if (!head_) {
        head_ = tail_ = new_node;
    } else {
        tail_->next = new_node;
        tail_ = new_node;
    }
    ++size_;
}

template<typename T>
void singly_linked_list<T>::clear() {
    Node* current = head_;
    while (current) {
        Node* temp = current;
        current = current->next;
        alloc_.destroy(temp);
        alloc_.deallocate(temp, 1);
    }
    head_ = tail_ = nullptr;
    size_ = 0;
}

template<typename T>
size_t singly_linked_list<T>::size() const {
    return size_;
}

template<typename T>
typename singly_linked_list<T>::iterator singly_linked_list<T>::begin() {
    return iterator(head_);
}

template<typename T>
typename singly_linked_list<T>::iterator singly_linked_list<T>::end() {
    return iterator(nullptr);
}

#endif // MEMORY_CONTAINER_H
