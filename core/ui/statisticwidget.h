#ifndef STATISTICWIDGET_H
#define STATISTICWIDGET_H

#include <QWidget>
#include <QtCharts>
namespace QtCharts{
    class QChartView;
}

class StatisticWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StatisticWidget(QWidget *parent = nullptr);

    QtCharts::QChartView* CreateChart();

signals:

};

#endif // STATISTICWIDGET_H
