#include "animationutil.h"
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QApplication>
#include <QDesktopWidget>
#include <QPoint>
#include <QStackedWidget>
#include <QLabel>

AnimationUtil::AnimationUtil(QObject *parent) : QObject(parent)
{

}


void AnimationUtil::AnimationWndDown(QWidget *w)
{
    QPropertyAnimation *animDown = new QPropertyAnimation(w, "pos");
    animDown->setDuration(400);
    animDown->setStartValue(QPoint(w->x(), w->y() - w->height()));
    animDown->setEasingCurve(QEasingCurve::OutBounce);
    animDown->setEndValue(QPoint(w->x(), w->y()));
    animDown->start(QAbstractAnimation::DeleteWhenStopped);
}

void AnimationUtil::AnimationWndDrop(QWidget *w)
{
    QPropertyAnimation *pAnimation = new QPropertyAnimation(w, "geometry");
//    int x = (dskwidth() - w->width()) / 2;
//    int y = (dskheight() - w->height()) / 2;
    pAnimation->setDuration(500);
    pAnimation->setStartValue(QRect(w->x(), 0, w->width(), w->height()));
    pAnimation->setEndValue(QRect(w->x(), w->y(), w->width(), w->height()));
    pAnimation->setEasingCurve(QEasingCurve::OutElastic);
    pAnimation->start(QAbstractAnimation::DeleteWhenStopped);
}

void AnimationUtil::AnimationWndShake(QWidget *w, int x)
{
    AnimationWndShake(w);
    ((QStackedWidget*)w)->setCurrentIndex(x);
}

void AnimationUtil::AnimationWndDown(QWidget *w, int x)
{
    AnimationWndDown(w);
    ((QStackedWidget*)w)->setCurrentIndex(x);
}

void AnimationUtil::AnimationWndDrop(QWidget *w, int x)
{
    AnimationWndDrop(w);
    ((QStackedWidget*)w)->setCurrentIndex(x);
}

void AnimationUtil::AnimationWndShake(QWidget *w)
{
//    w->setGeometry(dskwidth()/2 - w->width()/2,
//                   dskheight()/2 - w->height()/2, w->width(), w->height());

    QPropertyAnimation *animShake = new QPropertyAnimation(w, "pos");
    if(animShake->state() == QPropertyAnimation::Running)
    {
        animShake->stop();
    }
    QPoint pos = w->pos();
    animShake->setDuration(400);
    animShake->setStartValue(pos);
    animShake->setKeyValueAt(0.1,pos + QPoint(-12,-12));
    animShake->setKeyValueAt(0.2,pos + QPoint(0,-4));
    animShake->setKeyValueAt(0.3,pos + QPoint(4,0));
    animShake->setKeyValueAt(0.4,pos + QPoint(4,2));
    animShake->setKeyValueAt(0.5,pos + QPoint(6,-6));
    animShake->setKeyValueAt(0.6,pos + QPoint(-4,4));
    animShake->setKeyValueAt(0.7,pos + QPoint(-4,0));
    animShake->setKeyValueAt(0.8,pos + QPoint(0,8));
    animShake->setKeyValueAt(0.9,pos + QPoint(12,12));
    animShake->setEndValue(pos);
    animShake->start();
}

int AnimationUtil::dskwidth()
{
    return qApp->desktop()->availableGeometry().width();
}

int AnimationUtil::dskheight()
{
    return qApp->desktop()->availableGeometry().height();
}

void AnimationUtil::AnimationStart(QWidget *w)
{
    QPropertyAnimation *animPos = new QPropertyAnimation(w, "pos");
    animPos->setDuration(400);
    animPos->setStartValue(QPoint(dskwidth() - w->width(), dskheight()/2 - w->height()/2));
    animPos->setEndValue(QPoint(dskwidth()/2 - w->width()/2, dskheight()/2 - w->height()/2));
    animPos->setEasingCurve(QEasingCurve::Linear);

    QPropertyAnimation *animOpacity = new QPropertyAnimation(w, "windowOpacity");
    animOpacity->setDuration(400);
    animOpacity->setStartValue(0);
    animOpacity->setEndValue(1);

    QParallelAnimationGroup *group = new QParallelAnimationGroup(w);
    group->addAnimation(animPos);
    group->addAnimation(animOpacity);
    group->start(QAbstractAnimation::DeleteWhenStopped);
}

void AnimationUtil::AnimationDoorOpen(QWidget *w, int x)
{
    QLabel *labelLeft = new QLabel(w);
    labelLeft->resize(QSize(w->width()/2, w->height()));
    labelLeft->setAttribute(Qt::WA_DeleteOnClose);

    QPixmap pix = w->grab();
    QPixmap pixleft = pix.copy(0, 0, w->width()/2, w->height());
    labelLeft->setPixmap(pixleft);labelLeft->show();


    QLabel *labelRight = new QLabel(w);
    labelRight->resize(QSize(w->width()/2, w->height()));
    labelRight->setAttribute(Qt::WA_DeleteOnClose);
    QPixmap pixright = pix.copy(w->width()/2,0, w->width()/2, w->height());
    labelRight->setPixmap(pixright);
    labelRight->show();

    QPropertyAnimation *animLeft = new QPropertyAnimation(labelLeft,"geometry");
    animLeft->setDuration(1000);
    animLeft->setStartValue(QRect(0,0, w->width()/2, w->height()));
    animLeft->setEndValue(QRect(-w->width()*2,0, w->width()/2, w->height()));
    animLeft->setEasingCurve(QEasingCurve::InCubic);

    QPropertyAnimation *animRight = new QPropertyAnimation(labelRight, "geometry");
    animRight->setDuration(1000);
    animRight->setStartValue(QRect(w->width()/2, 0, w->width()/2, w->height()));
    animRight->setEndValue(QRect(w->width()*2, 0, w->width()/2, w->height()));
    animRight->setEasingCurve(QEasingCurve::InCubic);

    QParallelAnimationGroup *group = new QParallelAnimationGroup;
    group->addAnimation(animLeft);
    group->addAnimation(animRight);
    group->start(QAbstractAnimation::DeleteWhenStopped);
    ((QStackedWidget*)w)->setCurrentIndex(x);

    labelLeft->raise();
    labelRight->raise();
    QObject::connect(group, &QParallelAnimationGroup::finished, [=](){
        labelLeft->close();
        labelRight->close();
    });
}

void AnimationUtil::AnimationClose(QWidget *w)
{
    QPropertyAnimation *animClose = new QPropertyAnimation(w, "geometry");
    animClose->setStartValue(w->geometry());
    animClose->setEndValue(QRect(w->geometry().x(), w->geometry().y() + w->height(), w->width(), 0));
    animClose->setDuration(400);
    animClose->setEasingCurve(QEasingCurve::Linear);

    QPropertyAnimation *animOpacity = new QPropertyAnimation(w, "windowOpacity");
    animOpacity->setEndValue(1);
    animOpacity->setStartValue(0);
    animOpacity->setDuration(400);

    QParallelAnimationGroup *group = new QParallelAnimationGroup(w);
    group->addAnimation(animClose);
    group->addAnimation(animOpacity);
    group->start(QAbstractAnimation::DeleteWhenStopped);
    QObject::connect(group, &QParallelAnimationGroup::finished, []{
        qApp->quit();
    });
}
