// CustomDelegate.cpp
#include "CustomDelegate.h"
#include <QLineEdit>
#include <QDoubleValidator>

CustomDelegate::CustomDelegate(QObject *pParent) : QStyledItemDelegate(pParent) {}

//on créé un qlineEdit pour pouvoir interdire ou on l'ajout de truc 
QWidget *CustomDelegate::createEditor(QWidget *pParent, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    QLineEdit *pEditor = qobject_cast<QLineEdit*>(QStyledItemDelegate::createEditor(pParent, option, index));

    // Ajoutez un validateur pour interdire les valeurs négatives
    QDoubleValidator *pValidator = new QDoubleValidator(0, 1000, 2, pEditor);
    pEditor->setValidator(pValidator);

    return pEditor;
}

void CustomDelegate::setEditorData(QWidget *pEditor, const QModelIndex &index) const {
    QString value = index.model()->data(index, Qt::EditRole).toString();
    static_cast<QLineEdit*>(pEditor)->setText(value);
}

void CustomDelegate::setModelData(QWidget *pEditor, QAbstractItemModel *pModel, const QModelIndex &index) const {
    QString value = static_cast<QLineEdit*>(pEditor)->text();
    pModel->setData(index, value, Qt::EditRole);
}

void CustomDelegate::updateEditorGeometry(QWidget *pEditor, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    pEditor->setGeometry(option.rect);
}
