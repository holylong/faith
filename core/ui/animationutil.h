#ifndef ANIMATIONUTIL_H
#define ANIMATIONUTIL_H

#include <QObject>
#include <QWidget>

class AnimationUtil : public QObject
{
    Q_OBJECT
public:
    explicit AnimationUtil(QObject *parent = nullptr);

    static void AnimationWndDown(QWidget *w);
    static void AnimationWndDrop(QWidget *w);
    static void AnimationWndShake(QWidget *w);
    static void AnimationStart(QWidget *w);
    static void AnimationClose(QWidget *w);
    static void AnimationDoorOpen(QWidget *w, int x);

private:
    static int dskwidth();
    static int dskheight();

signals:

};

#endif // ANIMATIONUTIL_H
