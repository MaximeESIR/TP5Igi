#pragma once
#include <qabstractitemmodel.h>
#include <model/Variable.h>
#include "CustomDelegate.h"
class VariableModel :
    public QAbstractTableModel
{
public:
    VariableModel(Variable* variable, QObject* pParent = NULL)
        : QAbstractTableModel(pParent), m_customDelegate(this)
    {
        m_variable = variable;
    }

    virtual int rowCount(const QModelIndex& parent = QModelIndex()) const;
    virtual int columnCount(const QModelIndex& parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayPropertyRole)const;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole)const;
    virtual bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole);
    virtual Qt::ItemFlags flags(const QModelIndex& index) const override;
private:
    Variable* m_variable;
    CustomDelegate m_customDelegate;
};

