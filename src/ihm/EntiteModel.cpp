#include "EntiteModel.h"
int EntiteModel::rowCount(const QModelIndex& parent) const
{
	return m_entite->variables().size();
}
QVariant EntiteModel::data(const QModelIndex& index, int role) const {
	if (role != Qt::DisplayRole) return QVariant();
	return QVariant();// this->m_entite->variables().at(index.row());
}