import QtQuick 2.0
import QtQuick.Controls 2.12

Rectangle {
    id: button

    property string add: "Add"

    width: 80
    height:30
    radius: 10
    color: "#FFFF00"
    border.color: "#000000"
    border.width: 2

    signal clicked;

    Text {
        id: textButton
        text: qsTr("Add")
        anchors.centerIn: parent
        horizontalAlignment: TextInput.AlignHCenter
    }
    MouseArea {
        id: _mArea
        anchors.fill: parent
        onClicked: { parent.clicked() }
    }
}
