/********************************************************************************
** Form generated from reading UI file 'backward.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BACKWARD_H
#define UI_BACKWARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_backwardW
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *simulation_timeLE;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lat_le;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lon_le;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *h_le;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *backwardW)
    {
        if (backwardW->objectName().isEmpty())
            backwardW->setObjectName(QStringLiteral("backwardW"));
        backwardW->setWindowModality(Qt::ApplicationModal);
        backwardW->resize(536, 349);
        verticalLayout_2 = new QVBoxLayout(backwardW);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(backwardW);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        simulation_timeLE = new QLineEdit(groupBox);
        simulation_timeLE->setObjectName(QStringLiteral("simulation_timeLE"));

        horizontalLayout->addWidget(simulation_timeLE);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lat_le = new QLineEdit(groupBox);
        lat_le->setObjectName(QStringLiteral("lat_le"));
        lat_le->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        horizontalLayout_2->addWidget(lat_le);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lon_le = new QLineEdit(groupBox);
        lon_le->setObjectName(QStringLiteral("lon_le"));

        horizontalLayout_3->addWidget(lon_le);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        h_le = new QLineEdit(groupBox);
        h_le->setObjectName(QStringLiteral("h_le"));

        horizontalLayout_4->addWidget(h_le);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(backwardW);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(backwardW);
        QObject::connect(buttonBox, SIGNAL(accepted()), backwardW, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), backwardW, SLOT(reject()));

        QMetaObject::connectSlotsByName(backwardW);
    } // setupUi

    void retranslateUi(QDialog *backwardW)
    {
        backwardW->setWindowTitle(QApplication::translate("backwardW", "\320\236\320\261\321\200\320\260\321\202\320\275\321\213\320\271 \320\277\320\260\320\272\320\265\321\202 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        groupBox->setTitle(QApplication::translate("backwardW", "\320\236\320\261\321\200\320\260\321\202\320\275\321\213\320\271 \320\277\320\260\320\272\320\265\321\202 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        label->setText(QApplication::translate("backwardW", "\320\242\320\265\320\272\321\203\321\211\320\265\320\265 \320\262\321\200\320\265\320\274\321\217 \320\274\320\276\320\264\320\265\320\273\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217, \320\274\321\201", nullptr));
        label_2->setText(QApplication::translate("backwardW", "\320\250\320\270\321\200\320\276\321\202\320\260 (Lat), [\320\263\321\200\320\260\320\264]", nullptr));
        label_3->setText(QApplication::translate("backwardW", "\320\224\320\276\320\273\320\263\320\276\321\202\320\260 (Lon), [\320\263\321\200\320\260\320\264]", nullptr));
        label_4->setText(QApplication::translate("backwardW", "\320\222\321\213\321\201\320\276\321\202\320\260 \320\277\320\276\320\264\321\201\321\202\320\270\320\273\320\260\321\216\321\211\320\265\320\271 \320\277\320\276\320\262\320\265\321\200\321\205\320\275\320\276\321\201\321\202\320\270, [\320\274]", nullptr));
    } // retranslateUi

};

namespace Ui {
    class backwardW: public Ui_backwardW {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BACKWARD_H
