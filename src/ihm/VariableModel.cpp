#include "VariableModel.h"
#include "Variable.h"

int VariableModel::rowCount(const QModelIndex& parent) const
{
	return m_variable->pasDeTemps().size();
}
int VariableModel::columnCount(const QModelIndex& parent) const
{
	return 3;
}

QVariant VariableModel::data(const QModelIndex& index, int role) const {
    if (role == Qt::EditRole) {
        return QVariant::fromValue(&m_customDelegate);
    }

    if (role == Qt::DisplayRole) {
        switch (index.column()) {
            case 0: return m_variable->pasDeTemps().at(index.row());
            case 1: return QString::number(m_variable->temperature().at(index.row())) + " °C";
            case 2: return QString::number(m_variable->pression().at(index.row())) + " kPa";
        }
    }

    return QVariant();
}

QVariant VariableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role != Qt::DisplayRole) return QVariant();
	if (orientation == Qt::Orientation::Horizontal)
	{
		switch (section) {
		case 0: return "Pas de temps";
		case 1: return "Temperature";
		case 2: return "Pression";
		}
		return (section == 0 ? QStringLiteral("Pas de temps") : section == 1 ? QStringLiteral("Temp�rature") : QStringLiteral("Pression"));
	}
	else {
		return section;
	}
}

bool VariableModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
	if (role != Qt::DisplayRole) return false;
	bool conversionOK;
    double newValue = value.toDouble(&conversionOK);
	 if (!conversionOK) {
        return false;
    }
	switch (index.column())
	{
	case 0:
		m_variable->pasDeTemps().replace(index.row(), newValue);
		return true;
	case 1:
		m_variable->temperature().replace(index.row(), newValue);
		return true;
	case 2:
		m_variable->pression().replace(index.row(),newValue);
		return true;
	}
	//dire que ca a changé 
	emit dataChanged(index, index, {Qt::EditRole});
	return true;
}

Qt::ItemFlags VariableModel::flags(const QModelIndex& index) const {
    Qt::ItemFlags flags = QAbstractTableModel::flags(index);
    if (index.isValid() && (index.column() == 1 || index.column() == 2)) {
        flags |= Qt::ItemIsEditable;
    }
    return flags;
}