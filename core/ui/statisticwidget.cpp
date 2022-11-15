#include "statisticwidget.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QtCharts>
#include <QLineSeries>
#include <QChart>
#include <QChartView>

StatisticWidget::StatisticWidget(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *chartMainLayout = new QHBoxLayout();
    chartMainLayout->addWidget(CreateChart());
    setLayout(chartMainLayout);
}


QChartView* StatisticWidget::CreateChart(){
    QLineSeries *series = new QLineSeries();
    for (int i = 0; i < 500; i++) {
       QPointF p((qreal) i, qSin(M_PI / 50 * i) * 100);
       p.ry() += QRandomGenerator::global()->bounded(20);
       *series << p;
    }

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->setTitle("Simple ZoomLine chart example");
    chart->createDefaultAxes();
    chart->axes(Qt::Horizontal).first()->setRange(0,500);
    chart->axes(Qt::Vertical).first()->setRange(0, 120);

    QChartView *cpuView = new QChartView(chart);
    cpuView->setRenderHint(QPainter::Antialiasing);
    return cpuView;
}
