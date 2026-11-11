#include <iostream>
#include <string>
#include <utility>

class Train {
    struct Node {
        std::string code;
        int load;
        Node* next;
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    int total = 0;

    void clear() {
        while (head != nullptr) {
            Node* aux = head;
            head = head->next;
            delete aux;
        }
        tail = nullptr;
        total = 0;
    }

public:
    Train() = default;

    Train(const Train& other) {
        for (Node* p = other.head; p != nullptr; p = p->next) {
            pushTail(p->code, p->load);
        }
    }

    Train& operator=(const Train& other) {
        if (this != &other) {
            Train copy(other);
            std::swap(head, copy.head);
            std::swap(tail, copy.tail);
            std::swap(total, copy.total);
        }
        return *this;
    }

    ~Train() { clear(); }

    void pushHead(const std::string& c, int t) {
        Node* fresh = new Node{c, t, head};
        head = fresh;
        if (tail == nullptr) tail = fresh;
        total += t;
    }

    void pushTail(const std::string& c, int t) {
        Node* fresh = new Node{c, t, nullptr};
        if (tail == nullptr) head = fresh;
        else tail->next = fresh;
        tail = fresh;
        total += t;
    }

    bool remove(const std::string& c) {
        Node* prev = nullptr;
        Node* cur = head;
        while (cur != nullptr && cur->code != c) {
            prev = cur;
            cur = cur->next;
        }
        if (cur == nullptr) return false;
        if (prev == nullptr) head = cur->next;
        else prev->next = cur->next;
        if (cur == tail) tail = prev;
        total -= cur->load;
        delete cur;
        return true;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* cur = head;
        tail = head;
        while (cur != nullptr) {
            Node* following = cur->next;
            cur->next = prev;
            prev = cur;
            cur = following;
        }
        head = prev;
    }

    std::string describe() const {
        if (head == nullptr) return "EMPTY";
        std::string s;
        for (Node* p = head; p != nullptr; p = p->next) {
            s += p->code + ":" + std::to_string(p->load) + " ";
        }
        s += "(total " + std::to_string(total) + ")";
        return s;
    }
};

int main() {
    Train current;
    Train snapshot;
    std::string command;
    while (std::cin >> command) {
        if (command == "HEAD" || command == "TAIL") {
            std::string code;
            int t;
            std::cin >> code >> t;
            if (command == "HEAD") current.pushHead(code, t);
            else current.pushTail(code, t);
        } else if (command == "DROP") {
            std::string code;
            std::cin >> code;
            if (!current.remove(code)) std::cout << "NOT FOUND " << code << '\n';
        } else if (command == "REVERSE") {
            current.reverse();
        } else if (command == "SNAP") {
            snapshot = current;
        } else if (command == "RESTORE") {
            current = snapshot;
        } else if (command == "SHOW") {
            std::cout << current.describe() << '\n';
        }
    }
    std::cout << "FINAL " << current.describe() << '\n';
    return 0;
}
