#include <iostream>
#include "Social.h"

using namespace std;

int main() {
    Facebook fb;
    Vkontakte vk;
    Odnoklassniki ok;

    Vector<string> fbFriends = fb.getFriendlist();
    Vector<string> vkFriends = vk.getFriendlist();
    Vector<string> okFriends = ok.getFriendlist();

    Vector<Friend> f;
    for (int i = 0; i < fbFriends.Size(); ++i) {
        f.Add({fbFriends[i], true, false, false});
    }
    for (int i = 0; i < vkFriends.Size(); ++i) {
        f.Add({vkFriends[i], false, true, false});
    }
    for (int i = 0; i < okFriends.Size(); ++i) {
        f.Add({okFriends[i], false, false,true});
    }
    f.Sort(0, f.Size()-1);

    int len = f.Size();
    for (int i = 1; i < len; ++i) {
        if (f[i].name == f[i-1].name) {
            f[i-1].FB = f[i-1].FB || f[i].FB;
            f[i-1].VK = f[i-1].VK || f[i].VK;
            f[i-1].OK = f[i-1].OK || f[i].OK;
            f.Delete(i);
            --len;
            --i;
        }
    }

    for (int i = 0; i < f.Size(); ++i) {
        cout << f[i].name << " (";
        bool prev = false;
        if (f[i].FB) {
            prev = true;
            cout << "FB";
        }
        if (f[i].VK) {
            if (prev) cout << ", ";
            cout << "VK";
            prev = true;
        }
        if (f[i].OK) {
            if (prev) cout << ", ";
            cout << "OK";
        }
        cout << ")\n";
    }
}