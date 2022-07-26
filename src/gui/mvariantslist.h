#ifndef MVARIANTSLIST_H
#define MVARIANTSLIST_H

#include <QTableWidget>
#include <variants.h>
class MVariantsList : public QTableWidget
{
    Q_OBJECT
public:
    explicit MVariantsList(QWidget *parent = 0);
    Variants* m_pVariants;
    void Init(Variants* pVariants);
    void Fresh();
    void Apply();
signals:

public slots:
    void ListCellChanged(int currentRow, int currentColumn,
                            int previousRow, int previousColumn);
};

#endif // MVARIANTSLIST_H
