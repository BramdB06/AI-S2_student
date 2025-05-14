//
// Created by nick.roumimper on 5/14/2025.
//

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <functional>

// Eenvoudige methode om een volledige priority queue uit te printen.
// Merk op dat deze de priority queue ook volledig leeg maakt!
// Dit is dus alleen voor debuggen nuttig.
// Bron: https://en.cppreference.com/w/cpp/container/priority_queue
template<typename T>
void pop_println(std::string_view rem, T& pq)
{
  std::cout << rem << ": ";
  for (; !pq.empty(); pq.pop())
    std::cout << pq.top() << ' ';
  std::cout << '\n';
}

// Een voorbeeld van een zelfgemaakte klasse dat ik wil gebruiken in een priority queue.
// Effectief een tuple met vaste types in de waarden. Zie std::pair voor een algemenere implementatie.
class Pair {
  std::string name;
  int value;
public:
   Pair(std::string n, int v) : name(n), value(v) {}
   friend bool operator<(const Pair& lhs, const Pair& rhs);
   friend bool operator>(const Pair& lhs, const Pair& rhs);
   friend std::ostream &operator<<(std::ostream &os, Pair const& rhs);
};

// Overloading van < voor de klasse Pair.
bool operator<(const Pair& lhs, const Pair& rhs) {
  return lhs.value < rhs.value;
}

// Overloading van > voor de klasse Pair.
bool operator>(const Pair& lhs, const Pair& rhs) {
  return lhs.value > rhs.value;
}

// Overloading van << voor de klasse Pair. Houd in de gaten dat rhs echt const én & moet zijn,
// omdat er anders bij het invoeren en poppen uit de priority queue iets mismatcht.
std::ostream &operator<<(std::ostream &os, Pair const& rhs) {
  return os << "Pair: " << rhs.name << " - " << rhs.value << std::endl;
}

// Voorbeeldcode voor het gebruik van de priority queue.
int main(){
  // Rudimentair gebruik van de priority queue, met de volgorde van hoog naar laag.
  Pair val1 = Pair("A", 6);
  Pair val2 = Pair("B", 7);
  Pair val3 = Pair("C", 8);

  std::priority_queue<Pair> max_pq;

  max_pq.push(val1);
  max_pq.push(val2);
  max_pq.push(val3);

  pop_println("max_pq", max_pq);

  // Verfijnder gebruik van de priority queue, met de volgorde van laag naar hoog.
  std::vector<Pair> pairvector = {val1, val2, val3};
  std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>>
        min_pq(pairvector.begin(), pairvector.end());

  pop_println("min_pq", min_pq);

  return 0;
}

// Kopie van Pair. Voorbeeld waarbij operator<< wordt omgeleid via een interne functie,
// en die interne functie virtual is gemaakt. Dit omdat operator<< niet direct virtual
// gemaakt kan worden.
class PrePair {
  protected:
  std::string name;
  int value;
  public:
  PrePair(std::string n, int v) : name(n), value(v) {}
  friend bool operator<(const PrePair& lhs, const PrePair& rhs);
  friend bool operator>(const PrePair& lhs, const PrePair& rhs);
  friend std::ostream &operator<<(std::ostream &os, PrePair const& rhs) {
    return rhs.internalPrint(os);
  };
  virtual std::ostream& internalPrint(std::ostream &os) const = 0;
};

// Subklasse van PrePair, waarbij internalPrint wordt overridden door de subklasse.
// Merk op dat ik hier sinds de live demo een wijziging heb aangebracht;
// internalPrint heeft niet ook nog een referentie aan het te printen object nodig,
// dat is hij namelijk zelf. Zodoende is er geen rhs meer, maar wordt er gerefereerd
// aan this.
class PostPair : public PrePair {
  std::ostream& internalPrint(std::ostream &os) const override {
    return os << "Pair: " << this->name << " - " << this->value << std::endl;
  }
};
