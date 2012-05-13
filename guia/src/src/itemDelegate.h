#ifndef ITEMDELEGATE_H
#define ITEMDELEGATE_H

#include <QtGui>

class ItemDelegate : public QItemDelegate
{

public:
  ItemDelegate()
  {

  }

  QSize sizeHint (const QStyleOptionViewItem &, const QModelIndex &) const
  {
    return QSize(50,20);
  }

};
#endif // ITEMDELEGATE_H
