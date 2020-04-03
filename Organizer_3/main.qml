import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: root
    visible: true
    width: 840
    height: 480
    title: qsTr("Organaizer")
    Tile {
        id: basicTable
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
        id_: basicTable.model.rowCount()
        onAccepted: {
            basicTable.model.addLine(task, description_task, date_start, date_end, progress)
            id_ = basicTable.model.rowCount()
        }
    }
}
