
#include <string>
#include <queue>
#include <map>

struct Message {
    std::string sender;
    std::string content;
};

class MailboxModel {
public:
    void addUser(const std::string& user);
    void addMessage(const std::string& to, const Message& msg);
    bool hasMessages(const std::string& user);
    Message getMessage(const std::string& user);

private:
    std::map<std::string, std::queue<Message>> mailboxes;
};
#pragma once
