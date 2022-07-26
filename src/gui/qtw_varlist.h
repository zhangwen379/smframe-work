#ifndef QTW_VARLIST_H
#define QTW_VARLIST_H

#include <QTableWidget>
#include <variants.h>
#include <QDoubleValidator>
#include <QIntValidator>
class QTW_VarList : public QTableWidget
{
    Q_OBJECT
public:
    explicit QTW_VarList(QWidget *parent = 0);
    Variants* m_pVariants;
    void Init(Variants* pVariants);
    void Fresh();
    void Apply();
    QDoubleValidator v_Double ;
    QIntValidator v_Int ;
signals:

public slots:
    void ListCellChanged(int currentRow, int currentColumn,
                            int previousRow, int previousColumn);
};

#endif // QTW_VARLIST_H
