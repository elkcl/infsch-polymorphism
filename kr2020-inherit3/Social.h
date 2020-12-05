#ifndef POLYMORPHISM_SOCIAL_H
#define POLYMORPHISM_SOCIAL_H

#include "Vector.h"
#include <string>

class SocialNetwork {
public:
    virtual Vector<string> getFriendlist() const = 0;
};

class Facebook : public SocialNetwork {
public:
    Vector<string> getFriendlist() const override;
};

class Vkontakte : public SocialNetwork {
public:
    Vector<string> getFriendlist() const override;
};

class Odnoklassniki : public SocialNetwork {
public:
    Vector<string> getFriendlist() const override;
};

Vector<string> getFacebookFriends();
Vector<string> getVkontakteFriends();
Vector<string> getOdnoklassnikiFriends();

struct Friend {
    string name;
    bool FB;
    bool VK;
    bool OK;
};

bool operator<(const Friend &a, const Friend &b);

#endif //POLYMORPHISM_SOCIAL_H
