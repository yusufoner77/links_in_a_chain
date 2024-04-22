#include <string>
#include <iostream>

using namespace std;

class ChainLink {
    private:
      string color;

    public:
      ChainLink(string color) {
        this->color = color;
      }

      string get_color() {
        return this->color;
      }
};

class Node {
  public:
    ChainLink *data;
    Node *next;
    
    Node(ChainLink *data, Node *prev_node = nullptr) {
        this->data = data;
        this->next = nullptr;

        if (prev_node != nullptr) {
          prev_node->next = this;
        }
    }

    Node next_node() {
      return *next;
    }
};

int main() {
  ChainLink link_one = ChainLink("red");
  Node node_one = Node(&link_one);

  ChainLink link_two = ChainLink("blue");
  Node node_two = Node(&link_two, &node_one);

  ChainLink link_three = ChainLink("green");
  Node node_three = Node(&link_three, &node_two);

  ChainLink link_four = ChainLink("black");
  Node node_four = Node(&link_four, &node_three);

  // To access node one
  cout << node_one.data->get_color() << endl;

  // To access node two
  cout << node_one.next_node().data->get_color() << endl;

  // To access node three
  cout << node_one.next_node().next_node().data->get_color() << endl;
}