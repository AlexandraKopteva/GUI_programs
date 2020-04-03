import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: root
    visible: true
    width: 840
    height: 480
    title: qsTr("Organaizer")


    Table{
    id:_table
    }
    Button {
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        onClicked: { tableModel.open() }
    }
    TableModel {
        id: tableModel
        visible: false

        _id: _table.model.rowCount()
        onAccepted: {
            _table.model.addLine(task, description_task, date_start, date_end, progress)
            _id = _table.model.rowCount()
        }
    }
}
