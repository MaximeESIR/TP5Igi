// CustomDelegate.h
#ifndef CUSTOMDELEGATE_H
#define CUSTOMDELEGATE_H

#include <QStyledItemDelegate>

class CustomDelegate : public QStyledItemDelegate {
public:
    CustomDelegate(QObject *pParent = nullptr);

    QWidget *createEditor(QWidget *pParent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *pEditor, const QModelIndex &index) const override;
    void setModelData(QWidget *pEditor, QAbstractItemModel *pModel, const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *pEditor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // CUSTOMDELEGATE_H
