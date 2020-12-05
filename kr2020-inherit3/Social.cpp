#include "Social.h"

Vector<string> Facebook::getFriendlist() const {
    return getFacebookFriends();
}

Vector<string> Vkontakte::getFriendlist() const {
    return getVkontakteFriends();
}
Vector<string> Odnoklassniki::getFriendlist() const {
    return getOdnoklassnikiFriends();
}

Vector<string> getFacebookFriends() {
    Vector<string> v;
    v.Add("Vasya Pupkin");
    v.Add("Ivan Ivanov");
    v.Add("Ivan Kruzenshtern");
    v.Add("John Lennon");
    return v;
}

Vector<string> getVkontakteFriends() {
    Vector<string> v;
    v.Add("Linus Torvalds");
    v.Add("Vasya Pupkin");
    v.Add("Dennis Ritchie");
    return v;
}

Vector<string> getOdnoklassnikiFriends() {
    Vector<string> v;
    v.Add("Alan Parsons");
    v.Add("Linus Torvalds");
    v.Add("Richard Stallman");
    v.Add("John Lennon");
    v.Add("Edsger Dijkstra");
    v.Add("Vasya Pupkin");
    return v;
}

bool operator<(const Friend &a, const Friend &b) {
    return a.name < b.name;
}