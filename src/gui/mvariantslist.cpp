#include "mvariantslist.h"
#include <QHeaderView>
#include "base.h"
#include <QLineEdit>
#include <QComboBox>
MVariantsList::MVariantsList(QWidget *parent) : QTableWidget(parent)
{
    m_pVariants=0;
    setEditTriggers(QTableWidget::NoEditTriggers);
    setAlternatingRowColors(true);
    setSortingEnabled(false);

    connect(this,SIGNAL(currentCellChanged(int,int,int,int)),
            this,SLOT(ListCellChanged(int,int,int,int)));
}

void MVariantsList::Init(Variants *pVariants)
{
    m_pVariants=pVariants;Q_ASSERT(m_pVariants);
    int iSize=m_pVariants->m_mVariantMap.size();
    setRowCount(iSize);setColumnCount(3);

    QStringList header;
    header<<QObject::trUtf8("name")<<QObject::trUtf8("data")<<QObject::trUtf8("unit");
    setHorizontalHeaderLabels(header);
    QHeaderView * headview= horizontalHeader();
    headview->setSectionResizeMode(0,QHeaderView::ResizeToContents);
    headview->setSectionResizeMode(2,QHeaderView::ResizeToContents);


    VariantMap::iterator ii=m_pVariants->m_mVariantMap.begin();
    int iIndex=0;
    for(;ii!=m_pVariants->m_mVariantMap.end();ii++)
    {
        QString s=ii->m_sName;
        s.replace(QString("_"), QString(" "));
        QTableWidgetItem* pitem=new QTableWidgetItem(s+":");
        pitem->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        setItem(iIndex,0,pitem);

        pitem=new QTableWidgetItem();
        setItem(iIndex,1,pitem);

        VarDesc* pDesc=m_gVarDescMap.get_VarDesc(ii->m_iID);
        if(pDesc)
        {
            pitem=new QTableWidgetItem(pDesc->m_sUnit);
            setItem(iIndex,2,pitem);
        }
        iIndex++;
    }
}

void MVariantsList::Fresh()
{
    Q_ASSERT(m_pVariants);
    setCurrentCell(-1,-1);
    VariantMap::iterator ii=m_pVariants->m_mVariantMap.begin();
    int iIndex=0;
    for(;ii!=m_pVariants->m_mVariantMap.end();ii++,iIndex++)
    {
        QVariant& var=ii->m_vVar;
        QTableWidgetItem* pitem=item(iIndex,1);
        pitem->setData(Qt::UserRole,var);
        if(var.type()!=QVariant::UInt)
        {
            pitem->setText(var.toString());
        }
        else
        {
            VarDesc* pDesc=m_gVarDescMap.get_VarDesc(ii->m_iID);
            Q_ASSERT(pDesc);
            Q_ASSERT(!OUTOFRANGE(var.toInt(),0,pDesc->m_slRange.size()));
            pitem->setText(pDesc->m_slRange[var.toInt()]);
        }
    }
}

void MVariantsList::Apply()
{
    Q_ASSERT(m_pVariants);
    setCurrentCell(-1,-1);
    VariantMap::iterator ii=m_pVariants->m_mVariantMap.begin();
    int iIndex=0;
    for(;ii!=m_pVariants->m_mVariantMap.end();ii++,iIndex++)
    {
        QVariant& var=ii->m_vVar;
        QTableWidgetItem* pitem=item(iIndex,1 );
        var= pitem->data(Qt::UserRole);
    }
}

void MVariantsList::ListCellChanged(int currentRow, int currentColumn,
                                    int previousRow, int previousColumn)
{

    Q_ASSERT(m_pVariants);
    if(previousColumn==1)
    {

        QWidget *pWidgetPre=cellWidget(previousRow,previousColumn);
        if(pWidgetPre)
        {
            QTableWidgetItem* pitemPre=item(previousRow, previousColumn);
            QVariant var=pitemPre->data(Qt::UserRole);
            QVariant::Type type=var.type();
            if(type!=QVariant::UInt)
            {
                QLineEdit* pLineEdit=(QLineEdit*)pWidgetPre;
                QString text=pLineEdit->text();
                pitemPre->setText(text);
                switch (var.type()) {
                case QVariant::Int:
                    var=text.toInt();
                    break;
                case QVariant::Double:
                    var=text.toDouble();
                    break;
                case QVariant::String:
                    var=text;
                    break;
                default:
                    Q_ASSERT(0);
                    break;
                }
            }
            else
            {
                QComboBox* pCombo=(QComboBox*)pWidgetPre;
                QString text=pCombo->currentText();
                pitemPre->setText(text);
                var=uint(pCombo->currentIndex());
            }
            pitemPre->setData(Qt::UserRole,var);
            removeCellWidget(previousRow, previousColumn);
        }
    }

    if(currentColumn==1)
    {
    QTableWidgetItem* pitemCur=item(currentRow, currentColumn);
    QVariant var=pitemCur->data(Qt::UserRole);
    QVariant::Type type=var.type();
    if(type!=QVariant::UInt)
    {
        QLineEdit* pLineEdit=new QLineEdit(pitemCur->text());
        setCellWidget(currentRow, currentColumn,pLineEdit);
    }
    else
    {
        QComboBox* pCombo=new QComboBox();
        VariantMap::iterator ii=m_pVariants->m_mVariantMap.begin()+currentRow;
        VarDesc* pDesc=m_gVarDescMap.get_VarDesc(ii->m_iID);
        Q_ASSERT(pDesc);
        pCombo->addItems(pDesc->m_slRange);
        pCombo->setCurrentIndex(var.toUInt());
    }
    }

}

