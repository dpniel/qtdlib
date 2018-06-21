#ifndef QTDTEXTENTITYTYPE_H
#define QTDTEXTENTITYTYPE_H

#include <QObject>
#include "common/qabstracttdobject.h"

class QTdTextEntityType : public QTdObject
{
    Q_OBJECT
public:
    explicit QTdTextEntityType(QObject *parent = nullptr);
};

#define TEXT_ENTITY_CLASS(name, type) \
    class QTdTextEntityType##name : public QTdTextEntityType { \
        Q_OBJECT \
        Q_DISABLE_COPY(QTdTextEntityType##name) \
    public: \
        explicit QTdTextEntityType##name (QObject *parent = 0) : QTdTextEntityType(parent) { setType( type ); }; \
    };

TEXT_ENTITY_CLASS(Bold, QTdObject::TEXT_ENTITY_TYPE_BOLD)
TEXT_ENTITY_CLASS(BotCommand, QTdObject::TEXT_ENTITY_TYPE_BOT_COMMAND)
TEXT_ENTITY_CLASS(Code, QTdObject::TEXT_ENTITY_TYPE_CODE)
TEXT_ENTITY_CLASS(EmailAddress, QTdObject::TEXT_ENTITY_TYPE_EMAIL_ADDRESS)
TEXT_ENTITY_CLASS(Hashtag, QTdObject::TEXT_ENTITY_TYPE_HASHTAG)
TEXT_ENTITY_CLASS(Italic, QTdObject::TEXT_ENTITY_TYPE_ITALIC)
TEXT_ENTITY_CLASS(Mention, QTdObject::TEXT_ENTITY_TYPE_MENTION)
TEXT_ENTITY_CLASS(MentionName, QTdObject::TEXT_ENTITY_TYPE_MENTION_NAME)
TEXT_ENTITY_CLASS(PhoneNumber, QTdObject::TEXT_ENTITY_TYPE_PHONE_NUMBER)
TEXT_ENTITY_CLASS(Cashtag, QTdObject::TEXT_ENTITY_TYPE_CASHTAG)
TEXT_ENTITY_CLASS(Pre, QTdObject::TEXT_ENTITY_TYPE_PRE)
TEXT_ENTITY_CLASS(PreCode, QTdObject::TEXT_ENTITY_TYPE_PRE_CODE)
TEXT_ENTITY_CLASS(TextUrl, QTdObject::TEXT_ENTITY_TYPE_TEXT_URL)
TEXT_ENTITY_CLASS(Url, QTdObject::TEXT_ENTITY_TYPE_URL)

struct QTdTextEntityFactory {
    static QTdTextEntityType *create(const QJsonObject &json, QObject *parent = Q_NULLPTR);
};


#endif // QTDTEXTENTITYTYPE_H
