#include <unordered_map>

using namespace std;

class LRUCache {
private:
  struct Node {
    int key;
    int value;
    Node *next;
    Node *prev;
    Node() : key(-1), value(-1), next(nullptr), prev(nullptr) {}
    Node(int key, int value)
        : key(key), value(value), next(nullptr), prev(nullptr) {}
  };
  int capacity;
  // 双向环形链表
  Node *dummy;
  unordered_map<int, Node *> hash;

  void insert_front(Node *node) {
    node->prev = dummy;
    node->next = dummy->next;
    node->prev->next = node;
    node->next->prev = node;
  }

  void remove(Node *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  // 写成private的吧
  Node *get_node(int key) {
    auto it = hash.find(key);
    if (it == hash.end()) {
      return nullptr;
    }
    auto node = it->second;
    remove(node);
    insert_front(node);
    return node;
  }

public:
  // 你就在初始化列表里面写呗
  LRUCache(int capacity) : capacity(capacity), dummy(new Node()) {
    dummy->prev = dummy;
    dummy->next = dummy;
  }

  ~LRUCache() {
    auto curr = dummy->next;
    while (curr != nullptr) {
      if (curr == dummy)
        break;
      auto temp = curr;
      curr = curr->next;
      hash.erase(temp->key);
      delete temp;
    }
    delete dummy;
  }

  void put(int key, int value) {
    auto node = get_node(key);
    if (node == nullptr) {
      node = new Node(key, value);
      insert_front(node);
      hash[key] = node;
      if (hash.size() > capacity) {
        auto back = dummy->prev;
        hash.erase(back->key);
        remove(back);
        delete back;
      }

      // 匹配的是上面的if
    } else {
      node->value = value;
      remove(node);
      insert_front(node);
    }
  }

  int get(int key) {
    auto node = get_node(key);
    return node == nullptr ? -1 : node->value;
  }
};

int main(int argc, char *argv[]) { return 0; }
