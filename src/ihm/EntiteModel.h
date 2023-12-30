#pragma once
#include <qabstractitemmodel.h>
#include "model/Entite.h"
class EntiteModel :
    public QAbstractListModel
{
public:
    EntiteModel(Entite* entite, QObject* pParent = NULL)
        : QAbstractListModel(pParent)
    {
        m_entite = entite;
    }


    virtual int rowCount(const QModelIndex& parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayPropertyRole)const;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole)const;


    Entite* m_entite;
};

