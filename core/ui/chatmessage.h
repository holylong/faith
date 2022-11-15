#ifndef CHATMESSAGE_H
#define CHATMESSAGE_H

#include <QWidget>

class ChatMessage : public QWidget
{
    Q_OBJECT
public:
    explicit ChatMessage(QWidget *parent = nullptr);

    enum class TextType{
        TextSystem,
        TextMe,
        TextHe,
        TextTime,
    };

    void UpdateText(const QString& text, const QString& time, const QSize &txtSize, TextType txtType);

signals:

};

#endif // CHATMESSAGE_H
