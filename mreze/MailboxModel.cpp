#include "MailboxModel.h"

void MailboxModel::addUser(const std::string& user) {
    if (mailboxes.find(user) == mailboxes.end())
        mailboxes[user] = std::queue<Message>();
}

void MailboxModel::addMessage(const std::string& to, const Message& msg) {
    mailboxes[to].push(msg);
}

bool MailboxModel::hasMessages(const std::string& user) {
    return !mailboxes[user].empty();
}

Message MailboxModel::getMessage(const std::string& user) {
    Message msg = mailboxes[user].front();
    mailboxes[user].pop();
    return msg;
}
